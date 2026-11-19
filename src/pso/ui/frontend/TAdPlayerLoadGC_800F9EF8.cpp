#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_800F9EF8.h"
#include "pso/item/TUnk_8049C658.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/item/drop/TItemDrop.h"

extern "C" {
void __register_global_object(void *obj, void *dtor, void *link);
extern u8 resource_load_task_root[];
extern u8 resource_load_task_root_dtor_registration[];
extern "C" { extern char lbl_805DA910[]; }
const char *lbl_805D2B10 = lbl_805DA910;


    extern int TAdPlayerLoadGC__load_state;
void TAdPlayerLoadGC::set_state(int a0) { TAdPlayerLoadGC__load_state = a0; }

extern s32 TLoadCtrl__fade_task;

s32 TLoadCtrl__sub_800F9F00(void) {
    return TLoadCtrl__fade_task;
}
void __sinit_TAdPlayerLoadGC_800F9EF8_cpp(void) {
    __register_global_object(((TUnk_8049C658 *)resource_load_task_root)->construct(), (void *)__dt__13TUnk_8049C658Fv, resource_load_task_root_dtor_registration);
    disc_read_filename = lbl_805D2B10;
}

}

__declspec(section ".ctors") static void *const __sinit_TAdPlayerLoadGC_800F9EF8_cpp_ref = (void *)__sinit_TAdPlayerLoadGC_800F9EF8_cpp;
