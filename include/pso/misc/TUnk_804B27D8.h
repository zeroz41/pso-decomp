#ifndef PSO_MISC_TUNK_804B27D8_H
#define PSO_MISC_TUNK_804B27D8_H
#include "types.h"
#include "pso/object/TObjMapObject.h"

// The base of the map objects a player talks to to run a quest label
// (TOCapsuleAncient01, TOCapsuleLabo, TOComputerMachine01,
// TOMonumentAncient01). No class name string survives for it.
class TUnk_804B27D8 : public TObjMapObject {
public:
    TUnk_804B27D8(TObject *parent);
    virtual ~TUnk_804B27D8();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_6(s16 *state, s32);
    virtual void interact(s32 client);
    // Sets active from the activation rule and returns it.
    virtual s32 update_active_state();
    virtual void vfunc_15();
    // The step run_task takes in demo mode.
    virtual void vfunc_16();

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

// The subclasses' constructors and destructors are still written out by hand
// and reach the base through these.
extern "C" {
void *__ct__13TUnk_804B27D8FP7TObject(void *self, TObject *parent);
void *__dt__13TUnk_804B27D8Fv(void *self, s16 del);
}

#endif
