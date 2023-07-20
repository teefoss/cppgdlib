//
//  Random.h
//  ccgdlib
//
//  Created by Thomas Foster on 5/5/23.
//

#ifndef Random_h
#define Random_h

#include "shorttypes.h"

// PRNG using Wyhash32.
class Random {
public:
    Random() { };
    Random(u32 seed) : state(seed) { }

    u32 Int();
    u32 Int(int min, int max);
    float Float(); // Between 0 and 1.
    float Float(float min, float max); // max inclusive.
    bool Chance(float percent);

private:
    static const int MAX = 0xFFFFFFFF;
    u32 state = 0;
};


inline u32 Random::Int(int min, int max) {
    return Int() % (max - min + 1) + min;
}

inline float Random::Float() {
    return (float)Int() / (float)(MAX + 1);
}

inline float Random::Float(float min, float max) {
    return min + (max - min) * Float();
}

inline bool Random::Chance(float percent) {
    return Float() < percent;
}

#endif /* Random_h */
