#include "raylib.h"
#include "player.h" // Incluído para a colisão
#include "cobra2.h" // Inclui o próprio header (boa prática)
#include "Tela/tamanhos.h" // Para tam_cobra

#define TAMANHO_SPRITE_COBRA2 40 // Usar um nome mais descritivo. Assumi 40 para bater com o tam_cobra.
Cobra2 cobra2;

void CriarCobra2() {
    // Posição em grade (grid) do mapa. (1, 2) significa coluna 1, linha 2.
    int gridX = 2;
    int gridY = 3;

    // Converte a posição da grade para pixels na tela
    cobra2.rect.x = gridX * tam_cobra; // Usar tam_cobra para alinhar com o grid do jogo
    cobra2.rect.y = gridY * tam_cobra;
    cobra2.rect.width = 2*tam_cobra;  // O tamanho da sprite será o mesmo de um bloco do grid
    cobra2.rect.height = 2*tam_cobra;
    cobra2.cor = WHITE;
    cobra2.colisao=false;
    
    // Carrega a textura da sprite
    // IMPORTANTE: Texturas devem ser carregadas APÓS InitWindow() e descarregadas antes de CloseWindow()
    cobra2.textura = LoadTexture("imgs/snake_head.png");
}

void DescarregarCobra2() {
    // Boa prática: sempre descarregar a textura quando não for mais necessária.
    UnloadTexture(cobra2.textura);
}

void DesenharCobra2() {
    
    // SOLUÇÃO: Usando DrawTexturePro para posicionar e redimensionar a sprite corretamente.
    DrawTexturePro(
        cobra2.textura, // A textura a ser usada
        (Rectangle){ 0, 0, cobra2.textura.width, cobra2.textura.height }, // Origem: A imagem inteira
        cobra2.rect,          // Destino: O retângulo com a POSIÇÃO e TAMANHO corretos na tela
        (Vector2){ 0, 0 },    // Ponto de origem para rotação (canto superior esquerdo)
        0.0f,                 // Rotação em graus
        WHITE                 // Cor (WHITE para não alterar a cor original)
    );
    
}

// Função de colisão (exemplo de implementação)
int ColisaoCobra2(int fala) {
 
    // Posição da cabeça do jogador em coordenadas de grade
    int playerGridX = Player.corpo[0].x / tam_cobra;
    int playerGridY = Player.corpo[0].y / tam_cobra;

    // Posição da Cobra2 em coordenadas de grade
    int cobra2GridX = cobra2.rect.x / tam_cobra;
    int cobra2GridY = cobra2.rect.y / tam_cobra;

    // Verifica se a cabeça do jogador está na mesma célula da Cobra2
    if (playerGridX == cobra2GridX && playerGridY == cobra2GridY) {
        fala=3;
        return fala;

    }
    else {
        return fala;
    }


}