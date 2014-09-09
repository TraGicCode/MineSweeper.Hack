// dllmain.cpp : Defines the entry point for the DLL application.
#include "Precompiled.h"


auto WINAPI MainThread(LPVOID) -> DWORD
{
	// NOTE: Passing NULL/nullptr to GetModuleHandle will return the base address of the image file, that is minesweeper.
	MineSweeperHack hack = MineSweeperHack(GetModuleHandle(nullptr));
	hack.SetMineCount(2);
	hack.SetTimer(0);
	hack.ShowBombs();
	return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID
	)

{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		VERIFY(DisableThreadLibraryCalls(hModule));
		CreateThread(
			NULL,
			0,
			MainThread,
			NULL,
			0,
			NULL);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

