#ifndef PSO_MISC_TKEYBOARDCONTROL_802A1180_H
#define PSO_MISC_TKEYBOARDCONTROL_802A1180_H

#include "types.h"

extern "C" {
// Also the TMovie end callback of the opening movie: takes the callback's argument.
void set_movie_finished_flag(s32);
}
void update_movie_phase(void);

#endif
