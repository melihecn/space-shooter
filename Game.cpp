// Game.h
#pragma once

#include <memory>
#include "Ui.h"
#include "Player.h"
#include "raylib.h"

class Game {
public:
    Game();
    ~Game();

    void Update();
    void Draw();

private:
    static constexpr int SCREEN_WIDTH        = 1280;
    static constexpr int SCREEN_HEIGHT       = 720;
    static constexpr float PLAYER_CAM_OFFSET = 20.f;
    static constexpr float CAMERA_LERP_SPEED = 0.1f;

    std::unique_ptr<Ui>     ui_;
    std::unique_ptr<Player> player_;
    Camera2D                camera_;
    Texture2D               background_;

    // Simple linear interpolation helper
    static float Lerp(float a, float b, float t) {
        return a + (b - a) * t;
    }
};
