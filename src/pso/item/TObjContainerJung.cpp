#include "pso/misc/RenderFadeState.h"
#include "pso/system/vector.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/item/TObjContainerJungEnemy.h"
#include "pso/item/TObjContainerIdo.h"
#include "pso/item/TUnk_804B97C0.h"
#include "pso/misc/TContainerAncient01.h"
#include "pso/misc/TContainerAncient01R.h"
#include "types.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/item/TObjContainerJungEx_8018D900.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/object/TObjChip.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/item/TObjContainerJungEx.h"
#include "pso/item/TObjContainerItem.h"
#include "pso/item/TObjContainerJung.h"

extern "C" {
u32 init_collision_body_parts(void *, s32, s32);

s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);

#pragma push
#pragma fp_contract on
#pragma pop

s32 post_translate_matrix(void *);
void draw_ginja_object(void *);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();
void *__nw__7TObjectFUl(int);

#pragma push
#pragma fp_contract on
#pragma pop

extern void *tl_05;

}

struct Obj_8018CBF0 { u8 pad0[0x84]; s32 id; };

struct Obj_8018CB44 { u8 pad0[0x1C]; u16 f1C; u8 pad1[0x62]; u32 f80; s32 f84; };

struct Pkt_8018CB44 { u16 a; u16 b; s32 c; s32 d; s32 e; };

extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void debug_printf_at(s32 id, const char *fmt, ...);
extern char lbl_80445430[];
extern char lbl_8044543C[];
s32 get_current_floor();
extern s32 local_client_id;

s32 scale_matrix(s32, f32, f32, f32);

void TObjContainerJungEnemy::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            ((TObjContainerJungEnemy *)arg0)->vfunc_79();
            ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 1);
            ((TUnk_804AF8A0 *)arg0)->set_flag8();
            queue_destruction__7TObjectFv((arg0));
            this->mode = 1;
        }
    } else if ((s16) *arg1 == 1) {
        ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 1);
        ((TUnk_804AF8A0 *)arg0)->set_flag8();
        queue_destruction__7TObjectFv((arg0));
        this->mode = 1;
    }
}

struct Vec_8018C9F0 { f32 x, y, z; };
struct Spawn_8018C9F0 {
    u8 pad0[0xC];
    Vec_8018C9F0 pos;
    u8 pad18[0x20];
    f32 f38;
    u8 pad3c[4];
    s32 f40;
    s32 f44;
    u8 pad48[4];
};
struct Obj_8018C9F0 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x10];
    Vec_8018C9F0 pos;
    u8 pad44[0x326 - 0x44];
    s16 f326;
    u8 pad328[0x36C - 0x328];
    s32 f36c;
    s32 f370;
};

void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
u8 *construct_debris__8TObjChipFPvPvPv(u8 *arg0, u8 *arg1, u8 *arg2);
}
void play_container_break_sound(s32 arg0);
extern Spawn_8018C9F0 lbl_80445398;
extern Spawn_8018C9F0 lbl_804453E4;

