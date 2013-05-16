// A re-implementation of the Linux cp command

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void print_error(char *this, char *filename1, char *filename2){
	fprintf(stderr, "%s cannot copy %s to %s\n%s\n", this, filename1,
            filename2, strerror(errno));
    exit(EXIT_FAILURE);
}

void print_usage(char *this){
    fprintf(stderr, "Syntax Error:\nUsage: %s [filename] [new filename]\n", this);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
	errno = 0;
    FILE *fpr, *fpw;
	char ch;

	if(argc != 3){
		print_usage(argv[0]);
	}	
	if((fpr = fopen(argv[1], "rb")) == NULL){
		print_error(argv[0], argv[1], argv[2]);
	}
	if((fpw = fopen(argv[2], "rb")) != NULL){
	    errno = EEXIST;
        print_error(argv[0], argv[1], argv[2]);
    }
	if((fpw = fopen(argv[2], "wb")) == NULL){
		print_error(argv[0], argv[1], argv[2]);
    }

	while((ch = getc(fpr))!= EOF){
		putc(ch, fpw);
	}

	fclose(fpr);
	fclose(fpw);
	
	return 0;
}
