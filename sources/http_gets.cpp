#include <curl/curl.h>
#include "http_gets.h"
#include <iostream>

http_gets::http_gets()
{
}

http_gets::~http_gets()
{

}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int http_gets::get_website(std::string hostname, std::string & result)
{
    CURL *curl;

    result = "";
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL,           hostname.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA,     &result);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return EXIT_SUCCESS;
}
