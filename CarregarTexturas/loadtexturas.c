#include "raylib.h"
#include "CarregarTexturas/loadtexturas.h"

void Carregar(){

    apple=LoadTexture("imgs/apple.png");
    bush=LoadTexture("imgs/bush.png");
    crown=LoadTexture("imgs/crown.png");
    bombinha=LoadTexture("imgs/hole.png");
    menu=LoadTexture("imgs/menu.png");
    plano=LoadTexture("imgs/plano.png");
    snake_body=LoadTexture("imgs/snake_body.png");
    snake_head=LoadTexture("imgs/snake_head.png");
    
    // imagens usadas em menu e créditos
    Texture2D bgMenu = LoadTexture("imgs/menu.png");
    Texture2D bgJogar = LoadTexture("imgs/jogar.png");
    Texture2D bgCreditos = LoadTexture("imgs/creditos.png");
    Texture2D bgSair = LoadTexture("imgs/sair.png");
    Texture2D bgTelaCreditos = LoadTexture("imgs/tela_creditos.png");
    Texture2D bgTelaCreditosBotao = LoadTexture("imgs/tela_creditos_botao.png");
    Texture2D balao = LoadTexture("imgs/balao.png"); // balão de fala
}

void Descarregar(){

    UnloadTexture(apple);
    UnloadTexture(bush);
    UnloadTexture(crown);
    UnloadTexture(bombinha);
    UnloadTexture(menu);
    UnloadTexture(plano);
    UnloadTexture(snake_body);
    UnloadTexture(snake_head);
    
    // imagens usadas em menu e créditos
    UnloadTexture(bgMenu);
    UnloadTexture(bgJogar);
    UnloadTexture(bgCreditos);
    UnloadTexture(bgSair);
    UnloadTexture(bgTelaCreditos);
    UnloadTexture(bgTelaCreditosBotao);
    UnloadTexture(balao); // balão de fala

}
