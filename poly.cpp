#include "poly.h"
#include <iostream> 
#include <vector>

polynomial::polynomial(){

}

polynomial::polynomial(const polynomial &other) {
    this->_terms = other._terms;
}

void polynomial::print()const{
    if(_terms.empty()) { 
         std::cout << "0" << std::endl;
        return; 
    }
     bool first = true;
    for (const auto &[pow, coef] : _terms) {
        if (coef == 0) continue; // Skip zero coefficients

        // Handle formatting for signs
        if (!first && coef > 0) std::cout << " + ";
        else if (coef < 0) std::cout << " - ";

        // Print absolute value of coefficient if necessary
        if (std::abs(coef) != 1 || pow == 0) 
            std::cout << std::abs(coef);

        // Print the power term
        if (pow > 0) {
            std::cout << "x";
            if (pow > 1) std::cout << "^" << pow;
        }

        first = false;
    }

    std::cout << std::endl;
}

void sort(std::vector<std::pair<size_t,int>>&terms){
    size_t n = terms.size();
    for(size_t i = 0 ; i < n -1; i++) { 
        for(size_t j = 0; j < n -i-1; ++j) { 
            if(terms[j].first < terms[j+1].first) { 
                std::swap(terms[j], terms[j+1]);
            }
        }
    }
}



void print_vector(const std::vector<std::pair<size_t, int>>& terms) {
    for (const auto& [power, coefficient] : terms) {
        std::cout << "(" << power << ", " << coefficient << ") ";
    }
    std::cout << std::endl;
}

polynomial& polynomial::operator=(const polynomial &other){
    if(this != &other) { 
        this->_terms = other._terms;
    }
    return *this;
}

polynomial polynomial::operator*(const int num)const{
    polynomial result = *this;
    for(auto &[pow1, coeff1]: result._terms) { 
            coeff1*=num;
        }
    return result;
}

    polynomial operator*(int num , const polynomial &poly){
        return (poly*num);
    }

polynomial polynomial::operator*(const polynomial &other)const {
    std::vector<std::pair<size_t, int>>result; 

    for(const auto &[pow1, coeff1]: _terms) { 
        for(const auto &[pow2, coeff2]: other._terms){ 
            result.push_back({pow1+pow2, coeff1* coeff2});
        }
    }
    sort(result) ;
    std::vector<std::pair<power, coeff>>combine; 
    for(size_t i = 0; i <result.size(); ++i) { 
        if(i+1 < result.size() && result[i].first == result[i+1].first) { 
            result[i+1].second += result[i].second;
        }
        else{
            combine.push_back(result[i]);
        }
    }
    polynomial product;
    for (const auto &[pow, coef] : combine) {
        if (coef != 0) product._terms.push_back({pow, coef});
    }
    return product;
}

polynomial polynomial::operator+(const polynomial &other)const{
    std::vector<std::pair<size_t, int>>result; 
    
    size_t i =0, j = 0; 
    while(i< _terms.size() && j < other._terms.size()) { 
        auto [pow1, coeff1] = _terms[i];
        auto [pow2, coeff2] = other._terms[j];
        if(pow1== pow2) { 
            result.push_back({pow1, coeff1 + coeff2});
            i++;
            j++; 
        }
        else if(pow1< pow2) { 
            result.push_back({pow1, coeff1});
            i++;
        }
        else{
            result.push_back({pow2, coeff2});
            j++;
        }
        }
        while(i< _terms.size()){
            result.push_back(_terms[i]);
            i++;
        }
        while(j< other._terms.size()){
            result.push_back(other._terms[j]);
            j++;
        }
        sort(result);
std::vector<std::pair<power, coeff>> combine; 
for (size_t i = 0; i < result.size(); ++i) {
    if (i + 1 < result.size() && result[i].first == result[i + 1].first) {
        result[i + 1].second += result[i].second;
    } else {
        combine.push_back(result[i]);
    }
}
        polynomial sum;
         for (const auto &[pow, coef] : result) {
        if (coef != 0) sum._terms.push_back({pow, coef});
    }
        sum._terms = combine;
    return sum;
}
polynomial polynomial::operator+(const int num)const{
    bool inwhile = 0;
    polynomial result = *this;
    for(auto &[pow1, coeff1]: result._terms) { 
        if(pow1 ==0) { 
            inwhile = 1;
            coeff1+=num;
        }
    }
    if(!inwhile) { 
        result._terms.push_back({0, num});
    }
    return result;
}

    polynomial operator+(int num , const polynomial &poly){
        return (poly + num);
    }

