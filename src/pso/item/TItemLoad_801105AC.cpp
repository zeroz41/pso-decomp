#include "types.h"
#include "pso/item/TItemLoad_8010F52C.h"
#include "pso/item/TItemLoad_801105AC.h"
#include "pso/item/TUnk_8049F42C.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/TItemLoad.h"

extern char lbl_8043E3A8[];
extern char lbl_8043E3B8[];
extern char lbl_8043E3C8[];
extern char lbl_8043E3D8[];
extern char lbl_8043E3E8[];
extern char lbl_8043E3F8[];
extern char lbl_8043E408[];
extern char lbl_8043E418[];
extern char lbl_8043E428[];
extern char lbl_8043E43C[];
extern char lbl_8043E450[];
extern char lbl_8043E464[];
extern char lbl_8043E47C[];
extern char lbl_8043E490[];
extern char lbl_8043E4A4[];
extern char lbl_8043E4B4[];
extern const char *item_model_names[15];
extern const char *item_motion_names[2];
extern BmlResourceDescriptor item_bml_resource_descriptor;

struct Base_801105AC { char pad[0x18]; };
struct VObj_801105AC : Base_801105AC {
    virtual void m0(s32);
};

extern "C" {
void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void *mem_alloc(u32 size);
void * __nw__7TObjectFUl(s32);
void *__ct__7TObjectFP7TObject(void *, void *);
extern s32 TItemLoad__bml_resource;
extern void *TItemLoad__model_load_task_root;
extern void *TItemLoad__completed_model_load_task_root;
extern s32 TItemLoad__model_slot_in_use;
extern s32 item_load_resource_handle;
s32 TLobby__sub_8001FE7C(s32, s32);
s32 __ct__9TItemLoadFv(void *, s32);
void mem_free(void *p);

void TItemLoad::free_all() {
    mem_free((void *)TItemLoad__model_slot_in_use);
    if ((void *) TItemLoad__model_load_task_root != NULL) {
        ((VObj_801105AC *)TItemLoad__model_load_task_root)->m0(1);
    }
    if ((void *) TItemLoad__completed_model_load_task_root != NULL) {
        ((VObj_801105AC *)TItemLoad__completed_model_load_task_root)->m0(1);
    }
    TLobby__sub_8001FE7C(TItemLoad__bml_resource, 1);
    item_load_resource_handle = 0;
    TItemLoad__bml_resource = 0;
    TItemLoad__model_load_task_root = NULL;
    TItemLoad__completed_model_load_task_root = NULL;
    TItemLoad__model_slot_in_use = 0;
    TItemLoad::free_all_models();
    TItemLoad::free_boss4_rock();
}

extern s32 tl_05;

void TItemLoad::init_resources() {
    void *p;
    u32 buf;
    s32 i;
    TItemLoad::alloc_work_buffer();
    TItemLoad__sub_8010F5A0();
    p = ::operator new(0x440);
    if (p != NULL) {
        p = load_resource_from_descriptor(p, 5, &item_bml_resource_descriptor, 0, 0, 0);
    }
    TItemLoad__bml_resource = (s32)p;
    p = __nw__7TObjectFUl(0x1C);
    if (p != NULL) {
        p = __ct__7TObjectFP7TObject(p, NULL);
    }
    TItemLoad__completed_model_load_task_root = p;
    p = __nw__7TObjectFUl(0x1C);
    if (p != NULL) {
        p = __ct__7TObjectFP7TObject(p, NULL);
    }
    TItemLoad__model_load_task_root = p;
    buf = (u32)mem_alloc(0x30);
    TItemLoad__model_slot_in_use = buf;
    item_load_resource_handle = 0;
    if (buf != 0) {
        for (i = 0; i < 12; i++) {
            ((s32 *)TItemLoad__model_slot_in_use)[i] = 0;
        }
    }
}

void TItemLoad::create() {
    void *obj = __nw__7TObjectFUl(0x1C);
    if (obj != 0) {
        __ct__9TItemLoadFv(obj, tl_05);
    }
}

s32 TItemLoad__sub_80110740(void* p) { return *(s32*)((char*)p + 0x3c); }
s32 TItemLoad__sub_80110748(void* p) { return *(s32*)((char*)p + 0x28); }

__declspec(section ".data") const char *item_model_names[15] = { lbl_8043E3A8, lbl_8043E3B8, lbl_8043E3C8, lbl_8043E3D8, lbl_8043E3E8, lbl_8043E3F8, lbl_8043E408, lbl_8043E418, lbl_8043E428, lbl_8043E43C, lbl_8043E450, lbl_8043E464, lbl_8043E47C, lbl_8043E490, NULL };
__declspec(section ".data") const char *item_motion_names[2] = { lbl_8043E4A4, NULL };
BmlResourceDescriptor item_bml_resource_descriptor = { lbl_8043E4B4, item_model_names, item_motion_names, 14, 1 };
}
