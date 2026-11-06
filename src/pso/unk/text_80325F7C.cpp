#include "types.h"
#include "pso/map/CsnQuery.h"
#include "pso/unk/text_80325F7C.h"
#include "pso/system/vector.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningWing.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningHorn.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
struct Vec_80325F7C { f32 x, y, z; };

struct Ray_80325F7C { Vec_80325F7C o; Vec_80325F7C d; };

struct Ctl_80325F7C { u8 pad[0x38]; Vec_80325F7C pos; };

typedef struct Vec_80326074 { f32 x; f32 y; f32 z; } Vec_80326074;

typedef struct Seg_80326074 { Vec_80326074 pos; f32 pad; } Seg_80326074;

typedef struct Hit_80326074 { u8 pad[4]; f32 *pos; } Hit_80326074;

typedef struct Wing_80326074 {
    u8 pad0[0x48];
    Seg_80326074 segs[4];
    u8 pad88[8];
    s32 n;
    u8 pad94[4];
    Vec_80326074 vel;
} Wing_80326074;

extern "C" {
void TBoss8Dragon__sub_80063FB8(s32, void *, f32);
Ctl_80325F7C *get_player_by_client_id(s32);
void get_wing_position__26TBoss5GryphonLightningWingFl(void *, void *);
void copy_position__12TBoss8DragonFl(void *, void *);
void TObjPlayer__sub_80325D58(void *, void *, void *, void *);
void project_point_onto_line(void *, void *, void *);
extern const f32 lbl_805DF630;
s32 rand(void);
void vec3_add_to(void *, void *);
void subtract_vector(void *, void *);
extern const f32 lbl_805D8D48;
extern const f32 lbl_805DF644;
extern const f32 lbl_805DF648;
extern const f32 lbl_805DF64C;
void fn_80325F7C(void *arg0) {
    Ray_80325F7C ray;
    Vec_80325F7C pos;
    Vec_80325F7C wing;
    Vec_80325F7C hit;
    Vec_80325F7C dir;
    s32 inst;
    s32 i;
    Ctl_80325F7C *c;
    inst = TBoss8Dragon::get_instance_count();
    if (inst != 0) {
        i = 0;
        do {
            c = get_player_by_client_id(i);
            if (c != 0) {
                copy_position__12TBoss8DragonFl(arg0, &pos);
                get_wing_position__26TBoss5GryphonLightningWingFl(arg0, &wing);
                ray.o.x = pos.x;
                ray.o.y = c->pos.y;
                ray.o.z = pos.z;
                ray.d.x = wing.x - pos.x;
                ray.d.y = lbl_805DF630;
                ray.d.z = wing.z - pos.z;
                project_point_onto_line(&c->pos, &ray, &hit);
                dir.x = ray.d.x;
                dir.y = ray.d.y;
                dir.z = ray.d.z;
                ((TObjBoss2Tunnel *)(&dir))->update_scale();
                TObjPlayer__sub_80325D58(arg0, &pos, &dir, &hit);
                TBoss8Dragon__sub_80063FB8(inst, &hit, 6.0f);
            }
            i++;
        } while (i < 4);
    }
}
#pragma push
#pragma fp_contract on
void TBoss5GryphonLightningHorn::rebuild_lightning_segments() {
    Wing_80326074 *self = (Wing_80326074 *)this;
    Vec_80326074 q;
    Vec_80326074 p;
    Vec_80326074 d;
    Hit_80326074 *hit;
    f32 h;
    f32 len;
    s32 i;
    f32 r;
    get_wing_position__26TBoss5GryphonLightningWingFl(self, &p);
    p.x += self->vel.x;
    p.y += self->vel.y;
    p.z += self->vel.z;
    p.y = 60.0f;
    hit = (Hit_80326074 *)csnVecterUnder((s32)&p, 0x16EF);
    if (hit == NULL || (h = hit->pos[1]) > lbl_805D8D48) {
        get_wing_position__26TBoss5GryphonLightningWingFl(self, &p);
        self->vel.x *= 0.5f;
        self->vel.y *= 0.5f;
        self->vel.z *= 0.5f;
    } else {
        p.y = h;
    }
    copy_position__12TBoss8DragonFl(self, &q);
    VecCopy((Vec *)&d, (const Vec *)&p);
    subtract_vector(&d, &q);
    len = ((TObjBoss2Tunnel *)(&d))->update_scale() / (self->n - 1);
    d.x *= len;
    d.y *= len;
    d.z *= len;
    VecCopy((Vec *)&p, (const Vec *)&q);
    for (i = 0; i < self->n; i++) {
        VecCopy((Vec *)&self->segs[i].pos, (const Vec *)&p);
        vec3_add_to(&p, &d);
    }
    r = lbl_805DF648 * (lbl_805DF64C * (f32)rand()) + lbl_805DF644;
    for (i = 1; i < self->n - 1; i++) {
        self->segs[i].pos.y += r;
    }
    ((TBoss5GryphonLightningWing *)self)->update_wing_segments();
}
#pragma pop

}
