#ifndef COROA_H
#define COROA_H

#include "../raylib.h"

// Define a estrutura da nossa fruta
typedef struct Coroa {
    Rectangle rect; // Usamos o tipo 'Rectangle' da Raylib, que já tem posição (x, y) e tamanho (width, height)
    Color cor;
} Coroa;

extern Coroa coroa;
void CriarCoroa();
void DesenharCoroa();
void ColisaoCoroa();
#endif //COROA_H