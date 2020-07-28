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
    server.setConstructorArguments(publicKey);
    server.startListening();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    securityprovider::Client client;
    QObject::connect(&client, &securityprovider::Client::gotPublicKey, startServerWithKey);
    client.open(QUrl("ws://localhost:9092"));
    client.getPublicKey();

    return a.exec();
}
