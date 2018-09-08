//
//  Iterator.h
//  Patterns1
//
//  Created by Alex Usachov on 2/28/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef Iterator_h
#define Iterator_h

#include <iostream>

class Iterator
{
public:
    Iterator( int arr[], int size ):
    mArr(arr)
    , mSize(size)
    , mCurPos(0)
    {
        
    }
    
    void First()
    {
        mCurPos = 0;
    }
    
    void Next()
    {
        if ( !IsDone() )
        {
            mCurPos++;
        }
    }
    
    int operator * ()
    {
        return mArr[mCurPos];
    }
    
    bool IsDone()
    {
        if ( mCurPos >= mSize )
        {
            return true;
        }
        
        return false;
    }
    
private:
    int*    mArr;
    int     mSize;
    int     mCurPos;
};

#endif /* Iterator_h */
