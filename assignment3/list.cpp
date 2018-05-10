#include "list.hpp"

List::List() {
    this->array = NULL;
    this->size = 0;
}

List::List(int size) {
    this->array = new ListType[size];
    this->size = size;
}

List::List(const List& copy) {
#ifdef DEBUG
    printf("[*] using List copy constructor\n");
#endif
    this->size = copy.size;
    this->array = NULL;
    if (this->size > 0) {
        this->array = new ListType[this->size];
        for (int i = 0; i < this->size; i++) {
            this->array[i] = copy.array[i];
        }
    }
}

const List& List::operator=(const List& copy) {
#ifdef DEBUG
    printf("[*] using List assignment operator overload\n");
#endif
    this->size = copy.size;
    this->array = NULL;
    if (this->size > 0) {
        this->array = new ListType[this->size];
        for (int i = 0; i < this->size; i++) {
            this->array[i] = copy.array[i];
        }
    }

    return *this;
}