#include <raylib.h>
#include <raymath.h>

const int width = 1000;
const int height = 1000;

// Type for the player
typedef struct Player {
  Vector2 location;
  Vector2 speed;
  float acceleration;
  float rotation;
} Player;

// Type for the asteroids
typedef struct Asteroid {

} Asteroid;

// static objects
static Player player = {0};

int main(int argc, char **argv) {

  InitWindow(width, height, "Asteroids");

  // init player
  player.location = (Vector2){(float)width / 2, (float)height / 2};
  player.speed = (Vector2){0, 0};
  player.acceleration = 0.0;
  player.rotation = 0.0;

  Image triangle = LoadImage("../resources/textures/white-triangle.png");
  ImageResize(&triangle, triangle.width / 6, triangle.height / 6);
  Texture2D ship = LoadTextureFromImage(triangle);
  UnloadImage(triangle);

  SetTargetFPS(60);
  DrawTexture(ship, width / 2 - ship.width / 2, height / 2 - ship.height / 2,
              WHITE);

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_A))
      player.rotation--;
    if (IsKeyDown(KEY_D))
      player.rotation++;

    player.speed.x = sin(player.rotation * DEG2RAD) * 3.0f;
    player.speed.y = cos(player.rotation * DEG2RAD) * 3.0f;

    if (IsKeyDown(KEY_W)) {
      if (player.acceleration < 1)
        player.acceleration += 0.04f;
    } else {
      if (player.acceleration > 0)
        player.acceleration -= 0.04f;
      else if (player.acceleration < 0)
        player.acceleration = 0.0f;
    }

    if (IsKeyDown(KEY_S)) {
      if (player.acceleration > 0)
        player.acceleration -= 0.04f;
      else if (player.acceleration < 0)
        player.acceleration = 0;
    }
    player.location.x += (player.speed.x * player.acceleration);
    player.location.y -= (player.speed.y * player.acceleration);

    BeginDrawing();

    ClearBackground(BLACK);

    DrawTextureEx(ship, player.location, player.rotation, 1.0, WHITE);

    EndDrawing();
  }

  UnloadTexture(ship);

  CloseWindow();

  return 0;
}
