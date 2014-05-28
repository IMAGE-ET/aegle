#ifndef MARCHING_CUBES_H
#define MARCHING_CUBES_H
class MarchingCubes
{
public:

    MarchingCubes(void);
    MarchingCubes(const float& isovalue_);

    float getIsovalue();
    void setIsovalue(const float& isovalue);

    // Calls the marching cubes algorithm
    bool march();

    ~MarchingCubes(void);

private:
    float isovalue_;

};

#endif MARCHING_CUBES_H