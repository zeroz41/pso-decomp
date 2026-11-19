#ifndef PSO_UI_FRONTEND_TADENDTEXT_80307A34_H
#define PSO_UI_FRONTEND_TADENDTEXT_80307A34_H

#include "types.h"

// Set while the ending sequence (start_ending_sequence .. TAdEndText::cleanup) runs.
extern s32 ending_sequence_active;
// fn_801449F0 (TMovie) sets it, the TUnk_804E71A0 ctor clears it, TObjPlayer::disable_keyboard_control tests it.
extern s32 ending_movie_active_flag;

void start_ending_sequence(void);

#endif
