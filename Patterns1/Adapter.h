//
//  Adapter.h
//  Patterns1
//
//  Created by Alex Usachov on 3/5/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef Adapter_h
#define Adapter_h

#include <iostream>

class IAdaptee
{
public:
    virtual ~IAdaptee(){}
    
    virtual void BuildFundament(){ std::cout << "Fundament" << std::endl; };
    virtual void BuildWalls(){ std::cout << "Walls" << std::endl; };
    virtual void BuildRoof(){ std::cout << "Roof" << std::endl; };
};

class ITarget
{
public:
    virtual ~ITarget(){};
    virtual void BuildHouse() = 0;
};

class AdapterClass : public ITarget, IAdaptee
{
public:
    void BuildHouse()
    {
        std::cout << "House class" << std::endl;
        BuildFundament();
        BuildWalls();
        BuildRoof();
    }
};

class AdapterObject : public ITarget
{
public:
    AdapterObject( IAdaptee* adaptee ):
    mAdapteeObject(adaptee)
    {
        
    }
    ~AdapterObject()
    {
        delete mAdapteeObject;
        mAdapteeObject = nullptr;
    }
    
    void BuildHouse()
    {
        std::cout << "House obj" << std::endl;
        mAdapteeObject->BuildFundament();
        mAdapteeObject->BuildWalls();
        mAdapteeObject->BuildRoof();
    }
private:
    IAdaptee*    mAdapteeObject;
};


#endif /* Adapter_h */
