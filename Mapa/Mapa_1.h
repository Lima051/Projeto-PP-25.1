#ifndef WORLD
#define WORLD
#include "../Tela/tamanhos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Mapa {
    Rectangle rect; 
    Texture2D textura; // Adicionado para suportar imagem
    Vector2 pos;

} Mapa_STRUCT;
extern Mapa_STRUCT mapa[tam_Grade][tam_Grade];
extern int faseAtual;

void VerificarColisao();
void Colisao();
void DesenharMapa();
int Mapa[tam_Grade][tam_Grade];
#endif
