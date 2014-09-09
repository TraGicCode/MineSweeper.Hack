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
	MineSweeperHack(HMODULE gameBaseAddress);
	void SetTimer(int value);
	void SetMineCount(int mineCount);
	void ShowBombs();
};
