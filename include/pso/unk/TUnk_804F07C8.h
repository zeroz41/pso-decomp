#ifndef PSO_UNK_TUNK_804F07C8_H
#define PSO_UNK_TUNK_804F07C8_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804F07C8 : public TObject {
public:
    virtual ~TUnk_804F07C8();
    virtual void run_task();
    u8 unk_1C[0x4];
};
typedef char TUnk_804F07C8_size[sizeof(TUnk_804F07C8) == 0x20 ? 1 : -1];

#endif
