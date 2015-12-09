#include <stdlib.h> // srand
#include <time.h>   // timespec_get

void adjnoun_rand_seed ()
{
    struct timespec ts;
    timespec_get (&ts, TIME_UTC);
    srand (ts.tv_sec + ts.tv_nsec);
}
