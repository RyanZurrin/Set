//
// Created by Ryan.Zurrin001 on 1/16/2022.
//

#ifndef SET_SET_H
#define SET_SET_H
#include <bits/stdc++.h>
using namespace std;

template<typename ITEM>
class SetNode {
public:
    ITEM data;
    SetNode<ITEM> *next;
    SetNode<ITEM> *prev;
    SetNode() {
        next = nullptr;
        prev = nullptr;
    }
    SetNode(ITEM data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template<typename ITEM>
class Set {
    SetNode<ITEM> *_head;
    SetNode<ITEM> *_tail;
    SetNode<ITEM> *_current;
    int _size;
    int _capacity;
    bool _resizable;
public:
    Set(int capacity = INT_MAX); // constructor
    Set(ITEM data, int capacity = INT_MAX); // constructor
    Set(vector<ITEM> data); // constructor
    Set(const Set<ITEM> &other); // copy constructor
    Set(Set<ITEM> &&other);// move constructor
    Set<ITEM>& operator=(const Set<ITEM> &other); // assignment operator

    ~Set();
    void insert(ITEM data);
    void remove(ITEM data);
    bool contains(ITEM data);
    ITEM get(int i);
    ITEM pickRandom();
    ITEM removeRandom();
    void sort();
    void shuffle();
    void clear();
    void print();
    void printReverse();
    int size();
    int capacity();
    bool isEmpty();
    bool isFull();
    void resize();
    void setResizable(bool resizable);
    string toString();
    // overload the () operator
    SetNode<ITEM>* operator()(ITEM data);
    Set<ITEM> operator[](int i);

    template<typename T>
    friend ostream& operator<<(ostream& os, Set<T>& s);

    bool operator==(const Set<ITEM> &other);
    bool operator!=(const Set<ITEM> &other);
    bool operator<(const Set<ITEM> &other);
    bool operator>(const Set<ITEM> &other);
    bool operator<=(const Set<ITEM> &other);
    bool operator>=(const Set<ITEM> &other);

    // Iterator class
    class Iterator {
        SetNode<ITEM> *_current;
        SetNode<ITEM> *_head;
        SetNode<ITEM> *_tail;
    public:
        Iterator(SetNode<ITEM> *current, SetNode<ITEM> *head, SetNode<ITEM> *tail) {
            _current = current;
            _head = head;
            _tail = tail;
        }
        Iterator(const Iterator &other) {
            _current = other._current;
            _head = other._head;
            _tail = other._tail;
        }
        Iterator(Iterator &&other) {
            _current = other._current;
            _head = other._head;
            _tail = other._tail;
        }
        Iterator& operator=(const Iterator &other) {
            _current = other._current;
            _head = other._head;
            _tail = other._tail;
            return *this;
        }
        Iterator& operator=(Iterator &&other) {
            _current = other._current;
            _head = other._head;
            _tail = other._tail;
            return *this;
        }
        bool operator==(const Iterator &other) {
            return _current == other._current;
        }
        bool operator!=(const Iterator &other) {
            return _current != other._current;
        }
        Iterator& operator++() {
            if (_current == nullptr) {
                _current = _head;
            } else {
                _current = _current->next;
            }
            return *this;
        }
        Iterator& operator--() {
            if (_current == nullptr) {
                _current = _tail;
            } else {
                _current = _current->prev;
            }
            return *this;
        }
        ITEM& operator*() {
            return _current->data;
        }
        ITEM* operator->() {
            return &_current->data;
        }
        // hasNext()
        // next()
        ITEM next() {
            if (_current == nullptr) {
                _current = _head;
            } else {
                _current = _current->next;
            }
            return _current->data;
        }
        ITEM hasNext() {
            if (_current == nullptr) {
                return _head->data;
            } else {
                return _current->next->data;
            }
        }

    };
    Iterator begin() {
        return Iterator(_head, _head, _tail);
    }
    Iterator end() {
        return Iterator(_tail, _head, _tail);
    }
    // Reverse Iterator class
    class ReverseIterator {
        SetNode<ITEM> *_current;
        SetNode<ITEM> *_head;
        SetNode<ITEM> *_tail;
    public:
        ReverseIterator(SetNode<ITEM> *current, SetNode<ITEM> *head, SetNode<ITEM> *tail) {
            _current = current;
            _head = head;
            _tail = tail;
        }
        ReverseIterator(const ReverseIterator &other) {
            _current = other._current;
            _head = other._head;
            _tail = other._tail;
        }
        ReverseIterator(ReverseIterator &&other) {
            _current = other._current;
            _head = other._head;
            _tail = other._tail;
        }
        ReverseIterator& operator=(const ReverseIterator &other) {
            _current = other._current;
            _head = other._head;
            _tail = other._tail;
            return *this;
        }
        ReverseIterator& operator=(ReverseIterator &&other) {
            _current = other._current;
            _head = other._head;
            _tail = other._tail;
            return *this;
        }
        bool operator==(const ReverseIterator &other) {
            return _current == other._current;
        }
        bool operator!=(const ReverseIterator &other) {
            return _current != other._current;
        }
        ReverseIterator& operator++() {
            if (_current == nullptr) {
                _current = _tail;
            } else {
                _current = _current->prev;
            }
            return *this;
        }
        ReverseIterator& operator--() {
            if (_current == nullptr) {
                _current = _head;
            } else {
                _current = _current->next;
            }
            return *this;
        }
        ITEM& operator*() {
            return _current->data;
        }
        ITEM* operator->() {
            return &_current->data;
        }
    };
    ReverseIterator rbegin() {
        return ReverseIterator(_tail, _head, _tail);
    }
    ReverseIterator rend() {
        return ReverseIterator(_head, _head, _tail);
    }

};


template<typename ITEM>
Set<ITEM>::Set(int capacity) {
    _head = new SetNode<ITEM>();
    _tail = new SetNode<ITEM>();
    _head->next = _tail;
    _tail->prev = _head;
    _size = 0;
    _capacity = capacity;
    _resizable = false;
}

template<typename ITEM>
Set<ITEM>::Set(ITEM data, int capacity) {
    _head = new SetNode<ITEM>();
    _tail = new SetNode<ITEM>();
    _head->next = _tail;
    _tail->prev = _head;
    _size = 0;
    _capacity = capacity;
    _resizable = false;
    insert(data);
}

template<typename ITEM>
Set<ITEM>::Set(vector<ITEM> data) {
    // adds all elements in data to the set only keeping unique elements
    _head = new SetNode<ITEM>();
    _tail = new SetNode<ITEM>();
    _head->next = _tail;
    _tail->prev = _head;
    _size = 0;
    _capacity = data.size();
    _resizable = false;
    for (auto it = data.begin(); it != data.end(); ++it) {
        insert(*it);
    }
}


template<typename ITEM>
Set<ITEM>::Set(const Set<ITEM> &other) {
    _head = new SetNode<ITEM>();
    _tail = new SetNode<ITEM>();
    _head->next = _tail;
    _tail->prev = _head;
    _size = 0;
    _capacity = other._capacity;
    _resizable = other._resizable;
    for (auto it = other.begin(); it != other.end(); ++it) {
        insert(*it);
    }
}

template<typename ITEM>
Set<ITEM>::Set(Set<ITEM> &&other) {
    _head = other._head;
    _tail = other._tail;
    _size = other._size;
    other._head = nullptr;
    other._tail = nullptr;
    _capacity = other._capacity;
    _resizable = other._resizable;
    other._size = 0;
}

template<typename ITEM>
Set<ITEM> &Set<ITEM>::operator=(const Set<ITEM> &other) {
    if (this != &other) {
        _head = new SetNode<ITEM>();
        _tail = new SetNode<ITEM>();
        _head->next = _tail;
        _tail->prev = _head;
        _size = 0;
        _capacity = other._capacity;
        _resizable = other._resizable;
        for (auto it = other.begin(); it != other.end(); ++it) {
            insert(*it);
        }
    }
    return *this;
}

template<typename ITEM>
Set<ITEM>::~Set() {
    clear();
}


template<typename ITEM>
void Set<ITEM>::insert(ITEM data) {
    // checks to makes sure the data is not already in the set
    if (contains(data)) {
        return;
    }
    // checks to make sure the set is not full
    if (_size == _capacity) {
        if (_resizable) {
            _capacity *= 2;
        } else {
            return;
        }
    }
    // creates a new node to be added to the set
    SetNode<ITEM> *newNode = new SetNode<ITEM>(data);
    // adds the new node to the set
    cout << "adding " << data << endl;
    _head->next->prev = newNode;
    newNode->next = _head->next;
    _head->next = newNode;
    newNode->prev = _head;
    _size++;
}


template<typename ITEM>
void Set<ITEM>::remove(ITEM data) {
    // checks to makes sure the data is in the set
    if (!contains(data)) {
        return;
    }
    // finds the node to be removed
    SetNode<ITEM> *node = _head->next;
    while (node->data != data) {
        node = node->next;
    }
    // removes the node from the set
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    _size--;
    if (_size < _capacity / 4) {
        if (_resizable) {
            _capacity /= 2;
        }
    }
}

template<typename ITEM>
bool Set<ITEM>::contains(ITEM data) {
    // iterates through the set to see if the data is in the set
    for (auto it = begin(); it != end(); ++it) {
        if (*it == data) {
            return true;
        }
    }
    return false;
}

template<typename ITEM>
ITEM Set<ITEM>::get(int i) {
    // returns the ith element in the set
    if (i < 0 || i >= _size) {
        throw out_of_range("index out of range");
    }
    SetNode<ITEM> *current = _head->next;
    for (int j = 0; j < i; j++) {
        current = current->next;
    }
    return current->data;
}

template<typename ITEM>
ITEM Set<ITEM>::pickRandom() {
    if (isEmpty()) {
        throw std::out_of_range("Empty bag");
    }
    // generate using twister
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, _size - 1);
    int i = dis(gen);
    return get(i);
}

template<typename ITEM>
ITEM Set<ITEM>::removeRandom() {
    if (isEmpty()) {
        throw std::out_of_range("Empty bag");
    }
    // generate using twister
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, _size - 1);
    int i = dis(gen);
    return remove(get(i));
}

