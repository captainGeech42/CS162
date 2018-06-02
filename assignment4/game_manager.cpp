#include "game_manager.hpp"

GameManager::GameManager() {
    this->b.food = 50;
}

GameManager::~GameManager() {
    for (int i = 0; i < BOARD_SIZE; i++) {
	for (unsigned int j = 0; j < this->b.b[i].size(); j++) {
	    delete this->b.b[i][j];
	}
	this->b.b[i].clear();
    }
}

void GameManager::add_bee() {
    this->b.b[BOARD_SIZE - 1].push_back(new Bee);
}

void GameManager::add_ant() {
    printf("1. Harvester\t\t5. Short Thrower\n");
    printf("2. Thrower\t\t6. Wall\n");
    printf("3. Fire\t\t\t7. Ninja\n");
    printf("4. Long Thrower\t\t8. Bodyguard\n");

    Ant::Type type;
    int t;
    do {
        t = get_int("Please select the type of ant to place: ", true);
    } while ((t < 1 || t > 8) && t != -9999);
    if (t == -9999) return;
    type = static_cast<Ant::Type>(t - 1);

    int location;
    do {
        location = get_int("Please enter the square to place your ant (1-10): ") - 1;
    } while (!can_place(location, type));

    Ant *ant;
    switch (type) {
        case Ant::HARVESTER:
            ant = new Harvester;
            this->b.food -= 2;
            break;
        case Ant::THROWER:
            ant = new Thrower;
            this->b.food -= 4;
            break;
        case Ant::FIRE:
            ant = new Fire;
            this->b.food -= 4;
            break;
        case Ant::LONG_THROWER:
            ant = new LongThrower;
            this->b.food -= 3;
            break;
        case Ant::SHORT_THROWER:
            ant = new ShortThrower;
            this->b.food -= 3;
            break;
        case Ant::WALL:
            ant = new Wall;
            this->b.food -= 4;
            break;
        case Ant::NINJA:
            ant = new Ninja;
            this->b.food -= 6;
            break;
        case Ant::BODYGUARD:
            ant = new Bodyguard;
            this->b.food -= 4;
            break;
    }

    this->b.b[location].push_back(ant);
}

bool GameManager::can_place(int location, Ant::Type type) {
    if (location < 0 || location >= BOARD_SIZE) return false;

#ifdef DEBUG
    printf("made it past bound check\n");
#endif
    
    Ant* ant;
    Bodyguard* bg;
    bool can_place = true;
    for (unsigned int i = 0; i < this->b.b[location].size(); i++) {
        ant = dynamic_cast<Ant*>(this->b.b[location][i]);
        if (ant) {
            bg = dynamic_cast<Bodyguard*>(ant);
            if (!bg) {
                can_place = false;
            }
        }
    }

#ifdef DEBUG
    printf("made it past multiple ant check\n");
#endif

    switch (type) {
        case Ant::THROWER:
        case Ant::FIRE:
        case Ant::WALL:
        case Ant::BODYGUARD:
            if (this->b.food < 4) can_place = false;
            break;
        
        case Ant::LONG_THROWER:
        case Ant::SHORT_THROWER:
            if (this->b.food < 3) can_place = false;
            break;
        
        case Ant::NINJA:
            if (this->b.food < 6) can_place = false;
            break;
        
        case Ant::HARVESTER:
            if (this->b.food < 2) can_place = false;
            break;
    }

#ifdef DEBUG
    printf("made it past food check (current count: %d)\n", this->b.food);
#endif

    return can_place;
}

GameManager::State GameManager::get_state() {
    bool bees_left = false;

    Bee *b;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->b.b[i].size(); j++) {
            b = dynamic_cast<Bee*>(this->b.b[i][j]);
            if (b) {
                bees_left = true;
                break;
            }
        }
        if (bees_left) break;
    }

    if (!bees_left) return WIN;

    for (unsigned int i = 0; i < this->b.b[0].size(); i++) {
        b = dynamic_cast<Bee*>(this->b.b[0][i]);
        if (b) return LOSE;
    }

    return RUNNING;
}

void GameManager::next_turn() {
    //generate bee
    add_bee();
    
    this->ui.print(this->b);

    //add ant
    add_ant();

    //ants attack
    ant_attack();

    //bees attack
    bee_attack();
}

void GameManager::ant_attack() {
    remove_dead_ants();

    Ant *ant;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->b.b[i].size(); j++) {
            ant = dynamic_cast<Ant*>(this->b.b[i][j]);
            if (ant) ant->action(this->b);
        }
    }

    remove_dead_bees();
}

void GameManager::bee_attack() {
    remove_dead_bees();

    Ninja *n;
    Bodyguard *bg;
    Ant *a;
    Bee *b;

    for (int i = 1; i < BOARD_SIZE; i++) {
        n = NULL;
        bg = NULL;
        a = NULL;
        b = NULL;

        for (unsigned int j = 0; j < this->b.b[i].size(); j++) {
            n = n ? n : dynamic_cast<Ninja*>(this->b.b[i][j]);
            bg = bg ? bg : dynamic_cast<Bodyguard*>(this->b.b[i][j]);
            a = (a && a != bg) ? a : dynamic_cast<Ant*>(this->b.b[i][j]);
        }
        
        for (unsigned int j = 0; j < this->b.b[i].size(); j++) {
            b = dynamic_cast<Bee*>(this->b.b[i][j]);
            if (b) {
                if (n && !bg) {
                    // there is only a ninja on the square, move the bee forward
                    this->b.b[i-1].push_back(this->b.b[i][j]);
                    this->b.b[i].erase(this->b.b[i].begin() + j);
                } else if (bg) {
                    // there is a bodyguard present
                    bg->set_armor(bg->get_armor() - 1);
                    if (bg->get_armor() < 1) {
                        this->b.b[i-1].push_back(this->b.b[i][j]);
                        this->b.b[i].erase(this->b.b[i].begin() + j);
                    }
                } else if (a) {
                    // there is any other type of ant, attack normally
                    a->set_armor(a->get_armor() - 1);
                    if (a->get_armor() < 1) {
                        this->b.b[i-1].push_back(this->b.b[i][j]);
                        this->b.b[i].erase(this->b.b[i].begin() + j);
                    }
                } else {
		    // there is nothing, just move the bee
                    this->b.b[i-1].push_back(this->b.b[i][j]);
                    this->b.b[i].erase(this->b.b[i].begin() + j); 
		}
            }
        }
    }

    remove_dead_ants();
}

void GameManager::remove_dead_ants() {
    Ant *ant;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (unsigned j = 0; j < this->b.b[i].size(); j++) {
            ant = dynamic_cast<Ant*>(this->b.b[i][j]);
            if (ant) {
                if (ant->get_armor() < 1) {
                    delete ant;
                    this->b.b[i].erase(this->b.b[i].begin() + j);
                }
            }
        }
    }
}

void GameManager::remove_dead_bees() {
    Bee *bee;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (unsigned j = 0; j < this->b.b[i].size(); j++) {
            bee = dynamic_cast<Bee*>(this->b.b[i][j]);
            if (bee) {
                if (bee->get_armor() < 1) {
                    delete bee;
                    this->b.b[i].erase(this->b.b[i].begin() + j);
                }
            }
        }
    }
}
