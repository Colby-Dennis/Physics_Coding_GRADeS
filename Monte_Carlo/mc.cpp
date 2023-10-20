#include <iostream>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main() {

    int number_of_particles = 1000000;
    int number_of_steps = 6;
    double material_thickness = 15.0;
    double travel_distance = 5.0;
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

    std::cout<<"Escaped Particles: "<<escaped_particles<<std::endl;
    std::cout<<"Percent Escaped: "<<double(escaped_particles)*100/double(number_of_particles)<<std::endl;

    return 0;
}