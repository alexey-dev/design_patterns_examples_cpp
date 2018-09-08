//
//  main.cpp
//  Patterns1
//
//  Created by Alex Usachov on 2/26/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#include <iostream>
#include <memory>
#include <array>
#include <initializer_list>
#include <vector>
#include "AbstractFactories.h"
#include "Composite.h"
#include "Strategy.h"
#include "Decorator.h"
#include "Bridge.h"
#include "Visitor.h"
#include "Command.h"
#include "Iterator.h"
#include "Builder.h"
#include "Adapter.h"
#include "Facade.h"
#include "Flyweight.h"
#include "Prototype.h"
#include "Mediator.h"
#include "Memento.h"
#include "Proxy.h"
#include "Observer.h"
#include "State.h"
#include "TemplateMethod.h"
#include "ChainOfResponsibility.h"
#include "UnitTests/UnitTests.h"

void TestFactories()
{
    std::initializer_list<uint8_t> lst1 {0,1,2,0,1,1,2,1};
    TestAbstractFacories*test1 = new TestAbstractFacories( new GreenFactory(), std::vector<uint8_t>(lst1));
    TestAbstractFacories*test2 = new TestAbstractFacories( new RedFactory(), std::vector<uint8_t>(lst1));
    
    TestSuite suite1;
    suite1.AddTest(test1);
    suite1.AddTest(test2);
    suite1.Run();
}

void TestComposite()
{
    
    IJsonElement * root;
    root = new IJsonElement(NULL);
    
    std::unique_ptr<IJsonElement> UnPtr(root);
    
    JsonArray*arr = new JsonArray(root);
    JsonVar*var1 = new JsonVar(root);
    
    JsonObj* obj1 = new JsonObj(arr);
    JsonVar*var2 = new JsonVar(arr);
    JsonVar*var3 = new JsonVar(obj1);
    
    obj1->Add( var3 );
    arr->Add( obj1 );
    arr->Add( var2 );
    root->Add(var1);
    root->Add(arr);
    
    std::cout << root->GetCountChildren() << std::endl;
}

void TestStrategy()
{
    std::initializer_list<int8_t> lst1 {1,2,3,4,5};
    ContentVector v1( new MulStrategy(), std::vector<int8_t>(lst1) );
    ContentVector v2( new SumStrategy(), std::vector<int8_t>(lst1) );
    std::cout << v1.Calc() << std::endl;
    std::cout << v2.Calc() << std::endl;
}

void TestDecorator()
{
    std::vector<ITransport*> cars;
    cars.push_back( new CarWithDisel( new CleanCar() ) );
    cars.push_back( new CarWithDisel( new WashCar() ) );
    cars.push_back( new CarWithBigMirror( new CarWithDisel( new CleanCar() ) ) );
    cars.push_back( new CarWithDisel( new CarWithBigMirror( new CleanCar() ) ) );
    
    for ( auto car : cars )
    {
        car->Ride();
        delete car;
    }
}

void TestBridge()
{
    std::vector<IRaceVehicle*> cars;
    
    RaceCar * car1 = new RaceCar ( new ImplementationRainyRace() );
    RaceCar * car2 = new RaceCar ( new ImplementationSnowyRace() );
    
    JeepCar * car3 = new JeepCar ( new ImplementationRainyRace() );
    JeepCar * car4 = new JeepCar ( new ImplementationSnowyRace() );
    cars.push_back(car1);
    cars.push_back(car2);
    cars.push_back(car3);
    cars.push_back(car4);
    
    for ( auto c : cars )
    {
        c->Drive();
        c->Stop();
        
        delete c;
    }
    
    cars.clear();
}

void TestCommand()
{
    std::vector<ICommand*> cmds;
    
    
    cmds.push_back(new StartCommand);
    cmds.push_back(new StopCommand);
    cmds.push_back(new PlayCommand);
    cmds.push_back(new StartCommand);
    cmds.push_back(new StartCommand);
    
    
    for ( auto c : cmds )
    {
        c->Exec();

        delete c;
    }
    
    cmds.clear();
}

void TestIterator()
{
    int arr[] = {1,2,3,4,5};
    Iterator It(arr,5);
    
    for ( It.First(); !It.IsDone(); It.Next() )
    {
        cout << *It << endl;
    }
    
    for ( It.First(); !It.IsDone(); It.Next() )
    {
        cout << *It << endl;
    }
    
}

std::ostream& operator<<(std::ostream& os, CollectionElement& el)
{
    os << el.mValue;
    return os;
}

std::ostream& operator<<(std::ostream& os, CollectionElement* el)
{
    os << el->mValue;
    return os;
}


template <typename TN>
void PrintVector(const std::vector<TN>& vec)
{
    for ( TN el : vec )
    {
        cout << el << endl;
    }
}

void TestVisitor()
{
    std::vector<CollectionElement*> els;
    constexpr int8_t COUNT_ELS = 10;
    for ( int8_t i = 0; i < COUNT_ELS; i++ )
    {
        els.push_back(new CollectionElement);
    }
    
    unique_ptr<IVisitor> vistitor1( new TenVisitor );
    unique_ptr<IVisitor> vistitor2( new FiveVisitor );
    
    for ( int8_t i = 0; i < COUNT_ELS; i++ )
    {
        els[i]->Accept(&*vistitor1);
    }
    
    PrintVector(els);
    
    for ( int8_t i = 0; i < COUNT_ELS; i++ )
    {
        els[i]->Accept(&*vistitor2);
    }
    
    PrintVector(els);
}

