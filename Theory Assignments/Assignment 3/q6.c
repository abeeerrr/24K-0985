/* Name/Roll Number: Abeer Fatima (24K-0985)
q6: In a cutting-edge agritech system for precision farming, a dynamic pointer-based architecture is
deployed to seamlessly manage interconnected data across fields, crops, weather, and smart
equipment. Each field is represented as a structure containing GPS coordinates, soil health metrics,
and moisture levels, alongside a pointer to a dynamically allocated array of crop structures. These
crop structures store critical details like crop type, growth stage, and expected yield while
maintaining pointers to weather forecast structures that provide hyper-local predictions for
temperature, rainfall, and wind patterns.
The field structure also includes a pointer to an equipment array, representing key farming tools
like autonomous tractors, irrigation systems, and drones. Each equipment structure tracks
operational status, fuel levels, and activity schedules, enabling synchronized field operations. In
addition, an array of sensor structures is linked to each field, capturing real-time data on soil
nutrients, pH levels, and pest activity, empowering farmers to make informed decisions.
To scale operations, fields are grouped into regional hubs, each represented by a structure with
pointers to arrays of fields. These hubs maintain aggregate data like yield predictions, resource
distribution, and emergency response plans. All regional hubs are connected to a central analytics
server through pointers, allowing AI algorithms to process massive datasets and generate real-time
insights on crop health, irrigation efficiency, and equipment optimization.
This system’s dynamic design ensures that every byte of memory is utilized efficiently, enabling
rapid scaling and adaptation to environmental conditions. By leveraging advanced pointer
structures, the agritech platform offers farmers a futuristic, data-driven farming experience that
maximizes yield, minimizes waste, and supports sustainable agricultural practices.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float temperature;
    float rainfall;
    float windSpeed;
} WeatherForecast;

typedef struct {
    char cropType[50];
    char growthStage[50];
    float expectedYield;
    WeatherForecast *weather;
} Crop;

typedef struct {
    char equipmentName[30];
    char operationalStatus[10];
    float fuelLevel;
    char schedule[50];
} Equipment;

typedef struct {
    char parameter[30];
    float value;
} Sensor;

typedef struct {
    float latitude, longitude; 
    float soilHealth;
    float moistureLevel;
    Crop *crops;
    int numCrops;
    Equipment *equipment;
    int numEquipment;
    Sensor *sensors;
    int numSensors;
} Field;

typedef struct {
    Field *fields;
    int numFields;
} RegionalHub;

Field initializeField(int numCrops, int numEquipment, int numSensors) {
    Field field;
    field.crops = (Crop *)malloc(numCrops * sizeof(Crop));
    field.numCrops = numCrops;
    field.equipment = (Equipment *)malloc(numEquipment * sizeof(Equipment));
    field.numEquipment = numEquipment;
    field.sensors = (Sensor *)malloc(numSensors * sizeof(Sensor));
    field.numSensors = numSensors;

    printf("take the latitude and longitude for the field: ");
    scanf("%f %f", &field.latitude, &field.longitude);
    printf("Enter soil health and moisture level: ");
    scanf("%f %f", &field.soilHealth, &field.moistureLevel);

    for (int i = 0; i < numCrops; i++) {
        printf("take the crop type, growth stage, and expected yield for Crop %d: ", i + 1);
        scanf("%s %s %f", field.crops[i].cropType, field.crops[i].growthStage, &field.crops[i].expectedYield);

        field.crops[i].weather = (WeatherForecast *)malloc(sizeof(WeatherForecast));
        printf("take the temperature, rainfall, and wind speed for Crop %d: ", i + 1);
        scanf("%f %f %f", &field.crops[i].weather->temperature, &field.crops[i].weather->rainfall, &field.crops[i].weather->windSpeed);
    }

    for (int i = 0; i < numEquipment; i++) {
        printf("take the name, operational status, fuel level, and schedule for Equipment %d: ", i + 1);
        scanf("%s %s %f %s", field.equipment[i].equipmentName, field.equipment[i].operationalStatus, &field.equipment[i].fuelLevel, field.equipment[i].schedule);
    }

    for (int i = 0; i < numSensors; i++) {
        printf("take the sensor parameter and value for Sensor %d: ", i + 1);
        scanf("%s %f", field.sensors[i].parameter, &field.sensors[i].value);
    }

    return field;
}

void displayField(Field field) {
    printf("\n--- Field Details ---\n");
    printf("Location: (%.2f, %.2f)\n", field.latitude, field.longitude);
    printf("Soil Health: %.2f, Moisture Level: %.2f\n", field.soilHealth, field.moistureLevel);

    printf("Crops:\n");
    for (int i = 0; i < field.numCrops; i++) {
        printf("  Crop %d: %s, Stage: %s, Expected Yield: %.2f\n", i + 1, field.crops[i].cropType, field.crops[i].growthStage, field.crops[i].expectedYield);
        printf("    Weather: Temperature: %.2f, Rainfall: %.2f, Wind Speed: %.2f\n",
               field.crops[i].weather->temperature, field.crops[i].weather->rainfall, field.crops[i].weather->windSpeed);
    }

    printf("Equipment:\n");
    for (int i = 0; i < field.numEquipment; i++) {
        printf("  Equipment %d: %s, Status: %s, Fuel: %.2f, Schedule: %s\n", i + 1,
               field.equipment[i].equipmentName, field.equipment[i].operationalStatus, field.equipment[i].fuelLevel, field.equipment[i].schedule);
    }

    printf("Sensors:\n");
    for (int i = 0; i < field.numSensors; i++) {
        printf("  Sensor %d: %s, Value: %.2f\n", i + 1, field.sensors[i].parameter, field.sensors[i].value);
    }
}

void freeField(Field *field) {
    for (int i = 0; i < field->numCrops; i++) {
        free(field->crops[i].weather); 
    }
    free(field->crops);
    free(field->equipment);
    free(field->sensors);
}

int main() {
    int numFields;

    printf("take the number of fields in the regional hub: ");
    scanf("%d", &numFields);

    RegionalHub hub;
    hub.numFields = numFields;
    hub.fields = (Field *)malloc(numFields * sizeof(Field));

    for (int i = 0; i < numFields; i++) {
        printf("\nInitializing Field %d...\n", i + 1);
        hub.fields[i] = initializeField(2, 2, 2); 
    }

    for (int i = 0; i < numFields; i++) {
        displayField(hub.fields[i]);
    }

    for (int i = 0; i < numFields; i++) {
        freeField(&hub.fields[i]);
    }
    free(hub.fields);

    return 0;
}
