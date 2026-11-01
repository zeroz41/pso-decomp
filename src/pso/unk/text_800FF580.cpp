#include "types.h"
#include "pso/system/vector.h"
#include "pso/TObjEZRopeBase.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
struct Vec_800FF8CC {
    f32 x, y, z;
};

struct Src_800FF8CC {
    s8 count;
    u8 pad[3];
    Vec_800FF8CC rot;
    u8 pad2[8];
};

struct Pos_800FF8CC {
    u32 f0;
    Vec_800FF8CC v;
};

struct Self_800FF8CC {
    u8 pad[0x1C];
    s32 num;
    Src_800FF8CC *src;
    Pos_800FF8CC *pos;
    s32 arg;
    Vec_800FF8CC *out;
};

struct Vec_800FF8CC;
struct Vec_800FF788 { f32 x, y, z; };

struct Seg_800FF788 { s8 n; u8 pad1[3]; Vec_800FF788 dir; u8 pad10[8]; };

struct Src_800FF788 { s32 a; Vec_800FF788 v; };

struct Obj_800FF788 {
    u8 pad0[0x20];
    Seg_800FF788 *segs;
    Src_800FF788 *srcs;
    u32 flag;
    Vec_800FF788 *out;
};

extern "C" {
void vec3_add_to(Vec_800FF8CC *, Vec_800FF8CC *);
void fn_800FF580(void *, void *, f32);
f32 vector_length(void *);
void subtract_vector(void *, void *);
void normalize_vector(void *);
extern const f32 lbl_805DAA58;
extern const f32 lbl_805DAA5C;

void TObjEZRopeBase::sub_800FF788(void *mtx) {
    Seg_800FF788 *seg;
    Src_800FF788 *src;
    Vec_800FF788 *p;
    s32 n;
    f32 zero;
    f32 len;
    zero = lbl_805DAA58;
    seg = ((Obj_800FF788 *)this)->segs;
    src = ((Obj_800FF788 *)this)->srcs;
    p = ((Obj_800FF788 *)this)->out;
    while (seg->n >= 2) {
        len = vector_length(&seg->dir);
        VecCopy((Vec *)((Vec_800FF8CC *)p), (const Vec *)((Vec_800FF8CC *)&src->v));
        p++;
        n = seg->n - 1;
        while (n > 0) {
            vec3_add_to((Vec_800FF8CC *)p, (Vec_800FF8CC *)mtx);
            subtract_vector(p, p - 1);
            if (zero == vector_length(p)) {
                p->x = zero;
                p->y = lbl_805DAA5C;
                p->z = zero;
            } else {
                normalize_vector(p);
            }
            p->x *= len;
            p->y *= len;
            p->z *= len;
            vec3_add_to((Vec_800FF8CC *)p, (Vec_800FF8CC *)(p - 1));
            if (((Obj_800FF788 *)this)->flag != 0) {
                fn_800FF580(((Obj_800FF788 *)this), p, len);
            }
            n--;
            p++;
        }
        seg++;
        src++;
    }
}

void TObjEZRopeBase::sub_800FF8CC(void *src_arg, void *pos_arg, s32 arg) {
    Src_800FF8CC *src = (Src_800FF8CC *)src_arg;
    Pos_800FF8CC *pos = (Pos_800FF8CC *)pos_arg;
    s32 total;
    Src_800FF8CC *s;
    Pos_800FF8CC *p;
    Vec_800FF8CC *out;
    s32 n;
    total = 0;
    ((Self_800FF8CC *)this)->src = src;
    ((Self_800FF8CC *)this)->pos = pos;
    ((Self_800FF8CC *)this)->arg = arg;
    ((Self_800FF8CC *)this)->num = 0;
    for (s = src; s->count >= 2; s++) {
        total += s->count;
        ((Self_800FF8CC *)this)->num++;
    }
    ((Self_800FF8CC *)this)->out = (Vec_800FF8CC *)TQuestVmDownLoadServer::alloc(total * 0xC);
    s = ((Self_800FF8CC *)this)->src;
    p = ((Self_800FF8CC *)this)->pos;
    out = ((Self_800FF8CC *)this)->out;
    for (; s->count >= 2; s++, p++) {
        Vec_800FF8CC v = p->v;
        for (n = s->count; n > 0; n--, out++) {
            VecCopy((Vec *)out, (const Vec *)&v);
            vec3_add_to(&v, &s->rot);
        }
    }
}

}
