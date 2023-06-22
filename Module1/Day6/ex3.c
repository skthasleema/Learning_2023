#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time calculateDifference(struct Time t1, struct Time t2);

int main() {
    struct Time startTime, endTime, difference;

    printf("Enter the start time:\n");
    printf("Hours: ");
    scanf("%d", &startTime.hours);
    printf("Minutes: ");
    scanf("%d", &startTime.minutes);
    printf("Seconds: ");
    scanf("%d", &startTime.seconds);

    printf("\nEnter the end time:\n");
    printf("Hours: ");
    scanf("%d", &endTime.hours);
    printf("Minutes: ");
    scanf("%d", &endTime.minutes);
    printf("Seconds: ");
    scanf("%d", &endTime.seconds);

    difference = calculateDifference(startTime, endTime);

    printf("\nTime Difference: %d hours, %d minutes, %d seconds\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}

struct Time calculateDifference(struct Time t1, struct Time t2) {
    struct Time diff;
    int t1Seconds, t2Seconds, timeDifference;

    t1Seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    t2Seconds = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    timeDifference = t2Seconds - t1Seconds;

    diff.hours = timeDifference / 3600;
    timeDifference %= 3600;
    diff.minutes = timeDifference / 60;
    diff.seconds = timeDifference % 60;

    return diff;
}
