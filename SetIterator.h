#pragma once
#include "Set.h"
#include"SetIterator.h"

class SetIterator {
    //DO NOT CHANGE THIS PART
    friend class Set;
private:
    //DO NOT CHANGE THIS PART
    const Set& set;
    SetIterator(const Set& s);
    Set::Node* currentNode;

public:
    void first();
    void next();
    TElem getCurrent();
    bool valid() const;
};
