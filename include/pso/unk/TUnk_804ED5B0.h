#ifndef PSO_UNK_TUNK_804ED5B0_H
#define PSO_UNK_TUNK_804ED5B0_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804ED5B0 : public TObject {
public:
    virtual ~TUnk_804ED5B0();
    u8 unk_1C[0x1];
    s8 m_1d;
    u8 unk_1E[0x2];
};
typedef char TUnk_804ED5B0_size[sizeof(TUnk_804ED5B0) == 0x20 ? 1 : -1];

#endif
