#include <iostream>
#include <mutex>
#include "Cheats.hpp"

using namespace std;
DWORD64 GameBase = 0;
HWND hwnd = 0;
Vector2 ScreenSize = { GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN) };

void main()
{
	if (!(I::installDriver("AXP4ER6S677APV6A77I09C")))
	{
		cout << "[!] Failed to install driver!" << endl;
		system("pause");
		exit(0);
	}

	if (!(I::isInstall()))
	{
		cout << "[!] Failed to connect driver!" << endl;
		system("pause");
		exit(0);
	}

	DWORD PID = 0;
	while (!PID)
	{
		cout << "[!] Waiting game process..." << endl;
		Sleep(2000);
		PID = I::GetProcessIdByName(L"r5apex_dx12.exe");
	}

	system("cls");
	cout << "[+] PID: " << PID << endl;

	I::SetProcess(PID);
	GameBase = I::GetModuleBase("r5apex_dx12.exe");
	if (!GameBase)
	{
		cout << "[!] Failed to get region!" << endl;
		system("pause");
		exit(0);
	}

	cout << "[+] Base: " << hex << GameBase << endl;

	while (!hwnd)
	{
		hwnd = FindWindowA("Respawn001", "Apex Legends");
		Sleep(2000);
	}
	cout << "[+] Game HWND: " << hwnd << endl;
		
	try
	{
		extern mutex AccessPermission;
		Gui.AttachAnotherWindow("Apex Legends", "Respawn001", fun::Fun);
	}
	catch (OSImGui::OSException& e)
	{
		cout << e.what() << endl;
	}
	return;
}