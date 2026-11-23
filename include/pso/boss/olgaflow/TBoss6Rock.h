#ifndef PSO_BOSS_OLGAFLOW_TBOSS6ROCK_H
#define PSO_BOSS_OLGAFLOW_TBOSS6ROCK_H

#include "types.h"

struct TObjMapCsn;
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"

class TUnk_804F1280;
struct BmlResource;
struct NJS_TEXLIST;
struct TBoss6Type2;

// The per-kind parameters of a falling rock (boss6_rock_kind_params).
struct RockKindParams {
    s32 model_id;
    f32 radius;      // the marker's radius; players are pushed out to it
    f32 height;      // TObjMapCsn box: set y scale
    f32 width;       // TObjMapCsn box: set x/z scale
    f32 unk_10;
};

// One of the 32 rocks of the Olga Flow arena (TBoss6Type2): it waits at its
// point until commanded (set_rock_target), then falls from 450 units, lands
// as a TObjMapCsn collision box and later breaks into TBoss6CrushRock pieces.
struct TBoss6Rock : public TObjCollidable {
    TBoss6Rock(TObject *parent, s32 index);
    virtual ~TBoss6Rock();
    // Pushes the players out of a landed rock, hurting them when it lands.
    void push_out_players(s32 landed);
    virtual void run_task();
    virtual void render();
    void create_map_csn();
    s32 rock_index;                  // index into TBoss6Rock__instance_table and the point table
    TObjMapCsn *map_csn;             // the TObjMapCsn made when it lands
    s32 kind_index;                  // kind (index into boss6_rock_kind_params)
    s32 next_kind_index;             // kind of the next fall
    s32 fast_fall;                   // fast fall (1)
    s32 next_fast_fall;              // fast fall of the next fall
    s32 fall_state;                  // state: 0 waiting, 1 falling, 2 landed
    s32 command;                     // command: 0 none, 2 hold the landed rock
    f32 fall_speed;                  // fall speed
    s32 spin_speed;                  // y spin per frame
    Vec rock_point;                  // its point
    s32 push_timer;                  // frame counter of the landed push-out
    TUnk_804F1280 *marker;           // the marker object
    static const char *class_name;
    static TUnk_804F1280 *create();
    static TBoss6Rock *create(s32 index);
    static s32 is_rock_valid(s32 arg0);
    static s32 is_rock_state_2(int i);
    static void reset_rock_state(s32 arg0);
    static void clear_rock_state(s32 i);
    static void set_rock_target(s32 i, s32 a, s32 b);
    void release_object();
    void randomize_motion();
    static const RockKindParams *get_rock_entry(s32 arg0);
    void break_and_release();
    void update_fall();
    void init_spin_params();
    void draw_model();
    static s32 is_active();
    static void create_rock_pool(TBoss6Type2 *owner);
    static void free_data();
    static void load_resources();
    static void spawn_crush_rocks(Vec *point, s32 kind);
    static void break_rocks_in_radius(Vec *point, f32 radius);
    static s32 push_out_of_rocks(Vec *point, f32 radius);
    static s32 get_point(s32 index, Vec *point, f32 *radius);
    // The point a rock pushes players out of the boss's reach towards (TBoss6Type2).
    static s32 get_push_target(s32 i, Vec *out, f32 *radius);
    // Lays the 32 rock points out on four rings around the arena centre.
    static void init_rock_points();
    // Clears the owner (TBoss6Type2's dtor): every rock then destroys itself.
    static void clear_owner();
    // The model resource and texture list load_resources loads (TBoss6CrushRock's ctor).
    static BmlResource *get_resource();
    static NJS_TEXLIST *get_texture_list();
};

LAYOUT_ASSERT(TBoss6Rock_size, sizeof(TBoss6Rock) == 0xE8);

#endif
