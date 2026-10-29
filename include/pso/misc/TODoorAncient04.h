#ifndef PSO_MISC_TODOORANCIENT04_H
#define PSO_MISC_TODOORANCIENT04_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TODoorAncient04 : public TODoorBase {
    virtual ~TODoorAncient04();
    virtual void update_demo();
    virtual void update_open();
    virtual void update_closed();
    virtual void render();
    static void *create(void *arg0);
    static void cleanup_refs();
    static void load_resources();
};

typedef char TODoorAncient04_size[sizeof(TODoorAncient04) == 0xD4 ? 1 : -1];
#endif
