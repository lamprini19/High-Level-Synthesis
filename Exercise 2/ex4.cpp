#include <iostream>
#include <cstdlib>

// Simple swap function
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Simple "bubble sort" algorithm implementation
template<int N>
void bubble_sort (int a[N]) {
    for (int i=0; i<N; i++) {
        for (int k=0; k<N-1; k++) {
            if (a[k+1]<a[k]) {
                swap(a[k],a[k+1]);
            }
        }
    }
}

// Prints array
template<int N>
void printer(int a[N]) {
    for (int i=0; i<N; i++) {
        std::cout << a[i] << "  ";
    }
    std::cout << std::endl;
}

// Wave sort function
template<int N>
void wave_sort (int a[N]) {
    // 1st step: sort given array
    bubble_sort<N>(a);
    // 2nd step: swap the numbers
    for (int i=0; i<N-1; i+=2) {
        swap(a[i],a[i+1]);
    }
}

//       --- For Testing ---
// Checks if the array was sorted correctly
template <int N>
void check(int a[N]) {
    bool success = true;
    for (int i=0; i<N-1; i+=2) {
        if(a[i]<a[i+1] || a[i+1]>a[i+2])
            success = false;
            break;
    }
    if (success)
        std::cout << "   Everything ok" << std::endl;
    else
        std::cout << "   Something went wrong" << std::endl;
}

// Generates array of N elements
template<int N>
void random_array_generator(int a[N]) {
    for (int i=0; i<N; i++) {
        a[i] = rand();
    }
}

// Generates a random array, implements the algorithm, prints and checks the results
template<int N>
void testbench() {
    int arr[N];
    std::cout << "\nTest with " << N << " elements: " << std::endl;
    random_array_generator<N>(arr);
    std::cout << "   Before: ";
    printer<N>(arr);
    wave_sort<N>(arr);
    std::cout << "   After: ";
    printer<N>(arr);
    check<N>(arr);
    std::cout << std::endl;
}

int main(){

	srand((unsigned) time(NULL));

    // Test with randomly generated arrays
    testbench<5>();
    testbench<10>();
    testbench<6>();
    testbench<32>();
    testbench<7>();

    return 0;
}