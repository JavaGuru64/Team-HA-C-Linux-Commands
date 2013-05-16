// implementation of linux cd command

#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void print_error(char *this, char *dirname){
    fprintf(stderr, "%s cannot go to %s\n%s\n", this, dirname, strerror(errno));
  
    exit(EXIT_FAILURE);
}

void print_usage(char *this){
    fprintf(stderr, "SYNTAX ERROR:\nUsage: %s [dir_name]\n", this);

    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
    errno = 0;

    if(argc == 2){
        if(chdir(argv[1])){
            print_error(argv[0], argv[1]);
        }

        puts("\nThe cd command is ussualy built right into the shell");
        puts("our change_dir command is on a different process so");
        puts("the change happens but is changed back once the process ends\n");

        printf("Directory changed to %s\n", get_current_dir_name());
    }
    else if(argc == 1){
        struct passwd *user = getpwnam(getlogin());
        if(chdir(user->pw_dir)){
            print_error(argv[0], (user->pw_dir));
        }

        puts("\nThe cd command is ussualy built right into the shell");
        puts("our change_dir command is on a different process so");
        puts("the change happens but is changed back once the process ends\n");
        
        printf("Directory changed to %s\n", get_current_dir_name());
    }
    else{
        print_usage(argv[0]);
    }

    return 0;
}
