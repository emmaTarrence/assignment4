#include <iostream>
#include <vector>
#include <cassert>
#include "poly.h"

using term = std::pair<power, coeff>;

int main() {
    // Input polynomials
    std::vector<term> poly_input1 = {{2, 1}, {1, -1}, {0, -1}}; // x^2 - x - 1
    std::vector<term> poly_input2 = {{1, 1}, {0, -1}};          // x - 1
    std::vector<term> poly_input3 = {{3, 2}, {2, 1}, {1, -1}, {0, -1}}; // 2x^3 + x^2 - x - 1
    std::vector<term> poly_input4 = {{0, 0}};                   // 0
    std::vector<term> poly_input5 = {{0, 5}};                   // 5
    std::vector<term> poly_input6 = {{1, 1}};                   // x

    // Initialize polynomials
    polynomial p1(poly_input1.begin(), poly_input1.end()); // x^2 - x - 1
    polynomial p2(poly_input2.begin(), poly_input2.end()); // x - 1
    polynomial p3(poly_input3.begin(), poly_input3.end()); // 2x^3 + x^2 - x - 1
    polynomial p4(poly_input4.begin(), poly_input4.end()); // 0
    polynomial p5(poly_input5.begin(), poly_input5.end()); // 5
    polynomial p6(poly_input6.begin(), poly_input6.end()); // x

    // Test operations
    // std::cout << "(p1 % p2) + (p5 * p6) = ";
    // polynomial result1 = (p1 % p2) + (p5 * p6);

    // result1.print();

    std::cout << "(p3 * p2) + (p1 % p6) = ";
    polynomial result2 = (p3 * p2) + (p1 % p6);
    //     (p3*p2).print();
    // (p1%p6).print();
    result2.print();

    // std::cout << "(p4 + p5) * (p6 % p2) = ";
    // polynomial result3 = (p4 + p5) * (p6 % p2);
    // result3.print();

    // std::cout << "(p1 * p2) + (p3 % p6) = ";
    // polynomial result4 = (p1 * p2) + (p3 % p6);
    // result4.print();

    // // Verify results using canonical forms
    // std::vector<term> expected_result1 = {{1, 5}, {0, -1}}; // Expected result
    // assert(result1.canonical_form() == expected_result1);

    std::vector<term> expected_result2 = {{4, 2}, {3, 3}, {2, 1}, {1, -1}}; // Expected result
    assert(result2.canonical_form() == expected_result2);

    // std::vector<term> expected_result3 = {{1, 5}, {0, -5}}; // Expected result
    // assert(result3.canonical_form() == expected_result3);

    // std::vector<term> expected_result4 = {{5, 2}, {4, 3}, {3, -2}}; // Expected result
    // assert(result4.canonical_form() == expected_result4);

    // std::cout << "All tests passed!" << std::endl;

    return 0;
}
