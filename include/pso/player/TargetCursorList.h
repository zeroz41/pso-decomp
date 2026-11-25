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
    void set_id(u16 id);
    void set_flag(s16 flag);
    void set_value(f32 value);
    f32 get_value();
    void copy_from(TargetCursorRecord *src);
};

struct TargetCursorList {
    s32 count;
    TargetCursorRecord records[11];

    TargetCursorList();
    void increment_count();
    TargetCursorRecord *get_record(int index);
    s32 get_count();
    void set_count(s32 count);
};

void clear_target_cursor_list(TargetCursorList *list);
extern "C" {
TargetCursorRecord *__ct__18TargetCursorRecordFv(void *record);
TargetCursorList *__ct__16TargetCursorListFv(void *list);
}
// *dst = *src (TTecAnti's TU).
TargetCursorList *copy_technique_target_list(TargetCursorList *dst, TargetCursorList *src);

#endif
