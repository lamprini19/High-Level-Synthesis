#include <iostream>

// Counts set bits in an integer
unsigned short count_ones(unsigned int a) {
    unsigned short count = 0;
    // Kernighan's algorithm
    while(a>0){
        a &= (a - 1);
        count++;
    }
    return count;
}

int main() {

    // For testing
    unsigned int num[8] = {0, 100, 7, 9, 111, 54, 309, 2047};       // some random numbers
    unsigned int expected_result[8] = {0, 3, 3, 2, 6, 4, 5, 11};    // expected results

    int ones;
    // 8 Iterations for 8 tests
    for(int i=0; i<8; i++) {
        ones = count_ones(num[i]);
        if(expected_result[i]==ones)
            std::cout << "Set bits of: " << num[i] << " are " << ones << std::endl;
        else
            std::cout << "Something's wrong" << std::endl;
    }
    
    return 1;
}