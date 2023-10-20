#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <string>

#define PI 3.14159265

using namespace std;

int main() {

    string str;
    int number_of_particles;
    int number_of_steps;
    double material_thickness;
    double travel_distance;

    ifstream indata;
    indata.open("input.txt");
    indata >> str >> number_of_particles;
    indata >> str >> number_of_steps;
    indata >> str >> material_thickness;
    indata >> str >> travel_distance;
    indata.close();


    int escaped_particles = 0;

    for (int i = 0; i < number_of_particles; i++) {
        double particle_position = 0.0;
        int current_step = 0;

        while (current_step < number_of_steps) {
            double theta = ((float) rand()/RAND_MAX)*2*PI;
            particle_position += travel_distance*cos(theta);

            if (particle_position < 0.0 || particle_position > material_thickness) {
                current_step = number_of_steps;
            } else {
                current_step += 1;
            }
        }

        if (particle_position >= material_thickness) {
            escaped_particles += 1;
        }
    }

    cout<<"Escaped Particles: "<<escaped_particles<<endl;
    cout<<"Percent Escaped: "<<double(escaped_particles)*100/double(number_of_particles)<<endl;

    return 0;
}