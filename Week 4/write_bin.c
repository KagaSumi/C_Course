#include <stdio.h>
void writeBin(const char* filename, int data, int size){
    FILE *fptr =  fopen(filename,"wb");
    if (fptr == NULL){
        printf("eror");
    }
    fwrite(data, sizeof(int), size, fptr);
    fclose(fptr);
    return;
}

int main(){
    int numbers[3]= {10,20,30};
    writeBin("example.bin",numbers,3);
    printf("bin written");
    return 0;
}