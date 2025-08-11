#include "raylib.h"
#include "menu.c"
#include "menu.h"
#include "Game_Play/player.c"
#include "Game_Play/player.h"
#include "Mapa/Mapa_1.c"
#include "Mapa/Mapa_1.h"
#include "Tela/tamanhos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Game_Play/fruta.h"
#include "Game_Play/fruta.c"
#include "coroa.h"
#include "coroa.c"
#include "bomba.h"
#include "bomba.c"

int main() {

    InitWindow(S_l, S_a, "snakey labyrinth");
    SetTargetFPS(10);

    CriarCobra(40, (S_a/2)+10);
    CriarCoroa();

    CriarFruta(); // Cria a primeira fruta

    while (!WindowShouldClose()) {

        UpdateCobra();

        BeginDrawing();
            ClearBackground(BLACK);

            DesenharMapa();
            DesenharCobra();
            DesenharFruta();
            DesenharCoroa();
        EndDrawing();

    }

    CloseWindow();

    return 0;
}