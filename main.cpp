#include <iostream>
#include <chrono>
#include <optional>
#include <vector>

#include "poly.h"

std::optional<double> poly_test(polynomial& p1,
                                polynomial& p2,
                                std::vector<std::pair<power, coeff>> solution)

{
    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    polynomial p3 = p1 * p2;
    printf("3: ");
    p3.print();

    auto p3_can_form = p3.canonical_form();

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    if (p3_can_form != solution)
    {
        return std::nullopt;
    }

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}

int main()
{
    /** We're doing (x+1)^2, so solution is x^2 + 2x + 1*/
    std::vector<std::pair<power, coeff>> solution = {{2,1}, {1,2}, {0,1}};
    /** This holds (x+1), which we'll pass to each polynomial */
    std::vector<std::pair<power, coeff>> poly_input = {{1,1}, {0,1}};

    polynomial p1(poly_input.begin(), poly_input.end());
    polynomial p2(poly_input.begin(), poly_input.end());
    printf("1: ");
    p1.print();
    printf("2: ");
    p2.print();
    printf("3: ");
    polynomial p3 = p1 * p2;
    p3.print();


    polynomial p5(poly_input.begin(), poly_input.end());
    polynomial p6(poly_input.begin(), poly_input.end());
    printf("4: ");
    polynomial p4 = p5 + p6;
    p4.print();

    polynomial in1(poly_input.begin(), poly_input.end());

    polynomial out1 = in1 * 2;
    out1.print();

    polynomial in2(poly_input.begin(), poly_input.end());
    polynomial out2 = 2 * in2;
    out2.print();


   polynomial in3(poly_input.begin(), poly_input.end());
   polynomial out3 = 2 + in3;
   polynomial in4(poly_input.begin(), poly_input.end());
   polynomial out4 = in4 + 3;
    out3.print();
    out4.print();


    // std::optional<double> result = poly_test(p1, p2, solution);

    //  if (result.has_value())
    //  {
    //      std::cout << "Passed test, took " << result.value()/1000 << " seconds" << std::endl;
    //  } 
    //  else 
    //  {
    //      std::cout << "Failed test" << std::endl;
    //  }
}