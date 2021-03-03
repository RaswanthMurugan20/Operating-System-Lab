#include "types.h"
#include "user.h"
#include "syscall.h"

char SCCSid[] = "@(#) @(#)syscall.c:3.3 -- 5/15/91 19:30:21";

unsigned long iter;

void report()
{
        printf(2,"COUNT|%ld|1|lps\n", iter);
        exit();
}

int main(argc, argv)
int     argc;
char    *argv[];
{
        char   *test;
        test = "mix";
        iter = 0;

        switch (test[0]) {
        case 'm':
            while (iter <= 10) {

                close(dup(0));
                getpid();
                getpid();
                iter++;
            }
            break;
            // NOTREACHED 
        case 'c':
           while (1) {
                close(dup(0));
                iter++;
           }
           // NOTREACHED
        case 'g':
           while (1) {
                getpid();
                iter++;
           }
           // NOTREACHED
        case 'e':
           while (1) {
                int pid = fork();
                if (pid < 0) {
                    printf(2,"%s: fork failed\n", argv[0]);
                    exit();
                } else if (pid == 0) {
                    exec("/bin/true", (char **) 0);
                    printf(2,"%s: exec /bin/true failed\n", argv[0]);
                    exit();
                } else {
                    if (wait() < 0) {
                        printf(2,"%s: waitpid failed\n", argv[0]);
		        exit();
                    }
                }
                iter++;
           }
           // NOTREACHED 
        }

        exit();
}





