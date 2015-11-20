#include <stdio.h>
#include <sys/unistd.h>
#include <time.h>
#include "Cookie.h"

void print_info(){

    char hostname[128];

    if (gethostname(hostname, sizeof hostname) < 0){
        perror("printinfo_error");
        exit(errno);
    }
    
    char fmt[64], buf[64];
    struct timeval tv;
    struct tm *tm;
    gettimeofday(&tv, NULL);
    if ( (tm = localtime(&tv.tv_sec)) != NULL){
        strftime(fmt, sizeof fmt, "%H:%M:%S.%%03u", tm);
        snprintf(buf, sizeof buf, fmt, tv.tv_usec);
    }

    printf("%s-%s-%d: ", buf, hostname, getpid());
}
