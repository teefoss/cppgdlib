//
//  Vector.h
//  ccgdlib
//
//  Created by Thomas Foster on 5/4/23.
//

#ifndef Vector_h
#define Vector_h

#include "Math.h"

#define VEC_EPSILON 0.001f

struct Vec2 {
    float x;
    float y;

    Vec2() { }
    Vec2(float _x, float _y) : x(_x), y(_y) { }

    void  set(float _x, float _y) { x = _x; y = _y; }
    void  zero() { x = y = 0.0f; }
    void  lerp(const Vec2& a, const Vec2& b, float f);
    float length() const { return Math::Sqrt(lengthSqr()); };
    float lengthSqr() const { return x * x + y * y; }
    Vec2  normalized() const;
    Vec2  rotated(float degrees) const;

    Vec2  operator +  (const Vec2& a) const { return Vec2(x + a.x, y + a.y); }
    Vec2  operator -  (const Vec2& a) const { return Vec2(x - a.x, y - a.y); }
    float operator *  (const Vec2& a) const { return x * a.x + y * a.y; }
    Vec2  operator *  (float s) const { return Vec2(x * s, y * s); }
    void  operator += (const Vec2& a) { x += a.x; y += a.y; }
    void  operator -= (const Vec2& a) { x -= a.x; y -= a.y; }
    void  operator *= (float a) { x *= a; y *= a; }
    bool  operator == (Vec2& a) const { return a.x == x && a.y == y; }
    bool  operator != (Vec2& a) const { return a.x != x || a.y != y; }

    friend Vec2 operator * (float a, const Vec2& b) {
        return Vec2(b.x * a, b.y * a);
    }
};

#endif /* Vector_h */
