#ifndef UI_MANAGER
#define UI_MANAGER

#include <ncurses.h>

#include "board.hpp"

class UIManager {
private:
    struct Window {
	    WINDOW* w;
	    int x;
	    int y;
	    int width;
	    int height;
    };

    bool curses_mode;

    Window wboard;
    Window wmenu; //this may change, need to read Menu ncurses documentation
  
    Board board;

    void construct_window(Window);

    void init_board();
    void init_menu();

public:
    UIManager();
    UIManager(Board&);
    UIManager(const UIManager&);
    ~UIManager();

    const UIManager& operator=(const UIManager&);

    void redraw_menu();
};

#endif
