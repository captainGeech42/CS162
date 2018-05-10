#ifndef LIST
#define LIST

#include <stdio.h>

template <class T>
class List {
private:
    T* array;
    int size;
public:
    List();
    List(int);
    List(const List&);
    ~List();

    const List& operator=(const List&);

    void add(const T*);
};

#endif