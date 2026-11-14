#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer_80307618.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TUnk_804E70A8.h"
#include "pso/player/TUnk_804E71A0.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80307964.h"
#include "pso/unk/text_80120908.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"

// Built with -inline off,deferred: functions are written last to first.

extern "C" {
extern char shared_capture_texture_list[];
void TKeyBoardControl__sub_8000F91C(s32 arg0);
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
s32 queue_destruction__7TObjectFv();
void *__ct__6TMovieFP7TObjectPSclll(void *, void *, void *, void *, s32, s32, s32);
void *__nw__7TObjectFUl(u32);
extern u8 lbl_80475450[];
extern s32 game_difficulty_selection;
}
extern s32 ending_movie_active_flag;

TUnk_804E71A0::TUnk_804E71A0() : TObject(tl_04) {
    void *p;
    ending_movie_active_flag = 0;
    switch (game_difficulty_selection) {
    case 0:
    case 1:
    case 2:
        p = __nw__7TObjectFUl(0x4C);
        if (p != 0) {
            __ct__6TMovieFP7TObjectPSclll(p, tl_00, lbl_80475450, (void *)TObjPlayer::disable_keyboard_control, 0, 1, 0);
        }
        break;
    case 3:
        p = __nw__7TObjectFUl(0x4C);
        if (p != 0) {
            __ct__6TMovieFP7TObjectPSclll(p, tl_00, lbl_80475450, (void *)TObjPlayer::disable_keyboard_control, 0, 0, 0);
        }
        break;
    }
}

TUnk_804E71A0::~TUnk_804E71A0() {}

void TUnk_804E71A0::run_task() {}

void TObjPlayer::disable_keyboard_control() {
    queue_destruction__7TObjectFv();
    if ((s32) ending_movie_active_flag != 0) {
        TKeyBoardControl__sub_8000F9CC(2);
        return;
    }
    TKeyBoardControl__sub_8000F91C(2);
    TKeyBoardControl__sub_8000F9CC(0x12);
}

void TUnk_804E71A0::render() {}

char *get_shared_capture_texture_list(void) {
    return shared_capture_texture_list;
}

TUnk_804E70A8::~TUnk_804E70A8() {}

extern "C" {
u8 *TObjPlayer__sub_80307800(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804E70A8(tl_05, item);
    }
    return NULL;
}
}

TUnk_804E70A8::TUnk_804E70A8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(1);
    if (get_item_index() == 1) {
        set_weapon_flags(0x800);
    }
    pad_1f8 = 5;
    pad_1fc = 0;
    pad_200 = 0;
}

void TUnk_804E70A8::vfunc_60() {
    s32 player_list;
    if (pad_1f8 == 0) {
        player_list = TObjPlayer::get_player_list();
        begin_particle_tev();
        load_projection_tex(182.04445f * (f32)(pad_1fc + player_list * 3));
    }
}

void TUnk_804E70A8::update_weapon() {
    if (pad_1f8 > 0) {
        if (get_item_index() == 1) {
            pad_1f8--;
            if (pad_1f8 == 0) {
                set_weapon_flags(0x800);
            }
        }
    } else {
        pad_200 += 0xB6;
        pad_1fc = 182.0f * sin_table_lookup(pad_200);
    }
}

void TUnk_804E70A8::reserved_53() {
    NJS_OBJECT *model = item_model;
    draw_weapon_model();
    item_model = second_model;
    draw_weapon_at_joint((s32)this, 0x23);
    item_model = model;
}
