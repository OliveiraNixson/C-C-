/******************************************************************************

Projeto: Monitoramento de Sensores com Limites Personalizados

Implemente um sistema de monitoramento de sensores que simule a leitura de dados de temperatura e umidade de um sensor. O sistema deve permitir configurar limites personalizados para esses parâmetros, monitorar continuamente os sensores e gerar alertas quando os valores estiverem fora dos limites estabelecidos.
Instruções:

    Inicialização: O programa começa inicializando os sensores com valores padrão e simula a leitura dos dados de temperatura e umidade.
    Definir Limites: O usuário pode definir limites personalizados para temperatura e umidade.
    Monitoramento Contínuo: O sistema monitora continuamente os sensores e exibe os dados coletados, alertando quando os valores estiverem fora dos limites definidos.
    Interação: Durante o monitoramento, o usuário pode:
        Sair do programa pressionando 's' ou 'S'.
        Redefinir os limites de temperatura e umidade pressionando 'c' ou 'C'.
        Continuar monitorando ao pressionar qualquer outra tecla.
    Alertas: O sistema exibirá alertas e contará quantos alertas de temperatura e umidade foram gerados durante o monitoramento.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sensor.h"

int main() {
    struct Sensor sensores[MAX_SENSORES];  // Vetor de sensores
    float tempMin = 10.0, tempMax = 40.0;  // Limites padrão de temperatura
    float umidadeMin = 30.0, umidadeMax = 80.0;  // Limites padrão de umidade

    // Inicializando os sensores
    inicializarSensores(sensores, MAX_SENSORES);

    srand(time(NULL));  // Inicializa o gerador de números aleatórios

    // Definir limites personalizados de temperatura e umidade antes de iniciar
    definirLimites(&tempMin, &tempMax, &umidadeMin, &umidadeMax);

    // Loop para leitura contínua e monitoramento dos sensores
    while (1) {
        // Ler e exibir os dados dos sensores
        for (int i = 0; i < MAX_SENSORES; i++) {
            lerDadosSensor(&sensores[i]);
        }
        
        // Exibir os dados dos sensores e verificar condições
        exibirDadosSensores(sensores, MAX_SENSORES, tempMin, tempMax, umidadeMin, umidadeMax);
        
        // Opções para o usuário continuar, reconfigurar ou sair
        printf("Pressione 's' para sair, 'c' para configurar limites ou qualquer outra tecla para continuar monitorando...\n");
        char c = getchar();
        if (c == 's' || c == 'S') {
            break;  // Sair do programa
        } else if (c == 'c' || c == 'C') {
            // Entrar no menu de configuração para redefinir os limites
            definirLimites(&tempMin, &tempMax, &umidadeMin, &umidadeMax);
            printf("Novos limites de temperatura e umidade definidos!\n");
        }
    }

    printf("Programa encerrado.\n");

    return 0;
}
