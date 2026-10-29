#ifndef PSO_MISC_TOQUESTTALKBASE_H
#define PSO_MISC_TOQUESTTALKBASE_H
#include "types.h"
#include "pso/object/TObjMapObject.h"

// The base of the map objects a player talks to to run a quest label
// (TOCapsuleAncient01, TOCapsuleLabo, TOComputerMachine01,
// TOMonumentAncient01). No class name string survives for it; it is named
// for that role.
class TOQuestTalkBase : public TObjMapObject {
public:
    TOQuestTalkBase(TObject *parent);
    virtual ~TOQuestTalkBase();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_6(s16 *state, s32);
    virtual void interact(s32 client);
    // Sets active from the activation rule and returns it.
    virtual s32 update_active_state();
    // The per-frame animation step run_task ends with (the capsules spin
    // their lids). Empty here; defined at the end of TOComputerMachine01's
    // TU, where the linker kept the copy of this (inline) body.
    virtual void animate();
    // The step run_task takes in demo mode.
    virtual void update_demo();

    void set_quest_label(s32 label);
    void set_script_id(s32 id);
    s32 read_set_params();

    // 0 never, 1 a player within 70, 2 switch_id set on this floor.
    s32 activation;
    s32 active;  // 1 draws the model with its motion
    s32 switch_id;
    // 100-999 run quest_label on the mission manager, otherwise on the area
    // manager.
    s32 script_id;
    s32 quest_label;  // the label the quest thread runs, 0 for none
    TObject *quest_thread;
    s32 visible;  // update_object_view_visibility's last result
};

#endif
