#include <raylib.h>
#include <raymath.h>

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
      shipRotation--;
    }
    if (IsKeyDown(KEY_D)) {
      shipRotation++;
    }

    BeginDrawing();

    ClearBackground(BLACK);

    // this makes it rotate around the top left corner
    // and glitches about when turning with a/d
    // Vector2 rot = Vector2Rotate(shipVec, (float)shipRotation);

    DrawTextureEx(ship, shipVec, (float)shipRotation, 1.0, WHITE);

    EndDrawing();
  }

  UnloadTexture(ship);

  CloseWindow();

  return 0;
}
