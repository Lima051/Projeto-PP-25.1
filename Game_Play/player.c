#include "../raylib.h"
#include "player.h"
#include "../tela/tamanhos.h" 
#include "../Mapa/Mapa_1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CriarCobra(int x, int y) {
    Player.inicio = (Vector2){x,y};
    Player.corpo[0] = Player.inicio;
    Player.tamanho = 4;
    Player.direcao = (Vector2){0,0};
    
}

void UpdateCobra() {
    if (IsKeyPressed(KEY_UP) && !(Player.direcao.y > 0)) Player.direcao = (Vector2){0, -tam_cobra};
    if (IsKeyPressed(KEY_DOWN) && !(Player.direcao.y < 0)) Player.direcao = (Vector2){0, tam_cobra};
    if (IsKeyPressed(KEY_LEFT) && !(Player.direcao.x > 0)) Player.direcao = (Vector2){-tam_cobra, 0};
    if (IsKeyPressed(KEY_RIGHT) && !(Player.direcao.x < 0)) Player.direcao = (Vector2){tam_cobra, 0};

    for (int i = Player.tamanho - 1; i > 0; i--) {
        Player.corpo[i] = Player.corpo[i - 1];
    }

    Player.corpo[0].x += Player.direcao.x;
    Player.corpo[0].y += Player.direcao.y;

    Colisao();
    
}

void DesenharCobra() {
    for(int i = 0; i < Player.tamanho; i++) {
        DrawRectangleV(Player.corpo[i], (Vector2){tam_cobra, tam_cobra}, GREEN);
    }
}



