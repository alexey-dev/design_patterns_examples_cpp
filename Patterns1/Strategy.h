//
//  Strategy.h
//  Patterns1
//
//  Created by Alex Usachov on 2/26/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef Strategy_h
#define Strategy_h

#include <vector>

class IStrategy
{
public:
    virtual int32_t Calc( std::vector<int8_t>& data ) = 0;
    
    virtual ~IStrategy() {}
};

class SumStrategy : public IStrategy
{
public:
    virtual int32_t Calc( std::vector<int8_t>& data )
    {
        int32_t res = 0;
        for ( auto el : data )
        {
            res += el;
        }
        
        return res;
    }
    
};

class MulStrategy : public IStrategy
{
public:
    virtual int32_t Calc( std::vector<int8_t>& data )
    {
        int32_t res = data.size() == 0 ? 0 : 1;
        for ( auto el : data )
        {
            res *= el;
        }
        
        return res;
    }
    
};

class ContentVector
{
public:
    ContentVector(IStrategy*  strategy, const std::vector<int8_t>& data):
    mStrategy(strategy)
    , mData(data)
    {
        
    }
    
    ~ContentVector()
    {
        delete mStrategy;
        mData.clear();
    }
    
    int32_t Calc()
    {
        return mStrategy->Calc(mData);
    }
private:
    IStrategy*  mStrategy;
    std::vector<int8_t> mData;
};

#endif /* Strategy_h */
