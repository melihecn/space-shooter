#pragma once 
#include "Common.h"

class Ui
{
public:
    Ui();
    ~Ui();
    void Init();
    void Update();
    void Draw();
    void Unload();

    bool shouldClose = false;

    enum Screen { TITLE, GAME, OPTIONS };
    Screen currentScreen;

    void DrawTitleScreen();
    void DrawGameScreen();
    void DrawOptionsScreen();

    void drawScore();

    int getScore();
    void setScore(int score);

private:
    Rectangle startButton;
    Rectangle optionsButton;
    Rectangle exitButton;

    Rectangle fullscreenToggle;
    Rectangle volumeSlider;
    Rectangle backButton;

    int score;
    bool isFullscreen;
    float volume;
    int fontSize;
};
