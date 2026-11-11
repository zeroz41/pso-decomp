#include "pso/system/vector.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include <stdlib.h>
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
void set_constant_material(const NJS_ARGB *color);
#include "types.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/memory.h"
#include "pso/boss/dragon/TObjBoss1MokoHill_Solo.h"
#include "pso/boss/dragon/TObjBoss1MokoHill_SoloM.h"
#include <stddef.h>
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/system/BmlResource.h"
#include "pso/boss/dragon/TObjBoss1Rock.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/object/ambient/TObjFish.h"

struct RecoveredGlobal_8002D41C_lbl_80482060 { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8002D41C_lbl_80482060_size[sizeof(RecoveredGlobal_8002D41C_lbl_80482060) == 0x18 ? 1 : -1];

struct UV_8002D4C0 { s16 u, v; };

struct Vtx_8002D4C0 { s16 pad; s16 u; s16 v; };

struct Obj_8002D4C0 { f32 x; u8 pad[4]; f32 z; };

typedef struct Ent_8002CE78 {
    f32 *dst;
    f32 base;
    f32 ofs;
    s32 state;
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
extern BmlResource *lbl_805D4B50;
extern s32 dragon_common_texture_list;
extern Unk_8002DB7C *lbl_805D4B60;
extern Unk_8002DB7C *lbl_805D4B64;
extern Unk_8002DB7C *lbl_805D4B68;
extern UV_8002D4C0 *lbl_805D4B6C;
extern s16 *lbl_805D4B70;
extern s32 lbl_805D4B74;
extern Ent_8002CE78 *lbl_805D4B78;
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

void push_matrix(void);
void post_translate_matrix(void *);
void set_chunk_material_override_pair(s32, s32, s32, s32);
void queue_destruction__7TObjectFv();
void *__nw__7TObjectFUl(int);
void mem_free(void *p);
void *mem_alloc(u32);
f32 calc_nearest_crater_distance(void *);
f32 horizontal_distance_squared(void *, void *);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32, f32);
s32 update_scale__15TObjBoss2TunnelFv(void *, f32);
u8 *TObjBoss1MokoHill_SoloM__ct(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3);
void update_dragon_trail_uvs(Obj_8002D4C0 *self);
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
        for (p = lbl_805D4B78, i = 0; i < lbl_805D4B74; i++, p++) {
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
            draw_chunk_object((void *)lbl_805D4B50->models[3].model);
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
        } else {
            draw_chunk_object((void *)lbl_805D4B50->models[3].model);
        }
        pop_matrix();
        for (p = lbl_805D4B78, i = 0; i < lbl_805D4B74; i++, p++) {
            *p->dst = p->base;
        }
    }
}

