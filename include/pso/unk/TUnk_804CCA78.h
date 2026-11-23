#ifndef PSO_UNK_TUNK_804CCA78_H
#define PSO_UNK_TUNK_804CCA78_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

// A sound effect played once at a position, kept alive for `frames` frames and stopped when it is
// destroyed (callers: TGoGoBallGoal::update_effects, TUnk_804CC888::run_task).
class TUnk_804CCA78 : public TObject {
public:
    TUnk_804CCA78(Vec *pos, s16 frames, s32 sound, s32 pitch, TObject *parent);
    virtual ~TUnk_804CCA78();
    virtual void run_task();
    s16 frames; // name inferred: run_task destroys the object once age passes it
    s16 age; // name inferred: counted up by run_task
    s32 sound; // name inferred: the sound effect id play_sound_effect takes
    s32 sound_handle; // name inferred: play_sound_effect's result, stopped by the dtor
};
LAYOUT_ASSERT(TUnk_804CCA78_size, sizeof(TUnk_804CCA78) == 0x28);

#endif
