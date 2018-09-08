//
//  Facade.h
//  Patterns1
//
//  Created by Alex Usachov on 3/5/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef Facade_h
#define Facade_h

#include <iostream>

#define SAFE_DEL(pt) {if((pt)!=nullptr){delete (pt); (pt) = nullptr;}}

class Team
{
public:
    void PlayersOnLine()
    {
        std::cout << "Players on line" << std::endl;
    }
    void PlayersPlay()
    {
        std::cout << "Players play" << std::endl;
    }
    void GameFinished()
    {
        std::cout << "Players won!" << std::endl;
    }
};

class Coach
{
public:
    void OnStartingGame()
    {
        std::cout << "Coach is woried" << std::endl;
    }
    void GameisPlaing()
    {
        std::cout << "Coach shouts" << std::endl;
    }
    void GameFinished()
    {
        std::cout << "Coach happy!" << std::endl;
    }
};

class Ball
{
public:
    void StartGame()
    {
        std::cout << "Ball is on line" << std::endl;
    }
    void Play()
    {
        std::cout << "Goal!" << std::endl;
    }
    void GameFinished()
    {
        std::cout << "Ball is resting" << std::endl;
    }
};

class FootballGame
{
public:
    FootballGame():
     mTeam( new Team )
    , mCoach( new Coach )
    , mBall( new Ball )
    {
        
    }
    
    void Start()
    {
        std::cout << " Game starts: " << std::endl;
        mTeam->PlayersOnLine();
        mBall->StartGame();
        mCoach->OnStartingGame();
    }
    
    void Play()
    {
        std::cout << " Game is playing: " << std::endl;
        mTeam->PlayersPlay();
        mBall->Play();
        mCoach->GameisPlaing();
    }
    
    void Finish()
    {
        std::cout << " Game finished: " << std::endl;
        mTeam->GameFinished();
        mBall->GameFinished();
        mCoach->GameFinished();
    }
    
    ~FootballGame()
    {
        SAFE_DEL(mBall);
        SAFE_DEL(mTeam);
        SAFE_DEL(mCoach);
    }
    
private:
    Team*       mTeam;
    Coach*      mCoach;
    Ball*       mBall;
};

#endif /* Facade_h */
