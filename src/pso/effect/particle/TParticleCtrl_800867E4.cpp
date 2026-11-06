#include "types.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"

#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
struct Stack_8008683C {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_8008683C_lbl_804393F0 {
    s32 value;
    u8 remaining[0x8];
};

struct Ent_800868C4 { u8 data[0x98]; };

extern "C" {
s32 get_bml_model(void *, s32);
extern u8 *TParticleCtrl__regular_bml_resource;
extern RecoveredGlobal_8008683C_lbl_804393F0 lbl_804393F0;
extern s32 particle_pool_limit;
extern Ent_800868C4 *particle_global_entry_table;
extern Ent_800868C4 *particle_area_entry_table;
void *__nw__7TObjectFUl(int);
void *initialize_with_flags__13TParticleCtrlFPCvlllllUs(void *, void *, void *, s32, s32, s32, s32, s32);
void *__ct__13TParticleCtrlFv(void *self, void *pos, void *dir, void *ent, int a, int b, int c, int d, int e);
void *__ct__5THeapFUli(void *, void *, int);
void *__nw__5THeapFUl(int);

extern void *TParticleCtrl__heap;

void TParticleCtrl::init_heap(void *arg0) {
    void *o;
    if (TParticleCtrl__heap == NULL) {
        o = __nw__5THeapFUl(0x14);
        if (o != NULL) {
            o = __ct__5THeapFUli(o, arg0, 16);
        }
        TParticleCtrl__heap = o;
    }
}

    extern int TParticleCtrl__texture_list;

typedef char RecoveredGlobal_8008683C_lbl_804393F0_size[sizeof(RecoveredGlobal_8008683C_lbl_804393F0) == 0xC ? 1 : -1];
void TParticleCtrl::generate_child_default(s32 arg1, s32 arg2) {
    s32 arg0 = (s32)this;
    typedef char sp8_offset[(offsetof(Stack_8008683C, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8008683C, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8008683C, sp10) == 0x8) ? 1 : -1];
    Stack_8008683C stack;
    stack.sp8 = *(s32 *)((s8 *)&lbl_804393F0.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_804393F0.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_804393F0.value + 8);
    ((TParticleCtrl *)arg0)->alloc_child_particle((void *)arg1, (void *)&stack.sp8, (void *)arg2);
}

s32 TParticleCtrl::get_particle_model(s32 arg0) {
    if (arg0 < 3) {
        return get_bml_model(TParticleCtrl__regular_bml_resource, arg0);
    }
    return 0;
}

int TParticleCtrl::get_instance() {  return TParticleCtrl__texture_list; }
}
#pragma push
#pragma opt_propagation off
void *create_timed_particle_emitter_with_flags(void *pos, s32 id, s32 a, s32 b, s32 c) {
    void *p;
    s32 idx = id;
    if (particle_pool_limit > idx) {
        p = __nw__7TObjectFUl(0x78);
        if (p != 0) {
            p = initialize_with_flags__13TParticleCtrlFPCvlllllUs(p, pos, &particle_global_entry_table[idx], 0, a, b, 0, c);
        }
        return p;
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        p = __nw__7TObjectFUl(0x78);
        if (p != 0) {
            p = initialize_with_flags__13TParticleCtrlFPCvlllllUs(p, pos, &particle_area_entry_table[idx], 0, a, b, 0, c);
        }
        return p;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off

void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c) {
    void *p;
    s32 idx = id;
    if (particle_pool_limit > idx) {
        p = __nw__7TObjectFUl(0x78);
        if (p != 0) {
            p = ((TParticleCtrl *)p)->initialize((const void *)owner, (s32)&particle_global_entry_table[idx], 0, (s32)b, (s32)c, 0);
        }
        return p;
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        p = __nw__7TObjectFUl(0x78);
        if (p != 0) {
            p = ((TParticleCtrl *)p)->initialize((const void *)owner, (s32)&particle_area_entry_table[idx], 0, (s32)b, (s32)c, 0);
        }
        return p;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
void *create_timed_particle_emitter_with_angles(void *pos, void *dir, s32 id, s32 a, s32 b, s32 flags) {
    void *p;
    s32 idx = id;
    if (particle_pool_limit > idx) {
        p = __nw__7TObjectFUl(0x78);
        if (p != 0) {
            p = __ct__13TParticleCtrlFv(p, pos, dir, &particle_global_entry_table[idx], 0, a, b, 0, flags);
        }
        return p;
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        p = __nw__7TObjectFUl(0x78);
        if (p != 0) {
            p = __ct__13TParticleCtrlFv(p, pos, dir, &particle_area_entry_table[idx], 0, a, b, 0, flags);
        }
        return p;
    }
    return 0;
}
#pragma pop
