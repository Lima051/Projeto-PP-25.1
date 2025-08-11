#ifndef FRUTA_H
#define FRUTA_H

#include "../raylib.h"

// Define a estrutura da nossa fruta
typedef struct Fruta {
    Rectangle rect; // Usamos o tipo 'Rectangle' da Raylib, que já tem posição (x, y) e tamanho (width, height)
    Color cor;
} Fruta;

// Declara uma instância global da fruta, acessível em todo o projeto que incluir este .h
extern Fruta fruta;

// --- Protótipos das Funções ---
// Função para criar a fruta em uma posição aleatória
void CriarFruta();

// Função para desenhar a fruta na tela
void DesenharFruta();

void ColisaoFruta();

#endif // FRUTA_H