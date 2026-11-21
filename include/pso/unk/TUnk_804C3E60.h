#ifndef PSO_UNK_TUNK_804C3E60_H
#define PSO_UNK_TUNK_804C3E60_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804C3E60 : public TObject {
public:
    TUnk_804C3E60(TObject *parent, s32 gain, s32 duration);
    virtual ~TUnk_804C3E60();
    virtual void run_task();
    s32 countdown;
    s32 gain_offset;
};
typedef char TUnk_804C3E60_size[sizeof(TUnk_804C3E60) == 0x24 ? 1 : -1];

extern "C" TUnk_804C3E60 *battle_music_gain_task;

#endif
