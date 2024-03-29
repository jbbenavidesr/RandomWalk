#include<iostream>
#include<cmath>
#include <random>

//----- Global Constants ----- |
const double p = 0.5;
const int Nmol = 20;
const int v = 1; //Number of steps that a particle move each step.
const int L = 100;
const int T = 100000;

//----- Function Declarations ----- |
void random_step(int *Mol);
void draw(int *balls);

//----- MAIN ----- |
int main(void)
{
    // Initialize
    int *Mol= new int[Nmol * 2]; // A list with x and y position of all molecules
    for(int i = 0; i < 2 * Nmol; ++i) {
        Mol[i] = 0; 
    }
    for(int t=0; t < T; ++t)
        random_step(Mol);
    draw(Mol);

    delete [] Mol;

    return 0;
}

//----- FUNCTIONS ----- |
void random_step(int *Mol)
{
    /*
     * Performs a random step.
     */ 
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
                Mol[i*2]++;
                if (Mol[i*2] == (L/2)) Mol[i*2] = -L/2 + 1;
            } else { // Moves to left
                Mol[i*2]--;
                if (Mol[i*2] == -(L/2)) Mol[i*2] = L/2 - 1;
            }
        } else { // Moves in y
            if (p > r2){ // Moves up
                Mol[i*2 + 1]++;
                if (Mol[i*2 + 1] == (L/2)) Mol[i*2 + 1] = -L/2 + 1;
            } else { // Moves to down
                Mol[i*2 + 1]--;
                if (Mol[i*2 + 1] == -(L/2)) Mol[i*2 + 1] = L/2 - 1;
            }
        }
    }
}
void draw(int *balls)
{
    // Init lattice
    int Lattice[L][L];
    for (int ii = 0; ii < L; ++ii)
        for (int jj = 0; jj < L; ++jj)
            Lattice[ii][jj] = 0;
    
    // Insert balls
    for(int i = 0; i < Nmol; ++i) {
        Lattice[balls[i*2] + L/2][balls[i*2 + 1] + L/2]++;
    }

    // Output in pm3d map format
    for (int ii = 0; ii < L; ++ii){
        for (int jj = 0; jj < L; ++jj)
            std::cout << ii - L/2 << "\t" << jj - L/2 << "\t" <<  Lattice[ii][jj] << std::endl;
        std::cout << std::endl;
    }

}