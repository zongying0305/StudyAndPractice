#include <iostream>

void linearSearch( int arr[], int arrSize, int target ) {
    for ( int i = 0; i < arrSize; ++i ) {
        if ( arr[i] == target == target ) {
            std::cout << "Target found at index: " << i << std::endl;
            return;
        }
    }
    std::cout << "Target not found." << std::endl;
}

int main() {

    int arr[] = { 1, 2, 3, 4, 5, 5, 5, 6, 4 };
    int arrSize = sizeof( arr ) / sizeof( arr[0] );

    const int target = 10;
    linearSearch( arr, arrSize, target );

    system( "pause" );
    return 0;
}