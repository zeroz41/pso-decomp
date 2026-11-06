#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdLoadQuestPrtTxtGC_8034A090.h"
#include "pso/ui/frontend/TAdLoadQuestPrtTxtGC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/hud/TNowLoading.h"

struct Vec3_8034A090 {
    f32 x;
    f32 y;
    f32 z;
};

struct TAdLoadQuestPrtTxtGC_8034A090 {
    u8 pad0[0x1C];
    s32 count;
    void *particles[32];
    Vec3_8034A090 pos[32];
    s32 state;
    s32 timer;
};

struct T_8034A198 {
    u8 pad0[0x18];
    void *vt;
    s32 count;
    void *objs[32];
    u8 pada0[0x220 - 0xA0];
    s32 slot;
};

extern "C" {
TAdLoadQuestPrtTxtGC *quest_load_prt_txt_by_slot[3] = {NULL, NULL, NULL};
const char *TAdLoadQuestPrtTxtGC__name = "TAdLoadQuestPrtTxtGC";

void TAdLoadQuestPrtTxtGC::run_task() {
    TAdLoadQuestPrtTxtGC_8034A090 *self = (TAdLoadQuestPrtTxtGC_8034A090 *)this;
    s32 i;
    switch (self->state) {
    case 0:
        self->timer++;
        if (self->timer > 0xF0) {
            self->timer = 0;
        }
        for (i = 0; i < self->count; i++) {
            if (self->timer > i * 0x14 && self->timer < i * 0x14 + 0x28) {
                if (self->particles[i] != NULL) {
                    ((TParticleCtrl *)(self->particles[i]))->clear_active_flag();
                    self->pos[i].x += 15.6f;
                    ((TParticleCtrl *)self->particles[i])->set_position(&self->pos[i]);
                }
            } else {
                if (self->particles[i] != NULL) {
                    ((TParticleCtrl *)(self->particles[i]))->enable();
                    self->pos[i].x = 0.0f;
                    ((TParticleCtrl *)self->particles[i])->set_position(&self->pos[i]);
                }
            }
        }
        break;
    case 1:
        break;
    case 2:
        break;
    }
}

}
TAdLoadQuestPrtTxtGC::~TAdLoadQuestPrtTxtGC() {
    s32 i;
    if (((u32 *)&quest_load_prt_txt_by_slot)[((T_8034A198 *)this)->slot] != 0) {
        ((u32 *)&quest_load_prt_txt_by_slot)[((T_8034A198 *)this)->slot] = 0;
    }
    for (i = 0; i < ((T_8034A198 *)this)->count; i++) {
        if (((T_8034A198 *)this)->objs[i] != NULL) {
            queue_destruction__7TObjectFv(((T_8034A198 *)this)->objs[i]);
            ((T_8034A198 *)this)->objs[i] = NULL;
        }
    }
}

#pragma push
#pragma fp_contract on
// Lays the loading-text particles out for this slot: a column (0), two rows (1) or a 4x8 grid (2).
TAdLoadQuestPrtTxtGC::TAdLoadQuestPrtTxtGC(TObject *parent, s32 slot) : TObject(parent) {
    s32 i;
    s32 j;
    m_name = TAdLoadQuestPrtTxtGC__name;
    this->slot = slot;
    m_224 = 0;
    for (i = 0; i < 32; i++) {
        particles[i] = NULL;
    }
    switch (this->slot) {
    case 0:
        particle_count = 22;
        for (i = 0; i < particle_count; i++) {
            particle_pos[i].x = 8.0f;
            particle_pos[i].y = 16.0f * i + 72.0f;
            particle_pos[i].z = 0.002020202f;
            particles[i] = (TParticleCtrl *)create_particle(&particle_pos[i], 15, 1);
            if (particles[i] != NULL) {
                particles[i]->set_flags(0xC0);
                particles[i]->enable();
            }
        }
        break;
    case 1:
        particle_count = 19;
        for (i = 0; i < particle_count; i++) {
            f32 x = i > 9 ? 462.0f : 50.0f;
            f32 y = i > 9 ? 445.0f : 35.0f;
            s32 column = i > 9 ? i - 9 : i;
            particle_pos[i].x = 16.0f * column + x;
            particle_pos[i].y = y;
            particle_pos[i].z = 0.0022222223f;
            particles[i] = (TParticleCtrl *)create_particle(&particle_pos[i], 8, 1);
            if (particles[i] != NULL) {
                particles[i]->set_flags(0xC0);
            }
        }
        break;
    case 2:
        particle_count = 32;
        for (i = 0; i < 8; i++) {
            f32 y = 40.0f * i + 99.0f;
            for (j = 0; j < 4; j++) {
                s32 n = i * 4 + j;
                particle_pos[n].x = 16.0f * j + 555.0f;
                particle_pos[n].y = y;
                particle_pos[n].z = 0.1f;
                particles[n] = (TParticleCtrl *)create_particle(&particle_pos[n], 8, 1);
                // The original tests particles[i] here, not the particle just created.
                if (particles[i] != NULL) {
                    particles[i]->set_flags(0xC0);
                }
            }
        }
        break;
    }
}

#pragma pop

s32 get_or_create_prt_txt__14TAdLoadQuestGCFii(s32 parent, s32 slot) {
    if (quest_load_prt_txt_by_slot[slot] == NULL) {
        quest_load_prt_txt_by_slot[slot] = new TAdLoadQuestPrtTxtGC((TObject *)parent, slot);
    }
    return (s32)quest_load_prt_txt_by_slot[slot];
}
