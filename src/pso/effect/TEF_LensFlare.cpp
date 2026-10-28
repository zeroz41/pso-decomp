#include "types.h"
#include "pso/effect/TEF_LensFlare.h"
#include "pso/effect/TEF_PvrWave.h"
#include "pso/effect/TEF_LensFlare.h"

struct Base_8008194C_80081278 { char pad[0x50]; };
struct VObj_8008194C_80081278 : Base_8008194C_80081278 {
    virtual void m0();
    virtual void m1();
};

struct RecoveredGlobal_800818D8_lbl_8048E040 {
    s32 value;
    u8 remaining[0xEC];
};

struct RecoveredGlobal_800818D8_lbl_8048E130 {
    s32 value;
    u8 remaining[0x34];
};

extern "C" {
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern RecoveredGlobal_800818D8_lbl_8048E040 lens_flare_reflected_element_descriptors;
extern s32 __vt__13TEF_LensFlare[];
extern s32 TEF_LensFlare__class_name;
u8 *TEF_LensFlare__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__13TEF_LensFlareFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);

}
TEF_LensFlare::~TEF_LensFlare() {

}
extern "C" {

typedef char RecoveredGlobal_800818D8_lbl_8048E040_size[sizeof(RecoveredGlobal_800818D8_lbl_8048E040) == 0xF0 ? 1 : -1];
typedef char RecoveredGlobal_800818D8_lbl_8048E130_size[sizeof(RecoveredGlobal_800818D8_lbl_8048E130) == 0x38 ? 1 : -1];
u8 *TEF_LensFlare__ct(u8 *ef_lens_flare, s32 parent, s32 arg2) {
    __ct__8TObjBaseFP7TObject((void *)ef_lens_flare, (void *)parent);
    *(s32 **)((s8 *)ef_lens_flare + 0x18) = &(*(RecoveredGlobal_800818D8_lbl_8048E130 *)&__vt__13TEF_LensFlare).value;
    *(s32 *)((s8 *)ef_lens_flare + 0) = (s32) TEF_LensFlare__class_name;
    ((TEF_LensFlare *)(ef_lens_flare))->apply_object_set_data((void *)arg2);
    *(s32 **)((s8 *)ef_lens_flare + 0x90) = &lens_flare_reflected_element_descriptors.value;
    return ef_lens_flare;
}

void TEF_LensFlare::run_task() {  }
void TEF_PvrWave::render() {  }

void TEF_PvrWave::run_task() {
    struct VObj_8008194C_80081278 *o = (struct VObj_8008194C_80081278 *)*(void **)((s8 *)this + 0x1C);
    o->m1();
}

}
