#include "raylib.h"
#include "player.h"
#include "Tela/tamanhos.h"
#include "Mapa/Mapa_1.h"
#include "bomba.h"

// Tamanho fixo para a bomba
#define TAMANHO_BOMBA 20
Bomba bomba;

void CriarBomba(){
    bomba.rect.x=GetRandomValue(0, (tam_Grade - 1)) * TAMANHO_BOMBA;
    bomba.rect.y=GetRandomValue(0, (tam_Grade - 1)) * TAMANHO_BOMBA;
    

    // Define o tamanho e a cor da bomba
    bomba.rect.width = TAMANHO_BOMBA;
    bomba.rect.height = TAMANHO_BOMBA;
    bomba.cor = BLACK; // Você pode escolher qualquer cor
}

void DesenharBomba(){

    if(Mapa[(int)bomba.rect.x][(int)bomba.rect.y ]!=1){
        DrawRectangleRec(bomba.rect, bomba.cor);
    }
    else{
        DesenharBomba();
    }
}
void ColisaoBomba() {
    int gridX = Player.corpo[0].x / tam_cobra;
    int gridY = Player.corpo[0].y / tam_cobra;

    if (bomba.rect.x == gridX * tam_cobra && bomba.rect.y == gridY * tam_cobra) {

        // A cobra caiu na bomba, então diminui o tamanho da cobra
        Player.tamanho--;
        
        // Reposiciona a bomba em uma nova posição
        CriarBomba();

        
    }
}





