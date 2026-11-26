#ifndef PSO_BOSS_GOLDRAGON_BOSS8DEMOOBJECTS_H
#define PSO_BOSS_GOLDRAGON_BOSS8DEMOOBJECTS_H

#include "types.h"

// The live camera and monitors of Gol Dragon's demo room, and the room itself until its enemies are cleared.
void create_boss8_demo_objects(void);

// Release (reverse order) and load the Gol Dragon demo room's static resources.
void free_boss8_demo_resources(void);
void load_boss8_demo_resources(void);

#endif
