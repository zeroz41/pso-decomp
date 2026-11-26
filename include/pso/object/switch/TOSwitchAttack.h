#ifndef PSO_OBJECT_SWITCH_TOSWITCHATTACK_H
#define PSO_OBJECT_SWITCH_TOSWITCHATTACK_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TOSwitchAttack : public TObjBase {
    static void free_resources();
    static void load_resources();
    TOSwitchAttack(TObject *parent, void *set_data);
    virtual ~TOSwitchAttack();
    f32 size;             // scale.z: the scale of the effects
    f32 range_sq;         // scale.x squared: how near (squared) a target must be to be hit
    f32 damage;           // scale.y times twice the difficulty step
    s32 fired;            // 1 once it has gone off
    u16 trigger_switch;   // set_params[0]: the floor switch that sets it off, 0xFFFF for none
    u16 stop_switch;      // set_params[1]: while this switch is set it does nothing
    u16 repeatable;       // set_params[2] (0 or 1): 1 lets it go off again
    u8 trigger_state;     // the trigger switch's state last frame
    u8 effect_type;       // rotation_x (0-20): which effect goes with the blast
    s32 effect_timer;     // frames until the next effect of type 2
    static void create_sub(saddr parent, s32 stop_switch, s32 required_switch, s32 type, f32 scale);
    void init_params();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOSwitchAttack_size, sizeof(TOSwitchAttack) == 0xAC);

// "TOSwitchAttack", the name a switch-attack object takes.
extern const char *switch_attack_name;
#endif
