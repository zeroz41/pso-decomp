#include "types.h"
#include "pso/item/drop/TItemDrop_800F93F0.h"
#include "pso/item/TUnk_8049C658.h"
#include "pso/item/drop/TItemDrop.h"
#include "pso/unk/TLobby.h"
#include "pso/item/TUnk_8049C658.h"

struct B_800F957C { u8 pad[0x18]; };

struct N_800F957C : B_800F957C {
    virtual void m0(s32);
    void *p1C;
    u8 pad20[4];
    u32 id24;
};

struct Head_800F957C { u8 pad[0x14]; N_800F957C *first; };

extern "C" {
extern Head_800F957C resource_load_task_root[];
int safe_free__23TAdSinglePlyChrSelectGCFUl(void*);
s32 apply_rel_relocations(void *);
s32 read_disc_file(void *, void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void *set_stream_and_load_file__6TLobbyFi(const char *path);

extern s32 lbl_8049C658[];

void *TUnk_8049C658::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_8049C658;
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}

#pragma push
#pragma inline_depth(1)
#pragma dont_inline off

struct Drop_800F9448 {
    u8 pad_0[0x1C];
    s32 a;
    s32 b;
    u8 pad_24[0x14];
    Drop_800F9448() { ((TUnk_8049C658 *)this)->construct(); }
};

static inline s32 finish_800F9448(Drop_800F9448 *d, s32 r) {
    ((TUnk_8049C658 *)d)->destroy(-1);
    return r;
}

s32 TItemDrop__sub_800F9448(s32 arg0, s32 arg1) {
    Drop_800F9448 d;

    if (arg1 > 0) {
        d.a = arg0;
        d.b = arg1;
        return finish_800F9448(&d, apply_rel_relocations(&d));
    }
    return finish_800F9448(&d, 0);
}

s32 load_relocatable_file(s32 arg0, s32 arg1) {
    Drop_800F9448 d;
    s32 n;

    n = read_disc_file((void *) arg0, (void *) arg1);
    if (n > 0) {
        d.b = n;
        d.a = arg1;
        return finish_800F9448(&d, apply_rel_relocations(&d));
    }
    return finish_800F9448(&d, 0);
}

#pragma pop
int free_data_file(void* p) { return safe_free__23TAdSinglePlyChrSelectGCFUl(p); }
void *load_data_file(const char *path) { return set_stream_and_load_file__6TLobbyFi(path); }
void TLobby::free_nodes_with_id(u32 arg0) {
    N_800F957C *n = resource_load_task_root->first;
    while (n != 0) {
        if (n->id24 == arg0) {
            safe_free__23TAdSinglePlyChrSelectGCFUl(n->p1C);
            if (n != 0) {
                n->m0(1);
            }
        }
        n = *(N_800F957C **)((u8 *)n + 0xC);
    }
}
