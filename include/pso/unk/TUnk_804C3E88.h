#ifndef PSO_UNK_TUNK_804C3E88_H
#define PSO_UNK_TUNK_804C3E88_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804C3E88 : public TObject {
public:
    virtual ~TUnk_804C3E88();
    u8 unk_1C[0x24];
};
typedef char TUnk_804C3E88_size[sizeof(TUnk_804C3E88) == 0x40 ? 1 : -1];

#endif
