//
//  TemplateMethod.h
//  Patterns1
//
//  Created by Alex Usachov on 3/9/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef TemplateMethod_h
#define TemplateMethod_h

#include <iostream>

class IProfession
{
public:
    virtual ~IProfession(){};
    void TellAboutWorkDay()
    {
        DoWhatTimeWorkDayStarts();
        DoWhatDoDoesOnWork();
        DoWhatTimeWorkDayEnds();
    }
    
    virtual void DoWhatTimeWorkDayStarts() = 0;
    virtual void DoWhatDoDoesOnWork() = 0;
    virtual void DoWhatTimeWorkDayEnds() = 0;
};

class TractorDriver : public IProfession
{
public:
    void DoWhatTimeWorkDayStarts()
    {
        std::cout << " TractorDriver starts at 5.00. " << std::endl;
    }
    
    void DoWhatDoDoesOnWork()
    {
        std::cout << " TractorDriver rides on potato field on tractor. " << std::endl;
    }
    
    void DoWhatTimeWorkDayEnds()
    {
        std::cout << " TractorDriver ends at 14.00. " << std::endl;
    }
};

class SchoolTeacher : public IProfession
{
public:
    void DoWhatTimeWorkDayStarts()
    {
        std::cout << " Teacher starts at 8.00. " << std::endl;
    }
    
    void DoWhatDoDoesOnWork()
    {
        std::cout << " Teacher teachs children at school. " << std::endl;
    }
    
    void DoWhatTimeWorkDayEnds()
    {
        std::cout << " Teacher ends at 15.00. " << std::endl;
    }
};

#endif /* TemplateMethod_h */
