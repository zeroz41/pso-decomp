#include "types.h"
#include "pso/misc/TTecSifta.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/effect/TUnk_804CCC68.h"

#include "pso/misc/TTecAnti.h"
#include "pso/misc/TTecLuker.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8023B17C___vt__9TTecSifta {
    s32 value;
    u8 remaining[0x1C];
};

struct Obj_8023ACA8 { u8 pad[0xA6]; s16 state; };

struct VBase_18_b27ba1 { char pad[0x18]; };

struct HitInfo_8023AE8C { s32 type; f32 power; };

struct VObj_18_b27ba1 : VBase_18_b27ba1 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21(void *, HitInfo_8023AE8C *, void *, s32, s32);
};

struct Obj_8023AE8C { u8 pad[0x1C]; u8 *source; u8 pad20[0x74 - 0x20]; f32 power; };

struct Target_8023AF94 { u16 id; u8 pad[6]; };

struct Sifta_8023AF94 {
    u8 pad0[0x1C];
    u32 source;
    u8 pad1[0xA4 - 0x20];
    s16 level;
    u8 pad2[0xA8 - 0xA6];
    u16 source_id;
    u8 pad3[0xE0 - 0xAA];
    s32 count;
    Target_8023AF94 targets[11];
    s32 captured;
};

extern "C" {
s32 get_entity_id(int);
s32 TTecPlayerInfluence__ct(void *, void *, void *, void *);
int TTecSifta__sub_8023AC88(void* p);
extern s32 __vt__9TTecSifta[];
extern s32 lbl_805D3820;
extern const f32 lbl_805DC940;
u8 *TTecSifta__sub_8023B17C(TTecSifta *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 update_technique_slot__10TTecRaFoieFl(s32, s32, s32);
s32 play_sound_effect(int, void *, int, int);
s32 is_split_screen();
s32 is_script_controlled__10TObjPlayerFv(void *);
void *find_entity_by_id(u16 id);
void deliver_technique_to_party_targets(void *);
void run_task__9TTecSiftaFv(Sifta_8023AF94 *self);
void copy_technique_target_list(void *, void *);
void *TTecSifta__ct(void *arg0_, void *arg1, void *arg2, void *arg3, void *arg4);
s32 calc_technique_parameters(s32, s16, s32);
void *__nw__7TObjectFUl(int);
int spawn_support_tec_range_effect(void*);

int TTecSifta__sub_8023AC88(void* p) { return spawn_support_tec_range_effect(p); }

void TTecSifta::play_sifta_cast_sound() {
    Obj_8023ACA8 *arg0 = (Obj_8023ACA8 *)this;
    s32 r;
    switch (*(s16 *)&this->m_a6) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002AD14, (u8 *)arg0 + 0x20, 0, 0);
        if (r >= 0) {
            update_technique_slot__10TTecRaFoieFl(r, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002AD14, (u8 *)arg0 + 0x20, 0, 0);
        break;
    case 4:
    case 5:
        r = play_sound_effect(0x4002AD14, (u8 *)arg0 + 0x20, 0, 0);
        if (r >= 0) {
            update_technique_slot__10TTecRaFoieFl(r, -0x100, 0);
        }
        break;
    }
}

void TTecSifta::update_effect_params() {
    u8 *arg0 = (u8 *)this;
    s32 res;
    res = calc_technique_parameters(0xD, this->m_a4, 0xFFFF);
    ((TTecAnti *)(arg0 + 0x74))->copy_params((u8 *)res);
    this->m_74 = (f32) (this->m_98 * this->m_a4);
}

void TTecSifta::create_instance(void *pos, void *arg2, void *level) {
    void *o;
    o = __nw__7TObjectFUl(0x140);
    if (o != NULL) {
        TTecSifta__ct(o, this, pos, arg2, level);
    }
}

void TTecSifta::create(void *owner, void *pos, void *level) {
    void *o;
    o = __nw__7TObjectFUl(0x140);
    if (o != NULL) {
        TTecSifta__sub_8023B17C((TTecSifta *)((u8 *)o), (s32)owner, (s32)pos, (s32)level);
    }
}

void TTecSifta::vfunc_7(void *arg1_arg) {
    Obj_8023AE8C *arg0 = (Obj_8023AE8C *)this;
    VObj_18_b27ba1 *player = (VObj_18_b27ba1 *)arg1_arg;
    HitInfo_8023AE8C h;
    if (is_script_controlled__10TObjPlayerFv(player) == 0) {
        h.type = 9;
        h.power = arg0->power;
        if (is_split_screen() == 0) {
            TWindowCtrl::show_party_effect((void*)(get_entity_id((int)arg0->source)), (void*)(get_entity_id((int)player)), (void*)9);
        }
        HitInfo_8023AE8C c = h;
        player->m21(arg0->source, &c, 0, 0xD, -1);
    }
}

}
TTecSifta::~TTecSifta() {

}


