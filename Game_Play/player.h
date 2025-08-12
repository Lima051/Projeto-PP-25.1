#ifndef PLAYER
#define PLAYER
#include "../raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Audios/audios.h"

#define tamanho_maximo 100 //tamanho maximo da cobra

typedef struct Snake {
    
    Vector2 inicio;
    Vector2 corpo[tamanho_maximo];
    Vector2 direcao;
    Texture2D textura_head; // Adicionado para suportar imagem
    Texture2D textura_body; // Adicionado para suportar imagem
    int tamanho;
    float velocidade;
    float intervaloMovimento;
    Rectangle source;     // Retângulo de origem para a textura da cabeçaw

} Snake;

Snake Player;

void CriarCobra(int x, int y);
void UpdateCobra();
void DesenharCobra();

#endif