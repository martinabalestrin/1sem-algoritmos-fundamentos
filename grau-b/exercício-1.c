#include <stdio.h>
#include <stdlib.h>

typedef struct {

    float* readings;  // Array dinâmico para armazenar leituras de temperatura
    int size;         // Número de leituras atualmente no array
    int capacity;     // Capacidade total do array

} SensorData;

SensorData* createSensorData(int initialCapacity);

int addReading(SensorData* sensorData, float reading);

void freeSensorData(SensorData* sensorData);

int main() {

    SensorData* sensorData = createSensorData(2);
    float temp;

    do {
        printf("Temperatura (numero negativo para sair):\n");
        scanf("%f", &temp);

        if (temp < 0) {
            break;
        }

    } while(addReading(sensorData, temp) == 1);


        //addReading(sensorData, temp);

    printf("\n--- REGISTROS ---\n");

    for (int i = 0; i < sensorData->size; i++) {

        printf("Leitura %d: %.1f graus\n", i + 1, sensorData->readings[i]);
    }

    freeSensorData(sensorData);

    return 0;
}

SensorData* createSensorData(int initialCapacity) {

    SensorData* sensorData;

    sensorData = malloc(sizeof(SensorData));

    sensorData->readings = (float*)malloc(initialCapacity * sizeof(float));
    sensorData->size = 0;
    sensorData->capacity = initialCapacity;

    return sensorData;
}

int addReading(SensorData* sensorData, float reading) {

    int verificador = 0;

    if (sensorData->size >= sensorData->capacity) {

        // expande a capacidade em 50%
        sensorData->capacity =  sensorData->capacity * 1.5;
        sensorData->readings = (float*)realloc(sensorData->readings, sensorData->capacity * sizeof(float));

        verificador++;
    }

    sensorData->readings[sensorData->size] = reading;
    sensorData->size++;

    return verificador;
}

void freeSensorData(SensorData* sensorData) {

    if (sensorData->readings) {
        free(sensorData->readings);
    }

    free(sensorData);
}
