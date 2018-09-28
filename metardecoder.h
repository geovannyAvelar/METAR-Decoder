#ifndef METARDECODER_H
#define METARDECODER_H

#include "metar.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class MetarDecoder {
public:
    struct Metar decode(string metar);
private:
    string::size_type sz;

    vector<string> tokenize(string metar);
    struct Metar generateMetarStruct(vector<string> tokens);
    int extractWindDirection(string windSection);
};

#endif // METARDECODER_H
