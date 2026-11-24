#include "pso/system/BmlResource.h"
#include "pso/render/StripBufferPair.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/unk/text_803E2F28.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/render/StripBufferPair.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/object/city/CityTraffic.h"
#include "pso/object/city/CityTrafficTables.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/city/TObjCityAirCar_Car.h"
#include "pso/object/city/TObjCityAirCar_Ctrl.h"
#include "pso/unk/text_801811FC.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/math/FloatRounding.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/animation/MotionContext.h"
#include "pso/render/GinjaView.h"
#include "pso/unk/text_80184C2C.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/render/render_util.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/math/MatrixTransforms.h"


extern "C" {
s32 rotate_matrix_z(int, int);
s32 post_translate_matrix(void *);
}

extern "C" {
s32 vec3_add_to(void *, void *);
}


// Deferred TU: code is generated last-defined-first, so the functions are written in
// reverse address order (.text and the vtables then come out in the original order).

struct Info_80181698 { s32 f0; u32 n; };

typedef struct
{
  f32 x;
  f32 y;
  f32 z;
  f32 w;
} Quat_801817AC;


typedef struct
{
  f32 len[5];
  f32 ratio[5];
  s32 objs[5];
} Tbl_801817AC;

extern "C" {
BmlResource *city_air_car_model_resource;
NJS_TEXLIST *city_air_car_model_handle;
}

BmlResource *city_common_model_archive;
NJS_TEXLIST *city_common_texture_list;

#pragma defer_codegen on

const char *TObjCityAirCar_Ctrl__name = "TObjCityAirCar_Ctrl";
const char *TObjCityAirCar_Car__name = "TObjCityAirCar_Car";

f32 air_car_lane_spacing_table[5];
f32 air_car_lane_speed_scale_table[5];
StripBufferPair *air_car_buffer_pair_table[6];

NJS_OBJECT *get_city_common_model(s32 i) {
    return (NJS_OBJECT *)city_common_model_archive->models[i].model;
}
AnimationMotion *get_city_common_motion(s32 i) {
    return city_common_model_archive->motions[i].motion;
}

void measure_traffic_path_lengths(void) {
  Vec prev;
  Vec cur;
  Vec a;
  Vec b;
  Quat_801817AC q;
  Vec a2;
  Vec b2;
  Quat_801817AC q2;
  AnimationMotion *m;
  s32 i;
  s32 j;
  for (i = 0; i < 5; i++)
  {
    m = get_city_common_motion(city_traffic_path_motion_index_table[i]);
    f32 frame;
    f32 end = (m->frameCount - 1);
    frame = 0.0f;
    f32 total = frame;
    bind_motion_context((NJS_MOTION *)m, frame);
    sample_motion_node_transform(get_city_common_model(city_aircar_model_indices[i]), &prev.x, (s32 *)&a, &b.x, (f32 *)&q);
    for (frame += 0.5f; frame < end; frame += 0.5f)
    {
      bind_motion_context((NJS_MOTION *)m, frame);
      sample_motion_node_transform(get_city_common_model(city_aircar_model_indices[i]), &cur.x, (s32 *)&a2, &b2.x, (f32 *)&q2);
      subtract_vector(&prev, &cur);
      total += normalize_vector_safe(&prev);
      VecCopy((Vec *)&prev, (const Vec *)&cur);
    }
    air_car_lane_spacing_table[i] = total;
    air_car_lane_speed_scale_table[i] = end / total;
  }
  city_air_car_model_resource = 0;
  city_air_car_model_handle = 0;
  for (i = 0; i < 5; i++)
  {
    air_car_buffer_pair_table[i] = 0;
  }
  city_air_car_model_resource = get_season_model_resource(2);
  if (city_air_car_model_resource != 0)
  {
    city_air_car_model_handle = TLobby__sub_80184C2C(2);
    for (j = 0; j < 5; j++)
    {
      air_car_buffer_pair_table[j] = new StripBufferPair(city_air_car_model_resource->models[city_traffic_car_chunk_index_table[j]].model, 1);
    }
  }
}

void free_buffer_pair_table(void) {
    s32 i;
    for (i = 4; i >= 0; i--) {
        if (air_car_buffer_pair_table[i] != 0) {
            delete air_car_buffer_pair_table[i];
            air_car_buffer_pair_table[i] = 0;
        }
    }
}

