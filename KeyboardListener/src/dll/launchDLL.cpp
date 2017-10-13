//
// Created by Axel Drozdzynski on 07/10/2017.
//

#include <windows.h>
#include <string>
#include <iostream>
#include <list>

#include "IListener.hh"

int main()
{
    std::cout << "Hello World" << std::endl;
    HINSTANCE dll1 = LoadLibrary("KeyboardListener.dll");
	std::list<std::string> list;

    if (!dll1)
    {
        std::cout << "Could not laod the dynamic library" << std::endl;
        std::cout << "<Enter> to quit" << std::endl;
        getchar();
        return (42);
    }


    IListener* (*create)();
    void(*destroy)(IListener*);

    create = (IListener* (*)())GetProcAddress(dll1, "create");
    destroy = (void(*)(IListener*))GetProcAddress(dll1, "destroy");

    if (!create || !destroy)
    {
        std::cout << "could not locate the function"
                  << std::endl;
        std::cout << "<Enter> to quit" << std::endl;
        getchar();
        return (43);
    }

    IListener* obj = (IListener*)create();
	obj->run();
	getchar();
	obj->stop();
	destroy(obj);
	std::cout << "objet detruit" << std::endl;
	getchar();
	FreeLibrary(dll1);
	getchar();
	Sleep(3000);
    return 0;
}