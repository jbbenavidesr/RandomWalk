#include<iostream>
#include<cmath>
#include <random>

//----- Global Constants -----|
const double p = 0.5;
const double q = 1 - p;
const int v = 1; //Number of steps that a particle move each step.  
const int Tmax = 20; //Number of time steps. 

int main(void){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    int x = 0; //Position of the particle.

    for(int t=0; t<Tmax; ++t) {
        double r = dis(gen);
        if (p < r){
            x++;
        } else {
            x--;
        }

    }
    std::cout << x << std::endl;
    return 0;
}