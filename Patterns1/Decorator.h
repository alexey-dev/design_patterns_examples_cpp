//
//  Decorator.h
//  Patterns1
//
//  Created by Alex Usachov on 2/26/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef Decorator_h
#define Decorator_h

#include <iostream>

class ITransport
{
public:
    virtual void Ride() = 0;
    virtual ~ITransport(){};
};

class CleanCar : public ITransport
{
public:
    void Ride()
    {
        std::cout << " Car moved and cleaned road " << std::endl;
    }
    
};

class WashCar : public ITransport
{
public:
    void Ride()
    {
        std::cout << " Car moved and washed road by water " << std::endl;
    }
    
};

class IDecoratorCar : public ITransport
{
public:
    void Ride()
    {
        mBaseTransport->Ride();
    };
    
    IDecoratorCar( ITransport * transport ):
     mBaseTransport(transport)
    {
        
    }
    
    ~IDecoratorCar()
    {
        delete mBaseTransport;
    }
private:
    ITransport*     mBaseTransport;
};

class CarWithDisel : public IDecoratorCar
{
public:
    CarWithDisel( ITransport* transport ):
    IDecoratorCar(transport)
    {
        
    }
    
    void Ride()
    {
        IDecoratorCar::Ride();
        std::cout << "car has diesel engine and works loud" << std::endl;
    }
};

class CarWithBigMirror : public IDecoratorCar
{
public:
    CarWithBigMirror( ITransport* transport ):
    IDecoratorCar(transport)
    {
        
    }
    
    void Ride()
    {
        IDecoratorCar::Ride();
        std::cout << "car has big mirror and is very preety" << std::endl;
    }
};


#endif /* Decorator_h */
