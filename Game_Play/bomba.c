#include "raylib.h"
#include "player.h"
#include "Tela/tamanhos.h"
#include "Mapa/Mapa_1.h"
#include "Mapa/Mapa_2.h"
#include "bomba.h"

// Tamanho fixo para a bomba
#define TAMANHO_BOMBA 20
Bomba bomba;

void CriarBomba(){
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
    bomba.rect.x = gridX * TAMANHO_BOMBA;
    bomba.rect.y = gridY * TAMANHO_BOMBA;

    // E definimos o resto das propriedades da coroa
    bomba.rect.width = TAMANHO_BOMBA;
    bomba.rect.height = TAMANHO_BOMBA;
    bomba.cor = BLACK;
}

void DesenharBomba(){
        DrawRectangleRec(bomba.rect, bomba.cor);

}
void ColisaoBomba() {
    int gridX = Player.corpo[0].x / tam_cobra;
    int gridY = Player.corpo[0].y / tam_cobra;

    if (bomba.rect.x == gridX * tam_cobra && bomba.rect.y == gridY * tam_cobra) {

        // A cobra caiu na bomba, então diminui o tamanho da cobra
        Player.tamanho--;
        
        // Reposiciona a bomba em uma nova posição
        CriarBomba();

        
    }
}





