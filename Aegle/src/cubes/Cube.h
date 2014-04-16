/* @file Cube.h
 * 
 *  Header file for the cube encapsulation meant for the marching cubes algorithm
 */

#ifndef CUBE_H
#define CUBE_H

#include "../util/Matrix4.h"
#include "Facet.h"
#include <vector>
#include <string>
#include <array>

// vector of size 3
typedef std::array<float,3> vector;

// each one of the 12 edges has a vector interpolated
typedef std::array<vector,12> edges;

// each one of the 8 vertices has a x,y,z position
typedef std::array<vertex,8> cubeVertices;

class Cube
{
public:
    // Constructors
    Cube(void);
    Cube(cubeVertices vertices);

    // Destructors
    ~Cube(void);

    /* @Desc Return a string that has the cube's indices and the vertex locations
     * @Returns the string form of this cube.
     */
    std::string toString();

private:

    /* @Desc Given two vertices, compute the point on the edge
     *          whose weight equals the specified value
     * @Params v1, v2 - two vertices of the edge 
     * @Returns a vector of size 3
     */
    vector computeEdgeBetween(const vertex& v1, const vertex& v2);

    /* @Desc For all 12 edges, compute the edges
     */
    void computeEdges();

    /* @Desc Given a threshold, calculate the 8 bit integer
     *         where each bit represents a vertex and it is
     *         set when comparing the vertex to a thershold
     * @Params threshold - the threshold value to use to compute case
     * @Returns the case number for this cube
     */
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
