#include "demoserver.h"


DemoServer::DemoServer(QString providerPublicKey, QObject *parent) :
    QObject(parent), providerPublicKey(providerPublicKey)
{
    qDebug() << "Connected";
}

DemoServer::~DemoServer()
{
    qDebug() << "Disconnected";
}

bool DemoServer::login(QString jsonWebToken)
{
    try{
        auto verifier = jwt::verifier<jwt::default_clock,QtJsonTraits>(jwt::default_clock{})
            .with_claim("testClaim",jwt::basic_claim<QtJsonTraits>(QString("true")))
            .allow_algorithm(jwt::algorithm::rs256(providerPublicKey.toUtf8().constData(),"","",""))
            .with_issuer("securityprovider");

        auto decodedToken = jwt::decode<QtJsonTraits>(jsonWebToken);

        verifier.verify(decodedToken);

        authorized = true;
        qDebug() << "User " << decodedToken.get_subject() << " logged in with valid token";
        return true;
    }catch(std::runtime_error& e){
        authorized = false;
        qDebug() << "Invalid token";
        return false;
    }
}

QString DemoServer::getSecret()
{
    if(authorized){
        return "secret";
    }else{
        return "not authorized";
    }
}
