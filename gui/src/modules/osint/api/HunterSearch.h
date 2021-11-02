#ifndef HUNTERSEARCH_H
#define HUNTERSEARCH_H

#include "../AbstractOsintModule.h"

/*
 * INPUT domain:            OUTPUT: email
 */

namespace ModuleInfo {
    struct HunterSearch{
        QString name = "Hunter";
        QString url = "https://hunter.io/";
        QString url_apiDoc = "https://hunter.io/api-documentation/";
        QString summary = "Hunter lets you find professional email addresses in seconds and \n"
                          "connect with the people that matter for your business.";

        QMap<QString, QStringList> flags = {{"Domain Search",
                                             {PLACEHOLDERTEXT_DOMAIN, "You give one domain name and it returns all the email addresses using this domain name found on the internet."}},
                                            {"Email Finder",
                                             {PLACEHOLDERTEXT_DOMAIN, "This API endpoint finds the most likely email address from a domain name, a first name and a last name."}},
                                            {"Author Finder",
                                             {PLACEHOLDERTEXT_URL, "It finds the author of the article, and their most likely email address on the given domain name."}},
                                            {"Email Verifier",
                                             {PLACEHOLDERTEXT_EMAIL, "This API endpoint allows you to verify the deliverability of an email address."}},
                                            {"Email Count",
                                             {PLACEHOLDERTEXT_DOMAIN, "This API endpoint allows you to know how many email addresses we have for one domain or for one company. "}},
                                            {"Account Information",
                                             {PLACEHOLDERTEXT_NONE, "This API endpoint enables you to get information regarding your Hunter account at any time"}}};
    };
}

class HunterSearch: public AbstractOsintModule{

    public:
        HunterSearch(ScanArgs *args);
        ~HunterSearch() override;
        //...
        bool verifyEmail(QString email);

    public slots:
        void start() override;
        void replyFinishedEmail(QNetworkReply *) override;

    private:
        QString m_key;
};

#endif // HUNTERSEARCH_H
