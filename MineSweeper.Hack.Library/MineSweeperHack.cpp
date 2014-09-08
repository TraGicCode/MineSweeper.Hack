#include "Precompiled.h"
#include "MineSweeperHack.h"


struct DataOffsets
{
	static const DWORD MINECOUNT = 0x56A4;
	static const DWORD TIMER = 0x579C;
};

MineSweeperHack::MineSweeperHack(HMODULE baseAddress)
	: m_GameBaseAddress(reinterpret_cast<DWORD>(baseAddress))
{
	ASSERT(m_GameBaseAddress);
}

void MineSweeperHack::SetMineCount(int mineCount)
{
	ASSERT(m_GameBaseAddress);
	*(PDWORD)(m_GameBaseAddress + DataOffsets::MINECOUNT) = mineCount;
}

void MineSweeperHack::SetTimer(int value)
{
	ASSERT(m_GameBaseAddress);
	*(PDWORD)(m_GameBaseAddress + DataOffsets::TIMER) = value;
}