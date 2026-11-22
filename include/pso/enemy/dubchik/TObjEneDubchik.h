#ifndef PSO_ENEMY_DUBCHIK_TOBJENEDUBCHIK_H
#define PSO_ENEMY_DUBCHIK_TOBJENEDUBCHIK_H
#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/render/TUnk_80494938.h"

class TParticleCtrl;
class TUnk_80494968;

class TUnk_80491478;
struct BmlMotionEntry;

// The dubchik's loaded BML resource and its model table (TObjEneDubchik's TU loads it).
struct Mdl_800AA82C { u8 pad[8]; s32 f8; s32 fC; };
struct Res_800AA82C { u8 pad[0x42C]; Mdl_800AA82C *mdl; BmlMotionEntry *motions; };
extern "C" {
extern Res_800AA82C *dubchik_resource;
extern NJS_TEXLIST *dubchik_texlist;
}

class TObjEneDubchik : public TObjEnemyCustom {
public:
    TObjEneDubchik(TObject *parent, void *set_data);
    virtual s32 update_shock_clock();
    virtual ~TObjEneDubchik();
    void target_nearest_player(f32);
    void init_level_stats(s32);
    void sub_800AA10C();
    void sub_800A8B8C();
    void sub_800A8A7C();
    void update_fall_apart();  // state 5 (TObjEnemyCustom::run_death_reaction): falls apart into parts, reassembles
    s32 sub_800AB068();
    f32 sub_800AAF78(s32);
    virtual void run_move_action();
    virtual void run_idle_action();
    virtual void render();
    void render_model_and_set_attach_points();
    virtual void run_task();
    virtual s32 update_movement_status();
    s16 reassemble_count;  // 0x38C: bumped each time it falls apart; at 5 it stays dead (inferred)
    u8 pad_38E[0x2];
    s16 attack_count;  // 0x390: attacks since the last retarget; past 3 it retargets the nearest player (inferred)
    s16 collapsed;  // 0x392: set while the parts lie apart; render then draws with the base texlist (inferred)
    TUnk_80491478 *parts[3];  // the pieces it falls apart into
    s8 part_hit[3];
    u8 pad_3A3[0x1];
    f32 chase_distance;  // 0x3A4: distance walked while chasing; past a threshold it may switch target (inferred)
    TParticleCtrl *effect;  // 0x3A8: particle 0x119 while it falls apart (inferred)
    TUnk_80494968 *saver;
    TUnk_80494938 fade;
    u8 unk_3CC[0x4];
    f32 search_range;  // 0x3D0: passed to find_target_in_range (inferred)
    Vec part_offsets[3];
    u8 pad_3F8[0x24];
};
LAYOUT_ASSERT(TObjEneDubchik_size, sizeof(TObjEneDubchik) == 0x41C);

extern const char *TObjEneDubchik__class_name;

#endif
