#ifndef PSO_MISC_TODOORANCIENT09_H
#define PSO_MISC_TODOORANCIENT09_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct BmlResource;

// The ancient-area door locked by two floor switches (switch_id and the one
// after it): one light pair per switch on its frame turns green as the switch
// is set.
struct TODoorAncient09 : public TODoorBase {
    TODoorAncient09(TObject *parent, void *set_data);
    virtual ~TODoorAncient09();
    void door_ancient09_sync_state(void *);
    virtual void update_demo();
    virtual s32 init_door_switch_binding();
    virtual void update_open();
    virtual void update_closed();
    virtual void update_door_switch_state();
    virtual void vfunc_6(s16 *, s32);
    void play_open_sound();
    void draw_switch_lights();
    virtual void render();
    static void *create(void *set_data);
    static void destroy();
    static void load_resources();

    u16 extra_switch_id;  // switch_id + 1
    u8 pad_d6[0x2];
    s32 both_switches_set;  // LOCK_SWITCH: both switches are set
    s32 m_dc;               // cleared by the constructor, never read here
    s32 is_open;            // 1 from the time it starts opening until it closes
    s32 m_e4;               // cleared by the constructor, never read here

    static BmlResource *bml_resource;
    static s32 *texture_lists;  // [0] the bml's own (locked), [1] green (unlocked)
};

typedef char TODoorAncient09_size[sizeof(TODoorAncient09) == 0xE8 ? 1 : -1];

#endif
