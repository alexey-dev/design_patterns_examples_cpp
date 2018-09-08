//
//  State.h
//  Patterns1
//
//  Created by Alex Usachov on 3/9/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef State_h
#define State_h

#include <iostream>

class Programmer;

class IProgrammerState
{
public:
    
    virtual ~IProgrammerState()
    {
        
    }
    virtual void CamoToWork(Programmer* owner) = 0;
    virtual void DrinkCoffe(Programmer* owner) = 0;
    virtual void WorkAnHour(Programmer* owner) = 0;
};

class FreshMindState: public IProgrammerState
{
public:

    void CamoToWork(Programmer* owner);
    
    void DrinkCoffe(Programmer* owner);
    
    void WorkAnHour(Programmer* owner);
    
};

class TiredState: public IProgrammerState
{
public:
    
    void CamoToWork(Programmer* owner);
    
    void DrinkCoffe(Programmer* owner);
    
    void WorkAnHour(Programmer* owner);
    
};

class Programmer
{
public:
    friend class FreshMindState;
    friend class TiredState;
    
    Programmer():
     mWorkedHoursCount(0)
    , mState(nullptr)
    {
        ChangeState( new FreshMindState );
    }
    
    
    void CamoToWork()
    {
        mState->CamoToWork(this);
    }
    void DrinkCoffe()
    {
        mState->DrinkCoffe(this);
    }
    void WorkAnHour()
    {
        mState->WorkAnHour(this);
    }
    
    void ChangeState( IProgrammerState* NewState )
    {
        if ( mState != nullptr )
        {
            delete mState;
            mState = nullptr;
        }
        
        mState = NewState;
    }
    
private:
    int8_t              mWorkedHoursCount;
    IProgrammerState*   mState;
};

void FreshMindState::CamoToWork(Programmer* owner)
{
    std::cout << "Fresh: I'm happy to work!" << std::endl;
    owner->mWorkedHoursCount = 0;
}
void FreshMindState::DrinkCoffe(Programmer* owner)
{
    std::cout << "Fresh: I still fresh, no need in coffe!" << std::endl;
}
void FreshMindState::WorkAnHour(Programmer* owner)
{
    std::cout << "Fresh: Hour passed and I was happy to code during this hour!" << std::endl;
    owner->mWorkedHoursCount++;
    if ( owner->mWorkedHoursCount >= 4 )
    {
        owner->ChangeState(new TiredState);
    }
}

void TiredState::CamoToWork(Programmer* owner)
{
    std::cout << "Tired: It's hard to work for me now!" << std::endl;
    owner->mWorkedHoursCount = 0;
}
void TiredState::DrinkCoffe(Programmer* owner)
{
    std::cout << "Tired: I'm so tired, coffe saves an hour!" << std::endl;
    owner->mWorkedHoursCount--;
    if ( owner->mWorkedHoursCount <= 4 )
    {
        owner->ChangeState(new FreshMindState);
    }
}
void TiredState::WorkAnHour(Programmer* owner)
{
    std::cout << "Tired: Can't work now!" << std::endl;
}

#endif /* State_h */
