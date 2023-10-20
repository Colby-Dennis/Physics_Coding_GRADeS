import random
import math

number_of_particles = 100
number_of_steps = 6
material_thickness = 15
travel_distance = 5
escaped_particles = 0

# Looping over the large number of particles
for i in range(number_of_particles):
    # Initializing the particle
    particle_position = 0
    current_step = 0
    # Looping over the steps
    while (current_step < number_of_steps):
        # Finding the bounce angle and moving the particle accordingly
        theta = random.random()*2*math.pi
        particle_position += travel_distance*math.cos(theta)
        # Exit conditions
        if (particle_position < 0 or particle_position > material_thickness):
            current_step = number_of_steps
        else:
            # Continue if exit condition wasn't met.
            current_step += 1
    
    # While loop ended, check if particle escaped.
    if particle_position >= material_thickness:
        escaped_particles += 1

# Getting final results
print("Escaped Particles: " + str(escaped_particles))
print("Percent Escaped: " + str(escaped_particles*100/number_of_particles)+"%")
