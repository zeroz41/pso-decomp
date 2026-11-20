#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/text_803D853C.h"
#include "pso/boss/dragon/TBoss1DragonColli.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/TUnk_804E4B24.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/barbaray/TObjBoss7TunnelCol.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_802F1D1C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/TUnk_804E4AD4.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/TUnk_804E4B3C.h"
#include <stddef.h>
#include "pso/effect/item/TItemEffOrgaFlowShot.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_802F2070.h"
#include "pso/unk/text_802F0E24.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer_80011014.h"
#include <stdlib.h>
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

struct Nd_802F2348 { u8 pad[0xC]; Nd_802F2348 *next; };
struct Li_802F2348 { u8 pad[0x14]; Nd_802F2348 *head; };
// count + index list; the TUnk_804E4B24 constructor copies both into the segment it builds
struct Boss2TunnelEffectEntry {
    s32 count;
    const s32 *indices;
};
const s32 lbl_804743B0[3] = {0, 1, 2};
const s32 lbl_804743BC[4] = {3, 4, 5, 6};
const s32 lbl_804743CC[3] = {7, 8, 9};
const s32 lbl_804743D8[3] = {10, 11, 12};
const s32 lbl_804743E4[4] = {13, 14, 15, 16};
// where TObjBoss2Tunnel__sub_802F2A2C places its two TObjBoss7RaftSplash
const Vec TObjBoss2Tunnel__raft_splash_offset_table[2] = {{3.0f, 0.0f, -5.0f}, {-3.0f, 0.0f, -5.0f}};
const char *TObjBoss7TunnelCol__name = "TObjBoss7TunnelCol";
const CollisionBody TObjBoss7TunnelCol__col_desc = {{0.0f, 0.0f, 0.0f}, 100.0f, 9.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};
Boss2TunnelEffectEntry boss2_tunnel_effect_name_table[5] = {
    {3, lbl_804743B0},
    {4, lbl_804743BC},
    {3, lbl_804743CC},
    {3, lbl_804743D8},
    {4, lbl_804743E4},
};
s32 boss2_tunnel_spawn_timer_table[0x1F] = {
    2, 1, 2, 1, 1, 2, 2, 1, 2, 1, 2, 2, 1, 1, 1, 2,
    1, 2, 1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1,
};
s32 boss2_tunnel_spawn_timer_table_b[10] = {1, 1, 3, 4, 3, 3, 3, 3, 3, 3};
// y comes from a float constant of another file, so this file's static
// initializer (0x802F2CC4, .ctors 0x80433FDC) fills it in at startup.
extern "C" const f32 lbl_805DE9F4;
Vec lbl_804E4A44[2] = {
    {78.0f, lbl_805DE9F4, 83.0f},
    {-78.0f, lbl_805DE9F4, 83.0f},
};
u32 boss2_tunnel_state_flags;
s32 lbl_805D696C;
s8 lbl_805D6970;
extern "C" {
AnimationMotion *get_bml_motion(void *, s32);
s32 get_bml_model(void *, s32);
u32 __ct__7TObjectFP7TObject(void *, void *);
extern u8 *boss7_common_bml_resource;
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
}
extern "C" void *__ct__14TObjCollidableFP7TObject(void *, TObject *);
extern "C" {
void __dl__7TObjectFPv(void *);
s32 get_mode__11TCameraCtrlFPv(void *p);
extern s32 __vt__18TObjBoss7TunnelCol[];
}
struct GE_802F1DAC { s32 a, b, obj, d; };
struct GE_802F1E54 { s32 a, b, obj, d; };
extern "C" {
s32 draw_ginja_object(int);
s32 is_in_camera_range__18TObjBoss7TunnelColFv(void *);
extern u8 *boss7_common_bml_resource;
extern u8 *boss7_common_texture_list;
void __dt__7TObjectFv(void *, int);
void __dl__7TObjectFPv(void *);
u32 __nw__7TObjectFUl(s32);
void TObjBoss2Tunnel__sub_802F2278(void);
s32 TObjBoss2Tunnel__sub_802F22F4(void);
s32 init_piecewise_curve(void *, f32, f32, f32, f32, f32);
f32 update_position__15TObjBoss2TunnelFv(void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void TObjBoss2Tunnel__sub_802F2C4C(void);
void TObjBoss2Tunnel__sub_802F2C50(void);
void TObjBoss2Tunnel__sub_802F2C84(void);
void TObjBoss2Tunnel__sub_802F22DC(void);
void TObjBoss2Tunnel__sub_802F22C4(void);
s32 query_teammate_state__9TObjEneDDFv();
}
void draw_particle_effect(void *a0);
void draw_tunnel_segment(u8 *arg0);
extern "C" {
void fn_802F1DAC(u8 *arg0);
void fn_802F1E54(u8 *arg0);
s32 is_room_enemy_set_cleared(s32 floor, s16 room);
u8 *TObjBoss7RaftSplash__ct(u8 *object, u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4);
f32 rand_signed_unit();
u8 *__ct__13TObjBoss7DustFv(u8 *arg0, s32 arg1, s32 arg2);
s32 TObjBoss2Tunnel__sub_802F2070(void);
}

// Written last-to-first: the TU was compiled with deferred codegen, which emits functions in reverse
// order of definition (and the vtables in .text order).
#pragma defer_codegen on

f32 TUnk_804E4B3C::sub_802F2CBC() {
    return segment_x;
}

f32 TUnk_804E4B3C::sub_802F2CB4() {
    return scroll_speed;
}

void TUnk_804E4B3C::copy_position(const Vec *position) {
    VecCopy(&unk_78, position);
}

void TObjBoss2Tunnel__sub_802F2C84(void) { (*(int *)&boss2_tunnel_state_flags) = 0; }

void TObjBoss2Tunnel__sub_802F2C50(void) {
    new TUnk_804E4B3C(tl_04);
}

void TObjBoss2Tunnel__sub_802F2C4C(void) {  }

#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
TUnk_804E4B3C::TUnk_804E4B3C(TObject *parent) : TObject(parent) {
    s32 i;
    render_nodes = new TObject(this);
    effect_nodes = new TObject(this);
    phase = 0;
    if (is_split_screen() == 0) {
        half_length = 8000.0f;
    } else {
        half_length = 2666.6667f;
    }
    curve.reset_floats();
    sway_state = 0;
    sway_sign = 1.0f;
    segment_x = 0.0f;
    scroll_speed = 0.0f;
    boss2_tunnel_state_flags = 0;
    scroll_offset = 0.0f;
    spawn_index = 0;
    unk_78.x = 0.0f;
    unk_78.y = 0.0f;
    unk_78.z = 0.0f;
    dust_timer = 30;
    for (i = 0; i < 2; i++) {
        u8 *splash = (u8 *)TObject::operator new(0x40);
        if (splash != NULL) {
            TObjBoss7RaftSplash__ct(splash, (u8 *)this, (u8 *)&lbl_804E4A44[i], (u8 *)&TObjBoss2Tunnel__raft_splash_offset_table[i], (s32)&scroll_speed);
        }
    }
    new TUnk_804E4AD4(render_nodes, 0);
    new TUnk_804E4AD4(render_nodes, 1);
    new TUnk_804E4AD4(render_nodes, 2);
    if (lbl_805D6970 == 0) {
        lbl_805D696C = 1;
        lbl_805D6970 = 1;
    }
    if (is_room_enemy_set_cleared(get_current_floor(), 1) == 0) {
        spawn_segment_row_b();
        void *col = TObject::operator new(0xD8);
        if (col != NULL) {
            col = TObjBoss7TunnelCol__ct(col, this);
        }
        tunnel_col = (TObject *)col;
    } else {
        half_length = 8000.0f;
        spawn_segment_row_a();
        phase = 2;
        scroll_speed = 0.0f;
        segment_x = -50.0f;
        tunnel_col = NULL;
        boss2_tunnel_state_flags |= 0x8000;
    }
}
#pragma pop

TUnk_804E4B3C::~TUnk_804E4B3C() {
    if (tunnel_col != NULL) {
        tunnel_col->queue_destruction();
    }
}

void TUnk_804E4B3C::run_task() {
    update_phase_motion();
    static void (TUnk_804E4B3C::*phase_handlers[])() = {
        &TUnk_804E4B3C::init_effect,
        &TUnk_804E4B3C::sub_802F2400,
        &TUnk_804E4B3C::sub_802F23FC,
    };
    void (TUnk_804E4B3C::*handler)() = phase_handlers[phase];
    (this->*handler)();
    sub_802F273C();
}

f32 lbl_804E4AA4[12] = {
    26.0f, -19.0f, 62.0f,
    -26.0f, -19.0f, 62.0f,
    26.0f, -19.0f, 0.0f,
    -26.0f, -19.0f, 0.0f,
};
void TUnk_804E4B3C::update_phase_motion() {
    u8 *arg0 = (u8 *)this;
    f32 sp8;
    switch (*(s32 *)((s8 *)arg0 + 0x4C)) {
    case 0:
        if (TObjBoss2Tunnel::check_both((s32)arg0) != 0) {
            if (TObjBoss2Tunnel::is_phase_active((s32)arg0) != 0) {
                *(f32 *)((s8 *)arg0 + 0x50) = (-1.0f);
            } else {
                *(f32 *)((s8 *)arg0 + 0x50) = 1.0f;
            }
            *(s32 *)((s8 *)arg0 + 0x4C) = 1;
            init_piecewise_curve(arg0 + 0x20, 0.1f, (-0.1f), 150.0f, 5.0f, 2.0f);
            *(f32 *)((s8 *)arg0 + 0x54) = 0.0f;
        }
        break;
    case 1:
        if (TObjBoss2Tunnel::check_both((s32)arg0) == 0) {
            *(s32 *)((s8 *)arg0 + 0x4C) = 3;
            sp8 = fabs_float((f32) (*(f32 *)((s8 *)arg0 + 0x54)));
            init_piecewise_curve(arg0 + 0x20, 0.1f, (-0.1f), (f32) (*(f32 *)((s8 *)arg0 + 0x54)), (f32) (-update_position__15TObjBoss2TunnelFv(arg0 + 0x20)), 2.0f);
            return;
        }
        if (((TObjBoss2Tunnel *)(arg0 + 0x20))->advance_phase(&sp8) != 0) {
            *(s32 *)((s8 *)arg0 + 0x4C) = 2;
        }
        *(f32 *)((s8 *)arg0 + 0x54) = (f32) (sp8 * *(f32 *)((s8 *)arg0 + 0x50));
        return;
    case 2:
        if (TObjBoss2Tunnel::check_both((s32)arg0) == 0) {
            *(s32 *)((s8 *)arg0 + 0x4C) = 3;
            init_piecewise_curve(arg0 + 0x20, 0.1f, (-0.1f), 150.0f, 0.0f, 2.0f);
            return;
        }
        break;
    case 3:
        if (((TObjBoss2Tunnel *)(arg0 + 0x20))->advance_phase(&sp8) != 0) {
            *(f32 *)((s8 *)arg0 + 0x54) = 0.0f;
            *(s32 *)((s8 *)arg0 + 0x4C) = 0;
            return;
        }
        *(f32 *)((s8 *)arg0 + 0x54) = (f32) (*(f32 *)((s8 *)arg0 + 0x50) * (150.0f - sp8));
        break;
    }
}

void TUnk_804E4B3C::sub_802F273C() {  }

void TUnk_804E4B3C::advance_effect_timer() {
    this->scroll_speed += 0.05f;
    if (this->scroll_speed > boss7_tunnel_max_scroll_speed) {
        this->scroll_speed = (f32) boss7_tunnel_max_scroll_speed;
    }
}

// Dead-stripped from the DOL: no code of it survives, only its literal 2.0f
// (.sdata2 0x805DECF8, pooled between update_dust_spawn's 600.0f and
// advance_effect_timer's 0.05f). It sits between the two scroll-speed helpers
// (update_spawn_timer, advance_effect_timer); body and name inferred from that role.
void TUnk_804E4B3C::double_scroll_speed() {
    scroll_speed *= 2.0f;
}

#pragma push
#pragma opt_common_subs off
void TUnk_804E4B3C::update_spawn_timer(s32 arg1, s32 arg2, s32 arg3) {
    Vec position;
    f32 temp_f1;
    this->scroll_offset = (f32) (this->scroll_offset + this->scroll_speed);
    temp_f1 = this->scroll_offset;
    if (temp_f1 >= 800.0f) {
        this->scroll_offset = (f32) (temp_f1 - 800.0f);
        this->spawn_index = (s32) (this->spawn_index + 1);
        if ((s32) this->spawn_index == arg2) {
            if (arg3 != 0) {
                this->spawn_index = (arg2 - 1);
            } else {
                this->spawn_index = 0;
            }
        }
        position.x = this->segment_x;
        position.y = 0.0f;
        position.z = this->half_length - this->scroll_offset;
        spawn(*(s32 *)((s8 *)(arg1 + (this->spawn_index * 4)) + 0), &position);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TUnk_804E4B3C::update_dust_spawn() {
    u8 *arg0 = (u8 *)this;
    Vec v;
    u32 p;
    *(s32 *)((s8 *)arg0 + 0x74) = *(s32 *)((s8 *)arg0 + 0x74) - 1;
    if (*(s32 *)((s8 *)arg0 + 0x74) <= 0) {
        v.x = 200.0f * rand_signed_unit();
        v.y = 90.0f * (3.0517578125e-05f * (f32)rand()) + 10.0f;
        v.z = 600.0f;
        p = __nw__7TObjectFUl(0x30);
        if (p != 0U) {
            __ct__13TObjBoss7DustFv((u8 *)p, (s32)tl_05, (s32)&v);
        }
        *(s32 *)((s8 *)arg0 + 0x74) = 0x1E;
    }
}
#pragma pop

void TUnk_804E4B3C::init_effect() {
    advance_effect_timer();
    update_spawn_timer((s32)boss2_tunnel_spawn_timer_table, 0x1F, 0);
    if ((*(s32 *)&boss2_tunnel_state_flags) & 0x200) {
        (*(s32 *)&boss2_tunnel_state_flags) &= 0xFFFFFDFF;
        phase = 1;
        spawn_index = 0;
    }
    update_dust_spawn();
}

void TUnk_804E4B3C::sub_802F2400() {
    f32 temp_f1;
    TObject *object;
    update_spawn_timer((s32)boss2_tunnel_spawn_timer_table_b, 0xA, 1);
    if ((*(s32 *)&boss2_tunnel_state_flags) & 8) {
        temp_f1 = unk_78.z;
        if (temp_f1 < 1.0f) {
            phase = 2;
            this->scroll_speed = 0.0f;
            segment_x = (-50.0f);
            object = tunnel_col;
            if (object != NULL) {
                object->queue_destruction();
                tunnel_col = NULL;
            }
            (*(s32 *)&boss2_tunnel_state_flags) |= 0x8000;
            return;
        }
        if (temp_f1 < 100.0f) {
            TItemEffOrgaFlowShot::approach_value((f32 *)((s8 *)this + 0x5C), 0.02f, (f32)((f32) (0.1f * boss7_tunnel_max_scroll_speed)));
            TItemEffOrgaFlowShot::approach_value(&segment_x, (-1.0f), (-50.0f));
            return;
        }
        if (temp_f1 < 200.0f) {
            TItemEffOrgaFlowShot::approach_value((f32 *)((s8 *)this + 0x5C), 0.04f, (f32)((f32) (0.2f * boss7_tunnel_max_scroll_speed)));
            TItemEffOrgaFlowShot::approach_value(&segment_x, (-1.0f), (-30.000002f));
            return;
        }
        if (temp_f1 < 300.0f) {
            TItemEffOrgaFlowShot::approach_value((f32 *)((s8 *)this + 0x5C), 0.06f, (f32)((f32) (0.3f * boss7_tunnel_max_scroll_speed)));
            TItemEffOrgaFlowShot::approach_value(&segment_x, (-1.0f), (-15.000001f));
        }
    }
}

void TUnk_804E4B3C::sub_802F23FC() {  }

void TUnk_804E4B3C::render() {
    u8 *arg0 = (u8 *)this;
    Nd_802F2348 *n;
    if (query_teammate_state__9TObjEneDDFv() == 0) {
        for (n = (*(Li_802F2348 **)((s8 *)arg0 + 0x90))->head; n != 0; n = n->next) {
            draw_particle_effect(n);
        }
        for (n = (*(Li_802F2348 * *)&this->effect_nodes)->head; n != 0; n = n->next) {
            fn_802F1E54((u8 *)n);
        }
        for (n = (*(Li_802F2348 * *)&this->effect_nodes)->head; n != 0; n = n->next) {
            fn_802F1DAC((u8 *)n);
        }
        for (n = (*(Li_802F2348 * *)&this->effect_nodes)->head; n != 0; n = n->next) {
            draw_tunnel_segment((u8 *)n);
        }
    }
}

s32 TObjBoss2Tunnel::check_both(s32 arg0) {
    s32 temp_r31;
    s32 temp_r3;
    temp_r31 = TObjBoss2Tunnel__sub_802F22F4();
    temp_r3 = TObjBoss2Tunnel::is_phase_active(arg0);
    return temp_r3 | temp_r31;
}

s32 TObjBoss2Tunnel::is_phase_active(s32 _w0) {
    return ((u32) boss2_tunnel_state_flags >> 0xCU) & 1;
}

s32 TObjBoss2Tunnel__sub_802F22F4(void) {
    return ((u32) boss2_tunnel_state_flags >> 0xDU) & 1;
}

void TObjBoss2Tunnel__sub_802F22DC(void) {
    boss2_tunnel_state_flags |= 0x1000;
    boss2_tunnel_state_flags &= ~0x2000;
}

void TObjBoss2Tunnel__sub_802F22C4(void) {
    boss2_tunnel_state_flags |= 0x2000;
    boss2_tunnel_state_flags &= ~0x1000;
}

void TObjBoss2Tunnel::clear_flags_0x3000() { (*(int *)&boss2_tunnel_state_flags) = ((*(int *)&boss2_tunnel_state_flags) & 0xffffcfff); }

void TObjBoss2Tunnel::set_flag_0x200() { (*(int *)&boss2_tunnel_state_flags) = ((*(int *)&boss2_tunnel_state_flags) | 0x200); TObjBoss2Tunnel::clear_flags_0x3000(); }

void TObjBoss2Tunnel__sub_802F2278(void) { (*(int *)&boss2_tunnel_state_flags) = ((*(int *)&boss2_tunnel_state_flags) | 0x8); }

void TUnk_804E4B3C::spawn(s32 kind, Vec *position) {
    new TUnk_804E4B24(effect_nodes, kind, position, half_length);
}

void TUnk_804E4B3C::spawn_segment_row_b() {
    Vec position;
    position.x=segment_x;
    position.y=0.0f;
    for (position.z=half_length;position.z > -half_length;position.z-=800.0f) {
        if (799.0f > position.z && position.z > (-799.0f)) {
            spawn(0, &position);
        } else {
            spawn(2, &position);
        }
    }
}

void TUnk_804E4B3C::spawn_segment_row_a() {
    Vec position;
    position.x=segment_x;
    position.y=0.0f;
    for (position.z=half_length;position.z > -half_length;position.z-=800.0f) {
        if (799.0f > position.z && position.z > (-799.0f)) {
            spawn(4, &position);
        } else {
            spawn(3, &position);
        }
    }
}

extern "C" {
s32 TObjBoss2Tunnel__sub_802F2070(void) {
    return ((u32) boss2_tunnel_state_flags >> 0xFU) & 1;
}
}

TUnk_804E4B24::TUnk_804E4B24(TObject *parent, s32 kind, Vec *pos, f32 half_length) : TObject(parent) {
    Boss2TunnelEffectEntry *entry;
    controller = (TUnk_804E4B3C *)parent->m_up;
    entry = &boss2_tunnel_effect_name_table[kind];
    VecCopy(&position, pos);
    rotation_x = 0;
    rotation_y = 0;
    rotation_z = 0;
    model_indices = entry->indices;
    model_count = entry->count;
    this->kind = kind;
    this->half_length = half_length;
    if (kind == 4) {
        controller->copy_position(&position);
        TObjBoss2Tunnel__sub_802F2278();
    }
    update_collision();
}

TUnk_804E4B24::~TUnk_804E4B24() {}

void TUnk_804E4B24::run_task() {
    u8 *arg0 = (u8 *)this;
    position.x = controller->sub_802F2CBC();
    position.z = position.z - controller->sub_802F2CB4();
    if ((s32) this->kind == 4) {
        controller->copy_position(&position);
    }
    if (this->position.z <= -this->half_length) {
        ((TObject *)arg0)->queue_destruction();
    }
    ((TUnk_804E4B24 *)arg0)->update_collision();
}

extern "C" {
void fn_802F1E54(u8 *arg0) {
    if (((s32 (*)(void))is_in_camera_range__18TObjBoss7TunnelColFv)() != 0) {
        set_draw_list_mask(1);
        TObjFish::set_global_param((int)boss7_common_texture_list);
        push_matrix();
        TObjPlayer::concat_matrix(0, (int)(arg0 + 0x48));
        ((s32 (*)(int, void *))draw_ginja_object)((*(GE_802F1E54 **)((s8 *)boss7_common_bml_resource + 0x42C))[(*(s32 **)((s8 *)arg0 + 0x3C))[0]].obj, boss7_common_bml_resource);
        pop_matrix();
        restore_draw_list_mask();
    }
}
}

extern "C" {
void fn_802F1DAC(u8 *arg0) {
    if (((s32 (*)(void))is_in_camera_range__18TObjBoss7TunnelColFv)() != 0) {
        set_draw_list_mask(2);
        TObjFish::set_global_param((int)boss7_common_texture_list);
        push_matrix();
        TObjPlayer::concat_matrix(0, (int)(arg0 + 0x48));
        ((s32 (*)(int, void *))draw_ginja_object)((*(GE_802F1DAC **)((s8 *)boss7_common_bml_resource + 0x42C))[(*(s32 **)((s8 *)arg0 + 0x3C))[1]].obj, boss7_common_bml_resource);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x38) == 4) {
            ((s32 (*)(int, void *))draw_ginja_object)((*(GE_802F1DAC **)((s8 *)boss7_common_bml_resource + 0x42C))[(*(s32 **)((s8 *)arg0 + 0x3C))[2]].obj, boss7_common_bml_resource);
        }
        pop_matrix();
        restore_draw_list_mask();
    }
}
}

void draw_tunnel_segment(u8 *boss7_tunnel_col) {
    s32 var_r31;
    u8 *var_r30;
    u8 *var_r3;
    u8 *var_r4;
    var_r30 = boss7_tunnel_col;
    if (((TObjBoss7TunnelCol *)boss7_tunnel_col)->is_in_camera_range() != 0) {
        var_r3 = (u8 *)((void *)2);
        var_r4 = (u8 *)(*(u8 **)((s8 *)var_r30 + 0x3C));
        var_r4 += *(s32 *)((s8 *)var_r30 + 0x38) * 4;
        var_r31 = *(s32 *)((s8 *)var_r4 + (-4));
        set_draw_list_mask(2);
        var_r3 = boss7_common_texture_list;
        TObjFish::set_global_param((int)var_r3);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        var_r4 = (var_r30 + 0x48);
        var_r3 = NULL;
        TObjPlayer::concat_matrix(0, (int)var_r4);
        var_r3 = boss7_common_bml_resource;
        var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x42C));
        var_r3 += var_r31 * 0x10;
        var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 8));
        draw_ginja_object((int)var_r3);
        pop_matrix();
        TParticleCtrl::end_effect_render();
        restore_draw_list_mask();
    }
}

