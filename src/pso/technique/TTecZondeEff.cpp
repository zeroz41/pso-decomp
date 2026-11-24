#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/technique/TTecZondeEff.h"
#include "pso/effect/particle/ParticleStrip.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/render/render_util.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/render/GinjaView.h"
#include "pso/effect/TEffect.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/render/model_render_state.h"
#include "pso/unk/text_803D853C.h"
#include "pso/technique/TechniqueRingwaveList.h"


#pragma readonly_strings on

const char *TTecZondeEff_class_name = "TTecZondeEff";
NJS_TEXLIST tec_zonde_texture_list;
s32 TTecZondeEff__beam_vertex_data;



#pragma push
#pragma fp_contract on

#pragma fp_contract on
s32 TTecZondeEff::build_lightning_strip(ParticleStripVertex *out, Vec *pts, f32 *widths, f32 *heights) {
  f32 px;
  f32 py;
  f32 pz;
  f32 nx;
  f32 ny;
  f32 dx;
  f32 dy;
  f32 v;
  f32 inv;
  f32 ox;
  f32 oy;
  f32 scale;
  u32 color;
  ParticleStripVertex *o;
  Vec *p;
  s32 i;
  v = 0.0f;
  scale = 1.0f;
  px = pts->x;
  py = pts->y;
  pz = pts->z;
  color = 0xFFFFFF | power;
  p = pts + 1;
  o = out;
  for (i = 0; i < (point_count - 1); i++)
  {
    ny = p->y;
    nx = p->x;
    dy = ny - py;
    dx = nx - px;
    if (((dx * dx) + (dy * dy)) == 0.0f)
    {
      return 0;
    }
    inv = 1.0f / newton_sqrtf((dx * dx) + (dy * dy));
    dx *= inv;
    dy *= inv;
    ox = scale * (dy * widths[i]);
    oy = scale * ((-dx) * heights[i]);
    o[0].x = px + ox;
    o[0].y = py + oy;
    o[0].z = pz;
    o[0].u = 0.0f;
    o[0].v = v;
    o[0].color = color;
    o[1].x = px - ox;
    o[1].y = py - oy;
    o[1].z = pz;
    o[1].u = 1.0f;
    o[1].v = v;
    v += 1.0f;
    o[1].color = color;
    o += 2;
    px = nx;
    py = ny;
    pz = p->z;
    p++;
  }
  ox = scale * (dy * widths[point_count - 1]);
  oy = scale * ((-dx) * heights[point_count - 1]);
  o[0].x = px + ox;
  o[0].y = py + oy;
  o[0].z = pz;
  o[0].u = 0.0f;
  o[0].v = v;
  o[0].color = color;
  o[1].x = px - ox;
  o[1].y = py - oy;
  o[1].z = pz;
  o[1].u = 1.0f;
  o[1].v = v;
  o[1].color = color;
  return 1;
}

