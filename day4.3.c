#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time getTimeDifference(struct Time t1, struct Time t2) {
    struct Time diff;
    int seconds1, seconds2, totalSeconds;
    
    seconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    seconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    totalSeconds = seconds2 - seconds1;
    
    diff.hours = totalSeconds / 3600;
    totalSeconds %= 3600;
    diff.minutes = totalSeconds / 60;
    diff.seconds = totalSeconds % 60;
    
    return diff;
}

int main() {
    struct Time startTime, endTime, timeDiff;
    
    printf("Enter the start time (hours minutes seconds): ");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);
    
    printf("Enter the end time (hours minutes seconds): ");
    scanf("%d %d %d", &endTime.hours, &endTime.minutes, &endTime.seconds);
    
    timeDiff = getTimeDifference(startTime, endTime);
    
    printf("Time difference: %02d:%02d:%02d\n", timeDiff.hours, timeDiff.minutes, timeDiff.seconds);
    
    return 0;
}
