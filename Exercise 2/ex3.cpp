#include <iostream>

// Computes the sum of each row, stores it in row_sum[] array
template<int N, int M>
void compute_row_sum (short a[N][M], short row_sum[N]){
    int sum;
    for(int i=0; i<N; i++){
        sum = 0;
        for(int k=0; k<M; k++){
            sum += *(a[i]+k);
            }
        row_sum[i] = sum;
    }
}

// Prints array
template<int N>
void printer(short a[N]) {
    for (int i=0; i<N; i++) {
        std::cout << a[i] << "  ";
    }
    std::cout << std::endl;
}

// Prints array but 2D
template<int N, int M>
void printer2D(short a[N][M]) {
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++) {
        std::cout << *(a[i]+k) << "  ";
        }
        std::cout << std::endl;
    }
}

int main(){

    // Test 1
    std::cout << "Test 1:" << std::endl;
    short test1[5][6] = {{3,4,2,5,6,7},
                        {4,6,8,2,4,8},
                        {1,2,3,4,5,6},
                        {3,4,2,5,6,7},
                        {4,6,8,2,4,8}};
    short result1[5] = {0};
    short expected[5] = {27,32,21,27,32};
    // Print results
    compute_row_sum<5,6>(test1, result1); 
    std::cout << "Array: " << std::endl;
    printer2D<5,6>(test1);
    std::cout << "Result: " << std::endl;
    printer<5>(result1);
    std::cout << "Expected Result: " << std::endl;
    printer<5>(expected);

    // Test 2
    std::cout << "\n\nTest 2:" << std::endl;
    short test2[8][7] = {{3,1,0,6,7,9,1},
                        {4,6,8,2,4,8,1,},
                        {1,2,3,4,5,6,2,},
                        {0,0,0,0,0,3,4},
                        {4,6,8,2,4,8,5,},
                        {1,2,6,7,8,6,2,},
                        {0,0,1,2,3,3,4},
                        {4,7,6,5,4,8,5,}};
    short result2[8] = {0};
    short expected2[8] = {27,33,23,7,37,32,13,39};
    // Print results
    compute_row_sum<8,7>(test2, result2); 
    std::cout << "Array: " << std::endl;
    printer2D<8,7>(test2);
    std::cout << "Result: " << std::endl;
    printer<8>(result2);
    std::cout << "Expected Result: " << std::endl;
    printer<8>(expected2);

    // Test 3
    std::cout << "\n\nTest 3:" << std::endl;
    short test3[1][10] = {3,1,0,6,7,9,1,8,12,3};
    short result3[1] = {0};
    short expected3[1] = {50};
    // Print results
    compute_row_sum<1,10>(test3, result3); 
    std::cout << "Array: " << std::endl;
    printer2D<1,10>(test3);
    std::cout << "Result: " << std::endl;
    printer<1>(result3);
    std::cout << "Expected Result: " << std::endl;
    printer<1>(expected3);

    // Test 4
    std::cout << "\n\nTest 4:" << std::endl;
    short test4[8][1] = {{3},{4},{1},{19},{4},{1},{0},{4}};
    short result4[8] = {0};
    short expected4[8] = {3,4,1,19,4,1,0,4};
    // Print results
    compute_row_sum<8,1>(test4, result4); 
    std::cout << "Array: " << std::endl;
    printer2D<8,1>(test4);
    std::cout << "Result: " << std::endl;
    printer<8>(result4);
    std::cout << "Expected Result: " << std::endl;
    printer<8>(expected4);
}