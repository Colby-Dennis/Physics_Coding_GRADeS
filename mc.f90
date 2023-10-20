program mc
    implicit none

    integer :: number_of_particles, number_of_steps, current_step
    real :: material_thickness, travel_distance, particle_position
    real :: theta, pi
    integer :: escaped_particles, i
    character(len=256) :: str

    pi = atan(1.0)*4.0

    open(1, file="input.txt")
    read(1,*) str, number_of_particles
    read(1,*) str, number_of_steps
    read(1,*) str, material_thickness
    read(1,*) str, travel_distance
    close(1)

    escaped_particles = 0

    call RANDOM_SEED()

    do i = 1, number_of_particles
        particle_position = 0.0
        current_step = 0

        do while (current_step < number_of_steps)
            call RANDOM_NUMBER(theta)
            theta = theta * 2.0 * pi

            particle_position = particle_position + travel_distance*cos(theta)

            if (particle_position < 0.0 .or. particle_position >= material_thickness) then
                current_step = number_of_steps
            else
                current_step = current_step + 1
            end if

        end do

        if (particle_position >= material_thickness) then
            escaped_particles = escaped_particles + 1
        end if

    end do

    print*, "Escaped Particles: ", escaped_particles
    print*, "Percent Escaped: ", 100.0*real(escaped_particles)/real(number_of_particles)

end program mc