#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TTecZonde.h"
#include "pso/misc/TTecGiZonde.h"
#include "pso/player/TObjPlayer.h"

typedef struct GTarget_80232598 {
    u16 id;
    u16 pad2;
    u32 pad4;
} GTarget_80232598;

typedef struct GChain_80232598 {
    u8 pad0[0x130];
    s32 count;
    GTarget_80232598 targets[1];
} GChain_80232598;

struct Vec_80231C58 { f32 x, y, z; };

struct Part_80231C58 { u8 pad0[0x1C]; Vec_80231C58 pos; u8 pad28[0x2C - 0x28]; };

struct EntBase_80231C58 { u8 pad[0x18]; };

struct Ent_80231C58 : EntBase_80231C58 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30();
    virtual s32 m31();
    u8 pad1C[0x30 - 0x1C];
    u32 flags;
    u8 pad34[0xA4 - 0x34];
    Part_80231C58 *parts;
};

struct Target_80231C58 { u16 id; s16 part; u32 pad4; };

struct Chain_80231C58 {
    u8 pad0[0x20];
    Vec_80231C58 pos;
    u8 pad2C[0xC6 - 0x2C];
    s16 level;
    u8 padC8[0x130 - 0xC8];
    s32 count;
    Target_80231C58 targets[1];
};

extern "C" {
void *find_entity_by_id(u16 id);
s32 is_parents_unqueued__9TTecLukerFUl();
s16 get_entity_id(void *);
s32 update_technique_slot__10TTecRaFoieFl(s32, s32, s32);
s32 play_sound_effect(s32, void *, s32, s32);
s32 copy_technique_target_list(void *, void *);
s32 construct_facing_technique__10TObjPlayerFPviPvii(void *, void *, void *, s32);
extern s32 __vt__11TTecGiZonde[];
extern s32 TTecGiZonde_name_ref;
u8 *TTecGiZonde__ct(u8 *arg0, void *arg1, void *arg2, void *arg3, void * _w4);
f32 vector_length(Vec_80231C58 *);
void normalize_vector(Vec_80231C58 *);
void *__nw__7TObjectFUl(int);
u8 *construct_helper_effect__11TTecGiZondeFPvPvPvPvi(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4);
extern s32 tl_07;
extern const f32 lbl_805DC828;
extern const f32 lbl_805DC82C;
extern const f32 lbl_805DC830;
extern const f32 lbl_805DC834;
extern const f32 lbl_805DC838;
void *__dt__11TTecGiZondeFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);

