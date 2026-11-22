#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma defer_codegen on
#pragma readonly_strings on

#include "pso/system/vector.h"

#include "pso/system/NinjaTypes.h"

#include "pso/unk/text_803D8F74.h"

#include "pso/player/TObjPlayer_80011014.h"

#include "pso/system/MatrixOps.h"

#include "pso/math/MatrixTransforms.h"

#include <stdlib.h>

#include "pso/unk/text_803E2D70.h"

#include "pso/unk/text_803D96A8.h"


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
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

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

struct Trail_8002CFB8 {
    u8 pad0[0x10];
    void *f10;
    u8 pad14[0x1C - 0x14];
    s32 f1C;
    Vec pos;
    f32 f2C;
    f32 f30;
    f32 f34;
    u8 pad38[4];
    s32 f3C;
};

typedef struct Obj_8002CD8C {
    const char *name;
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

void *TObjBoss1MokoHill_Solo__ct(void *arg0_, void *parent, int arg2);


extern BmlResource *lbl_805D4B50;

extern s32 dragon_common_texture_list;

Unk_8002DB7C *lbl_805D4B60;

Unk_8002DB7C *lbl_805D4B64;

Unk_8002DB7C *lbl_805D4B68;

UV_8002D4C0 *lbl_805D4B6C;

s16 *lbl_805D4B70;

s32 lbl_805D4B74;

Ent_8002CE78 *lbl_805D4B78;

saddr dragon_trail_position_source;

saddr dragon_trail_heading_source;

extern s32 saved_model_render_flags;

extern s32 saved_chunk_polygon_flags_and_mask;

extern s32 saved_chunk_polygon_flags_or_mask;

extern s32 chunk_polygon_flags_or_mask;

extern s32 chunk_polygon_flags_and_mask;

extern s32 model_render_flags;


void post_translate_matrix(void *);

void set_chunk_material_override_pair(s32, s32, s32, s32);


f32 calc_nearest_crater_distance(void *);

f32 horizontal_distance_squared(void *, void *);

f32 sin_table_lookup(s32);

f32 cos_table_lookup(s32, f32);



void update_dragon_trail_uvs(Obj_8002D4C0 *self);

f32 rand_signed_unit(void);
}

const char *TObjBoss1MokoHill_SoloM__name = "TObjBoss1MokoHill_SoloM";
const char *TObjBoss1MokoHill_Solo__name = "TObjBoss1MokoHill_Solo";

s32 is_dragon_trail_damaging(u8 *arg0);

#pragma fp_contract on

s16 lbl_804FE238[11];

s16 lbl_804FE250[11];

#pragma push
#pragma fp_contract on
f32 rand_signed_unit(void) {
    return 2.0f * ((3.0517578e-05f * (f32) rand()) - 0.5f);
}

f32 lerp__9TDeadSpotFff(f32 farg0, f32 farg1) {
    return ((farg1 - farg0) * (3.0517578e-05f * (f32) rand())) + farg0;
}

#pragma pop
f32 apply_velocity_scale(Vec *vector, f32 farg0, f32 farg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    f32 var_f31;
    s32 temp_r31;

    temp_f1 = normalize_vector_xz(vector);
    if (temp_f1 > farg0) {
        var_f31 = 0.0f;
        vector->x = var_f31;
        vector->y = 1.0f;
        vector->z = var_f31;
    } else {
        temp_r31 = (s32) (32768.0f * (temp_f1 / farg0));
        var_f31 = farg1 * (1.0f + cos_table_lookup(temp_r31, 32768.0f));
        temp_f1_2 = sin_table_lookup(temp_r31);
        temp_f2 = vector->x * temp_f1_2;
        vector->x = temp_f2;
        vector->y = 1.0f;
        vector->z = vector->z * temp_f1_2;
        normalize_vector_safe((Vec *)vector);
    }
    return var_f31;
}