template<typename ITEM>
void Set<ITEM>::sort() {
    // sorts the set using insertion sort
    SetNode<ITEM> *current = _head->next;
    while (current != _tail) {
        SetNode<ITEM> *temp = current->next;
        while (temp != _tail) {
            if (temp->data < current->data) {
                // swaps the data
                ITEM tempData = temp->data;
                temp->data = current->data;
                current->data = tempData;
            }
            temp = temp->next;
        }
        current = current->next;
    }
}

template<typename ITEM>
void Set<ITEM>::shuffle() {
    // shuffles the set using the Fisher-Yates algorithm
    for (int i = 0; i < _size; i++) {
        // generate using twister
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, _size - 1);
        int j = dis(gen);
        // swaps the data
        ITEM tempData = get(i);
        remove(get(i));
        insert(tempData);
    }
}

template<typename ITEM>
void Set<ITEM>::print() {
    // use iterator to print the set
    for (auto it = begin(); it != end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

template<typename ITEM>
void Set<ITEM>::printReverse() {
    // use a reverse iterator to print the set in reverse order
    for (auto it = rbegin(); it != rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

template<typename ITEM>
int Set<ITEM>::capacity() {
    return _capacity;
}

template<typename ITEM>
bool Set<ITEM>::isEmpty() {
    return _size == 0;
}

template<typename ITEM>
bool Set<ITEM>::isFull() {
    return _size == _capacity;
}

template<typename ITEM>
void Set<ITEM>::resize() {
    // cheks tosee if it is full and if it is it doubles the capacity
    if (_size == _capacity) {
        _capacity *= 2;
    }
    // cheks to see if it is at 1/4 capacity and if it is it halves the capacity
    else if (_size == _capacity / 4) {
        _capacity /= 2;
    }
}

template<typename ITEM>
void Set<ITEM>::clear() {
    SetNode<ITEM> *current = _head->next;
    while (current != _tail) {
        SetNode<ITEM> *next = current->next;
        delete current;
        current = next;
    }
    _head->next = _tail;
    _tail->prev = _head;
    _size = 0;
}

template<typename ITEM>
int Set<ITEM>::size() {
    return _size;
}


template<typename ITEM>
bool Set<ITEM>::operator==(const Set<ITEM> &other) {
    if (_size != other._size) {
        return false;
    }
    for (auto it = begin(); it != end(); ++it) {
        if (other.find(*it) == other.end()) {
            return false;
        }
    }
    return true;
}

template<typename ITEM>
bool Set<ITEM>::operator!=(const Set<ITEM> &other) {
    return !(*this == other);
}

template<typename ITEM>
bool Set<ITEM>::operator<(const Set<ITEM> &other) {
    if (_size < other._size) {
        return true;
    }
    return false;
}

template<typename ITEM>
bool Set<ITEM>::operator>(const Set<ITEM> &other) {
    if (_size > other._size) {
        return true;
    }
    return false;
}

template<typename ITEM>
bool Set<ITEM>::operator>=(const Set<ITEM> &other) {
    if (*this > other || *this == other) {
        return true;
    }
    return false;
}

template<typename ITEM>
bool Set<ITEM>::operator<=(const Set<ITEM> &other) {
    if (*this < other || *this == other) {
        return true;
    }
    return false;
}

template<typename T>
ostream &operator<<(ostream &os, Set<T> &s) {
    os << "{";
    // use iterator to print the set but not the tail
    for (auto it = s.begin(); it != s.end(); ++it) {
        os << *it << " ";
    }
    os << "}";
    return os;
}

template<typename ITEM>
Set<ITEM> Set<ITEM>::operator[](int i) {
    Set<ITEM> temp;
    for (auto it = begin(); it != end(); ++it) {
        if (i == 0) {
            temp.insert(*it);
        }
        i--;
    }
    return temp;
}

template<typename ITEM>
SetNode<ITEM> *Set<ITEM>::operator()(ITEM data) {
    SetNode<ITEM> *current = _head->next;
    while (current != _tail) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template<typename ITEM>
void Set<ITEM>::setResizable(bool resizable) {
    _resizable = resizable;
}

template<typename ITEM>
string Set<ITEM>::toString() {
    return "";
}


#endif //SET_SET_H
