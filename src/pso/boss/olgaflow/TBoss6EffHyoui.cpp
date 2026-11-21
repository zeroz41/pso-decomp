#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/olgaflow/TBoss6EffHyoui.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"

extern "C" {
const char *lbl_805D44D8 = "TBoss6EffHyoui";
f32 lbl_805D6FF8;
s8 lbl_805D6FFC;
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

const s32 lbl_8047AC70[2] = {550, 551};

TBoss6EffHyoui::TBoss6EffHyoui(TObject *parent, u16 client, s32 effect, s32 duration)
    : TObject(parent) {
    m_name = lbl_805D44D8;
    this->client = client;
    this->duration = duration;
    emitter = NULL;
    TObjPlayer *player = get_player_by_client_id(this->client);
    if (player != NULL && TBoss6PlotFalz::is_active(player) != 0) {
        if (lbl_805D6FFC == 0) {
            lbl_805D6FFC = 1;
            lbl_805D6FF8 = 0.2f;
        }
        if ((emitter = create_particle_emitter(&player->position, lbl_8047AC70[effect])) != NULL) {
            emitter->set_flags(0x40);
            emitter->set_scale(lbl_805D6FF8, lbl_805D6FF8);
        }
    }
    age = 0;
}

TBoss6EffHyoui *TBoss6EffHyoui::create(u16 client, s32 effect, s32 duration) {
    return new TBoss6EffHyoui(static_cast<TObject *>(tl_02), client, effect, duration);
}
