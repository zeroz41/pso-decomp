#ifndef PSO_BOSS_OLGAFLOW_TBOSS6MINE_H
#define PSO_BOSS_OLGAFLOW_TBOSS6MINE_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/enemy/TObjEnemy.h"

// What TBoss6Type1's mine attack (TBoss6Type1__sub_802B6504) hands TBoss6Mine::create: a 0x40-byte object
// set entry copied from the mag mine's (TBoss4DarkFalz__sub_8004B4F0) followed by the mine's own spawn data.
// TBoss6Mine__ct reads 0x40-0x60 and passes the whole record to apply_set_data. Names inferred from those uses.
struct TBoss6MineSetData {
    s16 set_index; // TBoss6PlotFalz::get_next_point writes its set_index + counter here
    u8 pad_02[0x4];
    s16 entity_id; // ...and its entity_id + counter here
    s16 unk_08;
    u8 pad_0A[0x6];
    Vec position;
    u8 pad_1C[0x24];
    TObjEnemy *owner;
    Vec origin;
    Vec offset;
    s32 heading;
    s32 seed;
};

struct TBoss6Mine : public TObjEnemy {
    virtual ~TBoss6Mine();
    virtual void run_task();
    virtual void vfunc_63();
    virtual void vfunc_62();
    virtual void render_shadows();
    virtual void render();
    u32 m_374;
    TObjEnemy *owner;
    s32 heading;
    s32 state;
    u32 m_384;
    s32 seed; // state of next_random_float's sequence
    s32 state_frames;
    u32 m_390;
    u32 m_394;
    u32 m_398;
    f32 anim_frame;
    u32 rise_delay;
    u32 spread_frames;
    u32 arm_delay;
    f32 travel_distance;
    Vec start_pos;
    Vec target_pos;
    f32 fade_amount;
    void *emitter;
    void copy_pos();
    void draw();
    void update_facing_angles();
    s32 is_far_from_origin();
    static TBoss6Mine *create(TBoss6MineSetData *set_data);
    static f32 next_random_float(s32 *arg0);
    void explode_damage_players();
    void state_0();
    void state_1();
    void state_2();
    void state_3();
    void state_4();
    void state_5();
    void state_6();
    void state_7();
};

typedef char TBoss6MineSetData_size[sizeof(TBoss6MineSetData) == 0x64 ? 1 : -1];
typedef char TBoss6Mine_size[sizeof(TBoss6Mine) == 0x3D0 ? 1 : -1];

extern "C" {
s32 TBoss6Mine__ct(s32 arg0, s32 parent, TBoss6MineSetData *set_data);
void *__dt__10TBoss6MineFv(void *arg0, s16 arg1);
void explode_damage_players__10TBoss6MineFv(u8 *arg0);
}

#endif
