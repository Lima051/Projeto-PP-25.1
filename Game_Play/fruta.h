#ifndef FRUTA_H
#define FRUTA_H

#include "../raylib.h"
#include "../Audios/audios.h"

// Define a estrutura da nossa fruta
typedef struct Fruta {
    Rectangle rect; // Usamos o tipo 'Rectangle' da Raylib, que já tem posição (x, y) e tamanho (width, height)
    Texture2D textura;  // textura da bomba
    Sound EAT; // Som associado à fruta
} Fruta;

// Declara uma instância global da fruta, acessível em todo o projeto que incluir este .h
#define MAX_FRUTAS 20
extern Fruta fruta[MAX_FRUTAS];

// --- Protótipos das Funções ---
// Função para criar a fruta em uma posição aleatória
void CriarFruta();

void ReposicionarFruta(int i);

// Função para desenhar a fruta na tela
void DesenharFruta();

void ColisaoFruta();

#endif // FRUTA_H