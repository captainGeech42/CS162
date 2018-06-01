#include "ui_manager.hpp"

UIManager::UIManager(Board& b) {
    this->b = b;
}

void UIManager::print() {
    system("clear");
    printf("wassup\n");
}

int UIManager::get_max_height() {
    return 0;
}