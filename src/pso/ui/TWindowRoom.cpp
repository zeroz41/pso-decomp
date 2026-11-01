#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/misc/TWindowSubStatusDisp_80287570.h"
#include "pso/ui/TWindowRoom.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowDD.h"

struct RecoveredGlobal_8026D674_lbl_804D08DC {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_8026D674___vt__11TWindowRoom {
    s32 value;
    u8 remaining[0x14];
};

struct Pos_8026D740 { f32 x; f32 y; };

struct RoomTitleEntry {
    u8 unknown00[8];
    f32 positionX;
    u8 unknown0C[4];
    f32 width;
};

extern "C" {
int get_array_entry__11TWindowBaseFi(void*, int);
s32 save_position__11TWindowBaseFv(void *);
void construct_base__9TWindowDDFPUcsPUc(void *, void *, s16, void *);
void refresh_status_display__9TWindowDDFv(void *);
s32 get_window_layout_position(int);
extern RecoveredGlobal_8026D674_lbl_804D08DC room_window_base_parameters;
extern s32 __vt__11TWindowRoom[];
extern s32 TWindowRoom__class_name;
extern const f32 lbl_805DD2F0;
extern const f32 lbl_805DD2F4;
extern const f32 lbl_805DD2F8;
s32 clamp_list_scroll_offset(struct Pos_8026D740 *a, struct Pos_8026D740 *b, struct Pos_8026D740 *c);
s32 draw_visible_window_entries(s32, s32, s32);
int update_window_entry_list__11TWindowBaseFPv(void*, void*);
s32 draw_window_tab(s32, s32, s32, f32);
void __dl__7TObjectFPv(void *);
s32 draw_default_entry__9TWindowDDFl();
int initialize_subwindow__9TWindowDDFv(void*);

}

void *TWindowRoom::get_title_entry() {
    return (void *)get_array_entry__11TWindowBaseFi(this, 0);
}

void TWindowSubStatusDisp::set_entry_display_value(s32 arg1) {
    set_text_entry_string((u8 *)(get_array_entry__11TWindowBaseFi(this, 0)), arg1, 0x60);
}

void TWindowRoom::draw_tab(void *context) {
    draw_window_tab((s32)context, (s32)((u8 *)context + 0x10), 3, tabParameter);
}

void TWindowRoom::draw_status() {
    s32 temp_r3;
    s32 arg0 = (s32)this;

    temp_r3 = draw_default_entry__9TWindowDDFl();
    ((TWindowRoom *)arg0)->draw_tab((void *)temp_r3);
    draw_visible_window_entries(arg0, arg0 + 0x24, temp_r3);
}
void TWindowRoom::run_task() { initialize_subwindow__9TWindowDDFv(this); update_window_entry_list__11TWindowBaseFPv(this, (char*)this + 0x24); }

void *__dt__11TWindowRoomFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        ((TWindowRoom *)arg0)->objectVtable = __vt__11TWindowRoom;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8026D674_lbl_804D08DC_size[sizeof(RecoveredGlobal_8026D674_lbl_804D08DC) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_8026D674___vt__11TWindowRoom_size[sizeof(RecoveredGlobal_8026D674___vt__11TWindowRoom) == 0x18 ? 1 : -1];

TWindowRoom::TWindowRoom(char *title) {
    RoomTitleEntry *entry;
    construct_base__9TWindowDDFPUcsPUc(this, &room_window_base_parameters.value, 4,
                                    (void *)get_window_layout_position(0xAF));
    objectVtable = __vt__11TWindowRoom;
    className = TWindowRoom__class_name;
    entry = (RoomTitleEntry *)get_array_entry__11TWindowBaseFi(this, 0);
    set_text_entry_string((u8 *)entry, (u32)title, 0x60);
    refresh_status_display__9TWindowDDFv(entry);
    width = lbl_805DD2F0 + (entry->positionX + entry->width);
    positionX -= width;
    save_position__11TWindowBaseFv(this);
    tabParameter = TWindowSubStatusDisp__sub_802877A4(unknown48 - lbl_805DD2F4);
}

s32 clamp_list_scroll_offset(struct Pos_8026D740 *a, struct Pos_8026D740 *b, struct Pos_8026D740 *c) {
    f32 room;
    if (a->y < c->y || b->y < lbl_805DD2F8) {
        b->y = lbl_805DD2F8;
        return 1;
    }
    room = a->y - c->y;
    if (b->y > room) {
        b->y = room;
        return 1;
    }
    return 0;
}
