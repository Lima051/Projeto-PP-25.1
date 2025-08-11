#include "fruta.h"
#include "raylib.h"
#include "player.h"
#include "Tela/tamanhos.h"
#include "Mapa/Mapa_1.h"

// Tamanho fixo para a fruta
#define TAMANHO_FRUTA 20

// Definição da variável global 'fruta' que foi declarada como 'extern' no .h
Fruta fruta;

// Implementação da função para criar/reposicionar a fruta
void CriarFruta() {
    // Gera uma posição X aleatória dentro dos limites do Mapa
    fruta.rect.x = GetRandomValue(0, (tam_Grade - 1)) * TAMANHO_FRUTA;
    
    // Gera uma posição Y aleatória dentro dos limites da tela
    fruta.rect.y = GetRandomValue(0, (tam_Grade - 1) ) * TAMANHO_FRUTA;
                    

    // Define o tamanho e a cor da fruta
    fruta.rect.width = TAMANHO_FRUTA;
    fruta.rect.height = TAMANHO_FRUTA;
    fruta.cor = RED; // Você pode escolher qualquer cor

    // Nota: A lógica "(screenWidth / TAMANHO_FRUTA) - 1" garante que a fruta
    // sempre apareça alinhada a uma grade, o que é comum em jogos de cobra.
    // Se quiser uma posição totalmente livre, use:
    // fruta.rect.x = GetRandomValue(0, screenWidth - fruta.rect.width);
    // fruta.rect.y = GetRandomValue(0, screenHeight - fruta.rect.height);
}

// Implementação da função para desenhar a fruta
void DesenharFruta() {
    // A função DrawRectangleRec é perfeita pois aceita diretamente um struct Rectangle
    if(Mapa[(int)fruta.rect.x][(int)fruta.rect.y ]!=1){
        DrawRectangleRec(fruta.rect, fruta.cor);
    }
    else{
        DesenharFruta();
    }
}

void ColisaoFruta() {
    int gridX = Player.corpo[0].x / tam_cobra;
    int gridY = Player.corpo[0].y / tam_cobra;

    if (fruta.rect.x == gridX * tam_cobra && fruta.rect.y == gridY * tam_cobra) {

        // A cobra comeu a fruta, então aumentamos o tamanho da cobra
        Player.tamanho++;
        
        // Reposiciona a fruta em uma nova posição
        CriarFruta();

        
    }
}