s32 TTecZondeEff::project_lightning_points(Vec *out, f32 *strip_widths, f32 *strip_heights) {
  f32 sy0;
  f32 sx0;
  f32 cx;
  f32 cy;
  s32 i;
  sy0 = screen_projection.distance;
  sx0 = screen_projection.distance * (480.0f / (480.0f * screen_projection.width));
  cx = screen_projection.center_x;
  cy = screen_projection.center_y;
  for (i = 0; i < point_count; i++)
  {
    Vec v;
    f32 w;
    f32 sx;
    f32 sy;
    matrix_mult_vec(0, &points[i], &v);
    if (v.z >= 1.0f)
    {
      scale = scale;
      v.z = 1.0f;
    }
    w = 1.0f / (-v.z);
    v.y = -v.y;
    sx = sx0 * w;
    sy = sy0 * w;
    out[i].x = (v.x * sx) + cx;
    out[i].y = (v.y * sy) + cy;
    out[i].z = w;
    strip_widths[i] = sx * scale;
    strip_heights[i] = 1.8f * sy;
  }
  return 1;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TTecZondeEff::calc_lightning_scatter_direction(s32 axis, Vec *out) {

    switch (axis) {
    case 0: {
        f32 a, inv, q, p, b;
        inv = 1.0f / direction.x;
        p = direction.y;
        q = direction.z;
        a = 10.0f * rand_signed_unit();
        b = 10.0f * rand_signed_unit();
        out->y = a;
        out->z = b;
        out->x = inv * (a * p + b * q);
        normalize_vector_safe(out);
        break;
    }
    case 1: {
        f32 a, inv, q, p, b;
        inv = 1.0f / direction.y;
        p = direction.z;
        q = direction.x;
        a = 10.0f * rand_signed_unit();
        b = 10.0f * rand_signed_unit();
        out->z = a;
        out->x = b;
        out->y = inv * (a * p + b * q);
        normalize_vector_safe(out);
        break;
    }
    case 2: {
        f32 a, inv, q, p, b;
        inv = 1.0f / direction.z;
        p = direction.x;
        q = direction.y;
        a = 10.0f * rand_signed_unit();
        b = 10.0f * rand_signed_unit();
        out->x = a;
        out->y = b;
        out->z = inv * (a * p + b * q);
        normalize_vector_safe(out);
        break;
    }
    }
}
#pragma pop


s32 TTecZondeEff::calc_dominant_axis() {
    f32 temp_f1;
    f32 temp_f30;
    f32 temp_f31;

    temp_f30 = fabs_float(this->direction.x);
    temp_f31 = fabs_float(this->direction.y);
    temp_f1 = fabs_float(this->direction.z);
    if (temp_f30 > temp_f31) {
        if (temp_f30 > temp_f1) {
            return 0;
        }
        return 2;
    }
    if (temp_f31 > temp_f1) {
        return 1;
    }
    return 2;
}

void TTecZondeEff::randomize_bolt_jitter() {
    Vec *dir;
    s32 axis;
    s32 i;
    f32 k;
    axis = calc_dominant_axis();
    dir = jitter_dirs;
    for (i = 0; i < point_count; i++, dir++) {
        calc_lightning_scatter_direction(axis, dir);
    }
    k = 8.0f;
    for (i = 1; i < point_count - 1; i++) {
        widths[i] = k * rand_signed_unit();
    }
    widths[0] = 0.0f;
    widths[point_count - 1] = 0.0f;
}

#pragma push
#pragma fp_contract on
void TTecZondeEff::init_bolt_points() {
    f32 x0 = origin.x;
    f32 y0 = origin.y;
    f32 z0 = origin.z;
    f32 dx = direction.x;
    f32 dy = direction.y;
    f32 dz = direction.z;
    s32 i;
    for (i = 0; i < point_count; i++) {
        f32 t = (length * (f32)i) / (point_count - 1);
        base_points[i].x = dx * t + x0;
        base_points[i].y = dy * t + y0;
        base_points[i].z = dz * t + z0;
        if (is_split_screen() == 0) {
            spawn_particle_effect(&base_points[i], 0x1F0);
        }
    }
}
#pragma pop

void TTecZondeEff::render() {
    ParticleStripVertex verts[26];
    Vec screen_points[13];
    f32 strip_widths[13];
    f32 strip_heights[13];
    u32 id;
    if (active == 0 || get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_LOBBY) {
        return;
    }
    if (all_parents_unqueued_for_destruction() == 0) {
        return;
    }
    id = model_render_flags;
    saved_model_render_flags = id;
    model_render_flags = id | 0x10;
    TParticleCtrl::begin_effect_render();
    set_depth_buffer_settings_1();
    if (project_lightning_points(screen_points, strip_widths, strip_heights) != 0 && build_lightning_strip(verts, screen_points, strip_widths, strip_heights) != 0) {
        set_additive_blend();
        ((TWindowDD *)verts)->draw_transformed_primitive(point_count * 2, TTecZondeEff__beam_vertex_data, 1);
        set_default_alpha_blend();
    }
    TParticleCtrl::end_effect_render();
    set_constant_material(&chunk_material_color_half_alpha_f32);
    model_render_flags = saved_model_render_flags;
    restore_saved_depth_alpha_state();
}

#pragma push
#pragma fp_contract on
void TTecZondeEff::run_task() {
    s32 i;
    f32 s;
    TTecZondeEff__beam_vertex_data = tec_zonde_texture_list.textures[idx].texture->surface->id;
    if (timer > 0x78) {
        queue_destruction();
        return;
    }
    for (i = 0; i < point_count; i++) {
        widths[i] -= 0.05f;
        if (widths[i] <= 1.0f) {
            widths[i] = 1.0f;
        }
    }
    for (i = 0; i < point_count; i++) {
        s = widths[i];
        points[i].x = jitter_dirs[i].x * s + base_points[i].x;
        points[i].y = jitter_dirs[i].y * s + base_points[i].y;
        points[i].z = jitter_dirs[i].z * s + base_points[i].z;
    }
    active = 1;
    if (timer > start) {
        if (power > decay) {
            power -= decay;
            if ((f32)power <= 0.0f) {
                power = 0;
            }
        } else {
            power = 0;
            timer = 0x79;
        }
    }
    timer++;
}
#pragma pop

TTecZondeEff::~TTecZondeEff() {}
TTecZondeEff::TTecZondeEff(TObject *parent, s32 decay, s32 start, f32 scale) : TObject(parent) {
    m_name = TTecZondeEff_class_name;
    this->scale = scale;
    this->decay = decay;
    this->start = start;
    idx = 0;
    frame = 0;
    point_count = 13;
    timer = 0;
    power = 0xFF000000;
    active = 0;
}

TTecZondeEff::TTecZondeEff(TObject *parent, Vec *from, Vec *dir, s32 decay, s32 start, f32 length, f32 scale) : TObject(parent) {
    m_name = TTecZondeEff_class_name;
    this->scale = scale;
    this->decay = decay;
    this->start = start;
    VecCopy(&origin, from);
    VecCopy(&direction, dir);
    this->length = length;
    idx = 0;
    frame = 0;
    point_count = 13;
    init_bolt_points();
    randomize_bolt_jitter();
    timer = 0;
    power = 0xFF000000;
    active = 0;
}

TTecZondeEff::TTecZondeEff(TObject *parent, Vec *from, Vec *dir, f32 length) : TObject(parent) {
    m_name = TTecZondeEff_class_name;
    scale = 1.0f;
    decay = 0x08000000;
    start = 0x14;
    VecCopy(&origin, from);
    VecCopy(&direction, dir);
    this->length = length;
    idx = 0;
    frame = 0;
    point_count = 13;
    init_bolt_points();
    randomize_bolt_jitter();
    timer = 0;
    power = 0xFF000000;
    active = 0;
}

void clear_zonde_beam_vertex_pointer(void) {
    TTecZondeEff__beam_vertex_data = 0;
}
void TTecZondeEff::init_resources() {
    tec_zonde_texture_list.textures = technique_ringwave_texnames;
    tec_zonde_texture_list.nbTexture = 0x10;
    TTecZondeEff__beam_vertex_data = shared_effect_texture_list.textures[16].texture->surface->id;
}
