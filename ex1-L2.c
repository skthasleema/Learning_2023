#include <stdio.h>
#include <string.h>

#define MAX_SENSORS 10
#define MAX_DATA_LENGTH 100

typedef struct {
    char sensorID[10];
    float temperature;
    int humidity;
    int lightIntensity;
} Sensor;

void populateSensorData(char* data, Sensor* sensors, int* numSensors) {
    char* token;
    char* delimiter = "-: ";
    int sensorIndex = 0;

    // Parse the data and populate the sensor structure array
    token = strtok(data, delimiter);
    while (token != NULL) {
        if (strcmp(token, "S") == 0) {
            token = strtok(NULL, delimiter);
            strcpy(sensors[sensorIndex].sensorID, token);
        } else if (strcmp(token, "T") == 0) {
            token = strtok(NULL, delimiter);
            sensors[sensorIndex].temperature = atof(token);
        } else if (strcmp(token, "H") == 0) {
            token = strtok(NULL, delimiter);
            sensors[sensorIndex].humidity = atoi(token);
        } else if (strcmp(token, "L") == 0) {
            token = strtok(NULL, delimiter);
            sensors[sensorIndex].lightIntensity = atoi(token);
            sensorIndex++;
        }
        token = strtok(NULL, delimiter);
    }

    *numSensors = sensorIndex;
}

void displaySensorInfo(Sensor* sensors, int numSensors) {
    printf("Sensor Info:\n");
    printf("---------------------\n");
    for (int i = 0; i < numSensors; i++) {
        printf("Sensor ID: %s\n", sensors[i].sensorID);
        printf("Temperature: %.1f C\n", sensors[i].temperature);
        printf("Humidity: %d\n", sensors[i].humidity);
        printf("Light Intensity: %d%%\n", sensors[i].lightIntensity);
        printf("---------------------\n");
    }
}

int main() {
    char data[MAX_DATA_LENGTH];
    Sensor sensors[MAX_SENSORS];
    int numSensors = 0;

    printf("Enter the data: ");
    fgets(data, MAX_DATA_LENGTH, stdin);
    data[strcspn(data, "\n")] = '\0'; // Remove trailing newline character

    populateSensorData(data, sensors, &numSensors);
    displaySensorInfo(sensors, numSensors);

    return 0;
}
