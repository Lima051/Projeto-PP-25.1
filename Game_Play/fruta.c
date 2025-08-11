#include "fruta.h"
#include "raylib.h"
#include "player.h"
#include "Tela/tamanhos.h"
#include "Mapa/Mapa_1.h"
#include "Mapa/Mapa_2.h"

// Tamanho fixo para a fruta
#define TAMANHO_FRUTA 20

// Definição da variável global 'fruta' que foi declarada como 'extern' no .h
Fruta fruta;

// Implementação da função para criar/reposicionar a fruta
void CriarFruta(){
    int gridX;
    int gridY;

    // Este loop continuará sorteando novas coordenadas
    // até encontrar uma que NÃO seja uma parede (valor 1).
    if(faseAtual == 1) {
        do {
            gridX = GetRandomValue(0, (tam_Grade - 1));
            gridY = GetRandomValue(0, (tam_GradeY - 3));
        } while (Mapa[gridY][gridX] != 0);
    } else if(faseAtual == 2) {
        do {
            gridX = GetRandomValue(0, (tam_Grade - 1));
            gridY = GetRandomValue(0, (tam_GradeY - 1));
        } while (Mapa2[gridY][gridX] != 0);
    }
    // Quando o código chega aqui, temos certeza de que a posição (gridX, gridY) é válida.

    // Agora, convertemos as coordenadas do grid para coordenadas de pixels
    fruta.rect.x = gridX * TAMANHO_FRUTA;
    fruta.rect.y = gridY * TAMANHO_FRUTA;

    // E definimos o resto das propriedades da coroa
    fruta.rect.width = TAMANHO_FRUTA;
    fruta.rect.height = TAMANHO_FRUTA;
    fruta.cor = RED;
}
// Implementação da função para desenhar a fruta
void DesenharFruta() {

        DrawRectangleRec(fruta.rect, fruta.cor);
}

void ColisaoFruta() {
    int gridX = Player.corpo[0].x / tam_cobra;
    int gridY = Player.corpo[0].y / tam_cobra;

    if (fruta.rect.x == gridX * tam_cobra && fruta.rect.y == gridY * tam_cobra) {

        // A cobra comeu a fruta, então aumentamos o tamanho da cobra
        Player.tamanho++;
        
        // Reposiciona a fruta em uma nova posição
        CriarFruta();

        
    }
}