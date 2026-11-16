#include "types.h"
#include "libs/dolphin/include/dolphin/mtx/GeoTypes.h"
#include "pso/ui/window/TWindowDD_80341A08.h"
#include "pso/ui/window/TWindowDD_80347F34.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDD_WS_String.h"
#include "pso/ui/window/TWindowDD_80348100.h"

extern const s32 TWindowDD__data_805DFB50;
extern const f32 TWindowDD__data_805DFC10;

    extern unsigned char lbl_804EFCA8[];
void*TWindowDD::get_entry(int a0, int a1) {  return (char*)lbl_804EFCA8 + a1 * 8; }

void TWindowDD__sub_80347F48(u8 *arg0) {
    u8 *temp_r3;
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x68));
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)temp_r3 + 0x30) = (f32) TWindowDD__data_805DFC10;
        *(s32 *)((s8 *)temp_r3 + 0x50) = (s32) TWindowDD__data_805DFB50;
    }
}

void TWindowDD::init_entry_field_64(s32 arg1) {
    s32 arg0 = (s32)this;
    u8 *var_r3;
    var_r3 = (u8 *)(arg0 + (arg1 * 4));
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x64));
    if (var_r3 != NULL) {
        ((TWindowDD_WS_String *)var_r3)->init_and_set_field50((void *)((*(s32 *)&TWindowDD__data_805DFB50)));
    }
}

void TWindowDD__sub_80347FA0(s32 arg0, s32 arg1) {
    u8 *var_r3;
    var_r3 = (u8 *)(arg0 + (arg1 * 4));
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x64));
    if (var_r3 != NULL) {
        ((TWindowDD_WS_String *)var_r3)->update_position((*(s32 *)&TWindowDD__data_805DFB50));
    }
}

void TWindowDD::refresh_sub(void* p, void* a1) { TWindowDD__sub_80341AE0((u8 *)a1); ((TWindowDD *)a1)->set_mode_2(); }

void TWindowDD::apply_input(void* p, void* a1) { TWindowDD__sub_80341AE0((u8 *)a1); ((TWindowDD *)a1)->reset_cursor(); }

void TWindowDD::update(void* p, void* a1) { TWindowDD__sub_80341AE0((u8 *)a1); ((TWindowDD *)a1)->set_mode_2(); }

extern f32 lbl_805DFB54;

void TWindowDD::update(s32 arg1) {
    TWindowDD__sub_80341AF8((u8 *)arg1);
    ((TWindowDD *)arg1)->reset_cursor();
    if ((u32) this->m_98 != 0U) {
        ((TWindowDD *)(this->m_98))->set_scale(((TWindowDD *)arg1)->get_field_0x74(), (s32) lbl_805DFB54);
        ((TWindowDD *)(this->m_98))->set_value_f32(TWindowDD__sub_8034217C((u8 *)arg1));
    }
}

extern "C" {
int play_sound_effect(void*, Vec *, void*, void*);
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

void TWindowDD::spawn_window() { play_sound_effect((void*)344320, (Vec *)((void*)0), (void*)0, (void*)0); }
void TWindowDD::play_se() { play_sound_effect((void*)339734, (Vec *)((void*)0), (void*)0, (void*)0); }
void TWindowDD::play_sound() { play_sound_effect((void*)339201, (Vec *)((void*)0), (void*)0, (void*)0); }
u8 TWindowDD__sub_803482B0(u8 *arg0) {
    s32 var_r31;
    var_r31 = 0;
    if ((((s32)TWindowDD_check_input_mask(arg0 + 0x1C, 2)) != 0) || (*(s32 *)((s8 *)arg0 + 0x94) & 2)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

}
