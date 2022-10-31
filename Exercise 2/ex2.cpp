#include <iostream>

// Implements the requested algorithm:
// adds every digit to the sum.
// Every 2 digits (when cflag==false) check if the digit is >=5.
// In that case, add the sum of the 2 digits of (digit*2) instead.

unsigned int checksum (unsigned int a){
    int next = 1;
    int count = 0;
    int sum = 0;
    bool cflag = 1;     // alternates between 0 and 1 for every iteration

    while (a>0){

        next = a%10;       // rightmost digit

        // only case in which a different "next" value has to be added to the sum
        if (next>=5 && !cflag){
            int temp = next*2;
            next = temp%10 + (int)temp/10;
        }

        sum += next;
        count++;
        a = (int)a/10;          // get rid of rightmost digit
        cflag = !cflag;
    }

    return sum;
}

// Testbench
int main() {

    unsigned int a;
    unsigned int sum;

    // Test 1
    std::cout << "Test 1:" << std::endl << "a = 89635214\n";
    a=89635214;
    sum = checksum(a);
    std::cout << "sum = " << sum;
    if(sum==30) std::cout << " -> Correct\n\n";
    else std::cout << " -> Wrong\n\n";

    // Test 2
    std::cout << "Test 2:" << std::endl << "a = 345\n";
    a = 345;
    sum = checksum(a);
    std::cout << "sum = " << sum;
    if(sum==12) std::cout << " -> Correct\n\n";
    else std::cout << " -> Wrong\n\n";

    // Test 3
    std::cout << "Test 3:" << std::endl << "a = 199\n";
    a=199;
    sum = checksum(a);
    std::cout << "sum = " << sum;
    if(sum==19) std::cout << " -> Correct\n\n";
    else std::cout << " -> Wrong\n\n";

    // Test 4
    std::cout << "Test 4:" << std::endl << "a = 567893\n";
    a=567893;
    sum = checksum(a);
    std::cout << "sum = " << sum;
    if(sum==32) std::cout << " -> Correct\n\n";
    else std::cout << " -> Wrong\n\n";

    // Test 5
    std::cout << "Test 5:" << std::endl << "a = 111555\n";
    a=111555;
    sum = checksum(a);
    std::cout << "sum = " << sum;
    if(sum==14) std::cout << " -> Correct\n\n";
    else std::cout << " -> Wrong\n\n";

    return 0;
}