#pragma push
#pragma opt_propagation off
extern "C" {
void TObjContainerJungEnemy__vt77(const Obj_8018C9F0 *self) {
    if (self->f326 != 1) {
        Spawn_8018C9F0 a = lbl_80445398;
        f32 za;
        f32 ya;
        f32 xa;
        xa = self->pos.x;
        ya = self->pos.y;
        za = self->pos.z;
        a.pos.x = xa;
        a.pos.y = ya;
        a.pos.z = za;
        a.f38 = ya;
        a.f40 = self->f36c;
        a.f44 = self->f24;
        Spawn_8018C9F0 b = lbl_804453E4;
        f32 zb;
        f32 yb;
        f32 xb;
        xb = self->pos.x;
        yb = self->pos.y;
        zb = self->pos.z;
        b.pos.x = xb;
        b.pos.y = yb;
        b.pos.z = zb;
        b.f38 = yb;
        b.f40 = self->f370;
        b.f44 = self->f24;
        spawn_particle_effect_with_flags((void *)&self->pos, 0x45, 0x40);
        spawn_particle_effect_with_flags((void *)&self->pos, 0x46, 0x40);
        void *o = __nw__7TObjectFUl(0x234);
        if (o != 0) {
            construct_debris__8TObjChipFPvPvPv((u8 *)o, (u8 *)tl_05, (u8 *)&a);
        }
        o = __nw__7TObjectFUl(0x234);
        if (o != 0) {
            construct_debris__8TObjChipFPvPvPv((u8 *)o, (u8 *)tl_05, (u8 *)&b);
        }
        play_container_break_sound((s32)self);
    }
}
#pragma pop

f32 TObjContainerJungEnemy::receive_physical_attack(void *, f32) {
    Obj_8018CB44 *arg0 = (Obj_8018CB44 *)this;
    s16 sp8;
    Pkt_8018CB44 pkt;
    if ((this->entity_id >= 0x1000U) && (arg0->f80 != 0U) && (((TUnk_804AF8A0 *)arg0)->access_object_saved_state(&sp8, 1) != 0)) {
        sp8 = 1;
        ((TUnk_804AF8A0 *)arg0)->access_object_saved_state(&sp8, 0);
        ((TUnk_804AF8A0 *)arg0)->send_object_state_update(&sp8);
        ((TLobby *)(&pkt))->init_packet_67_04();
        pkt.b = this->entity_id;
        pkt.c = get_current_floor();
        pkt.d = this->m_84;
        pkt.e = local_client_id;
        ((TLobby *)(&pkt))->byteswap_and_send();
    }
    return 0.0f;
}

void TObjContainerJungEnemy::debug_print_item_box_info() {
    Obj_8018CBF0 *self = (Obj_8018CBF0 *)this;
    ((TObjContainerJungEnemy *)self)->load_models();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, lbl_80445430, this->m_84);
    debug_printf_at(0x130021, lbl_8044543C);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TObjContainerJungEnemy::vfunc_81() {

    switch (this->mode) {
    case 0:
        TObjFish::set_global_param(this->texture_id);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        scale_matrix(0, 0.85f, 0.85f, 0.85f);
        draw_ginja_object(*(void * *)&this->m_368);
        TParticleCtrl::begin_effect_render();
        draw_ginja_object(*(void * *)&this->m_374);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    case 1:
        return;
    }
}
}

struct RecoveredGlobal_8018CEDC_lbl_804B7168 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8018CEDC___vt__22TObjContainerJungEnemy {
    s32 value;
    u8 remaining[0x148];
};

