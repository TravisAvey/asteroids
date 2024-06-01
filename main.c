#include <raylib.h>

const int width = 640;
const int height = 480;

int main(int argc, char **argv) {

  InitWindow(width, height, "Asteroids");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Here is the asteroid game canvas", 190, 20, 20, LIGHTGRAY);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
