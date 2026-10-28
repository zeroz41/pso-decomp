#ifndef PSO_BOSS_TBOSS3VOLOPTP01_H
#define PSO_BOSS_TBOSS3VOLOPTP01_H

#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/player/TargetCursorList.h"
#include "pso/system/BmlResource.h"

#include <dolphin/mtx.h>
class TObjVoloptShutter;
struct TBoss3Volopt;

// Collision record behind TObjCollidable::m_a4.
struct TBoss3VoloptP01Collision {
    u8 pad_0[0x4];
    f32 height;
    u8 pad_8[0x10];
    u32 flags;
};

// Pieces built by TBreakUpMdl::init_from_model (vtable TBreakUpMdl__vtable).
struct TBoss3VoloptBreakupPieces {
    u8 pad_0[0xC];
    virtual ~TBoss3VoloptBreakupPieces();
};

struct TBoss3VoloptChunk {
    u8 pad_0[0x4];
    u8 *color;
};

struct TBoss3VoloptChunkList {
    u8 pad_0[0x4];
    TBoss3VoloptChunk *first;
};

struct TBoss3VoloptModelNode {
    u8 pad_0[0x4];
    void *root;
};

struct TBoss3VoloptP01Model {
    u8 pad_0[0x2C];
    TBoss3VoloptModelNode *pieces;
};

struct TBoss3VoloptP01Params {
    u8 pad_0[0x18];
    s32 values[1];
};

struct TBoss3VoloptP01Movement {
    f32 pad_0;
    f32 pad_4;
    s32 pad_8;
    s32 pad_c;
    s32 pad_10;
    s32 pad_14;
    s32 pad_18;
};

struct TBoss3VoloptP01CollisionPart {
    s32 pad_0;
    f32 pad_4;
    s32 pad_8;
    f32 pad_c;
    s32 pad_10;
    s32 pad_14;
    s32 pad_18;
    s32 pad_1c;
    s32 pad_20;
    s32 pad_24;
    s32 pad_28;
};

struct TBoss3VoloptBreakupParams {
    s32 pad_0;
    f32 pad_4[6];
};

struct TBoss3VoloptP01 : public TObjEnemyCustom {
    TBoss3VoloptP01(TBoss3Volopt *parent, s32 index, u16 id, s32 angle_param);
    TBoss3VoloptP01(TObject *parent, void *set_data);
    virtual ~TBoss3VoloptP01();
    virtual void run_task();
    virtual void render();

    void cast_tech_on_players();
    s32 fire_zonde_at_players();
    void set_primary(s32 primary);
    void push_nearby_players();
    BOOL is_mode_0();
    int is_broken();
    void get_node_position(s32 node, Vec *out);
    void sub_80042F84();
    s32 update_sink();
    s32 update_rise();
    void start_rise();
    void update_attack();
    void run_state_machine();
    void sub_80043758();
    void update_breakup();
    void update_state();
    void sub_80043CA8();
    void dispatch_state();
    static void destroy();
    static void init_breakup_effect();
    static void *create(void *set_data);
    void init_params();
    s32 sub_800443DC(s32 index);
    void load_model(s32 index);

    f32 y_offset;
    s8 rise_phase;
    u8 pad_391[0x3];
    s32 quarter_hp;
    s16 attack_timer;
    s16 effect_timer;
    s16 cast_count;
    u8 pad_39E[0x2];
    s32 resume_state;
    s32 last_state;
    s32 is_primary;
    TObject *charge_effect;
    TObject *glow_effect;
    s32 pulse_angle;
    TObjVoloptShutter *shutter;
    TargetCursorList targets;
};


typedef char TBoss3VoloptP01_size[sizeof(TBoss3VoloptP01) == 0x418 ? 1 : -1];
#endif
