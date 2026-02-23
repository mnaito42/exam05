#include <iostream>
#include "vect2.hpp"

int main() {
    std::cout << "=== Constructors ===\n";
    vect2 a;                 // default
    vect2 b(3, 4);           // param
    vect2 c(b);              // copy ctor
    vect2 d;
    d = b;                   // copy assignment
    std::cout << a << "\n" << b << "\n" << c << "\n" << d << "\n";

    std::cout << "\n=== Arithmetic ===\n";
    vect2 v1(1, 2), v2(3, 4);
    std::cout << (v1 + v2) << "\n";
    std::cout << (v2 - v1) << "\n";

    std::cout << "\n=== Compound Assignment ===\n";
    vect2 v3(1, 1);
    vect2 v4(2, 2);
    vect2 v5(3, 3);
    v3 += v4;
    std::cout << v3 << "\n";
    v3 -= vect2(1, 1);
    std::cout << v3 << "\n";

    std::cout << "\n=== Chained += ===\n";
    vect2 x1(1,1), x2(2,2), x3(3,3);
    x1 += x2 += x3;
    std::cout << x1 << "\n" << x2 << "\n";

    std::cout << "\n=== Comparison ===\n";
    vect2 cmp1(5,5), cmp2(5,5), cmp3(1,1);
    std::cout << (cmp1 == cmp2) << "\n";
    std::cout << (cmp1 != cmp3) << "\n";

    std::cout << "\n=== Index Access ===\n";
    vect2 idx(7, 8);
    std::cout << idx[0] << ", " << idx[1] << "\n";
    idx[0] = 42;
    idx[1] = 24;
    std::cout << idx << "\n";

    std::cout << "\n=== Scalar Multiplication ===\n";
    vect2 s1(2,3);
    std::cout << (s1 * 3) << "\n";
    std::cout << (3 * s1) << "\n";
    s1 *= 2;
    std::cout << s1 << "\n";

    std::cout << "\n=== Unary Minus ===\n";
    vect2 neg(5, -6);
    std::cout << (-neg) << "\n";

    std::cout << "\n=== Increment ===\n";
    vect2 inc(1,1);
    std::cout << ++inc << "\n";
    std::cout << inc++ << "\n";
    std::cout << inc << "\n";

    std::cout << "\n=== Decrement ===\n";
    vect2 dec(5,5);
    std::cout << --dec << "\n";
    std::cout << dec-- << "\n";
    std::cout << dec << "\n";

    std::cout << "\n=== Const Index Access ===\n";
    const vect2 const_v(9, 10);
    std::cout << const_v[0] << ", " << const_v[1] << "\n";

    return 0;
}
