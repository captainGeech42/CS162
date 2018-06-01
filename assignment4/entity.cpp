#include "entity.hpp"

Entity::Entity() {
    this->armor = 0;
}

int Entity::get_armor() const { return this->armor; }
void Entity::set_armor(int armor) { this->armor = armor; }

int Entity::get_index() const { return this->index; }
void Entity::set_index(int index) { this->index = index; }

char Entity::get_symbol() const { return this->symbol; }