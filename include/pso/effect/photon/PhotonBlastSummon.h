#ifndef PSO_EFFECT_PHOTON_PHOTONBLASTSUMMON_H
#define PSO_EFFECT_PHOTON_PHOTONBLASTSUMMON_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include <dolphin/mtx.h>
#include <stddef.h>

struct BmlResource;
struct NJS_OBJECT;
class TParticleCtrl;

// One target of a photon blast: queue_photon_blast_hit fills it, the
// deliver_photon_blast_results_* functions apply it.
struct PhotonBlastHit {
    u32 identity;  // entity id of the target
    f32 value;     // the blast entry's base value
    s32 kind;      // photon blast kind
};

// What the photon blast sequence passes to each summon it creates.
struct PhotonSummonParams {
    Vec position;
    u16 owner_id;   // entity id of the player who fired the blast
    s32 is_first;   // 0 when an earlier summon of the same chain already ran its opening
    s32 has_more;   // 1 when another summon follows this one
    u8 pad_18[4];
    u8 count;       // summons in the chain
    f32 level;
};

// One attachment effect of a photon blast summon; the summon holds a counted array of them.
struct PhotonBlastAttachment {
    TParticleCtrl *obj;
    Vec pos;
    s32 joint;  // the model joint whose position it follows, or < 0 to follow the summon
    s32 angles[3];
};

// The attachments publish_photon_blast_joint_origins moves onto their joints
// while the summon's model is drawn.
struct PhotonBlastJointList {
    PhotonBlastAttachment *list;
    s32 count;
};

// A particle effect a summon attaches to itself when its camera script starts.
struct PhotonAttachmentDef {
    s32 effect_id;
    s32 delay;
    s32 duration;
    s32 joint;
    s32 angles[3];
    s32 flags;
};

// A timed particle effect spawned around the owner when a summon opens.
struct PhotonOpeningEffect {
    s32 effect_id;
    s32 delay;
    s32 duration;
    Vec offset;  // rotated by the owner's heading, 30 above its position
    s32 flags;
};

// The attachment and opening effects of one photon blast kind.
struct PhotonBlastEffectSet {
    PhotonAttachmentDef *attachments;
    s32 attachment_count;
    PhotonOpeningEffect *opening_effects;
    s32 opening_effect_count;
};

// Base of the creatures a photon blast summons (TPhotonFarlla, TPhotonGolla, ...):
// the summon camera, the attachment effects and the scene state while it plays.
class TPhotonBlastSummon : public TObjMotion {
public:
    TPhotonBlastSummon();
    virtual ~TPhotonBlastSummon();
    virtual void enter_scene();
    virtual void update_if_active();
    void begin_photon_summon_camera(s8 script);
    // Eases the camera position and target towards their goals by fixed steps.
    // The caller passes 1.0 for speed; the steps do not use it.
    void update_camera_pose(f32 speed);
    void clear_photon_blast_joint_callback();
    void set_photon_blast_joint_callback();
    void update_photon_blast_attachments();
    void free_photon();
    void spawn_photon_blast_attachment_effects(s32 kind);
    void restore_fog();
    void apply_fog();
    void show_sky();
    void hide_sky();
    void update_state();
    void restore_camera();
    void setup_photon_blast_camera();

    // 0 while update_camera_pose eases the camera in; 1 once
    // begin_photon_summon_camera has started the summon's camera script.
    s32 camera_state;
    u32 attachment_count;
    // setup_photon_blast_camera places these behind the local player.
    Vec camera_target;
    Vec camera_position;
    Vec camera_target_goal;
    Vec camera_position_goal;
    s32 camera_script;  // the camera script begin_photon_summon_camera plays
    s32 blast_kind;     // photon blast kind, the index into photon_blast_attachment_table
    f32 pad_13C[3];
    PhotonBlastAttachment *attachments;
    s16 uv_scroll;      // scrolls the model's strip UVs, advanced 15 a frame
    u8 pad_14E[2];
    f32 power;          // the summon's level; scales the hits it queues
    u32 summon_flags;   // bit 0: another summon follows, leave the scene state alone
};

LAYOUT_ASSERT(TPhotonBlastSummon_camera_state, offsetof(TPhotonBlastSummon, camera_state) == 0xFC);
LAYOUT_ASSERT(TPhotonBlastSummon_camera_target, offsetof(TPhotonBlastSummon, camera_target) == 0x104);
LAYOUT_ASSERT(TPhotonBlastSummon_camera_position_goal, offsetof(TPhotonBlastSummon, camera_position_goal) == 0x128);
LAYOUT_ASSERT(TPhotonBlastSummon_attachments, offsetof(TPhotonBlastSummon, attachments) == 0x148);
LAYOUT_ASSERT(TPhotonBlastSummon_size, sizeof(TPhotonBlastSummon) == 0x158);

extern PhotonBlastHit photon_blast_hit_queue[32];
extern s32 photon_blast_hit_count;
extern PhotonBlastHit deferred_photon_blast_hit_queue[32];
extern s32 deferred_photon_blast_hit_count;
extern u32 last_photon_blast_hit_identity;
extern u32 last_deferred_photon_blast_hit_identity;
extern PhotonBlastEffectSet photon_blast_attachment_table[7];

void clear_deferred_photon_blast_hits(void);
void clear_photon_blast_hits(void);
void queue_deferred_photon_blast_hit(u32 identity, s32 kind, s32 allow_duplicate, f32 scale);
void queue_photon_blast_hit(u32 identity, s32 kind, s32 allow_duplicate, f32 scale);
void queue_deferred_photon_blast_support(u32 identity, s32 kind, s32 allow_duplicate);
void queue_photon_blast_support(u32 identity, s32 kind, s32 allow_duplicate);
void spawn_photon_blast_opening_effects(s32 kind, s32 owner_id);
void copy_effect_params(PhotonOpeningEffect *dst, PhotonOpeningEffect *src);
void publish_photon_blast_joint_origins(NJS_OBJECT *);

#endif
