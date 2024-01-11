#include <iostream>
#include <map>

int main() {

    std::map<int, int> m;
    int arr[] = { 1, 2, 3, 4, 5, 6, 4, 5, 2, 3, 4 };
    int arrSize = sizeof( arr ) / sizeof( arr[0] );

    for ( int i = 0; i < arrSize; ++i ) {
        if ( m.find( arr[i] ) == m.end() ) {
            m[arr[i]] = 1;
        }
        else {
            std::cout << arr[i] << std::endl;
            break;
        }
    }

    system( "pause" );
    return 0;
}