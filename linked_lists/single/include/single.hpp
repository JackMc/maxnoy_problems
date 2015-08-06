#ifndef SINGLE_LINKED_H_
#define SINGLE_LINKED_H_

template <typename T>
struct node;

template <typename T>
class singly_linked_list {
private:    
    // Finds the node preceding a given item.
    node<T> *find_prev(T& anItem);
    // Finds the node preceeding a given index (i.e. node of list[i-1])
    node<T> *find_prev(int i);

    node<T> *head;
    int l_size;

public:
    singly_linked_list();
    ~singly_linked_list();

    // Inserts an item at a given index
    void insert(T &x, int i);
    // Adds x to the end of the list.
    void add(T &x);
    // Deletes a given item from the list.
    bool delete_item(T &x);
    // Gets the size of this linked list.
    int size();

    // Operators
    T& operator[](int i);
};

#endif // SINGLE_LINKED_H_
