#include "types.h"
#include "pso/item/TItemList.h"
#include "pso/item/TItemList_801D57B0.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/item/TUnk_804C4468.h"
#include "pso/item/TUnk_804C4498.h"
#include "pso/TItemList.h"

struct Arr_801D5868 { s32 n; s32 e[1]; };
struct Ent_801D598C { u8 d[0x10]; };
struct Obj_801D598C { u8 pad[0x28]; Ent_801D598C e[1]; };
struct Ent_801D5854 { u8 d[0x1C]; };

struct Obj_801D5854 { u8 pad[0xA8]; Ent_801D5854 arr[1]; };

extern "C" {
s32 TItemList__sub_801D5868(Arr_801D5868 *, s32);
Ent_801D5854 *TItemList__sub_801D5854(Obj_801D5854 *p, s32 i);
s32 TItemList__sub_801D598C(Obj_801D598C *arg0, s32 arg1);
int VecCopy__FP3VecPC3Vec(void*);
void __ct__7TObjectFP7TObject(void *);
int copy_from__8ItemDataFP8ItemData(void*);

extern s32 __vt__9TItemList[];
extern void *TItemList__name;

void *__ct__9TItemListFv(void *item_list) {
    __ct__7TObjectFP7TObject(item_list);
    *(s32 **)((s8 *)item_list + 0x18) = __vt__9TItemList;
    *(void * *)&((TItemList *)item_list)->m_name = TItemList__name;
    *(u32 *)((s8 *)item_list + 0x1C) = 0;
    disallow_rendering__7TObjectFv((TObject *)item_list);
    return item_list;
}

void TItemList__sub_801D5804(s32 *arg0) {
    *arg0 += 1;
}

int TItemList::copy_item_data() { return copy_from__8ItemDataFP8ItemData((char*)this + 0x8); }
void TItemList__sub_801D5838(void* p) { *(s32*)((char*)p + 0x0) = 1; }
int TItemList__sub_801D5844(void* p) { return *(u32*)((char*)p + 0x0) == 0; }

Ent_801D5854 *TItemList__sub_801D5854(Obj_801D5854 *p, s32 i) {
    return &p->arr[i];
}

s32 TItemList__sub_801D5868(Arr_801D5868 *arg0, s32 arg1) {
    return (s32)&arg0->e[arg1];
}

void* get_ptr_0x44__9TItemListFPv(void* p) { return (char*)p + 0x44; }
void TUnk_804C4498::sub_801D5884(u8 v) { this->m_1d = v; }

void TItemList::lookup_entry_by_count(s32 arg1) {
    TItemList__sub_801D58C8((void*)(((u8 *)TItemList__sub_801D5868((Arr_801D5868 *)(arg1), (s8)(get_item_count())))));
}

void TItemList__sub_801D58C8(void* p) { *(s32*)((char*)p + 0x0) = 3; }
u8 TItemList::get_item_count() { return *(u8*)((char*)this + 0x1c); }
u16 TUnk_804C4468::sub_801D58DC() { return this->m_20; }

void TItemList::run_item_count_update() {
    u8 *arg0 = (u8 *)this;
    ((s32)((int)TItemList__sub_801D5854((Obj_801D5854 *)((int)((int) (*(s32 *)((s8 *)arg0 + 0x54)))), (s32)((int)((int) (((s8)get_item_count())))))));
}

void TUnk_804C4468::sub_801D591C() {
    ((void (*)(s32, s32))copy_position__9TItemListFPv)(TItemList__sub_801D598C((Obj_801D598C *)*(s32 *)(((u8 *)this) + 0x54), (s8)((TItemList *)((u8 *)this))->get_item_count()), ((s32 (*)(void))get_ptr_0x44__9TItemListFPv)());
}

int copy_position__9TItemListFPv(void* p) { return VecCopy__FP3VecPC3Vec((char*)p + 0x4); }

s32 TItemList__sub_801D598C(Obj_801D598C *arg0, s32 arg1) {
    return (s32)&arg0->e[arg1];
}
void TItemList__sub_801D59A0(TItemList *item_list, s32 arg1) {
    TItemList__sub_801D59DC((void*)(((u8 *)TItemList__sub_801D5868((Arr_801D5868 *)arg1, (s8)item_list->get_item_count()))));
}

}
