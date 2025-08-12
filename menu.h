#ifndef MENU_H
#define MENU_H

#include "raylib.h"

typedef enum {
    TELA_MENU,
    TELA_CREDITOS,
    TELA_JOGO,
    SAIR
} TelaAtual;

void RunMenu(TelaAtual *tela, Texture2D bgMenu, Texture2D bgJogar, Texture2D bgCreditos, Texture2D bgSair);
void RunCredits(TelaAtual *tela, Texture2D bgTelaCreditos, Texture2D bgTelaCreditosBotao);

#endif