#define UNQ(e) ((s32 (*)(u32)) is_parents_unqueued__9TTecLukerFUl)(e)
s32 TTecGiZonde::find_chain_targets() {
    Chain_80231C58 *self = (Chain_80231C58 *)this;
    Vec_80231C58 d;
    Vec_80231C58 d2;
    f32 scale = lbl_805DC828;
    f32 len;
    f32 len2;
    Ent_80231C58 *e;
    s32 i;
    Ent_80231C58 *a;
    Ent_80231C58 *b;
    void *p;
    e = (Ent_80231C58 *) find_entity_by_id(self->targets[0].id);
    if (UNQ((u32) e) == 0) {
        return 0;
    }
    d.x = e->parts[self->targets[0].part].pos.x - self->pos.x;
    d.y = e->parts[self->targets[0].part].pos.y - self->pos.y;
    d.z = e->parts[self->targets[0].part].pos.z - self->pos.z;
    len = vector_length(&d);
    if (lbl_805DC82C != len) {
        normalize_vector(&d);
    }
    switch (self->level) {
    case 0:
        p = __nw__7TObjectFUl(0x260);
        if (p != NULL) {
            ((TTecZonde *)p)->construct_bolt_effect((u8 *)tl_07, (u8 *)&self->pos, (u8 *)&d, 0x14000000, 20, (f32)len, (f32)lbl_805DC828);
        }
        p = __nw__7TObjectFUl(0x40);
        if (p != NULL) {
            construct_helper_effect__11TTecGiZondeFPvPvPvPvi((u8 *)p, (u8 *)(&e->parts[self->targets[0].part].pos), (u8 *)&self->pos, (u8 *)tl_07, 0x19F);
        }
        break;
    case 1:
        scale *= lbl_805DC830;
        p = __nw__7TObjectFUl(0x260);
        if (p != NULL) {
            ((TTecZonde *)p)->construct_bolt_effect((u8 *)tl_07, (u8 *)&self->pos, (u8 *)&d, 0x14000000, 20, (f32)len, (f32)scale);
        }
        p = __nw__7TObjectFUl(0x40);
        if (p != NULL) {
            construct_helper_effect__11TTecGiZondeFPvPvPvPvi((u8 *)p, (u8 *)(&e->parts[self->targets[0].part].pos), (u8 *)&self->pos, (u8 *)tl_07, 0x19F);
        }
        break;
    case 2:
        scale *= lbl_805DC834;
        p = __nw__7TObjectFUl(0x260);
        if (p != NULL) {
            ((TTecZonde *)p)->construct_bolt_effect((u8 *)tl_07, (u8 *)&self->pos, (u8 *)&d, 0x14000000, 20, (f32)len, (f32)scale);
        }
        p = __nw__7TObjectFUl(0x40);
        if (p != NULL) {
            construct_helper_effect__11TTecGiZondeFPvPvPvPvi((u8 *)p, (u8 *)(&e->parts[self->targets[0].part].pos), (u8 *)&self->pos, (u8 *)tl_07, 0x19F);
        }
        break;
    case 3:
        scale *= lbl_805DC830;
        p = __nw__7TObjectFUl(0x260);
        if (p != NULL) {
            ((TTecZonde *)p)->construct_bolt_effect((u8 *)tl_07, (u8 *)&self->pos, (u8 *)&d, 0x14000000, 20, (f32)len, (f32)scale);
        }
        p = __nw__7TObjectFUl(0x40);
        if (p != NULL) {
            construct_helper_effect__11TTecGiZondeFPvPvPvPvi((u8 *)p, (u8 *)(&e->parts[self->targets[0].part].pos), (u8 *)&self->pos, (u8 *)tl_07, 0x19F);
        }
        p = __nw__7TObjectFUl(0x40);
        if (p != NULL) {
            construct_helper_effect__11TTecGiZondeFPvPvPvPvi((u8 *)p, (u8 *)(&e->parts[self->targets[0].part].pos), (u8 *)&self->pos, (u8 *)tl_07, 0x188);
        }
        break;
    case 4:
        scale *= lbl_805DC834;
        p = __nw__7TObjectFUl(0x260);
        if (p != NULL) {
            ((TTecZonde *)p)->construct_bolt_effect((u8 *)tl_07, (u8 *)&self->pos, (u8 *)&d, 0x14000000, 20, (f32)len, (f32)scale);
        }
        p = __nw__7TObjectFUl(0x40);
        if (p != NULL) {
            construct_helper_effect__11TTecGiZondeFPvPvPvPvi((u8 *)p, (u8 *)(&e->parts[self->targets[0].part].pos), (u8 *)&self->pos, (u8 *)tl_07, 0x19F);
        }
        p = __nw__7TObjectFUl(0x40);
        if (p != NULL) {
            construct_helper_effect__11TTecGiZondeFPvPvPvPvi((u8 *)p, (u8 *)(&e->parts[self->targets[0].part].pos), (u8 *)&self->pos, (u8 *)tl_07, 0x188);
        }
        break;
    case 5:
        p = __nw__7TObjectFUl(0x260);
        if (p != NULL) {
            ((TTecZonde *)p)->construct_bolt_effect((u8 *)tl_07, (u8 *)&self->pos, (u8 *)&d, 0x14000000, 20, (f32)len, (f32)lbl_805DC838);
        }
        p = __nw__7TObjectFUl(0x260);
        if (p != NULL) {
            ((TTecZonde *)p)->construct_bolt_effect((u8 *)tl_07, (u8 *)&self->pos, (u8 *)&d, 0x14000000, 20, (f32)len, (f32)lbl_805DC828);
        }
        p = __nw__7TObjectFUl(0x260);
        if (p != NULL) {
            ((TTecZonde *)p)->construct_bolt_effect((u8 *)tl_07, (u8 *)&self->pos, (u8 *)&d, 0x14000000, 20, (f32)len, (f32)lbl_805DC828);
        }
        p = __nw__7TObjectFUl(0x40);
        if (p != NULL) {
            construct_helper_effect__11TTecGiZondeFPvPvPvPvi((u8 *)p, (u8 *)(&e->parts[self->targets[0].part].pos), (u8 *)&self->pos, (u8 *)tl_07, 0x19F);
        }
        p = __nw__7TObjectFUl(0x40);
        if (p != NULL) {
            construct_helper_effect__11TTecGiZondeFPvPvPvPvi((u8 *)p, (u8 *)(&e->parts[self->targets[0].part].pos), (u8 *)&self->pos, (u8 *)tl_07, 0x188);
        }
        break;
    }
    if (self->count == 1) {
        return 1;
    }
    for (i = 0; i < self->count - 1; i++) {
        a = (Ent_80231C58 *) find_entity_by_id(self->targets[i].id);
        b = (Ent_80231C58 *) find_entity_by_id(self->targets[i + 1].id);
        if (UNQ((u32) a) != 0 && UNQ((u32) b) != 0) {
        if ((a->flags & 0x20000000) && (b->flags & 0x20000000) &&
            TObjPlayer::is_valid_and_active((u32) a) != 0 && TObjPlayer::is_valid_and_active((u32) b) != 0 &&
            a->m31() != 0 && b->m31() != 0) {
            return 0;
        }
        d2.x = b->parts[self->targets[i].part].pos.x - a->parts[self->targets[i + 1].part].pos.x;
        d2.y = b->parts[self->targets[i].part].pos.y - a->parts[self->targets[i + 1].part].pos.y;
        d2.z = b->parts[self->targets[i].part].pos.z - a->parts[self->targets[i + 1].part].pos.z;
        len2 = vector_length(&d2);
        if (lbl_805DC82C != len2) {
            normalize_vector(&d2);
        }
        scale = lbl_805DC828;
        switch (self->level) {
        case 0:
            p = __nw__7TObjectFUl(0x260);
            if (p != NULL) {
                ((TTecZonde *)p)->construct_bolt_effect((u8 *)tl_07, (u8 *)(&a->parts[self->targets[i].part].pos), (u8 *)&d2, 0x14000000, 20, (f32)len2, (f32)lbl_805DC828);
            }
            break;
        case 1:
            scale *= lbl_805DC830;
            p = __nw__7TObjectFUl(0x260);
            if (p != NULL) {
                ((TTecZonde *)p)->construct_bolt_effect((u8 *)tl_07, (u8 *)(&a->parts[self->targets[i].part].pos), (u8 *)&d2, 0x14000000, 20, (f32)len2, (f32)scale);
            }
            break;
        case 2:
            scale *= lbl_805DC834;
            p = __nw__7TObjectFUl(0x260);
            if (p != NULL) {
                ((TTecZonde *)p)->construct_bolt_effect((u8 *)tl_07, (u8 *)(&a->parts[self->targets[i].part].pos), (u8 *)&d2, 0x14000000, 20, (f32)len2, (f32)scale);
            }
            break;
        case 3:
            scale *= lbl_805DC830;
            p = __nw__7TObjectFUl(0x260);
            if (p != NULL) {
                ((TTecZonde *)p)->construct_bolt_effect((u8 *)tl_07, (u8 *)(&a->parts[self->targets[i].part].pos), (u8 *)&d2, 0x14000000, 20, (f32)len2, (f32)scale);
            }
            break;
        case 4:
            scale *= lbl_805DC834;
            p = __nw__7TObjectFUl(0x260);
            if (p != NULL) {
                ((TTecZonde *)p)->construct_bolt_effect((u8 *)tl_07, (u8 *)(&a->parts[self->targets[i].part].pos), (u8 *)&d2, 0x14000000, 20, (f32)len2, (f32)scale);
            }
            break;
        case 5:
            p = __nw__7TObjectFUl(0x260);
            if (p != NULL) {
                ((TTecZonde *)p)->construct_bolt_effect((u8 *)tl_07, (u8 *)(&a->parts[self->targets[i].part].pos), (u8 *)&d2, 0x14000000, 20, (f32)len2, (f32)lbl_805DC838);
            }
            p = __nw__7TObjectFUl(0x260);
            if (p != NULL) {
                ((TTecZonde *)p)->construct_bolt_effect((u8 *)tl_07, (u8 *)(&a->parts[self->targets[i].part].pos), (u8 *)&d2, 0x14000000, 20, (f32)len2, (f32)lbl_805DC828);
            }
            p = __nw__7TObjectFUl(0x260);
            if (p != NULL) {
                ((TTecZonde *)p)->construct_bolt_effect((u8 *)tl_07, (u8 *)(&a->parts[self->targets[i].part].pos), (u8 *)&d2, 0x14000000, 20, (f32)len2, (f32)lbl_805DC828);
            }
            break;
        }
        } else {
            return 0;
        }
    }
    return 1;
}

