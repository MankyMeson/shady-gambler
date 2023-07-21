#include "primitive.hpp"

// Triangle member functions


void Triangle::init(vector<double> ipt_vec1, vector<double> ipt_vec2, vector<double> ipt_vec3)
{
    this->vec1 = ipt_vec1;
    this->vec2 = ipt_vec2;
    this->vec3 = ipt_vec3;
    this->have_units = false;
    this->have_magnitudes = false;
}


void Triangle::magnitudes_get(double* &magnitude_array, int which_vec)
{
    assert(
        which_vec <= 3 && which_vec >= 0,
        3,
        "Error: which_vec in magnitudes_get must be between 1 and 3."
    );

    if (not this->have_magnitudes) magnitudes_calc();
    if (which_vec==0) {
        magnitude_array[0] = this->vec1_magnitude;
        magnitude_array[1] = this->vec2_magnitude;
        magnitude_array[2] = this->vec3_magnitude;
    } else if (which_vec==1) {
        magnitude_array[0] = this->vec1_magnitude;
    } else if (which_vec==2) {
        magnitude_array[1] = this->vec2_magnitude;
    } else if (which_vec==3) {
        magnitude_array[2] = this->vec3_magnitude;
    }
}


void Triangle::magnitudes_calc()
{
    if (this->have_magnitudes) return;
    this->vec1_magnitude = sqrt(dot_product(this->vec1, this->vec1));
    this->vec2_magnitude = sqrt(dot_product(this->vec2, this->vec2));
    this->vec3_magnitude = sqrt(dot_product(this->vec3, this->vec3));
    this->have_magnitudes = true;
}


void Triangle::unit_vectors_get(vector<double>* &unit_vector_array, int which_vec)
{
    if (not this->have_units) unit_vectors_calc();
    if (which_vec==0) {
        unit_vector_array[0] = this->vec1_unit;
        unit_vector_array[1] = this->vec2_unit;
        unit_vector_array[2] = this->vec3_unit;
    } else if (which_vec==1) {
        unit_vector_array[0] = this->vec1_unit;
    } else if (which_vec==2) {
        unit_vector_array[1] = this->vec2_unit;
    } else if (which_vec==3) {
        unit_vector_array[2] = this->vec3_unit;
    }
}


void Triangle::unit_vectors_calc(void)
{
    if (this->have_units) return;
    if (not this->have_magnitudes) magnitudes_calc();
    this->vec1_unit = dscal(this->vec1, double(1.0)/this->vec1_magnitude);
    this->vec2_unit = dscal(this->vec2, double(1.0)/this->vec2_magnitude);
    this->vec3_unit = dscal(this->vec3, double(1.0)/this->vec3_magnitude);
    this->have_units = true;
}


bool Triangle::triangles_equivalent(Triangle* other)
{
    vector<double>* these_vectors[3] = { &this->vec1, &this->vec2, &this->vec3 };
    vector<double>* those_vectors[3] = { &other->vec1, &other->vec2, &other->vec3 };
    size_t vertex1_match_idx = 0;
    for (size_t i = 0; i < 3; i++) {
        if(vectors_equivalent(*these_vectors[0], *those_vectors[i])) vertex1_match_idx = i;
    }
    if (vertex1_match_idx == 0) return false;

    size_t other_vertex_1 = (vertex1_match_idx + 1) % 3;
    size_t other_vertex_2 = (vertex1_match_idx + 2) % 3;

    bool possibility1 = vectors_equivalent(*these_vectors[1], *those_vectors[other_vertex_1]) &&
                        vectors_equivalent(*these_vectors[2], *those_vectors[other_vertex_2]);
    bool possibility2 = vectors_equivalent(*these_vectors[2], *those_vectors[other_vertex_1]) &&
                        vectors_equivalent(*these_vectors[1], *those_vectors[other_vertex_2]);
    if (possibility1 || possibility2) return true;
    return false;
}

// Miscellaneous vector operations.


double dot_product(vector<double> vec1, vector<double> vec2)
{
    double product;
    for (size_t i = 0; i<vec1.size(); i++) product += vec1[i] * vec2[i];
    return product;
}


vector<double> dscal(vector<double> vec, double scalar)
{
    for (size_t i = 0; i<vec.size(); i++) vec[i] *= scalar;
    return vec;
}


bool vectors_equivalent(vector<double> vec1, vector<double> vec2)
{
    if (vec1.size() != vec2.size()) return false;
    vector<double>::iterator i, j;
    for (i = vec1.begin(); i != vec1.end(); i++) {
        for (j = vec2.begin(); j != vec2.end(); j++) {
            if (abs(i - j) > constants::EPSILON) return false;
        }
    }
    return true;
}
