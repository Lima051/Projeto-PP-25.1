#ifndef WORLD2
#define WORLD2
#include "../Tela/tamanhos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../raylib.h"

extern int faseAtual;
extern int Mapa2[tam_Grade][tam_Grade];

typedef struct {
    Texture2D chao;
    Texture2D parede;
} MapaTexturas2;

extern MapaTexturas2 mapaTx2;

void CarregarMapa2();
void DescarregarMapa2();
void VerificarColisao2();
void Colisao2();
void DesenharMapa2();

#endif
