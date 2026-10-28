#include "pso/system/NinjaTypes.h"
void set_constant_material(const NJS_ARGB *color);
#include "types.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/system/memory.h"
#include "pso/system/vector.h"
#include "pso/boss/TObjBoss1MokoHill_Solo.h"
#include "pso/boss/TObjBoss1MokoHill_SoloM.h"
#include <stddef.h>
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss1Rock.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/object/TObjFish.h"

struct RecoveredGlobal_8002D41C_lbl_80482060 { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8002D41C_lbl_80482060_size[sizeof(RecoveredGlobal_8002D41C_lbl_80482060) == 0x18 ? 1 : -1];

struct UV_8002D4C0 { s16 u, v; };

struct Vtx_8002D4C0 { s16 pad; s16 u; s16 v; };

struct Hdr_8002D4C0 { u8 pad[4]; s16 count; };

struct Obj_8002D4C0 { f32 x; u8 pad[4]; f32 z; };

typedef struct Ent_8002CE78 {
    f32 *dst;
    f32 base;
    f32 ofs;
    u8 padC[4];
} Ent_8002CE78;

typedef struct Obj_8002CE78 {
    u8 pad0[0x1C];
    s32 active;
    u8 pad20[0x14];
    f32 unk34;
    s32 unk38;
} Obj_8002CE78;

struct Trail_8002CC48 {
    u8 pad0[0x28];
    u8 pos[0x34 - 0x28];
    f32 f34;
    f32 f38;
    u8 pad3C[0x40 - 0x3C];
    s32 f40;
    s32 state;
    u8 pad48[0x4C - 0x48];
    s32 f4C;
};

struct Vec_8002CFB8 { f32 x; f32 y; f32 z; };
struct Ent_8002CFB8 { u8 pad0[8]; f32 f8; s32 state; };
struct Trail_8002CFB8 {
    u8 pad0[0x10];
    void *f10;
    u8 pad14[0x1C - 0x14];
    s32 f1C;
    Vec_8002CFB8 pos;
    f32 f2C;
    f32 f30;
    f32 f34;
    u8 pad38[4];
    s32 f3C;
};

struct Vtx_8002DB7C { f32 p[3]; f32 n[3]; };

struct Model_8002DB7C {
    u32 *vertices;
    u16 *polygons;
    f32 center[3];
    f32 radius;
};

struct Object_8002DB7C {
    u32 flags;
    Model_8002DB7C *model;
    f32 position[3];
    s32 rotation[3];
    f32 scale[3];
    Object_8002DB7C *child;
    Object_8002DB7C *sibling;
};

struct Grid_8002DB7C {
    s32 width;
    s32 strips;
    s32 stripWords;
    s32 materialWords;
    u32 *vertices;
    u16 *polygons;
    Model_8002DB7C model;
    Object_8002DB7C object;
};

struct Ent_8002DF7C { u8 pad0[8]; s32 id; u8 padc[4]; };

struct Res_8002DF7C { u8 pad0[0x42C]; Ent_8002DF7C *ents; };

struct Obj_8002DF7C {
    u8 pad0[0x1C];
    u8 pos[0x18];
    s32 ry;
    s32 rx;
    f32 x3c;
    f32 color;
    u8 pad44[0x50 - 0x44];
    s32 idx;
};

typedef struct Obj_8002CD8C {
    s32 unk0;
    u8 pad4[0x14];
    void *vtbl;
    u8 pad1C[0xC];
    u8 pos[0xC];
    f32 unk34;
    f32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
} Obj_8002CD8C;

extern "C" {
s32 get_state__12TBoss8DragonFv(void);
f32 lerp__9TDeadSpotFff(f32 farg0, f32 farg1);
void __ct__7TObjectFP7TObject(void *, void *);
s32 rand(void);
extern s32 __vt__22TObjBoss1MokoHill_Solo[];
extern s32 TObjBoss1MokoHill_Solo__name;
extern const f32 lbl_805D8180;
extern const f32 lbl_805D8184;
extern const f32 lbl_805D8188;
extern const f32 lbl_805D818C;
extern const f32 lbl_805D8190;
extern const f32 lbl_805D8194;
void *TObjBoss1MokoHill_Solo__ct(void *arg0_, void *arg1, int arg2);
extern s32 __vt__23TObjBoss1MokoHill_SoloM[];
extern s32 TObjBoss1MokoHill_SoloM__name;
extern u8 *lbl_805D4B50;
extern s32 dragon_common_texture_list;
extern int lbl_805D4B60;
extern int lbl_805D4B64;
extern int lbl_805D4B68;
extern int lbl_805D4B6C;
extern Hdr_8002D4C0 *lbl_805D4B70;
extern s32 lbl_805D4B74;
extern int lbl_805D4B78;
extern s32 dragon_trail_position_source;
extern s32 dragon_trail_heading_source;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern const f32 lbl_805D8178;
extern const f32 lbl_805D817C;
extern const f32 lbl_805D8198;
extern const f32 lbl_805D81A0;
extern const f32 lbl_805D81AC;
extern const f32 lbl_805D81B4;
extern const f32 lbl_805D81D0;
extern const f32 lbl_805D81D4;
extern const f32 lbl_805D81D8;
extern const f32 lbl_805D81DC;
extern const f32 lbl_805D81E0;
extern const f32 lbl_805D81E4;
extern const f32 lbl_805D81F4;
extern const f32 lbl_805D81F8;
extern const f32 lbl_805D8200;

void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
void push_matrix(void);
s32 pop_matrix(void);
void post_translate_matrix(void *);
void set_chunk_material_override_pair(s32, s32, s32, s32);
void draw_chunk_object(void *);
void queue_destruction__7TObjectFv();
void *__nw__7TObjectFUl(int);
void mem_free(void *p);
void *mem_alloc(u32);
f32 newton_sqrtf(f32);
f32 calc_nearest_crater_distance(void *);
f32 horizontal_distance_squared(void *, void *);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32, f32);
s32 update_scale__15TObjBoss2TunnelFv(void *, f32);
void rotate_matrix_y(int, int);
void rotate_matrix_x(int, int);
u8 *TObjBoss1MokoHill_SoloM__ct(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3);
void update_dragon_trail_uvs(Obj_8002D4C0 *self);
s32 TBoss8Dragon__sub_8002DAEC(void *arg0);
s32 TBoss8Dragon__sub_8002DB04(void *arg0);
void *destroy__12TBoss8DragonFPvs(void *arg0, s16 arg1);
Grid_8002DB7C *init_grid_mesh__12TBoss8DragonFPviiiPv(Grid_8002DB7C *g, s32 width, s32 strips, s32 materialWords, s16 *material);
f32 rand_signed_unit(void);

void TObjBoss1MokoHill_Solo::run_task() {
    Trail_8002CC48 *self = (Trail_8002CC48 *)this;
    switch (self->state) {
    case 0:
        self->f34 += lbl_805D8178;
        if (self->f34 >= self->f38) {
            self->f34 = self->f38;
            self->state = 1;
        }
        VecCopy((Vec *)self->pos, (const Vec *)(((void *(*)(void *))get_state__12TBoss8DragonFv)(self)));
        break;
    case 1:
        self->f40++;
        if (self->f40 > self->f4C) {
            self->state = 2;
        }
        break;
    case 2:
        self->f34 -= lbl_805D817C;
        if (self->f34 < lbl_805D8180) {
            queue_destruction__7TObjectFv();
        }
        break;
    }
}

s32 get_state__12TBoss8DragonFv(void) {
    return dragon_trail_position_source;
}
}
s32 is_dragon_trail_damaging(u8 *arg0);
TObjBoss1MokoHill_Solo::~TObjBoss1MokoHill_Solo() {

}