// polynomial polynomial::operator%(const polynomial &other){
 //   std::cout << "in" << std::endl;
    // other.print();
// if (this->canonical_form() == std::vector<std::pair<size_t, int>>{{0, 0}}) {
//     polynomial zero;
//     return zero;
// }

// if(other > *this) { 
//     return *this;
// }

//     std::vector<std::pair<size_t, int>> result;
    
//     polynomial in1 = *this; 
//     polynomial in2 = other;
//     // other.print();
//     // in2.print();
//     std::vector<std::pair<power, coeff>> can1 = this->canonical_form();
//     // std::cout << can1 << std::endl;
//     std::vector<std::pair<power, coeff>> can2 = other.canonical_form();
//     print_vector(can2);

//     sort(can1);
//     sort(can2);

//     auto [pow1, coeff1] = can1.front(); 
//     auto [pow2, coeff2] = can2.front(); 
//     if(pow1 < pow2) { 
//        // std::cout << pow1 << "," << pow2 << std::endl;
//         return *this;
//     }
//     if(coeff2 != 0) { 
//         size_t result_pow = pow1-pow2;
//         int result_coeff = coeff1/coeff2; 
//         result.push_back({result_pow, result_coeff});
//     }

//     polynomial mult;
//         for (const auto &[pow, coef] : result) {
//         if (coef != 0) mult._terms.push_back({pow, coef});
//     }
// //    in1.print();
// //     printf("mult: ");
// //     mult.print();
// //     printf( "\n");
//     polynomial sub = mult * other;
//     sub = sub * -1; 
//     // printf("sub: ");
//     // sub.print();
//     // printf( "\n");
//     // printf("in 1: ");
//     // in1.print();
//     // printf("out: ");
//     polynomial out = in1 + sub;
//     // out.print();
//     std::vector<std::pair<power, coeff>> outVec = out.canonical_form();
//     auto [powOut, coeffOut] = outVec.front(); 
//     // printf("powOut : %ld\n", powOut);
//     // printf("pow2 : %ld\n", pow2);

//     // printf("coeffOut : %d\n", coeffOut);
//     // printf("coeff2 : %d\n", coeff2);
//     polynomial trial = out + (-1 *in2); 
//     std::vector<std::pair<power, coeff>> trial1 = trial.canonical_form();
//   // auto [powTrial, coeffTrial] = trial1.front(); 
//     // out.print();
//     // printf("-");
//     // in2.print();
//     // printf("=");
//     // trial.print(); 
    

//     if((powOut >= pow2)){ 
//      //   out.print();
//         // printf("in if");
//         return out % in2;
//     }
//    // out.print();
//     return out;
// }
polynomial polynomial::operator%(const polynomial &other) {
    if (other._terms.empty() || (other._terms.size() == 1 && other._terms[0].second == 0)) {
        return *this;
    }

    polynomial dividend = *this;
    std::vector<std::pair<power, coeff>> dividend_terms = dividend.canonical_form();

    polynomial divisor = other;
    std::vector<std::pair<power, coeff>> divisor_terms = divisor.canonical_form();

    polynomial remainder;

    while (!dividend_terms.empty() &&
           dividend_terms.front().first >= divisor_terms.front().first) {
        power diff_power = dividend_terms.front().first - divisor_terms.front().first;
        coeff scale_coeff = dividend_terms.front().second / divisor_terms.front().second;

std::vector<std::pair<power, coeff>> term_vec = {{diff_power, scale_coeff}};
polynomial term_to_subtract(term_vec.begin(), term_vec.end());


        polynomial scaled_divisor = divisor * scale_coeff;
        for (auto &t : scaled_divisor._terms) {
            t.first += diff_power;
        }

        dividend = dividend + (scaled_divisor * -1);
        dividend_terms = dividend.canonical_form(); 
    }

    remainder = dividend;
    return remainder;
}


size_t polynomial::find_degree_of(){
    sort(_terms);
    for (const auto& [pow, coeff] : _terms) {
        if (coeff != 0) {
            return pow;
        }
    }
    return 0;
}

std::vector<std::pair<power, coeff>> polynomial::canonical_form() const {
  std::vector<std::pair<power, coeff>> result;

        for (const auto& term : _terms) {
            if (term.second != 0) {
                result.push_back(term);
        }
        }
        if (result.empty()) {
            return {{0, 0}};
        }

        sort(result);

        return result; 
    }

