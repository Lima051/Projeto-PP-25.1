#include "raylib.h"
#include "player.h"
#include "Tela/tamanhos.h"
#include "Mapa/Mapa_1.h"
#include "Mapa/Mapa_2.h"
#include "coroa.h"
#include "bomba.h"
#include "fruta.h"
#include "ProxFase.h"

// Tamanho fixo para a coroa
#define TAMANHO_COROA 20
Coroa coroa;

void CriarCoroa() {
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
    coroa.rect.x = gridX * TAMANHO_COROA;
    coroa.rect.y = gridY * TAMANHO_COROA;

    // E definimos o resto das propriedades da coroa
    coroa.rect.width = TAMANHO_COROA;
    coroa.rect.height = TAMANHO_COROA;
    coroa.cor = GOLD;
    coroa.ativa = true; // A coroa começa ativa
    coroa.Portal = Portal;
}

// VERSÃO CORRETA
void DesenharCoroa() {
    // Apenas desenha a coroa SE ela estiver ativa
    if (coroa.ativa) {
        DrawRectangleRec(coroa.rect, coroa.cor);
    }
    else {
        DesenharPortal();
    }
}

void ColisaoCoroa() {
    // Só checa a colisão se a coroa ainda estiver ativa
    if (!coroa.ativa) {
        return; // Se já foi coletada, não faz mais nada.
    }

    int gridX = Player.corpo[0].x / tam_cobra;
    int gridY = Player.corpo[0].y / tam_cobra;

    if (coroa.rect.x == gridX * tam_cobra && coroa.rect.y == gridY * tam_cobra) {
        // Abre passagem para a próxima fase
        Mapa[38][1] = 0;
        Mapa[38][2] = 0;
        Mapa[38][3] = 0;
        coroa.ativa = false; // <-- ESTA É A MÁGICA! A coroa agora está "invisível".
        PlaySound(coroa.Portal); // Toca o som do portal
    }
}