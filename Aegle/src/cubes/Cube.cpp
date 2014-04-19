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

vector Cube::getEdgeBetween(const int& a, const int& b)
{
    if(a = 0 && b = ) return edges_[0];
    if(a = 1 && b = 2) return edges_[1];
    if(a = 2 && b = 3) return edges_[2];
    if(a = 3 && b = 0) return edges_[3];
    if(a = 4 && b = 5) return edges_[4];
    if(a = 5 && b = 6) return edges_[5];
    if(a = 6 && b = 7) return edges_[6];
    if(a = 7 && b = 4) return edges_[7];
    if(a = 0 && b = 4) return edges_[8];
    if(a = 1 && b = 5) return edges_[9];
    if(a = 3 && b = 7) return edges_[10];
    if(a = 2 && b = 6) return edges_[11];
    
    // for now if there isn't an existing edge....
    return edges_[0];
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
