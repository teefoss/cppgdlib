//
//  QuadTree.hpp
//  ccgdlib
//
//  Created by Thomas Foster on 5/7/23.
//

#ifndef QuadTree_h
#define QuadTree_h

#define QUAD_NODE_DATA_COUNT 4

template <typename T>
class QuadNode {
public:
    QuadNode(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) { };
    ~QuadNode();
    bool Insert(T data, int x, int y);
    void Destroy();

private:
    void Subdivide();

    T data[QUAD_NODE_DATA_COUNT];
    int dataCount = 0;

    int x;
    int y;
    int w;
    int h;

    QuadNode * topLeft = nullptr;
    QuadNode * topRight = nullptr;
    QuadNode * bottomLeft = nullptr;
    QuadNode * bottomRight = nullptr;
};

#endif /* QuadTree_h */