void TestBuilder()
{
    BeverliHillsDirector Director;
    SmallShopBuilder  SmallBuilder;
    BigShopBuilder  BigBuilder;
    Shop * SimpleShop = Director.CreateSimpleShop(&SmallBuilder);
    Shop * PreetyShop = Director.CreatePreetyShop(&BigBuilder);
    Shop * MediumPreetyShop = Director.CreatePreetyShop(&SmallBuilder);
    
    delete SimpleShop;
    delete PreetyShop;
    delete MediumPreetyShop;
}

void TestAdapterMethod1( ITarget* adapter )
{
    adapter->BuildHouse();
}

void TestAdapterMethod2( AdapterObject* adapter )
{
    adapter->BuildHouse();
}

void TestAdapter()
{
    unique_ptr<AdapterClass> UPtrAdapterClass( new AdapterClass );
    TestAdapterMethod1(UPtrAdapterClass.get());
    
    unique_ptr<AdapterObject> UPtrAdapterObject( new AdapterObject( new IAdaptee ) );
    TestAdapterMethod2(UPtrAdapterObject.get());
}

void TestFacade()
{
    unique_ptr<FootballGame> UPFootball( new FootballGame() );
    UPFootball.get()->Start();
    UPFootball.get()->Play();
    UPFootball.get()->Finish();
}

void TestPrototype()
{
    constexpr int8_t MAX_FOOD_COUNT = 100;
    PrototypeFoodFactory Factory(new Tomato, new Bread);
    std::vector<IFoodClonable*> Vec;
    
    for ( int8_t i = 0; i < MAX_FOOD_COUNT; i++ )
    {
        if ( i%2 == 1 )
        {
            Vec.push_back( Factory.GetTomato() );
        }
        else
        {
            Vec.push_back( Factory.GetBread() );
        }
    }
    
    for( IFoodClonable* food : Vec )
    {
        delete food;
    }    
}

void TestFlyweight()
{
    constexpr int8_t MAX_TREES = 100;
    FruitFactory FactoryFruit;
    vector<FruitTree> Trees;
    
    for ( int8_t i = 0; i < MAX_TREES; i++ )
    {
        if ( i%2 == 1 )
        {
            Trees.push_back( FruitTree(i, FactoryFruit.GetFruit(FRUIT_TYPES::APPLE)) );
        }
        else
        {
            Trees.push_back( FruitTree(i, FactoryFruit.GetFruit(FRUIT_TYPES::PEACH)) );
        }
    }
    
    std::cout << "Finish flyweight" << endl;
    
}

void TestProxy()
{
    DBProxy DB("user","password",3306);
    DB.Connect();
    DB.Connect();
    if ( DB.IsConnected() )
    {
        DB.TestRequest();
    }
    if ( DB.IsConnected() )
    {
        DB.TestRequest();
    }
    DB.TestRequest();
    DB.TestRequest();
}

void TestChainOfResponsibility()
{
    Base * root = new Base;
    root->Add(new PlayEl);
    root->Add(new PlayEl);
    root->Add(new FinishEl);
    root->Add(new FinishEl);
    
    unique_ptr<PlayCmd> PtrPlay(new PlayCmd);
    unique_ptr<FinishCmd> PtrFinish(new FinishCmd);
    
    root->Handle(PtrPlay.get());
    root->Handle(PtrFinish.get());
    
    delete root;
}

void TestMediator()
{
    FootballMediator fotball;
    fotball.GenerateGoal();
    fotball.GenerateCrowdRun();
    fotball.GenerateGoal();
}

void TestMemento()
{
    UnitOriginator unit;
    unit.TakeDamage(5);
    unique_ptr<MementoUnit> PtrMemento( unit.CreateMemento() );
    unit.TakeDamage(100);
    unit.TakeDamage(75);
    unit.SetMemento(PtrMemento.get());
    unit.TakeDamage(100);
    unit.TakeDamage(100);
    unit.SetMemento(PtrMemento.get());
    unit.TakeDamage(100);
}

void TestObserver()
{
    GateSubject Gate;
    Gate.AddObserver( new GateKey );
    Gate.AddObserver( new CarInYard );
    Gate.Open();
    Gate.Close();
    Gate.Close();
    
}

void TestStatePattern()
{
    Programmer ProgrammerMan;
    ProgrammerMan.CamoToWork();
    ProgrammerMan.DrinkCoffe();
    ProgrammerMan.WorkAnHour();
    ProgrammerMan.WorkAnHour();
    ProgrammerMan.WorkAnHour();
    ProgrammerMan.DrinkCoffe();
    ProgrammerMan.WorkAnHour();
    ProgrammerMan.WorkAnHour();
    ProgrammerMan.DrinkCoffe();
    ProgrammerMan.WorkAnHour();
    ProgrammerMan.WorkAnHour();
    ProgrammerMan.WorkAnHour();
    ProgrammerMan.WorkAnHour();
}

void TestTemplateMethod()
{
    TractorDriver Tractor;
    Tractor.TellAboutWorkDay();
    SchoolTeacher Teacher;
    Teacher.TellAboutWorkDay();
}

int main(int argc, const char * argv[])
{
//    TestFactories();
//    TestComposite();
//    TestStrategy();
//    TestDecorator();
//    TestBridge();
//    TestCommand();
//    TestIterator();
//    TestVisitor();
//    TestBuilder();
//    TestAdapter();
//    TestFacade();
//    TestPrototype();
//    TestFlyweight();
//    TestProxy();
//    TestChainOfResponsibility();
//    TestMediator();
//    TestMemento();
//    TestObserver();
//    TestStatePattern();
    TestTemplateMethod();

    return 0;
}
