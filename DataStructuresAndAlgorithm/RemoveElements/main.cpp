#include <vector>
#include <iostream>

void removeElements( std::vector<int>& vect, int element )
{
    int c = 0;
    for( int i = 0; i < vect.size(); ++i )
    {
        int value = vect[i];
        if( value != element )
        {
            vect[c++] = value;
        }
    }

    for( int i = 0; i < c; ++i )
    {
        std::cout << vect[i] << "  ";
    }
}

int main()
{
    std::vector<int> vect;

    std::cout << "enter vecters size" << std::endl;
    int size = 0;
    std::cin >> size;

    int value = 0;
    for( int i = 0; i < size; ++i )
    {
        std::cout << "enter elements" << std::endl;
        std::cin >> value;
        vect.push_back( value );
    }

    std::cout << "enter element to remove" << std::endl;
    int element = 0;
    std::cin >> element;

    removeElements( vect, element );

    system( "pause" );
    return 0;
}