#pragma fp_contract on
#define arg0 ((Obj_8002CD8C *)arg0_)

void *TObjBoss1MokoHill_Solo__ct(void *arg0_, void *arg1, int arg2) {
    f32 r;
    f32 t;
    __ct__7TObjectFP7TObject(arg0, arg1);
    arg0->vtbl = __vt__22TObjBoss1MokoHill_Solo;
    arg0->unk0 = TObjBoss1MokoHill_Solo__name;
    VecCopy((Vec *)arg0->pos, (const Vec *)(((void *(*)(void *))get_state__12TBoss8DragonFv)(arg0)));
    arg0->unk34 = lbl_805D8180;
    r = (f32)rand();
    t = lbl_805D818C * r;
    arg0->unk38 = (f32) -((lbl_805D8188 * t) + lbl_805D8184);
    arg0->unk3C = (s32)((f32 (*)(f32, f32, f32, f32, f32))lerp__9TDeadSpotFff)(lbl_805D8190, lbl_805D8194, lbl_805D8188, t, r);
    arg0->unk40 = 0;
    arg0->unk44 = 0;
    if (TObjEneDD::check_v2_mode() != 0) {
        arg0->unk48 = 1;
    } else {
        arg0->unk48 = 0;
    }
    arg0->unk4C = arg2;
    return arg0;
}
#undef arg0

