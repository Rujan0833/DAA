#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int temp;
    cout << "Steps to compute GCD(" << a << ", " << b << "):" << endl;
    while (b != 0) {
        cout << a << " = " << b << " * " << a / b << " + " << a % b << endl;
        temp = b;
        b = a % b;
        a = temp;
    }
    cout << "GCD = " << a << endl;
    return a;
}

int main() {
    int a, b;
    cout << "Enter two positive integers: ";
    cin >> a >> b;
    gcd(a, b);
    return 0;
}