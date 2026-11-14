#ifndef PSO_ENEMY_TUNK_80486924_H
#define PSO_ENEMY_TUNK_80486924_H
#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/ModelNodeTables.h"

struct TBoss4DarkFalz;

// The class whose vtable is at 0x80486924 (emitted by TBoss4Zanzo.cpp). Its ctor names it "TBoss4Type2"
// (boss4_type2_class_name) and TBoss4Type2::create builds it with new(0x474), so this is Dark Falz's
// second form; its state handlers are still members of the TBoss4Type2 view in
// pso/boss/darkfalz/TBoss4Type2.h (shared with TBoss4Type1.cpp's handlers), so the class keeps its
// table name until the two are merged.
class TUnk_80486924 : public TObjEnemy {
public:
    TUnk_80486924(TObject *parent, s32 *params);
    virtual ~TUnk_80486924();
    void init_hanger();
    void draw_hanger();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void clear_harmful_statuses();
    virtual void apply_shock_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_confusion_status();
    virtual void apply_slow_status();
    virtual void apply_paralysis();
    virtual void apply_poison_status();
    s32 action;                   // row of boss4_type2_action_table (change_action)
    ModelNodeTables node_tables;
    TBoss4DarkFalz *owner;        // params[0], the Dark Falz that spawns it; run_task waits on it
    s32 unk_390;                  // TBoss4Uro::get_instance_count() at spawn
    CollisionBody *collision_body_parts; // init_collision_body_parts / free_collision_body_parts
    s32 unk_398;
    f32 unk_39c;
    s32 unk_3a0;
    s32 unk_3a4;
    s32 unk_3a8;
    s32 unk_3ac;                  // set_grid_pos: grid cell x
    s32 unk_3b0;                  // set_grid_pos: grid cell z
    Vec unk_3b4;                  // calc_grid_target_position
    f32 unk_3c0;
    u16 unk_3c4;                  // 0xFFFF, or the player TObjDFRecover::create gets
    u8 pad_3c6[0x2];
    s32 unk_3c8;
    s32 unk_3cc;
    f32 unk_3d0;
    f32 unk_3d4;
    s32 unk_3d8;
    s32 unk_3dc;
    s32 unk_3e0;
    s32 unk_3e4;
    f32 unk_3e8;
    s32 unk_3ec;                  // half the starting hp
    f32 unk_3f0;
    f32 hp_ratio;                 // run_task: hp / referenceHp
    Vec unk_3f8;
    Vec unk_404;
    Vec unk_410;
    s32 unk_41c;
    s32 unk_420;
    s32 unk_424;
    s32 unk_428;
    void *parts[8];               // particle emitters, released by the dt
    void *unk_44c;                // TObjFish__sub_800E3124(lbl_80486868, unk_450)
    Vec unk_450[3];
};

typedef char TUnk_80486924_size[sizeof(TUnk_80486924) == 0x474 ? 1 : -1];

#endif
