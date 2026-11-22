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

#include "pso/system/MatrixStack.h"
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/math/AngleLookup.h"
#include "pso/boss/dragon/TObjBoss1Crater.h"
#include "pso/boss/dragon/ObjBoss1CommonResource.h"

// A texture coordinate of the trail model as load_resources saved it, one per strip index.
struct TrailUV {
    s16 u;
    s16 v;
};

// A trail model vertex higher than 15 that bobs while the mound is active (load_resources lists them).
struct TrailRaisedVertex {
    f32 *dst;
    f32 base;
    f32 ofs;
    s32 state; // 0 sinking, 1 rising, else frames left to wait
};


Unk_8002DB7C *dragon_trail_grid;
Unk_8002DB7C *dragon_trail_strip;
Unk_8002DB7C *dragon_trail_small_grid;
TrailUV *dragon_trail_uvs;
s16 *dragon_trail_strips;
s32 dragon_trail_raised_count;
TrailRaisedVertex *dragon_trail_raised_vertices;
Vec *dragon_trail_position_source;
s32 *dragon_trail_heading_source;

const char *TObjBoss1MokoHill_SoloM__name = "TObjBoss1MokoHill_SoloM";
const char *TObjBoss1MokoHill_Solo__name = "TObjBoss1MokoHill_Solo";

#pragma fp_contract on

s16 dragon_trail_grid_u[11];

s16 dragon_trail_grid_v[11];

#pragma push
#pragma fp_contract on
f32 rand_signed_unit(void) {
    return 2.0f * ((3.0517578e-05f * (f32) rand()) - 0.5f);
}

f32 lerp__9TDeadSpotFff(f32 lo, f32 hi) {
    return ((hi - lo) * (3.0517578e-05f * (f32) rand())) + lo;
}