extern "C" {
u32 init_collision_body_parts(void *, s32, s32);
u8 * init_container_base(void *, s32);
extern RecoveredGlobal_8018CEDC_lbl_804B7168 container_jung_collision_desc;
extern s32 __vt__22TObjContainerJungEnemy[];
extern s32 TObjContainerJungEnemy__name;
s32 get_model__19TObjContainerJungExFl(s32);
s32 TObjContainerJung__sub_8018D3B8(s32);
s32 get_model_by_index__17TObjContainerJungFl(s32);
s32 free_collision_body_parts(void *);
s32 submit_cursor_candidate(void *, s32);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjContainerJungEnemy::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->m_364 != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerJungEnemy::load_models() {
    s32 var_r0;
    s32 temp_r3 = *(s32 *)&this->m_88;
    if (temp_r3 < 0) {
        var_r0 = 0;
    } else {
        var_r0 = 1;
        if (temp_r3 <= 1) {
            var_r0 = temp_r3;
        }
    }
    switch (var_r0) {
    case 0:
        this->m_368 = get_model_by_index__17TObjContainerJungFl(0);
        this->m_36c = get_model_by_index__17TObjContainerJungFl(1);
        this->m_370 = get_model_by_index__17TObjContainerJungFl(2);
        this->m_374 = get_model_by_index__17TObjContainerJungFl(3);
        this->texture_id = TObjContainerJung__sub_8018D3B8(0);
        return;
    default:
    case 1:
        this->m_368 = get_model__19TObjContainerJungExFl(0);
        this->m_36c = get_model__19TObjContainerJungExFl(1);
        this->m_370 = get_model__19TObjContainerJungExFl(2);
        this->m_374 = get_model__19TObjContainerJungExFl(3);
        this->texture_id = (s32)TObjContainerJungEx__sub_8018D900(0);
        return;
    }
}

extern void *tl_05;

void *TObjContainerJungEnemy::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x378);
    if (o != NULL) {
        o = TObjContainerJungEnemy__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void *__dt__22TObjContainerJungEnemyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__22TObjContainerJungEnemy;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B6C24 *)arg0)->destroy_container_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8018CEDC_lbl_804B7168_size[sizeof(RecoveredGlobal_8018CEDC_lbl_804B7168) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8018CEDC___vt__22TObjContainerJungEnemy_size[sizeof(RecoveredGlobal_8018CEDC___vt__22TObjContainerJungEnemy) == 0x14C ? 1 : -1];
u8 *TObjContainerJungEnemy__ct(u8 *arg0, s32 arg1, s32 _w2) {
    init_container_base(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8018CEDC___vt__22TObjContainerJungEnemy *)&__vt__22TObjContainerJungEnemy).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjContainerJungEnemy__name;
    ((TObjContainerJungEnemy *)arg0)->load_models();
    ((TObjContainerJungEnemy *)arg0)->mode = 0;
    ((TObjContainerJungEnemy *)arg0)->actorFlags = (s32) (((TObjContainerJungEnemy *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, (s32) &container_jung_collision_desc.value, 1);
    ((TObjPlayer *)arg0)->reset_photon_effect();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) (*(f32 *)((s8 *)arg0 + 0x78) + *(f32 *)((s8 *)&container_jung_collision_desc.value + 4));
    return arg0;
}

}

struct RecoveredGlobal_8018D314_lbl_804B7168 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8018D314___vt__19TObjContainerJungEx {
    s32 value;
    u8 remaining[0x148];
};

struct Vec_8018CFD4 { f32 x, y, z; };

struct Spawn_8018CFD4 {
    u8 pad0[0xC];
    Vec_8018CFD4 pos;
    u8 pad18[0x38 - 0x18];
    f32 f38;
    u8 pad3c[4];
    s32 f40;
    s32 f44;
    u8 pad48[4];
};

struct Obj_8018CFD4 { u8 pad[0x38]; Vec_8018CFD4 pos; };

