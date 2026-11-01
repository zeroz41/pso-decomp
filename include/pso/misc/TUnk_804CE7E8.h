#ifndef PSO_MISC_TUNK_804CE7E8_H
#define PSO_MISC_TUNK_804CE7E8_H
#include "types.h"
#include "pso/misc/TWindowMenuIconLine.h"

class TUnk_804CE7E8 : public TWindowMenuIconLine {
public:
    virtual ~TUnk_804CE7E8();
    void advance_all_entries(s32);
    void sub_80248B7C(s16);
    void sync_level_field();
    u8 unk_88[0x4];
};
typedef char TUnk_804CE7E8_size[sizeof(TUnk_804CE7E8) == 0x8C ? 1 : -1];

#endif
