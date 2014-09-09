#pragma once
#include "Precompiled.h"

#ifdef MINESWEEPER_HACK_LIBRARY_EXPORT
#define MINESWEEPER_HACK_LIBRARY_API __declspec(dllexport)
#else
#define MINESWEEPER_HACK_LIBRARY_API __declspec(dllimport)
#endif

class MINESWEEPER_HACK_LIBRARY_API MineSweeperHack
{
private:
	DWORD m_GameBaseAddress;
public:
	explicit MineSweeperHack(HMODULE gameBaseAddress);
    MineSweeperHack(const MineSweeperHack&) = delete;
	MineSweeperHack& operator=(const MineSweeperHack&) = delete;
	void SetTimer(int value);
	void SetMineCount(int mineCount);
	void ShowBombs();
};
