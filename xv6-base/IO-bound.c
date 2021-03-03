#include "types.h"
#include "user.h"
#include "syscall.h"

char SCCSid[] = "@(#) @(#)pipe.c:3.3 -- 5/15/91 19:30:20";

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
        char buf[512];
        int  pvec[2];

    pipe(pvec);

        iter = 0;

        while (iter <= 10) {


                if (write(pvec[1], buf, sizeof(buf)) != sizeof(buf)) {
                                printf(2,"write failed, error %d\n", write(pvec[0], buf, sizeof(buf)));
                        }
                if (read(pvec[0], buf, sizeof(buf)) != sizeof(buf))  {
                                printf(2,"read failed, error %d\n", read(pvec[0], buf, sizeof(buf)));
                        }
                iter++;
        }
        exit();
}
