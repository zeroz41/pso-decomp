#ifndef PSO_OBJECT_LOBBY_LOBBYPIGEON_H
#define PSO_OBJECT_LOBBY_LOBBYPIGEON_H

#include "types.h"

struct LobbyPigeon {
  u8 prefix[0x18];
  void *vtable;
  u8 fields1C[0x38 - 0x1C];
  f32 position[3];
  u8 fields44[0x60 - 0x44];
  s32 facing;
  u8 fields64[0x84 - 0x64];
  s32 movementSelector, themeSelector, modelSelector;
  f32 viewDistance, visibilityArgument;
  s32 phase;
  f32 scale;
  s32 modelIndex, theme;
  void *model;
  void *animation;
  void *path;
  f32 pathFrame, animationFrame, pathPosition[3];
  s32 pathYaw, pathPitch, pathRoll, rollSpeed, movement, randomDelay;
};

#endif
