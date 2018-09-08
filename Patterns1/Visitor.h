//
//  Visitor.h
//  Patterns1
//
//  Created by Alex Usachov on 2/28/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef Visitor_h
#define Visitor_h

class CollectionElement;

class IVisitor
{
public:
    ~IVisitor(){};
    
    virtual void VisitCollectionElement(CollectionElement& el) = 0;
};

class CollectionElement
{
public:
    CollectionElement():
    mValue(0)
    {
        
    }
    
    void Accept( IVisitor* visitor )
    {
        visitor->VisitCollectionElement(*this);
    }
    
    std::ostream& operator << (std::ostream& os)
    {
        os << this->mValue;
        return os;
    }
    
    friend std::ostream& operator<<(std::ostream& os, CollectionElement& el);
    friend std::ostream& operator<<(std::ostream& os, CollectionElement* el);
    
    int     mValue;
    
};

class TenVisitor : public IVisitor
{
public:
    ~TenVisitor(){};
    
    void VisitCollectionElement(CollectionElement& el)
    {
        el.mValue = 10;
    }
};

class FiveVisitor : public IVisitor
{
public:
    ~FiveVisitor(){};
    
    void VisitCollectionElement(CollectionElement& el)
    {
        el.mValue = 5;
    }
};

#endif /* Visitor_h */
