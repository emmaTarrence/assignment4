#include <iostream>
#include <chrono>
#include <optional>
#include <vector>
#include <cassert>
#include "poly.h"

// Test function for polynomial addition
std::optional<double> poly_test_addition(polynomial& p1,
                                         polynomial& p2,
                                         std::vector<std::pair<power, coeff>> expected_solution)
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    // Perform polynomial addition
    polynomial p3 = p1 + p2;
    printf("Addition Result: ");
    p3.print();

    // Get canonical form of the result
    auto p3_can_form = p3.canonical_form();

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // Compare the result with the expected solution
    if (p3_can_form != expected_solution)
    {
        return std::nullopt;  // If the result doesn't match, return null
    }

    // Return time taken in milliseconds
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}

int main()
{
    /** Edge Case 1: Zero Polynomial Addition */
    std::vector<std::pair<power, coeff>> zero_poly = {{0, 0}};
    std::vector<std::pair<power, coeff>> poly_input = {{1, 1}, {0, 1}}; // (x+1)

    polynomial p1(poly_input.begin(), poly_input.end());
    polynomial zero(zero_poly.begin(), zero_poly.end());
    printf("Zero Polynomial Addition: ");
    std::vector<std::pair<power, coeff>> expected1 = {{1, 1}, {0, 1}}; // (x+1)
    auto result1 = poly_test_addition(p1, zero, expected1);
    if (result1.has_value())
    {
        std::cout << "Passed zero polynomial test, took " << result1.value() / 1000 << " seconds" << std::endl;
    }
    else
    {
        std::cout << "Failed zero polynomial test" << std::endl;
    }

    /** Edge Case 2: Negative Coefficients */
    std::vector<std::pair<power, coeff>> poly_negative = {{1, -1}, {0, 2}}; // (-x + 2)
    std::vector<std::pair<power, coeff>> expected2 = {{0, 3}}; // (x + 3)
    polynomial p2(poly_input.begin(), poly_input.end());
    polynomial p3(poly_negative.begin(), poly_negative.end());
    printf("Negative Coefficients Addition: ");
    auto result2 = poly_test_addition(p2, p3, expected2);
    if (result2.has_value())
    {
        std::cout << "Passed negative coefficients test, took " << result2.value() / 1000 << " seconds" << std::endl;
    }
    else
    {
        std::cout << "Failed negative coefficients test" << std::endl;
    }

    /** Edge Case 3: Polynomials with Different Degrees */
    std::vector<std::pair<power, coeff>> poly_deg1 = {{2, 1}, {0, 1}}; // (x^2 + 1)
    std::vector<std::pair<power, coeff>> poly_deg2 = {{1, 1}, {0, 1}}; // (x + 1)
    std::vector<std::pair<power, coeff>> expected3 = {{2, 1}, {1, 1}, {0, 2}}; // (x^2 + x + 2)
    polynomial p4(poly_deg1.begin(), poly_deg1.end());
    polynomial p5(poly_deg2.begin(), poly_deg2.end());
    printf("Different Degree Polynomials Addition: ");
    auto result3 = poly_test_addition(p4, p5, expected3);
    if (result3.has_value())
    {
        std::cout << "Passed different degree polynomials test, took " << result3.value() / 1000 << " seconds" << std::endl;
    }
    else
    {
        std::cout << "Failed different degree polynomials test" << std::endl;
    }

    /** Edge Case 4: Identical Polynomials */
    std::vector<std::pair<power, coeff>> expected4 = {{1, 2}, {0, 2}}; // (2x + 2)
    polynomial p6(poly_input.begin(), poly_input.end());
    printf("Identical Polynomials Addition: ");
    auto result4 = poly_test_addition(p6, p6, expected4);
    if (result4.has_value())
    {
        std::cout << "Passed identical polynomials test, took " << result4.value() / 1000 << " seconds" << std::endl;
    }
    else
    {
        std::cout << "Failed identical polynomials test" << std::endl;
    }

    /** Edge Case 5: Empty Polynomial Addition */
    std::vector<std::pair<power, coeff>> empty_poly = {};
    polynomial p7(empty_poly.begin(), empty_poly.end());
    std::vector<std::pair<power, coeff>> expected5 = {{1, 1}, {0, 1}}; // (x+1)
    printf("Empty Polynomial Addition: ");
    auto result5 = poly_test_addition(p7, p1, expected5);
    if (result5.has_value())
    {
        std::cout << "Passed empty polynomial test, took " << result5.value() / 1000 << " seconds" << std::endl;
    }
    else
    {
        std::cout << "Failed empty polynomial test" << std::endl;
    }

    /** Edge Case 6: Adding Zero to Polynomial */
    std::vector<std::pair<power, coeff>> zero_poly2 = {{0, 0}}; // Zero polynomial
    polynomial p8(zero_poly2.begin(), zero_poly2.end());
    std::vector<std::pair<power, coeff>> expected6 = {{1, 1}, {0, 1}}; // (x+1)
    printf("Adding Zero to Polynomial: ");
    auto result6 = poly_test_addition(p8, p1, expected6);
    if (result6.has_value())
    {
        std::cout << "Passed adding zero polynomial test, took " << result6.value() / 1000 << " seconds" << std::endl;
    }
    else
    {
        std::cout << "Failed adding zero polynomial test" << std::endl;
    }

    return 0;
}
