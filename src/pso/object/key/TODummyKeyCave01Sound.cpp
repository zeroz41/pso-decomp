#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/key/TODummyKeyCave01Sound.h"
#include "pso/system/task/TObject_80019A50.h"

#include "types.h"
#include "pso/system/task/TObject.h"

extern "C" {
s32 __ct__7TObjectFP7TObject();

extern s32 __vt__21TODummyKeyCave01Sound[];
extern s32 TODummyKeyCave01Sound__class_name;

void TODummyKeyCave01Sound::run_task() {
    u8 *arg0 = (u8 *)this;
    this->delay_frames = (s32) (this->delay_frames - 1);
    if ((s32) this->delay_frames == 0) {
        ((TODummyKeyCave01Sound *)arg0)->play_cave01_key_sound();
        ((TObject *)arg0)->queue_destruction();
    }
}

TODummyKeyCave01Sound::~TODummyKeyCave01Sound() {}
void *TODummyKeyCave01Sound__ct(void *dummy_key_cave01_sound, s32 arg1, s32 arg2, s32 arg3) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)dummy_key_cave01_sound + 0x18) = __vt__21TODummyKeyCave01Sound;
    *(s32 *)((s8 *)dummy_key_cave01_sound + 0) = (s32) TODummyKeyCave01Sound__class_name;
    ((TODummyKeyCave01Sound *)dummy_key_cave01_sound)->delay_frames = arg3;
    ((TODummyKeyCave01Sound *)dummy_key_cave01_sound)->sound_kind = arg2;
    if ((s32) ((TODummyKeyCave01Sound *)dummy_key_cave01_sound)->delay_frames <= 0) {
        ((TODummyKeyCave01Sound *)dummy_key_cave01_sound)->play_cave01_key_sound();
        ((TObject *)dummy_key_cave01_sound)->queue_destruction();
    }
    return dummy_key_cave01_sound;
}

}
