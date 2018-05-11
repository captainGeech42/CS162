#include "game_manager.hpp"

GameManager::GameManager() {
    this->bank_account = 500000;
}

GameManager::GameManager(const GameManager& rhs) {
    this->available_properties = rhs.available_properties;
    this->owned_properties = rhs.owned_properties;
    this->bank_account = rhs.bank_account;
}

const GameManager& GameManager::operator=(const GameManager& rhs) {
    this->available_properties = rhs.available_properties;
    this->owned_properties = rhs.owned_properties;
    this->bank_account = rhs.bank_account;

    return *this;
}

int GameManager::get_bank_account() const { return this->bank_account; }

bool GameManager::is_game_over() {
    return this->bank_account <= 0 || this->bank_account >= 100000;
}

