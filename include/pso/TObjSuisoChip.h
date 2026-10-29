#ifndef PSO_TOBJSUISOCHIP_H
#define PSO_TOBJSUISOCHIP_H
#include "pso/TObjChip.h"
#include "types.h"

class TObjBase;

// A debris chip of the seabed tanks (TObjSeabedSuisoBrakable,
// TOTrapSeabed01): drawn around its owner's position and turn.
class TObjSuisoChip : public TObjChip {
public:
    TObjSuisoChip(TObjBase *owner, TObjChipSpawnParams *params);
    TObjSuisoChip(TObjBase *owner, TObjChipParams *params);
    virtual ~TObjSuisoChip();
    virtual s32 vfunc_8();
    virtual s32 vfunc_10(Vec *center);
    virtual void vfunc_12();

    static const char *class_name;

    Vec origin;      // the owner's position
    s32 rotation_y;  // the owner's y turn
    s32 pad_244;     // 1 hides the chips in vfunc_12
    s32 pad_248;
};

typedef char TObjSuisoChip_size[sizeof(TObjSuisoChip) == 0x24C ? 1 : -1];
#endif
