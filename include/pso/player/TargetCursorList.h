#ifndef PSO_PLAYER_TARGETCURSORLIST_H
#define PSO_PLAYER_TARGETCURSORLIST_H

#include "types.h"

// A technique's target list: up to eleven targeted entities.
struct TargetCursorRecord {
    u16 id;
    s16 flag;
    f32 value;

    TargetCursorRecord();
    void init_cursor_record();
};

struct TargetCursorList {
    s32 count;
    TargetCursorRecord records[11];

    TargetCursorList();
};

extern "C" {
void clear_target_cursor_list(TargetCursorList *list);
TargetCursorRecord *__ct__18TargetCursorRecordFv(void *record);
TargetCursorList *__ct__16TargetCursorListFv(void *list);
// *dst = *src (TTecAnti's TU).
TargetCursorList *copy_technique_target_list(TargetCursorList *dst, TargetCursorList *src);
}

#endif
