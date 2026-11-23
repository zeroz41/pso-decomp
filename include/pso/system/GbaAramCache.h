#ifndef PSO_SYSTEM_GBAARAMCACHE_H
#define PSO_SYSTEM_GBAARAMCACHE_H

#include "types.h"

// The ARAM block TAdWarningBaseGC::init_heap reserves for the downloaded .gba file.
extern u32 ad_warning_aram_base;
extern u32 TAdWarningBaseGC__aram_capacity;
extern s32 warning_aram_load_done_flag;
extern int TAdWarningBaseGC__aram_alloc_size;
extern int lobby_count_value;
extern s32 aram_request_busy_flag;

extern "C" {
void TLobby__sub_8032CDEC(void);
int TAdWarningBaseGC__sub_8032D020(void);
void TAdWarningBaseGC__sub_8032D188(void);
}

#endif
