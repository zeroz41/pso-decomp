#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/technique/TTecGiFoie.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecCircle.h"

#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecLuker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/object/base/TObjBase.h"

extern "C" {

struct HitInfo_8023154C { s32 type; f32 power; };

struct VBase_8023154C { char pad[0x18]; };

struct VObj_8023154C : VBase_8023154C {
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
    virtual void m21(void *, HitInfo_8023154C *, void *, s32, s32);
};

struct Rot_802312E4 { s32 x, y, z; };

// Same layout as TTecGiBarta's Row_802304A0 {entry, flags, scale}.
struct Part_802312E4 { s32 id; u32 flags; f32 scale; };

struct Profile_802312E4 { const Part_802312E4 *parts; u32 count; };

void * find_entity_by_id(u16);
void matrix_mult_vec(void *, void *, void *);

const char *TTecGiFoie__name = "TTecGiFoie";

// emitter_parts_N: the N particle parts an entry of TTecGiFoie__emitter_profile_table spawns.
static const Part_802312E4 emitter_parts_1[1] = {{34, 2, 0.0f}};
static const Part_802312E4 emitter_parts_2[2] = {{34, 2, 0.0f}, {172, 1, 0.0f}};
static const Part_802312E4 emitter_parts_3[3] = {{34, 2, 0.0f}, {172, 1, 0.0f}, {414, 0x1000, 1.0f}};

const Profile_802312E4 TTecGiFoie__emitter_profile_table[6] = {
    {emitter_parts_1, 1}, {emitter_parts_1, 1}, {emitter_parts_1, 1},
    {emitter_parts_2, 2}, {emitter_parts_2, 2}, {emitter_parts_3, 3},
};

// orbit_counts: per band, how many orbits TTecGiFoie__ct spaces evenly (360 / count degrees) around the caster.
static const u8 orbit_counts[6] = {1, 1, 1, 2, 2, 3};

// defer_codegen emits these in reverse source order: the last function in the file comes first in .text.
#pragma defer_codegen on

void TTecGiFoie::render() {  }

TTecGiFoie::TTecGiFoie(saddr source, Vec *origin, s32 level) : TTecCircle(source, origin, origin, level) {
    s32 i;
    s32 j;
    s32 k;
    s32 r;
    this->m_name = TTecGiFoie__name;
    calc_params();
    if (this->collidable != NULL) {
        this->collidable->bodies->radius = 5.0f + this->scope;
    }
    for (i = 0; i < 32; i++) {
        this->hitIds[i] = 0xFFFF;
    }
    for (j = 0; j < 3; j++) {
        this->orbits[j] = NULL;
    }
    this->hitCursor = 0;
    for (k = 0; k < orbit_counts[this->band]; k++) {
        Vec v = {0.0f, 0.0f, -10.0f};
        Vec p;
        s32 angle;
        s32 step;
        step = (s32)(182.04445f * (f32)(360 / orbit_counts[this->band]));
        angle = step * k + 0x4000;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, angle);
        matrix_mult_vec(0, &v, &v);
        pop_matrices(1);
        p.x = this->position.x + v.x;
        p.y = this->position.y + v.y;
        p.z = this->position.z + v.z;
        this->orbits[k] = new TUnk_804CC800(&p, angle, this->band, this->level, tl_07, 0);
    }
    switch (this->band) {
    case 0:
        r = play_sound_effect(0x4002A801, &this->position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, 0x100, 0);
        }
        break;
    case 1:
        play_sound_effect(0x4002A801, &this->position, 0, 0);
        break;
    case 2:
    case 3:
        r = play_sound_effect(0x4002A801, &this->position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x180, 0);
        }
        break;
    case 4:
        r = play_sound_effect(0x4002A801, &this->position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x250, 0);
        }
        break;
    case 5:
        r = play_sound_effect(0x4002A801, &this->position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x100, 0);
        }
        break;
    default:
        play_sound_effect(0x4002A801, &this->position, 0, 0);
        break;
    }
    if (this->source != NULL) {
        this->sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
void TTecGiFoie::run_task() {
    f32 distance;
    if (this->collidable == NULL) {
        queue_destruction();
        return;
    }
    this->source = (uaddr)find_entity_by_id(this->sourceId);
    if (this->source == 0) {
        queue_destruction();
        return;
    }
    if (TTecLuker::is_parents_unqueued((uaddr)this->orbits[0]) != 0) {
        distance = newton_sqrtf(horizontal_distance_squared(&this->orbits[0]->pad_2C, &this->position));
        if (this->collidable != NULL) {
            this->collidable->bodies->radius = 5.0f + distance;
        }
        apply_technique_to_area_targets();
        if (distance >= this->scope) {
            queue_destruction();
        }
    }
}
#pragma pop

TTecGiFoie::~TTecGiFoie() {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (TTecLuker::is_parents_unqueued((uaddr)this->orbits[i]) != 0) {
            this->orbits[i]->queue_destruction();
        }
    }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
void TTecGiFoie::vfunc_6(void *target) {
    s32 found = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (this->hitIds[i] == ((TObjBase *)target)->get_entity_id()) {
            found = 1;
        }
    }
    if (found == 0) {
        this->hitIds[this->hitCursor] = ((TObjBase *)target)->get_entity_id();
        this->hitCursor += 1;
        if (this->hitCursor >= 32) {
            this->hitCursor = 31;
        }
        HitInfo_8023154C tmp;
        tmp.type = 1;
        tmp.power = this->power;
        HitInfo_8023154C info = tmp;
        ((VObj_8023154C *)target)->m21((void *)this->source, &info, (void *)this->m_b8, 1, -1);
    }
}
#pragma pop

