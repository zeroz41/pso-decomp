#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/olgaflow/TBoss6EffHyoui.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/PlayerSlots.h"

extern "C" {
const char *TBoss6EffHyoui__name = "TBoss6EffHyoui";
f32 boss6_eff_hyoui_scale;
s8 boss6_eff_hyoui_scale_set;
extern void *tl_02;
}

void TBoss6EffHyoui::run_task() {
    if (emitter != NULL) {
        TObjPlayer *player = get_player_by_client_id(client);
        if (player != NULL && TBoss6PlotFalz::is_active(player) != 0) {
            emitter->set_position(&player->position);
        }
    }
    age++;
    if (age > duration) {
        queue_destruction();
    }
}

TBoss6EffHyoui::~TBoss6EffHyoui() {
    if (emitter != NULL) {
        TParticleCtrl::release(emitter);
    }
}

const s32 boss6_eff_hyoui_effect_ids[2] = {550, 551};

TBoss6EffHyoui::TBoss6EffHyoui(TObject *parent, u16 client, s32 effect, s32 duration)
    : TObject(parent) {
    m_name = TBoss6EffHyoui__name;
    this->client = client;
    this->duration = duration;
    emitter = NULL;
    TObjPlayer *player = get_player_by_client_id(this->client);
    if (player != NULL && TBoss6PlotFalz::is_active(player) != 0) {
        if (boss6_eff_hyoui_scale_set == 0) {
            boss6_eff_hyoui_scale_set = 1;
            boss6_eff_hyoui_scale = 0.2f;
        }
        if ((emitter = create_particle_emitter(&player->position, boss6_eff_hyoui_effect_ids[effect])) != NULL) {
            emitter->set_flags(0x40);
            emitter->set_scale(boss6_eff_hyoui_scale, boss6_eff_hyoui_scale);
        }
    }
    age = 0;
}

TBoss6EffHyoui *TBoss6EffHyoui::create(u16 client, s32 effect, s32 duration) {
    return new TBoss6EffHyoui(static_cast<TObject *>(tl_02), client, effect, duration);
}
