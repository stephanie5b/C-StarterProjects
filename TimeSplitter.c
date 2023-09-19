/*
 * TimeSplitter
 *
 * A program that takes an input in seconds since midnight and converts it to 
 * the format "hours:minutes:seconds am/pm". 
 * Example: 
 *          Input: 62605 seconds 
 *          Output: 5:23:25pm
 */

#include <stdio.h>

#define SECS_IN_DAY  86400
#define SECS_IN_HOUR 3600
#define SECS_IN_MIN  60

void split_time(long total_sec, int *hr, int *min, int *sec);

void split_time(long total_sec, int *hr, int *min, int *sec) {
    *hr = (total_sec % SECS_IN_DAY) / SECS_IN_HOUR;
    *min = (total_sec % SECS_IN_HOUR) / SECS_IN_MIN;
    *sec = total_sec % SECS_IN_MIN;
}

int main(void) {
    int hr = 0, min = 0, sec = 0;
    long userInputSec;
    char *timeOfDay[] = {"am", "pm"};

    printf("Seconds since midnight: ");
    scanf("%ld", &userInputSec);
    
    split_time(userInputSec, &hr, &min, &sec);

    char *suffix = (hr < 12) ? timeOfDay[0] : timeOfDay[1];
    if (hr > 12) {
        hr -= 12;
    }

    printf("\nTime: %d:%02d:%02d%s\n", hr, min, sec, suffix);

    return 0;
}
