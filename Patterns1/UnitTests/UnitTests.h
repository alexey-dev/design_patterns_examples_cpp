//
//  Unittest
//  TestUnittest
//
//  Created by Alex Usachov on 2/15/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include "../AbstractFactories.h"


using namespace std;

int32_t fibonacci( int32_t number );

struct TestResult
{
    int32_t mTotalCount;
    int32_t mSucceded;
    
    TestResult():
      mTotalCount(0)
    , mSucceded(0)
    {}
    
    void PrintRes()
    {
        cout << "Total count: " << mTotalCount << " succeded: " << mSucceded << " failed: " << mTotalCount - mSucceded << endl << "----------" << endl;
    }
};

class TestCase
{
public:
    TestCase():mIsSuccess(false)
    {}
    virtual ~TestCase(){};
    virtual void Run(TestResult& outRes)
    {
        outRes.mTotalCount ++;
    };
    void PrintRes()
    {
        string Res = mIsSuccess ? " succeded" : " failed";
        cout << typeid(this).name() << Res << endl;
    };
protected:
    void SetWasSuccess(){mIsSuccess = true;}
private:
    bool mIsSuccess;
};

class TestAbstractFacories: public TestCase
{
public:
    
    TestAbstractFacories ( IAbstractFactoryUnits * factory, const std::vector<uint8_t>& list ):
    mFactory(factory)
    , mList(list)
    {}
    
    void Run(TestResult& outRes)
    {
        TestCase::Run(outRes);
        
        for ( auto id : mList )
        {
            switch (id) {
                case uint8_t(eUnits::Warrior):
                    mFactory->CreateWarrior()->Walk();
                    break;
                case uint8_t(eUnits::Archer):
                    mFactory->CreateArcher()->Shoot();
                    break;
                case uint8_t(eUnits::Horse):
                    mFactory->CreateHorse()->Ride();
                    break;
                    
                default:
                    break;
            }
        }
       
        outRes.mSucceded++;
        SetWasSuccess();
    };
    
private:
    IAbstractFactoryUnits * mFactory;
    std::vector<uint8_t>    mList;
};

class TestFib: public TestCase
{
public:
    
    TestFib ( int32_t input, int32_t resTrue ):
    mInput(input)
    , mResTrue(resTrue)
    {}
    
    void Run(TestResult& outRes)
    {
        TestCase::Run(outRes);
        int32_t Res = fibonacci(mInput);
        
        assert(Res == mResTrue);
        if ( Res == mResTrue )
        {
            outRes.mSucceded++;
            SetWasSuccess();
        }
    };
    
private:
    int32_t mInput;
    int32_t mResTrue;
};

class TestSuite
{
public:
    ~TestSuite()
    {
        for ( auto Test : mTests )
        {
            delete Test;
        }
        
        mTests.clear();
    }
    
    void AddTest(TestCase* test)
    {
        mTests.push_back(test);
    }
    
    void PrintStart()
    {
        cout << "----------" << endl << "Start testing" << endl;
    }
    
    void Run()
    {
        PrintStart();
        
        for ( auto Test : mTests )
        {
            Test->Run( mResults );
            Test->PrintRes();
        }
        
        mResults.PrintRes();
    }
    
    
    
private:
    vector<TestCase*>       mTests;
    TestResult              mResults;
};



int32_t fibonacci( int32_t number )
{
    if ( number == 1 )
    {
        return 1;
    }
    else if ( number <= 0 )
    {
        return 0;
    }
    
    return fibonacci(number-1) + fibonacci(number-2);
}

void TestFibonacci( TestSuite& suite )
{
    suite.AddTest(new TestFib(5,5));
    suite.AddTest(new TestFib(0,0));
    suite.AddTest(new TestFib(9,34));
    suite.AddTest(new TestFib(11,89));
    
    suite.Run();
}


