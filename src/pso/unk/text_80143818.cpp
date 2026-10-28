#include "types.h"
#include "pso/unk/text_80143818.h"
#include "pso/object/TObjMotion.h"

extern "C" {
s32 __ct__14TObjCollidableFP7TObject();
extern s32 __vt__10TObjMotion[];
extern s32 TObjMotion__class_name;
u8 *TObjMotion__ct(u8 *motion) {
    __ct__14TObjCollidableFP7TObject();
    *(s32 **)((s8 *)motion + 0x18) = __vt__10TObjMotion;
    *(s32 *)((s8 *)motion + 0) = (s32) TObjMotion__class_name;
    ((TObjMotion *)(motion))->reset_motion_fields();
    *(s32 *)((s8 *)motion + 0xD8) = 0;
    ((TObjMotion *)motion)->unknownF8 = 0;
    *(s32 *)((s8 *)motion + 0xDC) = 0;
    *(s32 *)((s8 *)motion + 0xE0) = 0;
    ((TObjMotion *)motion)->unknownAC = 0;
    return motion;
}

}
