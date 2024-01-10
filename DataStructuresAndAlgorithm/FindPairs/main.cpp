/* Problem - given an ORDERED integer array return the pair of numbers whose sum
add to some number k if not found return false.
input array = [1,2,3,9], sum = 8
output false, false
input array = [1,2,4,4], sum = 8
output 4, 4
Note: we cannot have pairs of same index numbers.
*/

#include <iostream>
#include <tuple>
#include <unordered_set>

/* Using naive approach O(n^2) time complexity and O(1) space complexity. */
std::tuple<int, int>checkForPairs( int* arr, int sizeOfArr, int sum ) {
    for( int i = 0; i < sizeOfArr - 1; i++ ) {
        for( int j = i + 1; j < sizeOfArr; j++ ) {
            if( ( arr[i] + arr[j] ) == sum ) {
                return std::make_tuple( arr[i], arr[j] );
            }
        }
    }
    return std::make_tuple( false, false );
}

/* Using better approach that takes the concept that array is ordered. O(sizeOfArr) time complexity*/
std::tuple<int, int>betterCheckForPairs( int* arr, int sizeOfArr, int sum ) {
    int low = 0, high = sizeOfArr - 1;
    while( low < high ) {
        int temp = arr[low] + arr[high];
        if( temp > sum ) {
            high--;
        }
        else if( temp < sum ) {
            low++;
        }
        else {
            return std::make_tuple( arr[low], arr[high] );
        }
    }
    return std::make_tuple( false, false );
}

/*3. Till now we had assume that array is sorted now if remove that constraints the how to take that approach
method 1: again with naive approach discussed earlier.
method 2: using a data structure called set that will keep the track of all the visited numbers in array.
we are using set because it helps in maintaining integrity.
*/
std::tuple<int, int>usingUnsortedArray( int* arr, int sizeOfArr, int sum ) {
    std::unordered_set<int>comp;
    for( int i = 0; i < sizeOfArr; i++ ) {
        int target = sum - arr[i];
        if( comp.find( target ) != comp.end() ) {
            return std::make_tuple( arr[i], target );
        }
        comp.insert( arr[i] );
    }
    return std::make_tuple( false, false );
}

int main() {
    int x = 0, y = 0;
    int sum = 8;
    int arr1[] = { 1,2,3,9 };
    int arr2[] = { 1,2,4,4 };
    int arr3[] = { 1,2,4,5,0,2 };
    int n1 = sizeof( arr1 ) / sizeof( arr1[0] );
    int n2 = sizeof( arr2 ) / sizeof( arr2[0] );
    int n3 = sizeof( arr3 ) / sizeof( arr3[0] );

    std::tie( x, y ) = checkForPairs( arr1, n1, sum );
    std::cout << "The result is: " << x << ", " << y << std::endl;
    std::tie( x, y ) = checkForPairs( arr2, n2, sum );
    std::cout << "The result is: " << x << ", " << y << std::endl;

    std::cout << "-------  better approach below  ----------" << std::endl;
    std::tie( x, y ) = betterCheckForPairs( arr2, n2, sum );
    std::cout << "The result is: " << x << ", " << y << std::endl;

    std::cout << "-------  Approach when array is unsorted-------" << std::endl;
    std::tie( x, y ) = usingUnsortedArray( arr3, n3, sum );
    std::cout << "The result is: " << x << ", " << y << std::endl;
    return 0;
}