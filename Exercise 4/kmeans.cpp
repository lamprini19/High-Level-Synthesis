#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ac_int.h"
#include "ac_math.h"
#include "types.h"

#include "mc_scverify.h"

template<int N, int M>
bool CCS_BLOCK(kmeans)(Point points[N], int ID[N], Point center[M]) {
    POINTS: for (int i = 0; i < N; i++) {
            // read each sample
        ac_int<16, false> x = points[i].x;
        ac_int<16, false> y = points[i].y;
        ac_int<17, false> min_distance = -1;
        DIST: for (int j=0; j < M; j++) {
            // read each center
            ac_int<16, false> center_x = center[j].x;
            ac_int<16, false> center_y = center[j].y;
            
            // define the absolute value of each coordinate and the distance
            ac_int<16, false> abs_x, abs_y;
            ac_int<17, false> distance;

            // calculate manhattan distance
            ac_math::ac_abs(x-center_x, abs_x);
            ac_math::ac_abs(y-center_y, abs_y);
            distance = abs_x + abs_y;

            if (distance < min_distance) {
                min_distance = distance;
                ID[i] = j;
            }
        }
    }
    // update centers
    bool change = false; 
    NEW_CENT: for (int j = 0; j < M; j++) {
        ac_int<16, false> count = 0; 
        ac_int<16, false> new_cent_x, new_cent_y;
        ac_int<32, false> sum_x = 0, sum_y = 0;
        SUMS: for (int i = 0; i < N; i++) {
            // double the length of each point, in case there are
            // at most 2^16 samples with value 2^16 -1.
            if (ID[i] == j) {
                // find the mean value of the points in the cluster and
                // update the center to this.   
                count++;
                sum_x += points[i].x;
                sum_y += points[i].y;
            }
        }
        ac_math::ac_div(sum_x, count, new_cent_x);
        ac_math::ac_div(sum_y, count, new_cent_y);

        // check if centers changed
        ac_int<16, false> diff_x, diff_y;
        ac_math::ac_abs(center[j].x-new_cent_x, diff_x);
        ac_math::ac_abs(center[j].y-new_cent_y, diff_y);
        if ( diff_x >= 1 || diff_y >= 1) {
            change = true;
            center[j].x = new_cent_x;
            center[j].y = new_cent_y;
        }
    }
    // if new and old centers are almost similar return false, else return true
    return change;
}

CCS_MAIN(int argc, char** argv) {
    std::srand(std::time(NULL)); // use current time as seed for random generator
    const unsigned short N = 10; // number of samples
    const unsigned short M = 3;  // number of clusters
        
    // Randomly initialize data samples
    std::cout << "Samples:" << std::endl;
    Point points[N];
    for(int i = 0; i < N; i++) {
        Point p = {std::rand(), std::rand()};
        points[i] = p;
        std::cout << p.x << " " << p.y << std::endl;
    }

    // Random centroid initialization
    std::cout << "\nInitial Centers:" << std::endl;
    Point center[M];
    for(int i = 0; i < M; i++) {
        Point p = {std::rand(), std::rand()};
        center[i] = p;
        std::cout << p.x << " " << p.y << std::endl;
    }

    // Dummy initial ID values (cluster labels)
    int ID[N] = {0};
    
    // Execute K-Means
    int iterations = 0;
    bool go_on = true;
    while (go_on) {
        iterations++;
        go_on = kmeans<N, M>(points, ID, center);
    }
    
    std::cout << "\nKmeans converged after " << iterations << " iterations, and created the clusters:" << std::endl;
    
    for(int j=1; j<=M; j++) {
        std::cout << "*** Cluster " << j << " ***" << std::endl;
        for(int i=0; i<N; i++) {
            if (ID[i] = j)
                std::cout << points[i].x << " " << points[i].y << std::endl;
        }
    }
    
    std::cout << "\nWith final centers:" << std::endl;
    std::cout << center[0].x << " " << center[0].y << std::endl;
    std::cout << center[1].x << " " << center[1].y << std::endl;
    std::cout << center[2].x << " " << center[2].y << std::endl;
    CCS_RETURN(0);
}
