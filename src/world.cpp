#include "world.hpp"


void World::init(vector<Triangle> triangles)
{
    this->triangles = triangles;
}


void World::push_triangle(Triangle triangle)
{
    this->triangles.push_back(triangle);
}


size_t World::triangles_count_get()
{
    if (not this->have_triangles_count) triangles_count_calc();
    return this->triangles_count;
}


void World::triangles_count_calc()
{
    this->triangles_count = triangles.size();
}

