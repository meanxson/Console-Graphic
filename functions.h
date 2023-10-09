#pragma once
#include <cmath>
#include "vector2.h"
#include "vector3.h"

float clamp(float value, float min, float max){
	return fmax(fmin(value, max), min);
}

float length(vector2 const& v) { return sqrt(v.x * v.x + v.y * v.y); }

float length(vector3 const& v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }

float dot(vector3 const& a, vector3 const& b){
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vector3 normalize(vector3 v){
    return v / length(v);
}

vector2 sphereRaycast(vector3 ro, vector3 rd, float r) {
    float b = dot(ro, rd);
    float c = dot(ro, ro) - r * r;
    float h = b * b - c;
    if (h < 0.0) return vector2(-1.0);
    h = sqrt(h);
    return vector2(-b - h, -b + h);
}