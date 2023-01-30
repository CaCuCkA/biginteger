#ifndef BIG_INT_H
#define BIG_INT_H

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

    bool getMinus();

    BigInteger& operator=(const BigInteger&);

    void swap(BigInteger &other) noexcept;
    friend int length(const BigInteger& bi);
    friend bool Null(const BigInteger& bi);

    void operator-();

    BigInteger& operator++();
    BigInteger operator++(int);
    BigInteger& operator--();
    BigInteger operator--(int);

    friend BigInteger& operator+=(BigInteger&, const BigInteger&);
    friend BigInteger  operator+(const BigInteger&, const BigInteger&);
    friend BigInteger& operator-=(BigInteger&, const BigInteger&);
    friend BigInteger  operator-(const BigInteger&, const BigInteger&);

    BigInteger NthCatalan(int);
    BigInteger NthFibonacci(int);
    BigInteger Factorial(int);    

    friend BigInteger& operator*=(BigInteger&, const BigInteger&);
    friend BigInteger  operator*(const BigInteger&, const BigInteger&);
    friend BigInteger& operator/=(BigInteger&, const BigInteger&);
    friend BigInteger  operator/(const BigInteger&, const BigInteger&);

    friend BigInteger  operator%(const BigInteger&, const BigInteger&);
    friend BigInteger& operator%=(BigInteger&, const BigInteger&);

    friend BigInteger& operator^=(BigInteger&, const BigInteger&);
    friend BigInteger  operator^(const BigInteger&, const BigInteger&);

};

BigInteger sqrt(BigInteger &a);

std::ostream& operator<<(std::ostream&, const BigInteger&);
std::istream& operator>>(std::istream&, BigInteger&);

bool operator==(const BigInteger&, const BigInteger&);
bool operator!=(const BigInteger&, const BigInteger&);

bool operator>(const BigInteger&, const BigInteger&);
bool operator>=(const BigInteger&, const BigInteger&);
bool operator<(const BigInteger&, const BigInteger&);
bool operator<=(const BigInteger&, const BigInteger&);

#endif