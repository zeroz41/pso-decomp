#include "types.h"
#include "pso/ui/frontend/TAdLoadQuestPrtTxtGC.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdLoadQuestGC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/task/TObject.h"

void TAdLoadQuestPrtTxtGC::render() {  }

TAdLoadQuestPrtTxtGC *quest_load_prt_txt_by_slot[3] = {NULL, NULL, NULL};
const char *TAdLoadQuestPrtTxtGC__name = "TAdLoadQuestPrtTxtGC";

void TAdLoadQuestPrtTxtGC::run_task() {
    s32 i;
    switch (slot) {
    case 0:
        timer++;
        if (timer > 0xF0) {
            timer = 0;
        }
        for (i = 0; i < particle_count; i++) {
            if (timer > i * 0x14 && timer < i * 0x14 + 0x28) {
                if (particles[i] != NULL) {
                    (particles[i])->clear_active_flag();
                    particle_pos[i].x += 15.6f;
                    (particles[i])->set_position(&particle_pos[i]);
                }
            } else {
                if (particles[i] != NULL) {
                    (particles[i])->enable();
                    particle_pos[i].x = 0.0f;
                    (particles[i])->set_position(&particle_pos[i]);
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

TAdLoadQuestPrtTxtGC::~TAdLoadQuestPrtTxtGC() {
    s32 i;
    if (quest_load_prt_txt_by_slot[slot] != NULL) {
        quest_load_prt_txt_by_slot[slot] = NULL;
    }
    for (i = 0; i < particle_count; i++) {
        if (particles[i] != NULL) {
            particles[i]->queue_destruction();
            particles[i] = NULL;
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
    timer = 0;
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
            particles[i] = (TParticleCtrl *)create_particle_controller(&particle_pos[i], 15, 1);
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
            particles[i] = (TParticleCtrl *)create_particle_controller(&particle_pos[i], 8, 1);
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
                particles[n] = (TParticleCtrl *)create_particle_controller(&particle_pos[n], 8, 1);
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

TAdLoadQuestPrtTxtGC *TAdLoadQuestGC::get_or_create_prt_txt(int slot) {
    if (quest_load_prt_txt_by_slot[slot] == NULL) {
        quest_load_prt_txt_by_slot[slot] = new TAdLoadQuestPrtTxtGC(this, slot);
    }
    return quest_load_prt_txt_by_slot[slot];
}
