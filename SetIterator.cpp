#include "SetIterator.h"
#include "Set.h"
#include<exception>
// Constructor: O(1)
// - Both best and worst case complexities are Theta(1) because initializing a SetIterator object with a reference to a Set and setting the currentNode pointer to the head of the set does not depend on the size of the set.

SetIterator::SetIterator(const Set& s) : set(s), currentNode(s.head)
{
}
// first(): O(1)
// - Both best and worst case complexities are Theta(1) because setting the currentNode pointer to the head of the set is a constant time operation regardless of the size of the set.

void SetIterator::first() {
    currentNode = set.head;
}
// next(): O(1)
// - Both best and worst case complexities are Theta(1) because moving the currentNode pointer to the next node in the set is a constant time operation.

void SetIterator::next() {
    if (!valid()) {
        throw std::exception("Invalid iterator state: next() called on an invalid iterator.");
    }
    currentNode = currentNode->next;
}
// getCurrent(): O(1)
// - Both best and worst case complexities are Theta(1) because accessing the data stored in the currentNode is a constant time operation.

TElem SetIterator::getCurrent() {
    if (!valid()) {
        throw std::exception("Invalid iterator state: getCurrent() called on an invalid iterator.");
    }
    return currentNode->data;
}
// valid(): O(1)
// - Both best and worst case complexities are Theta(1) because checking if the currentNode pointer is not null is a constant time operation.
bool SetIterator::valid() const {
    return currentNode != nullptr;
}
