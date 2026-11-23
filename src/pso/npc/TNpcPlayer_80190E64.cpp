#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/TUnk_804B7C1C.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TUnk_804B7C04.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/npc/TNpcPlayer_80190E64.h"
#include "pso/unk/TLobby_80191218.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer_801BDF5C.h"

extern "C" void *__ct__14TObjCollidableFP7TObject(void *, s32);

CollisionBody npc_player_collision_body_part = {{0.0f, 5.0f, 0.0f}, 7.0f, 50.0f, 0, 0x30003, {0.0f, 0.0f, 0.0f}, 0.0f};

struct RecoveredGlobal_8019118C_lbl_804B7C1C {
    s32 value;
    u8 remaining[0x38];
};

struct Base_801910F4 { u8 pad0[0x18]; };

struct Ctrl_801910F4 : Base_801910F4 { virtual void v0(int); };

struct Obj_801910F4 { u8 pad0[0x18]; void *f18; u8 pad1C[0x90]; u16 fAC; };

struct Ctrl_801910F4;
struct Npc_80190FDC { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0x1C]; s32 f60; u8 pad64[4]; f32 f68; u8 pad6C[0x1C]; s32 f88; s32 f8C; u8 pad90[0x1C]; u16 fAC; u8 padAE[2]; s32 fB0; s32 fB4; };

struct Ply_80190FDC { u8 pad0[0x38]; f32 pos[3]; };

extern "C" {
s32 init_collision_body_parts(void *, void *, int);
extern RecoveredGlobal_8019118C_lbl_804B7C1C __vt__13TUnk_804B7C1C;
u8 *TLobby__sub_8019118C(u8 *actor, s32 arg1, saddr arg2);
extern s32 npc_player_char_data_buffer;
void free_collision_body_parts(void *);
f32 horizontal_distance_squared(void *, void *);
int npc_proximity_target_id = -1;
void TLobby__sub_80190FD0(int a0);
void send_6x24_teleport_player(u16 slot, void *pos, s32 heading);
s32 queue_player_injured_pose();
}
void set_player_quest_control_flag(TObjPlayer *player);

#pragma defer_codegen on
int hashi_versus2_flag;


void TObjHashiVersus2__sub_801912B0(void) { hashi_versus2_flag = 0; }

void TObjHashiVersus2__sub_801912A4(void) { hashi_versus2_flag = 1; }

void set_player_quest_control_flag(TObjPlayer *player) {
    player->set_state_flags(0x8000);
}


void TLobby__sub_80191270(void) { npc_proximity_target_id = -1; }

void TLobby__sub_80191264(void) { npc_proximity_target_id = -1; }

void *TLobby::create_npc(void *set_data) {
    void *o = TObject::operator new(0xB8);
    if (o != NULL) {
        o = TLobby__sub_8019118C((u8 *)o, (saddr)tl_05, (saddr)set_data);
    }
    return o;
}
u8 *TLobby__sub_8019118C(u8 *actor, s32 arg1, saddr set_data) {
    __ct__14TObjCollidableFP7TObject(actor, arg1);
    *(s32 **)((s8 *)actor + 0x18) = &__vt__13TUnk_804B7C1C.value;
    ((TUnk_804B7C1C *)(actor))->apply_object_set_data((void *)set_data);
    *(s16 *)((s8 *)actor + 0xAC) = 3;
    ((TUnk_804B7C1C *)actor)->m_b0 = (s32) ((TUnk_804B7C1C *)actor)->set_params[0];
    *(s32 *)((s8 *)actor + 0xB4) = 0;
    init_collision_body_parts(actor, &npc_player_collision_body_part, 1);
    ((TObjPlayer *)actor)->register_object_by_id();
    return actor;
}

TUnk_804B7C1C::~TUnk_804B7C1C() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
    u32 id = ((Obj_801910F4 *)this)->fAC;
    if (id != 0xFFFF) {
        Ctrl_801910F4 *c = (Ctrl_801910F4 *)get_player_by_client_id(id);
        if (c != NULL && c != NULL) {
            c->v0(1);
        }
    }
}

void TUnk_804B7C1C::run_task() {
    Npc_80190FDC *arg0 = (Npc_80190FDC *)this;
    Ply_80190FDC *p;
    if (npc_proximity_target_id == arg0->f8C) {
        ((TObject *)arg0)->queue_destruction();
        return;
    }
    p = (Ply_80190FDC *)get_player_by_client_id(local_client_id);
    if (p == 0) {
        return;
    }
    if (horizontal_distance_squared(arg0->pos, p->pos) <= arg0->f68 * arg0->f68) {
        ((TObjCollidable *)arg0)->set_indexed_flags(0, 1);
        if (arg0->fB4 == 0) {
            arg0->fB4 = 1;
            new TUnk_804B7C04(arg0->pos, arg0->f60, arg0->fAC, arg0->fB0, arg0->f88, tl_07);
        }
    } else {
        p = (Ply_80190FDC *)get_player_by_client_id(arg0->fAC);
        if (p != 0 && arg0->fB4 == 1 && ((TObjPlayer *)p)->is_inactive() == 1) {
            ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
            arg0->fB4 = 0;
            p = (Ply_80190FDC *)get_player_by_client_id(arg0->fAC);
            if (p != 0) {
                ((TObject *)p)->queue_destruction();
            }
        }
    }
}

void TUnk_804B7C1C::render() {  }

void TLobby__sub_80190FD0(int a0) { npc_proximity_target_id = a0; }


TUnk_804B7C04::TUnk_804B7C04(f32 *position, s32 heading, s32 slot, s32 record, s32 mode, TObject *parent)
    : TObject(parent) {
    VecCopy((Vec *)this->position, (const Vec *)position);
    this->heading = heading;
    this->slot = slot;
    unk_34 = record;
    m_2c = 0;
    unk_38 = mode;
    TNpcPlayer::ensure_rock_singleton();
    TLobby::request_file_read("npcplayerchar.dat", (s32)npc_player_char_data_buffer, (s32 *)&m_2c, (void **)0);
}

TUnk_804B7C04::~TUnk_804B7C04() {
    u8 *player_object = create_player_object(slot, 6, TNpcPlayer::build_npc_player_record(this->unk_34));
    if (player_object != NULL) {
        *(s16 *)((s8 *)player_object + 0x324) = 6;
        if (this->unk_38 == 1) {
            queue_player_injured_pose();
            set_player_quest_control_flag((TObjPlayer *)player_object);
        }
        send_6x24_teleport_player(slot, position, heading);
    }
}

void TUnk_804B7C04::run_task() { if (this->m_2c == 1) { queue_destruction(); } }