extern "C" {
u32 init_collision_body_parts(void *, s32, s32);
u8 * init_container_base(void *, s32);

extern s32 __vt__19TObjContainerJungEx[];
extern s32 TObjContainerJungEx__name;
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
}
void play_container_break_sound(s32 arg0);
extern "C" {
s32 get_model__19TObjContainerJungExFl(s32);
void *__nw__7TObjectFUl(int);
extern Spawn_8018CFD4 container_jung_ex_spawn_params_a;
extern Spawn_8018CFD4 container_jung_ex_spawn_params_b;
extern void *tl_05;
void TObjContainerJungEx__vt77(const Obj_8018CFD4 *self);
s32 post_translate_matrix(void *);
s32 scale_matrix(s32, f32, f32, f32);

s32 free_collision_body_parts(void *);
s32 submit_cursor_candidate(void *, s32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 __dl__7TObjectFPv(void *);
s32 set_global_param__8TObjFishFl();

void *TObjContainerJungEx::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x368);
    if (o != NULL) {
        o = TObjContainerJungEx__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

#pragma push
#pragma opt_propagation off
void TObjContainerJungEx__vt77(const Obj_8018CFD4 *self) {
    Spawn_8018CFD4 a = container_jung_ex_spawn_params_a;
    f32 pz;
    f32 py;
    f32 px;
    px = self->pos.x;
    py = self->pos.y;
    pz = self->pos.z;
    a.pos.x = px;
    a.pos.y = py;
    a.pos.z = pz;
    a.f38 = py;
    a.f40 = get_model__19TObjContainerJungExFl(1);
    a.f44 = (s32)TObjContainerJungEx__sub_8018D900(0);
    Spawn_8018CFD4 b = container_jung_ex_spawn_params_b;
    f32 qz;
    f32 qy;
    f32 qx;
    qx = self->pos.x;
    qy = self->pos.y;
    qz = self->pos.z;
    b.pos.x = qx;
    b.pos.y = qy;
    b.pos.z = qz;
    b.f38 = qy;
    b.f40 = get_model__19TObjContainerJungExFl(2);
    b.f44 = (s32)TObjContainerJungEx__sub_8018D900(0);
    spawn_particle_effect_with_flags((void *)&self->pos, 0x45, 0x40);
    spawn_particle_effect_with_flags((void *)&self->pos, 0x46, 0x40);
    void *o = __nw__7TObjectFUl(0x234);
    if (o != NULL) {
        construct_debris__8TObjChipFPvPvPv((u8 *)o, (u8 *)tl_05, (u8 *)&a);
    }
    o = __nw__7TObjectFUl(0x234);
    if (o != NULL) {
        construct_debris__8TObjChipFPvPvPv((u8 *)o, (u8 *)tl_05, (u8 *)&b);
    }
    play_container_break_sound((s32)self);
}
#pragma pop

void TObjContainerJungEx::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            this->vfunc_79();
            ((TUnk_804B6C24 *)arg0)->spawn_item((s32)arg0);
            ((TUnk_804AF8A0 *)arg0)->set_flag8();
            queue_destruction__7TObjectFv((arg0));
            this->mode = 1;
        }
    } else if ((s16) *arg1 == 1) {
        ((TUnk_804AF8A0 *)arg0)->set_flag8();
        queue_destruction__7TObjectFv((arg0));
        this->mode = 1;
    }
}

void TObjContainerJungEx::vfunc_81() {

    switch (this->mode) {
    case 0:
        TObjContainerJungEx__sub_8018D900(0);
        set_global_param__8TObjFishFl();
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        scale_matrix(0, 0.85f, 0.85f, 0.85f);
        draw_ginja_object((void *)get_model__19TObjContainerJungExFl(0));
        TParticleCtrl::begin_effect_render();
        draw_ginja_object((void *)get_model__19TObjContainerJungExFl(3));
        TParticleCtrl::end_effect_render();
        pop_matrix();
    case 1:
        return;
    }
}

void TObjContainerJungEx::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->m_364 != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void *__dt__19TObjContainerJungExFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TObjContainerJungEx;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B6C24 *)arg0)->destroy_container_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8018D314_lbl_804B7168_size[sizeof(RecoveredGlobal_8018D314_lbl_804B7168) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8018D314___vt__19TObjContainerJungEx_size[sizeof(RecoveredGlobal_8018D314___vt__19TObjContainerJungEx) == 0x14C ? 1 : -1];
u8 *TObjContainerJungEx__ct(u8 *arg0, s32 arg1, s32 _w2) {
    init_container_base(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8018D314___vt__19TObjContainerJungEx *)&__vt__19TObjContainerJungEx).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjContainerJungEx__name;
    ((TObjContainerJungEx *)arg0)->mode = 0;
    ((TObjContainerJungEx *)arg0)->actorFlags = (s32) (((TObjContainerJungEx *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, (s32) &container_jung_collision_desc.value, 1);
    ((TObjPlayer *)arg0)->reset_photon_effect();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) (*(f32 *)((s8 *)arg0 + 0x78) + *(f32 *)((s8 *)&container_jung_collision_desc.value + 4));
    return arg0;
}
}

