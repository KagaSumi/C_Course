#include <stdio.h>

void spin(int arr[10][10], int result_arr[10][10], int rows, int cols) {
    // Spinning the array by 90 degrees clockwise
    // We do this by filling the array sideways 
    // top too bottom right to left
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
            result_arr[j][rows - 1 - i] = arr[i][j]; // 90-degree clockwise rotation
        }
    }
}

void rotateArray(int arr[10][10], int n, int rows, int cols) {
    int temp_arr[10][10]; // Temporary array to hold the result of rotation
    int rotations = (n / 90) % 4; // How many times to rotate (0 to 3)

    //Spin however many times as rotations
    for (int i = 0; i < rotations; i++) {
        spin(arr, temp_arr, rows, cols); // Rotate once
                                         
        // Copy temp_arr back to arr for the next rotation
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                arr[r][c] = temp_arr[r][c];
            }
        }
    }

    // Print the rotated array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[10][10] = {
    {34, 23, 12, 65, 87, 44, 91, 10, 53, 25},
    {99, 41, 76, 84, 32, 19, 29, 62, 81, 70},
    {50, 93, 54, 13, 27, 77,  6, 80, 45, 36},
    { 9, 55, 74, 68,  2, 60, 28, 83, 67, 57},
    {31, 64, 22, 18, 71, 14, 88, 47, 92, 37},
    {11, 98, 39, 59, 46, 85, 73,  7, 66, 17},
    {26, 78, 33,  8, 56, 58, 72, 61, 20, 95},
    {15, 16, 43, 30, 42, 38, 40, 75, 52, 24},
    {97, 79,  3, 89, 21, 82, 48,  1, 63, 35},
    {49, 94,  4, 86, 96,  5, 90, 69, 51,  0}
};

    rotateArray(arr, 180, 10, 10);
    return 0;
}

