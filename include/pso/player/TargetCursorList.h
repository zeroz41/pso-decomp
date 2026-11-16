#ifndef PSO_PLAYER_TARGETCURSORLIST_H
#define PSO_PLAYER_TARGETCURSORLIST_H

#include "types.h"

// A technique's target list: up to eleven targeted entities.
struct TargetCursorRecord {
    u16 id;
    s16 flag;
    f32 value;

    void init_cursor_record();
};

struct TargetCursorList {
    s32 count;
    TargetCursorRecord records[11];
};

extern "C" {
void clear_target_cursor_list(TargetCursorList *list);
TargetCursorRecord *fn_8004438C(TargetCursorRecord *record);
}

#endif
