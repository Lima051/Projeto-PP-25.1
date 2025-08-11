#include "raylib.h"
#include "CarregarTexturas/loadtexturas.h"

void Carregar(){

    apple=LoadTexture("imgs/apple.png");
    bush=LoadTexture("imgs/bush.png");
    crown=LoadTexture("imgs/crown.png");
    bomba=LoadTexture("imgs/hole.png");
    menu=LoadTexture("imgs/menu.png");
    plano=LoadTexture("imgs/plano.png");
    snake_body=LoadTexture("imgs/snake_body.png");
    snake_head=LoadTexture("imgs/snake_head.png");
}

void Descarregar(){


    UnloadTexture(apple);
    UnloadTexture(bush);
    UnloadTexture(crown);
    UnloadTexture(bomba);
    UnloadTexture(menu);
    UnloadTexture(plano);
    UnloadTexture(snake_body);
    UnloadTexture(snake_head);

}