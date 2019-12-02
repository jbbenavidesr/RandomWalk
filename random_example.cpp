#include<iostream>
#include<cmath>
#include <random>

int main(void){
    int seed = 1;
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(0, 100);
    for(int n=0; n<100000; ++n) {
        std::cout << dis(gen) << std::endl;
    }
    return 0;
}