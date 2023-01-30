#ifndef BIG_INT_H
#define BIG_INT_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stdexcept>

class BigInteger {
private:
    std::string digits;
    bool minus;
public:
    BigInteger(long long n = 0);
    BigInteger(const std::string &);
    BigInteger(const char*);
    BigInteger(const BigInteger&);

    BigInteger& operator=(const BigInteger&);

    void swap(BigInteger &other) noexcept;
    friend int length(const BigInteger&);
    friend bool Null(const BigInteger&);
    friend void divide_by_two(BigInteger&);

    void operator-();

    BigInteger& operator++();
    BigInteger operator++(int);
    BigInteger& operator--();
    BigInteger operator--(int);

    friend BigInteger& operator+=(BigInteger&, const BigInteger&);
    friend BigInteger  operator+(const BigInteger&, const BigInteger&);
    friend BigInteger& operator-=(BigInteger&, const BigInteger&);
    friend BigInteger  operator-(const BigInteger&, const BigInteger&);

    friend BigInteger NthCatalan(int&);
    friend BigInteger NthFibonacci(int&);
    friend BigInteger Factorial(int&);    

    friend BigInteger& operator*=(BigInteger&, const BigInteger&);
    friend BigInteger  operator*(const BigInteger&, const BigInteger&);
    friend BigInteger& operator/=(BigInteger&, const BigInteger&);
    friend BigInteger  operator/(const BigInteger&, const BigInteger&);

    friend BigInteger  operator%(const BigInteger&, const BigInteger&);
    friend BigInteger& operator%=(BigInteger&, const BigInteger&);

    friend BigInteger& operator^=(BigInteger&, const BigInteger&);
    friend BigInteger  operator^(const BigInteger&, const BigInteger&);

    friend std::ostream& operator<<(std::ostream&, const BigInteger&);
    friend std::istream& operator>>(std::istream&, BigInteger&);

    friend BigInteger sqrt(BigInteger &);

    friend bool operator==(const BigInteger&, const BigInteger&);
    friend bool operator!=(const BigInteger&, const BigInteger&);

    friend bool operator>(const BigInteger&, const BigInteger&);
    friend bool operator>=(const BigInteger&, const BigInteger&);
    friend bool operator<(const BigInteger&, const BigInteger&);
    friend bool operator<=(const BigInteger&, const BigInteger&);

};

#endif