#include <iostream>
#include "Set.h"
int main() {
    // test the Set class here
    Set<char> s;
    s.setUnique(false);
    //s.setID(getName(s));
    s.add('A');
    s.add('B');
    s.add('Z');
    s.add('F');
    s.add('Q');
    s.add('S');
    s.add('X');
    s.add('Y');
    s.add('K');
    cout << s << endl;
    Set<char> s2;
    //s2.setID(getName(s2));
    s2.add('A');
    s2.add('B');
    s2.add('Z');
    s2.add('K');
    s2.add('Q');
    s2.add('K');
    cout << s2 << endl;
    Set<char> s3;
    //s3.setID(getName(s3));
    s3.setSorted(true);
    s3.setUnique(false);
    s3.add('Y');
    s3.add('X');
    s3.add('C');
    s3.add('N');
    s3.add('M');
    cout << s3 << endl;
    s.printUnion(s3);
    s.printIntersection(s3);
    s.printSymmetricDifference(s3);
    Set<char> s4;
    //s2.setID(getName(s2));
    s4.add('Z');
    s4.add('B');
    s4.add('A');
    s4.add('Q');
    s4.add('K');
    s4.add('K');

    Set<char> s5;
    s5.setUnique(false);
    s5 = s + s2;
    cout << s5 << endl;
    // get the power set of s3
    vector<vector<char>> v = s3.getPowerSet(true);

    Set<char> kleene = s3.kleeneClosure(3);
    cout << kleene << endl;
    Set<string> s6;
    s6.setUnique(false);
    s6.add("abc");
    s6.add("def");
    s6.add("ghi");
    s6.add("jkl");
    cout << s6 << endl;

    Set<string> s7;
    s7.setUnique(false);
    s7.add("a");
    s7.add("b");
    s7.add("c");
    s7.add("abc");
    s7.add("mno");
    s7.add("pqr");
    cout << s7 << endl;
    s6.printUnion(s7);
    s6.printIntersection(s7);
    s6.printSymmetricDifference(s7);

   // vector<vector<char>> v = s4.getPowerSet(true);

//    std::cout << "s isSubsetOf s2: " << s.isSubsetOf(s2) << std::endl;
//    std::cout << "s isProperSubsetOf s2: " << s.isPropersubsetOf(s2) << std::endl;
//    std::cout << "s isSubsetOf s3: " << s.isSubsetOf(s3) << std::endl;
//    std::cout << "s isProperSubsetOf s3: " << s.isPropersubsetOf(s3) << std::endl;
//    std::cout << "s isSupersetOf s2: " << s.isSupersetOf(s2) << std::endl;
//    std::cout << "s isProperSupersetOf s2: " << s.isProperSupersetOf(s2) << std::endl;
//    std::cout << "s isSupersetOf s3: " << s.isSupersetOf(s3) << std::endl;
//    std::cout << "s isDisjointFrom s2: " << s.isDisjointFrom(s2) << std::endl;
//    std::cout << "s isDisjointFrom s3: " << s.isDisjointFrom(s3) << std::endl;
//    // test the Set s2 noqw
//    std::cout << "s2 isSubsetOf s: " << s2.isSubsetOf(s) << std::endl;
//    std::cout << "s2 isProperSubsetOf s: " << s2.isPropersubsetOf(s) << std::endl;
//    std::cout << "s2 isSubsetOf s3: " << s2.isSubsetOf(s3) << std::endl;
//    std::cout << "s2 isProperSubsetOf s3: " << s2.isPropersubsetOf(s3) << std::endl;
//    std::cout << "s2 isSupersetOf s: " << s2.isSupersetOf(s) << std::endl;
//    std::cout << "s2 isProperSupersetOf s: " << s2.isProperSupersetOf(s) << std::endl;
//    std::cout << "s2 isSupersetOf s3: " << s2.isSupersetOf(s3) << std::endl;
//    std::cout << "s2 isProperSupersetOf s3: " << s2.isProperSupersetOf(s3) << std::endl;
//    std::cout << "s2 isDisjointFrom s: " << s2.isDisjointFrom(s) << std::endl;
//    std::cout << "s2 isDisjointFrom s3: " << s2.isDisjointFrom(s3) << std::endl;
//    // test the Set s3
//    std::cout << "s3 isSubsetOf s: " << s3.isSubsetOf(s) << std::endl;
//    std::cout << "s3 isProperSubsetOf s: " << s3.isPropersubsetOf(s) << std::endl;
//    std::cout << "s3 isSubsetOf s2: " << s3.isSubsetOf(s2) << std::endl;
//    std::cout << "s3 isProperSubsetOf s2: " << s3.isPropersubsetOf(s2) << std::endl;
//    std::cout << "s3 isSupersetOf s: " << s3.isSupersetOf(s) << std::endl;
//    std::cout << "s3 isProperSupersetOf s: " << s3.isProperSupersetOf(s) << std::endl;
//    std::cout << "s3 isSupersetOf s2: " << s3.isSupersetOf(s2) << std::endl;
//    std::cout << "s3 isProperSupersetOf s2: " << s3.isProperSupersetOf(s2) << std::endl;
//    std::cout << "s3 isDisjointFrom s: " << s3.isDisjointFrom(s) << std::endl;
//    std::cout << "s3 isDisjointFrom s2: " << s3.isDisjointFrom(s2) << std::endl;
    // test all of the relational operators
    std::cout << "s < s2: " << (s < s2) << std::endl;
    std::cout << "s > s2: " << (s > s2) << std::endl;
    std::cout << "s == s2: " << (s == s2) << std::endl;
    std::cout << "s >= s2: " << (s >= s2) << std::endl;
    std::cout << "s <= s2: " << (s <= s2) << std::endl;
    std::cout << "s != s2: " << (s != s2) << std::endl;
    std::cout << "s2 <= s3: " << (s2 <= s3) << std::endl;
    std::cout << "s2 == 42: " << (s2 == s4) << std::endl;


    return 0;
}