#pragma pop
f32 apply_velocity_scale(Vec *vector, f32 radius, f32 height) {
    f32 distance;
    f32 scale;
    f32 s;
    s32 angle;

    distance = normalize_vector_xz(vector);
    if (distance > radius) {
        scale = 0.0f;
        vector->x = scale;
        vector->y = 1.0f;
        vector->z = scale;
    } else {
        angle = (s32) (32768.0f * (distance / radius));
        scale = height * (1.0f + cos_table_lookup(angle));
        s = sin_table_lookup(angle);
        vector->x *= s;
        vector->y = 1.0f;
        vector->z *= s;
        normalize_vector_safe(vector);
    }
    return scale;
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
void TObjBoss1MokoHill_SoloM::load_resources() {
    f32 x;
    f32 small_x;
    f32 z;
    f32 small_z;
    TrailUV *uv;
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
    TrailRaisedVertex *e;
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
    resource = dragon_ground_resource;
    material = ((NJS_CNK_MODEL *)resource->models[4].model->model)->polygon_list;
    grid = new Unk_8002DB7C(width, 10, 8, material);
    dragon_trail_grid = grid;
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
        dragon_trail_grid_u[uv_index] = (s16)(1024.0f * (0.0125f * v->pos.x));
        dragon_trail_grid_v[uv_index] = (s16)(1024.0f * (-0.0125f * v->pos.x));
    }

    grid = new Unk_8002DB7C(5, 4, 8, material);
    dragon_trail_small_grid = grid;
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
    poly = dragon_trail_small_grid->polygons;
    poly[7] = (poly[7] & 0xC000) | 5;
    poly[8] |= 0x900;
    poly = dragon_trail_small_grid->get_strips();
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
    dragon_trail_strip = grid;
    {
        s16 *start;
        trail = (NJS_CNK_MODEL *)dragon_ground_resource->models[3].model->model;
        vtx = (f32 *)trail->vertex_list;
        poly = trail->polygon_list;
        poly[6] = 0x408;
        dragon_trail_strips = (poly += 8);
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
        dragon_trail_uvs = (TrailUV *)mem_alloc(total * sizeof(TrailUV));
        uv = dragon_trail_uvs;
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
    vertex_count = ((u32 *)((NJS_CNK_MODEL *)dragon_ground_resource->models[3].model->model)->vertex_list)[1] >> 16;
    dragon_trail_raised_count = 0;
    vstart = vtx;
    for (count_index = 0; count_index < vertex_count; count_index++, vtx += 6) {
        if (vtx[1] > 15.0f) dragon_trail_raised_count++;
    }
    dragon_trail_raised_vertices = (TrailRaisedVertex *)mem_alloc(dragon_trail_raised_count * sizeof(TrailRaisedVertex));
    e = dragon_trail_raised_vertices;
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
void TObjBoss1MokoHill_SoloM::free_resources() {
    mem_free(dragon_trail_raised_vertices);
    dragon_trail_raised_vertices = NULL;
    mem_free(dragon_trail_uvs);
    dragon_trail_uvs = NULL;
    delete dragon_trail_strip;
    dragon_trail_strip = NULL;
    delete dragon_trail_small_grid;
    dragon_trail_small_grid = NULL;
    delete dragon_trail_grid;
    dragon_trail_grid = NULL;
}

void update_dragon_trail_uvs(Vec *position) {
    s32 cnt;
    s16 n;
    s16 *p = dragon_trail_strips + 3;
    TrailUV *src = dragon_trail_uvs;
    s32 i = 0;
    s16 du = (s16)(1024.0f * (0.0125f * position->x));
    s16 dv = (s16)(1024.0f * (-0.0125f * position->z));
    cnt = dragon_trail_strips[2] & 0x3FFF;
    for (; i < cnt; i++) {
        n = *p++;
        s32 j;
        if (n < 0) {
            n = -n;
        }
        for (j = 0; j < n; j++) {
            p[1] = src->u + du;
            p[2] = src->v + dv;
            src++;
            p += 3;
        }
    }
}

f32 get_velocity_scale_limit(void) {
    return 16.0f;
}

TObjBoss1MokoHill_SoloM::TObjBoss1MokoHill_SoloM(TObject *parent, Vec *position, s32 *heading) : TObject(parent) {
    m_name = TObjBoss1MokoHill_SoloM__name;
    active = 0;
    dragon_trail_position_source = position;
    dragon_trail_heading_source = heading;
    VecCopy(&last_position, position);
    travel_distance = 0.0f;
    base_height = -30.0f;
    height = -30.0f;
    if (TObjEneDD::check_v2_mode() != 0) {
        v2_mode = 1;
    } else {
        v2_mode = 0;
    }
    no_hold = 0;
}

TObjBoss1MokoHill_SoloM::~TObjBoss1MokoHill_SoloM() {

}

void TObjBoss1MokoHill_SoloM::stop() {
    active = 0;
    height = -30.0f;
    base_height = -30.0f;
    new TObjBoss1MokoHill_Solo(m_up, 30);
    no_hold = 0;
}

void TObjBoss1MokoHill_SoloM::start() { active = 1; }

void TObjBoss1MokoHill_SoloM::start_without_hold() { start(); no_hold = 1; }

s32 TObjBoss1MokoHill_SoloM::is_dragon_trail_damaging() {
    return height >= -10.0f;
}

#pragma push
#pragma fp_contract on
void TObjBoss1MokoHill_SoloM::run_task() {
    Vec pos;
    Vec vel;
    f32 d;
    f32 ax;
    f32 az;
    f32 s;
    f32 c;
    s32 ang;
    TrailRaisedVertex *p;
    s32 i;

    if (active != 0) {
        base_height += 0.5f;
        if (base_height > 0.0f) {
            base_height = 0.0f;
        }
        d = calc_nearest_crater_distance(dragon_trail_position_source);
        height = base_height;
        if (0.0f != d && d < 95.0f) {
            height = -30.0f - -0.31578946f * d;
            if (height > base_height) {
                height = base_height;
            }
        }
        if (height >= 0.0f) {
            travel_distance += newton_sqrtf(horizontal_distance_squared(dragon_trail_position_source, &last_position));
            VecCopy(&last_position, dragon_trail_position_source);
            if (travel_distance >= 10.0f) {
                travel_distance = 0.0f;
                if (no_hold != 0) {
                    new TObjBoss1MokoHill_Solo(m_up, 0);
                } else {
                    new TObjBoss1MokoHill_Solo(m_up, 30);
                }
            }
            ang = *dragon_trail_heading_source;
            s = cos_table_lookup(ang);
            c = sin_table_lookup(ang);
            {
                f32 k = 120.0f;
                ax = c * k + dragon_trail_position_source->x;
                az = s * k + dragon_trail_position_source->z;
            }
            ang += (s32)(10000.0f * rand_signed_unit());
            s = cos_table_lookup(ang);
            c = sin_table_lookup(ang);
            {
                f32 k = 50.0f;
                pos.x = c * k + dragon_trail_position_source->x;
                pos.y = 0.0f;
                pos.z = s * k + dragon_trail_position_source->z;
            }
            vel.x = pos.x - ax;
            vel.z = pos.z - az;
            normalize_vector_xz(&vel);
            vel.x *= 1.5f;
            vel.z *= 1.5f;
            vel.y = lerp__9TDeadSpotFff(6.0f, 9.0f);
            new TObjBoss1Rock(m_up, &pos, &vel, 1);
        }
        for (p = dragon_trail_raised_vertices, i = 0; i < dragon_trail_raised_count; p++, i++) {
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
    TrailRaisedVertex *p;
    s32 i;
    if (active != 0) {
        TObjFish::set_global_param(dragon_common_texture_list);
        update_dragon_trail_uvs(dragon_trail_position_source);
        for (p = dragon_trail_raised_vertices, i = 0; i < dragon_trail_raised_count; i++, p++) {
            *p->dst = p->base + p->ofs;
        }
        push_matrix();
        post_translate_matrix(&dragon_trail_position_source->x);
        translate_matrix(0, 0.0f, height, 0.0f);
        if (v2_mode != 0) {
            saved_model_render_flags = model_render_flags;
            saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
            saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
            model_render_flags |= 0x800;
            set_chunk_material_override_pair(0xFF00, 0x100);
            draw_chunk_object(dragon_ground_resource->models[3].model);
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
        } else {
            draw_chunk_object(dragon_ground_resource->models[3].model);
        }
        pop_matrix();
        for (p = dragon_trail_raised_vertices, i = 0; i < dragon_trail_raised_count; i++, p++) {
            *p->dst = p->base;
        }
    }
}

TObjBoss1MokoHill_Solo::TObjBoss1MokoHill_Solo(TObject *parent, s32 hold_time) : TObject(parent) {
    m_name = TObjBoss1MokoHill_Solo__name;
    VecCopy(&position, get_source_position());
    height = -32.0f;
    peak_height = -(2.0f + 8.0f * (3.0517578e-05f * (f32)rand()));
    pad_3C = (s32)lerp__9TDeadSpotFff(20.0f, 40.0f);
    timer = 0;
    state = 0;
    if (TObjEneDD::check_v2_mode() != 0) {
        v2_mode = 1;
    } else {
        v2_mode = 0;
    }
    this->hold_time = hold_time;
}

TObjBoss1MokoHill_Solo::~TObjBoss1MokoHill_Solo() {

}

Vec *TObjBoss1MokoHill_Solo::get_source_position() {
    return dragon_trail_position_source;
}

void TObjBoss1MokoHill_Solo::run_task() {
    switch (state) {
    case 0:
        height += 4.0f;
        if (height >= peak_height) {
            height = peak_height;
            state = 1;
        }
        VecCopy(&position, get_source_position());
        break;
    case 1:
        timer++;
        if (timer > hold_time) {
            state = 2;
        }
        break;
    case 2:
        height -= 0.5f;
        if (height < -32.0f) {
            queue_destruction();
        }
        break;
    }
}
