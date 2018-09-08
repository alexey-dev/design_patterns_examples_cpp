//
//  ChainOfResponsibility.h
//  Patterns1
//
//  Created by Alex Usachov on 3/7/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef ChainOfResponsibility_h
#define ChainOfResponsibility_h

#include <iostream>

class ICmd
{
public:
    virtual ~ICmd()
    {
        std::cout << "~Destr cmd " << std::endl;
    }
    virtual void Execute() = 0;
};

class PlayCmd : public ICmd
{
public:
    void Execute()
    {
        std::cout << "Play executed" << std:: endl;
    }
};

class FinishCmd : public ICmd
{
public:
    void Execute()
    {
        std::cout << "Finish executed" << std:: endl;
    }
};


class Base
{
public:
    Base():
    mNext(nullptr)
    {
        
    }
    virtual ~Base()
    {
        std::cout << "~Destr()" << std::endl;
        if ( mNext != nullptr )
        {
            std::cout << "~Destr() for lower" << std::endl;
            delete mNext;
            mNext = nullptr;
        }
    }
    
    void Add( Base* el )
    {
        if ( mNext != nullptr )
        {
            mNext->Add(el);
        }
        else
        {
            mNext = el;
        }
    }
    
    virtual void Handle ( ICmd* cmd )
    {
        if ( mNext != nullptr )
        {
            mNext->Handle(cmd);
        }
    }
    
private:
    Base*   mNext;
};

class PlayEl : public Base
{
public:
    void Handle ( ICmd* cmd )
    {
        PlayCmd * c = dynamic_cast<PlayCmd *>(cmd);
        if ( c != nullptr )
        {
            c->Execute();
        }
        std::cout << "PlayEl executed" << std::endl;
    }
};

class FinishEl : public Base
{
public:
    void Handle ( ICmd* cmd )
    {
        FinishCmd * c = dynamic_cast<FinishCmd *>(cmd);
        if ( c != nullptr )
        {
            c->Execute();
        }
        std::cout << "FinishEl executed" << std::endl;
    }
};

#endif /* ChainOfResponsibility_h */
