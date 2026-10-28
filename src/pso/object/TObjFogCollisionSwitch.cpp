// Folded unit: pso/unk/text_80153674 + pso/object/TObjFogCollisionSwitch + pso/unk/text_80153A7C.
#include "types.h"
#include "pso/object/TObjFogCollision.h"
#include "pso/object/TObjFogCollisionSwitch.h"
#include "pso/object/TObjFogCollisionPoison.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_80153674.h"
#include "pso/unk/text_80153A7C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"

#pragma readonly_strings on

struct VBase_801537CC { char pad[0x18]; };

struct VObj_801537CC : VBase_801537CC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
};

struct O_801538D4 { u8 pad[0x8C]; s32 v; };

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Color_80153B64 { u32 v[4]; };

struct O_80153D98 { u8 pad[0x88]; s32 mode; };

extern void *tl_05;

extern "C" {

s32 is_split_screen();
s32 init_base__22TObjFogCollisionPoisonFPUcs(void *, void *, u16);
void *__nw__7TObjectFUl(int);
extern s32 __vt__22TObjFogCollisionPoison[];
extern s32 __vt__22TObjFogCollisionSwitch[];
extern s32 lbl_805D2E80;
extern s32 local_client_id;
void vfunc_14__16TObjFogCollisionFv(O_801538D4 *);
s32 vfunc_13__16TObjFogCollisionFl();
void debug_printf_at(int, void *, ...);
extern char lbl_80440090[];
extern char lbl_804400A4[];
extern char lbl_804400B8[];
void record_fog_collision_hit(s32 arg0, s32 arg1, s32 arg2);
u8 is_current_floor_switch_set(u16);
f32 get_random_float__21TObjEneMe3ShinowaRealFv(f32);

extern s32 game_difficulty_selection;

void TObjFogCollision__ct(void *);

extern void *lbl_805D2E7C;

s32 scale_matrix(int, f32, f32, f32);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern Color_80153B64 lbl_8044002C;
extern Color_80153B64 fog_collision_color_a;
extern Color_80153B64 fog_collision_color_b;
extern s32 saved_model_draw_color[];
extern s32 model_material_color[];
extern s32 lbl_805D28BC;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

extern char lbl_804400C8[];
extern char lbl_804400D4[];
extern char lbl_804400E0[];
f32 horizontal_distance_squared(void *, s32);
s32 get_player_by_client_id(u16);

}

// Function definitions in reverse address order (defer_codegen emits them reversed).
#pragma defer_codegen on

extern "C" {

int TObjFogCollision__sub_80153F70(void *self) { return 0; }
int TObjFogCollision__sub_80153F68(void *self) { return 0; }

void TObjFogCollision::vfunc_13(s32) {
    s32 temp_r0;
    temp_r0 = this->m_84;
    if (temp_r0 < 0) {
        this->m_84 = 0;
        return;
    }
    if (temp_r0 >= 0x80) {
        this->m_84 = 0x7F;
    }
}

s32 TObjFogCollision::check_collision(u16 arg1) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f31;
    s32 player;

    player = get_player_by_client_id((u16)arg1);
    if (player != 0) {
        temp_f0 = this->scale;
        temp_f31 = temp_f0 * temp_f0;
        temp_f1 = horizontal_distance_squared((u8 *)&this->position, player + 0x38);
        if (temp_f31 > temp_f1) {
            return 1;
        }
        if ((2.5e+03f + temp_f31) < temp_f1) {
            this->m_94 = 0x3C;
        }
        goto block_5;
    }
block_5:
    return 0;
}

void TObjFogCollision::run_task() {
    u16 i;
    if (TObjFogCollision__sub_80153F70(this) == 0 && TObjFogCollision__sub_80153F68(this) == 0) {
        for (i = 0; i != 4; i++) {
            if (check_collision(i) != 0) {
                record_fog_collision_hit(i, this->m_84, this->m_88 == 0);
            }
        }
    }
}

void TObjFogCollision::vfunc_14() {
    O_80153D98 *arg0 = (O_80153D98 *)this;
    debug_printf_at(0x13001C, (void *)"Rad");
    debug_printf_at(0x130020, lbl_804400C8);
    if (arg0->mode == 0) {
        debug_printf_at(0x130021, lbl_804400D4);
    } else {
        debug_printf_at(0x130021, lbl_804400E0);
    }
}

void TObjFogCollision::render() {
    u8 *arg0 = (u8 *)this;
    if (((s32)TObjFogCollision__sub_80153F70(this)) != 0) {
        this->vfunc_14();
    }
    if (((s32)TObjFogCollision__sub_80153F68(arg0)) != 0) {
        this->draw_volume();
    }
}

