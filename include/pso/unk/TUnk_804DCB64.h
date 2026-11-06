#ifndef PSO_UNK_TUNK_804DCB64_H
#define PSO_UNK_TUNK_804DCB64_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804DCB64 : public TObject {
public:
    TUnk_804DCB64();
    virtual ~TUnk_804DCB64();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x8];
};
typedef char TUnk_804DCB64_size[sizeof(TUnk_804DCB64) == 0x24 ? 1 : -1];

#endif
