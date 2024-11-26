#include <iostream>
#include "../include/funpay_api.h"

int main() {
    FunpayAPI funpay;

    if (funpay.login("username", "password")) {
        std::cout << "Login successful.\n";

        auto freeAccounts = funpay.fetchFreeAccounts();
        for (const auto& acc : freeAccounts) {
            std::cout << "Game: " << acc.game_name
                << ", Available: " << acc.available_count
                << ", Next Free: " << acc.next_free_time << "\n";
        }

        auto reviews = funpay.fetchReviews();
        for (const auto& rev : reviews) {
            std::cout << "User: " << rev.user_name
                << ", Rating: " << rev.rating
                << ", Comment: " << rev.comment << "\n";
        }
    }
    else {
        std::cout << "Login failed.\n";
    }

    return 0;
}
