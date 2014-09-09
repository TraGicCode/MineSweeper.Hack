#include "Precompiled.h"
#include "MineSweeperEnums.h"
#include "MineSweeperHack.h"


struct DataOffsets
{
	static const DWORD MINECOUNT = 0x56A4;
	static const DWORD TIMER = 0x579C;
};

typedef void(__stdcall *ShowBombsFn)(DWORD);

struct FunctionOffsets
{
	static const DWORD SHOW_BOMBS = 0x2F80;
};

MineSweeperHack::MineSweeperHack(HMODULE baseAddress)
	: m_GameBaseAddress(reinterpret_cast<DWORD>(baseAddress))
{
	ASSERT(m_GameBaseAddress);
}

auto MineSweeperHack::SetMineCount(int mineCount) -> void
{
	ASSERT(m_GameBaseAddress);
	*reinterpret_cast<PDWORD>(m_GameBaseAddress + DataOffsets::MINECOUNT) = mineCount;
}

auto MineSweeperHack::SetTimer(int value) -> void
{
	ASSERT(m_GameBaseAddress);
	*reinterpret_cast<PDWORD>(m_GameBaseAddress + DataOffsets::TIMER) = value;
}

auto MineSweeperHack::ShowBombs() -> void
{
	ASSERT(m_GameBaseAddress);
	reinterpret_cast<ShowBombsFn>(m_GameBaseAddress + FunctionOffsets::SHOW_BOMBS)(static_cast<DWORD>(ENUMS::BOMB));
}