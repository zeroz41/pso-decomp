#ifndef PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWAMIRAGE_H
#define PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWAMIRAGE_H

#include "types.h"

struct NJS_OBJECT;
struct BmlResource;
struct TBreakUpMdlData;
struct SampledMotionPoints;
struct player_stats;
struct AttackParams;
struct ActorParamBlock;
#include "pso/enemy/shinowa/TObjEneMe3Shinowa.h"

struct TObjEneMe3ShinowaReal;

struct TObjEneMe3ShinowaMirage : public TObjEneMe3Shinowa {
    TObjEneMe3ShinowaMirage(TObject *parent, TObjEneMe3ShinowaReal *owner, s32 entity_id, s32 set_index);
    virtual ~TObjEneMe3ShinowaMirage();
    virtual void apply_sword_hits();
    virtual s32 can_hit_same_target();
    virtual void select_next_attack_state();
    virtual void update_player_state_default();
    virtual s32 update_effect();
    virtual void dispatch_if_active();
    virtual void apply_effect_pair();
    virtual void state_fade_out(s32);
    void run_death_reaction();
    void run_hit_reaction();
    static void advance_camera_ctrl_step(NJS_OBJECT *);
    void render();
    void clear_mirage();
    void set_flag_0x100();
    void init_mirage();
    void activate_mirage(s32 index);
    void run_task();
    static TObjEneMe3ShinowaMirage *create(TObjEneMe3ShinowaReal *owner, s32 entity_id, s32 set_index);
    static void set_slot_min_clamped_value(s32 slot, f32 speed);
    static void free_shared_resources();
    // The enemy factory entry: builds the real Shinowa for a set entry.
    static void *create_real(void *set_data);
    u16 owner_id;
    NJS_ARGB fade_color;

    // Shared by every mirage.
    static const char *class_name;
    static BmlResource *bml_resource;
    static s32 render_node_index;
    static TBreakUpMdlData *breakup_model;
    static SampledMotionPoints *sword_trail_a;
    static SampledMotionPoints *sword_trail_b;
    static SampledMotionPoints *attack_trail;
    static Vec node_origin;
    // Per-variant parameter tables fetched from TLobby.
    static player_stats *base_params_by_variant[2];
    static AttackParams *attack_params_by_variant[2];
    static ActorParamBlock *resistance_params_by_variant[2];
    static TObjEneMe3ShinowaParams *mirage_info_table[2];
    // Copy of the model's texture list (the mirage swaps the first three texture addresses).
    static NJS_TEXLIST alternate_texture_list;
    static Vec body_node_position;
    static s32 *material_color_pointers[4];
    static EnemyMoveParams init_params;
};

LAYOUT_ASSERT(TObjEneMe3ShinowaMirage_size, sizeof(TObjEneMe3ShinowaMirage) == 0x440);
void load_shinowa_mirage_resources();

#endif
