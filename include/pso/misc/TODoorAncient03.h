#ifndef PSO_MISC_TODOORANCIENT03_H
#define PSO_MISC_TODOORANCIENT03_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

// A ruins door (bm_fe_obj_o_door03l.bml) built like TODoorAncient01: closed,
// it draws its frame and three glowing panels by hand; opening and closing
// play its motion. The texture list follows the lock: [0] locked, [1]
// unlocked.
class TODoorAncient03 : public TODoorBase {
public:
    TODoorAncient03(TObject *parent, void *set_data);
    virtual ~TODoorAncient03();
    virtual void render();
    virtual void update_closed();
    virtual void update_open();
    virtual void update_demo();
    static void *create(void *set_data);
    static void free_resources();
    static void load_resources();
};

typedef char TODoorAncient03_size[sizeof(TODoorAncient03) == 0xD4 ? 1 : -1];
#endif
