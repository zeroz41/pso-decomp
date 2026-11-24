#include "pso/system/memory.h"
#include "pso/unk/text_80066F10.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/boss/galgryphon/Boss5GryphonBehavior.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/boss/galgryphon/TBoss5GryphonSnarl.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"

#include "types.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/boss/goldragon/TBoss8Dragon_8005D700.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

extern "C" {
__declspec(section ".rodata") s32 boss5_gryphon_snarl_effect_id_table[4] = { 521, 539, 540, 538 };
const char *TBoss5GryphonSnarl__name = "TBoss5GryphonSnarl";
s32 * TBoss5GryphonSnarl__effect_table;
extern s32 boss5_gryphon_snarl_effect_id_table[4];
extern s32 *TBoss5GryphonSnarl__effect_table;
extern const char *TBoss5GryphonSnarl__name;


s32 release_texture_list(void*);

void TBoss5GryphonSnarl::render() {  }

}

#pragma push
#pragma fp_contract on
void TBoss5GryphonSnarl::run_task() {
    Vec v;
    f32 inner;
    f32 outer;
    TBoss5Gryphon *instance;
    f32 scale;
    s32 i;
    s32 angle;
    s32 j;

    switch (state) {
    case 0:
        inner = 7.0f * (f32)frame;
        instance = TBoss5Gryphon::get_instance();
        scale = (f32)(30 - frame) / 30.0f;
        scale += 1.0f;
        TBoss5Gryphon::apply_snarl_hit(instance, &position, inner, scale);
        outer = 10.0f + inner;
        for (i = 0; i < 32; i++) {
            angle = (i << 16) / 32;
            if (children_20[i] == NULL) {
                children_20[i] = (TObject *)spawn_continuous_particle_effect_with_flags(&position, TBoss5GryphonSnarl__effect_table[0], 0x2040);
            }
            if (children_20[i] != NULL) {
                v.x = inner * sin_table_lookup(angle) + position.x;
                v.y = 0.0f;
                v.z = inner * cos_table_lookup(angle) + position.z;
                ((TParticleCtrl *)children_20[i])->set_position(&v);
            }
            if (children_a0[i] == NULL) {
                children_a0[i] = (TObject *)spawn_continuous_particle_effect_with_flags(&position, TBoss5GryphonSnarl__effect_table[1], 0x40);
                if (children_a0[i] != NULL) {
                    attach_particle_model(static_cast<TParticleCtrl *>(children_a0[i]), get_bml_model(boss5_gryphon_bml_resource, 1), boss5_gryphon_texture_list, 0, 0, 1.0f);
                }
            }
            if (children_a0[i] != NULL) {
                v.x = outer * sin_table_lookup(angle) + position.x;
                v.y = 0.0f;
                v.z = outer * cos_table_lookup(angle) + position.z;
                ((TParticleCtrl *)children_a0[i])->set_position(&v);
            }
        }
        frame++;
        if (frame > 30) {
            frame = 0;
            state = 1;
        }
        break;
    case 1:
        for (j = 0; j < 32; j++) {
            if (children_20[j] != NULL) {
                ((TParticleCtrl *)children_20[j])->enable();
            }
            if (children_a0[j] != NULL) {
                ((TParticleCtrl *)children_a0[j])->enable();
            }
        }
        frame++;
        if (frame > 30) {
            queue_destruction();
        }
        break;
    }
}
#pragma pop

TBoss5GryphonSnarl::~TBoss5GryphonSnarl() {
    for (s32 index = 31; index >= 0; --index) {
        if (children_a0[index] != NULL) {
            children_a0[index]->queue_destruction();
            children_a0[index] = NULL;
        }
        if (children_20[index] != NULL) {
            children_20[index]->queue_destruction();
            children_20[index] = NULL;
        }
    }
}

#pragma push
#pragma opt_common_subs off
TBoss5GryphonSnarl::TBoss5GryphonSnarl(TObject *parent, void *arg2) : TObject(parent) {
    s32 i;
    m_name = TBoss5GryphonSnarl__name;
    VecCopy(&position, (const Vec *)arg2);
    position.y = 2.0f;
    frame = 0;
    state = 0;
    spawn_particle_effect_with_flags(&position, TBoss5GryphonSnarl__effect_table[3], 0x40);
    spawn_particle_effect_with_flags(&position, TBoss5GryphonSnarl__effect_table[2], 0x40);
    for (i = 0; i < 32; i++) {
        children_20[i] = NULL;
        children_a0[i] = NULL;
    }
}
#pragma pop

void TBoss5GryphonSnarl::release_effect_table() {  }


void TBoss5GryphonSnarl::select_effect_table() {
    switch (TBoss8Dragon__sub_8005D700()) {
    case 0:
        TBoss5GryphonSnarl__effect_table = boss5_gryphon_snarl_effect_id_table;
        break;
    }
}

void TLobby__sub_80066EC0(void) {
    if (boss5_common_texture_list != NULL) {
        release_texture_list(boss5_common_texture_list);
        safe_free(boss5_common_texture_list);
        boss5_common_texture_list = NULL;
    }
    delete boss5_common_bml_resource;
    boss5_common_bml_resource = 0;
}
