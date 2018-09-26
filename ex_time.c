#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>

extern char *tzname[];

int main() {
    time_t now;
    struct tm* sp;
    time(&now);
    if (putenv("TZ=PST8PDT") == 0){
        printf("%s", ctime(&now));
        sp = localtime(&now);
        printf("%d/%d/%02d %d:%02d %s\n",
            sp->tm_mon + 1, sp->tm_mday,
            sp->tm_year, sp->tm_hour,
            sp->tm_min, tzname[sp->tm_isdst]
        );
        exit(0);
    }
    else {
        int errsv = errno;
        printf("failed with errno = %d", errsv);
        exit(0);
   }
}

