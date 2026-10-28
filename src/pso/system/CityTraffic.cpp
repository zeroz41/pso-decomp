#pragma push

#include "types.h"
#include "pso/misc/TCameraCtrl_803D6538.h"
#include "pso/system/CityTraffic.h"
#include "pso/unk/text_80184C2C.h"
#include "pso/system/vector.h"

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
extern void *air_car_buffer_pair_table[];
extern "C" {
void __ct__7TObjectFP7TObject(void *);
extern u8 __vt__19TObjCityAirCar_Ctrl[];
extern s32 TObjCityAirCar_Ctrl__name;
extern const f32 lbl_805DBBC8;
Obj_801815F8 *construct_traffic_manager(Obj_801815F8 *arg0);
extern s32 city_traffic_path_motion_index_table[];
extern s32 city_aircar_model_indices[];
s32 alloc_tables__6TLobbyFll(s32, s32, s32, Ent_801817AC *);
void subtract_vector(Vec_801817AC *, Vec_801817AC *);
extern s32 city_traffic_car_chunk_index_table[];
extern Lob_801817AC *city_air_car_model_resource;
extern s32 city_air_car_model_handle;
extern const f32 lbl_805DBBC4;

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
    arg0->f20 = lbl_805DBBC8;
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
    bind_motion_context((s32)m, farg0);
    void *t = ((void * (*)(s32))get_city_common_model)(city_aircar_model_indices[arg0]);
    sample_motion_node_transform(t, arg1, &sp24, &sp18, &sp8);
    return r;
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

#pragma pop

#pragma push

#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
struct E_801819CC { s32 a; s32 b; };

struct O_801819CC { u8 pad[0x430]; E_801819CC *entries; };

struct E_801819E4 { s32 a; s32 b; s32 c; s32 d; };

struct O_801819E4 { u8 pad[0x42c]; E_801819E4 *entries; };

extern O_801819CC *city_common_model_archive;

f32 air_car_lane_spacing_table[5];
f32 air_car_lane_speed_scale_table[5];
void *air_car_buffer_pair_table[6];
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
    frame = lbl_805DBBC8;
    f32 total = frame;
    ((void (*)(Motion_801817AC *, f32))bind_motion_context)(m, frame);
    sample_motion_node_transform((void *)(get_city_common_model(city_aircar_model_indices[i])), (void *)&prev, (void *)&a, (void *)&b, (void *)&q);
    for (frame += lbl_805DBBC4; frame < end; frame += lbl_805DBBC4)
    {
      ((void (*)(Motion_801817AC *, f32))bind_motion_context)(m, frame);
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
    city_air_car_model_handle = TLobby__sub_80184C2C(2);
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

s32 get_city_common_motion(s32 i) {
    return city_common_model_archive->entries[i].b;
}
s32 get_city_common_model(s32 i) {
    return (*(O_801819E4 * *)&city_common_model_archive)->entries[i].c;
}

#pragma pop