void TTecGiZonde::create(void *arg1, void *arg2, void *arg3) {
    void *o;
    o = __nw__7TObjectFUl(0x18C);
    if (o != NULL) {
        TTecGiZonde__ct((u8 *)o, (void *)this, (void *)arg1, (void *)arg2, (void *)arg3);
    }
}

void *__dt__11TTecGiZondeFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TTecGiZonde;
        ((TObjPlayer *)arg0)->destroy_technique_effect_resources(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TTecGiZonde::deliver_chain_hits() {
    s32 i;
    u32 actor;
    for (i = 0; i < ((GChain_80232598 *)this)->count; i++) {
        actor = (u32)find_entity_by_id(((GChain_80232598 *)this)->targets[i].id);
        if (is_parents_unqueued__9TTecLukerFUl() != 0 && TObjPlayer::is_valid_and_active(actor) != 0) {
            this->vfunc_8((void *)actor);
        }
    }
}

void TTecGiZonde::run_task() {
    this->source = (u32)find_entity_by_id(this->sourceId);
    if ((u32) this->source == 0U) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    if ((s32) *(s32 *)((s8 *)this + 0x130) == 0) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    if (find_chain_targets() == 1) {
        deliver_chain_hits();
    }
    queue_destruction__7TObjectFv(this);
}
u8 *TTecGiZonde__ct(u8 *arg0, void *arg1, void *arg2, void *arg3, void * _w4) {
    s32 h;
    construct_facing_technique__10TObjPlayerFPviPvii(arg0, arg1, arg2, 0);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TTecGiZonde;
    ((TObjPlayer *)(arg0 + 0x130))->construct_target_cursor_records();
    *(s32 *)((s8 *)arg0 + 0) = TTecGiZonde_name_ref;
    ((TTecGiZonde *)arg0)->init_parameters();
    copy_technique_target_list(arg0 + 0x130, arg3);
    switch (((TTecGiZonde *)arg0)->band) {
    case 0:
        if ((h = play_sound_effect(0x4002A509, arg0 + 0x20, 0, 0)) >= 0) {
            update_technique_slot__10TTecRaFoieFl(h, 0x100, 0);
        }
        break;
    case 1:
        play_sound_effect(0x4002A509, arg0 + 0x20, 0, 0);
        break;
    case 2:
    case 3:
        if ((h = play_sound_effect(0x4002A509, arg0 + 0x20, 0, 0)) >= 0) {
            update_technique_slot__10TTecRaFoieFl(h, -0x180, 0);
        }
        break;
    case 4:
        if ((h = play_sound_effect(0x4002A509, arg0 + 0x20, 0, 0)) >= 0) {
            update_technique_slot__10TTecRaFoieFl(h, -0x250, 0);
        }
        break;
    case 5:
        if ((h = play_sound_effect(0x4002A509, arg0 + 0x20, 0, 0)) >= 0) {
            update_technique_slot__10TTecRaFoieFl(h, -0x100, 0);
        }
        break;
    }
    if (((TTecGiZonde *)arg0)->source != 0U) {
        ((TTecGiZonde *)arg0)->sourceId = get_entity_id((void *)((TTecGiZonde *)arg0)->source);
    }
    return arg0;
}

}
