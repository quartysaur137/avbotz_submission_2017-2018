#include <iostream>

#include "pid.hpp"
#include "pid.cpp"


int main()
{
    double desiredHeight;
    std::cout << "Desired Height: ";
    std::cin >> desiredHeight;

    double heightNow = getHeight();
    double basicIntegral = 0;
    double dt = 0.05;
    double errorNow = 0;
    double errorPrev = 0;
    double pidOut = 0;
    double basicDerivative = 0;
    while (desiredHeight != heightNow) {
	errorPrev = errorNow;
	errorNow = heightNow - desiredHeight;
	basicIntegral += errorNow * dt;
	basicDerivative = (errorNow - errorPrev) / dt;
	pidOut = KP * errorNow + KI * basicIntegral + KD * basicDerivative;
	setThrust(-pidOut);
	//assuming if thrust is x then it will go up by dt*x within the next dt seconds
	heightNow -= pidOut*dt*dt;
	std::cout << heightNow << std::endl;
    }
}
