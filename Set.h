//
// Created by Ryan.Zurrin001 on 1/16/2022.
//

#ifndef SET_SET_H
#define SET_SET_H
#include <bits/stdc++.h>
using namespace std;
// define getName to set the name of a variable to the object id
#define getName(x) #x
void powerSetHelper(string s, const string& o, vector<string> &v);
static int object_count = 0;
// buld an enum type for the differnt ways you can sort
enum SortType {
    ASCENDING,
    DESCENDING,
    RANDOM
};


template<typename ELEMENT>
class SetNode {
public:
    ELEMENT _element;
    SetNode<ELEMENT> *_next;
    SetNode<ELEMENT> *_prev;
    SetNode() {
        _next = nullptr;
        _prev = nullptr;
    }
    SetNode(ELEMENT elem) {
        this->_element = elem;
        this->_next = nullptr;
        this->_prev = nullptr;
    }
};

template<typename ELEMENT>
class Set {
    SetNode<ELEMENT> *_head;
    SetNode<ELEMENT> *_tail;
    string _id;
    int _size{};
    int _capacity{};
    bool _resizable{};
    bool _sorted{};
    bool _unique{};
    static string countToID(int count);
public:
    Set(int capacity = INT_MAX, bool sorted = false, bool unique = true, string id = countToID(object_count)); // constructor
    Set(ELEMENT elem, int capacity = INT_MAX, bool sorted = false, bool unique = true,string id = countToID(object_count)); // constructor
    Set(vector<ELEMENT> elements, bool sorted = false, bool unique = true, string id = countToID(object_count)); // constructor
    Set(Set<ELEMENT> &other); // copy constructor
    Set(Set<ELEMENT> &&other);// move constructor
    Set<ELEMENT>& operator=(const Set<ELEMENT> &other); // assignment operator

    ~Set();
    void add(ELEMENT elem);
    void remove(ELEMENT elem, bool all = false);
    bool contains(ELEMENT elem);
    void setID(string id);
    ELEMENT get(int i);
    ELEMENT getElement(ELEMENT elem);
    SetNode<ELEMENT>* getNode(ELEMENT elem);
    ELEMENT pickRandom();
    ELEMENT removeRandom();
    void sort(SortType sortType = ASCENDING);
    void shuffle();
    void clear();
    void print();
    void printUnion(Set<ELEMENT> &other);
    void printIntersection(Set<ELEMENT> &other);
    void printSymmetricDifference(Set<ELEMENT> &other);
    void printReverse();
    int size();
    int elementCount(ELEMENT elem);
    int capacity();
    bool isFull();
    void resize();
    void setResizable(bool resizable);
    void setSorted(bool sorted);
    void setUnique(bool unique);
    // getHead()
    SetNode<ELEMENT>* getHead();
    // getTail()
    SetNode<ELEMENT>* getTail();
    vector<vector<char>> getPowerSet(bool print = false);

    bool isSubsetOf(Set<ELEMENT> other);
    bool isPropersubsetOf(Set<ELEMENT> other);
    bool isSupersetOf(Set<ELEMENT> other);
    bool isProperSupersetOf(Set<ELEMENT> other);
    bool isDisjointFrom(Set<ELEMENT> other);
    bool isEqualTo(Set<ELEMENT> other);
    bool isEmptySet();
    bool sorted();
    bool unique();
    bool resizable();
    int getObjectCount();

    string toString();
    SetNode<ELEMENT>* operator()(ELEMENT elem) {
        return this->getNode(elem);
    }
    Set<ELEMENT> operator[] (ELEMENT elem) {
        Set<ELEMENT> temp;
        temp.add(elem);
        return temp;
    }

    template<typename T>
    friend ostream& operator<<(ostream& os, Set<T>& s);

    bool operator==(Set<ELEMENT> &other)  {
        return this->isEqualTo(other);
    }
    bool operator!=( Set<ELEMENT> &other) {
        return !(*this == other);
    }
    bool operator<( Set<ELEMENT> &other) {
        return this->_size < other._size;
    }
    bool operator>( Set<ELEMENT> &other) {
        return this->_size > other._size;
    }
    bool operator<=( Set<ELEMENT> &other) {
        return this->_size <= other._size;
    }
    bool operator>=( Set<ELEMENT> &other) {
        return this->_size >= other._size;
    }

