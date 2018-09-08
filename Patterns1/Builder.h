//
//  Builder.h
//  Patterns1
//
//  Created by Alex Usachov on 3/1/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef Builder_h
#define Builder_h

#include <vector>
//---------------------------------------------
class IProduct
{
public:
    ~IProduct(){};
};
//---------------------------------------------
class IDoor
{
public:
    ~IDoor(){};
};
//---------------------------------------------
class IWindow
{
public:
    ~IWindow(){};
};
//---------------------------------------------
class Shop
{
public:
    Shop()
    {
        
    };
    
    ~Shop()
    {
        
    };
    
    void AddWindow( IWindow* window )
    {
        mWindows.push_back( window );
    }
    void AddProduct( IProduct* product )
    {
        mProducts.push_back( product );
    }
    void AddDoor( IDoor* door )
    {
        mDoors.push_back( door );
    }
    
private:
    std::vector<IProduct*>  mProducts;
    std::vector<IWindow*>  mWindows;
    std::vector<IDoor*>  mDoors;
};
//---------------------------------------------
class BigWindow: public IWindow
{
public:
    ~BigWindow(){};
};
//---------------------------------------------
class MiddleWindow: public IWindow
{
public:
    ~MiddleWindow(){};
};
//---------------------------------------------
class SmallWindow: public IWindow
{
public:
    ~SmallWindow(){};
};

//---------------------------------------------
class BigDoor : public IDoor
{
public:
    ~BigDoor(){};
};
//---------------------------------------------
class SmallDoor : public IDoor
{
public:
    ~SmallDoor(){};
};
//---------------------------------------------
class BreadProduct : public IProduct
{
public:
    ~BreadProduct(){};
};
//---------------------------------------------
class ShopBuilder
{
public:
    ~ShopBuilder()
    {
        
    }
    virtual IProduct * CreateProduct()
    {
        return new BreadProduct;
    }
    virtual IWindow * CreateWindow()
    {
        return new MiddleWindow;
    }
    virtual IDoor * CreateDoor()
    {
        return new SmallDoor;
    }
    virtual Shop * CreateShop()
    {
        return new Shop;
    }
};
//---------------------------------------------
class SmallShopBuilder : public ShopBuilder
{
public:
    virtual IWindow * CreateWindow()
    {
        return new SmallWindow;
    }
};
//---------------------------------------------
class BigShopBuilder : public ShopBuilder
{
public:
    virtual IWindow * CreateWindow()
    {
        return new BigWindow;
    }
    
    virtual IDoor * CreateDoor()
    {
        return new BigDoor;
    }
};

//---------------------------------------------
class BeverliHillsDirector
{
public:
    Shop* CreateSimpleShop( ShopBuilder* builder )
    {
        Shop* shop = builder->CreateShop();
        
        IProduct * product1 = builder->CreateProduct();
        IDoor * door1 = builder->CreateDoor();
        IWindow * window1 = builder->CreateWindow();
        
        shop->AddDoor(door1);
        shop->AddWindow(window1);
        shop->AddProduct(product1);
        
        return shop;
    }
    
    Shop* CreatePreetyShop( ShopBuilder* builder )
    {
        Shop* shop = builder->CreateShop();
        
        IProduct * product1 = builder->CreateProduct();
        IDoor * door1 = builder->CreateDoor();
        IWindow * window1 = builder->CreateWindow();
        IWindow * window2 = builder->CreateWindow();
        IWindow * window3 = builder->CreateWindow();
        IWindow * window4 = builder->CreateWindow();
        
        shop->AddDoor(door1);
        shop->AddWindow(window1);
        shop->AddWindow(window2);
        shop->AddWindow(window3);
        shop->AddWindow(window4);
        shop->AddProduct(product1);
        
        return shop;
    }
};
//---------------------------------------------
#endif /* Builder_h */
