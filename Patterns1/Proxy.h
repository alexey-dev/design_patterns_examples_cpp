//
//  Proxy.h
//  Patterns1
//
//  Created by Alex Usachov on 3/7/18.
//  Copyright © 2018 Alex Usachov. All rights reserved.
//

#ifndef Proxy_h
#define Proxy_h

#include <iostream>
#include <string>

class IDB
{
public:
    virtual ~IDB(){};
    virtual void Connect() = 0;
    virtual bool IsConnected() = 0;
    virtual void TestRequest() = 0;
};

class MysqlDB : public IDB
{
public:
    MysqlDB( const std::string& user, const std::string& passw, int32_t port ):
    mUser(user)
    , mPassword(passw)
    , mPort(port)
    , mIsConnected(false)
    {
        
    }
    void Connect()
    {
        std::cout << "Simulate connection " << std::endl;
        mIsConnected = true;
    }
    bool IsConnected()
    {
        return mIsConnected;
    }
    void TestRequest()
    {
        std::cout << "test request " << std::endl;
    }
private:
    std::string mUser;
    std::string mPassword;
    int32_t     mPort;
    bool        mIsConnected;
};

class DBProxy : public IDB
{
public:
    DBProxy( const std::string& user, const std::string& passw, int32_t port)
    {
        mRealDB = new MysqlDB(user, passw, port);
    }
    
    ~DBProxy()
    {
        delete mRealDB;
        mRealDB = nullptr;
    }
    
    void Connect()
    {
        std::cout << "Block connection from proxy " << std::endl;
    }
    bool IsConnected()
    {
        return GetRealDB()->IsConnected();
    }
    void TestRequest()
    {
        if ( !GetRealDB()->IsConnected() )
        {
            GetRealDB()->Connect();
        }
        GetRealDB()->TestRequest();
    }
    
    IDB*    GetRealDB()
    {
        return mRealDB;
    }
    
private:
    
    MysqlDB*    mRealDB;
};

#endif /* Proxy_h */