f32 apply_default_velocity_scale(Vec *vector) {
    return apply_velocity_scale(vector, 60.0f, 16.0f);
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
        vt->pos.x = 0.0f;
        vt->pos.y = 0.0f;
        vt->pos.z = 0.0f;
        vt->normal.x = 0.0f;
        vt->normal.y = 0.0f;
        vt->normal.z = 0.0f;
        vt++;
    }
    *(u32 *)vt = 0xff;
    this->model.vertex_list = this->vertices;
    this->model.polygon_list = this->polygons;
    this->model.center[0] = 0.0f;
    this->model.center[1] = 0.0f;
    this->model.center[2] = 0.0f;
    this->model.r = 0.0f;
    this->object.evalflags = 0x17;
    this->object.model = &this->model;
    this->object.pos[0] = 0.0f;
    this->object.pos[1] = 0.0f;
    this->object.pos[2] = 0.0f;
    this->object.ang[0] = 0;
    this->object.ang[1] = 0;
    this->object.ang[2] = 0;
    this->object.scl[0] = 1.0f;
    this->object.scl[1] = 1.0f;
    this->object.scl[2] = 1.0f;
    this->object.child = NULL;
    this->object.sibling = NULL;
}

Unk_8002DB7C::~Unk_8002DB7C() {
    mem_free(vertices);
    vertices = NULL;
    mem_free(polygons);
    polygons = NULL;
    model.vertex_list = NULL;
    model.polygon_list = NULL;
}

Unk_8002DB7C::Vertex *Unk_8002DB7C::get_vertices() {
    return (Vertex *)(vertices + 2);
}

s16 *Unk_8002DB7C::get_strips() {
    return polygons + (materialWords + 3);
}

#pragma push
#pragma opt_propagation off
// Builds the dragon arena's run-time meshes: an 11 x 11 grid and a 5 x 5 grid shaped by
// apply_default_velocity_scale, an 11-wide single strip, the trail model's uv table and the list of
// its raised vertices (role inferred from the body; free_resources releases all of them).
void TBoss8Dragon__sub_8002D5F8(void) {
    f32 x;
    f32 small_x;
    f32 z;
    f32 small_z;
    UV_8002D4C0 *uv;
    s32 upper_v;
    f32 *source;
    Vec normal;
    s32 uv_index;
    s32 total;
    s32 strip_index;
    s32 lower_v;
    Unk_8002DB7C::Vertex *verts;
    f32 *vtx;
    s32 u;
    s32 uv_col;
    s32 j;
    s16 n;
    Unk_8002DB7C::Vertex *v;
    NJS_CNK_MODEL *trail;
    Ent_8002CE78 *e;
    s32 small_col;
    s32 row;
    s32 vertex_count;
    Vec small_normal;
    s32 col;
    s16 *material;
    s32 count_index;
    s16 *uv_strip;
    s32 strip_count;
    s32 uv_strip_index;
    Unk_8002DB7C::Vertex *v2;
    s32 small_row;
    f32 *vstart;
    s16 *poly;
    s32 uv_row;
    BmlResource *resource;
    s32 entry_index;
    Unk_8002DB7C *grid;
    s32 width = 11;
    resource = lbl_805D4B50;
    material = ((NJS_CNK_MODEL *)((NJS_OBJECT *)resource->models[4].model)->model)->polygon_list;
    grid = new Unk_8002DB7C(width, 10, 8, material);
    lbl_805D4B60 = grid;
    verts = grid->get_vertices();
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
    for (uv_index = 0; uv_index < 11; uv_index++, v++) {
        lbl_804FE238[uv_index] = (s16)(1024.0f * (0.0125f * v->pos.x));
        lbl_804FE250[uv_index] = (s16)(1024.0f * (-0.0125f * v->pos.x));
    }

    grid = new Unk_8002DB7C(5, 4, 8, material);
    lbl_805D4B68 = grid;
    v2 = grid->get_vertices();
    small_z = 0.0f;
    for (small_row = 0; small_row < 5; small_row++) {
        small_x = 15.0f;
        for (small_col = 0; small_col < 5; small_col++) {
            small_normal.x = small_x;
            small_normal.z = small_z;
            v2->pos.x = small_x;
            v2->pos.y = 2.0f + apply_default_velocity_scale(&small_normal);
            v2->pos.z = small_z;
            v2->normal.x = small_normal.x;
            v2->normal.y = small_normal.y;
            v2->normal.z = small_normal.z;
            v2++;
            small_x -= 7.5f;
        }
        small_z -= 7.5f;
    }
    poly = lbl_805D4B68->polygons;
    poly[7] = (poly[7] & 0xC000) | 5;
    poly[8] |= 0x900;
    poly = lbl_805D4B68->get_strips();
    upper_v = 0x400;
    lower_v = 0x300;
    for (uv_row = 0; uv_row < 4; uv_row++) {
        u = 0;
        poly++;
        for (uv_col = 0; uv_col < 5; uv_col++) {
            poly[1] = u;
            poly[2] = upper_v;
            poly[4] = u;
            poly[5] = lower_v;
            poly += 6;
            u += 0x100;
        }
        upper_v = lower_v;
        lower_v -= 0x100;
    }

    grid = new Unk_8002DB7C(11, 1, 8, material);
    lbl_805D4B64 = grid;
    {
        s16 *start;
        trail = (NJS_CNK_MODEL *)((NJS_OBJECT *)lbl_805D4B50->models[3].model)->model;
        vtx = (f32 *)trail->vertex_list;
        poly = trail->polygon_list;
        poly[6] = 0x408;
        lbl_805D4B70 = (poly += 8);
        poly[0] = 0x242;
        strip_count = poly[2] & 0x3FFF;
        poly += 3;
        start = poly;
        total = 0;
        vtx += 2;
        for (strip_index = 0; strip_index < strip_count; strip_index++) {
            n = *poly++;
            if (n < 0) n = -n;
            total += n;
        }
        lbl_805D4B6C = (UV_8002D4C0 *)mem_alloc(total * sizeof(UV_8002D4C0));
        uv = lbl_805D4B6C;
        uv_strip = start;
        for (uv_strip_index = 0; uv_strip_index < strip_count; uv_strip_index++) {
            n = *uv_strip++;
            if (n < 0) n = -n;
            for (j = 0; j < n; j++) {
                // Six floats (position and normal) per vertex.
                source = vtx + (u32)(*uv_strip * 6);
                uv_strip += 3;
                uv->u = (s16)(1024.0f * (0.0125f * source[0]));
                uv->v = (s16)(1024.0f * (-0.0125f * source[2]));
                uv++;
            }
        }
    }
    vertex_count = ((u32 *)((NJS_CNK_MODEL *)((NJS_OBJECT *)lbl_805D4B50->models[3].model)->model)->vertex_list)[1] >> 16;
    lbl_805D4B74 = 0;
    vstart = vtx;
    for (count_index = 0; count_index < vertex_count; count_index++, vtx += 6) {
        if (vtx[1] > 15.0f) lbl_805D4B74++;
    }
    lbl_805D4B78 = (Ent_8002CE78 *)mem_alloc(lbl_805D4B74 * sizeof(Ent_8002CE78));
    e = lbl_805D4B78;
    vtx = vstart;
    for (entry_index = 0; entry_index < vertex_count; vtx += 6, entry_index++) {
        if (vtx[1] > 15.0f) {
            e->dst = &vtx[1];
            e->base = vtx[1];
            e->ofs = -8.0f;
            e->state = (s32)(70.0f * (3.0517578125e-05f * (f32)rand())) + 2;
            e++;
        }
    }
}