s32 sample_aircar_path_position(s32 lane, void *pos, f32 frame) {
    Vec ang;
    Vec sp18;
    f32 quat[4];
    f32 lim;
    s32 r;
    Info_80181698 *m = ((Info_80181698 * (*)(s32))get_city_common_motion)(city_traffic_path_motion_index_table[lane]);
    u32 n = m->n;
    r = 1;
    lim = (n - 1);
    if (frame > lim) {
        frame = lim;
        r = 0;
    }
    bind_motion_context((NJS_MOTION *)m, frame);
    void *t = ((void * (*)(s32))get_city_common_model)(city_aircar_model_indices[lane]);
    sample_motion_node_transform((NJS_OBJECT *)t, (f32 *)pos, (s32 *)&ang, &sp18.x, quat);
    return r;
}

#pragma push
#pragma opt_propagation off
TObjCityAirCar_Ctrl::TObjCityAirCar_Ctrl(TObject *parent) : TObject(parent) {
    s32 i;
    s32 j;
    Lane *lane;
    m_name = TObjCityAirCar_Ctrl__name;
    pad_1C = 0;
    pad_20 = 0.0f;
    rare_car_counter = 0x14;
    for (i = 0; i < 5; i++) {
        lane = &lanes[i];
        lane->timer = 0;
        lane->count = 0;
        for (j = 0; j < 2; j++) {
            lane->cars[j] = NULL;
        }
    }
}
#pragma pop

TObjCityAirCar_Ctrl::~TObjCityAirCar_Ctrl() {

}


void TObjCityAirCar_Ctrl::run_task() {
    s32 i;
    Lane *r;
    s32 timer;
    s32 count;
    s32 j;
    s32 k;
    s32 type;
    f32 speed;
    TObjCityAirCar_Car *last;
    for (i = 0; i < 5; i++) {
        r = &lanes[i];
        count = r->count;
        timer = r->timer;
        for (j = 0; j < count; j++) {
            if (r->cars[j] == NULL || r->cars[j]->all_parents_unqueued_for_destruction() == 0) {
                count--;
                for (k = j; k < count; k++) {
                    r->cars[k] = r->cars[k + 1];
                }
                r->cars[count] = NULL;
                j--;
            }
        }
        if (count < 2 && --timer <= 0) {
            timer = lerp__9TDeadSpotFff(180.0f, 900.0f);
            if (i == 0 || i == 1) {
                type = floor_to_float(5.0f * (3.0517578e-5f * rand()));
            } else {
                type = (s32)floor_to_float(4.0f * (3.0517578e-5f * rand())) + 1;
            }
            if (i == 1 || i == 2) {
                rare_car_counter++;
                if (type == 4) {
                    if (rare_car_counter >= 40) {
                        rare_car_counter = 0;
                    } else {
                        type = 2;
                    }
                }
            }
            speed = air_car_lane_speed_scale_table[i] * lerp__9TDeadSpotFff(2.0f, 5.0f);
            if (count > 0) {
                last = r->cars[count - 1];
                if (fn_80181204(last) < 0.5f * air_car_lane_spacing_table[i]) {
                    speed = fn_801811FC(last);
                }
            }
            r->cars[count++] = new TObjCityAirCar_Car(this, i, type, speed);
        }
        r->count = count;
        r->timer = timer;
    }
}

void TObjCityAirCar_Ctrl::render() {  }


TObjCityAirCar_Car::TObjCityAirCar_Car(TObject *parent, s32 lane, s32 model_type, f32 path_speed) : TObjBase(parent) {
    m_name = TObjCityAirCar_Car__name;
    path_frame = 0.0f;
    this->lane = lane;
    this->model_type = model_type;
    this->path_speed = path_speed;
    uv_scroll = 0;
    light_blink = 0;
    light = NULL;
    update_path_motion();
    rotation_z = 0;
}

TObjCityAirCar_Car::~TObjCityAirCar_Car() {
    if (light != NULL) {
        light->queue_destruction();
    }
}


f32 fn_80181204(void* p) { return *(f32*)((char*)p + 0x90); }
f32 fn_801811FC(void* p) { return *(f32*)((char*)p + 0x94); }

