#ifndef PSO_SYSTEM_SCENE_TENDINGC_8008D00C_H
#define PSO_SYSTEM_SCENE_TENDINGC_8008D00C_H

#include "types.h"

// Start the A/B wall fade and the picture sequence (TEndingC, once its wall is fully shown).
void start_ending_ab_fade(void);
void start_ending_pic_sequence(void);
u32 get_ending_frame_counter(void);
void register_texture_ed_512kabe_c(void);

#endif
