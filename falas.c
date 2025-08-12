#include "raylib.h"
#include <string.h>

void DesenharBalao(Texture2D balao){
    DrawTexture(balao, 0, 400, WHITE);
}

void Texto1(){
    const char *fala1 = "Meu duo de presas não está aqui.";
    DrawText(fala1, 85, 620, 20, WHITE);
}

void Texto2(){
    const char *fala2 = "Meu duo de presas não está aqui.\nPreciso rastejar por esse labirinto para achar meu parceiro de veneno.";
    DrawText(fala2, 85, 620, 20, WHITE);
}

void Texto3(){
    const char *fala3 = "Aí está você!";
    DrawText(fala3, 85, 620, 20, WHITE);
}

void Texto4(){
    const char *fala3 = "Aí está você!\nPensei que tinha perdido o rastro.";
    DrawText(fala3, 85, 620, 20, WHITE);
}
