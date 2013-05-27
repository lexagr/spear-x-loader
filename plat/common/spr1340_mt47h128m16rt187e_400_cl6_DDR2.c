/*
 * (C) Copyright 2000-2009
 * Vikas Manocha, ST Microelectronics, vikas.manocha@st.com
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>

#if defined(CONFIG_SPEAR1340) && \
	(CONFIG_DDR_MT47H128M16) && (CONFIG_DDR2) && (CONFIG_DDR_FREQ_400)
const u32 mpmc_conf_vals[CONFIG_SPEAR_MPMCREGS] = {
	0x00000100, /* MPMC_REG_00 */
	0x00010100, /* MPMC_REG_01 */
	0x01000000, /* MPMC_REG_02 */
	0x00010100, /* MPMC_REG_03 */
	0x00000000, /* MPMC_REG_04 */
	0x00010100, /* MPMC_REG_05 */
	0x00000001, /* MPMC_REG_06 */
	0x00000000, /* MPMC_REG_07 */
	0x00000000, /* MPMC_REG_08 */ /* DDR2 RDLVL_GATE_REG_EN BIT_0 0x00000000 */
	0x00000000, /* MPMC_REG_09 */ /* DDR2 RDLVL_REG_EN BIT_24 0x00000000 */
	0x00000000, /* MPMC_REG_10 */
	0x00000101, /* MPMC_REG_11 */
	0x00000101, /* MPMC_REG_12 */
	0x01010000, /* MPMC_REG_13 */
	0x00000000, /* MPMC_REG_14 */
	0x01000000, /* MPMC_REG_15 */ /* DDR2 WRLVL_REG_EN BIT_8 0x01000000 */
	0x00000000, /* MPMC_REG_16 */
	0x00000000, /* MPMC_REG_17 */
	0x00000201, /* MPMC_REG_18 */ /* ORIG 00000303 */
	0x02010000, /* MPMC_REG_19 */ /* ORIG 0x02010102 */
	0x00020000, /* MPMC_REG_20 */
	0x03030001, /* MPMC_REG_21 */
	0x02030301, /* MPMC_REG_22 */
	0x03030303, /* MPMC_REG_23 */
	0x03030403, /* MPMC_REG_24 */
	0x03030305, /* MPMC_REG_25 */
	0x00000400, /* MPMC_REG_26 */
	0x02000200, /* MPMC_REG_27 */
	0x04030202, /* MPMC_REG_28 */
	0x01000103, /* MPMC_REG_29 */
	0x03000000, /* MPMC_REG_30 */
	0x0606060a, /* MPMC_REG_31 */
	0x06060606, /* MPMC_REG_32 */
	0x05050506, /* MPMC_REG_33 */
	0x05050505, /* MPMC_REG_34 */
	0x04040405, /* MPMC_REG_35 */
	0x04040404, /* MPMC_REG_36 */
	0x03030304, /* MPMC_REG_37 */
	0x03030303, /* MPMC_REG_38 */
	0x02020203, /* MPMC_REG_39 */
	0x02020202, /* MPMC_REG_40 */
	0x01010102, /* MPMC_REG_41 */
	0x01010101, /* MPMC_REG_42 */
	0x04000c01, /* MPMC_REG_43 */
	0x00000002, /* MPMC_REG_44 */
	0x00000204, /* MPMC_REG_45 */
	0x03070600, /* MPMC_REG_46 */
	0x02000505, /* MPMC_REG_47 */
	0x0000000c, /* MPMC_REG_48 */
	0x0c030206, /* MPMC_REG_49 */
	0x0200000c, /* MPMC_REG_50 */
	0x3f003f06, /* MPMC_REG_51 */
	0x19161200, /* MPMC_REG_52 */
	0x00000028, /* MPMC_REG_53 */
	0x00000000, /* MPMC_REG_54 */
	0x00000000, /* MPMC_REG_55 */
	0x00000000, /* MPMC_REG_56 */
	0x00004000, /* MPMC_REG_57 */
	0x03000000, /* MPMC_REG_58 */
	0x03031703, /* MPMC_REG_59 */
	0x06160504, /* MPMC_REG_60 */
	0x00006400, /* MPMC_REG_61 */
	0x00640064, /* MPMC_REG_62 */
	0x00640064, /* MPMC_REG_63 */
	0x000f0064, /* MPMC_REG_64 */
	0x0000000a, /* MPMC_REG_65 */
	0x00400100, /* MPMC_REG_66 */
	0x0c2d0200, /* MPMC_REG_67 */
	0x02000c2d, /* MPMC_REG_68 */
	0x02000200, /* MPMC_REG_69 */
	0x0c2d0200, /* MPMC_REG_70 */
	0x0a630a63, /* MPMC_REG_71 */
	0x00040004, /* MPMC_REG_72 */
	0x00000000, /* MPMC_REG_73 */
	0x00000000, /* MPMC_REG_74 */
	0xffffffff, /* MPMC_REG_75 */
	0xffffffff, /* MPMC_REG_76 */
	0xffffffff, /* MPMC_REG_77 */
	0x00000007, /* MPMC_REG_78 */
	0x00000000, /* MPMC_REG_79 */
	0x00000000, /* MPMC_REG_80 */
	0x00070000, /* MPMC_REG_81 */
	0x00070007, /* MPMC_REG_82 */
	0x00070007, /* MPMC_REG_83 */
	0x00000000, /* MPMC_REG_84 */
	0x00000000, /* MPMC_REG_85 */
	0x00030000, /* MPMC_REG_86 */
	0x00030003, /* MPMC_REG_87 */
	0x00030003, /* MPMC_REG_88 */
	0xffff0010, /* MPMC_REG_89 */
	0x00000000, /* MPMC_REG_90 */
	0x00000000, /* MPMC_REG_91 */
	0x00000000, /* MPMC_REG_92 */
	0x00000000, /* MPMC_REG_93 */
	0x00000000, /* MPMC_REG_94 */
	0x00000000, /* MPMC_REG_95 */
	0x00c800a0, /* MPMC_REG_96 */
	0x00000003, /* MPMC_REG_97 */
	0x0053000a, /* MPMC_REG_98 */
	0x000000c8, /* MPMC_REG_99 */
	0x00000000, /* MPMC_REG_100 */
	0x00000000, /* MPMC_REG_101 */
	0x00000000, /* MPMC_REG_102 */
	0x00000000, /* MPMC_REG_103 */
	0x00000000, /* MPMC_REG_104 */
	0x00000000, /* MPMC_REG_105 */
	0x00000000, /* MPMC_REG_106 */
	0x00000000, /* MPMC_REG_107 */
	0x00000000, /* MPMC_REG_108 */
	0x00000000, /* MPMC_REG_109 */
	0x00000000, /* MPMC_REG_110 */
	0x00000000, /* MPMC_REG_111 */
	0x00013880, /* MPMC_REG_112 */
	0x00000000, /* MPMC_REG_113 */
	0x000000c8, /* MPMC_REG_114 */
	0x00000050, /* MPMC_REG_115 */
	0x00000050, /* MPMC_REG_116 */
	0x00000050, /* MPMC_REG_117 */
	0x00000050, /* MPMC_REG_118 */
	0x00000050, /* MPMC_REG_119 */
	0x00000050, /* MPMC_REG_120 */
	0x00000000, /* MPMC_REG_121 */
	0x00000000, /* MPMC_REG_122 */
	0x000f1133, /* MPMC_REG_123 */
	0x00386100, /* MPMC_REG_124 */
	0x00386100, /* MPMC_REG_125 */
	0x00386100, /* MPMC_REG_126 */
	0x00386100, /* MPMC_REG_127 */
	0x00386100, /* MPMC_REG_128 */
	0x00000002, /* MPMC_REG_129 */
	0x1208a108, /* MPMC_REG_130 */
	0x1208a108, /* MPMC_REG_131 */
	0x1208a108, /* MPMC_REG_132 */
	0x1208a108, /* MPMC_REG_133 */
	0x1208a108, /* MPMC_REG_134 */
	0x01000000, /* MPMC_REG_135 */
	0x01000000, /* MPMC_REG_136 */
	0x01000000, /* MPMC_REG_137 */
	0x01000000, /* MPMC_REG_138 */
	0x01000000, /* MPMC_REG_139 */
	0x01000000, /* MPMC_REG_140 */
	0x01000000, /* MPMC_REG_141 */
	0x01000000, /* MPMC_REG_142 */
	0x01000000, /* MPMC_REG_143 */
	0x01000000, /* MPMC_REG_144 */
	0x06db6db6, /* MPMC_REG_145 */
	0x06db6db6, /* MPMC_REG_146 */
	0x06db6db6, /* MPMC_REG_147 */
	0x06db6db6, /* MPMC_REG_148 */
	0x06db6db6, /* MPMC_REG_149 */
	0x00000000, /* MPMC_REG_150 */
	0x00000000, /* MPMC_REG_151 */
	0x00000000, /* MPMC_REG_152 */
	0x00000000, /* MPMC_REG_153 */
	0x00000000, /* MPMC_REG_154 */
	0x2498a249, /* MPMC_REG_155 */
	0x2498a249, /* MPMC_REG_156 */
	0x2498a249, /* MPMC_REG_157 */
	0x2498a249, /* MPMC_REG_158 */
	0x2498a249, /* MPMC_REG_159 */
	0x04803219, /* MPMC_REG_160 */ /* ORIG 04800201 */
	0x04803219, /* MPMC_REG_161 */ /* ORIG 04800201 */
	0x04803219, /* MPMC_REG_162 */ /* ORIG 04800201 */
	0x04803219, /* MPMC_REG_163 */ /* ORIG 04800201 */
	0x04803219, /* MPMC_REG_164 */ /* ORIG 04800201 */
	0x00000000, /* MPMC_REG_165 */
	0x00000000, /* MPMC_REG_166 */
	0x00000000, /* MPMC_REG_167 */
	0x00000000, /* MPMC_REG_168 */
	0x00000000, /* MPMC_REG_169 */
	0x00000000, /* MPMC_REG_170 */
	0x00000000, /* MPMC_REG_171 */
	0x00000000, /* MPMC_REG_172 */
	0x00000000, /* MPMC_REG_173 */
	0x00000000, /* MPMC_REG_174 */
	0x00000000, /* MPMC_REG_175 */
	0x00000000, /* MPMC_REG_176 */
	0x00000000, /* MPMC_REG_177 */
	0x00000000, /* MPMC_REG_178 */
	0x00000000, /* MPMC_REG_179 */
	0x00000000, /* MPMC_REG_180 */
	0x00000000, /* MPMC_REG_181 */
	0x00000c2d, /* MPMC_REG_182 */
	0x00000c2d, /* MPMC_REG_183 */
	0x00000000, /* MPMC_REG_184 */
	0x00000c2d, /* MPMC_REG_185 */
	0x00000050, /* MPMC_REG_186 */
	0x00000000, /* MPMC_REG_187 */
	0x00000000, /* MPMC_REG_188 */
	0x00000000, /* MPMC_REG_189 */
	0x00000000, /* MPMC_REG_190 */
	0x00000000, /* MPMC_REG_191 */
	0x00000000, /* MPMC_REG_192 */
	0x00000000, /* MPMC_REG_193 */
	0x00000000, /* MPMC_REG_194 */
	0x00000000, /* MPMC_REG_195 */
	0x00000000, /* MPMC_REG_196 */
	0x00000000, /* MPMC_REG_197 */
	0x07000000, /* MPMC_REG_198 */
	0x00000007, /* MPMC_REG_199 */
	0x00000000, /* MPMC_REG_200 */
	0x00006d60, /* MPMC_REG_201 */
	0x0000004f, /* MPMC_REG_202 */
	0x00000000, /* MPMC_REG_203 */
	0x00000000, /* MPMC_REG_204 */
	0x00000000, /* MPMC_REG_205 */
	0x00000000, /* MPMC_REG_206 */
	0x00003ce1, /* MPMC_REG_207 */
};
#endif
