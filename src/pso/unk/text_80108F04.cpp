#include "types.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/item/TItemEffHeaven.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/unk/text_80108F04.h"
#include "pso/TItemAttacker.h"

struct Ent_80108F04 { u8 pad0[0x1C]; u8 sub[0x10]; };

struct Src_80108F04 { u8 pad0[0xA4]; Ent_80108F04 *ents; };

struct Arg_80108F04 { Src_80108F04 *src; s32 idx; };

struct Flame_80108F04 {
    s32 name;
    u8 pad4[0x18 - 0x4];
    void *vt;
    void *x1c;
    s16 x20;
    s32 idx;
};

extern "C" {
void *__nw__7TObjectFUl(u32 size);
extern void *tl_05;
s16 get_entity_id(void *);
void __ct__7TObjectFP7TObject(void *, void *);
extern void *__vt__13TItemEffFlame[];
extern s32 TItemEffFlame__class_name;

#define self ((Flame_80108F04 *)arg0)
#define arg2 ((Arg_80108F04 *)target)
void *TItemEffFlame__ct(void *arg0, void *parent, void *target) {
    __ct__7TObjectFP7TObject(arg0, parent);
    self->vt = __vt__13TItemEffFlame;
    self->name = TItemEffFlame__class_name;
    self->x20 = get_entity_id(arg2->src);
    self->idx = arg2->idx;
    {
        Src_80108F04 *src = arg2->src;
        self->x1c = ((void *(*)(void *, s32, void *))create_particle_emitter)(src->ents[self->idx].sub, 0x1BB, src);
    }
    disallow_rendering__7TObjectFv((TObject *)arg0);
    return arg0;
}
#undef self
#undef arg2

void spawn_flame_effect(void *self, void *target) {
    void *p;
    if (target != NULL) {
        p = __nw__7TObjectFUl(0x28);
        if (p != NULL) {
            p = TItemEffFlame__ct(p, tl_05, target);
        }
        TItemAttacker::spawn_item_timer((s32)p, (s32)((void *)destroy__14TItemEffHeavenFPv), 0x1E);
    }
}

}
