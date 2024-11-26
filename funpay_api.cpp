#include "../include/funpay_api.h"
#include <iostream>

bool FunpayAPI::login(const std::string& username, const std::string& password) {
    std::map<std::string, std::string> credentials = {
        {"username", username},
        {"password", password}
    };
    std::string response = http.post(base_url + "/login", credentials);
    return response.find("Welcome") != std::string::npos;
}

void FunpayAPI::updateAccountListing(const std::string& product_id, const std::string& new_password) {
    std::map<std::string, std::string> data = {
        {"product_id", product_id},
        {"password", new_password}
    };
    http.post(base_url + "/update_product", data);
}

void FunpayAPI::sendMessage(const std::string& user_id, const std::string& message) {
    std::map<std::string, std::string> data = {
        {"user_id", user_id},
        {"message", message}
    };
    http.post(base_url + "/send_message", data);
}

std::vector<FreeAccount> FunpayAPI::fetchFreeAccounts() {
    std::string html = http.get(base_url + "/accounts/free");
    HtmlParser parser;
    return parser.parseFreeAccounts(html);
}

std::vector<Review> FunpayAPI::fetchReviews() {
    std::string html = http.get(base_url + "/reviews");
    HtmlParser parser;
    return parser.parseReviews(html);
}
