#include <raylib.h>

const int width = 1000;
const int height = 1000;

int main(int argc, char **argv) {

  InitWindow(width, height, "Asteroids");

  Vector2 shipNose = {(float)width / 2, (float)height / 2};
  Vector2 shipLeft = {shipNose.x + 15, shipNose.y + 15};
  Vector2 shipRight = {shipLeft.x - 30, shipLeft.y};

  Image triangle = LoadImage("../resources/textures/white-triangle.png");
  ImageResize(&triangle, triangle.width / 6, triangle.height / 6);
  Texture2D ship = LoadTextureFromImage(triangle);
  UnloadImage(triangle);

  SetTargetFPS(120);

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_W)) {

      // add force to ship -y direction
      shipNose.y -= 2;
      shipLeft.y -= 2;
      shipRight.y -= 2;
    }
    if (IsKeyDown(KEY_S)) {
      // add force to ship +y direction
      shipNose.y += 2;
      shipLeft.y += 2;
      shipRight.y += 2;
    }
    if (IsKeyDown(KEY_A)) {
      // add force to ship -x direction
      shipNose.x -= 2;
      shipLeft.x -= 2;
      shipRight.x -= 2;
    }
    if (IsKeyDown(KEY_D)) {
      // add force to ship +x direction
      shipNose.x += 2;
      shipLeft.x += 2;
      shipRight.x += 2;
    }
    BeginDrawing();

    ClearBackground(BLACK);

    // DrawTriangleLines(shipNose, shipLeft, shipRight, WHITE);
    DrawTexture(ship, width / 2 - ship.width / 2, height / 2 - ship.height / 2,
                WHITE);

    EndDrawing();
  }

  UnloadTexture(ship);

  CloseWindow();

  return 0;
}
