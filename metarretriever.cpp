#include "metarretriever.h"
#include "httphandler.h"
#include <string>
#include <QString>

std::string MetarRetriever::get_metar(std::string icao) {
    HttpHandler * httpHandler = new HttpHandler();
    std::string url = base_url.append(icao);

    return httpHandler->get(url);
}
