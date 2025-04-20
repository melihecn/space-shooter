#include "Ui.h"
#include <iostream>

Ui::Ui() : currentScreen(TITLE), isFullscreen(false), volume(0.5f) {}

Ui::~Ui() {}

void Ui::Init()
{
    // Initialize buttons and controls
    startButton = {350, 200, 200, 100 };
    optionsButton = { 350, 400, 200, 100 };
    exitButton = { 350, 600, 200, 100 };
    fullscreenToggle = { 350, 200, 100, 50 };
    volumeSlider = { 350, 300, 200, 20 };
    backButton = { 350, 400, 100, 50 };
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
                std::cout << "exite basildi \n";
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
    DrawText("Title Screen", 350, 100, 20, DARKGRAY);
    DrawRectangleRec(startButton, BLACK);
    DrawText("Start Game", startButton.x + 10, startButton.y + 10, 30, DARKGRAY);
    DrawRectangleRec(optionsButton, BLACK);
    DrawText("Options", optionsButton.x + 10, optionsButton.y + 10, 30, DARKGRAY);
    DrawRectangleRec(exitButton, BLACK);
    DrawText("Exit", exitButton.x + 10, exitButton.y + 10, 30, DARKGRAY);
}

void Ui::DrawGameScreen()
{
    // game ui
}

void Ui::DrawOptionsScreen()
{
    DrawText("Options Screen", 350, 100, 20, DARKGRAY);
    DrawRectangleRec(fullscreenToggle, BLACK);
    DrawText(isFullscreen ? "Fullscreen: ON" : "Fullscreen: OFF", fullscreenToggle.x + 10, fullscreenToggle.y + 10, 30, DARKGRAY);
    DrawRectangleRec(volumeSlider, BLACK);
    DrawRectangle(volumeSlider.x + volume * volumeSlider.width - 5, volumeSlider.y - 5, 10, 30, DARKGRAY);
    DrawText("Volume", volumeSlider.x - 60, volumeSlider.y, 30, DARKGRAY);
    DrawRectangleRec(backButton, BLACK);
    DrawText("Back", backButton.x + 10, backButton.y + 10, 30, DARKGRAY);
}