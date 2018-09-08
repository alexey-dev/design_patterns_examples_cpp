//
//  Bridge.h
//  Patterns1
//
//  Created by Alex Usachov on 2/28/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef Bridge_h
#define Bridge_h

#include <iostream>

class IRaceVehicle;

class IImplementationRace
{
public:
    virtual ~IImplementationRace(){};
    virtual void    ImplDrive(IRaceVehicle* vehicle) = 0;
    virtual void    ImplStop(IRaceVehicle* vehicle) = 0;
};

class IRaceVehicle
{
public:
    IRaceVehicle(IImplementationRace * implementation):
     mImplementation(implementation)
    {}
    virtual ~IRaceVehicle()
    {
        delete mImplementation;
    };
    virtual void    Drive() = 0;
    virtual void    Stop() = 0;
protected:
    IImplementationRace * mImplementation;
};

class RaceCar: public IRaceVehicle
{
public:
    RaceCar(IImplementationRace * implementation):
    IRaceVehicle(implementation)
    {}
    ~RaceCar(){};
    
    void    Drive()
    {
        mImplementation->ImplDrive( this );
    }
    void    Stop()
    {
        mImplementation->ImplStop( this );
    }
};

class JeepCar: public IRaceVehicle
{
public:
    JeepCar(IImplementationRace * implementation):
    IRaceVehicle(implementation)
    {}
    ~JeepCar(){};
    
    void    Drive()
    {
        mImplementation->ImplDrive( this );
    }
    void    Stop()
    {
        mImplementation->ImplStop( this );
    }
};

class ImplementationSnowyRace : public IImplementationRace
{
public:
    ~ImplementationSnowyRace(){};
    void    ImplDrive(IRaceVehicle* vehicle)
    {
        std::cout << typeid(vehicle).name() << " drives on snowy race" << std::endl;
    }
    void    ImplStop(IRaceVehicle* vehicle)
    {
        std::cout << typeid(vehicle).name() << " stops on snowy race" << std::endl;
    }
};

class ImplementationRainyRace : public IImplementationRace
{
public:
    ~ImplementationRainyRace(){};
    void    ImplDrive(IRaceVehicle* vehicle)
    {
        std::cout << typeid(vehicle).name() << " drives on rainy race" << std::endl;
    }
    void    ImplStop(IRaceVehicle* vehicle)
    {
        std::cout << typeid(vehicle).name() << " stops on rainy race" << std::endl;
    }
};

#endif /* Bridge_h */