    // overload the+ operator to add an ELEMENT to the set
    Set<ELEMENT> operator+(ELEMENT elem) {
        Set<ELEMENT> temp = *this;
        temp.add(elem);
        return temp;
    }
    // overload the += operator to add an ELEMENT to the set
    Set<ELEMENT>& operator+=(ELEMENT elem) {
        this->add(elem);
        return *this;
    }
    // overload the + operator to add two sets together
    Set<ELEMENT> operator+(const Set<ELEMENT> &other) {
        Set<ELEMENT> result;
        bool unique = (this->_unique && other._unique);
        bool sorted = this->_sorted && other._sorted;
        result.setUnique(unique);
        result.setSorted(sorted);
        SetNode<ELEMENT> *temp = this->_head;
        while (temp != nullptr) {
            result.add(temp->_element);
            temp = temp->_next;
        }
        temp = other._head;
        while (temp != nullptr) {
            result.add(temp->_element);
            temp = temp->_next;
        }
        return result;
    }
    // overload the += operator to add a set to another set
    Set<ELEMENT>& operator+=(const Set<ELEMENT> &other) {
        for (int i = 0; i < other.size(); i++) {
            this->add(other[i]);
        }
        return *this;
    }
    // overload the - operator to remove an ELEMENT from a set
    Set<ELEMENT> operator-(const ELEMENT& elem) const {
        Set<ELEMENT> temp = *this;
        temp.remove(elem);
        return temp;
    }
    // overload the -= operator to remove an ELEMENT from a set
    Set<ELEMENT>& operator-=(const ELEMENT& elem) {
        this->remove(elem);
        return *this;
    }
    // overload the - operator to remove simialr ELEMENTs from one set out of another
    Set<ELEMENT> operator-(const Set<ELEMENT> &other)const  {
        Set<ELEMENT> temp = *this;
        for (int i = 0; i < other.size(); i++) {
            temp.remove(other[i]);
        }
        return temp;
    }
    // overload the -= operator to remove simialr ELEMENTs from one set out of another
    Set<ELEMENT>& operator-=(const Set<ELEMENT> &other) {
        for (int i = 0; i < other.size(); i++) {
            this->remove(other[i]);
        }
        return *this;
    }
    // overload the % operator to find the intersection of two sets
    Set<ELEMENT> operator%(Set<ELEMENT> &other) const {
        Set<ELEMENT> result;
        SetNode<ELEMENT>* temp = this->_head;
        while (temp != nullptr) {
            if (other.contains(temp->_element)) {
                result.add(temp->_element);
            }
            temp = temp->_next;
        }
        return result;
    }
    // overload the %= operator to find the intersection of two sets
    Set<ELEMENT>& operator%=(Set<ELEMENT> &other) {
        Set<ELEMENT> result;
        SetNode<ELEMENT>* temp = this->_head;
        while (temp != nullptr) {
            if (other.contains(temp->_element)) {
                result.add(temp->_element);
            }
            temp = temp->_next;
        }
        *this = result;
        return *this;
    }
    // overload the * operator to find the union of two sets
    Set<ELEMENT> operator*(Set<ELEMENT> &other)const  {
        Set<ELEMENT> result;
        SetNode<ELEMENT>* temp = this->_head;
        while (temp != nullptr) {
            result.add(temp->_element);
            temp = temp->_next;
        }
        temp = other._head;
        while (temp != nullptr) {
            result.add(temp->_element);
            temp = temp->_next;
        }
        return result;
    }
    // overload the *= operator to find the union of two sets
    Set<ELEMENT>& operator*=(Set<ELEMENT> &other) {
        Set<ELEMENT> result;
        SetNode<ELEMENT>* temp = this->_head;
        while (temp != nullptr) {
            result.add(temp->_element);
            temp = temp->_next;
        }
        temp = other._head;
        while (temp != nullptr) {
            result.add(temp->_element);
            temp = temp->_next;
        }
        *this = result;
        return *this;
    }
    // overload the / operator to find the symmetric difference of two sets
    Set<ELEMENT> operator/(Set<ELEMENT> &other) {
        Set<ELEMENT> result;
        SetNode<ELEMENT>* temp = this->_head;
        while (temp != nullptr) {
            if (!other.contains(temp->_element)) {
                result.add(temp->_element);
            }
            temp = temp->_next;
        }
        temp = other._head;
        while (temp != nullptr) {
            if (!this->contains(temp->_element)) {
                result.add(temp->_element);
            }
            temp = temp->_next;
        }
        return result;
    }
    // overload the /= operator to find the symmetric difference of two sets
    Set<ELEMENT>& operator/=(const Set<ELEMENT> &other) {
        Set<ELEMENT> result;
        SetNode<ELEMENT>* temp = this->_head;
        while (temp != nullptr) {
            if (!other.contains(temp->_element)) {
                result.add(temp->_element);
            }
            temp = temp->_next;
        }
        temp = other._head;
        while (temp != nullptr) {
            if (!this->contains(temp->_element)) {
                result.add(temp->_element);
            }
            temp = temp->_next;
        }
        *this = result;
        return *this;
    }
    // overload the ^ operator to find the complement of a set
    Set<ELEMENT> operator^(const Set<ELEMENT> &other)const  {
        Set<ELEMENT> result;
        SetNode<ELEMENT>* temp = other._head;
        while (temp != nullptr) {
            if (!this->contains(temp->_element)) {
                result.add(temp->_element);
            }
            temp = temp->_next;
        }
        return result;
    }

