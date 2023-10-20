program rk_simple
    implicit none

    real :: x, y, k1, k2, k3, k4, h
    integer :: n, i

    ! dy/dx = -x*y, y(0) = 1
    ! exact solution y = exp(-x*x/2)

    ! find y(3)

    n = 1000

    h = 3.0 / real(n)

    ! initial conditions
    y = 1
    x = 0

    ! dy/dx = -x*y
    do i = 1, n
        k1 = h * (-x*y)
        k2 = h * (-(x+0.5*h)*(y+0.5*k1))
        k3 = h * (-(x+0.5*h)*(y+0.5*k2))
        k4 = h * (-(x+0.5*h)*(y+0.5*k3))

        x = x + h
        y = y + (k1 + 2.0*k2 + 2.0*k3 + k4)/6

    end do

    print*, "x: ", x
    print*, "y: ", y


end program 