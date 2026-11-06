#include "types.h"
#include "pso/item/TItemLoad.h"
#include "pso/item/TItemLoad_80110010.h"
#include "pso/system/memory.h"
#include "pso/item/TUnk_8049F3F4.h"
#include "pso/item/TUnk_8049F42C.h"
#include "pso/system/task/TObject.h"

struct Base_801104C4_80110010 { char pad[0x18]; };
struct VObj_801104C4_80110010 : Base_801104C4_80110010 {
    virtual int m0();
    virtual int m1();
};

struct Node_801100F0 { u8 pad[0xC]; Node_801100F0 *next; u8 pad10[4]; Node_801100F0 *child; };

struct Node_8011038C { u8 pad[0xC]; Node_8011038C *next; u8 pad10[4]; Node_8011038C *child; };

struct Parm_8011029C { u8 pad[4]; s16 a; s16 b; };

struct Base_801103F4 { char pad[0xC]; struct Node_801103F4 *next; u8 pad10[4]; struct Node_801103F4 *child; };

struct Node_801103F4 : Base_801103F4 {
    virtual void m0(s32);
};

struct Load_8011006C { void *buf; s32 f4; s32 f8; s32 fC; s32 f10; void *f14; };

extern u32 TItemLoad__completed_model_load_task_root;
extern "C" {
void *TItemLoad__sub_801107EC(void *p);
void *lookup_item_pmt_record(u8 *item);
void *__nw__7TObjectFUl(u32);
extern s16 lbl_8043E4C0[];
extern s16 lbl_8043E4C8[];
extern void *TItemLoad__model_load_task_root;
extern s32 *TItemLoad__model_slot_in_use;
void *mem_alloc(u32);
void TLobby__sub_801E3E9C(s32, s32, void *, s32);
extern s32 lbl_8049F43C[];
Load_8011006C *init_buffer__9TItemLoadFPviii(Load_8011006C *self, s32 arg1, s32 arg2, s32 count);
s32 get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
void mem_free(void *p);

void *TUnk_8049F42C::sub_80110010(s16 arg1) {
    if (this != NULL) {
        *(s32 *)((s8 *)this + 0x14) = (s32)lbl_8049F43C;
        ((TItemLoad *)this)->free_texture();
        mem_free((void *)(*(s32 *)((s8 *)this + 0)));
        if (arg1 > 0) {
            ::operator delete(this);
        }
    }
    return this;
}

extern s32 TItemLoad__bml_resource;

Load_8011006C *init_buffer__9TItemLoadFPviii(Load_8011006C *self, s32 id, s32 arg2, s32 count) {
    s32 n = (count + 1) * 2;
    self->f14 = lbl_8049F43C;
    self->buf = mem_alloc((n + 0x116) & ~3);
    self->f8 = arg2;
    self->f4 = 0;
    self->fC = 0;
    TLobby__sub_801E3E9C(arg2, id, self->buf, 0);
    self->f10 = 1;
    return self;
}

s32 TItemLoad::has_resource_id(s32 id) {
    Node_801100F0 *n;
    if (TItemLoad__completed_model_load_task_root != 0) {
        for (n = ((Node_801100F0 *)TItemLoad__completed_model_load_task_root)->child; n != NULL; n = n->next) {
            if (id == TItemLoad__sub_801107E4(n)) {
                return 1;
            }
        }
    }
    return 0;
}

void TItemLoad::get_data_entry(s32 arg0, s32 *arg1) {
    if (arg1 != NULL) {
        *arg1 = TObjFish__sub_8001EDB0(TItemLoad__bml_resource, 0);
    }
}

void TItemLoad::lookup_item_data(s32 arg0, s32 *bml_model) {
    if (bml_model != NULL) {
        *bml_model = get_bml_model(TItemLoad__bml_resource, arg0);
    }
}

void TItemLoad::get_item_params(s32 *bml_model, s32 *arg1, s32 *bml_motion) {
    if ((bml_model != NULL) && (arg1 != NULL) && (bml_motion != NULL)) {
        *bml_model = get_bml_model(TItemLoad__bml_resource, 1);
        *arg1 = TObjFish__sub_8001EDB0(TItemLoad__bml_resource, 0);
        *bml_motion = get_bml_motion(TItemLoad__bml_resource, 0);
    }
}

void TItemLoad::get_model_ids(u8 arg0, s32 *bml_model, s32 *arg2) {
    if ((bml_model != NULL) && (arg2 != NULL)) {
        *bml_model = get_bml_model(TItemLoad__bml_resource, arg0 + 2);
        *arg2 = TObjFish__sub_8001EDB0(TItemLoad__bml_resource, 0);
    }
}
}

s32 request_item_model_load(u8 *item) {
    Parm_8011029C *parm;
    s32 a;
    s32 b;
    s32 i;
    void *obj;
    if (item != NULL) {
        parm = (Parm_8011029C *)lookup_item_pmt_record(item);
        if (parm != NULL) {
            a = parm->a;
            b = parm->b;
            if (a != -1 && b != -1) {
                a += lbl_8043E4C0[item[0]];
                b += lbl_8043E4C8[item[0]];
                if (TItemLoad__model_load_task_root != NULL && TItemLoad__model_slot_in_use != NULL) {
                    for (i = 0; i < 12; i++) {
                        if (TItemLoad__model_slot_in_use[i] == 0) {
                            TItemLoad__model_slot_in_use[i] = 1;
                            obj = __nw__7TObjectFUl(0x44);
                            if (obj != NULL) {
                                ((TUnk_8049F3F4 *)obj)->init((void *)TItemLoad__model_load_task_root, (void *)i, (void *)a, (void *)b);
                            }
                            return i;
                        }
                    }
                }
            }
        }
    }
    return -1;
}

void *TItemLoad::find_node_by_id(s32 id) {
    Node_8011038C *n;
    if (TItemLoad__completed_model_load_task_root != 0) {
        for (n = ((Node_8011038C *)TItemLoad__completed_model_load_task_root)->child; n != NULL; n = n->next) {
            if (id == TItemLoad__sub_801107E4(n)) {
                return TItemLoad__sub_801107EC(n);
            }
        }
    }
    return NULL;
}

void TItemLoad::release_resource_by_id(s32 id) {
    Node_801103F4 *roots[2] = { (Node_801103F4 *)TItemLoad__completed_model_load_task_root, (Node_801103F4 *)TItemLoad__model_load_task_root };
    s32 i;
    Node_801103F4 *n;
    for (i = 0; i != 2; i++) {
        if (roots[i] != NULL) {
            for (n = roots[i]->child; n != NULL; n = n->next) {
                if (id == TItemLoad__sub_801107E4(n)) {
                    if (n != NULL) {
                        n->m0(1);
                    }
                    TItemLoad__model_slot_in_use[id] = 0;
                    return;
                }
            }
        }
    }
}

void TItemLoad::update() {
    void *temp_r31;

    TItemLoad::update_all();
    if (((void *) TItemLoad__model_load_task_root != NULL) && ((u32) TItemLoad__completed_model_load_task_root != 0U)) {
        temp_r31 = *(void **)((s8 *)TItemLoad__model_load_task_root + 0x14);
        if (temp_r31 != NULL) {
            ((VObj_801104C4_80110010 *)temp_r31)->m1();
            if (TItemLoad__sub_801107F4(temp_r31) == 1) {
                ((TObject *)temp_r31)->set_parent((TObject *)TItemLoad__completed_model_load_task_root);
            }
        }
    }
}
