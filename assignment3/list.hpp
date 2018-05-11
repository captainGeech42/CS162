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

    List(int base_size) {
        this->size = 0;
        this->max_size = base_size;

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

    /************** getter/setter ******************/
    int get_size() const { return this->size; }
    int get_max_size() const { return this->max_size; }

    /************** functions *******************/
    T& at(int index) {
        assert(index >= 0 && index < this->size);

        return this->array[index];
    }
    const T& at(int index) const {
        assert(index >= 0 && index < this->size);

        return this->array[index];
    }

    T& front() { return this->array[0]; }
    const T& front() const { return this->array[0]; }

    T& back() { return this->array[this->size-1]; }
    const T& back() const { return this->array[this->size-1]; }

    void push_back(const T& item) {
        if (this->size == this->max_size) {
            increase_capacity();
        }

        this->array[size++] = item;
    }

    void pop_back() {
        delete this->array[this->size--];
    }

    void insert(const T& item, int index) {
        assert(index >= 0 && index < this->size);

        if (this->size == this->max_size) {
            increase_capacity();
        }

        for (int i = size; i >= index; i--) {
            this->array[i+1] = this->array[i];
        }
        this->array[index] = item;
    }

    void clear() {
        delete[] this->array;

        this->size = 0;
        this->max_size = BASE_SIZE;
        this->array = new T[this->max_size];
    }
};

#endif