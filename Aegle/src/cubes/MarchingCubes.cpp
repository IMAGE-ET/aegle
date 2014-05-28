#include "MarchingCubes.h"

MarchingCubes::MarchingCubes(void) : isovalue_(0)
{}

MarchingCubes::MarchingCubes(const float& isovalue)
{
    isovalue_ = isovalue;
}

float MarchingCubes::getIsovalue()
{
    return isovalue_;
}

void MarchingCubes::setIsovalue(const float& isovalue)
{
    isovalue_ = isovalue;
}

bool MarchingCubes::march()
{
    bool isSuccess = true;

    return isSuccess;
}

