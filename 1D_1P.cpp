#include<iostream>
#include<cmath>
#include <random>

//----- Global Constants ----- |
const double p = 0.7;
const int N = 100;
const int v = 1; //Number of steps that a particle move each step.  


//----- Function Declarations ----- |
int random_walk(int xi, int trails);

//----- MAIN ----- |
int main(void)
{
    for (int Ntrails = 1; Ntrails < 1000; Ntrails++){
        double x_prom= 0, x2_prom = 0;
        for(int ti = 0; ti < Ntrails; ti++){
            int trail = random_walk(0, N); 
            x_prom += trail;
            x2_prom += trail * trail;
        }
        x_prom /= Ntrails;
        x2_prom /= Ntrails;

        double dx2 = x2_prom - (x_prom*x_prom);

        std::cout << x_prom << std::endl;
        //std::cout << x2_prom << std::endl;
        //std::cout << dx2 << std::endl;
    }
    return 0;
}

//----- FUNCTIONS ----- |
int random_walk(int xi, int Tmax)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    int x = xi; //Initial position of the particle.

    for(int t=0; t<Tmax; ++t) {
        double r = dis(gen);
        if (p < r){
            x++;
        } else {
            x--;
        }
    }
    return x;
}