void TObjBoss1MokoHill_SoloM::render() {
    Obj_8002CE78 *arg0 = (Obj_8002CE78 *)this;
    Ent_8002CE78 *p;
    s32 i;
    if (arg0->active != 0) {
        TObjFish::set_global_param(dragon_common_texture_list);
        update_dragon_trail_uvs((Obj_8002D4C0 *)((struct Obj_8002D4C0 *)dragon_trail_position_source));
        for (p = (Ent_8002CE78 *)lbl_805D4B78, i = 0; i < lbl_805D4B74; i++, p++) {
            *p->dst = p->base + p->ofs;
        }
        push_matrix();
        post_translate_matrix((void *)dragon_trail_position_source);
        translate_matrix(0, lbl_805D8198, arg0->unk34, lbl_805D8198);
        if (arg0->unk38 != 0) {
            saved_model_render_flags = model_render_flags;
            saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
            saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
            model_render_flags |= 0x800;
            set_chunk_material_override_pair(0xFF00, 0x100, chunk_polygon_flags_or_mask, chunk_polygon_flags_and_mask);
            draw_chunk_object(*(void **)(*(u8 **)(lbl_805D4B50 + 0x42C) + 0x38));
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
        } else {
            draw_chunk_object(*(void **)(*(u8 **)(lbl_805D4B50 + 0x42C) + 0x38));
        }
        pop_matrix();
        for (p = (Ent_8002CE78 *)lbl_805D4B78, i = 0; i < lbl_805D4B74; i++, p++) {
            *p->dst = p->base;
        }
    }
}

#pragma push
#pragma fp_contract on
void TObjBoss1MokoHill_SoloM::run_task() {
    Trail_8002CFB8 *self = (Trail_8002CFB8 *)this;
    Vec_8002CFB8 pos;
    Vec_8002CFB8 vel;
    f32 d;
    f32 ax;
    f32 az;
    f32 s;
    f32 c;
    s32 ang;
    void *o;
    Ent_8002CFB8 *p;
    s32 i;

    if (self->f1C != 0) {
        self->f30 += 0.5f;
        if (self->f30 > 0.0f) {
            self->f30 = 0.0f;
        }
        d = calc_nearest_crater_distance((void *)dragon_trail_position_source);
        self->f34 = self->f30;
        if (0.0f != d && d < 95.0f) {
            self->f34 = -(-0.31578946f * d - -30.0f);
            if (self->f34 > self->f30) {
                self->f34 = self->f30;
            }
        }
        if (self->f34 >= 0.0f) {
            self->f2C += newton_sqrtf(horizontal_distance_squared((void *)dragon_trail_position_source, &self->pos));
            VecCopy((Vec *)&self->pos, (const Vec *)dragon_trail_position_source);
            if (self->f2C >= 10.0f) {
                self->f2C = 0.0f;
                if (self->f3C != 0) {
                    o = __nw__7TObjectFUl(0x50);
                    if (o != NULL) {
                        TObjBoss1MokoHill_Solo__ct(o, self->f10, 0);
                    }
                } else {
                    o = __nw__7TObjectFUl(0x50);
                    if (o != NULL) {
                        TObjBoss1MokoHill_Solo__ct(o, self->f10, 0x1E);
                    }
                }
            }
            ang = *(s32 *)dragon_trail_heading_source;
            s = ((f32 (*)(s32))cos_table_lookup)(ang);
            c = sin_table_lookup(ang);
            ax = c * lbl_805D81AC + ((Vec_8002CFB8 *)dragon_trail_position_source)->x;
            az = s * lbl_805D81AC + ((Vec_8002CFB8 *)dragon_trail_position_source)->z;
            ang += (s32)(10000.0f * rand_signed_unit());
            s = ((f32 (*)(s32))cos_table_lookup)(ang);
            c = sin_table_lookup(ang);
            pos.x = c * lbl_805D81B4 + ((Vec_8002CFB8 *)dragon_trail_position_source)->x;
            pos.y = 0.0f;
            pos.z = s * lbl_805D81B4 + ((Vec_8002CFB8 *)dragon_trail_position_source)->z;
            vel.x = pos.x - ax;
            vel.z = pos.z - az;
            ((TObjBoss2Tunnel *)(&vel))->clamp_velocity();
            vel.x *= 1.5f;
            vel.z *= 1.5f;
            vel.y = lerp__9TDeadSpotFff(6.0f, 9.0f);
            o = __nw__7TObjectFUl(0x54);
            if (o != NULL) {
                ((TObjBoss1Rock *)o)->construct(self->f10, &pos, &vel, (void *)1);
            }
        }
        for (p = (Ent_8002CFB8 *)lbl_805D4B78, i = 0; i < lbl_805D4B74; p++, i++) {
            switch (p->state) {
            case 0:
                if (p->f8 < -8.0f) {
                    p->f8 = -8.0f;
                    p->state = (s32)(70.0f * (3.0517578125e-05f * (f32)rand())) + 2;
                } else {
                    p->f8 = p->f8 - 0.2f;
                }
                break;
            case 1:
                if (p->f8 > 0.0f) {
                    p->f8 = 0.0f;
                    p->state = 0;
                } else {
                    p->f8 = p->f8 + lbl_805D8184;
                }
                break;
            default:
                p->state--;
                break;
            }
        }
    }
}
#pragma pop

