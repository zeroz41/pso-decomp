#ifndef PSO_BOSS_BARBARAY_TBOSS7CRAWFISH_H
#define PSO_BOSS_BARBARAY_TBOSS7CRAWFISH_H

#include "types.h"
#include <stddef.h>
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"

class TParticleCtrl;

// The tuning record TLobby::dispatch_shared_handler_a hands the crawfish.
struct Boss7CrawfishParams {
    f32 speed;
    u8 unk_4[0x14];
    s32 wait_time;
};

struct TBoss7Crawfish : public TObjEnemy {
    TBoss7Crawfish(TObject *parent, void *set);
    virtual ~TBoss7Crawfish();
    s32 sub_80308AA8();
    s32 is_visible();
    s32 is_within_x_limit();
    s16 get_floor();
    virtual void clear_harmful_statuses();
    virtual void apply_shock_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_confusion_status();
    virtual void apply_slow_status();
    virtual void apply_paralysis();
    virtual void apply_poison_status();
    CollisionBody collision_body;
    Boss7CrawfishParams *params;
    s32 hit_count;
    ActorBodyHit hits[4];
    s32 attack_timer;
    TParticleCtrl *effect;
    void play_persistent_sound_at_position(s32 sound_id);
    void spawn_effect(s32 sound_id);
    void free_child();
    void spawn_ground_effects();
    void apply_hit_to_target(ActorBodyHit *hit);
    virtual void render();
    void clear_object_state_exchange();
    void check_band_and_destroy();
    void advance_to_band_check();
    void update();
    void update_motion_and_release();
    void aim_at_nearest_player();
    void update_attack_state();
    s32 try_move_by_delta(const Vec *delta);
    void change_state(s32 state);
    virtual void run_task();
    static void destroy_instance();
    static void load_static_resource();
    f32 get_health();
    void set_anim_timer(s16 v);
    void register_attack_hits();
};

LAYOUT_ASSERT(TBoss7Crawfish_collision_body, offsetof(TBoss7Crawfish, collision_body) == 0x374);
LAYOUT_ASSERT(TBoss7Crawfish_hits, offsetof(TBoss7Crawfish, hits) == 0x3A8);
LAYOUT_ASSERT(TBoss7Crawfish_size, sizeof(TBoss7Crawfish) == 0x3D0);
#endif