struct RecoveredGlobal_8018D47C_lbl_804B7134 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8018D47C_lbl_804B7134_size[sizeof(RecoveredGlobal_8018D47C_lbl_804B7134) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8018D85C_lbl_804B7168 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8018D85C___vt__17TObjContainerJung {
    s32 value;
    u8 remaining[0x148];
};

struct Vec_8018D4DC { f32 x, y, z; };

struct Spawn_8018D4DC {
    u8 pad0[0xC];
    Vec_8018D4DC pos;
    u8 pad18[0x20];
    f32 f38;
    u8 pad3c[4];
    s32 f40;
    s32 f44;
    u8 pad48[4];
};

struct Obj_8018D4DC {
    u8 pad0[0x38];
    Vec_8018D4DC pos;
    u8 pad44[0x326 - 0x44];
    s16 f326;
};

extern "C" {
u8 * get_bml_model(void *, int);
extern s32 TObjContainerJung__bml_model_resource;
s32 TObjFish__sub_8001EDB0(void *, s32);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8018D47C_lbl_804B7134 TObjContainerJung__resource_descriptor;
extern s32 TObjContainerJung__bml_aux_handle;
u32 init_collision_body_parts(void *, s32, s32);
u8 * init_container_base(void *, s32);

extern s32 __vt__17TObjContainerJung[];
extern s32 TObjContainerJung__name;
s32 scale_matrix(s32, f32, f32, f32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 post_translate_matrix(void *);

void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
}
void play_container_break_sound(s32 arg0);
extern "C" {
void *__nw__7TObjectFUl(int);
extern Spawn_8018D4DC container_jung_debris_desc;
extern Spawn_8018D4DC container_jung_spawn_params;
extern void *tl_05;
void TObjContainerJung__vt77(const Obj_8018D4DC *self);
s32 TLobby__sub_8001FE7C(s32, s32);
s32 free_collision_body_parts(void *);
s32 submit_cursor_candidate(void *, s32);
s32 __dl__7TObjectFPv(void *);

s32 TObjContainerJung__sub_8018D3B8(s32) {
    return TObjContainerJung__bml_aux_handle;
}

u8 *TObjContainerJung::get_model_by_index(s32 arg0) {
    if ((void *) (*(u8 * *)&TObjContainerJung__bml_model_resource) != NULL) {
        return get_bml_model((*(u8 * *)&TObjContainerJung__bml_model_resource), arg0);
    }
    return NULL;
}

void *TObjContainerJung::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x368);
    if (o != NULL) {
        o = TObjContainerJung__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TObjContainerJung::release() {
    TLobby__sub_8001FE7C(TObjContainerJung__bml_model_resource, 1);
    TObjContainerJung__bml_model_resource = 0;
    TObjContainerJung__bml_aux_handle = 0;
}

void TObjContainerJung::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = ((TAdSinglePlyChrSelectGC *)((void *)0x440))->alloc();
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &TObjContainerJung__resource_descriptor.value, 0, 0, 0));
    }
    (*(u8 * *)&TObjContainerJung__bml_model_resource) = (unsigned char *) ((void *) var_r0);
    TObjContainerJung__bml_aux_handle = TObjFish__sub_8001EDB0((void *) var_r0, 0);
}

