#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <server.h>
#include "demoserver.h"
#include <client.h>

jsonrpc::Server<DemoServer> server(9093);
QString publicKey;

void startServerWithKey(const QString& key){
    publicKey = key;
    qDebug() << "Got Public key from securityProvider";
    qDebug() << "Starting server";
    server.setConstructorArguments(publicKey);
    server.startListening();
}

void providerError(){
    qDebug() << "Provider error";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    securityprovider::Client client;
    QObject::connect(&client, &securityprovider::Client::gotPublicKey, startServerWithKey);
    QObject::connect(&client, &securityprovider::Client::error, providerError);
    client.open(QUrl("ws://localhost:9092"));
    client.getPublicKey();

    return a.exec();
}
