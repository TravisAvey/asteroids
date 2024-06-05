#include <raylib.h>

const int width = 1000;
const int height = 1000;

int main(int argc, char **argv) {

  InitWindow(width, height, "Asteroids");

  Vector2 shipVec = {(float)width / 2, (float)height / 2};

  Image triangle = LoadImage("../resources/textures/white-triangle.png");
  ImageResize(&triangle, triangle.width / 6, triangle.height / 6);
  Texture2D ship = LoadTextureFromImage(triangle);
  UnloadImage(triangle);

  int shipRotation = 0;

  SetTargetFPS(60);
  DrawTexture(ship, width / 2 - ship.width / 2, height / 2 - ship.height / 2,
              WHITE);

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_W)) {

      // add force to ship -y direction
      shipVec.y -= 2;
    }
    if (IsKeyDown(KEY_S)) {
      // add force to ship +y direction
      shipVec.y += 2;
    }
    if (IsKeyDown(KEY_A)) {
      // turn ship
      shipRotation -= 5;
    }
    if (IsKeyDown(KEY_D)) {
      shipRotation += 5;
    }
    BeginDrawing();

    ClearBackground(BLACK);

    // DrawTexture(ship, shipVec.x, shipVec.y, WHITE);
    DrawTextureEx(ship, shipVec, (float)shipRotation, 1.0, WHITE);

    EndDrawing();
  }

  UnloadTexture(ship);

  CloseWindow();

  return 0;
}
