#pragma once
#include <string>
#include <map>

class HttpClient {
private:
    std::string cookies;
public:
    HttpClient() = default;
    std::string get(const std::string& url);
    std::string post(const std::string& url, const std::map<std::string, std::string>& data);
    void setCookies(const std::string& cookie_data);
    std::string getCookies() const;
};
