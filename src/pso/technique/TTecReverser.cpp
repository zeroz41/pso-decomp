#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/technique/TTecReverser.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/unk/TUnk_804CCC28.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "pso/effect/TUnk_804CC148.h"
#include "pso/effect/TUnk_804CCC68.h"

#include "pso/enemy/gibon/TObjEneBm5GibonU.h"

#include "pso/technique/TTecAnti.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TargetCursorList.h"

#pragma readonly_strings on

struct Entry_80239E44 { s32 a; s32 b; s32 c; s32 pad; };

struct Player_80239E44 { u8 pad[0x2FC]; Vec pos; };

struct Obj_80239E44 {
    u8 pad[0x18];
    void *vtable;
    void *parts[3];
    s32 f28;
    Vec pos;
};

struct Rev_8023A364 {
    u8 pad[0xcc];
    f32 fcc;
    f32 fd0;
    f32 fd4;
    u8 padd8[0xdc - 0xd8];
    s16 fdc;
    s16 fde;
    s16 fe0;
};

struct List_8023A244 { uaddr objs[16]; s32 vals[16]; s32 count; };

extern "C" {
s32 is_active__12TTecReverserFv();
void run_task__12TTecReverserFv(u8 *arg0);
s32 get_entity_id(int);
s32 copy_technique_target_list(void *, void *);
const char *lbl_805D3818 = "TTecReverser";
void __ct__7TObjectFP7TObject(void *self, void *parent);
extern s32 __vt__13TUnk_804CCC28[];
Entry_80239E44 revival_particle_table[3] = {
    {0, 0x1E, 0x35, 0},
    {0x23, 1, 0x36, 0},
    {0x2D, 1, 0x37, 0},
};
Obj_80239E44 *construct_revival_particle_effect(Obj_80239E44 *self, Player_80239E44 *player, void *parent);
s32 get_type__10TObjPlayerFPv(void *p);

}

void TUnk_804CCC68::debug_print_tech_params() {
    Rev_8023A364 *self = (Rev_8023A364 *)this;
    debug_printf_at(0x1E0014, "POWER  : %f", self->fcc);
    debug_printf_at(0x1E0015, "USE_TP : %d", self->fdc);
    debug_printf_at(0x1E0016, "CH_SPD : %d", self->fde);
    debug_printf_at(0x1E0017, "SPEED  : %f", self->fd0);
    debug_printf_at(0x1E0018, "SCOPE  : %f", self->fd4);
    debug_printf_at(0x1E0019, "MENTAL  : %f", self->fe0);
}

void TUnk_804CCC68::dispatch_all_technique_contacts() {
    List_8023A244 *list;
    s32 i;
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x128) == 0U) {
        queue_destruction();
        return;
    }
    if ((u16) get_entity_id((int) (*(s32 *)((s8 *)((u8 *)this) + 0x1C))) < 4U) {
        if (get_type__10TObjPlayerFPv((void *)(*(saddr *)((s8 *)((u8 *)this) + 0x1C) + 0x828)) != 0) {
            list = (List_8023A244 *) query_technique_player_contacts(*(s32 *)((s8 *)((u8 *)this) + 0x1C));
        } else {
            list = (List_8023A244 *) query_technique_enemy_contacts(*(s32 *)((s8 *)((u8 *)this) + 0x1C));
        }
    } else {
        list = (List_8023A244 *) query_technique_player_contacts(*(s32 *)((s8 *)((u8 *)this) + 0x1C));
    }
    if (list == NULL) {
        this->vfunc_6();
        queue_destruction();
        return;
    }
    for (i = 0; i < list->count; i++) {
        if (TObjPlayer::is_valid_and_active((int) list->objs[i]) != 0) {
            void *p = (void *) list->objs[i];
            if (p != NULL) {
                *(s32 *)((s8 *)((u8 *)this) + 0xF8) = list->vals[i];
                this->vfunc_8(p);
            }
        }
    }
}

