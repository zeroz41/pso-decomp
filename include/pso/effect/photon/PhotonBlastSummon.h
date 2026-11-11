#ifndef PSO_EFFECT_PHOTON_PHOTONBLASTSUMMON_H
#define PSO_EFFECT_PHOTON_PHOTONBLASTSUMMON_H

#include "types.h"

// One target of a photon blast: queue_photon_blast_hit fills it, the
// deliver_photon_blast_results_* functions apply it.
struct PhotonBlastHit {
    u32 identity;  // entity id of the target
    f32 value;     // the blast entry's base value
    s32 kind;      // photon blast kind
};

extern "C" {
void apply_all_default__8TFogCtrlFv(void);
extern PhotonBlastHit photon_blast_hit_queue[32];
extern s32 photon_blast_hit_count;
extern PhotonBlastHit deferred_photon_blast_hit_queue[32];
extern s32 deferred_photon_blast_hit_count;
}
void clear_deferred_photon_blast_hits(void);
void clear_photon_blast_hits(void);
void copy_effect_params(u8 *arg0, u8 *arg1);
extern "C" {
void *destroy_photon_motion_object(void *arg0, s16 arg1);
void *__ct__13TUnk_804C3248Fv(void *arg0);
}
void publish_photon_blast_joint_origins(void);
void queue_deferred_photon_blast_hit(u32 arg0, s32 arg1, s32 arg2);
extern "C" {
void queue_deferred_photon_blast_support(u32 identity, s32 kind, s32 allow_duplicate);
void queue_photon_blast_hit(u32 identity, s32 kind, s32 allow_duplicate, f32 scale);
}
void queue_photon_blast_support(void);
extern "C" {
void reset_state__10TSceneSoraFv(s32 _w0);
void spawn_photon_blast_opening_effects(s32 arg0, s32 arg1);
int update_all_default__8TFogCtrlFv(void);
}

#endif
