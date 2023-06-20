#include <stdio.h>

typedef struct {
    int hours;
    int minutes;
    int seconds;
} Time;

// Function to calculate the difference between two time periods
Time calculateTimeDifference(Time t1, Time t2) {
    Time diff;
    int totalSeconds1, totalSeconds2, difference;

    // Convert time periods to seconds
    totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    // Calculate the difference in seconds
    difference = totalSeconds2 - totalSeconds1;

    // Convert difference back to hours, minutes, and seconds
    diff.hours = difference / 3600;
    difference = difference % 3600;
    diff.minutes = difference / 60;
    diff.seconds = difference % 60;

    return diff;
}

int main() {
    Time startTime, endTime, difference;

    // Input start time
    printf("Enter start time:\n");
    printf("Hours: ");
    scanf("%d", &(startTime.hours));
    printf("Minutes: ");
    scanf("%d", &(startTime.minutes));
    printf("Seconds: ");
    scanf("%d", &(startTime.seconds));

    // Input end time
    printf("\nEnter end time:\n");
    printf("Hours: ");
    scanf("%d", &(endTime.hours));
    printf("Minutes: ");
    scanf("%d", &(endTime.minutes));
    printf("Seconds: ");
    scanf("%d", &(endTime.seconds));

    // Calculate the difference between the two time periods
    difference = calculateTimeDifference(startTime, endTime);

    // Output the difference
    printf("\nTime difference: %d hours, %d minutes, %d seconds\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}
