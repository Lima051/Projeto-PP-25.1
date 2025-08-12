#include "raylib.h"
#include "menu.c"
#include "menu.h"
#include "Game_Play/player.c"
#include "Game_Play/player.h"
#include "Mapa/Mapa_1.c"
#include "Mapa/Mapa_1.h"
#include "Mapa/Mapa_2.c"
#include "Mapa/Mapa_2.h"
#include "Tela/tamanhos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Game_Play/fruta.h"
#include "Game_Play/fruta.c"
#include "Game_Play/coroa.h"
#include "Game_Play/coroa.c"
#include "Game_Play/bomba.h"
#include "Game_Play/bomba.c"
#include "Game_Play/ProxFase.h"
#include "Game_Play/ProxFase.c"
#include "Audios/audios.h"

int main() {

    InitWindow(S_l, S_a, "snakey labyrinth");
    InitAudioDevice();

    CarregarAudios();
    PlayMusicStream(ForestMusic);
    SetMusicVolume(ForestMusic, 0.5f);
    
    SetTargetFPS(30);
    CriarCobra(40, (S_a/2)+10);
    CriarCoroa();
    CriarBomba();
    CriarFruta(); 
    

    while (!WindowShouldClose()) {

        UpdateCobra();
        ColisaoBomba();
        ColisaoCoroa();
        ColisaoPortal();
        UpdateMusicStream(ForestMusic);

        BeginDrawing();
            ClearBackground(WHITE);

            if(faseAtual == 1) {
                DesenharMapa();
            } else if (faseAtual == 2) {
                DesenharMapa2();
            }
            DesenharCobra();
            DesenharFruta();
            DesenharCoroa();
            DesenharBomba();
        EndDrawing();

    }

    DescarregarAudios();
    CloseAudioDevice();
    CloseWindow();

    return 0;
}