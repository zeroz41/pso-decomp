#include "pso/system/BmlResource.h"
#include "pso/render/StripBufferPair.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/unk/text_803E2F28.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/object/city/CityTraffic.h"
#include "pso/object/city/CityTrafficTables.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/city/TObjCityAirCar_Car.h"
#include "pso/object/city/TObjCityAirCar_Ctrl.h"
#include "pso/unk/text_801811FC.h"
#include "pso/unk/text_80181278.h"
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
#include "pso/unk/text_80087278.h"
#include "pso/render/render_util.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/math/MatrixTransforms.h"


extern "C" {
s32 rotate_matrix_z(int, int);
s32 post_translate_matrix(void *);
}

struct Car_80180E70 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 yaw;
    u8 pad64[0x90 - 0x64];
    f32 frame;
    f32 speed;
    s32 path;
    s32 model;
    s32 fa0;
    s32 fa4;
    uaddr light;
};

struct Car_80181074 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x5C - 0x44];
    s32 roll;
    s32 heading;
    s32 yaw;
    u8 pad68[0x90 - 0x68];
    f32 frame;
    f32 speed;
    s32 path;
};

extern "C" {
s32 vec3_add_to(void *, void *);
}

struct RecoveredGlobal_80181278_lbl_804B5908 {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {
u8 * __ct__8TObjBaseFP7TObject(void *);
extern RecoveredGlobal_80181278_lbl_804B5908 __vt__18TObjCityAirCar_Car;
}

struct Rec_80181310 { s32 timer; s32 count; void *objs[2]; };

struct Ctrl_80181310 { u8 pad0[0x24]; s32 counter; Rec_80181310 recs[5]; };

extern "C" {
void run_task__19TObjCityAirCar_CtrlFv(Ctrl_80181310 *self);
}

// Deferred TU: code is generated last-defined-first, so the functions are written in
// reverse address order (.text and the vtables then come out in the original order).

struct Rec_801815F8 { s32 a; s32 b; s32 c[2]; };

struct Obj_801815F8 { const char *name; u8 pad0[0x14]; u8 *vptr; s32 f1C; f32 f20; s32 f24; Rec_801815F8 recs[5]; };

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
void __ct__7TObjectFP7TObject(void *);
extern u8 __vt__19TObjCityAirCar_Ctrl[];
BmlResource *city_air_car_model_resource;
GinjaTextureList *city_air_car_model_handle;
}

BmlResource *city_common_model_archive;
GinjaTextureList *city_common_texture_list;

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

s32 sample_aircar_path_position(s32 arg0, void *arg1, f32 frame) {
    Vec sp24;
    Vec sp18;
    f32 sp8[4];
    f32 lim;
    s32 r;
    Info_80181698 *m = ((Info_80181698 * (*)(s32))get_city_common_motion)(city_traffic_path_motion_index_table[arg0]);
    u32 n = m->n;
    r = 1;
    lim = (n - 1);
    if (frame > lim) {
        frame = lim;
        r = 0;
    }
    bind_motion_context((NJS_MOTION *)m, frame);
    void *t = ((void * (*)(s32))get_city_common_model)(city_aircar_model_indices[arg0]);
    sample_motion_node_transform((NJS_OBJECT *)t, (f32 *)arg1, (s32 *)&sp24, &sp18.x, sp8);
    return r;
}

extern "C" {
#pragma push
#pragma opt_propagation off
Obj_801815F8 *construct_traffic_manager(Obj_801815F8 *arg0) {
    s32 i;
    s32 j;
    s32 off;
    Rec_801815F8 *r;
    s32 o;
    __ct__7TObjectFP7TObject(arg0);
    arg0->vptr = __vt__19TObjCityAirCar_Ctrl;
    arg0->name = TObjCityAirCar_Ctrl__name;
    arg0->f1C = 0;
    arg0->f20 = 0.0f;
    arg0->f24 = 0x14;
    for (i = 0; i < 5; i++) {
        r = &arg0->recs[i];
        r->a = 0;
        r->b = 0;
        for (j = 0; j < 2; j++) {
            r->c[j] = 0;
        }
    }
    return arg0;
}
}
#pragma pop

