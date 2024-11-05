#include <stdio.h>
#include <stdlib.h>

//Using 
# define MAX_TITLE_LENGTH 100
# define MAX_AUTHOR_LENGTH 100 

struct Book{
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int publicationYear;
    int ISBN;
};

void GetBookInfo(struct Book * book,int i){
    printf("Enter title of book %d: ",i+1);
    scanf(" %[^\n]%*c", book->title);

    printf("Enter author of book %d: ",i+1);
    scanf(" %[^\n]%*c", book->author);

    printf("Enter publication year of book %d: ",i+1);
    scanf("%d", &book->publicationYear);

    printf("Enter ISBN of book %d: ",i+1);
    scanf("%d", &book->ISBN);
}

void LogBook(FILE *file, struct Book * Books, int size){
    fprintf(file, "Book Catalog:\n");
    for (int i=0;i<size;i++){
        fprintf(file, "Title: %s\n", Books[i].title);
        fprintf(file, "Author: %s\n", Books[i].author);
        fprintf(file, "Publication Year: %d\n", Books[i].publicationYear);
        fprintf(file, "ISBN: %d\n\n",Books[i].ISBN);
    }
}

void ReadLog(FILE *file){
    char buffer[1000];
    while(fgets(buffer,100,file)){
        printf("%s", buffer);
    }
    return;
}

int main(){
    int size;
    printf("Enter number of books: ");
    scanf("%d", &size);

    //Dynamically Assign Memory
    struct Book *Books = malloc(sizeof(struct Book) * size);
    if (!Books) {
        printf("Error Allocating Memory");
        return 1;
    }

    //Get info for each book
    for (int i=0;i<size; i++){
        GetBookInfo(&Books[i], i);
    }

    // Log Each Book into Catalog.txt
    FILE * catalog = fopen("catalog.txt","w");
    if (!catalog){
        printf("Error Opening File");
        free(Books);
        return 1;
    }
    LogBook(catalog, Books, size);

    //Free Memory & Close file
    fclose(catalog);
    free(Books);

    // Re-open Catalog to read and output
    FILE * read = fopen("catalog.txt","r");
    if (!read){
        printf("Error Reading File");
        return 1;
    }
    ReadLog(read);
    fclose(read); // Close Read Head

    return 0;
}
