//update scanner and applier (and tf2 update checker)

#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include <stdio.h>
#include <SDL2/SDL_messagebox.h>
#include <algorithm>

using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

auto version_checker(string ver, string haxbox_uri){
    string readbuff;
    auto curver = ver.c_str();
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, haxbox_uri.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readbuff);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() faled %s\n", curl_easy_strerror(res));
        }
    curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    if(readbuff != curver){
        //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Haxbox Warning | Invalid Version", "Your Haxbox version is out of date\nplease update as soon as possible", NULL);
        return false;
    }
    else{
        return true;
    }
}

auto tf2_updated_checker(string update_uri, string confirmed, string no){
        string readbuff;
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, update_uri.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readbuff);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() faled %s\n", curl_easy_strerror(res));
        }
    curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    if(readbuff == confirmed){
        //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Haxbox Warning | tf2 updated", "Haxbox has detected that tf2 has been updated\nthis may cause your current version of Haxbox to be detected\nplease stand by as we shuffle around some code and change the Shasum\n", NULL);
        return false;
    }
    else{
        return true;
    }
}
