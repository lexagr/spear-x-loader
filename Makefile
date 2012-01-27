#
# (C) Copyright 2009
# Vipin Kumar, ST Microelectronics, vipin.kumar@st.com
#
# See file CREDITS for list of people who contributed to this
# project.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundatio; either version 2 of
# the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston,
# MA 02111-1307 USA
#

VERSION = 2010
PATCHLEVEL = 06
SUBLEVEL =
EXTRAVERSION =-lsp-3.2.3-rc1
ifneq "$(SUBLEVEL)" ""
XLOADER_VERSION = $(VERSION).$(PATCHLEVEL).$(SUBLEVEL)$(EXTRAVERSION)
else
XLOADER_VERSION = $(VERSION).$(PATCHLEVEL)$(EXTRAVERSION)
endif
TIMESTAMP_FILE = $(obj)include/timestamp_autogenerated.h
VERSION_FILE = $(obj)include/version_autogenerated.h

# Deal with colliding definitions from tcsh etc.
VENDOR=

#########################################################################
# Allow for silent builds
ifeq (,$(findstring s,$(MAKEFLAGS)))
XECHO = echo
else
XECHO = :
endif

TOPDIR		:= $(CURDIR)
export	TOPDIR

MKCONFIG	:= $(TOPDIR)/mkconfig
export MKCONFIG

obj :=
src :=
export obj src

ifeq ($(obj)include/config.mk,$(wildcard $(obj)include/config.mk))

# load ARCH, PLAT, and CPU configuration
include $(obj)include/config.mk
export	ARCH CPU PLAT VENDOR SOC

ifndef CROSS_COMPILE
CROSS_COMPILE = arm-linux-
endif	# CROSS_COMPILE

export	CROSS_COMPILE

# load other configuration
include $(TOPDIR)/config.mk

#########################################################################
# Xloader objects....order is important (i.e. start must be first)

OBJS  = cpu/$(CPU)/start.o
OBJS := $(addprefix $(obj),$(OBJS))


LIBS  = 
LIBS += cpu/$(CPU)/lib$(CPU).a
ifdef SOC
LIBS += cpu/$(CPU)/$(SOC)/lib$(SOC).a
endif
LIBS += lib_generic/libgeneric.a
LIBS += plat/common/libcommon.a
LIBS += lib_$(ARCH)/lib$(ARCH).a
LIBS += drivers/mtd/libmtd.a
LIBS += drivers/misc/libmisc.a
LIBS += drivers/pl061/libpl061.a
LIBS += common/libcommon.a
LIBS += drivers/serial/libserial.a

LIBS := $(addprefix $(obj),$(LIBS))

LIBPLAT = plat/$(PLATDIR)/lib$(PLAT).a
LIBPLAT := $(addprefix $(obj),$(LIBPLAT))

# Add GCC lib
PLATFORM_LIBS += -L $(shell dirname `$(CC) $(CFLAGS) -print-libgcc-file-name`) -lgcc

__OBJS := $(subst $(obj),,$(OBJS))
__LIBS := $(subst $(obj),,$(LIBS)) $(subst $(obj),,$(LIBPLAT))

#########################################################################
#########################################################################

# Always append ALL so that arch config.mk's can add custom ones
ALL += $(obj)xloader.srec $(obj)xloader.bin $(obj)xloader.code $(obj)xloader.img $(obj)System.map

all:		$(ALL)

$(obj)xloader.hex:	$(obj)xloader
		$(OBJCOPY) ${OBJCFLAGS} -O ihex $< $@

$(obj)xloader.srec:	$(obj)xloader
		$(OBJCOPY) -O srec $< $@

$(obj)xloader.bin:	$(obj)xloader
		$(OBJCOPY) ${OBJCFLAGS} -O binary $< $@

ifeq ("$(SOC)","spear13xx")
$(obj)xloader.img:	$(obj)xloader.bin
		mkimage -A $(ARCH) -T firmware -C none \
		-a $(TEXT_BASE) -e $(TEXT_BASE) \
		-n $(shell sed -n -e 's/.*XLOADER_VERSION//p' $(VERSION_FILE) | \
			sed -e 's/"[	 ]*$$/ for $(PLAT) board"/') \
		-d $< $@
else
$(obj)xloader.img:	$(obj)xloader.bin
		mkimage -A $(ARCH) -T firmware -C none \
		-a $(TEXT_BASE) -e $(TEXT_BASE) -n XLOADER \
		-d $< $@