    // iterators
    class iterator {
    public:
        iterator(SetNode<ELEMENT>* node) : _node(node) {}
        iterator& operator++() {
            _node = _node->_next;
            return *this;
        }
        iterator operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }
        bool operator==(const iterator& other) const {
            return _node == other._node;
        }
        bool operator!=(const iterator& other) const {
            return _node != other._node;
        }
        ELEMENT& operator*() {
            return _node->_element;
        }
        // hasNext
        bool hasNext() {
            return _node != nullptr;
        }
        // next
        ELEMENT next() {
            ELEMENT result = _node->_element;
            _node = _node->_next;
            return result;
        }
    private:
        SetNode<ELEMENT>* _node;
    };
    iterator begin() {
        return iterator(_head);
    }
    iterator end() {
        return iterator(nullptr);
    }
    // reverse iterators
    class reverse_iterator {
    public:
        reverse_iterator(SetNode<ELEMENT>* node) : _node(node) {}
        reverse_iterator& operator++() {
            _node = _node->_prev;
            return *this;
        }
        reverse_iterator operator++(int) {
            reverse_iterator temp = *this;
            ++(*this);
            return temp;
        }
        bool operator==(const reverse_iterator& other) const {
            return _node == other._node;
        }
        bool operator!=(const reverse_iterator& other) const {
            return _node != other._node;
        }
        ELEMENT& operator*() {
            return _node->_element;
        }
        // hasNext()
        bool hasNext() {
            return _node != nullptr;
        }
        // next()
        ELEMENT& next() {
            ELEMENT& temp = _node->_element;
            _node = _node->_prev;
            return temp;
        }
    private:
        SetNode<ELEMENT>* _node;
    };
    reverse_iterator rbegin() {
        return reverse_iterator(_tail);
    }
    reverse_iterator rend() {
        return reverse_iterator(nullptr);
    }
    // const iterators
    class const_iterator {
    public:
        const_iterator(SetNode<ELEMENT>* node) : _node(node) {}
        const_iterator& operator++() {
            _node = _node->_next;
            return *this;
        }
        const_iterator operator++(int) {
            const_iterator temp = *this;
            ++(*this);
            return temp;
        }
        bool operator==(const const_iterator& other) const {
            return _node == other._node;
        }
        bool operator!=(const const_iterator& other) const {
            return _node != other._node;
        }
        const ELEMENT& operator*() {
            return _node->_element;
        }
        // hasNext
        bool hasNext() {
            return _node != nullptr;
        }
        // next
        const ELEMENT& next() {
            const ELEMENT& temp = _node->_element;
            _node = _node->_next;
            return temp;
        }
    private:
        SetNode<ELEMENT>* _node;
    };
    const_iterator begin() const {
        return const_iterator(_head);
    }
    const_iterator end() const {
        return const_iterator(nullptr);
    }

};

template<typename ELEMENT>
Set<ELEMENT>::Set(int capacity, bool sorted, bool unique,string id) {
    object_count++;
    _id = id;
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
    _capacity = capacity;
    _resizable = false;
    _sorted = sorted;
    _unique = unique;
}

