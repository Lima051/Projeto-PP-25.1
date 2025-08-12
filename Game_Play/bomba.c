#include "raylib.h"
#include "player.h"
#include "Tela/tamanhos.h"
#include "Mapa/Mapa_1.h"
#include "Mapa/Mapa_2.h"
#include "bomba.h"
#include "CarregarTexturas/loadtexturas.h"

#define TAMANHO_BOMBA 20

Bomba bomba[MAX_BOMBA];

void CriarBomba() {
    for (int i = 0; i < MAX_BOMBA; i++) {
        int gridX, gridY;

        if (faseAtual == 1) {
            do {
                gridX = GetRandomValue(0, (tam_Grade - 1));
                gridY = GetRandomValue(0, (tam_GradeY - 3));
            } while (Mapa[gridY][gridX] == 1);
        } 
        else if (faseAtual == 2) {
            do {
                gridX = GetRandomValue(0, (tam_Grade - 1));
                gridY = GetRandomValue(0, (tam_GradeY - 1));
            } while (Mapa2[gridY][gridX] == 1);
        }

        bomba[i].rect.x = gridX * TAMANHO_BOMBA;
        bomba[i].rect.y = gridY * TAMANHO_BOMBA;
        bomba[i].rect.width  = TAMANHO_BOMBA;
        bomba[i].rect.height = TAMANHO_BOMBA;

        bomba[i].textura = LoadTexture("imgs/hole.png");
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
    } 
    else if (faseAtual == 2) {
        do {
            gridX = GetRandomValue(0, (tam_Grade - 1));
            gridY = GetRandomValue(0, (tam_GradeY - 1));
        } while (Mapa2[gridY][gridX] == 1);
    }

    bomba[i].rect.x = gridX * TAMANHO_BOMBA;
    bomba[i].rect.y = gridY * TAMANHO_BOMBA;
    bomba[i].rect.width  = TAMANHO_BOMBA;
    bomba[i].rect.height = TAMANHO_BOMBA;
}

void DesenharBomba() {
    for (int i = 0; i < MAX_BOMBA; i++) {
        DrawTexturePro(
            bomba[i].textura,
            (Rectangle){0, 0, bomba[i].textura.width, bomba[i].textura.height},
            bomba[i].rect,
            (Vector2){0, 0},
            0.0f,
            WHITE
        );
    }
}

void ColisaoBomba() {
    int gridX = Player.corpo[0].x / tam_cobra;
    int gridY = Player.corpo[0].y / tam_cobra;

    for (int i = 0; i < MAX_BOMBA; i++) {
        if (bomba[i].rect.x == gridX * tam_cobra &&
            bomba[i].rect.y == gridY * tam_cobra) {

            Player.tamanho--;
            PlaySound(bomba[i].Bomb);
            ReposicionarBomba(i);
        }
    }
}
