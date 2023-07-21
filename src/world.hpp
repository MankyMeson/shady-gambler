#ifndef __WORLD_H__
#define __WORLD_H__

#include <cstddef>
#include <vector>
#include <cmath>

#include "primitive.hpp"
#include "constants.hpp"

class World {
    public:
//      An arbitrary number of triangles.
        vector<Triangle> triangles;

//      An arbitrary number of camera positions.
//      PLACEHOLDER vector<Camera> cameras;

//      Member functions.
        void init(vector<Triangle> triangles);
        void push_triangle(Triangle t);
        size_t triangles_count_get(void);

    private:
//      Metadata.
        bool have_triangles_count;
        size_t triangles_count;
//      PLACEHOLDER size_t have_cameras_count;
//      PLACEHOLDER size_t cameras_count;

//      Private member functions relating to calculation of metadata etc.
        void triangles_count_calc(void);

};

#endif // __WORLD_H__
