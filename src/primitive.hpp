#ifndef __PRIMITIVE_H__
#define __PRIMITIVE_H__

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>

#include "constants.hpp"
#include "run_utils.hpp"

using namespace std;

class Triangle {
    public:
//      Triangle vertex vectors.
        vector<double> vec1;
        vector<double> vec2;
        vector<double> vec3;

//      Member functions.
        void init(vector<double> ipt_vec1, vector<double> ipt_vec2, vector<double> ipt_vec3);
        void magnitudes_get(double* &magnitude_array, int which_vec = 0);
        void magnitudes_calc(void);
        void unit_vectors_get(vector<double>* &unit_vector_array, int which_vec = 0);
        void unit_vectors_calc(void);
        bool triangles_equivalent(Triangle* other);

    private:
//      Cache.
        bool have_units;
        vector<double> vec1_unit;
        vector<double> vec2_unit;
        vector<double> vec3_unit;
        bool have_magnitudes;
        double vec1_magnitude;
        double vec2_magnitude;
        double vec3_magnitude;

};

double dot_product(vector<double> vec1, vector<double> vec2);

vector<double> dscal(vector<double> vec, double scalar);

bool vectors_equivalent(vector<double> vec1, vector<double> vec2);

#endif // __PRIMITIVE_H__
