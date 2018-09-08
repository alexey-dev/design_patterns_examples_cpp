//
//  AbstractFactories.h
//  Patterns1
//
//  Created by Alex Usachov on 2/26/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef AbstractFactories_h
#define AbstractFactories_h

enum class eUnits: uint8_t
{
    Warrior = 0,
    Archer = 1,
    Horse = 2
};

class IWarrior
{
public:
    virtual void Walk() = 0;
    ~IWarrior(){};
};

class IArcher
{
public:
    virtual void Shoot() = 0;
    ~IArcher(){};
};

class IHorse
{
public:
    virtual void Ride() = 0;
    ~IHorse(){};
};


class IAbstractFactoryUnits
{
public:
    virtual IWarrior* CreateWarrior() = 0;
    virtual IArcher* CreateArcher() = 0;
    virtual IHorse* CreateHorse() = 0;
    ~IAbstractFactoryUnits(){};
};

//Red commands
class RedWarrior: public IWarrior
{
public:
    void Walk(){ std::cout<<typeid(this).name()<<"\t"<< " walk" <<"\n"; };
};
class RedArcher: public IArcher
{
public:
    void Shoot(){std::cout<<typeid(this).name()<<"\t"<< " shot" <<"\n";};
};
class RedHorse: public IHorse
{
public:
    void Ride(){std::cout<<typeid(this).name()<<"\t"<< " ride" <<"\n";};
};

//Green commands
class GreenWarrior: public IWarrior
{
public:
    void Walk(){std::cout<<typeid(this).name()<<"\t"<< " walk" <<"\n";};
};
class GreenArcher: public IArcher
{
public:
    void Shoot(){std::cout<<typeid(this).name()<<"\t"<< " shot" <<"\n";};
};
class GreenHorse: public IHorse
{
public:
    void Ride(){std::cout<<typeid(this).name()<<"\t"<< " ride" <<"\n";};
};

class GreenFactory: public IAbstractFactoryUnits
{
    IWarrior* CreateWarrior(){ return new GreenWarrior();}
    IArcher* CreateArcher(){ return new GreenArcher();}
    IHorse* CreateHorse(){ return new GreenHorse();}
};

class RedFactory: public IAbstractFactoryUnits
{
    IWarrior* CreateWarrior(){ return new RedWarrior();}
    IArcher* CreateArcher(){ return new RedArcher();}
    IHorse* CreateHorse(){ return new RedHorse();}
};


#endif /* AbstractFactories_h */
