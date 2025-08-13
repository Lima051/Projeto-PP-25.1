#include "raylib.h"
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
#include "falas.h"
#include "Game_Play/cobra2.h"
#include "Game_Play/cobra2.c"

int main() {

    InitWindow(S_l, S_a, "snakey labyrinth");
    InitAudioDevice();
    
    Carregar();
    CarregarAudios();
    CarregarMapa1();
    CarregarMapa2();
    PlayMusicStream(ForestMusic);
    SetMusicVolume(ForestMusic, 0.5f);
    
    SetTargetFPS(30);
    CriarCobra(40, (S_a/2)+10);
    CriarCoroa();
    CriarBomba();
    CriarFruta();
    CriarCobra2();
    
    
    int sair = 1; // sair=0 fecha o jogo
    int fala = 1; // controla a exibição de falas

    TelaAtual tela = TELA_MENU; // controla a tela
    
    while (!WindowShouldClose() && sair) {

        UpdateCobra();
        ColisaoBomba();
        ColisaoCoroa();
        UpdateMusicStream(ForestMusic);

        BeginDrawing();
            ClearBackground(WHITE);
            
            switch(tela){
                case TELA_MENU:
                    RunMenu(&tela, bgMenu, bgJogar, bgCreditos, bgSair);
                break;
                case TELA_CREDITOS:
                    RunCredits(&tela, bgTelaCreditos, bgTelaCreditosBotao);
                break;
                case TELA_JOGO:
                    // Desenha mapa da fase atual
                    if (faseAtual == 1) {
                        DesenharMapa();  
                        UpdateMusicStream(ForestMusic);
  
                
                    }

                    if (faseAtual == 2){


                        UpdateMusicStream(ForestMusic);
                        DesenharMapa2();
                        DesenharCobra2();
                        fala=ColisaoCobra2(fala);

                        DescarregarMapa1();

                    } 

                    // Atualiza só se não houver fala
                    if (fala == 0) {
                        UpdateCobra();
                        ColisaoBomba();
                        ColisaoCoroa();
                    }

                    // Desenha elementos comuns

                    DesenharCobra();
                    DesenharFruta();
                    DesenharCoroa();
                    DesenharBomba();

                    // Controle de falas
                    if (faseAtual == 1) {
                        if (fala == 1) {
                            DesenharBalao(balao);
                            Texto1();
                            if (IsKeyPressed(KEY_ENTER)) fala = 2;
                        } else if (fala == 2) {
                            DesenharBalao(balao);
                            Texto2();
                            if (IsKeyPressed(KEY_ENTER)) fala = 0; // libera jogo
                        }
                    } else if (faseAtual == 2) {
    
                        if (fala == 3) {
                            DesenharBalao(balao);
                            Texto3();
                            if (IsKeyPressed(KEY_ENTER)) fala = 4;
                        } else if (fala == 4) {
                            DesenharBalao(balao);
                            Texto4();
                            if (IsKeyPressed(KEY_ENTER)) {
                                fala = 0;
                                tela = SAIR;
                            }
                        }
                    }
                break;
                case SAIR:
                    sair = 0;
                break;
            }
        EndDrawing();
    }
    
    Descarregar();
    DescarregarMapa2();
    DescarregarAudios();
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
