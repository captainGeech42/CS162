#include "ui_manager.hpp"

UIManager::UIManager() {
    this->curses_mode = false;
}

UIManager::UIManager(Board& board) {
    this->board = board;
    
    construct_window(this->wboard);
    construct_window(this->wmenu);

    // start curses mode
    initscr();
    refresh();
    this->curses_mode = true;

    this->init_board();
    this->init_menu();

    mvwprintw(this->wboard.w, 1, 1, "Board");
    mvwprintw(this->wmenu.w, 1, 1, "Menu");
    wrefresh(this->wboard.w);
    wrefresh(this->wmenu.w);
}

UIManager::UIManager(const UIManager& rhs) {
    this->board = rhs.board;
    this->wboard = rhs.wboard;
    this->wmenu = rhs.wmenu;
}

UIManager::~UIManager() {
    if (this->wboard.w != NULL) {
        wborder(this->wboard.w, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	    wrefresh(this->wboard.w);
        delwin(this->wboard.w);
    }
    
    if (this->wmenu.w != NULL) {
    	wborder(this->wmenu.w, ' ', ' ', ' ',' ',' ',' ',' ',' ');
        wrefresh(this->wmenu.w);
	    delwin(this->wmenu.w);
    }

    // end curses mode
    if (this->curses_mode) endwin();
}

const UIManager& UIManager::operator=(const UIManager& rhs) {
    this->board = rhs.board;
    this->wboard = rhs.wboard;
    this->wmenu = rhs.wmenu;

    return *this;
}

void UIManager::construct_window(Window w) {
    w.w = NULL;
    w.x = 0;
    w.y = 0;
    w.height = 0;
    w.width = 0;
}

void UIManager::init_board() {
    this->wboard.height = 10;
    this->wboard.width = 80;
    this->wboard.x = (COLS - this->wboard.width) / 2;
    this->wboard.y = (LINES - this->wboard.height) / 2;

    this->wboard.w = newwin(this->wboard.height, this->wboard.width, this->wboard.y, this->wboard.x);
    box(this->wboard.w, 0, 0);
    wrefresh(this->wboard.w);
}

void UIManager::init_menu() {
    this->wmenu.height = 10;
    this->wmenu.width = 80;
    this->wmenu.x = (COLS - this->wmenu.width) / 2;
    this->wmenu.y = (LINES - this->wmenu.height + this->wboard.height + 10) / 2;

    this->wmenu.w = newwin(this->wmenu.height, this->wmenu.width, this->wmenu.y, this->wmenu.x);
    box(this->wmenu.w, 0, 0);
    wrefresh(this->wmenu.w);
}

void UIManager::redraw_menu() {
    mvwprintw(this->wmenu.w, 1, 1, "Food Count: %d", this->board.food);
}