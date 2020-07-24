#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <server.h>
#include "demoserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //TODO get public key from provider
    QFileInfo publicKeyPath("../securityProvider/res/public_key.pem");

    QFile publicKeyFile(publicKeyPath.absoluteFilePath());

    bool error = false;
    if (!publicKeyFile.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Error opening publickey file: " << publicKeyPath.absoluteFilePath();
        error = true;
    }
    if(error){
        exit(1);
    }

    QString publicKey = QTextStream(&publicKeyFile).readAll();

    jsonrpc::Server<DemoServer> server(9093);
    server.setConstructorArguments(publicKey);
    server.startListening();

    return a.exec();
}
