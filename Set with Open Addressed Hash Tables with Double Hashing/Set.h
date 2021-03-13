#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
#define NULL_TELEM -11111111
typedef int TElem;
class SetIterator;

class Set {
    //DO NOT CHANGE THIS PART
    friend class SetIterator;

private:
    TElem* T;
    int m, len;

    int hash1(TElem k) const
    {//theta(1)
        if (k < 0)
            return (-1) * (k % m);
        return k % m;
    }

    int hash2(TElem k) const
    {//theta(1)
        if (k < 0)
            return 1 + (-1) * (k % (m - 1));
        return 1 + (k % (m - 1));
    }

    int hash(TElem k, int i) const
    {//theta(1)
        return (hash1(k) + i * hash2(k)) % m;
    }

public:
    //implicit constructor
    Set();

    //adds an element to the set
    //returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
    bool add(TElem e);

    //removes an element from the set
    //returns true if e was removed, false otherwise
    bool remove(TElem e);

    //checks whether an element belongs to the set or not
    bool search(TElem elem) const;

    //returns the number of elements;
    int size() const;

    //check whether the set is empty or not;
    bool isEmpty() const;

    //return an iterator for the set
    SetIterator iterator() const;

    // destructor
    ~Set();

    Set durchschnitt(Set s2, Set s3);
};


