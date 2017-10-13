 //
// IziHook.hh for IziHook in c:\Users\49207\Documents\Epitech-Rendu\cpp_spider\include\dll
//
// Made by Axel Drozdzynski
// Login   <drozdz_b>
//
// Started on  Sat Oct 6 19:27:05 2017 Axel Drozdzynski
// Last update Sat Oct 6 19:27:11 2017 Axel Drozdzynski
//

#ifndef IZIHOOK_HH_
#define IZIHOOK_HH_

#include <windows.h>
#include <string>
#include <list>

#ifdef BUILD_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif


	//int __declspec(dllexport) install();
	int  __declspec(dllexport) getElements(std::list<std::string>& list);

#ifdef __cplusplus
}
#endif

#endif