void TUnk_804CCC68::dispatch_technique_contact(s32) {
    u8 *var_r31;
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x128) == 0U) {
        queue_destruction();
        return;
    }
    if ((u16) get_entity_id((int) (*(s32 *)((s8 *)((u8 *)this) + 0x1C))) < 4U) {
        if (get_type__10TObjPlayerFPv((void *)(*(saddr *)((s8 *)((u8 *)this) + 0x1C) + 0x828)) != 0) {
            var_r31 = query_technique_player_contacts(*(s32 *)((s8 *)((u8 *)this) + 0x1C));
        } else {
            var_r31 = query_technique_enemy_contacts(*(s32 *)((s8 *)((u8 *)this) + 0x1C));
        }
    } else {
        var_r31 = query_technique_player_contacts(*(s32 *)((s8 *)((u8 *)this) + 0x1C));
    }
    if (var_r31 == NULL) {
        this->vfunc_6();
        queue_destruction();
        return;
    }
    if (TObjPlayer::is_valid_and_active((int) (*(u32 *)((s8 *)var_r31 + 0))) != 0) {
        void *p = *(void **)((s8 *)var_r31 + 0);
        if (p != NULL) {
            *(s32 *)((s8 *)((u8 *)this) + 0xF8) = (s32) *(s32 *)((s8 *)var_r31 + 0x40);
            this->vfunc_8(p);
        }
    }
}

#define tec_reverser ((u8 *)this)
TTecReverser::TTecReverser(saddr arg1, saddr origin, saddr targets, saddr level) : TUnk_804CC148(arg1, origin, level) {
    u32 temp_r3;
    __ct__16TargetCursorListFv((tec_reverser + 0xEC));
    ((TTecReverser *)tec_reverser)->m_name = lbl_805D3818;
    ((TechniqueParams *)(tec_reverser + 0x88))->copy(&technique_param_table[17]);
    ((TTecReverser *)tec_reverser)->sub_8022BE64(tec_reverser + 0x88, level);
    copy_technique_target_list(tec_reverser + 0xEC, (void *)targets);
    play_sound_effect(0x4002A812, tec_reverser + 0x20, 0, 0);
    temp_r3 = ((TTecReverser *)tec_reverser)->source;
    if (temp_r3 != 0U) {
        ((TTecReverser *)tec_reverser)->m_b4 = get_entity_id(temp_r3);
    }
}
#undef tec_reverser

TTecReverser::~TTecReverser() {

}

void TTecReverser::create(void *source, void *origin, void *targets, s32 level) {
    new TTecReverser((saddr)source, (saddr)origin, (saddr)targets, level);
}

void run_task__12TTecReverserFv(u8 *tec_reverser) {
    uaddr entity;
    ((TTecReverser *)tec_reverser)->source = (uaddr)find_entity_by_id((((TTecReverser *)tec_reverser)->m_b4));
    if ((u32) ((TTecReverser *)tec_reverser)->source == 0U) {
        ((TObject *)tec_reverser)->queue_destruction();
        return;
    }
    if ((s32) ((TTecReverser *)tec_reverser)->m_ec == 0) {
        ((TObject *)tec_reverser)->queue_destruction();
        return;
    }
    entity = (uaddr)find_entity_by_id((((TTecReverser *)tec_reverser)->m_f0));
    if ((is_active__12TTecReverserFv() == 0) && (TObjPlayer::is_valid_and_active(entity) != 0)) {
        ((TTecReverser *)(tec_reverser))->vfunc_6((void *)entity);
    }
    ((TObject *)tec_reverser)->queue_destruction();
}

void TTecReverser::render() {  }

Obj_80239E44 *construct_revival_particle_effect(Obj_80239E44 *self, Player_80239E44 *player, void *parent) {
    s32 i;
    __ct__7TObjectFP7TObject(self, parent);
    self->vtable = __vt__13TUnk_804CCC28;
    self->f28 = 0;
    VecCopy((Vec *)&self->pos, (const Vec *)&player->pos);
    for (i = 0; i < 3; i++) {
        if (i == 0) {
            Vec v;
            VecCopy((Vec *)&v, (const Vec *)&self->pos);
            v.y += 20.0f;
            self->parts[i] = create_timed_particle_emitter(&v, revival_particle_table[i].c, revival_particle_table[i].a, revival_particle_table[i].b);
        } else {
            self->parts[i] = create_timed_particle_emitter(&self->pos, revival_particle_table[i].c, revival_particle_table[i].a, revival_particle_table[i].b);
        }
    }
    return self;
}

void TUnk_804CCC28::run_task() {
    u8 *arg0 = (u8 *)this;
    this->m_28 = (this->m_28 + 1);
    if ((s32) this->m_28 == 0xA) {
        spawn_particle_effect((const Vec *)&this->unk_2C, 0x38);
    }
    if ((s32) this->m_28 > 0xC8) {
        ((TObject *)arg0)->queue_destruction();
    }
}

TUnk_804CCC28::~TUnk_804CCC28() {

}
