#include <iostream>
#include <vector>

void print( std::vector<std::vector<int>>& image ) {
    for ( int i = 0; i < image.size(); i++ ) {
        for ( int j = 0; j < image[0].size(); j++ ) {
            std::cout << image[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void rotate_image( int row, int col, std::vector<std::vector<int>>& image ) {

    int new_row = col, new_col = row;
    std::vector<std::vector<int>> rotated_image1( new_row, std::vector<int>( new_col ) );
    std::vector<std::vector<int>> rotated_image2( new_row, std::vector<int>( new_col ) );

    // assign values
    for ( int y = 0; y < new_row; ++y ) {
        for ( int x = 0; x < new_col; ++x ) {
            rotated_image1[y][x] = image[x][y];
            rotated_image2[y][x] = image[x][y];
        }
    }
    std::cout << "Switch r/c image: " << std::endl;
    print( rotated_image1 );

    // reverse
    int col_front = 0, col_back = new_col - 1;
    for ( int i = 0; i < new_row; ++i ) {
        while ( col_front < col_back ) {
            int temp = rotated_image1[i][col_front];
            rotated_image1[i][col_front] = rotated_image1[i][col_back];
            rotated_image1[i][col_back] = temp;
            ++col_front;
            --col_back;
        }
    }
    std::cout << "Rotated image 90: " << std::endl;
    print( rotated_image1 );

    int row_front = 0, row_back = new_row - 1;
    for ( int i = 0; i < new_col; ++i ) {
        while ( row_front < row_back ) {
            int temp = rotated_image2[row_front][i];
            rotated_image2[row_front][i] = rotated_image2[row_back][i];
            rotated_image2[row_back][i] = temp;
            ++row_front;
            --row_back;
        }
    }
    std::cout << "Rotated image -90: " << std::endl;
    print( rotated_image2 );
}

int main() {
    int row = 0;
    int col = 0;
    std::cout << "Enter row and col: " << std::endl;
    std::cin >> row >> col;

    std::vector<std::vector<int>> image( row, std::vector<int>( col ) );
    int n = 0;
    for ( int i = 0; i < row; i++ ) {
        for ( int j = 0; j < col; j++ ) {
            image[i][j] = ++n;
        }
    }

    std::cout << "Image: " << std::endl;
    print( image );

    rotate_image( row, col, image );

    system( "pause" );
    return 0;
}