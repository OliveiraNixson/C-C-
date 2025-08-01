#ifndef SENSOR_H
#define SENSOR_H

#define MAX_SENSORES 2  // Número máximo de sensores

// Estrutura para armazenar os dados do sensor
struct Sensor {
    int id;
    float temperatura;
    float umidade;
};

// Função para inicializar os sensores
void inicializarSensores(struct Sensor sensores[], int quantidade);

// Função para simular a leitura dos dados do sensor
void lerDadosSensor(struct Sensor *sensor);

// Função para exibir os dados de todos os sensores
void exibirDadosSensores(struct Sensor sensores[], int quantidade, float tempMin, float tempMax, float umidadeMin, float umidadeMax);


// Função para verificar as condições dos sensores
void verificarCondicoesSensor(struct Sensor *sensor, float tempMin, float tempMax, float umidadeMin, float umidadeMax);

// Função para definir limites personalizados de temperatura e umidade
void definirLimites(float *tempMin, float *tempMax, float *umidadeMin, float *umidadeMax);

#endif
