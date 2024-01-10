#include <iostream>

int linearSearch( int arr[], int n, int key ) {
    for( int i = 0; i < n; i++ ) {
        if( arr[i] == key ) {
            return i;
        }
    }
    return -1;
}

/*Algorithm for binary search
  Time Complexity = O(log n) if the array is already sorted
  otherwise, O(n log n) if the array is not sorted then apply merge sort then binary sort

  space Complexity = O(1)
*/
int binarySearch( int arr[], int n, int key ) {
    // since the array is sorted we will directly jump to binary search
    int first = 0;
    int last = n - 1;
    int mid = ( first + last ) / 2;
    while( first <= last ) {
        if( arr[mid] == key ) {
            return mid;
        }
        else if( arr[mid] < key ) {
            first = mid + 1;
        }
        else {
            last = mid - 1;
        }

        mid = ( first + last ) / 2;
    }

    if( first > last )
        return -1;

    return mid;
}

int main() {

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int arrSize = sizeof( arr ) / sizeof( arr[0] );

    const int key = 7;

    int indexL = linearSearch( arr, arrSize, key );
    if( indexL >= 0 ) {
        std::cout << "Element " << key << " found at index " << indexL << std::endl;
    }
    else {
        std::cout << "Element not " << key << "found" << std::endl;
    }

    int indexB = binarySearch( arr, arrSize, key );
    if( indexB >= 0 ) {
        std::cout << "Element " << key << " found at index " << indexB << std::endl;
    }
    else {
        std::cout << "Element not " << key << "found" << std::endl;
    }

    system( "pause" );
    return 0;
}