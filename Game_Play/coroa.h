#ifndef COROA_H
#define COROA_H

#include "../raylib.h"
#include "../Audios/audios.h"

typedef struct Coroa {
    Rectangle rect; 
    Texture2D textura; // Adicionado para suportar imagem
    Color cor; 
    int colect;
    bool ativa;
    Sound Portal;
} Coroa;

extern Coroa coroa;

void CriarCoroa();
void DesenharCoroa();
void ColisaoCoroa();

#endif //COROA_H
