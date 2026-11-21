#ifndef PSO_UI_HUD_TLOADINGCUR_H
#define PSO_UI_HUD_TLOADINGCUR_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TLoadingCur : public TObject {
    TLoadingCur(TObject *parent, Vec *pos);
    virtual ~TLoadingCur();
    void sub_8001CCD4();
    void update_camera_facing_offset();
    u8 unk_1C[0x4];
    f32 m_20;
    u8 unk_24[0x4];
    void* m_44;
    u8 _pad48[0x8];
    void* m_50;
    static s32 calc_clamp_offset(s32 arg0, u8 *arg1, u8 *arg2);
    void render();
    void run_task();
    u8 unk_38[0x4];
    f32 m_3c;
    u8 unk_40[0x14];
    f32 m_54;
    u8 unk_58[0x4];
};

LAYOUT_ASSERT(TLoadingCur_size, sizeof(TLoadingCur) == 0x5C);

extern "C" {
void *__dt__11TLoadingCurFv(void *arg0, s16 arg1);
}

#endif
