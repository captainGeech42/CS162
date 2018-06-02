#include "ui_manager.hpp"

void UIManager::print(Board& board) {
#ifndef DEBUG
    system("clear");
#endif

    printf("\tCurrent Food Count: %d\n", board.food);

    unsigned int max_height = get_max_height(board);

    /*
     * +---+---+
     * | L | L |
     * +---+---+
     */

    // print top border
    printf("╭");
    for (int i = 0; i < BOARD_SIZE; i++) {
	printf("───");
	if (i != BOARD_SIZE-1) {
	    printf("┬");
	} else {
	    printf("╮");
	}
    }
    printf("\n");

    // print data
    for (unsigned int i = 0; i < max_height; i++) {
	printf("│ ");
	for (int j = 0; j < BOARD_SIZE; j++) {
	    if (i < board.b[j].size()) {
		set_color(board.b[j][i]);
		printf("%c", board.b[j][i]->get_symbol());
		reset_color();
		printf(" │");
	    } else {
		printf("  │");
	    }
	    printf(" ");
	}
	printf("\n");
    }

    // print bottom border
    printf("╰");
    for (int i = 0; i < BOARD_SIZE; i++) {
	printf("───");
	if (i != BOARD_SIZE-1) {
	    printf("┴");
	} else {
	    printf("╯");
	}
    }
    printf("\n");

    // print legend
    printf("\033[%2$d;%1$dm1 Armor\033[0m\t\t\033[%3$d;%1$dm2 Armor\033[0m\t\t\033[%4$d;%1$dm3+ Armor\033[0m\n\n", BKGD, RED, YELLOW, GREEN);
}

int UIManager::get_max_height(Board& board) {
    unsigned int max = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
	if (board.b[i].size() > max) max = board.b[i].size();
    }

    return max;
}

void UIManager::set_color(Entity *e) {
    Color c;
    switch (e->get_armor()) {
	case 1:
	    c = RED;
	    break;
	case 2:
	    c = YELLOW;
	    break;
	default:
	    c = GREEN;
	    break;
    }

    printf("\033[%d;%dm", c, BKGD);
}

void UIManager::reset_color() {
    printf("\033[0m");
}
