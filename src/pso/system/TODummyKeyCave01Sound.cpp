#include "pso/object/TODummyKeyCave01Sound.h"
#include "pso/object/TObject_80019A50.h"

#include "types.h"

extern "C" {
s32 __ct__7TObjectFP7TObject();

extern s32 __vt__21TODummyKeyCave01Sound[];
extern s32 TODummyKeyCave01Sound__class_name;

void TODummyKeyCave01Sound::run_task() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x20) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) - 1);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x20) == 0) {
        ((TODummyKeyCave01Sound *)arg0)->play_cave01_key_sound();
        queue_destruction__7TObjectFv((arg0));
    }
}

TODummyKeyCave01Sound::~TODummyKeyCave01Sound() {}
void *TODummyKeyCave01Sound__ct(void *dummy_key_cave01_sound, s32 arg1, s32 arg2, s32 arg3) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)dummy_key_cave01_sound + 0x18) = __vt__21TODummyKeyCave01Sound;
    *(s32 *)((s8 *)dummy_key_cave01_sound + 0) = (s32) TODummyKeyCave01Sound__class_name;
    *(s32 *)((s8 *)dummy_key_cave01_sound + 0x20) = arg3;
    *(s32 *)((s8 *)dummy_key_cave01_sound + 0x1C) = arg2;
    if ((s32) *(s32 *)((s8 *)dummy_key_cave01_sound + 0x20) <= 0) {
        ((TODummyKeyCave01Sound *)dummy_key_cave01_sound)->play_cave01_key_sound();
        queue_destruction__7TObjectFv(dummy_key_cave01_sound);
    }
    return dummy_key_cave01_sound;
}

}
