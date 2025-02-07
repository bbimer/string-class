#include "string.h"
#include <iostream>

using namespace std;

int main() {
    try {
        String str1("hello");
        String str2("here are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form");
        String str3 = str1 + str2;
        cout << "operator +\t";
        str3.print();
        cout << "operator +=\t";
        String str4 = str1 += str2;
        str4.print();
        cout << "operator []\t" << str4[3] << endl;
        cout << "operator <<\t" << str1 << endl;
        cout << "operator ==\t" << (str1 == str2) << endl;
        cout << "operator !=\t" << (str1 != str2) << endl;
        cout << "operator >\t" << (str1 > str2) << endl;
        cout << "operator <\t" << (str1 < str2) << endl;
        String str5 = std::move(str1);
        cout << "operator (move)\t" << str4 << endl;
    }
    catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
