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

// TODO: probably want an array of lasers versus unlimited
// will help with performance
//
// TODO: need to figure out speed and direction of lasers
//
//
// TODO: need to add some kind of bounds on player and check
// if hit by asteroids
//
//
// TODO: need bounding box on asteroids and check if hit by laser
//
//
// TODO:check each of the games statuses and bounds each frame
//
//

// static objects
static Player player = {0};
static Texture2D ship;

// game conditions
static bool gameOver = false;
static bool gamePause = false;
static bool gameWon = false;

void InitGame();
void UpdatePlayer();

int main(int argc, char **argv) {
  InitGame();

  while (!WindowShouldClose()) {
    UpdatePlayer();

    BeginDrawing();

    ClearBackground(BLACK);

    DrawTextureEx(ship, player.location, player.rotation, 1.0, WHITE);

    EndDrawing();
  }

  UnloadTexture(ship);

  CloseWindow();

  return 0;
}

void InitGame() {
  InitWindow(width, height, "Asteroids");

  // init player
  player.location = (Vector2){(float)width / 2, (float)height / 2};
  player.speed = (Vector2){0, 0};
  player.acceleration = 0.0;
  player.rotation = 0.0;

  Image triangle = LoadImage("../resources/textures/white-triangle.png");
  ImageResize(&triangle, triangle.width / 6, triangle.height / 6);
  ship = LoadTextureFromImage(triangle);
  UnloadImage(triangle);

  SetTargetFPS(60);
  DrawTexture(ship, width / 2 - ship.width / 2, height / 2 - ship.height / 2,
              WHITE);
}

void UpdatePlayer() {
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
}
