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

#if defined(CONFIG_SPEAR13XX) && \
	(CONFIG_DDR_MT41J256M8) && (CONFIG_DDR_FREQ_400)
const u32 mpmc_conf_vals[CONFIG_SPEAR_MPMCREGS] = {
	0x00000101,
	0x00000100,
	0x01010000,
	0x00000100,
	0x00000000,
	0x00010101,
	0x00000001,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000101,
	0x00000101,
	0x01010000,
	0x00000000,
	0x01000000,
	0x00000000,
	0x00000000,
	0x00000001,
	0x02010102,
	0x00020000,
	0x07070000,	/* Changing DB9000AXI priority to high */
	0x00070700,	/* due to flickering issue on display */
	0x07000707,	/* form DENALI_CTL_21 to DENALI_CTL_25 */
	0x00000007,
	0x03070700,
	0x00000400,
	0x02000100,
	0x04030402,
	0x01000104,
	0x02020000,
	0x0606060a,
	0x06060606,
	0x05050506,
	0x05050505,
	0x04040405,
	0x04040404,
	0x03030304,
	0x03030303,
	0x02020203,
	0x02020202,
	0x01010102,
	0x01010101,
	0x06060c01,
	0x00000000,
	0x00000204,
	0x04070602,
	0x02000505,
	0x00000e0c,
	0x0c040406,
	0x06020008,
	0x3f003f06,
	0x19150f00,
	0x00000028,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00004000,
	0x03000000,
	0x03030c03,
	0x060f0c04,
	0x00006456, /*VM sshould  be 0x56  for 187E*/
	0x00640064,
	0x00640064,
	0x000f0064,
	0x0000000a,
	0x00400100,
	0x0c2d0200,
	0x0c2d0c2d,
	0x0c2d0c2d,
	0x0c2d0c2d,
	0x04200420,
	0x00460046,
	0x00000000,
	0x00000000,
	0xff005555,
	0xaaaa00ff,
	0xff005555,
	0x00000007,
	0x00000000,
	0x00000000,
	0x00070000,
	0x00070007,
	0x00070007,
	0x00000000,
	0x00000000,
	0x00030000,
	0x00030003,
	0x00030003,
	0xffff0010,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x02000000,
	0x6da60003,
	0x0044000a,
	0x00000200,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000001,
	0x00000001,
	0x00000001,
	0x00000001,
	0x00000001,
	0x0000ffff, /*VM TINIT max values*/
	0x00000000,
	0x00030d40,
	0x00000050,
	0x00000050,
	0x00000050,
	0x00000050,
	0x00000050,
	0x00000050,
	0x00000000,
	0x00000000,
	0x000f1133,
	0x00304001,
	0x00304001,
	0x00304001,
	0x00304001,
	0x00304001,
	0x00000002,
	0x2288a108,
	0x2288a108,
	0x2288a108,
	0x2288a108,
	0x2288a108,
	0x01000000,
	0x01000000,
	0x01000000,
	0x01000000,
	0x01000000,
	0x01000000,
	0x01000000,
	0x01000000,
	0x01000000,
	0x01000000,
	0x06db6db6,
	0x06db6db6,
	0x06db6db6,
	0x06db6db6,
	0x06db6db6,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x2494a249,
	0x2494a249,
	0x2494a249,
	0x2494a249,
	0x2494a249,
	0x04803219,
	0x04803219,
	0x04803219,
	0x04803219,
	0x04803219,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000c2d,
	0x00000c2d,
	0x00000000,
	0x00000c2d,
	0x00013880,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x07000000,
	0x00000007,
	0x00000000,
};
#endif
