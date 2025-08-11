#ifndef BOMBA_H
#define BOMBA_H

#include "../raylib.h"

// Define a estrutura da nossa fruta
typedef struct Bomba {
    Rectangle rect; // Usamos o tipo 'Rectangle' da Raylib, que já tem posição (x, y) e tamanho (width, height)
    Color cor;
} Bomba;

extern Bomba bomba;
void CriarBomba();
void DesenharBomba();
void ColisaoBomba();
#endif //BOMBA_H