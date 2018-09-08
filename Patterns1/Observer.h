//
//  Observer.h
//  Patterns1
//
//  Created by Alex Usachov on 3/9/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef Observer_h
#define Observer_h

#include <iostream>
#include <vector>

class GateSubject;

class IObserver
{
public:
    virtual ~IObserver()
    {
        std::cout << " ~IObserver() " << std::endl;
    }
    virtual void Update( GateSubject* subject ){};
};

class GateSubject
{
public:
    
    GateSubject():
    mClosed(true)
    {
        
    }
    
    ~GateSubject()
    {
        for ( auto Observer : mObservers )
        {
            delete Observer;
            Observer = nullptr;
        }
        
        mObservers.clear();
    }
    
    void AddObserver( IObserver* observer )
    {
        mObservers.push_back(observer);
    }
    
    void NotifyAll()
    {
        for ( auto Observer : mObservers )
        {
            Observer->Update( this );
        }
    }
    
    bool IsClosed()
    {
        return mClosed;
    }
    
    void Close()
    {
        if ( !IsClosed() )
        {
            mClosed = true;
            NotifyAll();
        }
    }
    
    void Open()
    {
        if ( IsClosed() )
        {
            mClosed = false;
            NotifyAll();
        }
    }
    
private:
    std::vector<IObserver*>     mObservers;
    bool                        mClosed;
};

class GateKey : public IObserver
{
public:
    void Update( GateSubject* subject )
    {
        if( !subject->IsClosed() )
        {
            std::cout << " Key is in keyhole " << std::endl;
        }
        else
        {
            std::cout << " Key isn't in keyhole " << std::endl;
        }
    }
};

class CarInYard : public IObserver
{
public:
    void Update( GateSubject* subject )
    {
        if( !subject->IsClosed() )
        {
            std::cout << " Car can drive in or drive out " << std::endl;
        }
        else
        {
            std::cout << " Car can't drive in or drive out if it's in yard " << std::endl;
        }
    }
};


#endif /* Observer_h */