#pragma pop
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

void update_dragon_trail_uvs(Obj_8002D4C0 *self) {
    s32 cnt;
    s16 n;
    s16 *p = lbl_805D4B70 + 3;
    UV_8002D4C0 *src = lbl_805D4B6C;
    s32 i = 0;
    s16 du = (s16)(1024.0f * (0.0125f * self->x));
    s16 dv = (s16)(1024.0f * (-0.0125f * self->z));
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

f32 get_velocity_scale_limit(void) {
    return 16.0f;
}

#define boss1_moko_hill_solo_m ((u8 *)this)
TObjBoss1MokoHill_SoloM::TObjBoss1MokoHill_SoloM(TObject *parent, u8 *position, s32 arg3) : TObject(parent) {
    *(s32 *)((s8 *)boss1_moko_hill_solo_m + 0) = (saddr) TObjBoss1MokoHill_SoloM__name;
    *(s32 *)((s8 *)boss1_moko_hill_solo_m + 0x1C) = 0;
    (*(u8 * *)&dragon_trail_position_source) = position;
    dragon_trail_heading_source = arg3;
    VecCopy((Vec *)(boss1_moko_hill_solo_m + 0x20), (const Vec *)position);
    ((TObjBoss1MokoHill_SoloM *)boss1_moko_hill_solo_m)->m_2c = (f32) 0.0f;
    *(f32 *)((s8 *)boss1_moko_hill_solo_m + 0x30) = (f32) -30.0f;
    ((TObjBoss1MokoHill_SoloM *)boss1_moko_hill_solo_m)->m_34 = (f32) -30.0f;
    if (TObjEneDD::check_v2_mode() != 0) {
        *(s32 *)((s8 *)boss1_moko_hill_solo_m + 0x38) = 1;
    } else {
        *(s32 *)((s8 *)boss1_moko_hill_solo_m + 0x38) = 0;
    }
    ((TObjBoss1MokoHill_SoloM *)boss1_moko_hill_solo_m)->m_3c = 0;
}
#undef boss1_moko_hill_solo_m

TObjBoss1MokoHill_SoloM::~TObjBoss1MokoHill_SoloM() {

}

void TBoss8Dragon::spawn_child_object() {
    void *o;
    *(u32 *)((u8 *)this + 0x1C) = 0;
    *(f32 *)((u8 *)this + 0x34) = -30.0f;
    *(f32 *)((u8 *)this + 0x30) = -30.0f;
    o = TObject::operator new(0x50);
    if (o != NULL) {
        TObjBoss1MokoHill_Solo__ct(o, (void *)(*(void **)((u8 *)this + 0x10)), 30);
    }
    *(u32 *)((u8 *)this + 0x3C) = 0;
}

void TBoss8Dragon::set_field_1c() { *(s32 *)((u8 *)this + 0x1C) = 1; }

void TBoss8Dragon::set_field_3c() { set_field_1c(); *(int *)((u8 *)this + 0x3C) = 1; }

s32 is_dragon_trail_damaging(u8 *arg0) {
    return *(f32 *)((s8 *)arg0 + 0x34) >= -10.0f;
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
            self->f34 = -30.0f - -0.31578946f * d;
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
                    o = TObject::operator new(0x50);
                    if (o != NULL) {
                        TObjBoss1MokoHill_Solo__ct(o, self->f10, 0);
                    }
                } else {
                    o = TObject::operator new(0x50);
                    if (o != NULL) {
                        TObjBoss1MokoHill_Solo__ct(o, self->f10, 0x1E);
                    }
                }
            }
            ang = *(s32 *)dragon_trail_heading_source;
            s = ((f32 (*)(s32))cos_table_lookup)(ang);
            c = sin_table_lookup(ang);
            {
                f32 k = 120.0f;
                ax = c * k + ((Vec *)dragon_trail_position_source)->x;
                az = s * k + ((Vec *)dragon_trail_position_source)->z;
            }
            ang += (s32)(10000.0f * rand_signed_unit());
            s = ((f32 (*)(s32))cos_table_lookup)(ang);
            c = sin_table_lookup(ang);
            {
                f32 k = 50.0f;
                pos.x = c * k + ((Vec *)dragon_trail_position_source)->x;
                pos.y = 0.0f;
                pos.z = s * k + ((Vec *)dragon_trail_position_source)->z;
            }
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
                    p->ofs += 2.0f;
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
        translate_matrix(0, 0.0f, arg0->unk34, 0.0f);
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