s32 is_dragon_trail_damaging(u8 *arg0) {
    return *(f32 *)((s8 *)arg0 + 0x34) >= lbl_805D81D0;
}

void TBoss8Dragon::set_field_3c() { set_field_1c(); *(int *)&this->unk_3C = 1; }
void TBoss8Dragon::set_field_1c() { *(s32 *)&this->unk_1C = 1; }

void TBoss8Dragon::spawn_child_object() {
    void *o;
    *(u32 *)&this->unk_1C = 0;
    *(f32 *)&this->m_34 = lbl_805D81A0;
    *(f32 *)&this->unk_30 = lbl_805D81A0;
    o = __nw__7TObjectFUl(0x50);
    if (o != NULL) {
        TObjBoss1MokoHill_Solo__ct(o, (void *)(*(void * *)&this->m_10), 30);
    }
    *(u32 *)&this->unk_3C = 0;
}
TObjBoss1MokoHill_SoloM::~TObjBoss1MokoHill_SoloM() {

}

u8 *TObjBoss1MokoHill_SoloM__ct(u8 *boss1_moko_hill_solo_m, u8 *arg1, u8 *arg2, s32 arg3) {
    __ct__7TObjectFP7TObject(boss1_moko_hill_solo_m, arg1);
    *(s32 **)((s8 *)boss1_moko_hill_solo_m + 0x18) = &(*(RecoveredGlobal_8002D41C_lbl_80482060 *)&__vt__23TObjBoss1MokoHill_SoloM).value;
    *(s32 *)((s8 *)boss1_moko_hill_solo_m + 0) = (s32) TObjBoss1MokoHill_SoloM__name;
    *(s32 *)((s8 *)boss1_moko_hill_solo_m + 0x1C) = 0;
    (*(u8 * *)&dragon_trail_position_source) = arg2;
    dragon_trail_heading_source = arg3;
    VecCopy((Vec *)(boss1_moko_hill_solo_m + 0x20), (const Vec *)arg2);
    ((TObjBoss1MokoHill_SoloM *)boss1_moko_hill_solo_m)->m_2c = (f32) lbl_805D8198;
    *(f32 *)((s8 *)boss1_moko_hill_solo_m + 0x30) = (f32) lbl_805D81A0;
    ((TObjBoss1MokoHill_SoloM *)boss1_moko_hill_solo_m)->m_34 = (f32) lbl_805D81A0;
    if (TObjEneDD::check_v2_mode() != 0) {
        *(s32 *)((s8 *)boss1_moko_hill_solo_m + 0x38) = 1;
    } else {
        *(s32 *)((s8 *)boss1_moko_hill_solo_m + 0x38) = 0;
    }
    ((TObjBoss1MokoHill_SoloM *)boss1_moko_hill_solo_m)->m_3c = 0;
    return boss1_moko_hill_solo_m;
}

