#include "types.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804B7C1C.h"
#include "pso/misc/TUnk_804B7C04.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/player/TObjPlayer.h"
extern "C" void *__ct__13TUnk_804AF8A0FP7TObject(void *, s32);

struct RecoveredGlobal_8019118C_lbl_804B7BD8 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8019118C_lbl_804B7C1C {
    s32 value;
    u8 remaining[0x38];
};

struct Npc_80190F3C { u8 pad0[0x18]; void *f18; u8 f1C[0xC]; s32 f28; s32 f2C; s16 f30; s16 pad32; s32 f34; s32 f38; };

struct Base_801910F4 { u8 pad0[0x18]; };

struct Ctrl_801910F4 : Base_801910F4 { virtual void v0(int); };

struct Obj_801910F4 { u8 pad0[0x18]; void *f18; u8 pad1C[0x90]; u16 fAC; };

struct Npc_80190F3C;
struct Ctrl_801910F4;
struct Npc_80190FDC { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0x1C]; s32 f60; u8 pad64[4]; f32 f68; u8 pad6C[0x1C]; s32 f88; s32 f8C; u8 pad90[0x1C]; u16 fAC; u8 padAE[2]; s32 fB0; s32 fB4; };

struct Ply_80190FDC { u8 pad0[0x38]; f32 pos[3]; };

extern "C" {
s32 init_collision_body_parts(void *, void *, int);
extern RecoveredGlobal_8019118C_lbl_804B7BD8 npc_player_collision_body_part;
extern RecoveredGlobal_8019118C_lbl_804B7C1C lbl_804B7C1C;
u8 *TLobby__sub_8019118C(u8 *arg0, s32 arg1, s32 arg2);
void __ct__7TObjectFP7TObject(void *, void *);
extern u8 lbl_80445910[];
extern s32 lbl_804B7C04[];
extern s32 lbl_805D5860;
Npc_80190F3C *TNpcPlayer__sub_80190F3C(Npc_80190F3C *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6);
void free_collision_body_parts(void *);
void *get_player_by_client_id(s32 i);
s32 __dl__7TObjectFPv(void *);
Obj_801910F4 *__dt__13TUnk_804B7C1CFv(Obj_801910F4 *arg0, s16 arg1);
void queue_destruction__7TObjectFv(void *arg0);
f32 horizontal_distance_squared(void *, void *);
void *__nw__7TObjectFUl(int);
extern int npc_proximity_target_id;
extern s32 local_client_id;
extern void *tl_07;
void TLobby__sub_80190FD0(int a0);
s32 build_npc_player_record__10TNpcPlayerFl(s32);
void send_6x24_teleport_player(u16 slot, void *pos, s32 heading);
u8 *create_player_object(u16, s32, s32);
s32 queue_player_injured_pose();
s32 __dt__7TObjectFv(void *, s32);
s32 set_player_quest_control_flag(void *);

void TUnk_804B7C04::run_task() { if (this->m_2c == 1) { queue_destruction__7TObjectFv(this); } }

u8 *TNpcPlayer::destroy_and_materialize_player(s16 arg1) {
    u8 *player_object;

    if (this != NULL) {
        *(s32 **)((s8 *)((u8 *)this) + 0x18) = lbl_804B7C04;
        player_object = create_player_object(*(u16 *)((s8 *)((u8 *)this) + 0x30), 6, build_npc_player_record__10TNpcPlayerFl(*(s32 *)((s8 *)((u8 *)this) + 0x34)));
        if (player_object != NULL) {
            *(s16 *)((s8 *)player_object + 0x324) = 6;
            if ((s32) this->m_38 == 1) {
                queue_player_injured_pose();
                set_player_quest_control_flag(player_object);
            }
            send_6x24_teleport_player(*(u16 *)((s8 *)((u8 *)this) + 0x30), ((u8 *)this) + 0x1C, *(s32 *)&this->_pad28);
        }
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return ((u8 *)this);
}

Npc_80190F3C *TNpcPlayer__sub_80190F3C(Npc_80190F3C *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6) {
    __ct__7TObjectFP7TObject(arg0, arg6);
    arg0->f18 = ((u8 *)&lbl_804B7C04);
    VecCopy((Vec *)arg0->f1C, (const Vec *)arg1);
    arg0->f28 = arg2;
    arg0->f30 = arg3;
    arg0->f34 = arg4;
    arg0->f2C = 0;
    arg0->f38 = arg5;
    TNpcPlayer::ensure_rock_singleton();
    TLobby::request_file_read((s32)lbl_80445910, (s32)lbl_805D5860, &arg0->f2C, (void **)0);
    return arg0;
}

void TLobby__sub_80190FD0(int a0) { npc_proximity_target_id = a0; }

void TUnk_804B7C1C::render() {  }
typedef char RecoveredGlobal_8019118C_lbl_804B7BD8_size[sizeof(RecoveredGlobal_8019118C_lbl_804B7BD8) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8019118C_lbl_804B7C1C_size[sizeof(RecoveredGlobal_8019118C_lbl_804B7C1C) == 0x3C ? 1 : -1];

void TUnk_804B7C1C::run_task() {
    Npc_80190FDC *arg0 = (Npc_80190FDC *)this;
    Ply_80190FDC *p;
    void *o;
    if (npc_proximity_target_id == arg0->f8C) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    p = (Ply_80190FDC *)get_player_by_client_id(local_client_id);
    if (p == 0) {
        return;
    }
    if (horizontal_distance_squared(arg0->pos, p->pos) <= arg0->f68 * arg0->f68) {
        ((TUnk_804AF8A0 *)arg0)->set_indexed_flags(0, 1);
        if (arg0->fB4 == 0) {
            arg0->fB4 = 1;
            o = __nw__7TObjectFUl(0x3C);
            if (o != 0) {
                TNpcPlayer__sub_80190F3C((Npc_80190F3C *)o, arg0->pos, arg0->f60, arg0->fAC, arg0->fB0, arg0->f88, tl_07);
            }
        }
    } else {
        p = (Ply_80190FDC *)get_player_by_client_id(arg0->fAC);
        if (p != 0 && arg0->fB4 == 1 && ((TObjPlayer *)p)->is_inactive() == 1) {
            ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 1);
            arg0->fB4 = 0;
            p = (Ply_80190FDC *)get_player_by_client_id(arg0->fAC);
            if (p != 0) {
                queue_destruction__7TObjectFv((p));
            }
        }
    }
}

Obj_801910F4 *__dt__13TUnk_804B7C1CFv(Obj_801910F4 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->f18 = ((u8 *)&lbl_804B7C1C);
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        u32 id = arg0->fAC;
        if (id != 0xFFFF) {
            Ctrl_801910F4 *c = (Ctrl_801910F4 *)get_player_by_client_id(id);
            if (c != NULL && c != NULL) {
                c->v0(1);
            }
        }
        __dt__13TUnk_804AF8A0Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TLobby__sub_8019118C(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__13TUnk_804AF8A0FP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804B7C1C.value;
    ((TUnk_804B7C1C *)(arg0))->apply_object_set_data((void *)arg2);
    *(s16 *)((s8 *)arg0 + 0xAC) = 3;
    ((TUnk_804B7C1C *)arg0)->m_b0 = (s32) ((TUnk_804B7C1C *)arg0)->set_params[0];
    *(s32 *)((s8 *)arg0 + 0xB4) = 0;
    init_collision_body_parts(arg0, &npc_player_collision_body_part.value, 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    return arg0;
}

}
