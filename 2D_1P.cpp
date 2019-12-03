#include<iostream>
#include<cmath>
#include <random>

//----- Global Constants ----- |
const double p = 0.5;
const int Nmol = 1;
const int v = 1; //Number of steps that a particle move each step.
const int L = 100;

//----- Function Declarations ----- |
int random_walk(int xi, int trails);
void draw(int balls[][2]);

//----- MAIN ----- |
int main(void)
{
    // Initialize
    int Mol[Nmol][2]; // A list with x and y position of all molecules
    for(int i = 0; i < Nmol; ++i) {
        Mol[i][0] = 0; 
        Mol[i][1] = 0;
    }

    // Init random generator
    std::random_device rd; //Random seed 
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    // Update
    for(int i = 0; i < Nmol; ++i) {
    // ---Select if moving in x or y
        double r1 = dis(gen);
        double r2 = dis(gen);
        if (p > r1){ // Moves in x
            if (p > r2){ // Moves to right
                Mol[i][0]++;
            } else { // Moves to left
                Mol[i][0]--;
            }
        } else { // Moves in y
            if (p > r2){ // Moves up
                Mol[i][1]++;
            } else { // Moves to down
                Mol[i][1]--;
            }
        }
    }
    draw(Mol);


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
        if (p > r){
            x++;
        } else {
            x--;
        }
    }
    return x;
}
void draw(int balls[][2])
{
    // Init lattice
    int Lattice[L][L];
    for (int ii = 0; ii < L; ++ii)
        for (int jj = 0; jj < L; ++jj)
            Lattice[ii][jj] = 0;
    
    // Insert balls
    for(int i = 0; i < Nmol; ++i) {
        Lattice[balls[i][0] + L/2][balls[i][1] + L/2]++;
    }

    // Output in pm3d map format
    for (int ii = 0; ii < L; ++ii){
        for (int jj = 0; jj < L; ++jj)
            std::cout << ii - L/2 << "\t" << jj - L/2 << "\t" <<  Lattice[ii][jj] << std::endl;
        std::cout << std::endl;
    }

}