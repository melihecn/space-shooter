#pragma once 
#include "raylib.h"

class Ui
{
public:
    Ui();
    ~Ui();
    void Init();
    void Update();
    void Draw();
    void Unload();

    enum Screen { TITLE, GAME, OPTIONS };
    Screen currentScreen;

    void DrawTitleScreen();
    void DrawGameScreen();
    void DrawOptionsScreen();

private:

    Rectangle startButton;
    Rectangle optionsButton;
    Rectangle exitButton;

    Rectangle fullscreenToggle;
    Rectangle volumeSlider;
    Rectangle backButton;
    bool isFullscreen;
    float volume;
};
