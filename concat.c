// implementation of cat method

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void print_error(char *this, char *filename){
    fprintf(stderr, "%s cannot concat %s\n%s\n",
            this, filename, strerror(errno));
    exit(EXIT_FAILURE);
}

void print_usage(char *this){
    fprintf(stderr, "Syntax Error:\nUsage: %s [filename]", this);
    exit(EXIT_FAILURE);
}
int main(int argc, char *argv[]){
    errno = 0;
    FILE *fp;
    int maxline = 1024;
    char line[maxline];

    if(argc == 2){
        if((fp = fopen(argv[1], "rb")) == NULL){
            print_error(argv[0], argv[1]);
        }
    }
    else{
        print_usage(argv[0]);
    }

    while(fgets(line, maxline, fp)){
        printf("%s", line);
    }

    fclose(fp);
}
