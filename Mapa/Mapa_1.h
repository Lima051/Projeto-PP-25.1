#ifndef WORLD
#define WORLD
#include "../Tela/tamanhos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../raylib.h"

extern int faseAtual;
extern int Mapa[tam_Grade][tam_Grade];

typedef struct {
    Texture2D chao;
    Texture2D parede;
} MapaTexturas1;

extern MapaTexturas1 mapaTx1;

void CarregarMapa1();
void DescarregarMapa1();
void VerificarColisao();
void Colisao();
void DesenharMapa();

#endif
