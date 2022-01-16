#include <iostream>
#include "Set.h"
int main() {
    // test the Set class here
    Set<int> s;
    cout << "s is empty: " << s.isEmpty() << endl;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(8);
    s.insert(9);
    cout << "s is empty: " << s.isEmpty() << endl;
    cout << "is s full: " << s.isFull() << endl;
    cout << s << endl;
    std::cout << "size: " << s.size() << std::endl;
    std::cout << "contains 1 " << s.contains(1) << std::endl;
    std::cout << "containts 10 " << s.contains(10) << std::endl;
    std::cout << "containts 2 " << s.contains(2) << std::endl;
    cout << "removing 1 and 2\n";
    s.remove(1);
    s.remove(2);
    cout << s << endl;
    std::cout << s.size() << std::endl;
    std::cout << "contains 1 " << s.contains(1) << std::endl;
    std::cout << "containts 10 " << s.contains(10) << std::endl;
    std::cout << "containts 2 " << s.contains(2) << std::endl;
    // shuffle the set
    cout << "shuffling\n";
    s.shuffle();
    cout << s << endl;
    // sort the set
    cout << "sorting\n";
    s.sort();
    cout << s << endl;
    // test the iterator
    cout << "testing iterator\n";
    Set<int>::Iterator it = s.begin();
    while (it.hasNext()) {
        cout << *it << " ";
        it.next();
    }
    cout << endl;

    cout << s << endl;
    cout << "printing in reverse order\n";
    s.printReverse();
    cout << endl;
    cout << "printint in normal order\n";
    s.print();
    cout << endl;
    cout << "clearing\n";
    s.clear();
    cout << s << endl;
    cout << "is s empty: " << s.isEmpty() << endl;
    cout << "is s full: " << s.isFull() << endl;
    cout << "size: " << s.size() << endl;
    cout << "contains 1 " << s.contains(1) << endl;
    cout << "containts 10 " << s.contains(10) << endl;
    cout << "containts 2 " << s.contains(2) << endl;



    return 0;
}
