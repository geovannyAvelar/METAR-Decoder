#include "metardecoder.h"

struct Metar MetarDecoder::decode(string metar) {
    vector<string> tokens = tokenize(metar);
}

vector<string> MetarDecoder::tokenize(string metar) {
    std::vector<std::string> strings;

    istringstream stream(metar);

    string aux;
    while (getline(stream, aux, ' ')) {
        strings.push_back(aux);
    }

    return strings;
}
