#ifndef PSO_MISC_TUNK_804EFBAC_H
#define PSO_MISC_TUNK_804EFBAC_H
#include "types.h"
#include "pso/misc/TWindowBase.h"

class TUnk_804EFBAC : public TWindowBase {
public:
    virtual ~TUnk_804EFBAC();
    u8 unk_1C[0x50];
};
typedef char TUnk_804EFBAC_size[sizeof(TUnk_804EFBAC) == 0x6C ? 1 : -1];

#endif