void update_dragon_trail_uvs(Obj_8002D4C0 *self) {
    s32 cnt;
    s16 n;
    s16 *p = (s16 *)((u8 *)lbl_805D4B70 + 6);
    UV_8002D4C0 *src = (*(UV_8002D4C0 * *)&lbl_805D4B6C);
    s32 i = 0;
    s16 du = (s16)(lbl_805D81D8 * (lbl_805D81DC * self->x));
    s16 dv = (s16)(lbl_805D81D8 * (lbl_805D81E0 * self->z));
    cnt = lbl_805D4B70->count & 0x3FFF;
    for (; i < cnt; i++) {
        n = *p++;
        s32 j;
        if (n < 0) {
            n = -n;
        }
        for (j = 0; j < n; j++) {
            Vtx_8002D4C0 *v = (Vtx_8002D4C0 *)p;
            v->u = src->u + du;
            v->v = src->v + dv;
            src++;
            p += 3;
        }
    }
}

void TBoss8Dragon::free_resources() { mem_free((void *)lbl_805D4B78); lbl_805D4B78 = 0; mem_free((void *)lbl_805D4B6C); lbl_805D4B6C = 0; ((int (*)(void*, void*))destroy__12TBoss8DragonFPvs)((void*)lbl_805D4B64, (void*)1); lbl_805D4B64 = 0; ((int (*)(void*, void*))destroy__12TBoss8DragonFPvs)((void*)lbl_805D4B68, (void*)1); lbl_805D4B68 = 0; ((int (*)(void*, void*))destroy__12TBoss8DragonFPvs)((void*)lbl_805D4B60, (void*)1); lbl_805D4B60 = 0; }

s32 TBoss8Dragon__sub_8002DAEC(void *arg0) {
    return *(s32 *)((s8 *)arg0 + 0x14) + ((*(s32 *)((s8 *)arg0 + 0xC) + 3) * 2);
}

s32 TBoss8Dragon__sub_8002DB04(void *arg0) {
    return *(s32 *)((s8 *)arg0 + 0x10) + 8;
}

void *destroy__12TBoss8DragonFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        mem_free((void *)(*(s32 *)((s8 *)arg0 + 0x10)));
        *(s32 *)((s8 *)arg0 + 0x10) = 0;
        mem_free((void *)(*(s32 *)((s8 *)arg0 + 0x14)));
        *(s32 *)((s8 *)arg0 + 0x14) = 0;
        *(s32 *)((s8 *)arg0 + 0x18) = 0;
        *(s32 *)((s8 *)arg0 + 0x1C) = 0;
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

Grid_8002DB7C *init_grid_mesh__12TBoss8DragonFPviiiPv(Grid_8002DB7C *g, s32 width, s32 strips, s32 materialWords, s16 *material) {
    s32 i;
    s32 first;
    s32 second;
    s16 *p;
    s32 row;
    s32 x;
    s32 count;
    u32 *v;
    Vtx_8002DB7C *vt;
    g->width = width;
    g->strips = strips;
    g->materialWords = materialWords;
    g->stripWords = g->width * 6 + 1;
    g->polygons = (u16 *)mem_alloc((g->materialWords + 5 + g->stripWords * g->strips) * 2);
    g->vertices = (u32 *)mem_alloc((g->width * (g->strips + 1) * 6 + 3) * 4);
    p = (s16 *)g->polygons;
    for (i = 0; i < g->materialWords; i++) {
        *p++ = *material++;
    }
    *p++ = 0x242;
    *p++ = g->stripWords * g->strips + 1;
    *p++ = g->strips;
    first = 0;
    second = g->width;
    for (row = 0; row < g->strips; row++) {
        *p++ = g->width * 2;
        for (x = 0; x < g->width;) {
            *p++ = first++;
            x++;
            *p++ = 0;
            *p++ = 0;
            *p++ = second++;
            *p++ = 0;
            *p++ = 0;
        }
    }
    *p++ = 0xff;
    *p = 0xff;
    count = g->width * (g->strips + 1);
    v = g->vertices;
    *v++ = ((count * 6 + 1) << 16) | 0x29;
    *v++ = count << 16;
    vt = (Vtx_8002DB7C *)v;
    for (i = 0; i < count; i++) {
        vt->p[0] = lbl_805D8198;
        vt->p[1] = lbl_805D8198;
        vt->p[2] = lbl_805D8198;
        vt->n[0] = lbl_805D8198;
        vt->n[1] = lbl_805D8198;
        vt->n[2] = lbl_805D8198;
        vt++;
    }
    *(u32 *)vt = 0xff;
    g->model.vertices = g->vertices;
    g->model.polygons = g->polygons;
    g->model.center[0] = lbl_805D8198;
    g->model.center[1] = lbl_805D8198;
    g->model.center[2] = lbl_805D8198;
    g->model.radius = lbl_805D8198;
    g->object.flags = 0x17;
    g->object.model = &g->model;
    g->object.position[0] = lbl_805D8198;
    g->object.position[1] = lbl_805D8198;
    g->object.position[2] = lbl_805D8198;
    g->object.rotation[0] = 0;
    g->object.rotation[1] = 0;
    g->object.rotation[2] = 0;
    g->object.scale[0] = lbl_805D81F4;
    g->object.scale[1] = lbl_805D81F4;
    g->object.scale[2] = lbl_805D81F4;
    g->object.child = NULL;
    g->object.sibling = NULL;
    return g;
}

