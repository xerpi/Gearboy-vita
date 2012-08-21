/* 
 * Gearboy Gameboy Emulator
 * Copyright (C) 2012 Ignacio Sanchez
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 * The full license is available at http://www.gnu.org/licenses/gpl.html
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#ifndef MBC2MEMORYRULE_H
#define	MBC2MEMORYRULE_H

#include "MemoryRule.h"

class MBC2MemoryRule : public MemoryRule
{
public:
    MBC2MemoryRule(Processor* pProcessor, Memory* pMemory, 
            Video* pVideo, Input* pInput, Cartridge* pCartridge);
    virtual ~MBC2MemoryRule();
    virtual u8 PerformRead(u16 address);
    virtual void PerformWrite(u16 address, u8 value);
    virtual void Reset();
private:
    int m_iCurrentROMBank;
    bool m_bRamEnabled;
    u8 m_HigherRomBankBits;
};

#endif	/* MBC2MEMORYRULE_H */
