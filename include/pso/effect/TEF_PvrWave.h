#ifndef PSO_UNK_TEF_PVRWAVE_H
#define PSO_UNK_TEF_PVRWAVE_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TEF_PvrWave : public TObject {
public:
    virtual ~TEF_PvrWave();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x1C];
};
typedef char TEF_PvrWave_size[sizeof(TEF_PvrWave) == 0x38 ? 1 : -1];

#endif
