#include <iostream>
#include <vector>
#include <cassert>
#include "poly.h"

int main() {
    using term = std::pair<power, coeff>;
    std::vector<term> poly_input1 = {{2, 1}, {1, -1}, {0, -1}}; // Represents x^2 - x - 1
    std::vector<term> poly_input2 = {{1, 1}, {0, -1}};          // Represents x - 1

    // Initialize polynomials
    polynomial p1(poly_input1.begin(), poly_input1.end()); // x^2 - x - 1
    polynomial p2(poly_input2.begin(), poly_input2.end()); // x - 1

    // Test 1: Modulus of two polynomials
    polynomial p_mod = p1 % p2; // Expected result: -1
    std::cout << "(x^2 - x - 1) % (x - 1) = ";
    p_mod.print();

    // Verify the result of p1 % p2
    std::vector<term> expected_mod = {{0, -1}}; // -1
    auto p_mod_canonical = p_mod.canonical_form();
    assert(p_mod_canonical == expected_mod);
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
