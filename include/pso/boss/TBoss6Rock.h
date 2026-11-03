#ifndef PSO_BOSS_TBOSS6ROCK_H
#define PSO_BOSS_TBOSS6ROCK_H

#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/vector.h"

class TUnk_804F1280;
struct TBoss6Type2;

// The per-kind parameters of a falling rock (TBoss6Rock__data_80479258).
struct RockKindParams {
    s32 model_id;
    f32 radius;      // the marker's radius; players are pushed out to it
    f32 height;      // TObjMapCsn box: set y scale
    f32 width;       // TObjMapCsn box: set x/z scale
    f32 unk_10;
};

// One of the 32 rocks of the Dark Falz arena (TBoss6Type2): it waits at its
// point until commanded (set_rock_target), then falls from 450 units, lands
// as a TObjMapCsn collision box and later breaks into TBoss6CrushRock pieces.
struct TBoss6Rock : public TObjCollidable {
    TBoss6Rock(TObject *parent, s32 index);
    virtual ~TBoss6Rock();
    virtual void run_task();
    virtual void render();
    void sub_80353F5C();
    s32 m_ac;            // index into TBoss6Rock__instance_table and the point table
    u32 m_b0;            // the TObjMapCsn made when it lands
    s32 m_b4;            // kind (index into TBoss6Rock__data_80479258)
    s32 m_b8;            // kind of the next fall
    s32 m_bc;            // fast fall (1)
    s32 m_c0;            // fast fall of the next fall
    s32 m_c4;            // state: 0 waiting, 1 falling, 2 landed
    s32 m_c8;            // command: 0 none, 2 hold the landed rock
    f32 m_cc;            // fall speed
    s32 m_d0;            // y spin per frame
    Vec m_d4;            // its point
    s32 m_e0;            // frame counter of the landed push-out
    TUnk_804F1280 *m_e4; // the marker object
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
    static void create_rock_pool(s32 arg0);
    static void free_data();
    static void load_resources();
    void spawn_crush_rocks(s32 kind);
    void break_rocks_in_radius(f32 r);
    s32 push_out_of_rocks(f32 r);
    static s32 get_point(s32 arg0, s32 arg1, f32 *arg2);
};

typedef char TBoss6Rock_size[sizeof(TBoss6Rock) == 0xE8 ? 1 : -1];

extern "C" {
// The texture list and model resource load_resources loads (TBoss6CrushRock's ctor).
int TBoss6Rock__sub_80353A04(void);
int TBoss6Rock__sub_80353A0C(void);
// The point a rock pushes players out of the boss's reach towards (TBoss6Type2).
s32 TBoss6Rock__sub_80353A14(s32 i, Vec *out, f32 *radius);
// Lays the 32 rock points out on four rings around the arena centre.
void TBoss6Rock__sub_80354188(void);
// Pushes the players out of a landed rock, hurting them when it lands.
void TBoss6Rock__sub_803542E8(TBoss6Rock *rock, s32 landed);
// Clears the owner (TBoss6Type2's dtor): every rock then destroys itself.
void TBoss6Rock__sub_80354A44(void);
}

#endif
