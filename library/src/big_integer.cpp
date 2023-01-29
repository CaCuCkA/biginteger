// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "../include/big_integer.hpp"

BigInteger::BigInteger(long long n) {
    if (n < 0) minus = true;
    do {
        digits.push_back(n % 10);
        n /= 10;
    } while (n);
}

BigInteger::BigInteger(const char* c_str) {
    digits = "";
    int n = std::strlen(c_str);

    if(c_str[0] == '-') minus = true;

    for (int i = n - 1; i >= 0; --i) {
        if (!isdigit(c_str[i]) && c_str[i] != '-')
            throw("{ERROR} You string contains not a number!\n");
        digits.push_back(c_str[i] - '0');
    }
}

BigInteger::BigInteger(const std::string& str) : BigInteger(str.c_str()) {}

BigInteger::BigInteger(const BigInteger& bi)
    : digits(bi.digits), minus(bi.minus) {}

BigInteger& BigInteger::operator=(const BigInteger& bi) {
    digits = bi.digits;
    minus = bi.minus;
    return *this;
}

void BigInteger::swap(BigInteger &other) noexcept {
    digits.swap(other.digits);
    std::swap(minus, other.minus);
}

int length(const BigInteger& bi) {
    return bi.digits.size();
}

void BigInteger::operator-() {
    minus = !minus;
}

BigInteger& BigInteger::operator++() {
    return *this += 1;
}

BigInteger BigInteger::operator++(int) {
    BigInteger copy;
    copy = *this;
    ++*this;
    return copy;
}

BigInteger& BigInteger::operator--() {
    return *this -= 1;
}

BigInteger BigInteger::operator--(int) {
    BigInteger copy;
    copy = *this;
    --*this;
    return copy;
}

BigInteger operator+(const BigInteger& a, const BigInteger& b) {
    BigInteger copy(a);
    if (a.minus == b.minus) {
        copy += b;
    } else {
        if (a > b) {
            copy -= b;
        } else {
            copy = b;
            copy -= a;
        }
    }
    
    return copy;
}

BigInteger& operator+=(BigInteger& a, const BigInteger& b) {
    int temp_sum = 0, digit = 0,
            size_a = length(a), size_b = length(b);
    
    if (size_a < size_b){
        a.digits.append(size_b - size_a, '0');
        size_a = size_b;
    }

    for (int i = 0; i < size_a; ++i) {
        if (i < size_b) {
            temp_sum = (a.digits[i] + b.digits[i]) + digit;
        } else {
            temp_sum = a.digits[i] + digit;
        }
        digit = temp_sum / 10;
        a.digits[i] = (temp_sum % 10);
    }

    if (digit) a.digits.push_back(digit);

    return a;
}

BigInteger operator-(const BigInteger& a, const BigInteger& b) {
    BigInteger copy(a);
    if (a.minus || b.minus) {
        copy += b;
    } else {
        if (a > b) {
            copy -= b;
        } else {
            copy = b;
            copy -= a;
        }
    } 
    return copy;
}

BigInteger& operator-=(BigInteger& a, const BigInteger& b) {
    int digit = 0, temp_diff = 0,
            size_a = length(a), size_b = length(b);
    
    for (int i = 0; i < size_a; --i) {
        if (i < size_b) {
            temp_diff = (a.digits[i] - b.digits[i]) + t;
        } else {
            temp_diff = a.digits[i] + t;
        }

        if (temp_diff < 0) {
            temp_diff += 10;
            t = -1;
        } else {
            t = 0;
        }
        a.digits[i] = temp_diff;
    }

    while (n > 1 && a.digits[n - 1] == 0) {
        a.digits.pop_back();
        --n;
    }
    return a;
}

