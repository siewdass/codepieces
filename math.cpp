#include <cmath>
#include <iomanip>
#include <random>

class math {
public:
    int random( int min, int max );
    double random( double min, double max );
    int round( double number );
} Math;

int math::random( int min, int max ) {

    std::random_device seed;
    std::default_random_engine engine( seed( ) );
    std::uniform_int_distribution < > distribution( min, max );
    int number = distribution( engine );

    return number;
}

double math::random( double min, double max ) {

    std::random_device seed;
    //std::default_random_engine engine( seed( ) );
    std::mt19937 engine( seed( ) );
    std::uniform_real_distribution < > distribution( min, max );
    double number = distribution( engine );

    return ceil( number * 100.0 ) / 100.0;
}


int math::round( double number ) {
    return lround( number );
}

#include <iostream>

int main( ) {

    for ( int i = 0; i < 3; i ++ ) {
        std::cout << Math.random( 1.0, 2.0 ) << std::endl;
    }

    std::cout << Math.round( 15.4 ) << std::endl;
}