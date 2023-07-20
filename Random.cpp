//
//  Random.cpp
//  ccgdlib
//
//  Created by Thomas Foster on 5/5/23.
//

#include "Random.h"

u32 Random::Int()
{
    state += 0xE120FC15;
    u64 tmp = (u64)state * 0x4A39B70D;
    u32 m1 = (u32)(( tmp >> 32) ^ tmp );
    tmp = (u64)m1 * 0x12FAD5C9;
    u32 m2 = (u32)( (tmp >> 32) ^ tmp );

    return m2;
}
