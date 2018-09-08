//
//  Prototype.h
//  Patterns1
//
//  Created by Alex Usachov on 3/6/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef Prototype_h
#define Prototype_h

class IFoodClonable
{
public:
    virtual ~IFoodClonable(){}
    virtual IFoodClonable* Clone() = 0;
};

class Bread : public IFoodClonable
{
public:
    IFoodClonable* Clone(){ return new Bread; }
};

class Tomato : public IFoodClonable
{
public:
    IFoodClonable* Clone(){ return new Tomato; }
};


class PrototypeFoodFactory
{
public:
    PrototypeFoodFactory( Tomato* tomato, Bread* bread ):
    mTomato(tomato)
    , mBread(bread)
    {}
    
    ~PrototypeFoodFactory()
    {
        delete mTomato;
        delete mBread;
    }
    
    IFoodClonable*      GetTomato(){ return mTomato->Clone(); }
    IFoodClonable*      GetBread(){ return mBread->Clone(); }
    
private:
    Tomato*     mTomato;
    Bread*      mBread;
};

#endif /* Prototype_h */
