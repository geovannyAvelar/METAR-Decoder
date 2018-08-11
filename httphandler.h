#ifndef HTTPHANDLER_H
#define HTTPHANDLER_H

#include <curl/curl.h>
#include <string>

class HttpHandler {
    public:
        std::string get(std::string url);
    private:
        CURL *curl;
        CURLcode res;

        static size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data);
};

#endif // HTTPHANDLER_H
