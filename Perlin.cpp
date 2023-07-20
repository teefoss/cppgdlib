//
//  Perlin.cpp
//  ccgdlib
//
//  Created by Thomas Foster on 5/5/23.
//

#include "Perlin.h"

double Perlin::noise(double x, double y, double z,
                     double frequency,
                     int octaves,
                     double amplitude,
                     double persistence,
                     double lacunarity) {
    double total = 0.0;

    for ( int i = 0; i < octaves; i++ ) {
        total += _noise(x * frequency, y * frequency, z * frequency) * amplitude;
        amplitude *= persistence;
        frequency *= lacunarity;
    }

    return total;
}

double Perlin::_noise(double x, double y, double z) {
    int X = (int)floor(x) & 255;                    // FIND UNIT CUBE THAT
    int Y = (int)floor(y) & 255;                    // CONTAINS POINT.
    int Z = (int)floor(z) & 255;

    x -= floor(x);                                  // FIND RELATIVE X,Y,Z
    y -= floor(y);                                  // OF POINT IN CUBE.
    z -= floor(z);

    double u = fade(x);                             // COMPUTE FADE CURVES
    double v = fade(y);                             // FOR EACH OF X,Y,Z.
    double w = fade(z);

    int A = p[X  ]+Y, AA = p[A]+Z, AB = p[A+1]+Z;   // HASH COORDINATES OF
    int B = p[X+1]+Y, BA = p[B]+Z, BB = p[B+1]+Z;   // THE 8 CUBE CORNERS,

    return lerp(w, lerp(v, lerp(u, grad(p[AA  ], x  , y  , z   ),  // AND ADD
                                   grad(p[BA  ], x-1, y  , z   )), // BLENDED
                           lerp(u, grad(p[AB  ], x  , y-1, z   ),  // RESULTS
                                   grad(p[BB  ], x-1, y-1, z   ))),// FROM  8
                   lerp(v, lerp(u, grad(p[AA+1], x  , y  , z-1 ),  // CORNERS
                                   grad(p[BA+1], x-1, y  , z-1 )), // OF CUBE
                           lerp(u, grad(p[AB+1], x  , y-1, z-1 ),
                                   grad(p[BB+1], x-1, y-1, z-1 ))));
}

double Perlin::fade(double t) {
    return t * t * t * (t * (t * 6 - 15) + 10);
}

double Perlin::lerp(double t, double a, double b) {
    return a + t * (b - a);
}

double Perlin::grad(int hash, double x, double y, double z) {
    int h = hash & 15;                      // CONVERT LO 4 BITS OF HASH CODE
    double u = h<8 ? x : y,                 // INTO 12 GRADIENT DIRECTIONS.
    v = h<4 ? y : h==12||h==14 ? x : z;
    return ((h&1) == 0 ? u : -u) + ((h&2) == 0 ? v : -v);
}
