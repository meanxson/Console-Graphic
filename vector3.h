#pragma once

#include "vector2.h"

struct vector3 {
    float x, y, z;

    vector3(float value) : x(value), y(value), z(value) {}

    vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    vector3(float x, vector2 const &uv) : x(x), y(uv.x), z(uv.y) {}

    vector3 operator+(vector3 const &other) {
        return vector3(x + other.x, y + other.y, z + other.z);
    }

    vector3 operator-(vector3 const &other) {
        return vector3(x - other.x, y - other.y, z - other.z);
    }

    vector3 operator*(vector3 const &other) {
        return vector3(x * other.x, y * other.y, z * other.z);
    }

    vector3 operator/(vector3 const &other) {
        return vector3(x / other.x, y / other.y, z / other.z);
    }

    vector3 operator-() {
        return vector3(-x, -y, -z);
    }
};