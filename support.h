#ifndef CONTROL_H
#define CONTROL_H

#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>


#define ON_ERROR(expr, errStr, retVal) {                 \
    if (expr) {                                           \
        fprintf(stderr, "FATAL ERROR: %s\n", errStr);      \
        return retVal;                                      \
    }                                                        \
}                                                             \

std::vector<int> generateArr(int amount);
int* generateCArr(int amount);

//--------BIN HEAP---------//

std::vector<int> generateArr(int amount) {
    std::vector<int> vec;

    srand((unsigned) time(NULL));

    for (int i = 0; i < amount; i++) {
        int random = rand() % 150000;                // generating ramdom value
        vec.push_back(random);
    }

    return vec;
}

int* generateCArr(int amount) {
    int* vec = (int*) calloc((size_t) amount, sizeof(int));

    srand((unsigned) time(NULL));

    for (int i = 0; i < amount; i++) {
        int random = rand() % 150000;                // generating ramdom value
        vec[i] = random;
    }

    return vec;
}

#endif