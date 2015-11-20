#include <stdio.h>
#include <sys/unistd.h>
#include <time.h>
#include "Cookie.h"


#define JudyNum 1
#define TinaNum 2

///
// because Tina is the younger sister who is the jewel of the Mother's eyes,
// She gets 2 cookies per Judy's 1
// Judy feels very insecure about this
// To signify this, Judy's B value is 1 and Tina's B value is 2
//
///

//sleep between 1 and 5 seconds
void sleepRand(){
    time_t t;
    srand( (unsigned) time(&t));
    sleep(rand() %4 + 1);
}

void print_info(){

    char hostname[128];

    if (gethostname(hostname, sizeof hostname) < 0){
        perror("printinfo_error");
        exit(1);
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
