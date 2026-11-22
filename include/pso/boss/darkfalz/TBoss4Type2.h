#ifndef PSO_BOSS_DARKFALZ_TBOSS4TYPE2_H
#define PSO_BOSS_DARKFALZ_TBOSS4TYPE2_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/ModelNodeTables.h"
#include <stddef.h>

struct BmlResource;
struct TBoss4FormSetData;
struct CollisionBody;
class ModelNodePositionCapture;
class TParticleCtrl;
struct TBoss4DarkFalz;
class TBoss4Zanzo;
class TObjDFJisin;
struct TBoss4ZanzoParams;

/* Boss parameter block 0x36 from TLobby::dispatch_shared_handler_a (read by TBoss4Type1.cpp and
 * TObjDFHorming). move_seconds is clamped to 1..60 and scaled by 30.0 into a frame count; the two
 * levels are the 4th (level) argument of the Ra Barta / Ra Foie create calls; power is cast to f32. */
struct TBoss4Type2Params
{
    f32 move_seconds;
    u8 pad_04[0x14];
    saddr rafoie_level;
    saddr rabarta_level;
    s32 power;
};

// Dark Falz's second form. Its vtable is at 0x80486924 (emitted by TBoss4Zanzo.cpp), its ctor
// names it "TBoss4Type2" and create builds it with new(0x474). It circles the arena centre and
// relays every action it picks through its owner (send_code_25_4), so all clients run the same
// one. Field names inferred from their uses in TBoss4Zanzo.cpp.
class TBoss4Type2 : public TObjEnemy {
public:
    TBoss4Type2(TObject *parent, TBoss4FormSetData *set_data);
    virtual ~TBoss4Type2();
    virtual void run_task();
    virtual void render();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    virtual void clear_harmful_statuses();
    virtual void apply_shock_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_confusion_status();
    virtual void apply_slow_status();
    virtual void apply_paralysis();
    virtual void apply_poison_status();
    static TBoss4Type2 *create(TBoss4FormSetData *set_data);
    static s32 is_active();
    static TBoss4Zanzo *create_zanzo(TObject *parent, TBoss4ZanzoParams *params);
    static TObjDFJisin *create_jisin(TObject *parent, s32 angle);
    static s32 pick_weighted_random(s32 n, f32 *weights, s32 *values);
    f32 compute_wave_offset(f32 t);
    void init_hanger();
    s32 get_phase();
    void get_demo2_params(u16 *a, u16 *b, u16 *out);
    void draw_hanger();
    saddr pick_random_angle();
    void update_orbit_position();
    void change_action(s32 next_action);
    void send_action(s32 next_action);
    void send_turn_action(s32 next_action, s32 next_angle);
    void send_attack_code(s32 next_action, u16 id);
    void apply_packed_state(u32 code);
    void calc_grid_target_position();
    void set_grid_pos(Vec *pos);
    void find_target_pos(Vec *out);
    void send_random_action(s32 lo, s32 hi);
    void choose_next_action();
    void choose_action_after_move();
    void apply_resta_heal();
    void spawn_bishi_around_players();
    void spawn_afterimages();
    void set_attack_pattern_by_index(s32 index);
    void update_phase_timer();
    void advance_afterimage();
    void appear_enter();
    void appear_idle();
    void appear_update();
    void wait_next_idle();
    void dead_enter();
    void dead_idle();
    void dead_update();
    void move_enter();
    void move_idle();
    void move_update();
    void jisin_enter();
    void jisin_idle();
    void jisin_update();
    void beam_enter();
    void beam_idle();
    void beam_update();
    void tenchu_enter();
    void tenchu_idle();
    void tenchu_update();
    void md_stop1_enter();
    void md_stop_idle();
    void md_stop_update();
    void md_stop2_enter();
    void md_stop3_enter();
    void md_stop4_enter();
    void md_recover_enter();
    void md_recover_idle();
    void md_recover_update();

    s32 action;                      // row of boss4_type2_action_table (change_action)
    ModelNodeTables node_tables;
    TBoss4DarkFalz *owner;           // params[0], the Dark Falz that spawns it; run_task waits on it
    BmlResource *archive;
    CollisionBody *collision_body_parts; // init_collision_body_parts / free_collision_body_parts
    s32 action_timer;                // frames left in the current action
    f32 turn_ratio;                  // 0 at base_angle, 1 at target_angle
    s32 angle;                       // where it stands on its circle round the arena centre
    s32 base_angle;
    s32 target_angle;
    s32 grid_x;                      // set_grid_pos: grid cell x
    s32 grid_z;                      // set_grid_pos: grid cell z
    Vec grid_target;                 // calc_grid_target_position
    f32 texture_scroll;
    u16 target_player;               // 0xFFFF, or the player TObjDFRecover::create gets
    u8 pad_3c6[0x2];
    s32 anim;                        // row of TBoss4Type2__attack_pattern_table
    s32 unk_3cc;
    f32 anim_frame;
    f32 anim_speed;
    s32 anim_looped;
    s32 anim_mode;
    s32 move_count;                  // moves since the last other action
    s32 hit;                         // set by run_hit_reaction, cleared once drawn
    f32 beam_ratio;                  // how far it has risen for a beam; no collision while nonzero
    s32 half_hp;
    f32 hit_flash;
    f32 hp_ratio;                    // run_task: hp / referenceHp
    Vec beam_dir;
    Vec beam_side;
    Vec beam_pos;
    s32 move_frames;
    s32 move_turn_frames;
    s32 stop_action;                 // the MD_STOP action a beam, tenchu or recover ends in
    saddr resta_level;               // level argument of TTecResta::create
    TParticleCtrl *parts[8];         // particle emitters, released by the dt
    ModelNodePositionCapture *node_capture;
    Vec node_positions[3];           // node_capture's captured node positions
};

LAYOUT_ASSERT(Type2NodeTablesOffset, offsetof(TBoss4Type2, node_tables) == 0x378);
LAYOUT_ASSERT(TBoss4Type2_parts, offsetof(TBoss4Type2, parts) == 0x42C);
LAYOUT_ASSERT(TBoss4Type2_size, sizeof(TBoss4Type2) == 0x474);

#endif
