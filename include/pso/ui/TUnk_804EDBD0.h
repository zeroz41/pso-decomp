#ifndef PSO_UI_TUNK_804EDBD0_H
#define PSO_UI_TUNK_804EDBD0_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804EDBD0 : public TObject {
public:
    virtual ~TUnk_804EDBD0();
    void *init_vtable();
    virtual void run_task();
    u8 unk_1C[0x4];
};
typedef char TUnk_804EDBD0_size[sizeof(TUnk_804EDBD0) == 0x20 ? 1 : -1];

#endif
