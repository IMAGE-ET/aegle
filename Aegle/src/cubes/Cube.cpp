#include "Cube.h"


Cube::Cube(void)
{
    value_ = 0;
    // vertices_;
    // edges_ = ;
    // modelView_ = ;
    id_ = idCount++;
    isHidden_ = false;
}

Cube::Cube(cubeVertices vertices)
{
    value_ = 0;
    vertices_ = vertices;
    // edges_ = ;
    // modelView_ = ;
    id_ = idCount++;
    isHidden_ = false ;
}

Cube::~Cube(void)
{

}

int Cube::determineCase(const float& threshold)
{
    int num = 0;

    for(size_t i = 0; i < vertices_.size(); ++i)
    {
        // set each bit as corresponding to each vertex
        num += (vertices_[i].weight - threshold > 0) ? 1 << i : 0;
    }

    return num;
}

vector Cube::computeEdgeBetween(const vertex& v1, const vertex& v2)
{
    double weight = (value_ - v1.weight)/(v2.weight - v1.weight);

    vector retVal;
    if(weight >= 0 && weight <= 1) 
    {
        // interpolated edge is v1 plus a portion of the difference between them
        retVal[0] = v1.x + ((v2.x - v1.x) * weight);
        retVal[1] = v1.x + ((v2.y - v1.y) * weight);
        retVal[2] = v1.x + ((v2.z - v1.z) * weight);
    }

    return retVal;
}

void Cube::computeEdges()
{
    edges_[0] = computeEdgeBetween(vertices_[0], vertices_[1]);
    edges_[1] = computeEdgeBetween(vertices_[1], vertices_[2]);
    edges_[2] = computeEdgeBetween(vertices_[2], vertices_[3]);
    edges_[3] = computeEdgeBetween(vertices_[3], vertices_[0]);

    edges_[4] = computeEdgeBetween(vertices_[4], vertices_[5]);
    edges_[5] = computeEdgeBetween(vertices_[5], vertices_[6]);
    edges_[6] = computeEdgeBetween(vertices_[6], vertices_[7]);
    edges_[7] = computeEdgeBetween(vertices_[7], vertices_[4]);

    edges_[8] = computeEdgeBetween(vertices_[0], vertices_[4]);
    edges_[9] = computeEdgeBetween(vertices_[1], vertices_[5]);
    edges_[10] = computeEdgeBetween(vertices_[3], vertices_[7]);
    edges_[11] = computeEdgeBetween(vertices_[2], vertices_[6]);
}

std::string Cube::toString()
{
    std::string ret("");

    ret += "Cube #" + id_;
    ret += ": [";

    for(size_t i = 0; i < vertices_.size(); i++)
    {
        ret += "<" + std::to_string(vertices_[i].x);
        ret += "," + std::to_string(vertices_[i].y);
        ret += "," + std::to_string(vertices_[i].z);
        ret += "|" + std::to_string(vertices_[i].weight); 
        ret += ">";
    }
    return ret;
}