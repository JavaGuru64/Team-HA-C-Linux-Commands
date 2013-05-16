// deletes a file or directory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void print_error(char *this, char *filename){
        fprintf(stderr, "%s: could not delete file %s;\n%s\n", 
        this, filename, strerror(errno));
        exit(EXIT_FAILURE);
}

void print_usage(char *this){
    fprintf(stderr, "Usage: %s [filename]\n", this);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
    errno = 0;

    if(argc == 2){
        if(remove(argv[1])){
            print_error(argv[0], argv[1]);
        }
    }else{
        puts("ERROR: ");
        print_usage(argv[0]);
    }

    return 0;
}