TObjCityAirCar_Ctrl::~TObjCityAirCar_Ctrl() {

}


void run_task__19TObjCityAirCar_CtrlFv(Ctrl_80181310 *self) {
    s32 i;
    Rec_80181310 *r;
    s32 timer;
    s32 count;
    s32 j;
    s32 k;
    s32 type;
    f32 speed;
    void *last;
    void *o;
    for (i = 0; i < 5; i++) {
        r = &self->recs[i];
        count = r->count;
        timer = r->timer;
        for (j = 0; j < count; j++) {
            if (r->objs[j] == NULL || ((TObject *)(r->objs[j]))->all_parents_unqueued_for_destruction() == 0) {
                count--;
                for (k = j; k < count; k++) {
                    r->objs[k] = r->objs[k + 1];
                }
                r->objs[count] = NULL;
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
                self->counter++;
                if (type == 4) {
                    if (self->counter >= 40) {
                        self->counter = 0;
                    } else {
                        type = 2;
                    }
                }
            }
            speed = air_car_lane_speed_scale_table[i] * lerp__9TDeadSpotFff(2.0f, 5.0f);
            if (count > 0) {
                last = r->objs[count - 1];
                if (fn_80181204(last) < 0.5f * air_car_lane_spacing_table[i]) {
                    speed = fn_801811FC(last);
                }
            }
            o = TObject::operator new(0xAC);
            if (o != NULL) {
                o = construct_city_air_car((TObjCityAirCar_Car *)o, self, i, type, speed);
            }
            r->objs[count++] = o;
        }
        r->count = count;
        r->timer = timer;
    }
}

void TObjCityAirCar_Ctrl::render() {  }


u8 *construct_city_air_car(TObjCityAirCar_Car *city_air_car_car, void *parent, s32 arg2, s32 type, f32 farg0) {
    __ct__8TObjBaseFP7TObject(city_air_car_car);
    *(s32 **)((s8 *)city_air_car_car + 0x18) = &__vt__18TObjCityAirCar_Car.value;
    city_air_car_car->m_name = TObjCityAirCar_Car__name;
    *(f32 *)((s8 *)city_air_car_car + 0x90) = 0.0f;
    *(s32 *)((s8 *)city_air_car_car + 0x98) = arg2;
    city_air_car_car->m_9c = type;
    city_air_car_car->m_94 = farg0;
    *(s32 *)((s8 *)city_air_car_car + 0xA0) = 0;
    city_air_car_car->m_a4 = 0;
    *(s32 *)((s8 *)city_air_car_car + 0xA8) = 0;
    city_air_car_car->update_path_motion();
    city_air_car_car->rotation_z = 0;
    return (u8 *)city_air_car_car;
}

TObjCityAirCar_Car::~TObjCityAirCar_Car() {
    if (unk_A8 != NULL) {
        unk_A8->queue_destruction();
    }
}


f32 fn_80181204(void* p) { return *(f32*)((char*)p + 0x90); }
f32 fn_801811FC(void* p) { return *(f32*)((char*)p + 0x94); }

