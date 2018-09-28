#include "metardecoder.h"
#include "metar.h"
#include "stringutils.h"
#include <sstream>

struct Metar MetarDecoder::decode(string metar) {
    StringUtils * strUtils = new StringUtils();

    // Separating METAR from date in string start
    string metarString = strUtils->tokenize(metar, '-')[1];
    metarString = metarString.substr(7, metarString.size());

    /* TODO
     * For some reason i don't know yet, ICAO code is corrupted
     * after tokenize method has applied to separate METAR sections
     * by space, so i'm obtaining it using substr on original metar string
     */
    string icao = metarString.substr(0, 4);
    vector<string> tokens = strUtils->tokenize(metarString, ' ');
    tokens[0] = icao;

    return generateMetarStruct(tokens);
}

struct Metar MetarDecoder::generateMetarStruct(vector<string> tokens) {
    struct Metar metar;
    metar.icao_code = &tokens[0][0];
    metar.wind_direction = extractWindDirection(tokens[2]);
}

int MetarDecoder::extractWindDirection(string windSection) {
    string directionStr = windSection.substr(0, 3);
    int direction = stoi(directionStr, &sz);
    return direction;
}

int MetarDecoder::extractVisibility(string visibilitySection) {
    if(visibilitySection == "CAVOK") {
        return 9999;
    }



}

