#include "httphandler.h"

std::string HttpHandler::get(std::string url) {
    HttpHandler::curl = curl_easy_init();
    std::string response_string;
    CURLcode res;

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            return "";
        }

        curl_easy_cleanup(curl);
    }

    return response_string;
}

size_t HttpHandler::writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    ((std::string*) data)->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

