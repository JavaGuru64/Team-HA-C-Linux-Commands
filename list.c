// implementation of linux ls command

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// a necissary function for scandir which only returns the number one
// if we wanted to list only certain things then we would edit this method
static int filter(const struct dirent *unused){
    return 1;
}

void print_error(char *this, char *dir){
    fprintf(stderr, "%s cannot list from %s\n%s\n", this, dir, strerror(errno));
    exit(EXIT_FAILURE);
}

void print_usage(char *this){
    puts("ERROR:");
    fprintf(stderr, "Usage: %s [directory]\n", this);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
    errno = 0;
    struct dirent **contents;
    int content_count;

    if(argc < 2){
        if((content_count = scandir("./", &contents, filter, alphasort))<0){
            print_error(argv[0], "./");
        }
    }
    else if(argc == 2){
        if((content_count = scandir(argv[1], &contents, filter, alphasort))<0){
            print_error(argv[0], argv[1]);
        }
    }
    else{
        print_usage(argv[0]);
    }
    
    int i;
    for(i=0; i<content_count; i++){
        puts(contents[i]->d_name);
    }
    
    return 0;
}
