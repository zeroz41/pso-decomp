#ifndef PSO_MISC_TODOORANCIENT05_H
#define PSO_MISC_TODOORANCIENT05_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TODoorAncient05 : public TODoorBase {
    virtual ~TODoorAncient05();
    virtual void update_open();
    virtual void update_closed();
    virtual void render();
    static void *create(void *arg0);
    static void reset();
    static void load_resources();
};

typedef char TODoorAncient05_size[sizeof(TODoorAncient05) == 0xD4 ? 1 : -1];
#endif
