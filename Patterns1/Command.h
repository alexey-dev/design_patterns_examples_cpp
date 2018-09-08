//
//  Command.h
//  Patterns1
//
//  Created by Alex Usachov on 2/28/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef Command_h
#define Command_h

#include <iostream>

class ICommand
{
public:
    virtual ~ICommand(){}
    virtual void Exec() = 0;
};

class StartCommand: public ICommand
{
public:
    ~StartCommand(){}
    virtual void Exec()
    {
        std::cout << "Start" << std::endl;
    }
};

class StopCommand: public ICommand
{
public:
    ~StopCommand(){}
    virtual void Exec()
    {
        std::cout << "Stop" << std::endl;
    }
};

class PlayCommand: public ICommand
{
public:
    ~PlayCommand(){}
    virtual void Exec()
    {
        std::cout << "Play" << std::endl;
    }
};


#endif /* Command_h */
