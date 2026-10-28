#include "types.h"
#include "pso/object/TObjRaderCol.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/object/TObjRaderCol.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_801976F4___vt__12TObjRaderCol {
    s32 value;
    u8 remaining[0x34];
};

struct Col_8019750C { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0x4C]; f32 f90; s32 f94; u8 pad98[4]; s32 f9C; };

struct Ply_8019750C { u8 pad0[0x38]; f32 pos[3]; };

extern "C" {
s32 __ct__13TUnk_804B9870FP7TObject(void *);
extern s32 __vt__12TObjRaderCol[];
extern s32 lbl_805D3410;
f32 xz_distance_squared(void *, void *);
void *get_player_by_client_id(s32 i);
void check_any_player_in_range__12TObjRaderColFPv(Col_8019750C *arg0);
extern s32 local_client_id;
void __dl__7TObjectFPv(void *);

void TObjRaderCol::render() {  }

void check_any_player_in_range__12TObjRaderColFPv(Col_8019750C *arg0) {
    s32 found;
    s32 i;
    s32 j;
    Ply_8019750C *p;
    found = 0;
    for (i = 0; i < 4; i++) {
        p = (Ply_8019750C *)get_player_by_client_id(i);
        if (p != 0 && ((TObjPlayer *)p)->is_body_collision_inactive() != 0) {
            found = 1;
        }
    }
    if (found == 0) {
        if (arg0->f9C > 0) {
            arg0->f9C--;
        } else {
            for (j = 0; j < 4; j++) {
                p = (Ply_8019750C *)get_player_by_client_id(j);
                if (p != 0 && xz_distance_squared(p->pos, arg0->pos) < arg0->f90 * arg0->f90) {
                    TRaderMapCore::reveal_region_by_id(arg0->f94);
                    queue_destruction__7TObjectFv(arg0);
                    return;
                }
            }
        }
    }
}

#define arg0 ((Col_8019750C *)arg0_)
void TObjRaderCol::check_local_player_in_range(void *arg0_) {
    Ply_8019750C *p = (Ply_8019750C *)get_player_by_client_id(local_client_id);
    if (p != 0) {
        if (((TObjPlayer *)p)->is_body_collision_inactive() != 0) {
            return;
        }
    } else {
        return;
    }
    s32 t = arg0->f9C;
    if (t > 0) {
        arg0->f9C = t - 1;
        return;
    }
    if (p != 0) {
        if (xz_distance_squared(p->pos, arg0->pos) < arg0->f90 * arg0->f90) {
            TRaderMapCore::reveal_region_by_id((s16)arg0->f94);
            queue_destruction__7TObjectFv(arg0);
        }
    }
}
#undef arg0

void TObjRaderCol::run_task() {

    switch (this->m_98) {
    case 0:
        TRaderMapCore::block_region_by_id((s16) this->m_94);
        this->m_98 = 1;
        return;
    case 1:
        if (TRaderMapCore::is_not_split_screen() == 1) {
            check_any_player_in_range__12TObjRaderColFPv((Col_8019750C *)(this));
            return;
        }
        TObjRaderCol::check_local_player_in_range(this);
        return;
    }
}

typedef char RecoveredGlobal_801976F4___vt__12TObjRaderCol_size[sizeof(RecoveredGlobal_801976F4___vt__12TObjRaderCol) == 0x38 ? 1 : -1];
u8 *TObjRaderCol__ct(TObjRaderCol *rader_col, s32 arg1, s32 arg2) {
    __ct__13TUnk_804B9870FP7TObject(rader_col);
    *(s32 **)((s8 *)rader_col + 0x18) = &(*(RecoveredGlobal_801976F4___vt__12TObjRaderCol *)&__vt__12TObjRaderCol).value;
    *(s32 *)((s8 *)rader_col + 0) = (s32) lbl_805D3410;
    ((TObjRaderCol *)(rader_col))->apply_object_set_data((void *)arg2);
    *(f32 *)((s8 *)rader_col + 0x90) = (f32) rader_col->scale.x;
    rader_col->m_94 = (s32) rader_col->set_params[0];
    rader_col->m_98 = 0;
    rader_col->m_9c = 3;
    disallow_rendering__7TObjectFv((rader_col));
    return (u8 *)rader_col;
}

}
TObjRaderCol::~TObjRaderCol() {

}
extern "C" {

}
