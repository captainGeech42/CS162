#ifndef ENTITY
#define ENTITY

class Entity {
protected:
    int armor, index;
    char symbol;
    Entity();

public:
    virtual ~Entity() {};

    int get_armor() const;
    void set_armor(int);
    int get_index() const;
    void set_index(int);
    char get_symbol() const;
};

#endif
