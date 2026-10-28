#include "types.h"
#include "pso/misc/TLobby_802A018C.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TODoorFourLightBase.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
s32 load_resource_from_descriptor(s32, int, void *, int, int, int);
u8 *load_gvm_texture_file(s32 arg0);
extern s32 lbl_80466118[];
extern s32 lbl_80466138[];
extern s32 lbl_80466150[];
extern s32 lbl_80466170[];
extern s32 bm_o_door_seabed01_resource_descriptor[];
extern u32 door_labo_bml_resource;
extern u32 lbl_805D6604;
extern u32 lbl_805D6608;
s32 TLobby__sub_8001FE7C(s32, s32);
s32 release_texture_list(void*);

void TLobby::free_chr_select_slots() {
    if ((u32) lbl_805D6608 != 0U) {
        release_texture_list((void*)lbl_805D6608);
        TAdSinglePlyChrSelectGC::safe_free(lbl_805D6608);
        lbl_805D6608 = 0U;
    }
    if ((u32) lbl_805D6604 != 0U) {
        release_texture_list((void*)lbl_805D6604);
        TAdSinglePlyChrSelectGC::safe_free(lbl_805D6604);
        lbl_805D6604 = 0U;
    }
    if ((u32) door_labo_bml_resource != 0U) {
        TLobby__sub_8001FE7C(door_labo_bml_resource, 1);
        door_labo_bml_resource = 0U;
    }
}

void TLanguage__sub_802A0204(void) {
    s32 global_state;
    s32 var_r0;
    s32 var_r0_2;
    global_state = TOKeyMachine01::get_global_state();
    switch (global_state) {
    case 28:
        var_r0 = (int)::operator new(0x440);
        if (var_r0 != 0) {
            var_r0 = load_resource_from_descriptor(var_r0, 5, bm_o_door_seabed01_resource_descriptor, 0, 0, 0);
        }
        door_labo_bml_resource = var_r0;
        lbl_805D6604 = (u32)load_gvm_texture_file((s32)lbl_80466118);
        lbl_805D6608 = (u32)load_gvm_texture_file((s32)lbl_80466138);
        return;
    case 29:
        var_r0_2 = (int)::operator new(0x440);
        if (var_r0_2 != 0) {
            var_r0_2 = load_resource_from_descriptor(var_r0_2, 5, bm_o_door_seabed01_resource_descriptor, 0, 0, 0);
        }
        door_labo_bml_resource = var_r0_2;
        lbl_805D6604 = (u32)load_gvm_texture_file((s32)lbl_80466150);
        lbl_805D6608 = (u32)load_gvm_texture_file((s32)lbl_80466170);
        return;
    }
}

void TODoorFourLightBase::clamp_light_index() {
    if ((s32) this->m_88 < 0) {
        this->m_88 = 0;
    }
    if ((s32) this->m_88 > 4) {
        *(s32 *)&this->m_88 = 4;
    }
    this->m_f8 = (s32) this->m_88;
}

}
