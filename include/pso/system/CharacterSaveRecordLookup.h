#ifndef PSO_SYSTEM_CHARACTER_SAVE_RECORD_LOOKUP_H
#define PSO_SYSTEM_CHARACTER_SAVE_RECORD_LOOKUP_H

#include "types.h"

// The recovered lookup at 80202990 consumes the full client word. Its existing
// result is a target address word; this does not recover the complete record.
extern "C" s32 get_character_save_record(u32 client);

#endif