void TTecGiFoie::create(void *source, void *origin, s32 level) {
    new TTecGiFoie((saddr)source, (Vec *)origin, level);
}

TUnk_804CC800::TUnk_804CC800(Vec *pos, s32 angle, s32 band, s32 level, TObject *parent, u8 single) : TObject(parent) {
    this->pad_46 = 0;
    this->pad_20.x = pos->x;
    this->pad_20.y = pos->y;
    this->pad_20.z = pos->z;
    this->pad_44 = band;
    this->pad_45 = level;
    VecCopy(&this->pad_2C, &this->pad_20);
    this->pad_3C = angle;
    this->pad_38 = 0.0f;
    this->pad_40 = 0;
    this->pad_47 = single;
    if (this->pad_47 != 0) {
        Rot_802312E4 r;
        this->pad_1C = (TParticleCtrl **)mem_alloc(4);
        r.x = 0;
        r.y = 0;
        r.z = 0x4000;
        this->pad_1C[0] = (TParticleCtrl *)spawn_continuous_particle_with_direction(&this->pad_20, &r, 0x19D);
        this->pad_38 = 5.0f;
    } else {
        s32 i;
        this->pad_1C = (TParticleCtrl **)mem_alloc(TTecGiFoie__emitter_profile_table[this->pad_44].count * 4);
        for (i = 0; i < TTecGiFoie__emitter_profile_table[this->pad_44].count; i++) {
            Rot_802312E4 r;
            const Part_802312E4 *p;
            r.x = 0;
            r.y = 0;
            r.z = 0x4000;
            p = &TTecGiFoie__emitter_profile_table[this->pad_44].parts[i];
            this->pad_1C[i] = (TParticleCtrl *)spawn_particle_effect_with_rotation(&this->pad_20, &r, p->id, (p->flags & 0x1000) ? (u16)0x2000 : (u16)0);
            if (this->pad_44 == 2) {
                if (level >= 0xF && level < 0x19) {
                    if (i <= 1 && this->pad_1C[i] != NULL) {
                        this->pad_1C[i]->set_scale(1.3f, 1.3f);
                    }
                } else if (level >= 0x19 && level < 0x1E) {
                    if (i <= 1 && this->pad_1C[i] != NULL) {
                        this->pad_1C[i]->set_scale(1.3f, 1.8f);
                    }
                }
            }
        }
    }
}

