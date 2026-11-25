#ifndef PSO_SYSTEM_TLOADCTRL_80227390_H
#define PSO_SYSTEM_TLOADCTRL_80227390_H

#include "types.h"

void start_music_crossfade(s32 frames);
extern "C" {
void play_area_music(char *name);
}
void update_music_fade(void);

#endif
