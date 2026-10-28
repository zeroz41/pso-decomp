#include "types.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
struct Vec_8029EC3C { f32 x; f32 y; f32 z; };

struct Ray_8029EC3C { Vec_8029EC3C o; Vec_8029EC3C d; };

struct Hit_8029EC3C {
    u8 pad0[4];
    struct HitE_8029EC3C {
        f32 v[6];
        u32 flags;
    } *e;
};

extern "C" {
void *get_player_by_client_id(s32);
f32 vec_squared_length(u8 *arg0);
void reflect_matrix_in_plane(s32, void *);
s32 *csnVecterUnder(s32 origin, s32 mask);
Hit_8029EC3C *csnVector(void *, void *, s32);
extern s32 local_client_id;
extern Vec_8029EC3C sora_reflection_ray_direction;
extern const f32 lbl_805DDD88;
extern const f32 lbl_805DDD8C;
extern const f32 lbl_805DDD98;
extern const f32 lbl_805DDD9C;
s32 fn_8029EC3C(Vec_8029EC3C *pos, s32 arg1);
#pragma push
#pragma fp_contract on
s32 fn_8029EC3C(Vec_8029EC3C *pos, s32 arg1) {
    Ray_8029EC3C ray;
    Vec_8029EC3C a;
    Vec_8029EC3C b;
    Vec_8029EC3C d;
    void *p;
    Hit_8029EC3C *r;
    Hit_8029EC3C::HitE_8029EC3C *e;
    f32 scale;
    p = get_player_by_client_id(local_client_id);
    if (p == 0) return 0;
    scale = lbl_805DDD98;
    if (get_current_floor_area() == AREA_SEABED_UPPER) {
        if ((s16)((TObjBase *)p)->get_room() == 0x5A) {
            scale = lbl_805DDD9C;
        } else {
            scale = lbl_805DDD98;
        }
    }
    VecCopy((Vec *)&a, (const Vec *)pos);
    b.x = scale * sora_reflection_ray_direction.x + a.x;
    b.y = a.y - lbl_805DDD88 * sora_reflection_ray_direction.y;
    b.z = scale * sora_reflection_ray_direction.z + a.z;
    d.x = b.x - pos->x;
    d.z = b.z - pos->z;
    d.y = b.y - pos->y;
    if (lbl_805DDD8C == vec_squared_length((u8 *)&d)) {
        ray.o.x = pos->x;
        ray.o.y = pos->y;
        ray.o.z = pos->z;
        ray.d.x = sora_reflection_ray_direction.x;
        ray.d.y = sora_reflection_ray_direction.y;
        ray.d.z = sora_reflection_ray_direction.z;
        reflect_matrix_in_plane(0, &ray);
        return 1;
    }
    if (lbl_805DDD8C == sora_reflection_ray_direction.x && lbl_805DDD8C == sora_reflection_ray_direction.z) {
        r = (Hit_8029EC3C *)csnVecterUnder((s32)&a, arg1);
    } else {
        r = csnVector(&a, &b, arg1);
    }
    if (r != 0) {
        e = r->e;
        if (!(e->flags & 0x4000)) return 0;
        ray.o.x = e->v[0];
        ray.o.y = e->v[1];
        ray.o.z = e->v[2];
        ray.d.x = e->v[3];
        ray.d.y = e->v[4];
        ray.d.z = e->v[5];
        reflect_matrix_in_plane(0, &ray);
        return 1;
    }
    return 0;
}
#pragma pop

}
