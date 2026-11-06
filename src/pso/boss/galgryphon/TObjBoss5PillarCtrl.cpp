#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5PillarCtrl.h"
#include "pso/system/task/TObject_80019A50.h"

#include "pso/boss/galgryphon/TObjBoss5Pillar.h"

#pragma readonly_strings on

extern "C" {
const char *lbl_805D3B38 = "TObjBoss5PillarCtrl";
}


struct Pc_8028B198 { u8 pad0[0x18]; void *vt; s32 count; void **a; };

struct Node_8028B23C { u8 pad[0x8]; u8 data[0x28]; Node_8028B23C *next; };

struct List_8028B23C { u8 pad[0x2C]; Node_8028B23C *head; };

struct Owner_8028B23C { u8 pad[0x28]; List_8028B23C *list; };

struct Game_8028B23C { u8 pad[0x42C]; Owner_8028B23C *owner; };

struct Ctrl_8028B23C {
    s32 f0;
    u8 pad[0x14];
    void *vt;
    s32 count;
    void **pillars;
};

extern "C" {
void *__nw__7TObjectFUl(int);
void mem_free(void *);
extern u8 __vt__19TObjBoss5PillarCtrl[];
void *mem_alloc(u32 size);
void __ct__7TObjectFP7TObject(void *, void *);
extern const char *lbl_805D3B38;
extern Game_8028B23C *lbl_805D4DD8;
Ctrl_8028B23C *TObjBoss5PillarCtrl__ct(Ctrl_8028B23C *arg0, void *arg1);
s32 play_sound_effect(s32, s32, s32, s32);
int TObjBoss5Pillar__sub_8028B70C(void*);
int TObjBoss5Pillar__sub_8028B710(void*);

void TObjBoss5PillarCtrl::render() {  }
void TObjBoss5PillarCtrl::run_task() {  }

}
TObjBoss5PillarCtrl::~TObjBoss5PillarCtrl() {
    s32 i;
    for (i = ((Pc_8028B198 *)this)->count - 1; i >= 0; i--) {
        if (((Pc_8028B198 *)this)->a[i] != NULL) {
            queue_destruction__7TObjectFv(((Pc_8028B198 *)this)->a[i]);
            ((Pc_8028B198 *)this)->a[i] = NULL;
        }
    }
    mem_free(((Pc_8028B198 *)this)->a);
}


Ctrl_8028B23C *TObjBoss5PillarCtrl__ct(Ctrl_8028B23C *arg0, void *arg1) {
    Node_8028B23C *n;
    s32 i;
    List_8028B23C *lst;
    __ct__7TObjectFP7TObject(arg0, arg1);
    arg0->vt = __vt__19TObjBoss5PillarCtrl;
    arg0->f0 = ((s32)lbl_805D3B38);
    arg0->count = 0;
    arg0->pillars = NULL;
    for (n = lbl_805D4DD8->owner->list->head; n != NULL; n = n->next) {
        arg0->count++;
    }
    if (arg0->count <= 0) {
        queue_destruction__7TObjectFv(arg0);
        return arg0;
    }
    lst = lbl_805D4DD8->owner->list;
    arg0->pillars = (void **)mem_alloc(arg0->count * 4);
    for (i = 0, n = lst->head; i < arg0->count; i++) {
        arg0->pillars[i] = TObjBoss5Pillar::create(n->data);
        n = n->next;
    }
    return arg0;
}

void *TObjBoss5PillarCtrl::create() {
    void *o;
    o = __nw__7TObjectFUl(0x24);
    if (o != NULL) {
        o = TObjBoss5PillarCtrl__ct((Ctrl_8028B23C *)(o), this);
    }
    return o;
}

int TObjBoss5PillarCtrl::update_pillar() { return TObjBoss5Pillar__sub_8028B70C(this); }
int TObjBoss5PillarCtrl::forward_pillar_2B710() { return TObjBoss5Pillar__sub_8028B710(this); }
void TObjBoss5PillarCtrl::play_sound_once() {
    if ((s32) this->m_1c == 0) {
        play_sound_effect(0x4003A819, 0, 0, 0);
        this->m_1c = 1;
    }
}

