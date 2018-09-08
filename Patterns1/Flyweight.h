//
//  Flyweight.h
//  Patterns1
//
//  Created by Alex Usachov on 3/6/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef Flyweight_h
#define Flyweight_h

#include <map>

class Apple;
class Peach;

enum class FRUIT_TYPES : int8_t
{
    APPLE,
    PEACH
};

class IFruit
{
public:
    virtual ~IFruit(){};
    
};

class Apple: public IFruit
{
public:
    Apple(){};
};

class Peach: public IFruit
{
public:
    Peach(){};
};

class FruitFactory
{
public:
    
    static IFruit* Create( FRUIT_TYPES type )
    {
        if ( type == FRUIT_TYPES::APPLE )
        {
            return new Apple();
        }
        else if ( type == FRUIT_TYPES::PEACH )
        {
            return new Peach();
        }
        
        return nullptr;
    };
    
    IFruit* GetFruit( FRUIT_TYPES type )
    {
        if ( mFruits.count(type) == 0  )
        {
            mFruits[type] = Create(type);
        }
        
        return mFruits[type];
    }
private:
    std::map< FRUIT_TYPES, IFruit* > mFruits;
};

class FruitTree
{
public:
    FruitTree( int8_t pos, IFruit* fruit ):
    mPos(pos)
    , mFruit(fruit)
    {
        
    }
private:
    IFruit* mFruit;
    int8_t  mPos;
};



#endif /* Flyweight_h */
