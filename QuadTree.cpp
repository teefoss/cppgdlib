//
//  QuadTree.cpp
//  ccgdlib
//
//  Created by Thomas Foster on 5/7/23.
//

#include "QuadTree.h"

template <typename T>
void QuadNode<T>::Subdivide() {
    int newW = w / 2;
    int newH = h / 2;

    topLeft         = new QuadNode(x,        y,        newW, newH);
    topRight        = new QuadNode(x + newW, y,        newW, newH);
    bottomLeft      = new QuadNode(x,        y + newH, newW, newH);
    bottomRight     = new QuadNode(x + newW, y + newH, newW, newH);

    for ( int i = 0; i < dataCount; i++ ) {
        if ( topLeft->Insert(data[i], GetX(data[i]), GetY(data[i])) )
            continue;

        if ( topRight->Insert(data[i], GetX(data[i]), GetY(data[i])) )
            continue;

        if ( bottomLeft->Insert(data[i], GetX(data[i]), GetY(data[i])) )
            continue;

        if ( bottomRight->Insert(data[i], GetX(data[i]), GetY(data[i])) )
            continue;
    }

    dataCount = 0;
}

template <typename T>
bool QuadNode<T>::Insert(T _data, int _x, int _y) {

    if ( _x < x || _x >= x + w || _y < y || _y >= y + h ) return false;

    if ( dataCount < QUAD_NODE_DATA_COUNT && topLeft == nullptr ) {
        data[dataCount++] = _data;
        return true;
    }

    if ( topLeft == nullptr ) Subdivide();

    if ( topLeft->Insert(_data, _x, _y) ) return true;
    if ( topRight->Insert(_data, _x, _y) ) return true;
    if ( bottomLeft->Insert(_data, _x, _y) ) return true;
    if ( bottomRight->Insert(_data, _x, _y) ) return true;
}

template <typename T>
void QuadNode<T>::Destroy() {
    if ( topLeft ) delete topLeft;
    if ( topRight ) delete topRight;
    if ( bottomLeft ) delete bottomLeft;
    if ( bottomRight ) delete bottomRight;
}
