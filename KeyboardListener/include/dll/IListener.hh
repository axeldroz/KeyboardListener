//
// IListener.hh for IListener in c:\Users\49207\Documents\Epitech-Rendu\cpp_spider
//
// Made by Axel Drozdzynski
// Login   <drozdz_b>
//
// Started on  Sat Sep 29 14:27:00 2017 Axel Drozdzynski
// Last update Sat Sep 29 14:52:44 2017 Axel Drozdzynski
//

#ifndef ILISTENER_HH_
# define ILISTENER_HH_

#include <list>

class IListener
{
public:
	virtual int run() = 0;
	virtual int stop() = 0;
	virtual std::string getFilenameOutput() = 0;
	virtual int getElements(std::list<std::string>& list) = 0;
};

#endif /* !ILISTENER_HH_ */