typedef char RecoveredGlobal_8023B17C___vt__9TTecSifta_size[sizeof(RecoveredGlobal_8023B17C___vt__9TTecSifta) == 0x20 ? 1 : -1];

void run_task__9TTecSiftaFv(Sifta_8023AF94 *self) {
    u32 target;
    s32 i;
    self->source = (u32)find_entity_by_id(self->source_id);
    if (self->source == 0) {
        queue_destruction__7TObjectFv(self);
        return;
    }
    if (self->captured != 0) {
        if (self->level <= 1) {
            ((TTecSifta *)self)->vfunc_7((void *)self->source);
        } else {
            ((TTecSifta *)self)->vfunc_7((void *)self->source);
            if (self->count != 0) {
                for (i = 0; i < self->count; i++) {
                    target = (u32)find_entity_by_id(self->targets[i].id);
                    if (TTecLuker::is_parents_unqueued(target) != 0) {
                        ((TTecSifta *)self)->vfunc_7((void *)target);
                    }
                }
            }
        }
    } else if (self->level <= 1) {
        ((TTecSifta *)self)->vfunc_7((void *)self->source);
    } else {
        deliver_technique_to_party_targets(self);
    }
    queue_destruction__7TObjectFv(self);
}

#pragma push
#pragma opt_common_subs off
struct Obj_8023ACA8;
#define arg0 ((u8 *)arg0_)
void *TTecSifta__ct(void *arg0_, void *owner, void *pos, void *arg3, void *level) {
    u8 *temp_r3;
    u32 t;
    TTecPlayerInfluence__ct(arg0, owner, pos, level);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__9TTecSifta;
    ((TObjPlayer *)(arg0 + 0xE0))->construct_target_cursor_records();
    *(s32 *)((s8 *)arg0 + 0) = lbl_805D3820;
    *(s32 *)&((TTecSifta *)arg0)->m_13c = 1;
    copy_technique_target_list(arg0 + 0xE0, arg3);
    ((TTecSifta *)arg0)->update_effect_params();
    temp_r3 = *(u8 **)((s8 *)arg0 + 0xDC);
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 0xA4)) + 0xC) = lbl_805DC940 + ((TTecSifta *)arg0)->m_7c;
    }
    t = ((TTecSifta *)arg0)->source;
    if (t != 0U) {
        *(s16 *)&((TTecSifta *)arg0)->m_a8 = get_entity_id((int)t);
    }
    if (*(s32 *)&((TTecSifta *)arg0)->m_ac != 0) {
        TTecSifta__sub_8023AC88(arg0);
        ((TTecSifta *)arg0)->play_sifta_cast_sound();
    }
    return arg0_;
}
#undef arg0
#pragma pop

u8 *TTecSifta__sub_8023B17C(TTecSifta *arg0, s32 owner, s32 pos, s32 level) {
    u32 temp_r3_2;
    u8 *temp_r3;
    TTecPlayerInfluence__ct((void *)arg0, (void *)owner, (void *)pos, (void *)level);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8023B17C___vt__9TTecSifta *)&__vt__9TTecSifta).value;
    ((TObjPlayer *)((u8 *)arg0 + 0xE0))->construct_target_cursor_records();
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D3820;
    arg0->m_13c = 0;
    arg0->update_effect_params();
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xDC));
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 0xA4)) + 0xC) = (f32) (lbl_805DC940 + arg0->m_7c);
    }
    temp_r3_2 = arg0->source;
    if (temp_r3_2 != 0U) {
        arg0->m_a8 = get_entity_id(temp_r3_2);
    }
    TTecSifta__sub_8023AC88(arg0);
    arg0->play_sifta_cast_sound();
    return (u8 *)arg0;
}

void TTecSifta::render() {  }

