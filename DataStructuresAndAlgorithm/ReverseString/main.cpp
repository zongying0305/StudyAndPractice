#include <iostream>
#include <string>

int main() {

    std::string str;
    std::cout << "Enter a string: " << std::endl;
    std::getline( std::cin, str );
    std::string str2 = str;

    // f1
    std::cout << "Entered string is: " << str << std::endl;
    std::reverse( str.begin(), str.end() );
    std::cout << "Reversed string is: " << str << std::endl;

    // f2
    std::cout << "Entered string is: " << str2 << std::endl;
    int len = str2.length() - 1; // '\0'
    for( int i = 0; i <= len; ++i, --len ) {
        std::swap( str2[i], str2[len] );
    }
    std::cout << "Reversed string is: " << str2 << std::endl;

    system( "pause" );
    return 0;
}