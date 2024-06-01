#include <raylib.h>

const int width = 1000;
const int height = 1000;

int main(int argc, char **argv) {

  InitWindow(width, height, "Asteroids");

  Vector2 shipNose = {(float)width / 2, (float)height / 2};
  Vector2 shipLeft = {shipNose.x + 15, shipNose.y + 15};
  Vector2 shipRight = {shipLeft.x - 30, shipLeft.y};

  SetTargetFPS(120);

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_W)) {
      shipNose.y -= 2;
      shipLeft.y -= 2;
      shipRight.y -= 2;
    }
    if (IsKeyDown(KEY_S)) {
      shipNose.y += 2;
      shipLeft.y += 2;
      shipRight.y += 2;
    }
    if (IsKeyDown(KEY_A)) {
      shipNose.x -= 2;
      shipLeft.x -= 2;
      shipRight.x -= 2;
    }
    if (IsKeyDown(KEY_D)) {
      shipNose.x += 2;
      shipLeft.x += 2;
      shipRight.x += 2;
    }
    BeginDrawing();

    ClearBackground(BLACK);

    DrawTriangleLines(shipNose, shipLeft, shipRight, WHITE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
