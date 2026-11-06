#ifndef PSO_BOSS_TBOSS4TYPE1_H
#define PSO_BOSS_TBOSS4TYPE1_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/text_8004AA04.h"

struct TBoss4DarkFalz;

struct TBoss4Type1 : public TObjEnemy
{
    TBoss4Type1(TObject *parent, s32 *params);
    virtual ~TBoss4Type1();
    virtual void run_task();
    virtual void render();
    virtual void apply_poison_status();
    virtual void apply_paralysis();
    virtual void apply_slow_status();
    virtual void apply_confusion_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_shock_status();
    virtual void clear_harmful_statuses();
    virtual void vfunc_62();
    virtual void vfunc_63();
    void sub_80053440();
    void sub_80053670();
    void snapshot_position();
    void render_effects();
    void update_boss4_phase_timer();
    void draw_parts();
    void push_players_out_of_colliders();
    void sub_80053D4C();
    void update_follow_camera_offsets();
    static s32 create(s32 arg0);
    s32 state;                    // index into the lbl_80485C48 state table
    ModelNodeTables model_nodes;
    TBoss4DarkFalz *owner;        // params[0], the Dark Falz that spawns it; run_task waits on it
    s32 unk_390;                  // TBoss4Uro::get_instance_count() at spawn
    s32 unk_394;                  // init_collision_body_parts(lbl_80485E2C, 3)
    u8 pad_398[0x8];
    s32 unk_3a0;
    s32 unk_3a4;
    s32 unk_3a8;
    s32 unk_3ac;
    u8 pad_3b0[0x14];
    s32 unk_3c4;                  // shared boss param 0x39 +0x18, clamped to 1..6
    s32 unk_3c8;
    s32 move_frames;              // boss param move_seconds (1..60, else 25) times 30
    s32 unk_3d0;
    s32 unk_3d4;
    s32 unk_3d8;                  // half the starting hp
    f32 unk_3dc;
    f32 hp_ratio;                 // run_task: hp / referenceHp
    u8 pad_3e4[0x8];
    f32 unk_3ec;
    u8 pad_3f0[0x8];
    void *parts[13];              // particle effects, released by the dt
    void *fx[3];                  // TObjFish__sub_800E3124(lbl_804860F0, unk_438[i])
    Vec unk_438[3][2];
    void *unk_480;                // TObjFish__sub_800E3124(lbl_80486120, unk_484)
    Vec unk_484[2];
};

typedef char TBoss4Type1_size[sizeof(TBoss4Type1) == 0x49C ? 1 : -1];

#endif
