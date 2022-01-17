#include <iostream>
#include "Set.h"
int main() {
    // test the Set class here
    Set<char> s;
    cout << "s is empty: " << s.isEmptySet() << endl;
    s.add('A');
    s.add('B');
    s.add('C');
    s.add('K');
    s.add('Q');
    s.add('P');
    s.add('Y');
    s.add('C');
    s.add('W');
    s.add('Q');
    s.add('T');
    cout << "s is empty: " << s.isEmptySet() << endl;
    cout << "is s full: " << s.isFull() << endl;
    cout << s << endl;
    std::cout << "size: " << s.size() << std::endl;
    std::cout << "contains q " << s.contains('Q') << std::endl;
    std::cout << "containts Z " << s.contains('Z') << std::endl;
    std::cout << "containts 27 " << s.contains('P') << std::endl;
    cout << "removing P and A\n";
    s.remove('P');
    s.remove('A');
    cout << s << endl;
    std::cout << "new size: " << s.size() << std::endl;
    std::cout << "contains Q " << s.contains('Q') << std::endl;
    std::cout << "containts Z " << s.contains('Z') << std::endl;
    std::cout << "containts P " << s.contains('P') << std::endl;
    // shuffle the set
    cout << "shuffling\n";
    s.shuffle();
    cout << s << endl;
    // sort the set
    cout << "sorting\n";
    s.sort(DESCENDING);
    cout << s << endl;
    // test the iterator
    cout << "testing iterator\n";
    Set<char>::iterator it = s.begin();
    while (it.hasNext()) {
        cout << *it << " ";
        it.next();
    }
    cout << endl;

    vector<vector<char>> powerSet = s.getPowerSet();
    Set<char> b;
    b.setUnique(false);
    for (int i = 0; i < powerSet.size(); i++) {
        for (int j = 0; j < powerSet[i].size(); j++) {
            b.add(powerSet[i][j]);
        }

    }
    cout <<"printing power set\n";
    cout << b << endl;
    // is s a subset of b?
    cout << "is s a subset of b? " << s.isSubsetOf(b) << endl;
    Set<char> c;
    c.add('Z');
    c.add('X');
    c.add('F');
    cout << "is c a subset of b? " << c.isSubsetOf(b) << endl;
    cout << "is b a subset of c? " << b.isSubsetOf(c) << endl;
    cout << "is b a subset of s? " << b.isSubsetOf(s) << endl;
    cout << "is s a subset of c? " << s.isSubsetOf(c) << endl;

    //cout << s << endl;
    cout << "printing in reverse order\n";
    s.printReverse();
    cout << endl;
    cout << "printint in normal order\n";
    s.print();
    cout << endl;
    cout << "clearing\n";
    s.clear();
    cout << s << endl;
    cout << "is s empty: " << s.isEmptySet() << endl;
    cout << "is s full: " << s.isFull() << endl;
    cout << "size: " << s.size() << endl;
    cout << "contains Q " << s.contains('Q') << endl;



    return 0;
}
