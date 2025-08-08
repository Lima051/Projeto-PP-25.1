#include "fruta.h"

// Tamanho fixo para a fruta
#define TAMANHO_FRUTA 20

// Definição da variável global 'fruta' que foi declarada como 'extern' no .h
Fruta fruta;

// Implementação da função para criar/reposicionar a fruta
void CriarFruta(int screenWidth, int screenHeight) {
    // Gera uma posição X aleatória dentro dos limites da tela
    // Subtraímos o tamanho para garantir que não apareça fora da borda
    fruta.rect.x = GetRandomValue(0, (screenWidth / TAMANHO_FRUTA) - 1) * TAMANHO_FRUTA;
    
    // Gera uma posição Y aleatória dentro dos limites da tela
    fruta.rect.y = GetRandomValue(0, (screenHeight / TAMANHO_FRUTA) - 1) * TAMANHO_FRUTA;

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
    DrawRectangleRec(fruta.rect, fruta.cor);
}