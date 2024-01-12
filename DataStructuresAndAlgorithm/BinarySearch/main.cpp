#include <iostream>

void binarySearch2( int arr[], int low, int high, int target ) {
    int mid = (low + high) / 2;
    if ( arr[mid] == target ) {
        std::cout << "Found at index: " << mid << std::endl;
        return;
    }
    if ( arr[mid] < target ) {
        binarySearch2( arr, mid + 1, high, target );
    }
    else if ( arr[mid] > target ) {
        binarySearch2( arr, 0, mid - 1, target );
    }
}

void binarySearch( int arr[], int low, int high, int target ) {
    while ( low <= high )
    {
        int mid = (low + high) / 2;
        if ( arr[mid] == target ) {
            std::cout << "Found at index: " << mid << std::endl;
            return;
        }
        else if ( arr[mid] < target ) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    std::cout << "Not found" << std::endl;
}

int main() {

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 14, 15, 18 };
    int arrSize = sizeof( arr ) / sizeof( arr[0] );
    binarySearch( arr, 0, arrSize - 1, 18 );
    binarySearch2( arr, 0, arrSize - 1, 15 );

    system( "pause" );
    return 0;
}