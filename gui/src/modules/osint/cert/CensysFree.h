#ifndef CENSYSFREE_H
#define CENSYSFREE_H

/*
 * INPUT domain:           OUTPUT: cert, subdomain
 * INPUT ip:               OUTPUT: cert, subdomain
 * INPUT cert:             OUTPUT: cert, subdomain
 */

#include "../AbstractOsintModule.h"

namespace ModuleInfo {
    struct CensysFree{
        QString name = "Censys";
        QString url = "https://censys.io/";
        QString url_apiDoc = "https://censys.io/api/v1/docs/";
        QString summary = "Censys reduces your Internet attack surface by continually discovering unknown assets and helping remediate Internet facing risks";
        QMap<QString, QStringList> flags = {};
    };
}

class CensysFree: public AbstractOsintModule{

    public:
        CensysFree(ScanArgs *args);
        ~CensysFree() override;

    public slots:
        void start() override;
        void replyFinishedSubdomain(QNetworkReply *reply) override;
        void replyFinishedSSLCert(QNetworkReply *reply) override;
};

#endif // CENSYSFREE_H