endif

$(obj)xloader.code:	$(obj)xloader
		$(OBJDUMP) -D $< > $@

GEN_XLOADER = \
		cd $(TOPDIR) && $(LD) $(LDFLAGS) $(__OBJS) \
			--start-group $(__LIBS) --end-group $(PLATFORM_LIBS) \
			-Map xloader.map -o xloader
$(obj)xloader:		depend $(OBJS) $(LIBPLAT) $(LIBS) $(LDSCRIPT)
		$(GEN_XLOADER)

$(OBJS):	depend
		$(MAKE) -C cpu/$(CPU) $(if $(REMOTE_BUILD),$@,$(notdir $@))

$(LIBS):	depend
		$(MAKE) -C $(dir $(subst $(obj),,$@))

$(LIBPLAT):	depend $(LIBS)
		$(MAKE) -C $(dir $(subst $(obj),,$@))

$(LDSCRIPT):	depend
		$(MAKE) -C $(dir $@) $(notdir $@)

$(VERSION_FILE):
		@( printf '#define XLOADER_VERSION "Xloader %s%s"\n' "$(XLOADER_VERSION)" \
		 '$(shell $(TOPDIR)/tools/setlocalversion $(TOPDIR))' ) > $@.tmp
		@cmp -s $@ $@.tmp && rm -f $@.tmp || mv -f $@.tmp $@

$(TIMESTAMP_FILE):
		@date +'#define XLOADER_DATE "%b %d %C%y"' > $@
		@date +'#define XLOADER_TIME "%T"' >> $@

depend dep:	$(TIMESTAMP_FILE) $(VERSION_FILE) $(obj)include/autoconf.mk
		for dir in $(SUBDIRS) ; do $(MAKE) -C $$dir _depend ; done

SYSTEM_MAP = \
		$(NM) $1 | \
		grep -v '\(compiled\)\|\(\.o$$\)\|\( [aUw] \)\|\(\.\.ng$$\)\|\(LASH[RL]DI\)' | \
		LC_ALL=C sort
$(obj)System.map:	$(obj)xloader
		@$(call SYSTEM_MAP,$<) > $(obj)System.map

#
# Auto-generate the autoconf.mk file (which is included by all makefiles)
#
# This target actually generates 2 files; autoconf.mk and autoconf.mk.dep.
# the dep file is only include in this top level makefile to determine when
# to regenerate the autoconf.mk file.
$(obj)include/autoconf.mk.dep: $(obj)include/config.h include/common.h
	@$(XECHO) Generating $@ ; \
	set -e ; \
	: Generate the dependancies ; \
	$(CC) -x c -DDO_DEPS_ONLY -M $(HOST_CFLAGS) $(CPPFLAGS) \
		-MQ $(obj)include/autoconf.mk include/common.h > $@

$(obj)include/autoconf.mk: $(obj)include/config.h
	@$(XECHO) Generating $@ ; \
	set -e ; \
	: Extract the config macros ; \
	$(CPP) $(CFLAGS) -DDO_DEPS_ONLY -dM include/common.h | \
		sed -n -f tools/scripts/define2mk.sed > $@.tmp && \
	mv $@.tmp $@

sinclude $(obj)include/autoconf.mk.dep

#########################################################################
else	# !config.mk
all $(obj)xloader.hex $(obj)xloader.srec $(obj)xloader.bin \
$(obj)xloader.img $(obj)xloader.dis $(obj)xloader \
$(SUBDIRS) $(TIMESTAMP_FILE) $(VERSION_FILE) depend \
dep $(obj)System.map:
	@echo "System not configured - see README" >&2
	@ exit 1
endif	# config.mk

#########################################################################

unconfig:
	@rm -f $(obj)include/config.h $(obj)include/config.mk \
		$(obj)plat/*/config.tmp $(obj)plat/*/*/config.tmp \
		$(obj)include/autoconf.mk $(obj)include/autoconf.mk.dep

spear300_config \
spear300_usbtty_config :
	@[ -z "$(findstring usbtty,$@)" ] || \
		{ echo "#define CONFIG_SPEAR_USBTTY" >> $(obj)include/config.h ; \
		}
	@$(MKCONFIG) -n $@ -a spear300 arm arm926ejs spear300 NULL spear

spear310_config \
spear310_usbtty_config :
	@[ -z "$(findstring usbtty,$@)" ] || \
		{ echo "#define CONFIG_SPEAR_USBTTY" >> $(obj)include/config.h ; \
		}
	@$(MKCONFIG) -n $@ -a spear310 arm arm926ejs spear310 NULL spear

