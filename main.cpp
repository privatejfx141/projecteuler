#include <iostream>
#include <math.h>
using namespace std;

long fibonacci(int n);
int gcd(int a, int b);
int lcm(int a, int b);
int problem1();
long problem2();
int problem5();


int main() {
    cout << "Problem 1: " << problem1() << endl;
    cout << "Problem 2: " << problem2() << endl;
    cout << "Problem 5: " << problem5() << endl;

    for (int i=1; i<=20; i++) {
        cout << i << " -> " << ((problem5()) / i) << endl;
    }
}

int problem1() {
    int sum = 0;
    for (int i=0; i<1000; ++i) {
        if ((i % 3 == 0) || (i % 5 == 0)) {
            sum += i;
        }
    }
    return sum;
}

long fibonacci(int n) {

    long value;
    // base cases n=1,2.
    if (n <= 1) {
        value = 1;
    } else if (n == 2) {
        value = 2;
    // recursive decomposition: n-1 and n-2 approaches
    } else {
        value = fibonacci(n-1) + fibonacci(n-2);
    }
    return value;

}

long problem2() {
    int limit = 4000000;
    long sum = 0;

    long fib_num = 0;
    int i = 1;
    while (fib_num < limit) {
        fib_num = fibonacci(i);
        if (fib_num % 2 == 0) {
            sum += fib_num;
        }
        i += 1;
    }
    return sum;
}

int gcd(int a, int b) {
    // base case.
    if (b == 0) {
        return a;
    // recursive decomposition.
    } else {
        return gcd(b, a % b);
    }

}

int lcm(int a, int b) {

    int div = (int) (a * b) / gcd(a, b);
    return div;

}

int problem5() {
    // smallest positive number.
    int value = 1;

    for (int i=1; i<20; ++i) {
        value = lcm(value, i);
    }
    return value;

}
