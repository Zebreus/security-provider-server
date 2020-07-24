#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QString>
#include <jwt-cpp/jwt.h>

class DemoServer : public QObject
{
    Q_OBJECT
    QString providerPublicKey;
public:
    explicit DemoServer(QString providerPublicKey, QObject *parent = nullptr);

signals:

public slots:
    bool login(QString jsonWebToken);
    QString getSecret();
};

#endif // SERVER_H
