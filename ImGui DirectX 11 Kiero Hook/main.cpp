#include "dx/hook/present.h"

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	AllocConsole();
	FILE* file;
	freopen_s(&file, "CONOUT$", "w", stdout);

	IL2CPP::Initialize();
	Hooks::Initialize();

	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&Present::oPresent, Present::hkPresent);
			init_hook = true;
		}
	} while (!init_hook);

	while (true) {
		if (GetAsyncKeyState(VK_INSERT) & 1)
			Menu::bMenuOpened = !Menu::bMenuOpened;
		Sleep(10);
	}

	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}