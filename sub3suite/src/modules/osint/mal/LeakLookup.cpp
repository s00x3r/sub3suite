#include "LeakLookup.h"
#include "src/utils/Config.h"

#define DOMAINS 0
#define EMAIL 1
#define IP 2
#define USERNAME 3

/*
 * something is wrong!...
 */
LeakLookup::LeakLookup(ScanArgs args): AbstractOsintModule(args)
{
    manager = new s3sNetworkAccessManager(this);
    log.moduleName = "LeakLookup";

    if(args.outputRaw)
        connect(manager, &s3sNetworkAccessManager::finished, this, &LeakLookup::replyFinishedRawJson);
    ///
    /// get api key...
    ///
    
    m_key = APIKEY.value("leaklookup").toString();
    
}
LeakLookup::~LeakLookup(){
    delete manager;
}

void LeakLookup::start(){
    QNetworkRequest request;

    QUrl url;
    if(args.outputRaw){
        switch (args.rawOption) {
        case DOMAINS:
            url.setUrl("https://leak-lookup.com/api/search/?key="+m_key+"&type=domain&query="+target);
            break;
        case EMAIL:
            url.setUrl("https://leak-lookup.com/api/search/?key="+m_key+"&type=email_address&query="+target);
            break;
        case IP:
            url.setUrl("https://leak-lookup.com/api/search/?key="+m_key+"&type=ipaddress&query="+target);
            break;
        case USERNAME:
            url.setUrl("https://leak-lookup.com/api/search/?key="+m_key+"&type=username&query="+target);
            break;
        }
        request.setUrl(url);
        manager->get(request);
        activeRequests++;
    }
}
