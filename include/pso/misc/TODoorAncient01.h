#ifndef PSO_MISC_TODOORANCIENT01_H
#define PSO_MISC_TODOORANCIENT01_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

// The ruins door (bm_fe_obj_o_door01l.bml). Closed, it draws its frame and
// three glowing panels by hand; opening and closing play its motion. The
// texture list follows the lock: [0] locked, [1] unlocked.
class TODoorAncient01 : public TODoorBase {
public:
    TODoorAncient01(TObject *parent, void *set_data);
    virtual ~TODoorAncient01();
    virtual void render();
    virtual void update_closed();
    virtual void update_open();
    virtual void update_demo();
    static void *create(void *set_data);
    static void free_statics();
    static void load_assets();
};

typedef char TODoorAncient01_size[sizeof(TODoorAncient01) == 0xD4 ? 1 : -1];
#endif
