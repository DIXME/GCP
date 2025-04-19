#ifndef VECTORS_H
#define VECTORS_H

#include <iostream>
#include <string>
#include <sstream>

template <typename T, int N>
class Vec {
public:
    T data[N];

    Vec() {
        for (int i = 0; i < N; ++i) data[i] = T();
    }

    Vec(std::initializer_list<T> list) {
        int i = 0;
        for (auto& val : list) {
            if (i < N) data[i++] = val;
        }
    }

    T& operator[](int index) { return data[index]; }
    const T& operator[](int index) const { return data[index]; }

    Vec operator+(const Vec& other) const {
        Vec result;
        for (int i = 0; i < N; ++i) result[i] = data[i] + other[i];
        return result;
    }

    Vec operator-(const Vec& other) const {
        Vec result;
        for (int i = 0; i < N; ++i) result[i] = data[i] - other[i];
        return result;
    }

    Vec operator*(const T& scalar) const {
        Vec result;
        for (int i = 0; i < N; ++i) result[i] = data[i] * scalar;
        return result;
    }

    Vec operator/(const T& scalar) const {
        Vec result;
        for (int i = 0; i < N; ++i) result[i] = data[i] / scalar;
        return result;
    }

    Vec& operator+=(const Vec& other) {
        for (int i = 0; i < N; ++i) data[i] += other[i];
        return *this;
    }

    Vec& operator-=(const Vec& other) {
        for (int i = 0; i < N; ++i) data[i] -= other[i];
        return *this;
    }

    Vec& operator*=(const T& scalar) {
        for (int i = 0; i < N; ++i) data[i] *= scalar;
        return *this;
    }

    Vec& operator/=(const T& scalar) {
        for (int i = 0; i < N; ++i) data[i] /= scalar;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec& vec) {
        os << "(";
        for (int i = 0; i < N; ++i) {
            os << vec[i];
            if (i < N - 1) os << ", ";
        }
        os << ")";
        return os;
    }

    friend std::string operator+(const std::string& str, const Vec& vec) {
        std::ostringstream oss;
        oss << str << vec;
        return oss.str();
    }
};

using Vec2 = Vec<float, 2>;
using Vec3 = Vec<float, 3>;
using Vec4 = Vec<float, 4>;

#endif // VECTORS_H