#pragma push
#pragma fp_contract on
void TObjBoss1MokoHill_SoloM::run_task() {
    Trail_8002CFB8 *self = (Trail_8002CFB8 *)this;
    Vec pos;
    Vec vel;
    f32 d;
    f32 ax;
    f32 az;
    f32 s;
    f32 c;
    s32 ang;
    void *o;
    Ent_8002CE78 *p;
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
            normalize_vector_xz(&vel);
            vel.x *= 1.5f;
            vel.z *= 1.5f;
            vel.y = lerp__9TDeadSpotFff(6.0f, 9.0f);
            new TObjBoss1Rock((TObject *)self->f10, &pos, &vel, 1);
        }
        for (p = lbl_805D4B78, i = 0; i < lbl_805D4B74; p++, i++) {
            switch (p->state) {
            case 0:
                if (p->ofs < -8.0f) {
                    p->ofs = -8.0f;
                    p->state = (s32)(70.0f * (3.0517578125e-05f * (f32)rand())) + 2;
                } else {
                    p->ofs = p->ofs - 0.2f;
                }
                break;
            case 1:
                if (p->ofs > 0.0f) {
                    p->ofs = 0.0f;
                    p->state = 0;
                } else {
                    p->ofs = p->ofs + lbl_805D8184;
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

void TBoss8Dragon::set_field_3c() { set_field_1c(); *(int *)&this->m_3c = 1; }
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
    *(u32 *)&this->m_3c = 0;
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
    s16 *p = lbl_805D4B70 + 3;
    UV_8002D4C0 *src = lbl_805D4B6C;
    s32 i = 0;
    s16 du = (s16)(lbl_805D81D8 * (lbl_805D81DC * self->x));
    s16 dv = (s16)(lbl_805D81D8 * (lbl_805D81E0 * self->z));
    cnt = lbl_805D4B70[2] & 0x3FFF;
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

void TBoss8Dragon::free_resources() {
    mem_free(lbl_805D4B78);
    lbl_805D4B78 = NULL;
    mem_free(lbl_805D4B6C);
    lbl_805D4B6C = NULL;
    delete lbl_805D4B64;
    lbl_805D4B64 = NULL;
    delete lbl_805D4B68;
    lbl_805D4B68 = NULL;
    delete lbl_805D4B60;
    lbl_805D4B60 = NULL;
}

extern s16 lbl_804FE238[11];
extern s16 lbl_804FE250[11];

// Builds the dragon arena's run-time meshes: an 11 x 11 grid and a 5 x 5 grid shaped by
// apply_default_velocity_scale, an 11-wide single strip, the trail model's uv table and the list of
// its raised vertices (role inferred from the body; free_resources releases all of them).
void TBoss8Dragon__sub_8002D5F8(void) {
    s16 *material = ((NJS_CNK_MODEL *)((NJS_OBJECT *)lbl_805D4B50->models[4].model)->model)->polygon_list;
    Unk_8002DB7C::Vertex *v;
    s32 count;
    s16 v1;
    f32 *vtx;
    s32 total;
    f32 x;
    s32 col2;
    s16 n;
    Ent_8002CE78 *e;
    s32 row;
    Vec normal;
    Unk_8002DB7C::Vertex *verts;
    s16 u;
    s16 *poly;
    s16 v0;
    s32 i;
    f32 *pos;
    f32 x2;
    Vec normal2;
    f32 z;
    NJS_CNK_MODEL *trail;
    UV_8002D4C0 *uv;
    s32 col;
    Unk_8002DB7C::Vertex *v2;
    s16 *strip;
    s16 *start;
    s16 *p;
    s32 row2;
    f32 z2;
    f32 *vstart;

    lbl_805D4B60 = new Unk_8002DB7C(11, 10, 8, material);
    verts = lbl_805D4B60->get_vertices();
    v = verts;
    z = 60.0f;
    for (row = 0; row < 11; row++) {
        x = 60.0f;
        for (col = 0; col < 11; col++) {
            normal.x = x;
            normal.z = z;
            v->pos.x = x;
            v->pos.y = apply_default_velocity_scale(&normal);
            v->pos.z = z;
            v->normal.x = normal.x;
            v->normal.y = normal.y;
            v->normal.z = normal.z;
            v++;
            x -= 12.0f;
        }
        z -= 12.0f;
    }
    v = verts;
    for (i = 0; i < 11; i++) {
        lbl_804FE238[i] = 1024.0f * (0.0125f * v->pos.x);
        lbl_804FE250[i] = 1024.0f * (-0.0125f * v->pos.x);
        v++;
    }

    lbl_805D4B68 = new Unk_8002DB7C(5, 4, 8, material);
    v2 = lbl_805D4B68->get_vertices();
    z2 = 0.0f;
    for (row2 = 0; row2 < 5; row2++) {
        x2 = 15.0f;
        for (col2 = 0; col2 < 5; col2++) {
            normal2.x = x2;
            normal2.z = z2;
            v2->pos.x = x2;
            v2->pos.y = 2.0f + apply_default_velocity_scale(&normal2);
            v2->pos.z = z2;
            v2->normal.x = normal2.x;
            v2->normal.y = normal2.y;
            v2->normal.z = normal2.z;
            v2++;
            x2 -= 7.5f;
        }
        z2 -= 7.5f;
    }
    poly = lbl_805D4B68->polygons;
    poly[7] = (poly[7] & 0xC000) | 5;
    poly[8] |= 0x900;
    strip = lbl_805D4B68->get_strips();
    v0 = 0x400;
    v1 = 0x300;
    for (row = 0; row < 4; row++) {
        strip++;
        u = 0;
        for (col = 0; col < 5; col++) {
            strip[1] = u;
            strip[2] = v0;
            strip[4] = u;
            strip[5] = v1;
            strip += 6;
            u += 0x100;
        }
        v0 = v1;
        v1 -= 0x100;
    }

    lbl_805D4B64 = new Unk_8002DB7C(11, 1, 8, material);

    trail = (NJS_CNK_MODEL *)((NJS_OBJECT *)lbl_805D4B50->models[3].model)->model;
    vtx = (f32 *)trail->vertex_list;
    poly = trail->polygon_list;
    poly[6] = 0x408;
    p = poly + 8;
    lbl_805D4B70 = p;
    p[0] = 0x242;
    count = p[2] & 0x3FFF;
    p += 3;
    start = p;
    vtx += 2;
    total = 0;
    for (i = 0; i < count; i++) {
        n = *p++;
        if (n < 0) {
            n = -n;
        }
        total += n;
    }
    uv = (UV_8002D4C0 *)mem_alloc(total * 4);
    p = start;
    lbl_805D4B6C = uv;
    for (i = 0; i < count; i++) {
        n = *p++;
        if (n < 0) {
            n = -n;
        }
        for (col = 0; col < n; col++) {
            pos = vtx + *p * 6;
            p += 3;
            uv->u = 1024.0f * (0.0125f * pos[0]);
            uv->v = 1024.0f * (-0.0125f * pos[2]);
            uv++;
        }
    }

    count = ((u32 *)((NJS_CNK_MODEL *)((NJS_OBJECT *)lbl_805D4B50->models[3].model)->model)->vertex_list)[1] >> 16;
    lbl_805D4B74 = 0;
    vstart = vtx;
    for (i = 0; i < count; i++) {
        if (vtx[1] > 15.0f) {
            lbl_805D4B74++;
        }
        vtx += 6;
    }
    e = (Ent_8002CE78 *)mem_alloc(lbl_805D4B74 * 16);
    vtx = vstart;
    lbl_805D4B78 = e;
    for (i = 0; i < count; i++) {
        if (vtx[1] > 15.0f) {
            e->dst = &vtx[1];
            e->base = vtx[1];
            e->ofs = -8.0f;
            e->state = (s32)(70.0f * (3.0517578125e-05f * (f32)rand())) + 2;
            e++;
        }
        vtx += 6;
    }
}

s16 *Unk_8002DB7C::get_strips() {
    return polygons + (materialWords + 3);
}

Unk_8002DB7C::Vertex *Unk_8002DB7C::get_vertices() {
    return (Vertex *)(vertices + 2);
}

Unk_8002DB7C::~Unk_8002DB7C() {
    mem_free(vertices);
    vertices = NULL;
    mem_free(polygons);
    polygons = NULL;
    model.vertex_list = NULL;
    model.polygon_list = NULL;
}

Unk_8002DB7C::Unk_8002DB7C(s32 width, s32 strips, s32 materialWords, s16 *material) {
    s32 i;
    s32 first;
    s32 second;
    s16 *p;
    s32 row;
    s32 x;
    s32 count;
    u32 *v;
    Vertex *vt;
    this->width = width;
    this->strips = strips;
    this->materialWords = materialWords;
    this->stripWords = this->width * 6 + 1;
    this->polygons = (s16 *)mem_alloc((this->materialWords + 5 + this->stripWords * this->strips) * 2);
    this->vertices = (u32 *)mem_alloc((this->width * (this->strips + 1) * 6 + 3) * 4);
    p = this->polygons;
    for (i = 0; i < this->materialWords; i++) {
        *p++ = *material++;
    }
    *p++ = 0x242;
    *p++ = this->stripWords * this->strips + 1;
    *p++ = this->strips;
    first = 0;
    second = this->width;
    for (row = 0; row < this->strips; row++) {
        *p++ = this->width * 2;
        for (x = 0; x < this->width;) {
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
    count = this->width * (this->strips + 1);
    v = this->vertices;
    *v++ = ((count * 6 + 1) << 16) | 0x29;
    *v++ = count << 16;
    vt = (Vertex *)v;
    for (i = 0; i < count; i++) {
        vt->pos.x = lbl_805D8198;
        vt->pos.y = lbl_805D8198;
        vt->pos.z = lbl_805D8198;
        vt->normal.x = lbl_805D8198;
        vt->normal.y = lbl_805D8198;
        vt->normal.z = lbl_805D8198;
        vt++;
    }
    *(u32 *)vt = 0xff;
    this->model.vertex_list = this->vertices;
    this->model.polygon_list = this->polygons;
    this->model.center[0] = lbl_805D8198;
    this->model.center[1] = lbl_805D8198;
    this->model.center[2] = lbl_805D8198;
    this->model.r = lbl_805D8198;
    this->object.evalflags = 0x17;
    this->object.model = &this->model;
    this->object.pos[0] = lbl_805D8198;
    this->object.pos[1] = lbl_805D8198;
    this->object.pos[2] = lbl_805D8198;
    this->object.ang[0] = 0;
    this->object.ang[1] = 0;
    this->object.ang[2] = 0;
    this->object.scl[0] = lbl_805D81F4;
    this->object.scl[1] = lbl_805D81F4;
    this->object.scl[2] = lbl_805D81F4;
    this->object.child = NULL;
    this->object.sibling = NULL;
}

f32 apply_default_velocity_scale(Vec *vector) {
    return apply_velocity_scale(vector, lbl_805D81E4, lbl_805D81D4);
}

f32 apply_velocity_scale(Vec *vector, f32 farg0, f32 farg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    f32 var_f31;
    s32 temp_r31;

    temp_f1 = normalize_vector_xz(vector);
    if (temp_f1 > farg0) {
        var_f31 = lbl_805D8198;
        vector->x = var_f31;
        vector->y = lbl_805D81F4;
        vector->z = var_f31;
    } else {
        temp_r31 = (s32) (lbl_805D81F8 * (temp_f1 / farg0));
        var_f31 = farg1 * (lbl_805D81F4 + cos_table_lookup(temp_r31, lbl_805D81F8));
        temp_f1_2 = sin_table_lookup(temp_r31);
        temp_f2 = vector->x * temp_f1_2;
        vector->x = temp_f2;
        vector->y = lbl_805D81F4;
        vector->z = vector->z * temp_f1_2;
        update_scale__15TObjBoss2TunnelFv(vector, temp_f1_2);
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
