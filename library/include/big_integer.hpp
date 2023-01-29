#ifndef BIG_INT_H
#define BIG_INT_H

#include <string>

class BigInteger {
private:
    std::string digits;
public:
    BigInteger(unsigned long long);
    explicit BigInteger(std::string &);
    explicit BigInteger(const char*);
    explicit BigInteger(BigInteger&);

    BigInteger& operator=(const BigInteger&);

    BigInteger& operator++();
    BigInteger operator++(int);
    BigInteger& operator--();
    BigInteger operator--(int);

    BigInteger NthCatalan(int);
    BigInteger NthFibonacci(int);
    BigInteger Factorial(int);    

};

BigInteger& operator+=(BigInteger&, const BigInteger&);
BigInteger  operator+(const BigInteger&, const BigInteger&);
BigInteger& operator-=(BigInteger&, const BigInteger&);
BigInteger  operator-(const BigInteger&, const BigInteger&);

BigInteger& operator*=(BigInteger&, const BigInteger&);
BigInteger  operator*(const BigInteger&, const BigInteger&);
BigInteger& operator/=(BigInteger&, const BigInteger&);
BigInteger  operator/(const BigInteger&, const BigInteger&);

BigInteger  operator%(const BigInteger&, const BigInteger&);
BigInteger& operator%=(BigInteger&, const BigInteger&);

BigInteger& operator^=(BigInteger&, const BigInteger&);
BigInteger  operator^(const BigInteger&, const BigInteger&);

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