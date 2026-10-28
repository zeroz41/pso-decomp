#include "types.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/unk/text_8028A820.h"
#include "pso/misc/TOKeyMachine01.h"
extern "C" {
void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
}
extern u8 lbl_80450C50[];
extern u8 lbl_80450C6C[];
extern u8 bm_obj_door_ruins_resource_descriptor[];
extern u8 bm_obj_door_space_resource_descriptor[];
extern void *green_door_bml_resource;
extern void *green_door_texture_handle;
void load_green_door_resources(void) {
    void *p;
    green_door_bml_resource = 0;
    green_door_texture_handle = 0;
    switch (TOKeyMachine01::get_global_state()) {
    case 0x13:
    case 0x14:
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, bm_obj_door_ruins_resource_descriptor, 0, 0, 0);
        }
        green_door_bml_resource = p;
        green_door_texture_handle = load_gvm_texture_file((s32)lbl_80450C50);
        break;
    case 0x15:
    case 0x16:
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, bm_obj_door_space_resource_descriptor, 0, 0, 0);
        }
        green_door_bml_resource = p;
        green_door_texture_handle = load_gvm_texture_file((s32)lbl_80450C6C);
        break;
    }
}
