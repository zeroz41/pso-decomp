#ifndef PSO_PLAYER_TUNK_804E3BD8_H
#define PSO_PLAYER_TUNK_804E3BD8_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TBreakUpMdlData;

// Base of the De Rol Le breakup effects: a TBreakUpMdlData and one 0x2C piece record per node.
class TUnk_804E3BD8 : public TObject {
public:
    TUnk_804E3BD8(TObject *parent);
    virtual ~TUnk_804E3BD8();
    void sub_802E75B8();
    void alloc_breakup_model(s32);
    TBreakUpMdlData *model;
    s32 age;        // frames alive; run_task destroys the effect at 0xA0
    s32 count;      // node count, copied from model->m_count
    u8 *pieces;     // count records of 0x2C bytes
};

#endif
