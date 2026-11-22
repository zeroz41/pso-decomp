#ifndef PSO_ENEMY_DARKGUNNER_TOBJENEDARKGUNNER_H
#define PSO_ENEMY_DARKGUNNER_TOBJENEDARKGUNNER_H
#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/render/TUnk_80490470.h"

class TObject;

struct TObjEneDarkGunner : public TObjEnemyCustom {
    TObjEneDarkGunner(TObject *parent, void *set_data);
    virtual ~TObjEneDarkGunner();
    static void *create(void *set_data);
    void sub_800A27CC();
    virtual void run_task();
    virtual void render();
    void set_fields_24_34_from_global(void*);
    void sub_800A159C();
    void sub_800A1520();
    int is_flag_set_388_bit26();
    void apply_fall_damage_flag();
    void set_hidden_flag();
    void trigger_action_if_not_flagged();
    virtual s32 update_movement_status();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    virtual void run_move_action();
    virtual void run_idle_action();
    virtual s32 update_action_hold_status();
    virtual void refresh_target();
    f32 render_y_offset;
    u8 unk_390[0x4];
    f32 m_394;
    u8 unk_398[0x58];
    void* children[4];
    void* child400;
    void* child404;
    TUnk_80490470 render_control;
    s32 material_phase;
    u16 center_id;  // entity id of the TObjEneDarkGunCenter that links it
    u8 pad_42a[2];
};
extern "C" const char *TObjEneDarkGunner__class_name;

LAYOUT_ASSERT(DarkGunnerSize, sizeof(TObjEneDarkGunner)==0x42C);
#endif
