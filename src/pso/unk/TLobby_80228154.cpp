#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/item/TUnk_804CC048.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TLobby_80207644.h"
#include <stddef.h>
#include "pso/system/scene/TScene.h"
#include "pso/unk/TLobby_800FD78C.h"


struct RecoveredGlobal_80228634_lbl_804CBE98 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_80228754_lbl_804CBE98 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_802286C4_lbl_804CBE98 {
    s32 value;
    u8 remaining[0x1AC];
};


extern "C" {
s32 select_area_entrance(void *arg0);
s32 lookup_scene_object__6TLobbyFPv(s32, void *);
extern RecoveredGlobal_80228634_lbl_804CBE98 area_initializer_dispatch_table;
void run_area_scene_cleanup(u8 *arg0);
void promote_area_floor(u8 *arg0);
void load_area_scene_and_init(u8 *arg0);
s32 get_floor_map_terrain(s32);


void TLobby::clear_ready_flag_unless_locked() {
    if (get_current_floor_area() != AREA_LOBBY) {
        *(s32 *)((s8 *)this + 0x20) = (s32) (*(s32 *)((s8 *)this + 0x20) & 0xFFFFFFFE);
    }
}

void TLobby::set_area(s32 arg1) {
    *(s32 *)&this->m_next = arg1;
    *(s32 *)((s8 *)this + 0x18) = get_floor_map_terrain(*(s32 *)&this->m_next);
}

#pragma push
#pragma fp_contract on
s32 select_area_entrance(void *arg0) {
    s32 temp_r0;
    s32 temp_r3;
    if ((s32) *(s32 *)((s8 *)arg0 + 0) > 0x11) {
        return 4;
    }
    if (*(s32 *)((s8 *)arg0 + 0x20) & 1) {
        return 2;
    }
    if ((TLobby::get_instance() == 0) && (get_floor_area(*(s32 *)((s8 *)arg0 + 0)) == 0xD)) {
        switch (get_floor_area(*(s32 *)((s8 *)arg0 + 4))) {
        case 8:
        case 9:
        case 10:
            return 1;
        default:
            return 0;
        }
    }
    temp_r0 = *(s32 *)((s8 *)arg0 + 4) - *(s32 *)((s8 *)arg0 + 0);
    if (temp_r0 >= 0) {
        return 1;
    }
    return (temp_r0 < 0) ? 0 : 4;
}
#pragma pop

typedef char RecoveredGlobal_80228634_lbl_804CBE98_size[sizeof(RecoveredGlobal_80228634_lbl_804CBE98) == 0x1B0 ? 1 : -1];
void run_area_scene_cleanup(u8 *arg0) {
    s32 sp8;
    s32 (*var_r12)(s32);
    s32 *var_r4;
    s32 var_r3;
    u8 *var_r31;
    var_r4 = &sp8;
    var_r31 = arg0;
    var_r3 = *(s32 *)((s8 *)arg0 + 4);
    if (lookup_scene_object__6TLobbyFPv(var_r3, var_r4) != 0) {
        var_r3 = (s32) &area_initializer_dispatch_table.value;
        var_r3 = (s32) &area_initializer_dispatch_table.value;
        var_r3 += sp8 * 0xC;
        var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 8);
        var_r12(var_r3);
    } else {
        var_r3 = (s32) &area_initializer_dispatch_table.value;
        var_r3 = (s32) &area_initializer_dispatch_table.value;
        var_r3 += *(s32 *)((s8 *)var_r31 + 4) * 0xC;
        var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 8);
        var_r12(var_r3);
    }
    *(s32 *)((s8 *)var_r31 + 4) = 0;
    *(s32 *)((s8 *)var_r31 + 8) = 0;
    *(s32 *)((s8 *)var_r31 + 0xC) = 0;
}

typedef char RecoveredGlobal_80228754_lbl_804CBE98_size[sizeof(RecoveredGlobal_80228754_lbl_804CBE98) == 0x1B0 ? 1 : -1];

typedef char RecoveredGlobal_802286C4_lbl_804CBE98_size[sizeof(RecoveredGlobal_802286C4_lbl_804CBE98) == 0x1B0 ? 1 : -1];
void load_area_scene_and_init(u8 *arg0) {
    s32 sp8;
    s32 (*var_r12)(s32);
    s32 *var_r4;
    s32 var_r3;
    u8 *var_r31;
    var_r31 = arg0;
    var_r3 = *(s32 *)((s8 *)arg0 + 4);
    set_current_floor_area((var_r3));
    var_r3 = *(s32 *)((s8 *)var_r31 + 0x10);
    TScene::set_scene(var_r3);
    var_r3 = *(s32 *)((s8 *)var_r31 + 4);
    var_r4 = &sp8;
    if (lookup_scene_object__6TLobbyFPv(var_r3, var_r4) != 0) {
        var_r3 = (s32) &(*(RecoveredGlobal_802286C4_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 = (s32) &(*(RecoveredGlobal_802286C4_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 += sp8 * 0xC;
        var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 4);
        var_r12(var_r3);
        return;
    }
    var_r3 = (s32) &(*(RecoveredGlobal_802286C4_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
    var_r3 = (s32) &(*(RecoveredGlobal_802286C4_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
    var_r3 += *(s32 *)((s8 *)var_r31 + 4) * 0xC;
    var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 4);
    var_r12(var_r3);
}

void promote_area_floor(u8 *arg0) {
    s32 sp8;
    s32 (*var_r12)(s32);
    s32 *var_r4;
    s32 var_r3;
    u8 *var_r31;
    var_r4 = &sp8;
    var_r31 = arg0;
    var_r3 = *(s32 *)((s8 *)arg0 + 4);
    if (lookup_scene_object__6TLobbyFPv(var_r3, var_r4) != 0) {
        var_r3 = (s32) &(*(RecoveredGlobal_80228754_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 = (s32) &(*(RecoveredGlobal_80228754_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 += sp8 * 0xC;
        var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 8);
        var_r12(var_r3);
    } else {
        var_r3 = (s32) &(*(RecoveredGlobal_80228754_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 = (s32) &(*(RecoveredGlobal_80228754_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 += *(s32 *)((s8 *)var_r31 + 4) * 0xC;
        var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 8);
        var_r12(var_r3);
    }
    *(s32 *)((s8 *)var_r31 + 0) = (s32) *(s32 *)((s8 *)var_r31 + 4);
    *(s32 *)((s8 *)var_r31 + 4) = (s32) *(s32 *)((s8 *)var_r31 + 0xC);
    *(s32 *)((s8 *)var_r31 + 0x10) = (s32) *(s32 *)((s8 *)var_r31 + 0x18);
    TLobby::reset_story_select_state();
}
}

Obj_80515BA0 lbl_80515BA0;
