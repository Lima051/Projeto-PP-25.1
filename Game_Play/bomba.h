#ifndef BOMBA_H
#define BOMBA_H

#include "../raylib.h"
#include "../Audios/audios.h"

typedef struct Bomba {
    Rectangle rect;     // posição e tamanho
    Texture2D textura;  // textura da bomba
    Sound Bomb;         // som associado à bomba
} Bomba;

#define MAX_BOMBA 20
extern Bomba bomba[MAX_BOMBA];

void CriarBomba();
void ReposicionarBomba(int i);
void DesenharBomba();
void ColisaoBomba();

#endif // BOMBA_H
