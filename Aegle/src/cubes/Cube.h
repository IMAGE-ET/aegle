#pragma once

#ifndef CUBE_H
#define CUBE_H


#include "../util/Matrix4.h"
#include "Facet.h"
#include <vector>
#include <string>
#include <array>

typedef std::array<float,3> vector;

// each one of the 12 edges has a vector interpolated
typedef std::array<vector,12> edges;

// each one of the 8 vertices has a x,y,z position
typedef std::array<vertex,8> cubeVertices;

class Cube
{
public:
    Cube(void);
    Cube(cubeVertices vertices);
    ~Cube(void);
    std::string toString();

private:

    vector computeEdgeBetween(const vertex& v1, const vertex& v2);
    void computeEdges();

    int determineCase(const float& threshold);

    int value_;
    cubeVertices vertices_;
    edges edges_;
    Matrix4 modelView_;
    int id_;
    bool isHidden_;
};

static int idCount = 0;

#endif CUBE_H