template<typename ELEMENT>
Set<ELEMENT>::Set(ELEMENT elem, int capacity, bool sorted, bool unique, string id) {
    object_count++;
    _id = id;
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
    _capacity = capacity;
    _resizable = true;
    _sorted = sorted;
    _unique = unique;
    add(elem);
}

template<typename ELEMENT>
Set<ELEMENT>::Set(vector<ELEMENT> elements, bool sorted, bool unique, string id) {
    object_count++;
    _id = id;
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
    _capacity = INT_MAX;
    _resizable = false;
    _sorted = sorted;
    _unique = unique;
    for (ELEMENT elem : elements) {
        add(elem);
    }
}

template<typename ELEMENT>
Set<ELEMENT>::Set(Set<ELEMENT> &other) {
    object_count++;
    _id = countToID(object_count);
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
    _capacity = INT_MAX;
    _resizable = other._resizable;
    _sorted = other._sorted;
    _unique = other._unique;
    for (ELEMENT elem : other) {
        add(elem);
    }
}

template<typename ELEMENT>
Set<ELEMENT>::Set(Set<ELEMENT> &&other) {
    object_count++;
    _id = countToID(object_count);
    _head = other._head;
    _tail = other._tail;
    _size = other._size;
    _capacity = other._capacity;
    _resizable = other._resizable;
    _sorted = other._sorted;
    _unique = other._unique;
    other._head = nullptr;
    other._tail = nullptr;
    other._size = 0;
    other._capacity = INT_MAX;
    other._resizable = false;
    other._sorted = false;
    other._unique = false;
}

template<typename ELEMENT>
Set<ELEMENT> &Set<ELEMENT>::operator=(const Set<ELEMENT> &other) {
    object_count++;
    _id = countToID(object_count);
    if (this != &other) {
        clear();
        for (ELEMENT elem : other) {
            add(elem);
        }
    }
    return *this;
}

template<typename ELEMENT>
Set<ELEMENT>::~Set() {
    clear();
}

template<typename ELEMENT>
void Set<ELEMENT>::add(ELEMENT elem) {
    // adds unique elem to the set
    if (_unique) {
        if (contains(elem)) {
            return;
        }
    }
    if (_size == capacity() && _resizable) {
        resize();
    }
    if (_size == 0) {
        _head = new SetNode<ELEMENT>(elem);
        _tail = _head;
        _size++;
    } else if ((!contains(elem)) && (_size < _capacity) && _unique) {
        SetNode<ELEMENT> *newNode = new SetNode<ELEMENT>(elem);
        if (_sorted) {
            if (newNode->_element < _head->_element) {
                newNode->_next = _head;
                _head->_prev = newNode;
                _head = newNode;
            } else if (newNode->_element > _tail->_element) {
                _tail->_next = newNode;
                newNode->_prev = _tail;
                _tail = newNode;
            } else {
                SetNode<ELEMENT> *temp = _head;
                while (temp->_next != nullptr && temp->_next->_element < newNode->_element) {
                    temp = temp->_next;
                }
                newNode->_next = temp->_next;
                temp->_next = newNode;
                newNode->_prev = temp;
                if (newNode->_next != nullptr) {
                    newNode->_next->_prev = newNode;
                }
            }
        } else {
            newNode->_next = _head;
            _head->_prev = newNode;
            _head = newNode;
        }
        _size++;
    } else if ((_size < _capacity) && !_unique) {
        SetNode<ELEMENT> *newNode = new SetNode<ELEMENT>(elem);
        if (_sorted) {
            if (newNode->_element < _head->_element) {
                newNode->_next = _head;
                _head->_prev = newNode;
                _head = newNode;
            } else if (newNode->_element > _tail->_element) {
                _tail->_next = newNode;
                newNode->_prev = _tail;
                _tail = newNode;
            } else {
                SetNode<ELEMENT> *temp = _head;
                while (temp->_next != nullptr &&
                temp->_next->_element < newNode->_element) {
                    temp = temp->_next;
                }
                newNode->_next = temp->_next;
                temp->_next = newNode;
                newNode->_prev = temp;
                if (newNode->_next != nullptr) {
                    newNode->_next->_prev = newNode;
                }
            }
        } else {
            newNode->_next = _head;
            _head->_prev = newNode;
            _head = newNode;
        }
        _size++;
    } else {
        return;
    }
}

