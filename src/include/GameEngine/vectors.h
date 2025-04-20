#ifndef VECTORS_H
#define VECTORS_H

#include <iostream>
#include <string>
#include <sstream>

struct Vec2 {
    float x;
    float y;

    Vec2(float x, float y) : x(x), y(y) {
        //
    }

    Vec2 operator+(const Vec2& b) const { 
        return Vec2(x + b.x, y + b.y);
    }

    Vec2 operator-(const Vec2& b) const { 
        return Vec2(x - b.x, y - b.y);
    }

    Vec2 operator/(const Vec2& b) const { 
        return Vec2(x / b.x, y / b.y);
    }

    Vec2 operator*(const Vec2& b) const { 
        return Vec2(x * b.x, y * b.y);
    }

    Vec2 operator+=(const Vec2& b) const { 
        return Vec2(x + b.x, y + b.y);
    }

    Vec2 operator-=(const Vec2& b) const { 
        return Vec2(x - b.x, y - b.y);
    }

    Vec2 operator/=(const Vec2& b) const { 
        return Vec2(x / b.x, y / b.y);
    }

    Vec2 operator*=(const Vec2& b) const { 
        return Vec2(x * b.x, y * b.y);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec2& b) {
        os << '(' << b.x << ',' << b.y << ')';
        return os;
    }
};

struct Vec3 {
    float x;
    float y;
    float z;

    Vec3(float x, float y, float z) : x(x), y(y), z(z) {
        //
    }

    Vec3 operator+(const Vec3& b) const { 
        return Vec3(x + b.x, y + b.y, z + b.z);
    }

    Vec3 operator-(const Vec3& b) const { 
        return Vec3(x - b.x, y - b.y, z - b.z);
    }

    Vec3 operator/(const Vec3& b) const { 
        return Vec3(x / b.x, y / b.y, z / b.z);
    }

    Vec3 operator*(const Vec3& b) const { 
        return Vec3(x * b.x, y * b.y, z * b.z);
    }

    Vec3 operator+=(const Vec3& b) const { 
        return Vec3(x + b.x, y + b.y, z + b.z);
    }

    Vec3 operator-=(const Vec3& b) const { 
        return Vec3(x - b.x, y - b.y, z - b.z);
    }

    Vec3 operator/=(const Vec3& b) const { 
        return Vec3(x / b.x, y / b.y, z / b.z);
    }

    Vec3 operator*=(const Vec3& b) const { 
        return Vec3(x * b.x, y * b.y, z * b.z);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec3& b) {
        os << '(' << b.x << ',' << b.y << ',' << b.z << ')';
        return os;
    }
};

#endif // VECTORS_H