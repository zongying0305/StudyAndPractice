#include <vector>
#include <iostream>

int removeElements( std::vector<int>& vect, int element ) {
    int new_size = 0;
    for( int i = 0; i < vect.size(); ++i ) {
        int value = vect[i];
        if( value != element )
        {
            vect[new_size] = value;
            new_size++;
        }
    }

    return new_size;
}

int main() {

    std::vector<int> vect;

    std::cout << "enter vecters size" << std::endl;
    int size = 0;
    std::cin >> size;

    int value = 0;
    for( int i = 0; i < size; ++i ) {
        std::cout << "enter elements" << std::endl;
        std::cin >> value;
        vect.push_back( value );
    }

    std::cout << "enter element to remove" << std::endl;
    int element = 0;
    std::cin >> element;

    int new_size = removeElements( vect, element );
    std::cout << "vecters after removing element: " << std::endl;
    for( int i = 0; i < size; ++i ) {
        std::cout << vect[i] << " ";
    }

    system( "pause" );
    return 0;
}