//
//  Mediator.h
//  Patterns1
//
//  Created by Alex Usachov on 3/8/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef Mediator_h
#define Mediator_h

#include <iostream>

class IMediator
{
public:
    virtual ~IMediator(){};
    virtual void GoalScored() = 0;
    virtual void CrowdOnfield() = 0;
};

class IMediatorElement
{
public:
    virtual ~IMediatorElement(){};
    IMediatorElement( IMediator*  mediator ):
    mMediator(mediator)
    {
        
    };
protected:
    IMediator*  mMediator;
};

class Crowd : private IMediatorElement
{
public:
    Crowd(IMediator*  mediator):
    IMediatorElement( mediator )
    {
        
    }
    void ReactionGoalScored()
    {
        std::cout << "Crowd happy on goal" << std::endl;
    }
    void ReactionRunOnField()
    {
        std::cout << "Crowd crazy on field" << std::endl;
    }
    void ActionRunOnField()
    {
        mMediator->CrowdOnfield();
    }
private:
    
};
class BallEl : private IMediatorElement
{
public:
    BallEl(IMediator*  mediator):
    IMediatorElement( mediator )
    {
        
    }
    void ReactionGoalScored()
    {
        std::cout << "Ball is in gate" << std::endl;
    }
    void ReactionRunOnField()
    {
        std::cout << "Ball is in crowd's hands" << std::endl;
    }
    void ActionGoal()
    {
        mMediator->GoalScored();
    }
private:
    
};

class FootballMediator : public IMediator
{
public:
    FootballMediator()
    {
        mBall = new BallEl(this);
        mCrowd = new Crowd(this);
    };
    
    void GoalScored()
    {
        mBall->ReactionGoalScored();
        mCrowd->ReactionGoalScored();
    }
    void CrowdOnfield()
    {
        mBall->ReactionRunOnField();
        mCrowd->ReactionRunOnField();
    }
    
    void GenerateGoal()
    {
        mBall->ActionGoal();
    }
    
    void GenerateCrowdRun()
    {
        mCrowd->ActionRunOnField();
    }
    
private:
    BallEl *    mBall;
    Crowd *     mCrowd;
};


#endif /* Mediator_h */
