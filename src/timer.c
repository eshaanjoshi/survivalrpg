#include "timer.h"
#include "defines.h"
struct timeval *init_time()
{
    struct timeval *start = (struct timeval*)malloc(sizeof(struct timeval));
    gettimeofday(start, NULL);
    return start;
}

long timer(struct timeval *start)
{
    time_t initial_s = start->tv_sec;
    suseconds_t initial_u = start->tv_usec;
    gettimeofday(start, NULL);
    //return (initial_s - start->tv_sec) * 1000000;// + initial_u - start->tv_usec;
    return (signed long)(start->tv_usec - initial_u);
}

long time_since(struct timeval *start){
    struct timeval stop;
    gettimeofday(&stop, NULL);
    //printf("took %lu us\n", (stop.tv_sec - start->tv_sec) * 1000000 + stop.tv_usec - start->tv_usec);
    return  (stop.tv_sec - start->tv_sec) * 1000000 + stop.tv_usec - start->tv_usec;
}


void wait_until(struct timeval *t)
{
    while(time_since(t) < FRAME_DELAY){
            
    }
}