#ifndef METARRETRIEVER_H
#define METARRETRIEVER_H

#include <string>

class MetarRetriever {
    public:
        std::string get_metar(std::string icao);

    private:
        std::string base_url = "http://www.redemet.aer.mil.br/api/consulta_automatica/index.php?msg=metar&local=";
};

#endif // METARRETRIEVER_H
