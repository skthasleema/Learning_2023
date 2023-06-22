#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100

// Structure to store log entry data
typedef struct {
    int entryNo;
    char sensorNo[3];
    float temperature;
    int humidity;
    int light;
    char time[9];
} LogEntry;

// Function to extract log entries from data.csv and store them in an array
int extractLogEntries(LogEntry logEntries[]) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    int entryCount = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (entryCount >= MAX_ENTRIES) {
            printf("Maximum number of entries exceeded.\n");
            break;
        }

        LogEntry entry;

        // Extracting data from the line
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,\n]", &entry.entryNo, entry.sensorNo,
               &entry.temperature, &entry.humidity, &entry.light, entry.time);

        logEntries[entryCount] = entry;
        entryCount++;
    }

    fclose(file);
    return entryCount;
}

// Function to display the log entry
void displayLogEntry(LogEntry entry) {
    printf("EntryNo: %d\n", entry.entryNo);
    printf("SensorNo: %s\n", entry.sensorNo);
    printf("Temperature: %.1f\n", entry.temperature);
    printf("Humidity: %d\n", entry.humidity);
    printf("Light: %d\n", entry.light);
    printf("Time: %s\n", entry.time);
    printf("------------------------------------\n");
}

// Function to display all log entries in the array
void displayLogEntries(LogEntry logEntries[], int count) {
    printf("Log Entries:\n");
    for (int i = 0; i < count; i++) {
        displayLogEntry(logEntries[i]);
    }
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int entryCount = extractLogEntries(logEntries);

    displayLogEntries(logEntries, entryCount);

    return 0;
}
