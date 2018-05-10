#ifndef LIST
#define LIST

#include <assert.h>
#include <stdio.h>

#define BASE_SIZE 15

template <class T>
class List {
private:
    T* array;
    int size;
    int max_size;

    void increase_capacity() {
        this->max_size *= 2;
        T* arr = new T[this->max_size];
        for (int i = 0; i < size; i++) {
            arr[i] = this->array[i];
        }

        delete[] this->array;
        this->array = arr;
    }

public:
    /*************** constructor/destructor ********************/
    List() {
        this->size = 0;
        this->max_size = BASE_SIZE;

        this->array = new T[this->max_size];
    }

    List(const List& rhs) {
        this->size = rhs.size;
        this->max_size = rhs.max_size;
        this->array = NULL;

        if (this->size != 0) {
            this->array = new T[this->size];
            for (int i = 0; i < this->size; i++) {
                this->array[i] = rhs.array[i];
            }
        }
    }

    ~List() {
        if (this->array != NULL) delete[] this->array;
    }

    /*************** operators ******************/
    const List& operator=(const List& rhs) {
        this->size = rhs.size;
        this->max_size = rhs.max_size;
        if (this->array != NULL) delete[] this->array;
        this->array == NULL;

        if (this->size != 0) {
            this->array = new T[this->size];
            for (int i = 0; i < this->size; i++) {
                this->array[i] = rhs.array[i];
            }
        }

        return *this;
    }

    T& operator[](int index) { return this->at(index); }
    const T& operator[](int index) const { return this->at(index); }

    /************** functions *******************/
    T& at(int index) {
        assert(index >= 0 && index < this->size);

        return this->array[index];
    }
    const T& at(int index) const {
        assert(index >= 0 && index < this->size);

        return this->array[index];
    }

    void push_back(const T& item) {
        if (this->size == this->max_size) {
            increase_capacity();
        }

        this->array[size++] = item;
    }
};

#endif