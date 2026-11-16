#include "types.h"
#include "pso/unk/TLobby_800F9A60.h"
#include "pso/system/task/TObject.h"

extern "C" {

void apply_rel_relocations(void *);
void *ct_object__13TUnk_8049C658Fv(void *, void *);
void memset(void *, int, int);
void strncpy(void *, void *, int);

extern s32 resource_load_task_root[];
struct VOff_800F9A60_o_800f9a60 { char pad_0[0x28]; char f_28[1]; };

void TLobby__sub_800F9A60(void *arg0, void *arg1, void *arg2) {
    struct VOff_800F9A60_o_800f9a60 *o;
    o = (struct VOff_800F9A60_o_800f9a60 *)TObject::operator new(0x3C);
    if (o != NULL) {
        o = (struct VOff_800F9A60_o_800f9a60 *)ct_object__13TUnk_8049C658Fv(o, resource_load_task_root);
    }
    memset(o->f_28, 0, 17);
    strncpy(o->f_28, arg0, 16);
    *(void **)((s8 *)o + 0x0) = o->f_28;
    *(void **)((s8 *)o + 0x1C) = arg1;
    *(void **)((s8 *)o + 0x20) = arg2;
    apply_rel_relocations(o);
}

}
