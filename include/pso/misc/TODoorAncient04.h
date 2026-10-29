#ifndef PSO_MISC_TODOORANCIENT04_H
#define PSO_MISC_TODOORANCIENT04_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

// A ruins door (bm_fe_obj_o_door04l.bml) built like TODoorAncient01: closed,
// it draws its frame and three glowing panels by hand; opening and closing
// play its motion. The texture list follows the lock: [0] locked, [1]
// unlocked.
class TODoorAncient04 : public TODoorBase {
public:
    TODoorAncient04(TObject *parent, void *set_data);
    virtual ~TODoorAncient04();
    virtual void render();
    virtual void update_closed();
    virtual void update_open();
    virtual void update_demo();
    static void *create(void *set_data);
    static void free_resources();
    static void load_resources();
};

typedef char TODoorAncient04_size[sizeof(TODoorAncient04) == 0xD4 ? 1 : -1];
#endif
