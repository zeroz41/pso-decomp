#ifndef PSO_NETWORK_TPLYONCREATED_H
#define PSO_NETWORK_TPLYONCREATED_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TPlyOnCreated : public TObject {
public:
    TPlyOnCreated(s32 client, int (*callback)(void *));
    virtual void run_task();
    virtual ~TPlyOnCreated();
    u16 player_id;
    int (*callback)(void *);
public:
    static void *create(s32 client, int (*callback)(void *));
};
LAYOUT_ASSERT(TPlyOnCreated_size, sizeof(TPlyOnCreated) == 0x24);

#endif
