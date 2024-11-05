// #include <stdio.h>
// void print_array(int rows, int cols, int array[rows][cols]) {
//      printf("\n2D Array is: \n");
//     for (int i=0; i<rows; i++){
//         for (int j=0; j<cols; j++){
//             printf("%d ",array[i][j]);
//         }
//         printf("\n");
//     }
// }
// int main(){
//     int rows, cols;
//     printf("Enter the no of rows\n");
//     scanf("%d", &rows);
//     printf("Enter the no of cols\n");
//     scanf("%d", &cols);
//
//     // Defining a 2D - Arraggy
//     // 1 2
//     // 3 4
//     int array[rows][cols];
//
//     printf("Enter the values of array\n");
//     for (int i=0; i<rows; i++){
//         for (int j=0; j<cols; j++){
//             printf("Enter the elements of [%d][%d]",i,j);
//             scanf("%d",&array[i][j]);
//         }
//     }
//     print_array(rows,cols,array);
//
//     // Access specific index of a 2D array 0-1
//
//     int row,col;
//
//     printf("Which index are you trying to access \n");
//     scanf("%d %d", &row,&col);
//
//     if (0<row<rows && col<cols){
//         printf("Element at [%d][%d] is %d\n", row,col, array[row][col]);
//         printf("\n");
//     }
//     else{
//         printf("Out of Array Error");
//     }
//     // activity-1: Insert to a specific Location
//     int value;
//     printf("Which index are you trying to update \n");
//     scanf("%d %d", &row,&col);
//     printf("What value do you want to update it do \n");
//     scanf("%d", &value);
//     if (0<row<rows && col<cols){
//         array[row][col] = value;
//         printf("Element at [%d][%d] is %d\n", row,col, array[row][col]);
//         printf("\n");
//         print_array(rows,cols,array);
//     }
//     else{
//         printf("Out of Array Error");
//     }
//     // Activity 2 : Delete a specific location;
//
//     printf("Which index are you trying to delete");
//     scanf("%d %d", &row,&col);
//     if (0<row<rows && col<cols){
//         array[row][col] = 0;
//         printf("Element at [%d][%d] is %d\n", row,col, array[row][col]);
//         printf("\n");
//         print_array(rows,cols,array);
//     }
//     else{
//         printf("Out of Array Error");
//     }
//
//     // Activity 3: Making sum of the elements in the array
//     int sum = 0;
//     for (int i=0; i<rows; i++) {
//         for (int j=0; j<cols; j++) {
//             sum+=array[i][j];
//         }
//     }
//     printf("The sum of the array is %d\n", sum);
//     return 0;
// }