//
//  Math.h
//  ccgdlib
//
//  Created by Thomas Foster on 5/4/23.
//

#ifndef Math_h
#define Math_h

#include <math.h>

namespace Math {

constexpr float PI          = 3.14159265358979323846f;
constexpr float TWO_PI      = PI * 2.0f;
constexpr float HALF_PI     = PI * 0.5f;

template <typename T>
inline T Max(const T& a, const T& b) {
    return (a < b ? b : a);
}

template <typename T>
inline T Min(const T& a, const T& b) {
    return (a < b ? a : b);
}

inline float ToRadians(float degrees) {
    return degrees * PI / 180.0f;
}

inline float ToDegrees(float radians) {
    return radians * 180.0f / PI;
}

template <typename T>
inline T Clamp(const T& value, const T& lower, const T& upper) {
    return Min(upper, Max(lower, value));
}

inline float Lerp(float a, float b, float f) {
    return a + f * (b - a);
}

template <typename T>
inline int Sign(T n) {
    return (n < 0) ? -1 : ((n > 0) ? 1 : 0);
}

// Library function replacements

inline float    Abs(float x)    { return fabsf(x);  }
inline int      Abs(int x)      { return abs(x);    }
inline float    Sqrt(float x)   { return sqrtf(x);  }
inline float    Cos(float x)    { return cosf(x);   }
inline float    Tan(float x)    { return tanf(x);   }

// TODO: other library functions



} // namespace Math

#endif /* Math_h */
