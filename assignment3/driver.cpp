#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game_manager.hpp"

int main() {
    srand(time(NULL));

    GameManager gm;
    GameManager::State state = GameManager::kInitalize;

    while (!gm.is_game_over()) {
        switch (state) {
        case GameManager::kInitalize:
            gm.generate_properties();
            state = GameManager::kDebts;
            break;
        case GameManager::kUpdateProperties:
            gm.update_properties();
            state = GameManager::kDebts;
            break;
        case GameManager::kDebts:
            gm.print_status();
            gm.pay_debts();
            state = GameManager::kTaxes;
            break;
        case GameManager::kTaxes:
            gm.pay_taxes();
            state = GameManager::kRent;
            break;
        case GameManager::kRent:
            gm.collect_rent();
            state = GameManager::kEvent;
            break;
        case GameManager::kEvent:
            gm.event();
            state = GameManager::kPurchase;
            break;
        case GameManager::kPurchase:
            gm.buy_property();
            state = GameManager::kSell;
            break;
        case GameManager::kSell:
            gm.sell_property();
            state = GameManager::kChangeRent;
            break;
        case GameManager::kChangeRent:
            gm.update_rent();
            state = GameManager::kUpdateProperties;
            break;
        }
    }

    // game over
    if (gm.get_bank_account() < 1) {
        printf("You lose!\n");
    } else {
        printf("You win!\n");
    }

    return 0;
}