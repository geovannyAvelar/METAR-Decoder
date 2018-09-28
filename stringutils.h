#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class StringUtils
{
public:
    vector<string> tokenize(string metar, char delimiter);
};

#endif // STRINGUTILS_H