#pragma push
#pragma fp_contract on
s32 TObjCityAirCar_Car::update_path_motion() {
    Vec a;
    Vec b;
    s32 ang;
    s32 ok;
    s32 d;
    s32 p;
    s32 r;
    sample_aircar_path_position(lane, &a, path_frame);
    ok = sample_aircar_path_position(lane, &b, 2.0f + path_frame);
    VecCopy(&position, &b);
    vec3_add_to(&position, &a);
    position.x *= 0.5f;
    position.y *= 0.5f;
    position.z *= 0.5f;
    ang = 10430.38043493439 * atan2_float(b.x - a.x, b.z - a.z);
    d = angle_diff_s16(rotation_y, ang);
    rotation_y = ang;
    p = rotation_z;
    r = rotation_x;
    if (d > 0x30) {
        if (r > 0) {
            r = 0;
        }
        r -= 0x40;
        if (r < -0x200) {
            r = -0x200;
        }
        p += r;
        if (p < -0x3800) {
            p = -0x3800;
        }
    } else if (d < -0x30) {
        if (r < 0) {
            r = 0;
        }
        r += 0x40;
        if (r > 0x200) {
            r = 0x200;
        }
        p += r;
        if (p > 0x3800) {
            p = 0x3800;
        }
    } else {
        r = 0;
        if (p > 0x100) {
            p -= 0x100;
        } else if (p < -0x100) {
            p += 0x100;
        } else {
            p = 0;
        }
    }
    rotation_z = p;
    rotation_x = r;
    return ok;
}
void TObjCityAirCar_Car::run_task() {
    Vec v;
    f32 scale;
    path_frame += path_speed;
    if (this->update_path_motion() == 0) {
        queue_destruction();
    }
    if ((lane == 1 && path_frame >= 15.5f && path_frame <= 35.5f) ||
        (lane == 2 && path_frame >= 15.0f && path_frame <= 35.0f)) {
        if (model_type == 4) {
            play_persistent_sound(0x4004CB02, this, &position, 0, 0);
        } else if (model_type == 0) {
            set_sound_pitch_request(play_persistent_sound(0x4004C101, this, &position, 0, 0), -0x200, 0);
        } else {
            play_persistent_sound(0x4004C101, this, &position, 0, 0);
        }
    }
    if (city_air_car_model_resource != 0) {
        uv_scroll -= 0xA;
        if (uv_scroll < 0) {
            uv_scroll += 0x100;
        }
        light_blink++;
        if (light_blink >= 0x28) {
            light_blink = 0;
        }
        if (light == 0) {
            light = spawn_continuous_particle_effect_with_flags(&position, 0x8A, 0x40);
        }
        if (light != 0) {
            if (model_type == 0) {
                scale = 20.0f;
            } else {
                scale = 10.0f;
            }
            VecCopy(&v, &position);
            v.x -= scale * sin_table_lookup(rotation_y);
            v.z -= scale * cos_table_lookup(rotation_y);
            light->set_position(&v);
        }
    }
}

#pragma pop

void TObjCityAirCar_Car::render() {
    u32 texture_index;
    NJS_TEXNAME *texture_entries;
    if (this->update_object_view_visibility(800.0f, 50.0f) != 0) {
        TParticleCtrl::end_effect_render();
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, this->rotation_y);
        if (model_type != 0) {
            rotate_matrix_z(0, this->rotation_z);
        }
        TObjFish::set_global_param(city_common_texture_list);
        draw_chunk_object(get_city_common_model(city_aircar_model_indices[model_type]));
        TParticleCtrl::begin_effect_render();
        draw_ginja_object(get_city_common_model(city_air_car_model_index_table[model_type]));
        if (city_air_car_model_resource != NULL) {
            texture_entries = city_air_car_model_handle->textures;
            texture_index = texture_entries[2].global_index;
            if (light_blink >= 0x14) {
                texture_entries[2].global_index = texture_entries[0].global_index;
            }
            TObjFish::set_global_param(city_air_car_model_handle);
            air_car_buffer_pair_table[model_type]->scroll_uvs(uv_scroll, 0);
            draw_chunk_object((void *)city_air_car_model_resource->models[city_traffic_car_chunk_index_table[model_type]].model);
            city_air_car_model_handle->textures[2].global_index = texture_index;
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}
