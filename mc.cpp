#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

#define PI 3.14159

int main() {

    int number_of_particles;
    int number_of_steps;
    float material_thickness;
    float travel_distance;
    float particle_position;
    int current_step;
    float theta;
    int escaped_particles;

    string str;

    ifstream indata;
    indata.open("input.txt");
    indata >> str >> number_of_particles;
    indata >> str >> number_of_steps;
    indata >> str >> material_thickness;
    indata >> str >> travel_distance;
    indata.close();

    escaped_particles = 0;

    for (int i = 0; i < number_of_particles; i++) {
        particle_position = 0.0;
        current_step = 0;

        while (current_step < number_of_steps) {
            theta = ((float) rand()/RAND_MAX)*2*PI;

            particle_position += travel_distance*cos(theta);

            if (particle_position < 0 || particle_position > material_thickness) {
                current_step = number_of_steps;
            } else {
                current_step++;
            }
        }

        if (particle_position >= material_thickess) {
            escaped_particles += 1;
        }
    }

    cout << "Escaped Particles: " << escaped_particles << endl;
    cout << "Percent Escaped: " << double(escaped_particles)*100/double(number_of_particles)<<endl;
    return 0;
}