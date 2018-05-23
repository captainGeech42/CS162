#ifndef UI_MANAGER
#define UI_MANAGER

#include <ncurses.h>

class UIManager {
private:
    struct Window {
	WINDOW* w;
	int x;
	int y;
	int width;
	int height;
    };

    Window board;
    Window menu; //this may change, need to read Menu ncurses documentation
   
    void construct_window(Window);

    void init_board();
    void init_menu();

public:
    UIManager();
    UIManager(const UIManager&);
    ~UIManager();

    
};

#endif
