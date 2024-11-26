#pragma once
#include <string>
#include <vector>

struct FreeAccount {
    std::string game_name;
    int available_count;
    std::string next_free_time;
};

struct Review {
    std::string user_name;
    int rating;
    std::string comment;
};

class HtmlParser {
public:
    std::vector<FreeAccount> parseFreeAccounts(const std::string& html);
    std::vector<Review> parseReviews(const std::string& html);
};
