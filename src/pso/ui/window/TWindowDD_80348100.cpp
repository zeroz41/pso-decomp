#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDD_80348100.h"

#include "types.h"

extern "C" {
int play_sound_effect(void*, void*, void*, void*);
int refresh_sub__9TWindowDDFPvPv(void);
int update__9TWindowDDFPvPv(void);
int update__9TWindowDDFl(void);

    extern const float lbl_805DFB94;
    extern const float lbl_805DFB98;
    extern const float lbl_805DFB9C;
    extern const float lbl_805DFBA0;
void TWindowDD::set_default_coords(int a0, void* a1) { refresh_sub__9TWindowDDFPvPv(); *(float*)((char*)a1 + 0x30) = lbl_805DFB94; *(float*)((char*)a1 + 0x40) = lbl_805DFB94; *(float*)((char*)a1 + 0x34) = lbl_805DFB98; *(float*)((char*)a1 + 0x44) = lbl_805DFB98; *(float*)((char*)a1 + 0x38) = lbl_805DFB9C; *(float*)((char*)a1 + 0x48) = lbl_805DFB9C; *(float*)((char*)a1 + 0x3c) = lbl_805DFBA0; *(float*)((char*)a1 + 0x4c) = lbl_805DFBA0; }

    extern const float lbl_805DFB80;
    extern const float lbl_805DFB84;
    extern const float lbl_805DFB88;
    extern const float lbl_805DFB8C;
void TWindowDD::init_layout(int a0, void* a1) { update__9TWindowDDFPvPv(); *(float*)((char*)a1 + 0x30) = lbl_805DFB80; *(float*)((char*)a1 + 0x40) = lbl_805DFB80; *(float*)((char*)a1 + 0x34) = lbl_805DFB84; *(float*)((char*)a1 + 0x44) = lbl_805DFB84; *(float*)((char*)a1 + 0x38) = lbl_805DFB88; *(float*)((char*)a1 + 0x48) = lbl_805DFB88; *(float*)((char*)a1 + 0x3c) = lbl_805DFB8C; *(float*)((char*)a1 + 0x4c) = lbl_805DFB8C; }

    extern const float TWindowDD__data_805DFB6C;
    extern const float lbl_805DFB70;
    extern const float TWindowDD__data_805DFB74;
    extern const float lbl_805DFB78;
void TWindowDD::set_default_positions(int a0, void* a1) { update__9TWindowDDFl(); *(float*)((char*)a1 + 0x30) = TWindowDD__data_805DFB6C; *(float*)((char*)a1 + 0x40) = TWindowDD__data_805DFB6C; *(float*)((char*)a1 + 0x34) = lbl_805DFB70; *(float*)((char*)a1 + 0x44) = lbl_805DFB70; *(float*)((char*)a1 + 0x38) = TWindowDD__data_805DFB74; *(float*)((char*)a1 + 0x48) = TWindowDD__data_805DFB74; *(float*)((char*)a1 + 0x3c) = lbl_805DFB78; *(float*)((char*)a1 + 0x4c) = lbl_805DFB78; }

void TWindowDD::spawn_window() { play_sound_effect((void*)344320, (void*)0, (void*)0, (void*)0); }
void TWindowDD::play_se() { play_sound_effect((void*)339734, (void*)0, (void*)0, (void*)0); }
void TWindowDD::play_sound() { play_sound_effect((void*)339201, (void*)0, (void*)0, (void*)0); }
u8 TWindowDD__sub_803482B0(u8 *arg0) {
    s32 var_r31;
    var_r31 = 0;
    if ((((s32)TWindowDD_check_input_mask(arg0 + 0x1C, 2)) != 0) || (*(s32 *)((s8 *)arg0 + 0x94) & 2)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

}