template<typename ELEMENT>
void Set<ELEMENT>::remove(ELEMENT elem, bool all) {
    // removes elem from the set
    if (_size == 0) {
        return;
    }
    do {
        SetNode<ELEMENT> *current = _head;
        while (current != nullptr) {
            if (current->_element == elem) {
                if (current == _head) {
                    _head = current->_next;
                    if (_head != nullptr) {
                        _head->_prev = nullptr;
                    }
                } else if (current == _tail) {
                    _tail = current->_prev;
                    if (_tail != nullptr) {
                        _tail->_next = nullptr;
                    }
                } else {
                    current->_prev->_next = current->_next;
                    current->_next->_prev = current->_prev;
                }
                delete current;
                _size--;
                return;
            }
            current = current->_next;
        }
    } while (all && elementCount(elem) > 0);
}

template<typename ELEMENT>
bool Set<ELEMENT>::contains(ELEMENT elem) {
    // returns true if the set contains the elem
    SetNode<ELEMENT> *current = _head;
    while (current != nullptr) {
        if (current->_element == elem) {
            return true;
        }
        current = current->_next;
    }
    return false;
}

template<typename ELEMENT>
ELEMENT Set<ELEMENT>::get(int i) {
    // returns the elem at index i
    if (i < 0 || i >= _size) {
        return NULL;
    }
    SetNode<ELEMENT> *current = _head;
    for (int j = 0; j < i; j++) {
        current = current->_next;
    }
    return current->_element;
}

template<typename ELEMENT>
ELEMENT Set<ELEMENT>::getElement(ELEMENT elem) {
    // returns the elem at index i
    if (_size == 0) {
        return NULL;
    }
    SetNode<ELEMENT> *current = _head;
    while (current != nullptr) {
        if (current->_element == elem) {
            return current->_element;
        }
        current = current->_next;
    }
    return NULL;
}

template<typename ELEMENT>
ELEMENT Set<ELEMENT>::pickRandom() {
    if (_size == 0) {
        throw std::out_of_range("Empty bag");
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, _size - 1);
    int i = dis(gen);
    SetNode<ELEMENT> *current = _head;
    for (int j = 0; j < i; j++) {
        current = current->_next;
    }
    return current->_element;
}

template<typename ELEMENT>
ELEMENT Set<ELEMENT>::removeRandom() {
    if (_size == 0) {
        throw std::out_of_range("Empty bag");
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, _size - 1);
    int i = dis(gen);
    SetNode<ELEMENT> *current = _head;
    for (int j = 0; j < i; j++) {
        current = current->_next;
    }
    ELEMENT _element = current->_element;
    if (current == _head) {
        _head = current->_next;
        if (_head != nullptr) {
            _head->_prev = nullptr;
        }
    } else if (current == _tail) {
        _tail = current->_prev;
        if (_tail != nullptr) {
            _tail->_next = nullptr;
        }
    } else {
        current->_prev->_next = current->_next;
        current->_next->_prev = current->_prev;
    }
    delete current;
    _size--;
    return _element;
}

template<typename ELEMENT>
void Set<ELEMENT>::sort(SortType sortType) {
    // sorts the set
    this->_sorted = true;
    if (_size == 0) {
        return;
    }
    std::srand(std::time(0));
    vector<ELEMENT> v;
    SetNode<ELEMENT> *current = _head;
    while (current != nullptr) {
        v.push_back(current->_element);
        current = current->_next;
    }
    // sort the vecotr occording to the sort type
    switch (sortType) {
        case SortType::ASCENDING:
            std::sort(v.begin(), v.end(), std::greater<ELEMENT>());
            break;
        case SortType::DESCENDING:
            std::sort(v.begin(), v.end());
            break;
        case SortType::RANDOM:
            std::random_shuffle(v.begin(), v.end());
            break;
    }
    clear();
    for (int i = 0; i < v.size(); i++) {
        add(v[i]);
    }
}

template<typename ELEMENT>
void Set<ELEMENT>::shuffle() {
    if (_size == 0) {
        return;
    }
    sort(RANDOM);
}

