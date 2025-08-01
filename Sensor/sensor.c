#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicializa os sensores com valores padrão
void inicializarSensores(struct Sensor sensores[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        sensores[i].id = i + 1;
        sensores[i].temperatura = 0.0;
        sensores[i].umidade = 0.0;
    }
}

// Simula a leitura de dados do sensor
void lerDadosSensor(struct Sensor *sensor) {
    sensor->temperatura = 20.0 + (rand() % 1000) / 100.0;  // Simula temperatura entre 20.0 e 30.0
    sensor->umidade = 50.0 + (rand() % 500) / 10.0;        // Simula umidade entre 50.0 e 100.0
}

// Exibe os dados de todos os sensores
void exibirDadosSensores(struct Sensor sensores[], int quantidade, float tempMin, float tempMax, float umidadeMin, float umidadeMax) {
    for (int i = 0; i < quantidade; i++) {
        printf("Sensor ID: %d\n", sensores[i].id);
        printf("Temperatura: %.2f °C\n", sensores[i].temperatura);
        printf("Umidade: %.2f %%\n", sensores[i].umidade);
        verificarCondicoesSensor(&sensores[i], tempMin, tempMax, umidadeMin, umidadeMax);
        printf("\n");
    }
}

// Função que verifica as condições dos sensores (temperatura e umidade)
void verificarCondicoesSensor(struct Sensor *sensor, float tempMin, float tempMax, float umidadeMin, float umidadeMax) {
    static int alertasTemperatura = 0;
    static int alertasUmidade = 0;

    // Verifica os limites de temperatura definidos pelo usuário
    if (sensor->temperatura > tempMax) {
        printf("Alerta: Temperatura alta no Sensor %d!\n", sensor->id);
        alertasTemperatura++;
    } else if (sensor->temperatura < tempMin) {
        printf("Alerta: Temperatura baixa no Sensor %d!\n", sensor->id);
        alertasTemperatura++;
    } else {
        printf("Temperatura estável no Sensor %d.\n", sensor->id);
    }

    // Verifica os limites de umidade definidos pelo usuário
    if (sensor->umidade > umidadeMax) {
        printf("Alerta: Umidade alta no Sensor %d!\n", sensor->id);
        alertasUmidade++;
    } else if (sensor->umidade < umidadeMin) {
        printf("Alerta: Umidade baixa no Sensor %d!\n", sensor->id);
        alertasUmidade++;
    } else {
        printf("Umidade estável no Sensor %d.\n", sensor->id);
    }

    // Exibe o total de alertas gerados até o momento
    printf("Total de alertas de temperatura: %d\n", alertasTemperatura);
    printf("Total de alertas de umidade: %d\n", alertasUmidade);
}

// Função para definir limites personalizados de temperatura e umidade
void definirLimites(float *tempMin, float *tempMax, float *umidadeMin, float *umidadeMax) {
    printf("Defina a temperatura mínima: ");
    scanf("%f", tempMin);
    printf("Defina a temperatura máxima: ");
    scanf("%f", tempMax);

    printf("Defina a umidade mínima: ");
    scanf("%f", umidadeMin);
    printf("Defina a umidade máxima: ");
    scanf("%f", umidadeMax);
}