#pragma push
#pragma opt_propagation off
void TObjContainerJung__vt77(const Obj_8018D4DC *self) {
    void *o;
    if (self->f326 != 1) {
        Spawn_8018D4DC a = container_jung_debris_desc;
        f32 pz;
        f32 py;
        f32 px;
        px = self->pos.x;
        py = self->pos.y;
        pz = self->pos.z;
        a.pos.x = px;
        a.pos.y = py;
        a.pos.z = pz;
        a.f38 = py;
        a.f40 = (s32) get_bml_model((void *) TObjContainerJung__bml_model_resource, 1);
        a.f44 = TObjContainerJung__bml_aux_handle;
        Spawn_8018D4DC b = container_jung_spawn_params;
        f32 qz;
        f32 qy;
        f32 qx;
        qx = self->pos.x;
        qy = self->pos.y;
        qz = self->pos.z;
        b.pos.x = qx;
        b.pos.y = qy;
        b.pos.z = qz;
        b.f38 = qy;
        b.f40 = (s32) get_bml_model((void *) TObjContainerJung__bml_model_resource, 2);
        b.f44 = TObjContainerJung__bml_aux_handle;
        spawn_particle_effect_with_flags((void *)&self->pos, 0x45, 0x40);
        spawn_particle_effect_with_flags((void *)&self->pos, 0x46, 0x40);
        o = __nw__7TObjectFUl(0x234);
        if (o != 0) {
            construct_debris__8TObjChipFPvPvPv((u8 *)o, (u8 *)tl_05, (u8 *)&a);
        }
        o = __nw__7TObjectFUl(0x234);
        if (o != 0) {
            construct_debris__8TObjChipFPvPvPv((u8 *)o, (u8 *)tl_05, (u8 *)&b);
        }
        play_container_break_sound((s32)self);
    }
}
#pragma pop

void TObjContainerJung::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            this->vfunc_79();
            ((TUnk_804806E8 *)arg0)->request_box_item_drop((u8 *)&this->position, 1);
            ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 1);
            ((TUnk_804AF8A0 *)arg0)->set_flag8();
            queue_destruction__7TObjectFv((arg0));
            this->mode = 1;
        }
    } else if ((s16) *arg1 == 1) {
        ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 1);
        ((TUnk_804AF8A0 *)arg0)->set_flag8();
        queue_destruction__7TObjectFv((arg0));
        this->mode = 1;
    }
}

void TObjContainerJung::vfunc_81() {
    if ((void *)(*(u8 **)&TObjContainerJung__bml_model_resource) != NULL) {
        switch (this->mode) {
        case 0:
            TObjFish::set_global_param(TObjContainerJung__bml_aux_handle);
            push_matrix();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            scale_matrix(0, 0.85f, 0.85f, 0.85f);
            draw_ginja_object((void *)get_bml_model(*(u8 **)&TObjContainerJung__bml_model_resource, 0));
            TParticleCtrl::begin_effect_render();
            draw_ginja_object((void *)get_bml_model(*(u8 **)&TObjContainerJung__bml_model_resource, 3));
            TParticleCtrl::end_effect_render();
            pop_matrix();
            break;
        case 1:
            break;
        }
    }
}

void TObjContainerJung::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->m_364 != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void *__dt__17TObjContainerJungFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TObjContainerJung;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B6C24 *)arg0)->destroy_container_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8018D85C_lbl_804B7168_size[sizeof(RecoveredGlobal_8018D85C_lbl_804B7168) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8018D85C___vt__17TObjContainerJung_size[sizeof(RecoveredGlobal_8018D85C___vt__17TObjContainerJung) == 0x14C ? 1 : -1];
u8 *TObjContainerJung__ct(u8 *arg0, s32 arg1, s32 _w2) {
    init_container_base(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8018D85C___vt__17TObjContainerJung *)&__vt__17TObjContainerJung).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjContainerJung__name;
    ((TObjContainerJung *)arg0)->mode = 0;
    ((TObjContainerJung *)arg0)->actorFlags = (s32) (((TObjContainerJung *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, (s32) &container_jung_collision_desc.value, 1);
    ((TObjPlayer *)arg0)->reset_photon_effect();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) (*(f32 *)((s8 *)arg0 + 0x78) + *(f32 *)((s8 *)&container_jung_collision_desc.value + 4));
    return arg0;
}
}
