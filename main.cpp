#include <iostream>
#include <vector>
#include <cassert>
#include "poly.h"

int main() {
    using term = std::pair<power, coeff>;
    std::vector<term> poly_input1 = {{2, 1}, {1, -1}, {0, -1}}; // Represents x^2 - x - 1
    std::vector<term> poly_input3 = {{3, 2}, {2, 1}, {1, -1}, {0, -1}}; // Represents 2x^3 + x^2 - x - 1
    std::vector<term> poly_input2 = {{1, 1}, {0, -1}}; // Represents x - 1
    std::vector<term> poly_input4 = {{0, 0}}; // Represents 0
    std::vector<term> poly_input5 = {{0, 5}}; // Represents 5 (constant)
    std::vector<term> poly_input6 = {{1, 1}}; // Represents x

    // Initialize polynomials
    polynomial p1(poly_input1.begin(), poly_input1.end()); // x^2 - x - 1
    polynomial p2(poly_input2.begin(), poly_input2.end()); // x - 1
    polynomial p3(poly_input3.begin(), poly_input3.end()); // 2x^3 + x^2 - x - 1
    polynomial p4(poly_input4.begin(), poly_input4.end()); // 0
    polynomial p5(poly_input5.begin(), poly_input5.end()); // 5
    polynomial p6(poly_input6.begin(), poly_input6.end()); // x

    // Test 1: Modulus of two polynomials
    std::cout << "(x^2 - x - 1) % (x - 1) = ";
    polynomial p_mod = p1 % p2; // Expected result: -1
    p_mod.print();

    std::cout << "(2x^3 + x^2 - x - 1) % (x - 1) = ";
    polynomial p_mod1 = p3 % p2; // Expected result: -1
    p_mod1.print();

   // Edge Case 1: Zero polynomial modulus with another polynomial (Expected result: 0)
   std::cout << "0 % (x - 1) = ";
    polynomial p_mod2 = p4 % p2; // Expected result: 0
    p_mod2.print();

    // // Edge Case 2: Modulus with constant polynomial (Expected result: 5)
    // std::cout << "5 % (x - 1) = ";
    // polynomial p_mod3 = p5 % p2; // Expected result: 5 (constant)
    // p_mod3.print();

    // Edge Case 3: Dividing by polynomial of degree higher than dividend (Expected result: x - 1)
    std::cout << "(x) % (x^2 - x - 1) = ";
    polynomial p_mod4 = p6 % p1; // Expected result: x
    p_mod4.print();

    // Edge Case 4: Dividing by a root polynomial (Expected result: 0)
    std::cout << "(x - 1) % (x - 1) = ";
    polynomial p_mod5 = p2 % p2; // Expected result: 0
    p_mod5.print();

    // Verify the results
    std::vector<term> expected_mod = {{0, -1}}; // Expected result: -1
    auto p_mod_canonical = p_mod.canonical_form();
    assert(p_mod_canonical == expected_mod);

    std::vector<term> expected_mod1 = {{0, 1}}; // Expected result: -1
    auto p_mod1_canonical = p_mod1.canonical_form();
    assert(p_mod1_canonical == expected_mod1);

    std::vector<term> expected_mod2 = {{0, 0}}; // Expected result: 0
    auto p_mod2_canonical = p_mod2.canonical_form();
    assert(p_mod2_canonical == expected_mod2);

    // std::vector<term> expected_mod3 = {{0, 5}}; // Expected result: 5 (constant)
    // auto p_mod3_canonical = p_mod3.canonical_form();
    // assert(p_mod3_canonical == expected_mod3);

    std::vector<term> expected_mod4 = {{1, 1}}; // Expected result: x
    auto p_mod4_canonical = p_mod4.canonical_form();
    assert(p_mod4_canonical == expected_mod4);

    std::vector<term> expected_mod5 = {{0, 0}}; // Expected result: 0
    auto p_mod5_canonical = p_mod5.canonical_form();
    assert(p_mod5_canonical == expected_mod5);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
