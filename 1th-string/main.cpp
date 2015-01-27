#include <iostream>
#include "String.h"

using std::cout;
using std::endl;

void doit(String s) {
    // s was copied in from the calling site because this is neither a
    // reference nor a pointer
    cout << s << endl;
    // after the end of the function the destructor on s is called
    // which causes the string contents of s to be deleted
}

template <typename T>
T min(T x, T y) {
    if (y < x) { return y; }
    return x;
}

int main(void) {
    cout << ">>>" << endl;

    String s{"Hello, World"};
    doit(s);

    cout << s << endl;

    int a = 1;
    int b = 2;
    int c = min<int>(a,b);
    int d = min(a,b);
    double e = min<double>(a, 3.14);

    return 0;
}

