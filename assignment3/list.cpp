#include "list.hpp"

template <class T>
List<T>::List() {
    this->array = NULL;
    this->size = 0;
}

template <class T>
List<T>::List(int size) {
    this->array = new T[size];
    this->size = size;
}

template <class T>
List<T>::List(const List& copy) {
#ifdef DEBUG
    printf("[*] using List copy constructor\n");
#endif
    this->size = copy.size;
    this->array = NULL;
    if (this->size > 0) {
        this->array = new T[this->size];
        for (int i = 0; i < this->size; i++) {
            this->array[i] = copy.array[i];
        }
    }
}

template <class T>
const List<T>& List<T>::operator=(const List& copy) {
#ifdef DEBUG
    printf("[*] using List assignment operator overload\n");
#endif
    this->size = copy.size;
    this->array = NULL;
    if (this->size > 0) {
        this->array = new T[this->size];
        for (int i = 0; i < this->size; i++) {
            this->array[i] = copy.array[i];
        }
    }

    return *this;
}