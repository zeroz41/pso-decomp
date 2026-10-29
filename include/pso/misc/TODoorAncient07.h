#ifndef PSO_MISC_TODOORANCIENT07_H
#define PSO_MISC_TODOORANCIENT07_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TODoorAncient07 : public TODoorBase {
    virtual ~TODoorAncient07();
    virtual void update_open();
    virtual void update_closed();
    virtual void render();
    static void *create(void *arg0);
    static void cleanup();
    static void load_resources();
};

typedef char TODoorAncient07_size[sizeof(TODoorAncient07) == 0xD4 ? 1 : -1];
#endif
