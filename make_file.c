// Creates a file

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *new;

    if(argc == 2){
        if(fopen(argv[1], "r") != NULL){   
            puts("ERROR: File already exists");
        }
        else if((new = fopen(argv[1], "w")) == NULL){
            puts("ERROR");
        }
        fclose(new);
    }
    else{
        puts("ERROR:");
        puts("Usage: ./make_file [file name]");
    }

    return(0);
}
