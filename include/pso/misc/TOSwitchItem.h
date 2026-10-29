#ifndef PSO_MISC_TOSWITCHITEM_H
#define PSO_MISC_TOSWITCHITEM_H

#include "types.h"
#include "pso/misc/TOKey.h"

// What a TOSwitchItem counts (set_params[1]; 8 and up count every item).
enum SwitchItemFilter {
    SWITCH_ITEM_ANY = 0,
    SWITCH_ITEM_WEAPON = 1,
    SWITCH_ITEM_ARMOR = 2,
    SWITCH_ITEM_SHIELD = 3,
    SWITCH_ITEM_UNIT = 4,
    SWITCH_ITEM_MAG = 5,
    SWITCH_ITEM_TOOL = 6,   // counts the stack sizes
    SWITCH_ITEM_MESETA = 7  // counts the amounts
};

// A floor switch held on while enough items of one kind lie on the ground
// within its radius (scale.x).
class TOSwitchItem : public TOKey {
public:
    TOSwitchItem(TObject *parent, void *set_data);
    virtual ~TOSwitchItem();
    virtual void run_task();
    virtual void render();
    virtual void send_switch_on();
    virtual void debug_draw_key_id();
    void init_params();
    static void *create(void *set_data);
    static void load_assets();
    static void free_assets();

    f32 range_sq;        // scale.x squared
    s32 items_present;   // the count reached required_count
    s32 item_filter;     // SwitchItemFilter
    s32 required_count;  // set_params[2] + 1
};

typedef char TOSwitchItem_size[sizeof(TOSwitchItem) == 0xF8 ? 1 : -1];

extern const char *TOSwitchItem__class_name;

#endif
