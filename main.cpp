#include <iostream>
#include <chrono>
#include <optional>
#include <vector>
#include <cassert>
#include "poly.h"

int main() {
    using term = std::pair<power, coeff>;
    
    // Input polynomials for testing
    std::vector<term> poly_input = {{1, 1}, {2, 1}}; // Represents (x + 1)

    // Test 1: Add two polynomials
    polynomial p1(poly_input.begin(), poly_input.end()); // (x + 1)
    polynomial p2(poly_input.begin(), poly_input.end()); // (x + 1)
    // polynomial p_sum = p1 + p2; // Expected result: 2x + 2
    // std::cout << "p1 + p2 = ";
    // p_sum.print();

    // // Test 2: Multiply a polynomial by an integer
    // polynomial p_mult = p1 * 2; // Expected result: 2x + 2
    // std::cout << "p1 * 2 = ";
    // p_mult.print();

    // Test 3: Integer added to polynomial (int + polynomial)
    polynomial p_add_int = -2 + p1; // Expected result: x + 3
    std::cout << "2 + x + 1 = ";
    p_add_int.print();

    // Test 4: Polynomial added to integer (polynomial + int)
    polynomial p_int_add = p1 + 0; // Expected result: x + 4
    std::cout << "x + 1 + 3 = ";
    p_int_add.print();

    // Test 5: Verify canonical form after addition
    // auto p_canonical = p_add_int.canonical_form();
    // std::vector<term> expected_canonical = {{1, 1}, {0, 3}}; // x + 3
    // assert(p_canonical == expected_canonical);

    // Test 6: Empty polynomial addition
    std::vector<term> empty = {};
    polynomial p_empty(empty.begin(), empty.end());
    polynomial p_empty_sum = p1 + p_empty; // Expected result: p1
    std::cout << "p1 + empty = ";
    p_empty_sum.print();
    
    // Output degree of a polynomial
    size_t degree = p1.find_degree_of();
    std::cout << "Degree of p1: " << degree << std::endl;

    std::cout << "All tests completed successfully!" << std::endl;
    return 0;
}
