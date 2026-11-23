#include "pso/effect/enemy/TeneFakeTecThunderEff.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/ChunkMaterialColor.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/GinjaView.h"
#include "pso/render/model_render_state.h"
#include "pso/render/render_util.h"
#include "pso/system/vector.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/unk/text_803D853C.h"
#include "types.h"

#pragma readonly_strings on

extern "C" Vec *subtract_vector(Vec *v, const Vec *sub);

const char *TeneFakeTecThunderEff::class_name = "TeneFakeTecThunderEff";
// The bolt's textures (set up by init_fake_tec_texlist) and the texture
// render draws with.
__declspec(section ".data") NJS_TEXLIST fake_tec_texlist;
u32 fake_tec_texture;

#pragma push
#pragma fp_contract on
void TeneFakeTecThunderEff::build_beam_points() {
    f32 len;
    f32 ax;
    f32 ay;
    f32 az;
    f32 dx;
    f32 dy;
    f32 dz;
    s32 i;
    s32 axis;
    f32 fx;
    f32 fy;
    f32 fz;
    Vec *p;

    VecCopy(&origin, from);
    VecCopy(&delta, to);
    subtract_vector(&delta, from);
    len = vector_length(&delta);
    segment_length = len / target_point_count;
    ax = origin.x;
    ay = origin.y;
    az = origin.z;
    dx = delta.x;
    dy = delta.y;
    dz = delta.z;
    point_count = 0;
    for (i = 0; i < target_point_count; i++) {
        f32 tt = (segment_length * i) / (target_point_count - 1);
        spacing[i] = tt;
        base_points[i].x = dx * tt + ax;
        base_points[i].y = dy * tt + ay;
        base_points[i].z = dz * tt + az;
    }
    point_count = target_point_count;
    fx = fabs_float(delta.x);
    fy = fabs_float(delta.y);
    fz = fabs_float(delta.z);
    if (fx > fy) {
        if (fx > fz) {
            axis = 0;
        } else {
            axis = 2;
        }
    } else if (fy > fz) {
        axis = 1;
    } else {
        axis = 2;
    }
    p = jitter_dirs;
    switch (axis) {
    case 0: {
        f32 u;
        f32 k;
        f32 inv;
        f32 e2;
        f32 e1;
        f32 v;
        inv = 1.0f / delta.x;
        e1 = delta.y;
        e2 = delta.z;
        k = 5.0f;
        for (i = 0; i < point_count; i++) {
            u = k * rand_signed_unit();
            v = k * rand_signed_unit();
            p->y = u;
            p->z = v;
            p->x = inv * (u * e1 + v * e2);
            normalize_vector_safe(p);
            p++;
        }
        break;
    }
    case 1: {
        f32 u;
        f32 inv;
        f32 e2;
        f32 e1;
        f32 v;
        inv = 1.0f / delta.y;
        e1 = delta.z;
        e2 = delta.x;
        f32 k;
        k = 5.0f;
        for (i = 0; i < point_count; i++) {
            u = k * rand_signed_unit();
            v = k * rand_signed_unit();
            p->z = u;
            p->x = v;
            p->y = inv * (u * e1 + v * e2);
            normalize_vector_safe(p);
            p++;
        }
        break;
    }
    case 2: {
        f32 u;
        f32 inv;
        f32 e2;
        f32 e1;
        f32 v;
        inv = 1.0f / delta.z;
        e1 = delta.x;
        e2 = delta.y;
        f32 k;
        k = 5.0f;
        for (i = 0; i < point_count; i++) {
            u = k * rand_signed_unit();
            v = k * rand_signed_unit();
            p->x = u;
            p->y = v;
            p->z = inv * (u * e1 + v * e2);
            normalize_vector_safe(p);
            p++;
        }
        break;
    }
    }
    for (i = 1; i < point_count - 1; i++) {
        jitter[i] = 4.0f * rand_signed_unit();
    }
    jitter[0] = 0.0f;
    jitter[point_count - 1] = 0.0f;
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma fp_contract on
void TeneFakeTecThunderEff::render() {
    TeneFakeTecThunderVertex verts[34];
    Vec out[17];
    f32 sa[17];
    f32 sb[17];
    Vec v;
    f32 sw;
    f32 sh;
    f32 cy;
    f32 cx;
    f32 one;
    f32 prevX;
    f32 prevY;
    f32 prevZ;
    f32 curX;
    f32 curY;
    f32 dx;
    f32 dy;
    f32 vv;
    f32 u0;
    f32 w;
    f32 a;
    f32 b;
    f32 inv;
    f32 nx;
    f32 ny;
    u32 vertex_color;
    Vec *q;
    TeneFakeTecThunderVertex *p;
    s32 i;
    s32 j;
    if (active == 0) {
        return;
    }
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    sw = screen_projection.distance;
    cx = screen_projection.center_x;
    cy = screen_projection.center_y;
    sh = sw * (480.0f / (480.0f * screen_projection.width));
    vertex_color = color | 0xFFFFFF;
    for (i = 0; i < point_count; i++) {
        matrix_mult_vec(0, &points[i], &v);
        if (v.z >= 1.0f) {
            v.z = 1.0f;
        }
        w = 1.0f / -v.z;
        v.y = -v.y;
        a = sh * w;
        b = sw * w;
        out[i].x = v.x * a + cx;
        sa[i] = a;
        out[i].y = v.y * b + cy;
        sb[i] = b;
        out[i].z = w;
    }
    vv = 0.0f;
    u0 = vv;
    p = verts;
    q = &out[1];
    prevX = out[0].x;
    prevY = out[0].y;
    prevZ = out[0].z;
    one = 1.0f;
    for (j = 0; j < point_count - 1; j++) {
        curY = q->y;
        curX = q->x;
        dy = curY - prevY;
        dx = curX - prevX;
        inv = one / newton_sqrtf(dx * dx + dy * dy);
        dx *= inv;
        dy *= inv;
        nx = one * (dy * sa[j]);
        ny = one * (-dx * sb[j]);
        p[0].x = prevX + nx;
        p[0].y = prevY + ny;
        p[0].z = prevZ;
        p[0].u = u0;
        p[0].v = vv;
        p[0].color = vertex_color;
        p[1].x = prevX - nx;
        p[1].y = prevY - ny;
        p[1].z = prevZ;
        prevZ = q->z;
        q++;
        p[1].u = one;
        p[1].v = vv;
        vv += one;
        p[1].color = vertex_color;
        p += 2;
        prevX = curX;
        prevY = curY;
    }
    nx = one * (dy * sa[point_count - 1]);
    ny = one * (-dx * sb[point_count - 1]);
    p[0].x = prevX + nx;
    p[0].y = prevY + ny;
    p[0].z = prevZ;
    p[0].u = 0.0f;
    p[0].v = vv;
    p[0].color = vertex_color;
    p[1].x = prevX - nx;
    p[1].y = prevY - ny;
    p[1].z = prevZ;
    p[1].u = one;
    p[1].v = vv;
    p[1].color = vertex_color;
    set_additive_blend();
    ((TWindowDD *)verts)->draw_transformed_primitive(point_count * 2, fake_tec_texture, 1);
    set_constant_material(&chunk_material_color_half_alpha_f32);
    model_render_flags = saved_model_render_flags;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TeneFakeTecThunderEff::run_task() {
    s32 i;
    if (active != 0) {
        build_beam_points();
        fake_tec_texture = fake_tec_texlist.textures[texture].texture->surface->id;
        for (i = 0; i < point_count; i++) {
            jitter[i] = 4.0f * (0.1f * sin_table_lookup(timer * 0x1800) + 0.2f);
        }
        for (i = 0; i < point_count; i++) {
            f32 s = jitter[i];
            points[i].x = jitter_dirs[i].x * s + base_points[i].x;
            points[i].y = jitter_dirs[i].y * s + base_points[i].y;
            points[i].z = jitter_dirs[i].z * s + base_points[i].z;
        }
        timer++;
    }
}
#pragma pop

TeneFakeTecThunderEff::~TeneFakeTecThunderEff() {}

TeneFakeTecThunderEff::TeneFakeTecThunderEff(TObject *parent, Vec *from, Vec *to, s32 point_count) : TObject(parent) {
    m_name = class_name;
    this->from = from;
    this->to = to;
    texture = 0;
    pad_334 = 0;
    target_point_count = point_count;
    build_beam_points();
    timer = 0;
    color = 0xFF000000;
    active = 0;
}
