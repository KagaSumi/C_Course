#include <stdio.h>

//File and pointer ot delete a file
void deleteFile(const char *filename){
    //Precondition Check if file exists
    FILE *fptr = fopen(filename,"r");
    if (fptr == NULL){
        printf("File does not exist");
        return;
    }
    fclose(fptr);
    (remove(filename) == 0) ? 0 : printf("Failed to delete file\n");
    return;
}
int main(){
    deleteFile("example.txt"); 
    return 0;
}