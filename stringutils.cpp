#include "stringutils.h"

vector<string> StringUtils::tokenize(string metar, char delimiter) {
    std::vector<std::string> strings;

    istringstream stream(metar);

    string aux;
    while (getline(stream, aux, delimiter)) {
        strings.push_back(aux);
    }

    return strings;
}
