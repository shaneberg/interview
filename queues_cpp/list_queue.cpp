#include <iostream>
#include "list_queue.h"

template <typename T>
ListQueue<T>::ListQueue() : _head(nullptr), _tail(nullptr), _size(0) { }

template <typename T>
ListQueue<T>::~ListQueue() {
    clear();
}

template <typename T>
bool ListQueue<T>::enqueue(const T& item) {
    Node* node = new Node(item);

    if (!node) {
        return false;
    }

    if (_tail) {
        _tail->_next = node;
    }

    _tail = node;

    if (!_head) {
        _head = node;
    }

    _size++;
    return true;
}

template <typename T>
bool ListQueue<T>::dequeue(T& item) {
    bool success = front(item);

    if (success) {
        Node* next = _head->_next;
        delete _head;
        _head = next;
        _size--;

        // If the list is now empty, ensure that the _tail is reset
        if (!_head) {
            _tail = nullptr;
        }
    }

    return success;
}

template <typename T>
bool ListQueue<T>::front(T& item) const {
    if (empty()) {
        return false;
    }

    item = _head->_data;
    return true;
}

template <typename T>
bool ListQueue<T>::empty() const {
    return !_head;
}

template <typename T>
size_t ListQueue<T>::size() const {
    return _size;
}

template <typename T>
void ListQueue<T>::clear() {
    T item;
    while(dequeue(item));
}

template <typename T>
void ListQueue<T>::print() const {
    Node* current = _head;
    while(current) {
        std::cout << "[" << current->_data << "]";
        current = current->_next;
    }
    std::cout << "[/]" << std::endl;
}

template <typename T>
ListQueue<T>::ListQueue(const ListQueue<T>& other) : _head(nullptr), _tail(nullptr), _size(0) {
    Node* current = other._head;
    while (current) {
        enqueue(current->_data);
        current = current->_next;
    }

}

template <typename T>
ListQueue<T>& ListQueue<T>::operator=(const ListQueue<T>& other) {
    if (this != &other) {
        clear();

        Node* current = other._head;
        while(current) {
            enqueue(current->_data);
            current = current->_next;
        }
    }

    return *this;
}

template <typename T>
ListQueue<T>::Node::Node(const T& data) : _data(data), _next(nullptr) { }

template class ListQueue<int>;

