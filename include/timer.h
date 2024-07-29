#ifndef TIMER
#define TIMER
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>


struct timeval *init_time();

long timer(struct timeval *start);

long time_since(struct timeval *start);

void wait_until(struct timeval *t);
#endif