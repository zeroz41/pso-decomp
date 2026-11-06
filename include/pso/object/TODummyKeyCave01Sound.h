#ifndef PSO_OBJECT_TODUMMYKEYCAVE01SOUND_H
#define PSO_OBJECT_TODUMMYKEYCAVE01SOUND_H

#include "pso/TObject.h"
#include "types.h"

class TODummyKeyCave01Sound : public TObject {
public:
    virtual ~TODummyKeyCave01Sound();
    void play_cave01_key_sound();
    virtual void run_task();
    s32 sound_kind;
    s32 delay_frames;
};

extern "C" {
void *TODummyKeyCave01Sound__ct(void *dummy_key_cave01_sound, s32 arg1, s32 arg2, s32 arg3);
}

#endif
