#ifndef PSO_ITEM_TUNK_804C4498_H
#define PSO_ITEM_TUNK_804C4498_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

class TObjBase;

// Base of the two item placement searches (vtable 0x804C4498): walks rings of
// candidate positions around origin until one has ground below and no player
// body in the way.
class TUnk_804C4498 : public TObject {
public:
    TUnk_804C4498(TObject *parent, TObjBase *source, const Vec *pos, s8 arg);
    virtual ~TUnk_804C4498();
    void sub_801D5884(u8);
    s32 reset_placement_search_ring();
    s32 step_placement_search();
    s8 unk_1C;
    s8 ring;
    s8 sample;
    s8 count;
    u16 client_id; // get_entity_id(source), 0xFFFF without one
    s32 room;
    s32 heading;
    s32 step;
    s32 angle;
    f32 radius;
    Vec origin;
    Vec candidate;
    s32 online;
};

#endif
