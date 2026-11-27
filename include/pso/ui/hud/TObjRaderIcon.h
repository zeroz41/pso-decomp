#ifndef PSO_UI_HUD_TOBJRADERICON_H
#define PSO_UI_HUD_TOBJRADERICON_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjRaderIcon : public TObjBase {
    TObjRaderIcon(TObject *parent, void *set_data);
    virtual ~TObjRaderIcon();
    s32 color_mode;     // set_params[0]: 0 green when all its switches are set, else red; 1 the fixed color
    s32 switch_count;   // set_params[1] high half: how many switches (0-12)
    s32 first_switch;   // set_params[1] low half: the first switch id
    f32 size;           // scale.x: the gate's size on the radar
    u32 color;          // set_params[2]: ARGB of the fixed color
    virtual void render();
    virtual void run_task();
    void initialize_from_placement();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjRaderIcon_size, sizeof(TObjRaderIcon) == 0xA4);



#endif
