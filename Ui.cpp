#include "Ui.h"
#include <iostream>

Ui::Ui() : currentScreen(TITLE), isFullscreen(false), volume(0.5f) {}

Ui::~Ui() {}

void Ui::Init()
{
    startButton = {350, 200, 200, 100 };
    optionsButton = { 350, 400, 200, 100 };
    exitButton = { 350, 600, 200, 100 };
    fullscreenToggle = { 350, 200, 100, 50 };
    volumeSlider = { 350, 300, 200, 20 };
    backButton = { 350, 400, 100, 50 };

    score = 0;
    fontSize = 30;
}

void Ui::Update()
{
    switch (currentScreen) {
        case TITLE:
            if (CheckCollisionPointRec(GetMousePosition(), startButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentScreen = GAME;
            }
            if (CheckCollisionPointRec(GetMousePosition(), optionsButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentScreen = OPTIONS;
            }
            if (CheckCollisionPointRec(GetMousePosition(), exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                
                shouldClose = true;
                break;
            }
            break;
        case GAME:
            if (IsKeyPressed(KEY_ESCAPE)) {
                currentScreen = OPTIONS;
            }
        case OPTIONS:
            if (CheckCollisionPointRec(GetMousePosition(), fullscreenToggle) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                isFullscreen = !isFullscreen;
                ToggleFullscreen();
            }
            if (CheckCollisionPointRec(GetMousePosition(), volumeSlider) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                volume = (GetMouseX() - volumeSlider.x) / volumeSlider.width;
                if (volume < 0.0f) volume = 0.0f;
                if (volume > 1.0f) volume = 1.0f;
                SetMasterVolume(volume);
            }
            if (CheckCollisionPointRec(GetMousePosition(), backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentScreen = TITLE;
            }
            break;
    }
}

void Ui::Draw()
{
    switch (currentScreen) {
        case TITLE:
            DrawTitleScreen();
            break;
        case GAME:
            DrawGameScreen();
            break;
        case OPTIONS:
            DrawOptionsScreen();
            break;
    }
}

void Ui::Unload()
{
    // Unload resources if any
}

void Ui::DrawTitleScreen()
{
    DrawText("Title Screen", 350, 100, fontSize, DARKGRAY);
    DrawRectangleRec(startButton, BLACK);
    DrawText("Start Game", startButton.x + 10, startButton.y + 10, fontSize, DARKGRAY);
    DrawRectangleRec(optionsButton, BLACK);
    DrawText("Options", optionsButton.x + 10, optionsButton.y + 10, fontSize, DARKGRAY);
    DrawRectangleRec(exitButton, BLACK);
    DrawText("Exit", exitButton.x + 10, exitButton.y + 10, fontSize, DARKGRAY);
}

void Ui::DrawGameScreen()
{
    // game ui

    drawScore();
    DrawFPS(100, 100);
}

void Ui::DrawOptionsScreen()
{
    DrawText("Options Screen", 350, 100, 20, DARKGRAY);
    DrawRectangleRec(fullscreenToggle, BLACK);
    DrawText(isFullscreen ? "Fullscreen: ON" : "Fullscreen: OFF", fullscreenToggle.x + 10, fullscreenToggle.y + 10, fontSize, DARKGRAY);
    DrawRectangleRec(volumeSlider, BLACK);
    DrawRectangle(volumeSlider.x + volume * volumeSlider.width - 5, volumeSlider.y - 5, 10, fontSize, DARKGRAY);
    DrawText("Volume", volumeSlider.x - 60, volumeSlider.y, fontSize, DARKGRAY);
    DrawRectangleRec(backButton, BLACK);
    DrawText("Back", backButton.x + 10, backButton.y + 10, fontSize, DARKGRAY);
}

void Ui::drawScore()
{
    DrawText("SCORE", SCREEN_WIDTH - 200, 100, fontSize, BLACK);
    std::string scoreTextString = std::to_string(score);
    const char* scoreTextChar = scoreTextString.c_str();
    DrawText(scoreTextChar, SCREEN_WIDTH - 200, 150, fontSize, BLACK);
}

int Ui::getScore()
{
    return this->score;
}

void Ui::setScore(int score)
{
    this->score += score;
}
