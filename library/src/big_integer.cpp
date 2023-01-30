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
            throw("{ERROR} You string contains not a number!");
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

bool Null(const BigInteger& bi) {
    return bi.digits.size() == 1 && bi.digits[0] == '0';
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
            temp_sum = (a.digits[i] + b.digits[i] - 2 * 48) + digit;
        } else {
            temp_sum = (a.digits[i] - 48) + digit;
        }
        digit = temp_sum / 10;
        a.digits[i] = (temp_sum % 10) + 48;
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
    
    for (int i = 0; i < size_a; ++i) {
        if (i < size_b) {
            temp_diff = (a.digits[i] - b.digits[i]) + digit;
        } else {
            temp_diff = (a.digits[i] - 48) + digit;
        }
        if (temp_diff < 0) {
            temp_diff += 10;
            digit = -1;
        } else {
            digit = 0;
        }
        a.digits[i] = temp_diff + 48;
    }

    while (size_a > 1 && a.digits[size_a - 1] == 0) {
        a.digits.pop_back();
        --size_a;
    }
    return a;
}

BigInteger operator*(const BigInteger& a, const BigInteger& b) {
    BigInteger copy(a);
    copy.minus = !(a.minus == b.minus);
    copy *= b;
    return copy;
}

BigInteger& operator*=(BigInteger& a, const BigInteger& b) {
    if (!Null(a) && !Null(b)) {
        int size_a = length(a), size_b = length(b); 
        std::vector<int> vc(size_a + size_b, 0);
        for (int i = 0; i < size_a; ++i) {
            for (int j = 0; j < size_b; ++j) {
                vc[i + j] = (a.digits[i] - 48) * (b.digits[j] - 48);
            }
        }
        size_a += size_b;
        a.digits.resize(vc.size());
        for (int temp_product, i = 0, digit = 0; i < size_a; ++i) {
            temp_product = vc[i] + digit;
            digit = temp_product / 10;
            vc[i] = temp_product % 10;
            a.digits[i] = vc[i] + 48;
        }

        for (int i = size_a - 1; i >= 1 && !vc[i]; --i) {
            a.digits.pop_back();
        }
    } else {
        a = BigInteger();
    }
    return a;
}

BigInteger operator/(const BigInteger& a, const BigInteger& b) {
    BigInteger copy(a);
    copy.minus = !(a.minus == b.minus);
    copy /= b;
    return copy;
}

BigInteger& operator/=(BigInteger& a, const BigInteger& b) {
    if (Null(b)) {
        throw std::logic_error("{ERROR}: Division by 0");
    } else if (a < b) {
        a = BigInteger();
    } else if (a == b) {
        a = BigInteger(1);
    } else {
        int i, logic_cat = 0, cc,
                size_a = length(a), size_b = length(b);
        std::vector<int> cat(size_a, 0);
        BigInteger temp;
        for (i = size_a - 1; temp * 10 + (a.digits[i] - 48) < b; --i) {
            temp *= 10;
            temp += (a.digits[i] - 48);
        }
        for (; i >= 0; --i) {
            temp = temp * 10 + (a.digits[i] - 48);
            for (cc = 9; cc * b > temp; --cc);
            temp -= cc * b;
            cat[logic_cat++] = cc;
        }
        a.digits.resize(cat.size());
        for (i = 0; i < logic_cat; ++i) {
            a.digits[i] = cat[logic_cat - i - 1] + 48;
        }
        a.digits.resize(logic_cat);
    }
    return a;
}


