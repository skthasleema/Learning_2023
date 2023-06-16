#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct my_date_t {
    uint8_t date;   // day
    uint8_t month;  // month
    uint16_t year;  // year
} my_date_t;

typedef enum status_t {
    SUCCESS,    // Function has successfully converted the string to structure
    NULL_PTR,   // Function is given NULL pointers to work with
    INCORRECT   // Incorrect values for date or month or year
} status_t;

status_t string_to_date_converter(char* input_string, my_date_t* result_date) {
    if (input_string == NULL || result_date == NULL) {
        return NULL_PTR;
    }

    // Ensure the input string length is correct (10 characters including '\0')
    if (strlen(input_string) != 10) {
        return INCORRECT;
    }

    // Extract day, month, and year from the input string
    char day_str[3];
    char month_str[3];
    char year_str[5];

    strncpy(day_str, input_string, 2);
    day_str[2] = '\0';
    strncpy(month_str, input_string + 3, 2);
    month_str[2] = '\0';
    strncpy(year_str, input_string + 6, 4);
    year_str[4] = '\0';

    // Convert day, month, and year strings to integers
    int day = atoi(day_str);
    int month = atoi(month_str);
    int year = atoi(year_str);

    // Validate the converted values
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
        return INCORRECT;
    }

    // Populate the result_date structure
    result_date->date = (uint8_t)day;
    result_date->month = (uint8_t)month;
    result_date->year = (uint16_t)year;

    return SUCCESS;
}

int main() {
    char input_string[] = "15/06/2023";
    my_date_t result_date;

    status_t conversion_status = string_to_date_converter(input_string, &result_date);

    if (conversion_status == SUCCESS) {
        printf("Conversion successful. Resultant date: %02d/%02d/%04d\n",
               result_date.date, result_date.month, result_date.year);
    } else if (conversion_status == NULL_PTR) {
        printf("Error: NULL pointers provided.\n");
    } else if (conversion_status == INCORRECT) {
        printf("Error: Incorrect format or values in the input string.\n");
    }

    return 0;
}