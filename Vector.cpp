//
//  Vector.cpp
//  ccgdlib
//
//  Created by Thomas Foster on 5/4/23.
//

#include "Vector.h"

void Vec2::lerp(const Vec2 &a, const Vec2 &b, float f) {
    if ( f <= 0.0f ) {
        (*this) = a;
    } else if ( f >= 1.0f ) {
        (*this) = b;
    } else {
        (*this) = a + f * (b - a);
    }
}

Vec2 Vec2::normalized() const {
    float len = length();
    return Vec2(x / len, y / len);
}

Vec2 Vec2::rotated(float degrees) const {
    float radians = Math::ToRadians(degrees);

    Vec2 result;
    result.x = cos(radians) * x - sin(radians) * y;
    result.y = sin(radians) * x + cos(radians) * y;

    return result;
}
