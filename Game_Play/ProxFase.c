#include "raylib.h"
#include "player.h"
#include "Tela/tamanhos.h"
#include "Mapa/Mapa_1.h"
#include "Mapa/Mapa_2.h"
#include "coroa.h"
#include "bomba.h"
#include "fruta.h"
#include "ProxFase.h"

#define TAMANHO 20

void DesenharPortal() {
    
    if(faseAtual == 1) {
        DrawRectangle((1 * TAMANHO), (39 * TAMANHO), TAMANHO, TAMANHO, RED);
        DrawRectangle((2 * TAMANHO), (39 * TAMANHO), TAMANHO, TAMANHO, RED);
        DrawRectangle((3 * TAMANHO), (39 * TAMANHO), TAMANHO, TAMANHO, RED);
    }
}

void ColisaoPortal() {
    int gridX = Player.corpo[0].x / tam_cobra;
    int gridY = Player.corpo[0].y / tam_cobra;
    
    if (gridY == 39 && (gridX == 1 || gridX == 2 || gridX == 3)) {
        
        faseAtual = 2;

        memset(Player.corpo, 0, sizeof(Player.corpo));

        CriarCobra(Player.inicio.x, Player.inicio.y);
        CriarBomba();
        CriarFruta();
    }
}