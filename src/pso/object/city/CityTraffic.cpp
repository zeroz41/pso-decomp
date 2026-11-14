#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/object/city/CityTraffic.h"
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
#include "pso/camera/TCameraCtrl_803D6538.h"
#include "pso/unk/text_80184C2C.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/unk/text_80087278.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Rec16_80180D18 { s32 f0; s32 f4; s32 f8; s32 fc; };

extern "C" {
s32 scroll_strip_uvs(void *, s16, int);
s32 rotate_matrix_z(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
s32 draw_ginja_object();
s32 draw_chunk_object(int, void *);
extern s32 city_air_car_model_index_table[];
extern void **city_common_texture_list;
}
struct Vec_80180E70 { f32 x, y, z; };

struct Car_80180E70 {
    u8 pad0[0x38];
    Vec_80180E70 pos;
    u8 pad44[0x60 - 0x44];
    s32 yaw;
    u8 pad64[0x90 - 0x64];
    f32 frame;
    f32 speed;
    s32 path;
    s32 model;
    s32 fa0;
    s32 fa4;
    u32 light;
};

struct Vec_80181074 { f32 x, y, z; };

struct Car_80181074 {
    u8 pad0[0x38];
    Vec_80181074 pos;
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
s32 update_technique_slot__10TTecRaFoieFl(s32, int, int);
s32 vec3_add_to(void *, void *);
}

struct RecoveredGlobal_80181278_lbl_804B5908 {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {
void __dl__7TObjectFPv(void *);
u8 * __ct__8TObjBaseFP7TObject(void *);
extern RecoveredGlobal_80181278_lbl_804B5908 __vt__18TObjCityAirCar_Car;
extern s32 TObjCityAirCar_Car__name;
typedef char RecoveredGlobal_80181278_lbl_804B5908_size[sizeof(RecoveredGlobal_80181278_lbl_804B5908) == 0x34 ? 1 : -1];
}

struct Rec_80181310 { s32 timer; s32 count; void *objs[2]; };

struct Ctrl_80181310 { u8 pad0[0x24]; s32 counter; Rec_80181310 recs[5]; };

extern "C" {
void *__nw__7TObjectFUl(u32);
void run_task__19TObjCityAirCar_CtrlFv(Ctrl_80181310 *self);
}

// Deferred TU: code is generated last-defined-first, so the functions are written in
// reverse address order (.text and the vtables then come out in the original order).

struct Rec_801815F8 { s32 a; s32 b; s32 c[2]; };

struct Obj_801815F8 { s32 f00; u8 pad0[0x14]; u8 *vptr; s32 f1C; f32 f20; s32 f24; Rec_801815F8 recs[5]; };

struct Info_80181698 { s32 f0; u32 n; };

struct V3_80181698 { f32 x; f32 y; f32 z; };

typedef struct
{
  f32 x;
  f32 y;
  f32 z;
} Vec_801817AC;

typedef struct
{
  f32 x;
  f32 y;
  f32 z;
  f32 w;
} Quat_801817AC;

typedef struct
{
  u32 pad0;
  u32 count;
} Motion_801817AC;

typedef struct
{
  s32 pad0;
  s32 pad4;
  s32 f8;
  s32 padC;
} Ent_801817AC;

typedef struct
{
  u8 pad[0x42C];
  Ent_801817AC *entries;
} Lob_801817AC;

typedef struct
{
  f32 len[5];
  f32 ratio[5];
  s32 objs[5];
} Tbl_801817AC;

void *destroy_buffer_pair(void *arg0, s16 arg1);
extern "C" {
void __ct__7TObjectFP7TObject(void *);
extern u8 __vt__19TObjCityAirCar_Ctrl[];
extern s32 TObjCityAirCar_Ctrl__name;
extern s32 city_traffic_path_motion_index_table[];
extern s32 city_aircar_model_indices[];
s32 alloc_tables__6TLobbyFll(s32, s32, s32, Ent_801817AC *);
void subtract_vector(Vec_801817AC *, Vec_801817AC *);
extern s32 city_traffic_car_chunk_index_table[];
Lob_801817AC * city_air_car_model_resource;
void ** city_air_car_model_handle;
}

struct E_801819CC { s32 a; s32 b; };

struct O_801819CC { u8 pad[0x430]; E_801819CC *entries; };

struct E_801819E4 { s32 a; s32 b; s32 c; s32 d; };

struct O_801819E4 { u8 pad[0x42c]; E_801819E4 *entries; };

extern O_801819CC *city_common_model_archive;

#pragma defer_codegen on

f32 air_car_lane_spacing_table[5];
f32 air_car_lane_speed_scale_table[5];
void *air_car_buffer_pair_table[6];

s32 get_city_common_model(s32 i) {
    return (*(O_801819E4 * *)&city_common_model_archive)->entries[i].c;
}
s32 get_city_common_motion(s32 i) {
    return city_common_model_archive->entries[i].b;
}

void measure_traffic_path_lengths(void) {
  Vec_801817AC prev;
  Vec_801817AC cur;
  Vec_801817AC a;
  Vec_801817AC b;
  Quat_801817AC q;
  Vec_801817AC a2;
  Vec_801817AC b2;
  Quat_801817AC q2;
  Motion_801817AC *m;
  s32 i;
  s32 j;
  s32 *new_var;
  s32 p;
  for (i = 0; i < 5; i++)
  {
    m = (Motion_801817AC *) get_city_common_motion(city_traffic_path_motion_index_table[i]);
    f32 frame;
    f32 end = (m->count - 1);
    frame = 0.0f;
    f32 total = frame;
    bind_motion_context((NJS_MOTION *)m, frame);
    sample_motion_node_transform((void *)(get_city_common_model(city_aircar_model_indices[i])), (void *)&prev, (void *)&a, (void *)&b, (void *)&q);
    for (frame += 0.5f; frame < end; frame += 0.5f)
    {
      bind_motion_context((NJS_MOTION *)m, frame);
      sample_motion_node_transform((void *)(get_city_common_model(city_aircar_model_indices[i])), (void *)&cur, (void *)&a2, (void *)&b2, (void *)&q2);
      subtract_vector(&prev, &cur);
      total += ((TObjBoss2Tunnel *)(&prev))->update_scale();
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
  city_air_car_model_resource = (Lob_801817AC *)get_season_model_resource(2);
  if (city_air_car_model_resource != 0)
  {
    city_air_car_model_handle = (void **)TLobby__sub_80184C2C(2);
    for (j = 0; j < 5; j++)
    {
      p = (int)::operator new(0x14);
      new_var = city_traffic_car_chunk_index_table;
      if (p != 0)
      {
        p = alloc_tables__6TLobbyFll(p, city_air_car_model_resource->entries[new_var[j]].f8, 1, city_air_car_model_resource->entries);
      }
      air_car_buffer_pair_table[j] = (void *)p;
    }
  }
}

void free_buffer_pair_table(void) {
    s32 i;
    for (i = 4; i >= 0; i--) {
        if (air_car_buffer_pair_table[i] != 0) {
            destroy_buffer_pair(air_car_buffer_pair_table[i], 1);
            air_car_buffer_pair_table[i] = 0;
        }
    }
}

s32 sample_aircar_path_position(s32 arg0, void *arg1, f32 farg0) {
    V3_80181698 sp24;
    V3_80181698 sp18;
    f32 sp8[4];
    f32 lim;
    s32 r;
    Info_80181698 *m = ((Info_80181698 * (*)(s32))get_city_common_motion)(city_traffic_path_motion_index_table[arg0]);
    u32 n = m->n;
    r = 1;
    lim = (n - 1);
    if (farg0 > lim) {
        farg0 = lim;
        r = 0;
    }
    bind_motion_context((NJS_MOTION *)m, farg0);
    void *t = ((void * (*)(s32))get_city_common_model)(city_aircar_model_indices[arg0]);
    sample_motion_node_transform(t, arg1, &sp24, &sp18, &sp8);
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
    arg0->f00 = TObjCityAirCar_Ctrl__name;
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

extern "C" {
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
            o = __nw__7TObjectFUl(0xAC);
            if (o != NULL) {
                o = construct_city_air_car((TObjCityAirCar_Car *)o, self, i, type, speed);
            }
            r->objs[count++] = o;
        }
        r->count = count;
        r->timer = timer;
    }
}
}

void TObjCityAirCar_Ctrl::render() {  }

extern "C" {
u8 *construct_city_air_car(TObjCityAirCar_Car *city_air_car_car, void *parent, s32 arg2, s32 arg3, f32 farg0) {
    __ct__8TObjBaseFP7TObject(city_air_car_car);
    *(s32 **)((s8 *)city_air_car_car + 0x18) = &__vt__18TObjCityAirCar_Car.value;
    *(s32 *)((s8 *)city_air_car_car + 0) = (s32) TObjCityAirCar_Car__name;
    *(f32 *)((s8 *)city_air_car_car + 0x90) = 0.0f;
    *(s32 *)((s8 *)city_air_car_car + 0x98) = arg2;
    city_air_car_car->m_9c = arg3;
    city_air_car_car->m_94 = farg0;
    *(s32 *)((s8 *)city_air_car_car + 0xA0) = 0;
    city_air_car_car->m_a4 = 0;
    *(s32 *)((s8 *)city_air_car_car + 0xA8) = 0;
    city_air_car_car->update_path_motion();
    city_air_car_car->rotation_z = 0;
    return (u8 *)city_air_car_car;
}
}

TObjCityAirCar_Car::~TObjCityAirCar_Car() {
    if (unk_A8 != NULL) {
        unk_A8->queue_destruction();
    }
}

extern "C" {
f32 fn_80181204(void* p) { return *(f32*)((char*)p + 0x90); }
f32 fn_801811FC(void* p) { return *(f32*)((char*)p + 0x94); }
}

#pragma push
#pragma fp_contract on
struct Car_80181074;
s32 TObjCityAirCar_Car::update_path_motion() {
    Car_80181074 *self = (Car_80181074 *)this;
    Vec_80181074 a;
    Vec_80181074 b;
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
    Vec_80180E70 v;
    f32 scale;
    f32 t;
    t = ((Car_80180E70 *)this)->frame;
    ((Car_80180E70 *)this)->frame = t + ((Car_80180E70 *)this)->speed;
    if (((TObjCityAirCar_Car *)this)->update_path_motion() == 0) {
        queue_destruction();
    }
    if ((((Car_80180E70 *)this)->path == 1 && ((Car_80180E70 *)this)->frame >= 15.5f && ((Car_80180E70 *)this)->frame <= 35.5f) ||
        (((Car_80180E70 *)this)->path == 2 && ((Car_80180E70 *)this)->frame >= 15.0f && ((Car_80180E70 *)this)->frame <= 35.0f)) {
        if (((Car_80180E70 *)this)->model == 4) {
            play_persistent_sound(0x4004CB02, (s32)((Car_80180E70 *)this), (u32)&((Car_80180E70 *)this)->pos, 0, 0);
        } else if (((Car_80180E70 *)this)->model == 0) {
            update_technique_slot__10TTecRaFoieFl(play_persistent_sound(0x4004C101, (s32)((Car_80180E70 *)this), (u32)&((Car_80180E70 *)this)->pos, 0, 0), -0x200, 0);
        } else {
            play_persistent_sound(0x4004C101, (s32)((Car_80180E70 *)this), (u32)&((Car_80180E70 *)this)->pos, 0, 0);
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
            ((Car_80180E70 *)this)->light = (u32)spawn_continuous_particle_effect_with_flags(&((Car_80180E70 *)this)->pos, 0x8A, 0x40);
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
    s32 temp_r31;
    u8 *temp_r3;
    if (((VObj_18_26a62c *)(this))->m8(800.0f, 50.0f) != 0) {
        TParticleCtrl::end_effect_render();
        push_matrix();
        post_translate_matrix((void *) ((u8 *)this + 0x38));
        rotate_matrix_y(0, this->rotation_y);
        if ((s32) this->m_9c != 0) {
            rotate_matrix_z(0, this->rotation_z);
        }
        TObjFish::set_global_param((int)city_common_texture_list);
        get_city_common_model((*(s32 *)((s8 *)((u8 *)city_aircar_model_indices + (this->m_9c * 4)) + 0)));
        ((void (*)()) draw_chunk_object)();
        TParticleCtrl::begin_effect_render();
        get_city_common_model((*(s32 *)((s8 *)((u8 *)city_air_car_model_index_table + (this->m_9c * 4)) + 0)));
        draw_ginja_object();
        if ((void *) city_air_car_model_resource != NULL) {
            temp_r3 = (u8 *)(*(u8 **)((s8 *)city_air_car_model_handle + 0));
            temp_r31 = *(s32 *)((s8 *)temp_r3 + 0x20);
            if ((s32) this->m_a4 >= 0x14) {
                *(s32 *)((s8 *)temp_r3 + 0x20) = (s32) *(s32 *)((s8 *)temp_r3 + 8);
            }
            TObjFish::set_global_param((int)city_air_car_model_handle);
            scroll_strip_uvs(air_car_buffer_pair_table[this->m_9c], *(s32 *)((s8 *)this + 0xA0), 0);
            draw_chunk_object((*(Rec16_80180D18 **)((s8 *)city_air_car_model_resource + 0x42C))[((s32 *)city_traffic_car_chunk_index_table)[this->m_9c]].f8, (void *)city_air_car_model_resource);
            *(s32 *)((s8 *)(*(u8 **)((s8 *)city_air_car_model_handle + 0)) + 0x20) = temp_r31;
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}
