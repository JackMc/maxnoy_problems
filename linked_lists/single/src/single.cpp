#include "single.hpp"

#include <stdexcept>

template <typename T>
struct node {
    node<T> *prev;
    node<T> *next;

    T &data;

    node<T>(T &x) {
        this->x = x;
    }
};


template <typename T>
singly_linked_list<T>::singly_linked_list() : l_size(0), head(0) { }

template <typename T>
singly_linked_list<T>::~singly_linked_list() {
    node<T> *current = this->head;

    while (current) {
        // Grab the next pointer so we can use it after deletion.
        node<T> *next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
node<T> *singly_linked_list<T>::find_prev(int i) {
    node<T>* current = this->head;
    int j = 0;

    while (j < i && j < this->l_size) {
        current = current->next;

        j++;
    }

    if (j == this->l_size) {
        throw std::out_of_range("Index bigger than size.");
    }
    
    return current;
}

template <typename T>
node<T> *singly_linked_list<T>::find_prev(T &x) {
    node<T>* current = this->head;

    if (!current) {
        return current;
    }

    while (current && *(current->data) != x) {
        current = current->next;
    }

    return current;
}

template <typename T>
void singly_linked_list<T>::insert(T &x, int i) {
    node<T> *prev = this->find_prev(i);
    node<T> *x_node = new node<T>(x);

    if (!prev) {
        this->head = x_node;
    }
    else {
        x_node->next = prev->next;
        prev->next = x_node;
    }

    this->l_size++;
}

template <typename T>
bool singly_linked_list<T>::delete_item(T &x) {
    node<T> *prev = this->find_prev(x);

    if (prev) {
        node<T> *x_node = prev->next;
        prev->next = x_node->next;
        delete x_node;
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
int singly_linked_list<T>::size() {
    return this->l_size;
}
