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

#include "MemoryCell.h"

MemoryCell::MemoryCell()
{
    Reset();
}

void MemoryCell::Reset()
{
    m_iWriteCount = 0;
    m_iReadCount = 0;
    m_szDisassembled[0] = 0;
    m_Register.SetValue(0);
    m_OldRegister.SetValue(0);
}

u8 MemoryCell::Read()
{
    m_iReadCount++;
    return m_Register.GetValue();
}

void MemoryCell::Write(u8 value)
{
    m_iWriteCount++;
    m_OldRegister.SetValue(m_Register.GetValue());
    m_Register.SetValue(value);
}

void MemoryCell::SetDisassembledString(const char* szDisassembled)
{
    strcpy(m_szDisassembled, szDisassembled);
}

char* MemoryCell::GetDisassembledString() 
{
    return m_szDisassembled;
}

unsigned int MemoryCell::GetReadCount() const
{
    return m_iReadCount;
}

unsigned int MemoryCell::GetWriteCount() const
{
    return m_iWriteCount;
}

u8 MemoryCell::GetOldValue() const
{
    return m_OldRegister.GetValue();
}

u8 MemoryCell::GetValue() const
{
    return m_Register.GetValue();
}

void MemoryCell::SetValue(u8 value)
{
    m_Register.SetValue(value);
}
