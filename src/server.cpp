#include "server.h"

Server::Server(QString providerPublicKey, QObject *parent) :
    QObject(parent), providerPublicKey(providerPublicKey)
{

}

bool Server::login(QString jsonWebToken)
{
    //login not implemented
    assert(false);
    return false;
}

QString Server::getSecret()
{
    //getSecret not implemented
    assert(false);
    return "";
}