s32 TObjBoss7TunnelCol::is_in_camera_range() {
    f32 temp_f1;

    if (get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x20) {
        temp_f1 = *(f32 *)&this->texlist;
        if ((temp_f1 < -300.0f) && (300.0f < temp_f1)) {
            return 0;
        }
    }
    return 1;
}

void TUnk_804E4B24::update_collision() {
    set_matrix_identity((u8 *)matrix);
    translate_matrix_vec3((u8 *)matrix, (u8 *)&position);
    rotate_matrix_yxz((s32)matrix, rotation_x, rotation_y, rotation_z);
}

extern "C" {
void *TObjBoss7TunnelCol__ct(void *player, TObject *parent) {
    TObjBoss7TunnelCol *self = (TObjBoss7TunnelCol *)player;
    __ct__14TObjCollidableFP7TObject(player, parent);
    *(s32 **)((s8 *)player + 0x18) = __vt__18TObjBoss7TunnelCol;
    self->m_name = TObjBoss7TunnelCol__name;
    copy_collision_body(&self->collision_body, &TObjBoss7TunnelCol__col_desc);
    *(f32 *)((s8 *)player + 0x38) = 85.0f;
    *(f32 *)((s8 *)player + 0x3C) = 0.0f;
    *(f32 *)((s8 *)player + 0x40) = 0.0f;
    ((TObjCollidable *)player)->set_collision_body(&self->collision_body);
    ((TObjPlayer *)player)->register_object_by_id();
    return player;
}
}

TObjBoss7TunnelCol::~TObjBoss7TunnelCol() {
    unregister_object_by_id();
    clear_collision_bodies();
}

void TObjBoss7TunnelCol::run_task() {  }

void TObjBoss7TunnelCol::render() {  }

TUnk_804E4AD4::TUnk_804E4AD4(TObject *parent, s32 kind) : TObject(parent) {
    model = get_bml_model(boss7_common_bml_resource, kind + 0x11);
    motion = get_bml_motion(boss7_common_bml_resource, kind);
    last_frame = (f32)motion->frameCount - 1.0f;
    frame = 0.0f;
}

TUnk_804E4AD4::~TUnk_804E4AD4() {}

void TUnk_804E4AD4::run_task() {
    f32 temp_f0;
    f32 temp_f1;
    this->frame += 1.0f;
    temp_f1 = this->last_frame;
    temp_f0 = this->frame;
    if (temp_f1 <= temp_f0) {
        this->frame = (f32) (temp_f0 - temp_f1);
    }
}
