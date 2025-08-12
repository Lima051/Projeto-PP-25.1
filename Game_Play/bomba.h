#ifndef BOMBA_H
#define BOMBA_H

#include "../raylib.h"
#include "../Audios/audios.h"

// Define a estrutura da nossa fruta
typedef struct Bomba {
    Rectangle rect; // Usamos o tipo 'Rectangle' da Raylib, que já tem posição (x, y) e tamanho (width, height)
    Color cor;
    Sound Bomb; // Som associado à bomba
} Bomba;

#define MAX_BOMBA 20
extern Bomba bomba[MAX_BOMBA];

void CriarBomba();
void DesenharBomba();
void ColisaoBomba();
#endif //BOMBA_H