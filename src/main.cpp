#include <iostream>
#include <vector>
#include "primitive.hpp"

using namespace std;

int main() {
    Triangle t1;
    t1.init((vector<double>) {0.0, 0.0, 0.0}, (vector<double>) {1.0, 1.0, 0.0}, (vector<double>) {1.0, 0.0, 0.0});

    cout << "Triangle :\n";
    cout << "    vec1 : " << to_string(t1.vec1.at(0)) << " " << to_string(t1.vec1.at(1)) << endl;
    cout << "    vec2 : " << to_string(t1.vec2.at(0)) << " " << to_string(t1.vec2.at(1)) << endl;
    cout << "    vec3 : " << to_string(t1.vec3.at(0)) << " " << to_string(t1.vec3.at(1)) << endl;

    vector<double> t1_unit_vectors[3];
    vector<double>* t1_unit_vectors_array_ptr = &t1_unit_vectors[0];
    t1.unit_vectors_get(t1_unit_vectors_array_ptr);

    cout << "    unit_vec1 : " << to_string(t1_unit_vectors[0].at(0)) << " " << to_string(t1_unit_vectors[0].at(1)) << endl;
    cout << "    unit_vec2 : " << to_string(t1_unit_vectors[1].at(0)) << " " << to_string(t1_unit_vectors[1].at(1)) << endl;
    cout << "    unit_vec3 : " << to_string(t1_unit_vectors[2].at(0)) << " " << to_string(t1_unit_vectors[2].at(1)) << endl;

    double t1_magnitudes[3];
    double* t1_mag_array_ptr = &t1_magnitudes[0];
    t1.magnitudes_get(t1_mag_array_ptr);
    cout << "   magnitude1 : " << to_string(t1_magnitudes[0]) << endl;
    cout << "   magnitude2 : " << to_string(t1_magnitudes[1]) << endl;
    cout << "   magnitude3 : " << to_string(t1_magnitudes[2]) << endl;

    return 0;
}
