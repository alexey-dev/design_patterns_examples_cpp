//
//  Memento.h
//  Patterns1
//
//  Created by Alex Usachov on 3/8/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef Memento_h
#define Memento_h

#include <iostream>

class UnitOriginator;

class MementoUnit
{
    friend class UnitOriginator;
    
    void SetState ( int32_t health, int32_t armor )
    {
        mArmor = armor;
        mHealth = health;
    }
    
    int32_t mHealth;
    int32_t mArmor;
};

class UnitOriginator
{
public:
    UnitOriginator():
    mHealth(100)
    ,mArmor(50)
    {
        
    }
    
    void TakeDamage( int32_t damage )
    {
        const int32_t StartDamage = damage;
        
        std::cout << "Unit takes" << StartDamage << " damage" << std::endl;
        
        damage -= mArmor;
        
        if ( damage > 0 )
        {
            mArmor = 0;
            mHealth -= damage;
            
            if ( mHealth <= 0 )
            {
                std::cout << "Unit defeated" << std::endl;
            }
        }
        else
        {
            mArmor -= StartDamage;
        }
    }
    
    void SetMemento( MementoUnit * memento )
    {
        mHealth = memento->mHealth;
        mArmor = memento->mArmor;
    }
    
    MementoUnit* CreateMemento()
    {
        MementoUnit * Munit = new MementoUnit;
        Munit->SetState( mHealth, mArmor );
        return Munit;
    }
    
private:
    int32_t mHealth;
    int32_t mArmor;
};

#endif /* Memento_h */
