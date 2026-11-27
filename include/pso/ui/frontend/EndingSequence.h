#ifndef PSO_UI_FRONTEND_ENDINGSEQUENCE_H
#define PSO_UI_FRONTEND_ENDINGSEQUENCE_H

#include "types.h"

// Set while the ending sequence (start_ending_sequence .. exit_ending_sequence) runs.
extern s32 ending_sequence_active;
// set_ending_movie_active (TMovie) sets it, the TEndingMovie ctor clears it, TEndingMovie::finish_movie tests it.
extern s32 ending_movie_active_flag;

void start_ending_sequence(void);
void update_ending_sequence();
void exit_ending_sequence();

#endif
