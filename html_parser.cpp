#include "../include/html_parser.h"
#include <gumbo.h>

std::vector<FreeAccount> HtmlParser::parseFreeAccounts(const std::string& html) {
    std::vector<FreeAccount> accounts;
    GumboOutput* output = gumbo_parse(html.c_str());
    gumbo_destroy_output(&kGumboDefaultOptions, output);
    return accounts;
}

std::vector<Review> HtmlParser::parseReviews(const std::string& html) {
    std::vector<Review> reviews;
    GumboOutput* output = gumbo_parse(html.c_str());
    gumbo_destroy_output(&kGumboDefaultOptions, output);
    return reviews;
}