template<typename ELEMENT>
void Set<ELEMENT>::clear() {
    SetNode<ELEMENT> *current = _head;
    while (current != nullptr) {
        SetNode<ELEMENT> * next = current->_next;
        delete current;
        current = next;
    }
    object_count--;
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

template<typename ELEMENT>
void Set<ELEMENT>::print() {
    SetNode<ELEMENT> *current = _head;
    cout << _id << ": " << "{ ";
    while (current != nullptr) {
        std::cout << current->_element << " ";
        current = current->_next;
    }
    cout << "}" << endl;
    std::cout << std::endl;
}

template<typename ELEMENT>
void Set<ELEMENT>::printReverse() {
    SetNode<ELEMENT> *current = _tail;
    cout << _id << ": " << "{ ";
    while (current != nullptr) {
        std::cout << current->_element << " ";
        current = current->_prev;
    }
    cout << "}" << endl;
    std::cout << std::endl;
}
/**
 * @brief checks how many elements are in the set
 * @return  int: the size of the set
 */
template<typename ELEMENT>
int Set<ELEMENT>::size() {
    return _size;
}
/**
 * @brief counts how many times the given element is in the set
 * @tparam ELEMENT
 * @param elem
 * @return int: the number of times the element is in the set
 */
template<typename ELEMENT>
int Set<ELEMENT>::elementCount(ELEMENT elem) {
    if (_size == 0) {
        return 0;
    }
    if (_size == 1) {
        if (_head->_element == elem) {
            return 1;
        } else {
            return 0;
        }
    }
    if (_unique && contains(elem)) {
        return 1;
    }
    SetNode<ELEMENT> *current = _head;
    int count = 0;
    while (current != nullptr) {
        if (current->_element == elem) {
            count++;
        }
        current = current->_next;
    }
    return count;
}
/**
 * @brief checks the capacity of the set
 * @return int: the capacity of the set
 */
template<typename ELEMENT>
int Set<ELEMENT>::capacity() {
    return _capacity;
}


/**
 * @brief checks if the set is full
 * @tparam ELEMENT
 * @return  true if the set is full, false otherwise
 */
template<typename ELEMENT>
bool Set<ELEMENT>::isFull() {
    return _size == _capacity;
}
/**
 * @brief resize the capacity of the set
 */
template<typename ELEMENT>
void Set<ELEMENT>::resize() {
    // if the set is full, double the capacity
    // if the set is 1/4 full, halve the capacity
    if (_size == _capacity) {
        _capacity *= 2;
    } else if (_size == _capacity / 4) {
        _capacity /= 2;
    }
}
/**
 * @brief sets the resizable flag to true or false
 * @param resizable true or false to set the resizable flag
 */
template<typename ELEMENT>
void Set<ELEMENT>::setResizable(bool resizable) {
    _resizable = resizable;
}

template<typename ELEMENT>
string Set<ELEMENT>::toString() {
    stringstream ss;
    SetNode<ELEMENT> *current = _head;
    ss << _id << ": " << "{ ";
    while (current != nullptr) {
        ss << current->_element << " ";
        current = current->_next;
    }
    ss << "}";
    return ss.str();
}

template<typename ELEMENT>
void Set<ELEMENT>::setSorted(bool sorted) {
    _sorted = sorted;
}

template<typename ELEMENT>
void Set<ELEMENT>::setUnique(bool unique) {
    _unique = unique;
}

template<typename ELEMENT>
SetNode<ELEMENT> *Set<ELEMENT>::getHead() {
    return _head;
}

template<typename ELEMENT>
SetNode<ELEMENT> *Set<ELEMENT>::getTail() {
    return _tail;
}


template<typename T>
ostream &operator<<(ostream &os, Set<T> &s) {
    os << s.toString();
    return os;
}

template<typename ELEMENT>
bool Set<ELEMENT>::isSubsetOf(Set<ELEMENT> other) {
    set<ELEMENT> otherSet;
    set<ELEMENT> thisSet;
    SetNode<ELEMENT> *current = other._head;
    SetNode<ELEMENT> *current2 = _head;
    while (current != nullptr || current2 != nullptr) {
        if (current != nullptr) {
            otherSet.insert(current->_element);
            current = current->_next;
        }
        if (current2 != nullptr) {
            thisSet.insert(current2->_element);
            current2 = current2->_next;
        }
    }
    current = _head;
    while (current != nullptr) {
        if (otherSet.find(current->_element) == otherSet.end()) {
            return false;
        }
        current = current->_next;
    }
    current = nullptr;
    current2 = nullptr;
    delete current;
    delete current2;
    return true;
}

template<typename ELEMENT>
bool Set<ELEMENT>::isPropersubsetOf(Set<ELEMENT> other) {
    unordered_set<ELEMENT> otherSet;
    unordered_set<ELEMENT> thisSet;
    SetNode<ELEMENT> *current = other._head;
    SetNode<ELEMENT> *current2 = _head;
    while (current != nullptr || current2 != nullptr) {
        if (current != nullptr) {
            otherSet.insert(current->_element);
            current = current->_next;
        }
        if (current2 != nullptr) {
            thisSet.insert(current2->_element);
            current2 = current2->_next;
        }
    }
    current = _head;
    while (current != nullptr) {
        if (otherSet.find(current->_element) == otherSet.end()) {
            return false;
        }
        current = current->_next;
    }
    current = nullptr;
    current2 = nullptr;
    delete current;
    delete current2;
    return true && (otherSet.size() > thisSet.size());
}

template<typename ELEMENT>
bool Set<ELEMENT>::isSupersetOf(Set<ELEMENT> other) {
    // if the other set is a subset of this set, then this set is a superset
    return other.isSubsetOf(*this);
}
template<typename ELEMENT>
bool Set<ELEMENT>::isProperSupersetOf(Set<ELEMENT> other) {
    // if the other set is a proper subset of this set, then this set is a proper superset
    return other.isPropersubsetOf(*this);
}

template<typename ELEMENT>
bool Set<ELEMENT>::isDisjointFrom(Set<ELEMENT> other) {
    // if there are no elements in common in the two sets, then they are disjoint
    unordered_set<ELEMENT> otherSet;
    unordered_set<ELEMENT> thisSet;
    SetNode<ELEMENT> *current = other._head;
    SetNode<ELEMENT> *current2 = _head;
    while (current != nullptr || current2 != nullptr) {
        if (current != nullptr) {
            otherSet.insert(current->_element);
            current = current->_next;
        }
        if (current2 != nullptr) {
            thisSet.insert(current2->_element);
            current2 = current2->_next;
        }
    }
    current = _head;
    while (current != nullptr) {
        if (otherSet.find(current->_element) != otherSet.end()) {
            return false;
        }
        current = current->_next;
    }
    current = nullptr;
    current2 = nullptr;
    delete current;
    delete current2;
    return true;
}

template<typename ELEMENT>
bool Set<ELEMENT>::isEqualTo(Set<ELEMENT> other) {
    // if the two sets are equal, then they are equal
    unordered_set<ELEMENT> otherSet;
    unordered_set<ELEMENT> thisSet;
    SetNode<ELEMENT> *current = other._head;
    SetNode<ELEMENT> *current2 = _head;
    while (current != nullptr || current2 != nullptr) {
        if (current != nullptr) {
            otherSet.insert(current->_element);
            current = current->_next;
        }
        if (current2 != nullptr) {
            thisSet.insert(current2->_element);
            current2 = current2->_next;
        }
    }
    current = _head;
    while (current != nullptr) {
        if (otherSet.find(current->_element) == otherSet.end()) {
            return false;
        }
        current = current->_next;
    }
    current = nullptr;
    current2 = nullptr;
    delete current;
    delete current2;
    return true && (otherSet.size() == thisSet.size());
}
/**
 * @brief checks if the set is theempty set
 * @return  true if the set is empty, false otherwise
 */
template<typename ELEMENT>
bool Set<ELEMENT>::isEmptySet() {
    return _head == nullptr;
}


template<typename ELEMENT>
vector<vector<char>> Set<ELEMENT>::getPowerSet(bool print) {
    //cout << "Power Set" << endl;
    vector<string> result;
    stringstream ss;
    Set<ELEMENT> *tmp(this);
    if (!_sorted) {
        tmp->sort(ASCENDING);
    }

    // convert the contesnts of the set to a string
    SetNode<ELEMENT> *current = tmp->_head;
    while (current != nullptr) {
        ss << current->_element;
        current = current->_next;
    }
    string s = ss.str();
    powerSetHelper(s, "", result);
    vector<vector<char>> v;
    //reverse the result vector
    // convert the strings back to the elements
    for (string str : result) {
        vector<char> temp;
        for (char c : str) {
            temp.push_back(c);
        }
        //reverse(temp.begin(), temp.end());
        v.push_back(temp);
    }
    if (print) {
        int i = 1;
        cout << "power set:\n";
        for (vector<char> vc : v) {
            cout << i << ": ";
            for (char c : vc) {
                cout << c << " ";
            }
            i++;
            cout << endl;
        }
    }
    tmp = nullptr;
    delete tmp;
    current = nullptr;
    delete current;
    //cout << "end power set" << endl;
    return v;
}

template<typename ELEMENT>
SetNode<ELEMENT> *Set<ELEMENT>::getNode(ELEMENT elem) {
    SetNode<ELEMENT> *current = _head;
    while (current != nullptr) {
        if (current->_element == elem) {
            return current;
        }
        current = current->_next;
    }
    return nullptr;
}

template<typename ELEMENT>
bool Set<ELEMENT>::sorted() {
    return _sorted;
}

template<typename ELEMENT>
bool Set<ELEMENT>::unique() {
    return _unique;
}

template<typename ELEMENT>
bool Set<ELEMENT>::resizable() {
    return _resizable;
}

template<typename ELEMENT>
void Set<ELEMENT>::printUnion(Set<ELEMENT> &other) {
    Set<ELEMENT> tmp;
    tmp = other  *  *this;
    cout << this->_id << " U " << other._id << ": ";
    cout << "{ ";
    for (ELEMENT elem : tmp) {
        cout << elem << " ";
    }
    cout << "}" << endl;

}


template<typename ELEMENT>
void Set<ELEMENT>::printIntersection(Set<ELEMENT> &other) {
    Set<ELEMENT> tmp;
    tmp = other % *this;
    cout << this->_id << " ∩ " << other._id << ": ";
    cout << "{ ";
    for (ELEMENT elem : tmp) {
        cout << elem << " ";
    }
    cout << "}" << endl;
}


template<typename ELEMENT>
void Set<ELEMENT>::printSymmetricDifference(Set<ELEMENT> &other) {
    Set<ELEMENT> tmp;
    tmp = other / *this;
    cout << this->_id << " Δ " << other._id << ": ";
    cout << "{ ";
    for (ELEMENT elem : tmp) {
        cout << elem << " ";
    }
    cout << "}" << endl;
}



// use dynamic programmin to find all  subsequences of a string
void powerSetHelper(string s, const string& o, vector<string> &v) {
    if (s.length() == 0) {
        v.push_back(o);
        return;
    }
    powerSetHelper(s.substr(1), o, v);
    powerSetHelper(s.substr(1), o + s[0], v);
    sort(v.begin(), v.end(), [](const string& s1, const string& s2) {
        if (s1.length() == s2.length()) {
            return s1 < s2;
        } else {
            return s1.length() < s2.length();
        }
    });
}
template<typename ELEMENT>
string Set<ELEMENT>::countToID(int count) {
    switch (count) {
        case 0:
            return "A"; break;
        case 1:
            return "B"; break;
        case 2:
            return "C"; break;
        case 3:
            return "D"; break;
        case 4:
            return "E"; break;
        case 5:
            return "F"; break;
        case 6:
            return "G"; break;
        case 7:
            return "H"; break;
        case 8:
            return "I"; break;
        case 9:
            return "J"; break;
        case 10:
            return "K"; break;
        case 11:
            return "L"; break;
        case 12:
            return "M"; break;
        case 13:
            return "N"; break;
        case 14:
            return "O"; break;
        case 15:
            return "P"; break;
        case 16:
            return "Q"; break;
        case 17:
            return "R"; break;
        case 18:
            return "S"; break;
        case 19:
            return "T"; break;
        case 20:
            return "U"; break;
        case 21:
            return "V"; break;
        case 22:
            return "W"; break;
        case 23:
            return "X"; break;
        case 24:
            return "Y"; break;
        case 25:
            return "Z"; break;
        default:
            return "ABC";
    }
}

template<typename ELEMENT>
void Set<ELEMENT>::setID(string id) {
    _id = id;
}

template<typename ELEMENT>
int Set<ELEMENT>::getObjectCount() {
    return object_count;
}


#endif //SET_SET_H
