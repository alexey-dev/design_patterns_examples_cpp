//
//  Composite.h
//  Patterns1
//
//  Created by Alex Usachov on 2/26/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef Composite_h
#define Composite_h

#include <iostream>
#include <vector>

class IJsonElement
{
public:
    IJsonElement( IJsonElement*parent ):
     mParent(parent)
    {
        
    }
    
    virtual ~IJsonElement()
    {
        for ( auto el : mChildren )
        {
            delete el;
        }
        
        mChildren.clear();
        
        std::cout << "~IJsonElement" << std::endl;
    }
    virtual void Add(IJsonElement* el)
    {
        mChildren.push_back(el);
    }
    
    virtual int32_t GetCountChildren()
    {
        int32_t Temp = mChildren.size();
        for ( auto el : mChildren )
        {
            Temp += el->GetCountChildren();
        }
        
        return Temp;
    }
protected:
    IJsonElement*                mParent;
    std::vector<IJsonElement*>   mChildren;
};

class JsonArray : public IJsonElement
{
public:
    JsonArray( IJsonElement*parent ):
    IJsonElement(parent)
    {
        
    }
    
    ~JsonArray()
    {
    }
};
class JsonObj : public IJsonElement
{
public:
    JsonObj( IJsonElement*parent ):
    IJsonElement(parent)
    {
        
    }
    
    ~JsonObj()
    {
    }
};
class JsonVar : public IJsonElement
{
public:
    JsonVar( IJsonElement*parent ):
    IJsonElement(parent)
    {
        
    }
    
    ~JsonVar()
    {
    }
    
    virtual void Add(IJsonElement* el)
    {
    }
    
    virtual int32_t GetCountChildren()
    {
        return 0;
    }
};

#endif /* Composite_h */
