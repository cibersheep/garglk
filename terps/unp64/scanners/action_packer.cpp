/* This is a cut-down version of UNP64 with only the bare minimum
 * needed to decompress a number of Commodore 64 adventure games.
 * It is distributed under the zlib License by kind permission of
 * the original authors Magnus Lind and iAN CooG.
 */

/*
 UNP64 - generic Commodore 64 prg unpacker
 (C) 2008-2022 iAN CooG/HVSC Crew^C64Intros
 original source and idea: testrun.c, taken from exo20b7

 Follows original disclaimer
 */

/*
 * Copyright (c) 2002 - 2023 Magnus Lind.
 *
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 */

/*
 C++ version based on code adapted to ScummVM by Avijeet Maurya
 */

#include "types.h"
#include "unp64.h"
#include "exo_util.h"

namespace Unp64 {

void scnActionPacker(UnpStr *unp) {
	uint8_t *mem;

	if (unp->_idFlag)
		return;
	mem = unp->_mem;
	if (unp->_depAdr == 0) {
		if (u32eq(mem + 0x811, 0x018538A9) &&
			u32eq(mem + 0x81d, 0xCEF7D0E8) &&
			u32eq(mem + 0x82d, 0x0F9D0837) &&
			u32eq(mem + 0x84b, 0x03D00120)) {
			unp->_depAdr = 0x110;
			unp->_forced = 0x811;
			unp->_strMem = READ_LE_UINT16(&mem[0x848]);
			unp->_fEndAf = 0x120;
			unp->_retAdr = READ_LE_UINT16(&mem[0x863]);
			unp->_idFlag = 1;
			return;
		}
	}
}

} // End of namespace Unp64
