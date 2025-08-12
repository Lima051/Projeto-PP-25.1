#include "raylib.h"
#include "audios.h"

void CarregarAudios() {

    Bomb = LoadSound("Audios/Efeitos/Bomb.mp3");
    Portal = LoadSound("Audios/Efeitos/Portal.mp3");
    EAT = LoadSound("Audios/Efeitos/EAT.mp3");
    ForestMusic = LoadMusicStream("Audios/Efeitos/Forest_Zone.mp3");

}

void DescarregarAudios() {

    UnloadSound(Bomb);
    UnloadSound(Portal);
    UnloadSound(EAT);
    UnloadMusicStream(ForestMusic);

}