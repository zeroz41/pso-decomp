#ifndef PSO_MISC_TODOORANCIENT08_H
#define PSO_MISC_TODOORANCIENT08_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct BmlResource;

// The ancient-area door locked by four floor switches (switch_id and the
// three after it): one light pair per switch on its frame turns green as the
// switch is set.
struct TODoorAncient08 : public TODoorBase {
    TODoorAncient08(TObject *parent, void *set_data);
    virtual ~TODoorAncient08();
    void door_ancient08_sync_state(void *);
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

    u16 extra_switch_ids[3];  // switch_id + 1 .. + 3
    u8 pad_da[0x2];
    s32 all_switches_set;  // LOCK_SWITCH: all four switches are set
    s32 m_e0;              // cleared by the constructor, never read here
    s32 is_open;           // 1 from the time it starts opening until it closes
    s32 m_e8;              // cleared by the constructor, never read here

    static BmlResource *bml_resource;
    static s32 *texture_lists;  // [0] the bml's own (unlocked), [1] red (locked)
};

typedef char TODoorAncient08_size[sizeof(TODoorAncient08) == 0xEC ? 1 : -1];

#endif
