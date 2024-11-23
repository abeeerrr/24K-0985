/*
Name/Roll Number: Abeer Fatima (24K-0985)

Q7: Create a program with a constant that defines the maximum allowable temperature (in
Celsius). Write a function to compare input temperatures and use a static variable to
count how many times temperatures exceeded the limit.

*/

#include <stdio.h>

#define MAX_TEMP 40


struct TemperatureData {
    int exceedCount; 
};

void compareTemperature(struct TemperatureData *data, int temp) {
    if (temp == -1) {
        return;  
    }

    if (temp > MAX_TEMP) {
        data->exceedCount++;  
        printf("Temperature %d°C exceeds the limit of %d°C!\n", temp, MAX_TEMP);
    } else {
        printf("Temperature %d°C is within the limit.\n", temp);
    }

   
    printf("Number of times the temperature exceeded the limit: %d\n", data->exceedCount);

    
    printf("Enter a temperature (in Celsius, or -1 to quit): ");
    scanf("%d", &temp);

    compareTemperature(data, temp);
}

int main() {
    struct TemperatureData data = {0}; 
    int temperature;

    printf("Enter a temperature (in Celsius, or -1 to quit): ");
    scanf("%d", &temperature);

    compareTemperature(&data, temperature);

    return 0;
}
