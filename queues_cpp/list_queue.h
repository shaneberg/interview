#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

template <typename T>
class ListQueue {

private:
    class Node {
        public:
            T _data;
            Node* _next;
            Node(const T& data);
    };

    Node* _head;
    Node* _tail;
    size_t _size;

public:
    ListQueue();
    ~ListQueue();

    bool enqueue(const T& item);
    bool dequeue(T& item);

    bool front(T& item) const;

    bool empty() const;
    size_t size() const;
    void clear();

    void print() const;

    ListQueue(const ListQueue<T>& other);
    ListQueue& operator=(const ListQueue<T>& other);
};

#endif // LIST_QUEUE_H
