#ifndef COBRA2_H
#define COBRA2_H

#include "../raylib.h"
#include "../Audios/audios.h"

typedef struct Cobra2 {
    Rectangle rect; 
    Texture2D textura; // Adicionado para suportar imagem
    Color cor;
    bool colisao;
} Cobra2;

extern Cobra2 cobra2;

void CriarCobra2();
void DesenharCobra2();
int ColisaoCobra2(int fala);
void DescarregarCobra2();

#endif //COROA_H