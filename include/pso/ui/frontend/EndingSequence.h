#ifndef PSO_UI_FRONTEND_ENDINGSEQUENCE_H
#define PSO_UI_FRONTEND_ENDINGSEQUENCE_H

#include "types.h"

// Set while the ending sequence (start_ending_sequence .. TAdEndText::cleanup) runs.
extern s32 ending_sequence_active;
// fn_801449F0 (TMovie) sets it, the TEndingMovie ctor clears it, TEndingMovie::finish_movie tests it.
extern s32 ending_movie_active_flag;

void start_ending_sequence(void);

#endif
