#ifndef PSO_EFFECT_ITEM_TITEMEFFARMOR_H
#define PSO_EFFECT_ITEM_TITEMEFFARMOR_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct AnimationMotion;
struct GinjaTextureList;
struct NJS_OBJECT;

struct TItemEffArmor : public TObject {
    virtual ~TItemEffArmor();
    uaddr m_1c;
    u8 unk_20[0x4];
    f32 m_24;
    u8 unk_28[0x4];
    void* m_2c;
    u8 _pad30[0x8];
    void* m_38;
    u8 unk_3C[0x1C];
    f32 m_58;
    u8 unk_5C[0x4];
    f32 m_60;
    u8 unk_64[0x4];
    u32 m_68;
    uaddr m_6c;
    NJS_OBJECT *model;
    AnimationMotion *motion;
    GinjaTextureList *texture_list;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TItemEffArmor_size, sizeof(TItemEffArmor) == 0x7C);

extern "C" {
void *__dt__13TItemEffArmorFv(void *arg0, s16 arg1);
}

#endif
