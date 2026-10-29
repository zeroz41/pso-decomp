#ifndef PSO_MISC_TODOORANCIENT06_H
#define PSO_MISC_TODOORANCIENT06_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TODoorAncient06 : public TODoorBase {
    virtual ~TODoorAncient06();
    virtual void update_open();
    virtual void update_closed();
    virtual void render();
    static void *create(void *arg0);
    static void destroy();
    static void load_resources();
};

typedef char TODoorAncient06_size[sizeof(TODoorAncient06) == 0xD4 ? 1 : -1];
#endif
