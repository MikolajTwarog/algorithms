#include <bits/stdc++.h>
using namespace std;

__uint128_t power(__uint128_t &n, __uint128_t k, __uint128_t &p) {
    if (k == 1)
        return n % p;
    // cout << k << endl;
    __uint128_t result = power(n, k/2, p);
    result = ((__uint128_t)(result)*result)%p;
    if (k % 2 == 1)
        result = ((__uint128_t)(result)*n)%p;
    return result;
}


bool primality_test(__uint128_t x) {
    if (x % 2 == 0 && x != 2)
        return false;
    
    int s = 0;
    __uint128_t d = x - 1;
    while (d % 2 == 0) {
        d = d >> 1;
        s++;
    }
    // cout << s << endl;

    __uint128_t a = rand() % (x-1) + 1;
    __uint128_t pow = power(a, d, x);

    // cout << d << " " << s << " " << a << " " << pow << endl;

    if (pow == 1)
        return true;
    
    for (int i = 0; i < s; i++) {
        if (pow == x - 1)
            return true;
        pow = ((__uint128_t)(pow)*pow)%x;
    }

    return false;
}

bool pr(__uint128_t x) {
    for (__uint128_t i = 2; i*i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        unsigned long long x;
        cin >> x;
        bool result = true;
        for (int i = 0; i < 10 && result; i++)
            result = primality_test(x);
        result ? cout << "TAK\n" : cout << "NIE\n";
        // __uint128_t asd = x;
        // asd = asd*asd%(asd-1);
    }
}

// int main() {
//     for (__uint128_t i = 100000; i < 1000000000; i++) {
//         bool result = true;
//         for (int j = 0; j < 10 && result; j++)
//             result = primality_test(i);
//         if (result != pr(i)) {
//             cout << (unsigned long long)i << " " << "CHUJJJ\n";
//             break;
//         }
//     }
    
// }