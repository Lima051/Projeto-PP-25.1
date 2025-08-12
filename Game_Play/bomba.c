#include "raylib.h"
#include "player.h"
#include "Tela/tamanhos.h"
#include "Mapa/Mapa_1.h"
#include "Mapa/Mapa_2.h"
#include "bomba.h"

// Tamanho fixo para a bomba
#define TAMANHO_BOMBA 20

Bomba bomba[MAX_BOMBA];

void CriarBomba(){
    
    for(int i = 0; i < MAX_BOMBA; i++) {
        int gridX;
        int gridY;

        // Este loop continuará sorteando novas coordenadas
        // até encontrar uma que NÃO seja uma parede (valor 1).
        if(faseAtual == 1) {
            do {
                gridX = GetRandomValue(0, (tam_Grade - 1));
                gridY = GetRandomValue(0, (tam_GradeY - 3));
            } while (Mapa[gridY][gridX] == 1);
        } else if(faseAtual == 2) {
            do {
                gridX = GetRandomValue(0, (tam_Grade - 1));
                gridY = GetRandomValue(0, (tam_GradeY - 1));
            } while (Mapa2[gridY][gridX] == 1);
        }
        // Quando o código chega aqui, temos certeza de que a posição (gridX, gridY) é válida.

        // Agora, convertemos as coordenadas do grid para coordenadas de pixels
        bomba[i].rect.x = gridX * TAMANHO_BOMBA;
        bomba[i].rect.y = gridY * TAMANHO_BOMBA;

        // E definimos o resto das propriedades da coroa
        bomba[i].rect.width = TAMANHO_BOMBA;
        bomba[i].rect.height = TAMANHO_BOMBA;
        bomba[i].cor = BLACK;
        bomba[i].Bomb = Bomb;
    }
}

void ReposicionarBomba(int i) {
    int gridX, gridY;

    if (faseAtual == 1) {
        do {
            gridX = GetRandomValue(0, (tam_Grade - 1));
            gridY = GetRandomValue(0, (tam_GradeY - 3));
        } while (Mapa[gridY][gridX] == 1);
    } else if (faseAtual == 2) {
        do {
            gridX = GetRandomValue(0, (tam_Grade - 1));
            gridY = GetRandomValue(0, (tam_GradeY - 1));
        } while (Mapa2[gridY][gridX] == 1);
    }

    bomba[i].rect.x = gridX * TAMANHO_BOMBA;
    bomba[i].rect.y = gridY * TAMANHO_BOMBA;
    bomba[i].rect.width = TAMANHO_BOMBA;
    bomba[i].rect.height = TAMANHO_BOMBA;
    bomba[i].cor = BLACK;
    bomba[i].Bomb = Bomb;
}

void DesenharBomba(){
    for(int i = 0; i < MAX_BOMBA; i++) {
        DrawRectangleRec(bomba[i].rect, bomba[i].cor);
    }
}
void ColisaoBomba() {
    int gridX = Player.corpo[0].x / tam_cobra;
    int gridY = Player.corpo[0].y / tam_cobra;

    for(int i = 0; i < MAX_BOMBA; i++) {
        if (bomba[i].rect.x == gridX * tam_cobra && bomba[i].rect.y == gridY * tam_cobra) {

            // A cobra caiu na bomba, então diminui o tamanho da cobra
            Player.tamanho--;

            PlaySound(bomba[i].Bomb); // Toca o som da bomba
            // Reposiciona a bomba em uma nova posição
            
            ReposicionarBomba(i);

            
        }
    }
}





