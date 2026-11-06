#ifndef PSO_UI_CHARCREATE_TCHCRTAGINFORMATION_H
#define PSO_UI_CHARCREATE_TCHCRTAGINFORMATION_H

#include "types.h"
#include "pso/TChCrTag.h"

struct TChCrTagInformation : public TChCrTag {
    virtual ~TChCrTagInformation();
    void draw_char_info_sprites();
    void render();
    void update_selected_char();
    void run_task();
    static void *create(void *arg0);
    static void *create_default();
    u8 unk_1C[0x8];
    f32 m_24;
    f32 m_28;
    u8 unk_2C[0x8];
    f32 m_34;
    u8 unk_38[0x4];
};

typedef char TChCrTagInformation_size[sizeof(TChCrTagInformation) == 0x3C ? 1 : -1];

extern "C" {
int TChCrTagInformation__vt4(void);
void *__dt__19TChCrTagInformationFv(void *arg0, s16 arg1);
}

// --- C functions defined in TChCrTagInformation.cpp ---
extern "C" {
int TChCrTagInformation__vt4(void);
void *__dt__19TChCrTagInformationFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
