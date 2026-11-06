#ifndef PSO_UNK_TUNK_804F07C8_H
#define PSO_UNK_TUNK_804F07C8_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804F07C8 : public TObject {
public:
    // Spawns a TNpcPlayer partner for every client slot holding an NPC (the lobby's party area).
    TUnk_804F07C8(TObject *parent);
    virtual ~TUnk_804F07C8();
    virtual void run_task();
    u32 partner_count; // inferred: incremented once per partner the ctor creates
};
typedef char TUnk_804F07C8_size[sizeof(TUnk_804F07C8) == 0x20 ? 1 : -1];

#endif
