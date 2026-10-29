#ifndef PSO_MISC_TODOORANCIENT01_H
#define PSO_MISC_TODOORANCIENT01_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TODoorAncient01 : public TODoorBase {
    virtual ~TODoorAncient01();
    virtual void update_demo();
    virtual void update_open();
    virtual void update_closed();
    virtual void render();
    static void *create(void *arg0);
    static void free_statics();
    static void load_assets();
};

typedef char TODoorAncient01_size[sizeof(TODoorAncient01) == 0xD4 ? 1 : -1];
#endif
