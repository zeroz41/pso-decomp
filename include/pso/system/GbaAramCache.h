#ifndef PSO_SYSTEM_GBAARAMCACHE_H
#define PSO_SYSTEM_GBAARAMCACHE_H

#include "types.h"

// The ARAM block TAdWarningBaseGC::init_heap reserves for the downloaded .gba file.
extern u32 ad_warning_aram_base;
extern s32 warning_aram_load_done_flag;
extern int lobby_count_value;
extern s32 aram_request_busy_flag;

void reset_warning_aram_cache(void);
extern "C" {
int get_aligned_aram_alloc_size(void);
void reset_aram_state(void);
}

#endif
