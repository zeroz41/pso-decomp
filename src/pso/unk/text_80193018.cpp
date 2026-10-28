#include "types.h"
#include "pso/unk/text_80193018.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"

extern char lbl_80445A30[];
extern char lbl_80445A44[];
extern char lbl_80445A60[];
extern char lbl_80445A74[];
extern char lbl_80445A90[];
extern char lbl_80445AA4[];
extern char lbl_80445AC0[];
extern char lbl_80445AD4[];
extern char lbl_80445AF0[];
extern char lbl_80445B08[];
extern char lbl_80445B20[];
extern char lbl_80445B38[];
extern char lbl_80445B50[];
extern char lbl_80445B68[];
extern const char *fe_obj_lazer2_4m_model_names[9];
extern const char *fe_obj_lazer2_4m_motion_names[5];
extern BmlResourceDescriptor lazer_fence_norm_episode1_resource_descriptor;
extern const char *fe_obj_lazer2_2_model_names[9];
extern const char *fe_obj_lazer2_2_motion_names[5];
extern BmlResourceDescriptor lazer_fence_norm_episode2_resource_descriptor;

extern "C" {
void *load_resource_from_descriptor(void *, int, BmlResourceDescriptor *, int, int, int);
u8 *load_gvm_texture_file(s32 arg0);
}
extern u8 lbl_80445BB8[];
extern u8 lbl_80445BCC[];
extern s32 lazer_fence_norm_texture_list;
extern void *lazer_fence_norm_bml_resource;
void load_lazer_fence_norm_resources(void) {
    void *obj;
    switch (get_current_area()) {
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 34:
    case 35:
        obj = ::operator new(0x440);
        if (obj != 0) {
            obj = load_resource_from_descriptor(obj, 5, &lazer_fence_norm_episode2_resource_descriptor, 0, 0, 0);
        }
        lazer_fence_norm_bml_resource = obj;
        lazer_fence_norm_texture_list = (s32)load_gvm_texture_file((s32)lbl_80445BB8);
        break;
    default:
        obj = ::operator new(0x440);
        if (obj != 0) {
            obj = load_resource_from_descriptor(obj, 5, &lazer_fence_norm_episode1_resource_descriptor, 0, 0, 0);
        }
        lazer_fence_norm_bml_resource = obj;
        lazer_fence_norm_texture_list = (s32)load_gvm_texture_file((s32)lbl_80445BCC);
        break;
    }
}
extern "C" {

__declspec(section ".data") const char *fe_obj_lazer2_4m_model_names[9] = { lbl_80445A30, lbl_80445A44, lbl_80445A60, lbl_80445A74, lbl_80445A90, lbl_80445AA4, lbl_80445AC0, lbl_80445AD4, NULL };
__declspec(section ".data") const char *fe_obj_lazer2_4m_motion_names[5] = { lbl_80445AF0, lbl_80445B08, lbl_80445B20, lbl_80445B38, NULL };
BmlResourceDescriptor lazer_fence_norm_episode1_resource_descriptor = { lbl_80445B50, fe_obj_lazer2_4m_model_names, fe_obj_lazer2_4m_motion_names, 8, 4 };
__declspec(section ".data") const char *fe_obj_lazer2_2_model_names[9] = { lbl_80445A30, lbl_80445A44, lbl_80445A60, lbl_80445A74, lbl_80445A90, lbl_80445AA4, lbl_80445AC0, lbl_80445AD4, NULL };
__declspec(section ".data") const char *fe_obj_lazer2_2_motion_names[5] = { lbl_80445AF0, lbl_80445B08, lbl_80445B20, lbl_80445B38, NULL };
}
BmlResourceDescriptor lazer_fence_norm_episode2_resource_descriptor = { lbl_80445B68, fe_obj_lazer2_2_model_names, fe_obj_lazer2_2_motion_names, 8, 4 };
