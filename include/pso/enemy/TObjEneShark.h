#ifndef PSO_ENEMY_TOBJENESHARK_H
#define PSO_ENEMY_TOBJENESHARK_H

#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/misc/RenderFadeState.h"

struct TObjEneShark {
    void sub_800AC9DC(s32);
    void apply_clamped_mode_param();
    void vfunc_83();
    void vfunc_101();
    void vfunc_98();
    void vfunc_97();
    void vfunc_96();
    void vfunc_95();
    void vfunc_94();
    void vfunc_93();
    void render();

    u8 unknown00[0x18];
    void* virtualTable;
    u8 unknown1C[0x08];
    void* textures;
    u8 unknown28[0x08];
    u32 m_30;
    void* model;
    f32 position[3];
    u8 unknown44[0x1C];
    s32 rotation_y;
    u8 unknown64[0x54];
    s16 m_b8;
    u8 unk_BA[0x6];
    f32 m_c0;
    u8 unk_C4[0x14];
    u32 m_d8;
    u32 m_dc;
    u8 _padE0[0x1CC];
    u32 m_2ac;
    u8 unknown2B0[0x4C];
    f32 body_center[3];
    u8 unknown308[0x1E];
    s16 action;
    u16 m_328;
    u8 _pad32A[0x2];
    s16 m_32c;
    u8 _pad32E[0x6];
    u32 m_334;
    u8 _pad338[0x2];
    s16 m_33a;
    u16 m_33c;
    u16 m_33e;
    u8 _pad340[0x10];
    u32 m_350;
    u8 _pad354[0x14];
    u32 m_368;
    u8 _pad36C[0x8];
    u16 m_374;
    u16 m_376;
    u32 m_378;
    u32 m_37c;
    f32 render_y_offset;
    u8 unknown384[0x0C];
    u32 m_390;
    u8 _pad394[0x14];

    MaterialOpacityFade fade;

    void* m_3c4;
    void* m_3c8;
    RenderFadeState camera_fades[4];
    static void *create(void *arg0);
    static void free_resources();
};

typedef char TObjEneSharkFadeOffset[offsetof(TObjEneShark, fade) == 0x3A8 ? 1 : -1];

#include <stddef.h>
#define SHARK_OFFSET(member, offset) \
    typedef char Shark_##member##_offset[(offsetof(TObjEneShark, member) == offset) ? 1 : -1]
SHARK_OFFSET(virtualTable, 0x18);
SHARK_OFFSET(textures, 0x24);
SHARK_OFFSET(m_30, 0x30);
SHARK_OFFSET(model, 0x34);
SHARK_OFFSET(position, 0x38);
SHARK_OFFSET(rotation_y, 0x60);
SHARK_OFFSET(m_b8, 0xB8);
SHARK_OFFSET(m_d8, 0xD8);
SHARK_OFFSET(m_dc, 0xDC);
SHARK_OFFSET(m_2ac, 0x2AC);
SHARK_OFFSET(body_center, 0x2FC);
SHARK_OFFSET(action, 0x326);
SHARK_OFFSET(m_328, 0x328);
SHARK_OFFSET(m_32c, 0x32C);
SHARK_OFFSET(m_334, 0x334);
SHARK_OFFSET(m_33a, 0x33A);
SHARK_OFFSET(m_33c, 0x33C);
SHARK_OFFSET(m_33e, 0x33E);
SHARK_OFFSET(m_350, 0x350);
SHARK_OFFSET(m_368, 0x368);
SHARK_OFFSET(m_374, 0x374);
SHARK_OFFSET(m_376, 0x376);
SHARK_OFFSET(m_378, 0x378);
SHARK_OFFSET(m_37c, 0x37C);
SHARK_OFFSET(render_y_offset, 0x380);
SHARK_OFFSET(m_390, 0x390);
SHARK_OFFSET(fade, 0x3A8);
SHARK_OFFSET(m_3c4, 0x3C4);
SHARK_OFFSET(m_3c8, 0x3C8);
SHARK_OFFSET(camera_fades, 0x3CC);
#undef SHARK_OFFSET
typedef char SharkFadeStride[(sizeof(RenderFadeState) == 0x1C) ? 1 : -1];
typedef char SharkSize[(sizeof(TObjEneShark) == 0x43C) ? 1 : -1];

extern "C" {
void *TObjEneShark__ct(void *arg0, void *arg1, void *arg2);
void TObjPlayer__sub_800ACA0C(void);
}

#endif
