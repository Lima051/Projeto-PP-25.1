#include "menu.h"
#include "raylib.h"

void RunMenu(TelaAtual *tela, Texture2D bgMenu, Texture2D bgJogar, Texture2D bgCreditos, Texture2D bgSair) {

    const int bottonWidht = 477;
    const int bottonHight = 85;

    Rectangle startBotton = {
        222,
        513,
        bottonWidht, bottonHight
    };
    Rectangle creditosBotton = {
        222,
        613,
        bottonWidht, bottonHight
    };
    
    Rectangle sairBotton = {
        222,
        713,
        bottonWidht, bottonHight
    };

    Vector2 mousePos = GetMousePosition();
    // JOGAR
    if (CheckCollisionPointRec(mousePos, startBotton)) {
        DrawTexture(bgJogar, 0, 0, WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) *tela = TELA_JOGO;
    // CREDITOS
    }else if (CheckCollisionPointRec(mousePos, creditosBotton)) {
        DrawTexture(bgCreditos, 0, 0, WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) *tela = TELA_CREDITOS;
    // SAIR
    } else if(CheckCollisionPointRec(mousePos, sairBotton)){
        DrawTexture(bgSair, 0, 0, WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) *tela = SAIR;
    } else{
        DrawTexture(bgMenu, 0, 0, WHITE);
    }
}

void RunCredits(TelaAtual *tela, Texture2D bgTelaCreditos, Texture2D bgTelaCreditosBotao) {
    int ScreenWidht = 920;

    Rectangle voltarBotton = { 21, 732, 275, 59 };

    Vector2 mousePos = GetMousePosition();

    // VOLTAR
    if (CheckCollisionPointRec(mousePos, voltarBotton)) {
        DrawTexture(bgTelaCreditosBotao, 0, 0, WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) *tela = TELA_MENU;
    } else {
        DrawTexture(bgTelaCreditos, 0, 0, WHITE);
    }

    // Texto de créditos
    const char *avll = "Anderson Lima - avll";
    const char *flo = "Felipe de Lima - flo";
    const char *rgaw = "Renata Gabrielle - rgaw";
    const char *rffn = "Ronald Nascimento - rffn";
    
    int avllWidth = MeasureText(avll, 20);
    int posX_avll = (ScreenWidht - avllWidth) / 2;
    
    int floWidth = MeasureText(flo, 20);
    int posX_flo = (ScreenWidht - floWidth) / 2;
    
    int rgawWidth = MeasureText(rgaw, 20);
    int posX_rgaw = (ScreenWidht - rgawWidth) / 2;
    
    int rffnWidth = MeasureText(rffn, 20);
    int posX_rffn = (ScreenWidht - rffnWidth) / 2;
    
    DrawText(avll, posX_avll, 352, 20, WHITE);
    DrawText(flo, posX_flo, 437, 20, WHITE);
    DrawText(rgaw, posX_rgaw, 522, 20, WHITE);
    DrawText(rffn, posX_rffn, 607, 20, WHITE);
}

