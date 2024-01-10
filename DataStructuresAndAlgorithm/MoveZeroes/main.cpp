/**
 * Move all the non-zero elements to the front of the vector and fill the remaining
 * positions with zeros.
 */

#include <iostream>
#include <vector>

int moveZeroes( std::vector<int>& vect ) {
    int new_size = 0;
    for( size_t i = 0; i < vect.size(); ++i ) {
        if( vect[i] != 0 ) {
            vect[new_size] = vect[i];
            ++new_size;
        }
    }
    while( new_size < vect.size() ) {
        vect[new_size] = 0;
        ++new_size;
    }
    return new_size;
}

int main() {

    std::vector<int> vect;
    int element = 0;
    std::cout << "Enter elements: " << std::endl;
    for( int i = 0; i < 10; ++i ) {
        std::cin >> element;
        vect.push_back( element );
    }

    int new_size = moveZeroes( vect );

    for( int i = 0; i < new_size; ++i ) {
        std::cout << vect[i] << std::endl;
    }

    system( "pause" );
    return 0;
}