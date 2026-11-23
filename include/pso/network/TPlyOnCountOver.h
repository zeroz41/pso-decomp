#ifndef PSO_NETWORK_TPLYONCOUNTOVER_H
#define PSO_NETWORK_TPLYONCOUNTOVER_H
#include "pso/system/task/TObject.h"
#include "types.h"

struct TObjPlayer;

class TPlyOnCountOver : public TObject {
public:
    TPlyOnCountOver(u16 player_id, s16 count, void (*callback)(TObjPlayer *));
    virtual void run_task();
    virtual ~TPlyOnCountOver();
    u16 player_id;
    s16 count;
    void (*callback)(TObjPlayer *);
public:
    static void *create(u16 player_id, s16 count, void (*callback)(TObjPlayer *));
};
LAYOUT_ASSERT(TPlyOnCountOver_size, sizeof(TPlyOnCountOver) == 0x24);

#endif
