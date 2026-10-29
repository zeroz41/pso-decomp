#ifndef PSO_MISC_TODOORANCIENT03_H
#define PSO_MISC_TODOORANCIENT03_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TODoorAncient03 : public TODoorBase {
    virtual ~TODoorAncient03();
    virtual void update_demo();
    virtual void update_open();
    virtual void update_closed();
    virtual void render();
    static void *create(void *arg0);
    static void free_resources();
    static void load_resources();
};

typedef char TODoorAncient03_size[sizeof(TODoorAncient03) == 0xD4 ? 1 : -1];
#endif
