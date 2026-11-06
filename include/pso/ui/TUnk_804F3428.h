#ifndef PSO_UI_TUNK_804F3428_H
#define PSO_UI_TUNK_804F3428_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804F3428 : public TObject {
public:
    virtual ~TUnk_804F3428();
    void *init(void *, void *, void *);
    virtual void run_task();
    u8 unk_1C[0x4];
    u32 m_20;
};
typedef char TUnk_804F3428_size[sizeof(TUnk_804F3428) == 0x24 ? 1 : -1];

#endif
