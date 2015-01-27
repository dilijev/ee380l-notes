#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

#include "Number.h"

using namespace std::rel_ops;
using namespace std;

// inline ostream& operator<<(ostream& out, const vector<Number>& v) {
void print(vector<Number>& v) {
    // iteration
    auto curr = v.begin();
    while (curr != v.end()) {
        cout << *curr << endl;
        curr++;
    }
    cout << endl;
}

void sort() {
    // initializer list
    vector<Number> v {Number(2), Number(3), Number(1), Number(0)};
    print(v);
    sort(v.begin(), v.end());
    print(v);
}

int main() {
    Number n(1);
    Number m(2);

    cout << "n: " << n << endl;
    cout << "m: " << m << endl;

    cout << "1<2  " << (n<m) << endl;
    cout << "1<=2 " << (n<=m) << endl;
    cout << "1>2  " << (n>m) << endl;
    cout << "1>=2 " << (n>=m) << endl;
    cout << "1==2 " << (n==m) << endl;
    cout << "1!=2 " << (n!=m) << endl;

    sort();
}
