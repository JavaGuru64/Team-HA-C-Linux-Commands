// reimplementation of the mkdir linux command

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void print_error(char *this, char *dirname){
    fprintf(stderr, "%s cannot make directory %s\n%s\n",
            this, dirname, strerror(errno));
    exit(EXIT_FAILURE);
}

void print_usage(char *this){
    fprintf(stderr, "SYNTAX ERROR:\nUsage: %s [dir_name]", this);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
    errno = 0;

    if(argc == 2){
        if(mkdir(argv[1], (S_IRWXG | S_IRWXU))){
            print_error(argv[0], argv[1]);
        }
    }
    else{
        print_usage(argv[0]);
    }

    return 0;
}