TUnk_804CC800::~TUnk_804CC800() {
    u32 i;
    if (this->pad_47 != 0) {
        this->pad_1C[0]->queue_destruction();
    } else {
        for (i = 0; i < TTecGiFoie__emitter_profile_table[this->pad_44].count; i++) {
            this->pad_1C[i]->queue_destruction();
        }
    }
    mem_free(this->pad_1C);
}

void TUnk_804CC800::run_task() {
    static const f32 lbl_8044D338[3] = {0.0f, 3.5f, 7.0f};
    s32 rot[3];
    s32 bob;
    switch (pad_44) {
    case 0:
        bob = 0;
        break;
    case 1:
        bob = 1;
        break;
    case 2:
        bob = 2;
        break;
    case 3:
        bob = 0;
        break;
    case 4:
        bob = 1;
        break;
    case 5:
        bob = 2;
        break;
    default:
        bob = 0;
        break;
    }
    pad_40++;
    if (pad_46) {
        Vec offset;
        pad_38 += 0.015;
        pad_3C += 0x1C71;
        offset.x = pad_38 * cos_table_lookup(pad_3C);
        offset.z = pad_38 * sin_table_lookup(pad_3C);
        offset.y = 0.0f;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, pad_48);
        rotate_matrix_x(0, 0x4000);
        rotate_vector_by_matrix(0, &offset, &offset);
        pop_matrix();
        pad_2C.x = pad_20.x + offset.x;
        pad_2C.y = pad_20.y + offset.y;
        pad_2C.z = pad_20.z + offset.z;
    } else {
        pad_38 += 0.55f;
        pad_3C += (s32)(182.04445f * (pad_44 + 9));
        pad_2C.y = lbl_8044D338[bob] * sin_table_lookup((s32)(182.04445f * (f32)(pad_40 * 15))) + pad_20.y;
        pad_2C.x = pad_38 * cos_table_lookup(pad_3C) + pad_20.x;
        pad_2C.z = pad_38 * sin_table_lookup(pad_3C) + pad_20.z;
    }
    if (pad_47) {
        Vec dir = {0.0f, 0.0f, 1.0f};
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, pad_48);
        rotate_vector_by_matrix(0, &dir, &dir);
        pop_matrix();
        rot[0] = 0;
        rot[1] = 0;
        rot[2] = 0;
        direction_to_rotation_xz((u8 *)&dir, &rot[0], &rot[2]);
        pad_1C[0]->set_position(&pad_2C);
        pad_1C[0]->set_direction(rot);
    } else {
        u32 i;
        s16 roll;
        rot[1] = (s32)(10430.38043493439 * atan2_float(pad_2C.x - pad_20.x, pad_2C.z - pad_20.z));
        roll = i = 0;
        rot[0] = rot[1] - 0x8000;
        rot[1] = roll;
        rot[2] = 0x4000;
        for (; i < TTecGiFoie__emitter_profile_table[pad_44].count; i++) {
            pad_1C[i]->set_position(&pad_2C);
            pad_1C[i]->set_direction(rot);
        }
    }
}

void TTecGiFoie::calc_params() {
    TechniqueParams *params = calc_technique_parameters(1, level, 0xFFFF);
    ((TechniqueParams *)&power)->copy(params);
    if (level >= 15 && TTecCtrl::is_technique_ready() == 0) {
        power = (f32)(tech_high_level_linear_power_table[1].base + tech_high_level_linear_power_table[1].per_level * level);
        return;
    }
    power = power + (f32)(((TechniqueParams *)&power)->pad_24 * level);
    if (TTecCtrl::is_technique_ready()) {
        power = power * technique_scale_table[1].power;
    }
}

#pragma defer_codegen off

}
