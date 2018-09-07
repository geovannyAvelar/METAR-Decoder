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
    vector<string> tokenize(string metar);
};

#endif // METARDECODER_H