f32 TBoss8Dragon::apply_default_velocity_scale() {
    f32 *vector = (f32 *)this;
    return ((TBoss8Dragon *)vector)->apply_velocity_scale(lbl_805D81E4, lbl_805D81D4);
}

f32 TBoss8Dragon::apply_velocity_scale(f32 farg0, f32 farg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    f32 var_f31;
    s32 temp_r31;

    temp_f1 = ((TObjBoss2Tunnel *)this)->clamp_velocity();
    if (temp_f1 > farg0) {
        var_f31 = lbl_805D8198;
        *(f32 *)((s8 *)this + 0) = var_f31;
        *(f32 *)&this->unk_4 = (f32) lbl_805D81F4;
        this->m_8 = var_f31;
    } else {
        temp_r31 = (s32) (lbl_805D81F8 * (temp_f1 / farg0));
        var_f31 = farg1 * (lbl_805D81F4 + cos_table_lookup(temp_r31, lbl_805D81F8));
        temp_f1_2 = sin_table_lookup(temp_r31);
        temp_f2 = *(f32 *)((s8 *)this + 0) * temp_f1_2;
        *(f32 *)((s8 *)this + 0) = temp_f2;
        *(f32 *)&this->unk_4 = (f32) lbl_805D81F4;
        this->m_8 = (f32) (this->m_8 * temp_f1_2);
        update_scale__15TObjBoss2TunnelFv(this, temp_f1_2);
    }
    return var_f31;
}

#pragma push
#pragma fp_contract on
f32 lerp__9TDeadSpotFff(f32 farg0, f32 farg1) {
    return ((farg1 - farg0) * (lbl_805D818C * (f32) rand())) + farg0;
}
#pragma pop

#pragma push
#pragma fp_contract on
f32 rand_signed_unit(void) {
    return lbl_805D8184 * ((lbl_805D818C * (f32) rand()) - lbl_805D817C);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjBoss1Rock::render() {
    Obj_8002DF7C *self = (Obj_8002DF7C *)this;
    if (self->color < lbl_805D8200) {
        saved_model_render_flags = model_render_flags;
        model_render_flags = saved_model_render_flags | 0x810;
        ((void (*)(s32, s32))set_chunk_material_override_pair)(0xFF00, 0x800);
        set_constant_material((const NJS_ARGB *)((&self->color)));
        push_matrix();
        TObjFish::set_global_param(dragon_common_texture_list);
        post_translate_matrix(self->pos);
        rotate_matrix_y(0, self->ry);
        rotate_matrix_x(0, self->rx);
        ((void (*)(s32))draw_chunk_object)((*(Res_8002DF7C **)&lbl_805D4B50)->ents[self->idx].id);
        pop_matrix();
        ((void (*)(s32, s32))set_chunk_material_override_pair)(0xFF00, 0);
        model_render_flags = saved_model_render_flags;
    } else {
        push_matrix();
        TObjFish::set_global_param(dragon_common_texture_list);
        post_translate_matrix(self->pos);
        rotate_matrix_y(0, self->ry);
        rotate_matrix_x(0, self->rx);
        ((void (*)(s32))draw_chunk_object)((*(Res_8002DF7C **)&lbl_805D4B50)->ents[self->idx].id);
        pop_matrix();
    }
}
#pragma pop
