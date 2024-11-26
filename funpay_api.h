#pragma once
#include "http_client.h"
#include <string>
#include <vector>
#include "html_parser.h"

class FunpayAPI {
private:
    HttpClient http;
    std::string base_url = "https://funpay.com";
public:
    FunpayAPI() = default;
    bool login(const std::string& username, const std::string& password);
    void updateAccountListing(const std::string& product_id, const std::string& new_password);
    void sendMessage(const std::string& user_id, const std::string& message);
    std::vector<FreeAccount> fetchFreeAccounts();
    std::vector<Review> fetchReviews();
};
