#include "raylib.h"
#include "player.h"
#include "Tela/tamanhos.h"
#include "Mapa/Mapa_1.h"
#include "coroa.h"

// Tamanho fixo para a coroa
#define TAMANHO_COROA 20
Coroa coroa;

void CriarCoroa(){

    coroa.rect.x=GetRandomValue(0, (tam_Grade - 1)) * TAMANHO_COROA;
    coroa.rect.y=GetRandomValue(0, (tam_Grade - 1)) * TAMANHO_COROA;

    // Define o tamanho e a cor da coroa
    coroa.rect.width = TAMANHO_COROA;
    coroa.rect.height = TAMANHO_COROA;
    coroa.cor = GOLD; // Você pode escolher qualquer cor


}

void DesenharCoroa(){
        if(Mapa[(int)coroa.rect.x][(int)coroa.rect.y ]!=1){
        DrawRectangleRec(coroa.rect, coroa.cor);
    }
    else{
        DesenharCoroa();
    }
}

void ColisaoCoroa(){
    int gridX = Player.corpo[0].x / tam_cobra;
    int gridY = Player.corpo[0].y / tam_cobra;
        //Tamanho da cobra=7 significa que a cobra comeu 3 frutas  em seguida sem resetar
        if (coroa.rect.x == gridX * tam_cobra && coroa.rect.y == gridY * tam_cobra && Player.tamanho==7) {
            //Abre passagem para a próxima fase
                Mapa[44][43]=0;
                Mapa[44][42]=0;


        }

}