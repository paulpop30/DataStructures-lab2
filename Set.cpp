#include "Set.h"
#include "SetIterator.h"

// Constructor: 
// Best Case Complexity (Theta)(1)
// Worst Case Complexity (Theta)(1)
// Final Complexity O(1)

Set::Set() : head(nullptr), tail(nullptr), count(0) {}


// add :
// Best Case Complexity (Theta)(1) - Adding to an empty set
// Worst Case Complexity (Theta)(n) - Adding when element already exists or resizing is needed
// Final Complexity O(n)

bool Set::add(TElem elem) {
    if (search(elem)) {
        return false; // Element already exists in the set
    }

    Node* newNode = new Node(elem);
    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
    return true;
}

// remove: O(n)
// Best Case Complexity (Theta)(1) - Removing the head or tail element
// Worst Case Complexity (Theta)(n) - Removing from the middle of the set
// Final Complexity O(n)

bool Set::remove(TElem elem) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == elem) {
            if (current == head) {
                head = head->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
                else {
                    tail = nullptr; // Set became empty after removal
                }
            }
            else if (current == tail) {
                tail = tail->prev;
                tail->next = nullptr;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            count--;
            return true;
        }
        current = current->next;
    }
    return false; // Element not found in the set
}

// search: 
// Best Case Complexity (Theta)(1) - Finding the element at the head or tail
// Worst Case Complexity (Theta)(n) - Finding the element at the middle or not found
// Final Complexity O(n)

bool Set::search(TElem elem) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == elem) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// size:
// Best Case Complexity (Theta)(1)
// Worst Case Complexity (Theta)(1)
// Final Complexity O(1)

int Set::size() const {
    return count;
}

// isEmpty:
// Best Case Complexity (Theta)(1)
// Worst Case Complexity (Theta)(1)
// Final Complexity O(1)

bool Set::isEmpty() const {
    return count == 0;
}
// Destructor:
// Best Case Complexity (Theta)(1) - When the set is empty
// Worst Case Complexity (Theta)(n) - When there are n elements in the set
// Final Complexity O(n)

Set::~Set() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// iterator:
// Best Case Complexity (Theta)(1)
// Worst Case Complexity (Theta)(1)
// Final Complexity O(1)

SetIterator Set::iterator() const {
    return SetIterator(*this);
}
