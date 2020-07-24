#include "demoserver.h"


DemoServer::DemoServer(QString providerPublicKey, QObject *parent) :
    QObject(parent), providerPublicKey(providerPublicKey)
{

}

bool DemoServer::login(QString jsonWebToken)
{
    //login not implemented
    assert(false);
    return false;
}

QString DemoServer::getSecret()
{
    //getSecret not implemented
    assert(false);
    return "";
}
