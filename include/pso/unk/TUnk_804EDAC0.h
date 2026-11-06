#ifndef PSO_UNK_TUNK_804EDAC0_H
#define PSO_UNK_TUNK_804EDAC0_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804EDAC0 : public TObject {
public:
    virtual ~TUnk_804EDAC0();
    virtual void render();
    u8 unk_1C[0x68];
};
typedef char TUnk_804EDAC0_size[sizeof(TUnk_804EDAC0) == 0x84 ? 1 : -1];

#endif
