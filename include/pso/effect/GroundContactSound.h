#ifndef PSO_EFFECT_GROUND_CONTACT_SOUND_H
#define PSO_EFFECT_GROUND_CONTACT_SOUND_H
#include <dolphin/mtx.h>

class TObject;

// The sounds of something touching the ground; each picks the variant for the
// current floor's area and plays nothing on other floors.
void play_ground_step_sound(TObject *owner, Vec *pos);
void play_ground_landing_sound(Vec *pos);
void play_ground_contact_sound(Vec *pos);

#endif
