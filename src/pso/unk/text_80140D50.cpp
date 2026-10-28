#include "types.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLobby_80140FF4.h"
#include "pso/object/TObjLight_80133568.h"
#include "pso/unk/text_80140D50.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/CurrentArea.h"

struct Obj_80140EE4 { u8 pad[0x1c]; void *slots[0x201]; };

struct Ent_80140F18 { void *key; u8 pad[0x14]; };

struct Obj_80140F18 { u8 pad[0x1c]; Ent_80140F18 *slots[1]; };

extern "C" {
void register_slot(Obj_80140EE4 *self, void *p);
void collect_collision_groups(Obj_80140F18 *self, Ent_80140F18 *e);
s32 is_split_screen();
s32 is_quest_active();
void TLobby__sub_801403B4(int);
}
void init_music_sequencer(s32 program);
extern "C" {
void play_area_music(void *);
void load_floor_sound_bank();
extern char lbl_8043F260[];

s32 fn_80140D50(void) {
    get_current_area();
    load_floor_sound_bank();
    if (TLobby::check_disconnect_conditions() != 0) {
        return 0;
    }
    init_area_lights();
    TLobby::create_tasks();
    if (get_main_phase() != 0xE || is_quest_active() == 0) {
        switch (get_current_area()) {
        case 0x14:
            TBoss4DarkFalz::dispatch_by_main_phase(0x4B);
            break;
        }
    }
    TLobby__sub_801403B4(0);
    if (is_split_screen() != 0) {
        play_area_music(lbl_8043F260);
    } else if (TLobby::get_instance() == 1) {
        init_music_sequencer(7);
    }
    return 1;
}

void fn_80140DFC(s32 arg0, s32 arg1) {
    remove_value_from_id_list((s32)((void *)arg0), (u32)((void *) (TLobby__sub_80141030((void *)arg1))));
}
}

void remove_value_from_id_list(s32 arg0, u32 arg1) {
    s32 i;
    u32 *p;
    p = (u32 *)(arg0 + 0x1C);
    for (i = 0; i < 0x200; p++, i++) {
        if (*p == arg1) {
            u32 *src;
            u32 *dst = p;
            s32 k;
            src = ++p;
            for (k = i; k < 0x200; k++) {
                *dst = *src++;
                if (*++dst == 0) {
                    return;
                }
            }
            *p = 0;
            return;
        }
    }
}

void fn_80140EA8(s32 arg0, s32 arg1) {
    register_slot((Obj_80140EE4 *)((void *)arg0), (void *)((void *) (TLobby__sub_80141030((void *)arg1))));
}
void register_slot(Obj_80140EE4 *self, void *p) {
    s32 i;
    void **s = self->slots;
    for (i = 0; i < 0x200; i++, s++) {
        if (*s == 0) {
            s[0] = p;
            s[1] = 0;
            return;
        }
    }
}
void collect_collision_groups(Obj_80140F18 *self, Ent_80140F18 *e) {
    Ent_80140F18 **p = self->slots;
    while (e->key != 0) {
        *p++ = e;
        e++;
    }
    *p = 0;
}