void TObjFogCollision::draw_volume() {
    u8 *arg0 = (u8 *)this;
    f32 s;
    if (((VObj_18_26a62c *)(arg0))->m8(1.5e+02f, this->scale) != 0) {
        Color_80153B64 c0 = lbl_8044002C;
        Color_80153B64 c3 = fog_collision_color_a;
        Color_80153B64 cd = fog_collision_color_b;
        saved_model_render_flags = model_render_flags;
        ((TRaderMapCore *)saved_model_draw_color)->copy_vec4(model_material_color);
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x810;
        set_chunk_material_override_pair(0xFF00, 0x800);
        switch (this->m_90) {
        case 0:
            ((TUnk_80494AE0 *)((f32 *)&c0))->set_chunk_material_color();
            break;
        case 1:
        case 2:
        case 4:
        case 5:
            ((TUnk_80494AE0 *)((f32 *)&cd))->set_chunk_material_color();
            break;
        case 3:
            ((TUnk_80494AE0 *)((f32 *)&c3))->set_chunk_material_color();
            break;
        }
        push_matrix();
        s = 0.5f * this->scale;
        post_translate_matrix((u8 *)&this->position);
        scale_matrix(0, s, 3.0f, s);
        draw_chunk_object((void *)lbl_805D28BC);
        pop_matrix();
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        ((TRaderMapCore *)model_material_color)->copy_vec4(saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
    }
}

void *TObjFogCollisionSwitch__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x98);
    if (o != NULL) {
        o = TObjFogCollisionSwitch__ct(o, tl_05, arg0);
    }
    return o;
}

void *TObjFogCollisionSwitch__ct(void *fog_collision_switch, void *parent, void *set) {
    TObjFogCollision__ct(fog_collision_switch);
    *(s32 **)((s8 *)fog_collision_switch + 0x18) = __vt__22TObjFogCollisionSwitch;
    *(void * *)&((TObjFogCollisionSwitch *)fog_collision_switch)->m_name = lbl_805D2E7C;
    return fog_collision_switch;
}

}

TObjFogCollisionSwitch::~TObjFogCollisionSwitch() {

}

extern "C" {

void TObjFogCollisionSwitch::vfunc_13(s32) {
    s32 temp_r0;

    vfunc_13__16TObjFogCollisionFl();
    temp_r0 = this->m_8c;
    if (temp_r0 < 0) {
        this->m_8c = 0;
        return;
    }
    if (temp_r0 > 0xFF) {
        this->m_8c = 0xFF;
    }
}

s32 TObjFogCollisionSwitch::sub_80153A0C() {
    return *(f32 *)&this->m_70 >= 1.0f;
}

void run_task__22TObjFogCollisionSwitchFv(TObjFogCollisionSwitch *arg0) {
    s32 st;
    u16 i;
    if (TObjFogCollision__sub_80153F70(arg0) == 0 && TObjFogCollision__sub_80153F68(arg0) == 0) {
        st = arg0->sub_80153A0C();
        if (st == is_current_floor_switch_set(arg0->m_8c)) {
            for (i = 0; i != 4; i++) {
                if (((TObjFogCollision *)arg0)->check_collision(i) != 0) {
                    record_fog_collision_hit(i, arg0->m_84, *(s32 *)((s8 *)arg0 + 0x88) == 0);
                }
            }
        }
    }
}

void TObjFogCollisionSwitch::vfunc_14() {
    O_801538D4 *arg0 = (O_801538D4 *)this;
    vfunc_14__16TObjFogCollisionFv(arg0);
    if (((TObjFogCollisionSwitch *)arg0)->sub_80153A0C() != 0) {
        debug_printf_at(0x13001E, lbl_80440090);
    } else {
        debug_printf_at(0x13001E, lbl_804400A4);
    }
    debug_printf_at(0x130022, lbl_804400B8, this->m_8c);
}

void *create__22TObjFogCollisionPoisonFPv(void *arg0) {
    void *o = __nw__7TObjectFUl(0x9C);
    if (o != NULL) {
        o = TObjFogCollisionPoison__ct(o, tl_05, arg0);
    }
    return o;
}

void *TObjFogCollisionPoison__ct(void *arg0, void *arg1, void *arg2) {
    u16 i;
    void *o;
    TObjFogCollisionSwitch__ct(arg0, arg1, arg2);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__22TObjFogCollisionPoison;
    *(s32 *)((s8 *)arg0 + 0) = lbl_805D2E80;
    ((VObj_801537CC *)arg0)->m11();
    if (is_split_screen() != 0) {
        for (i = 0; i != 4; i++) {
            o = __nw__7TObjectFUl(0x2C);
            if (o != NULL) {
                init_base__22TObjFogCollisionPoisonFPUcs(o, arg0, i);
            }
        }
    } else {
        o = __nw__7TObjectFUl(0x2C);
        if (o != NULL) {
            init_base__22TObjFogCollisionPoisonFPUcs(o, arg0, local_client_id);
        }
    }
    return arg0;
}

}

TObjFogCollisionPoison::~TObjFogCollisionPoison() {

}

extern "C" {

void TObjFogCollisionPoison::vfunc_13(s32) {
    f32 var_f2;

    *(s32 *)&this->m_98 = (s32) get_random_float__21TObjEneMe3ShinowaRealFv(this->target_scale);
    switch ((s32) game_difficulty_selection) {
    default:
    case 0:
        var_f2 = 1.0f;
        break;
    case 1:
        var_f2 = 2.0f;
        break;
    case 2:
        var_f2 = 3.0f;
        break;
    case 3:
        var_f2 = 6.0f;
        break;
    }
    *(s32 *)&this->m_98 = (s32) ((f32) *(s32 *)&this->m_98 * var_f2);
}

void run_task__22TObjFogCollisionPoisonFv(void *self) {
    if (TObjFogCollision__sub_80153F70(self)) {
        return;
    }
    if (TObjFogCollision__sub_80153F68(self)) {
        return;
    }
}

}
