#include "types.h"
#include "pso/unk/text_8034D3D0.h"
#include "pso/system/vector.h"
typedef struct Vec4_8034D500 {
    f32 x, y, z, w;
} Vec4_8034D500;

typedef struct Vec3_8034D500 {
    f32 x, y, z;
} Vec3_8034D500;

extern "C" {
f32 TBoss8Dragon__sub_8008072C(f32, f32);
s32 calc_binomial_coefficient__12TBoss8DragonFll(int, int);
s32 eval_bezier_curve__12TBoss8DragonFPviiPvf(Vec4_8034D500 *pts, s32 count, s32 closed, Vec3_8034D500 *out, f32 t);
struct Entry_8034D3D0 {
    u8 pad0[0xC];
    f32 weight;
};

s32 fn_8034D3D0(Entry_8034D3D0 *e, s32 n, s32 arg2, s32 closed, s32 arg4, f32 scale) {
    f32 sum;
    f32 total;
    f32 ratio;
    s32 i;

    if (e == NULL || n <= 1) {
        return 0;
    }
    sum = 0.0f;
    for (i = 0; i < n; i++) {
        sum += e[i].weight;
    }
    if (0.0f == sum) {
        return 0;
    }
    if (closed == 0) {
        total = (s32) (sum - e[n - 1].weight);
    } else {
        total = (s32) sum;
    }
    ratio = scale * arg2; ratio /= total;
    if (ratio >= 1.0f) {
        return 1;
    }
    return eval_bezier_curve__12TBoss8DragonFPviiPvf((Vec4_8034D500 *)e, n, closed, (Vec3_8034D500 *)arg4, ratio);
}

#pragma push
#pragma fp_contract on
s32 eval_bezier_curve__12TBoss8DragonFPviiPvf(Vec4_8034D500 *pts, s32 count, s32 closed, Vec3_8034D500 *out, f32 t) {
    s32 n;
    s32 i;
    s32 m;
    f32 u;
    f32 w;
    f32 a;
    f32 b;
    s32 k;
    if (count <= 2) {
        return 0;
    }
    n = count - 1;
    u = (1.0f) - t;
    out->z = out->y = out->x = (0.0f);
    if (closed == 0) {
        for (i = 0; i <= n; i++) {
            k = calc_binomial_coefficient__12TBoss8DragonFll(n, i);
            a = TBoss8Dragon__sub_8008072C(t, (f32)i);
            b = TBoss8Dragon__sub_8008072C(u, (f32)(n - i));
            w = ((f32)k * a) * b;
            out->x += w * pts[i].x;
            out->y += w * pts[i].y;
            out->z += w * pts[i].z;
        }
    } else {
        m = n + 1;
        for (i = 0; i <= n; i++) {
            k = calc_binomial_coefficient__12TBoss8DragonFll(m, i);
            a = TBoss8Dragon__sub_8008072C(t, (f32)i);
            b = TBoss8Dragon__sub_8008072C(u, (f32)(m - i));
            w = ((f32)k * a) * b;
            if (i == n) {
                out->x += w * pts[0].x;
                out->y += w * pts[0].y;
                out->z += w * pts[0].z;
            } else {
                out->x += w * pts[i].x;
                out->y += w * pts[i].y;
                out->z += w * pts[i].z;
            }
        }
    }
    if ((1.0f) == t) {
        return 1;
    }
    return 0;
}
#pragma pop

}

struct PartnerText_8034D9E0 {
    const char *text[6];
    s32 kind[6];
};

struct PartnerText_8034DA38
{
  const char *text[6];
  s32 kind[6];
};

struct PartnerText_8034D9E0 partner_dialogue_table[4];
struct V3_8034D790 { f32 x, y, z; };
struct Ent_8034D790 { V3_8034D790 p; f32 weight; };
extern "C" {
void normalize_vector(void *);

#pragma push
#pragma fp_contract on
s32 fn_8034D790(Ent_8034D790 *e, s32 n, s32 arg2, s32 closed, V3_8034D790 *out, f32 scale) {
    V3_8034D790 a;
    V3_8034D790 b;
    V3_8034D790 d;
    f32 sum;
    f32 pos;
    f32 acc;
    f32 prev;
    s32 total;
    s32 seg;
    s32 i;
    s32 idx;

    if (e == NULL || n <= 1) {
        return 0;
    }
    sum = 0.0f;
    for (i = 0; i < n; i++) {
        sum += e[i].weight;
    }
    if (0.0f == sum) {
        return 0;
    }
    pos = scale * arg2;
    if (closed == 0) {
        total = (s32)(sum - e[n - 1].weight);
    } else {
        total = (s32)sum;
    }
    seg = (s32)pos / total;
    pos -= seg * sum;
    if (closed == 0 && seg != 0) {
        VecCopy((Vec *)out, (const Vec *)&e[n - 1]);
        return 1;
    }
    acc = 0.0f;
    prev = acc;
    for (i = 0; i < n; i++) {
        acc += e[i].weight;
        if (pos <= acc) {
            pos -= prev;
            idx = i;
            break;
        }
        prev = acc;
    }
    if (idx == n - 1) {
        VecCopy((Vec *)&a, (const Vec *)&e[idx]);
        VecCopy((Vec *)&b, (const Vec *)&e[0]);
    } else {
        VecCopy((Vec *)&a, (const Vec *)&e[idx]);
        VecCopy((Vec *)&b, (const Vec *)&e[idx + 1]);
    }
    d.x = b.x - a.x;
    d.y = b.y - a.y;
    d.z = b.z - a.z;
    normalize_vector(&d);
    out->x = d.x * pos + a.x;
    out->y = d.y * pos + a.y;
    out->z = d.z * pos + a.z;
    return 0;
}
}
#pragma pop
const char *get_partner_custom_text(s32 kind, u16 player) {
    s32 i;
    if (player >= 4) {
        return NULL;
    }
    for (i = 0; i < 6; i++) {
        if (kind == partner_dialogue_table[player].kind[i]) {
            return partner_dialogue_table[player].text[i];
        }
    }
    return NULL;
}
typedef struct PartnerText_8034DA38 PartnerText_8034DA38;
void set_partner_dialogue_override(const char *text, s32 kind, u16 player) {
  s32 i;
  long long off;
  if (player >= 4)
  {
    return;
  }
  off = player * 0x30;
  for (i = 0; i < 6; i++)
  {
    if ((((struct PartnerText_8034DA38 *)&partner_dialogue_table)[player].kind[i] == 25) || (kind == ((struct PartnerText_8034DA38 *)&partner_dialogue_table)[player].kind[i]))
    {
      ((struct PartnerText_8034DA38 *) (((u8 *) ((struct PartnerText_8034DA38 *)&partner_dialogue_table)) + off))->kind[i] = kind;
      ((struct PartnerText_8034DA38 *)&partner_dialogue_table)[player].text[i] = text;
      return;
    }
  }
}
