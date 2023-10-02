#include <iostream>
#include "list_queue.h"

void runListQueueTests() {
    ListQueue<int> q;

    // Test 1: Check if the queue starts empty
    if (q.empty()) {
        std::cout << "Test 1 passed: ListQueue starts empty." << std::endl;
    } else {
        std::cout << "Test 1 failed: ListQueue should start empty." << std::endl;
    }

    q.print();

    // Test 2: Enqueue items and verify the size
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    if (q.size() == 3) {
        std::cout << "Test 2 passed: Enqueue works." << std::endl;
    } else {
        std::cout << "Test 2 failed: Enqueue doesn't work." << std::endl;
    }

    q.print();

    // Test 3: Check front item without dequeue
    int frontItem;
    bool frontResult = q.front(frontItem);
    if (frontResult && frontItem == 5) {
        std::cout << "Test 3 passed: Front item check." << std::endl;
    } else {
        std::cout << "Test 3 failed: Front item mismatch." << std::endl;
    }

    q.print();

    // Test 4: Dequeue items and verify order and size
    int item1;
    int item2;
    bool result1 = q.dequeue(item1);
    bool result2 = q.dequeue(item2);
    if (result1 && result2 && item1 == 5 && item2 == 10 && q.size() == 1) {
        std::cout << "Test 4 passed: Dequeue and order check." << std::endl;
    } else {
        std::cout << "Test 4 failed: Dequeue or order is incorrect." << std::endl;
    }

    q.print();

    // Test 5: Clear the queue
    q.clear();
    if (q.empty() && q.size() == 0) {
        std::cout << "Test 5 passed: Clear works." << std::endl;
    } else {
        std::cout << "Test 5 failed: Clear doesn't work." << std::endl;
    }
    q.print();

    // Test 6: Test the copy constructor
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(16);
    ListQueue<int> qCopy = q; // Create a copy of the original queue
    if (qCopy.size() == q.size()) {
        std::cout << "Test 6 passed: Copy constructor size matches." << std::endl;
    } else {
        std::cout << "Test 6 failed: Copy constructor size mismatch." << std::endl;
    }

    q.print();
    qCopy.print();

    // Test 7: Modify the original queue and ensure the copy remains unchanged
    q.enqueue(20);
    if (qCopy.size() == q.size() - 1) {
        std::cout << "Test 7 passed: Copy remains unchanged after modifying original." << std::endl;
    } else {
        std::cout << "Test 7 failed: Copy changed after modifying original." << std::endl;
    }

    q.print();
    qCopy.print();

    // Test 8: Dequeue from the copy and ensure the original remains unchanged
    int copyItem;
    size_t expected = q.size();
    bool copyResult = qCopy.dequeue(copyItem);
    if (copyResult && copyItem == 10 && q.size() == expected) {
        std::cout << "Test 8 passed: Original remains unchanged after modifying copy." << std::endl;
    } else {
        std::cout << "Test 8 failed: Original changed after modifying copy." << std::endl;
    }

    qCopy.print();
    q.print();

    // Test 9: Clear and then add 1.
    q.clear();
    q.enqueue(7);
    if (q.size() == 1) {
        std::cout << "Test 9 passed: Clearing and then adding 1 worked." << std::endl;
    } else {
        std::cout << "Test 9 failed: Clearing and adding 1 didn't work." << std::endl;
    }

    q.print();
}

void runCopyAssignmentTests() {
    // Test 1: Basic assignment check
    ListQueue<int> original;
    original.enqueue(5);
    original.enqueue(10);
    original.enqueue(15);

    ListQueue<int> assignedQueue;
    assignedQueue = original;

    if (assignedQueue.size() == 3 && !assignedQueue.empty()) {
        std::cout << "Test 1 passed: Basic assignment works." << std::endl;
    } else {
        std::cout << "Test 1 failed: Basic assignment doesn't work." << std::endl;
    }

    original.print();
    assignedQueue.print();

    // Test 2: Ensure deep copy was made (i.e., modifying the original doesn't affect the copy)
    int originalItem;
    original.dequeue(originalItem);

    int assignedItem;
    assignedQueue.front(assignedItem);
    if (assignedItem == 5) {
        std::cout << "Test 2 passed: Deep copy is ensured." << std::endl;
    } else {
        std::cout << "Test 2 failed: Deep copy not made." << std::endl;
    }

    original.print();
    assignedQueue.print();

    // Test 3: Self-assignment
    assignedQueue = assignedQueue;
    if (assignedQueue.size() == 3) { // Size should remain unchanged after self-assignment
        std::cout << "Test 3 passed: Self-assignment check." << std::endl;
    } else {
        std::cout << "Test 3 failed: Self-assignment is problematic." << std::endl;
    }

    original.print();
    assignedQueue.print();

    // Test 4: Overwriting with a different queue
    ListQueue<int> newQueue;
    newQueue.enqueue(100);
    assignedQueue = newQueue;

    if (assignedQueue.size() == 1) {
        assignedQueue.front(assignedItem);
        if (assignedItem == 100) {
            std::cout << "Test 4 passed: Overwriting old queue with a new one works." << std::endl;
        } else {
            std::cout << "Test 4 failed: Overwriting doesn't work correctly." << std::endl;
        }
    } else {
        std::cout << "Test 4 failed: Overwriting doesn't work correctly." << std::endl;
    }

    newQueue.print();
    assignedQueue.print();

    // Test 5: Assigning an empty queue
    ListQueue<int> emptyQueue;
    assignedQueue = emptyQueue;
    if (assignedQueue.empty() && assignedQueue.size() == 0) {
        std::cout << "Test 5 passed: Assigning an empty queue works." << std::endl;
    } else {
        std::cout << "Test 5 failed: Problem assigning an empty queue." << std::endl;
    }

    emptyQueue.print();
    assignedQueue.print();
}

// You can then call this function in your main or in your test suite.
int main() {
    runListQueueTests();
    runCopyAssignmentTests();
    return 0;
}