#define arg0 ((Obj_8002CD8C *)arg0_)
void *TObjBoss1MokoHill_Solo__ct(void *arg0_, void *parent, int arg2) {
    f32 r;
    f32 t;
    __ct__7TObjectFP7TObject(arg0, parent);
    arg0->vtbl = __vt__22TObjBoss1MokoHill_Solo;
    arg0->name = TObjBoss1MokoHill_Solo__name;
    VecCopy((Vec *)arg0->pos, (const Vec *)(((void *(*)(void *))get_state__12TBoss8DragonFv)(arg0)));
    arg0->unk34 = -32.0f;
    r = (f32)rand();
    arg0->unk38 = (f32) -(2.0f + 8.0f * (t = 3.0517578e-05f * r));
    arg0->unk3C = (s32)((f32 (*)(f32, f32, f32, f32, f32))lerp__9TDeadSpotFff)(20.0f, 40.0f, 8.0f, t, r);
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
TObjBoss1MokoHill_Solo::~TObjBoss1MokoHill_Solo() {

}

s32 get_state__12TBoss8DragonFv(void) {
    return dragon_trail_position_source;
}

void TObjBoss1MokoHill_Solo::run_task() {
    Trail_8002CC48 *self = (Trail_8002CC48 *)this;
    switch (self->state) {
    case 0:
        self->f34 += 4.0f;
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
        self->f34 -= 0.5f;
        if (self->f34 < -32.0f) {
            queue_destruction();
        }
        break;
    }
}
