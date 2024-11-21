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

polynomial& polynomial::operator*(const polynomial &other) {
    std::vector<std::pair<power, coeff>>result; 

    for(const auto &[pow1, coeff1]: _terms) { 
        for(const auto &[pow2, coeff2]: other._terms){ 
            result.push_back({pow1+pow2, coeff1* coeff2});
        }
    }
  //  print_vector(result);

    sort(result) ;
    //print_vector(result);
    std::vector<std::pair<power, coeff>>combine; 
    for(size_t i = 0; i <result.size(); ++i) { 
        if(i+1 < result.size() && result[i].first == result[i+1].first) { 
            result[i+1].second += result[i].second;
        }
        else{
            combine.push_back(result[i]);
        }
    }
    //print_vector(combine);

    _terms = {};
    for (const auto &[pow, coef] : combine) {
        if (coef != 0) _terms.push_back({pow, coef});
    }
    //this->print();
    return *this;
}

polynomial& polynomial::operator+(const polynomial &other){
    std::vector<std::pair<power, coeff>>result; 
    size_t i =0, j = 0; 
    while(i< _terms.size() && j < other._terms.size()) { 
        auto [pow1, coeff1] = _terms[i];
        auto [pow2, coeff2] = other._terms[i];

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
        _terms = result;
    return *this;
}


polynomial& polynomial::operator%(const polynomial &other){
    return *this;

}

size_t polynomial::find_degree_of(){
    return 0; 
}

std::vector<std::pair<power, coeff>> polynomial::canonical_form() const {
    return {}; // Return an empty vector for now
}