#pragma push
#pragma fp_contract on
struct Car_80181074;
s32 TObjCityAirCar_Car::update_path_motion() {
    Car_80181074 *self = (Car_80181074 *)this;
    Vec a;
    Vec b;
    s32 ang;
    s32 ok;
    s32 d;
    s32 p;
    s32 r;
    sample_aircar_path_position(self->path, &a, self->frame);
    ok = sample_aircar_path_position(self->path, &b, 2.0f + self->frame);
    VecCopy((Vec *)&self->pos, (const Vec *)&b);
    vec3_add_to(&self->pos, &a);
    self->pos.x *= 0.5f;
    self->pos.y *= 0.5f;
    self->pos.z *= 0.5f;
    ang = 10430.38043493439 * atan2_float(b.x - a.x, b.z - a.z);
    d = angle_diff_s16(self->heading, ang);
    self->heading = ang;
    p = self->yaw;
    r = self->roll;
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
    self->yaw = p;
    self->roll = r;
    return ok;
}
void TObjCityAirCar_Car::run_task() {
    Vec v;
    f32 scale;
    f32 t;
    t = ((Car_80180E70 *)this)->frame;
    ((Car_80180E70 *)this)->frame = t + ((Car_80180E70 *)this)->speed;
    if (this->update_path_motion() == 0) {
        queue_destruction();
    }
    if ((((Car_80180E70 *)this)->path == 1 && ((Car_80180E70 *)this)->frame >= 15.5f && ((Car_80180E70 *)this)->frame <= 35.5f) ||
        (((Car_80180E70 *)this)->path == 2 && ((Car_80180E70 *)this)->frame >= 15.0f && ((Car_80180E70 *)this)->frame <= 35.0f)) {
        if (((Car_80180E70 *)this)->model == 4) {
            play_persistent_sound(0x4004CB02, (saddr)((Car_80180E70 *)this), (uaddr)&((Car_80180E70 *)this)->pos, 0, 0);
        } else if (((Car_80180E70 *)this)->model == 0) {
            set_sound_pitch_request(play_persistent_sound(0x4004C101, (saddr)((Car_80180E70 *)this), (uaddr)&((Car_80180E70 *)this)->pos, 0, 0), -0x200, 0);
        } else {
            play_persistent_sound(0x4004C101, (saddr)((Car_80180E70 *)this), (uaddr)&((Car_80180E70 *)this)->pos, 0, 0);
        }
    }
    if (city_air_car_model_resource != 0) {
        ((Car_80180E70 *)this)->fa0 -= 0xA;
        if (((Car_80180E70 *)this)->fa0 < 0) {
            ((Car_80180E70 *)this)->fa0 += 0x100;
        }
        ((Car_80180E70 *)this)->fa4++;
        if (((Car_80180E70 *)this)->fa4 >= 0x28) {
            ((Car_80180E70 *)this)->fa4 = 0;
        }
        if (((Car_80180E70 *)this)->light == 0) {
            ((Car_80180E70 *)this)->light = (uaddr)spawn_continuous_particle_effect_with_flags(&((Car_80180E70 *)this)->pos, 0x8A, 0x40);
        }
        if (((Car_80180E70 *)this)->light != 0) {
            if (((Car_80180E70 *)this)->model == 0) {
                scale = 20.0f;
            } else {
                scale = 10.0f;
            }
            VecCopy((Vec *)&v, (const Vec *)&((Car_80180E70 *)this)->pos);
            v.x -= scale * sin_table_lookup(((Car_80180E70 *)this)->yaw);
            v.z -= scale * cos_table_lookup(((Car_80180E70 *)this)->yaw);
            ((TParticleCtrl *)((Car_80180E70 *)this)->light)->set_position(&v);
        }
    }
}

#undef self
#pragma pop

void TObjCityAirCar_Car::render() {
    u32 texture_index;
    GinjaTextureEntry *texture_entries;
    if (this->update_object_view_visibility(800.0f, 50.0f) != 0) {
        TParticleCtrl::end_effect_render();
        push_matrix();
        post_translate_matrix((void *) ((u8 *)this + 0x38));
        rotate_matrix_y(0, this->rotation_y);
        if ((s32) this->m_9c != 0) {
            rotate_matrix_z(0, this->rotation_z);
        }
        TObjFish::set_global_param(city_common_texture_list);
        draw_chunk_object(get_city_common_model(city_aircar_model_indices[this->m_9c]));
        TParticleCtrl::begin_effect_render();
        draw_ginja_object(get_city_common_model(city_air_car_model_index_table[this->m_9c]));
        if (city_air_car_model_resource != NULL) {
            texture_entries = city_air_car_model_handle->entries;
            texture_index = texture_entries[2].global_index;
            if ((s32) this->m_a4 >= 0x14) {
                texture_entries[2].global_index = texture_entries[0].global_index;
            }
            TObjFish::set_global_param(city_air_car_model_handle);
            air_car_buffer_pair_table[this->m_9c]->scroll_uvs(*(s32 *)((s8 *)this + 0xA0), 0);
            draw_chunk_object((void *)city_air_car_model_resource->models[city_traffic_car_chunk_index_table[this->m_9c]].model);
            city_air_car_model_handle->entries[2].global_index = texture_index;
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}
