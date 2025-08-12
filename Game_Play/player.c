#include "../raylib.h"
#include "player.h"
#include "../tela/tamanhos.h" 
#include "../Mapa/Mapa_1.h"
#include "../Mapa/Mapa_2.h"
#include "fruta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CarregarTexturas/loadtexturas.h"

void CriarCobra(int x, int y) {
    Player.inicio = (Vector2){x,y};
    Player.corpo[0] = Player.inicio;
    Player.tamanho = 4;
    Player.direcao = (Vector2){0,0};
    Player.velocidade = 0.30f;
    Player.intervaloMovimento = 0.0f;
    Player.textura_head=snake_head;
    Player.textura_body=snake_body;   
}

void UpdateCobra() {
    if (IsKeyPressed(KEY_UP) && !(Player.direcao.y > 0)) Player.direcao = (Vector2){0, -tam_cobra};
    if (IsKeyPressed(KEY_DOWN) && !(Player.direcao.y < 0)) Player.direcao = (Vector2){0, tam_cobra};
    if (IsKeyPressed(KEY_LEFT) && !(Player.direcao.x > 0)) Player.direcao = (Vector2){-tam_cobra, 0};
    if (IsKeyPressed(KEY_RIGHT) && !(Player.direcao.x < 0)) Player.direcao = (Vector2){tam_cobra, 0};

    Player.intervaloMovimento += GetFrameTime();

    if (Player.intervaloMovimento >= Player.velocidade) {
        Player.intervaloMovimento = 0.0f;

        for (int i = Player.tamanho - 1; i > 0; i--) {
            Player.corpo[i] = Player.corpo[i - 1];
        }

        Player.corpo[0].x += Player.direcao.x;
        Player.corpo[0].y += Player.direcao.y;

        if(faseAtual == 1) {
            Colisao();
        } else if (faseAtual == 2) {
            Colisao2();
        }
        ColisaoFruta();
    }
    DesenharFruta();
    
}

void DesenharCobra() {
    for(int i = Player.tamanho-1; i >=0; i--) {
        if (i!=0){
            DrawTextureEx(Player.textura_body, Player.corpo[i], 0.0f, 0.020f, WHITE);
        }
        else{
            DrawTextureEx(Player.textura_head, Player.corpo[i], 0.0f, 0.020f, WHITE);

        }
    }
}

