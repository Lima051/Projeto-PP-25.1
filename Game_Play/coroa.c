#include "raylib.h"
#include "player.h"
#include "Tela/tamanhos.h"
#include "Mapa/Mapa_1.h"
#include "Mapa/Mapa_2.h"
#include "coroa.h"
#include "bomba.h"
#include "fruta.h"
#include "ProxFase.h"
#include "CarregarTexturas/loadtexturas.h"

#define TAMANHO_COROA 20
Coroa coroa;

void CriarCoroa() {
    int gridX;
    int gridY;

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

    coroa.rect.x = gridX * TAMANHO_COROA;
    coroa.rect.y = gridY * TAMANHO_COROA;
    coroa.rect.width = TAMANHO_COROA;
    coroa.rect.height = TAMANHO_COROA;
    coroa.cor = GOLD;
    coroa.ativa = true;
    coroa.Portal = Portal;

    // Carregar textura
    coroa.textura = LoadTexture("imgs/crown.png");
}

void DesenharCoroa() {
    if (coroa.ativa) {
        // Desenha usando textura em vez de cor sólida
        DrawTexturePro(
            coroa.textura,
            (Rectangle){0, 0, coroa.textura.width, coroa.textura.height},
            coroa.rect,
            (Vector2){0, 0},
            0.0f,
            WHITE
        );
    }
    else {
        
        DesenharPortal();
        ColisaoPortal();
    }
}

void ColisaoCoroa() {
    if (!coroa.ativa) {
        return;
    }

    int gridX = Player.corpo[0].x / tam_cobra;
    int gridY = Player.corpo[0].y / tam_cobra;

    if (coroa.rect.x == gridX * tam_cobra && coroa.rect.y == gridY * tam_cobra) {
        Mapa[38][1] = 0;
        Mapa[38][2] = 0;
        Mapa[38][3] = 0;
        coroa.ativa = false;
        PlaySound(coroa.Portal);
    }
}
