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
    int tamanho;
    float velocidade;
    float intervaloMovimento;

} Snake;

Snake Player;

void CriarCobra(int x, int y);
void UpdateCobra();
void DesenharCobra();

#endif