spear320_config \
spear320_usbtty_config :
	@[ -z "$(findstring usbtty,$@)" ] || \
		{ echo "#define CONFIG_SPEAR_USBTTY" >> $(obj)include/config.h ; \
		}
	@$(MKCONFIG) -n $@ -a spear320 arm arm926ejs spear320 NULL spear

spear320_hmi_config \
spear320_hmi_usbtty_config :
	@[ -z "$(findstring usbtty,$@)" ] || \
		{ echo "#define CONFIG_SPEAR_USBTTY" >> $(obj)include/config.h ; \
		}
	@$(MKCONFIG) -n $@ -a spear320_hmi arm arm926ejs spear320_hmi NULL spear

spear600_config \
spear600_usbtty_config :
	@[ -z "$(findstring usbtty,$@)" ] || \
		{ echo "#define CONFIG_SPEAR_USBTTY" >> $(obj)include/config.h ; \
		}
	@$(MKCONFIG) -n $@ -a spear600 arm arm926ejs spear600 NULL spear

spear1300_config \
spear1300_usbtty_config :
	@[ -z "$(findstring usbtty,$@)" ] || \
		{ echo "#define CONFIG_SPEAR_USBTTY" >> $(obj)include/config.h ; \
		}
	@$(MKCONFIG) -n $@ -a spear1300 arm arm_cortexa8 spear1300 NULL spear13xx

spear1310_reva_config \
spear1310_reva_usbtty_config :
	@[ -z "$(findstring usbtty,$@)" ] || \
		{ echo "#define CONFIG_SPEAR_USBTTY" >> $(obj)include/config.h ; \
		}
	@$(MKCONFIG) -n $@ -a spear1310_reva arm arm_cortexa8 spear1310_reva NULL spear13xx

spear1340_config \
spear1340_usbtty_config :
	@[ -z "$(findstring usbtty,$@)" ] || \
		{ echo "#define CONFIG_SPEAR_USBTTY" >> $(obj)include/config.h ; \
		}
	@$(MKCONFIG) -n $@ -a spear1340 arm arm_cortexa8 spear1340 NULL spear13xx

spear900_config \
spear900_usbtty_config :
	@[ -z "$(findstring usbtty,$@)" ] || \
		{ echo "#define CONFIG_SPEAR_USBTTY" >> $(obj)include/config.h ; \
		}
	@$(MKCONFIG) -n $@ -a spear900 arm arm_cortexa8 spear900 NULL spear13xx

spear900_lcad_config \
spear900_lcad_usbtty_config :
	@[ -z "$(findstring usbtty,$@)" ] || \
		{ echo "#define CONFIG_SPEAR_USBTTY" >> $(obj)include/config.h ; \
		}
	@$(MKCONFIG) -n $@ -a spear900_lcad arm arm_cortexa8 spear900_lcad NULL spear13xx

spearR1801e_config \
spearR1801e_usbtty_config :
	@[ -z "$(findstring usbtty,$@)" ] || \
		{ echo "#define CONFIG_SPEAR_USBTTY" >> $(obj)include/config.h ; \
		}
	@$(MKCONFIG) -n $@ -a spearR1801e arm arm_cortexa8 spearR1801e NULL spear13xx

#########################################################################
#########################################################################
#########################################################################

clean:
	@rm -f $(TIMESTAMP_FILE) $(VERSION_FILE)
	@find $(TOPDIR) -type f \
		\( -name 'core' -o -name '*.bak' -o -name '*~' \
		-o -name '*.o'	-o -name '*.a' -o -name '*.exe'	\) -print \
		| xargs rm -f

clobber:	clean
	@find $(TOPDIR) -type f \( -name .depend \
		-o -name '*.srec' -o -name '*.bin' -o -name xloader.img \) \
		-print0 \
		| xargs -0 rm -f
	@rm -f $(OBJS) $(obj)*.bak $(obj)*.*~
	@rm -f $(obj)xloader $(obj)xloader.map $(obj)xloader.hex $(ALL)
	@rm -f $(obj)include/asm/proc $(obj)include/asm/arch $(obj)include/asm

mrproper \
distclean:	clobber unconfig

backup:
	F=`basename $(TOPDIR)` ; cd .. ; \
	gtar --force-local -zcvf `date "+$$F-%Y-%m-%d-%T.tar.gz"` $$F

#########################################################################
