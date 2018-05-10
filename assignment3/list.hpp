#ifndef LIST
#define LIST

#include <cstddef>
#include <stdio.h>

class ListType {
// intentionally empty
};

class List {
private:
    ListType* array;
    int size;
public:
    List();
    List(int);
    List(const List&);
    ~List();

    const List& operator=(const List&);

    void add(const ListType*);
};

#endif