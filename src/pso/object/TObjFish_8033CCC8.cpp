#include "types.h"
#include "pso/system/PadRumble.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/misc/TCameraCtrl_800687BC.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TBoss6Demo11_TYPE1_DEAD.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/object/TObjFish.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"

struct Range_8033CDF8 { s32 lo; s32 hi; s32 idx; };

struct Vec_8033CDF8 { f32 x, y, z; };

struct Fish_8033CDF8 { u8 pad[0x4C]; Vec_8033CDF8 vecs[3]; };

extern "C" {
s32 play_sound_effect(int, int, int, int);
extern Range_8033CDF8 fish_spawn_entry_table[];
void clear_render_callback__8TObjFishFv(void);
s32 push_matrix(void);
f32 post_translate_matrix(void);
extern const f32 lbl_805DFA58;
extern const f32 lbl_805DFA5C;
extern const f32 lbl_805DFA60;
void *TObjFish__sub_8033D1AC(void *, void *, void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void *__nw__7TObjectFUl(int);

void TBoss6Demo11_TYPE1_DEAD::render_fade_model() {
    u8 *arg0 = (u8 *)this;
    f32 var_f31;
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x44);
    if (temp_r0 < 0xBF) {
        var_f31 = lbl_805DFA58;
    } else if (temp_r0 >= 0xCC) {
        var_f31 = lbl_805DFA5C;
    } else {
        var_f31 = (f32) (0xCC - temp_r0) / lbl_805DFA60;
    }
    if (lbl_805DFA5C != var_f31) {
        if (var_f31 < lbl_805DFA58) {
            TBoss6PlotFalz::set_fade_material_color(var_f31);
        }
        push_matrix();
        set_motion_packed_rotation();
        ((f32 (*)(void *))post_translate_matrix)(arg0 + 0x1C);
        TObjFish::set_global_param(*(s32 *)&(*(void * *)((u8 *)this + 0x2C)));
        draw_model_motion((void *)(*(s32 *)&(this->m_28)), (void *)(*(s32 *)&(this->m_30)), this->m_40);
        TObjFish::set_global_param(this->m_38);
        ((TObjFish *)((this->m_88)))->set_draw_callback_list();
        draw_model_motion((void *)(*(s32 *)&(*(void * *)((u8 *)this + 0x34))), (void *)(*(s32 *)((s8 *)arg0 + 0x3C)), this->m_40);
        ((int (*)(void *))clear_render_callback__8TObjFishFv)((this->m_88));
        clear_motion_packed_rotation();
        pop_matrix();
        if (var_f31 < lbl_805DFA58) {
            TObjFish::reset_fish_globals();
        }
    }
}

void TBoss6Demo11_TYPE1_DEAD::render() { this->render_fade_model(); }

extern s32 lbl_804EF9EC[];

#define F(T, o) (*(T *)(arg0 + (o)))
void TBoss6Demo11_TYPE1_DEAD::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 found;
    s32 i;
    Vec_8033CDF8 *p;
    u8 *q;
    Range_8033CDF8 *t;
    if ((F(f32, 0x40) += 0.7f) > 179.0f) {
        F(f32, 0x40) = 179.0f;
    }
    switch (F(s32, 0x44)) {
    case 0x98:
        play_sound_effect(0x40032104, 0, 0, 0);
        break;
    case 0xF9:
        play_sound_effect(0x40032B25, 0, 0, 0);
        break;
    case 0x1E:
        play_sound_effect(0x4003A811, 0, 0, 0);
        break;
    case 0x3C:
    case 0x5A:
    case 0x14:
    case 0xA:
        play_sound_effect(0x40032E23, 0, 0, 0);
        break;
    }
    if (F(s32, 0x44) >= 0x89) {
        play_persistent_sound(0x4003A424, (s32)arg0, 0, 0, 0);
    }
    switch (F(s32, 0x44)) {
    case 0xE:
        q = arg0 + 0x7C;
        spawn_particle_effect_with_flags(q, 0x21C, 0x40);
        spawn_particle_effect_with_flags(q, 0x21D, 0x40);
        break;
    case 0x4E:
        q = arg0 + 0x70;
        spawn_particle_effect_with_flags(q, 0x21C, 0x40);
        spawn_particle_effect_with_flags(q, 0x21D, 0x40);
        break;
    }
    if (F(s32, 0x44) >= 0xB9 && !(F(s32, 0x44) & 3)) {
        q = arg0 + 0x4C;
        spawn_particle_effect_with_flags(q, 0x13C, 0x40);
        spawn_particle_effect_with_flags(q, 0x13D, 0x40);
    }
    found = 0;
    for (i = 0; i < 4; i++) {
        t = &fish_spawn_entry_table[i];
        if (F(s32, 0x44) >= t->lo && F(s32, 0x44) < t->hi) {
            p = &((Fish_8033CDF8 *)arg0)->vecs[t->idx];
            if (F(void *, 0x8C) == NULL) {
                F(void *, 0x8C) = create_particle_emitter(p, 0x21F);
                if (F(void *, 0x8C) != NULL) {
                    ((TParticleCtrl *)(F(void *, 0x8C)))->set_flags(0x40);
                }
            } else {
                ((TParticleCtrl *)F(void *, 0x8C))->set_position(p);
            }
            found = 1;
            break;
        }
    }
    if (found == 0 && F(void *, 0x8C) != NULL) {
        TParticleCtrl::release(F(void *, 0x8C));
        F(void *, 0x8C) = NULL;
    }
    switch (F(s32, 0x44)) {
    case 5:
    case 0x19:
    case 0x46:
    case 0x5F:
    case 0x6E:
    case 0x8C:
    case 0xBE:
    case 0xFF:
        start_pad_rumble_all(0xC0, 0xF);
        break;
    }
    F(s32, 0x44)++;
    if (F(s32, 0x44) >= 0x101 || ((TObjFish *)(F(s32, 0x48)))->get_phase() != 3) {
        queue_destruction__7TObjectFv(arg0);
    }
}

void *TBoss6Demo11_TYPE1_DEAD::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804EF9EC;
        restore_player_cameras();
        if (*(void * *)&(this->m_88) != NULL) { TObjFish::init_state_1(*(void * *)&(this->m_88)); *(s32 *)&(this->m_88) = 0; }
        if (*(void * *)&(this->unk_8C) != NULL) { TParticleCtrl::release(*(void * *)&(this->unk_8C)); *(s32 *)&(this->unk_8C) = 0; }
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void *TBoss6PlotFalz::create(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x90);
    if (o != NULL) {
        o = TObjFish__sub_8033D1AC(o, arg0, arg1);
    }
    return o;
}

}
