#include "ui_manager.hpp"

UIManager::UIManager() {
    construct_window(this->board);
    construct_window(this->menu);

    // start curses mode
    initscr();
    refresh();

    this->init_board();
    this->init_menu();

    mvwprintw(this->board.w, 1, 1, "Board");
    mvwprintw(this->menu.w, 1, 1, "Menu");
    wrefresh(this->board.w);
    wrefresh(this->menu.w);
}

UIManager::UIManager(const UIManager& rhs) {
    this->board = rhs.board;
    this->menu = rhs.menu;
}

UIManager::~UIManager() {
    if (this->board.w != NULL) {
        wborder(this->board.w, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(this->board.w);
        delwin(this->board.w);
    }
    
    if (this->menu.w != NULL) {
	wborder(this->menu.w, ' ', ' ', ' ',' ',' ',' ',' ',' ');
        wrefresh(this->menu.w);
	delwin(this->menu.w);
    }

    // end curses mode
    endwin();
}

void UIManager::construct_window(Window w) {
    w.w = NULL;
    w.x = 0;
    w.y = 0;
    w.height = 0;
    w.width = 0;
}

void UIManager::init_board() {
    this->board.height = 5;
    this->board.width = 30;
    this->board.x = (COLS - this->board.width) / 2;
    this->board.y = (LINES - this->board.height) / 2;

    this->board.w = newwin(this->board.height, this->board.width, this->board.y, this->board.x);
    box(this->board.w, 0, 0);
    wrefresh(this->board.w);
}

void UIManager::init_menu() {
    this->menu.height = 5;
    this->menu.width = 30;
    this->menu.x = (COLS - this->menu.width) / 2;
    this->menu.y = (LINES - this->menu.height + 15) / 2;

    this->menu.w = newwin(this->menu.height, this->menu.width, this->menu.y, this->menu.x);
    box(this->menu.w, 0, 0);
    wrefresh(this->menu.w);
}
