#include "types.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/vector.h"
struct Vec_8036D0C0 { f32 x, y, z; };

struct Hold_8036D0C0 {
    s32 x0;
    u8 pad4[0x14];
    void *vt;
    u8 pad1c[0x1C];
    Vec_8036D0C0 pos;
    u8 pad44[0x4C];
    void *x90;
    s16 x94;
    u8 pad96[2];
    s32 x98;
    s32 x9c;
};

extern "C" {
s16 get_entity_id(void *);
void __ct__8TObjBaseFP7TObject(void *, s32);
extern void *__vt__17TObjEneHoldEffect[];
extern s32 lbl_805D44E8;
extern s32 tl_07;
Hold_8036D0C0 *TObjEneHoldEffect__ct(Hold_8036D0C0 *o, u8 *parent, s32 type, s32 arg3);
Hold_8036D0C0 *TObjEneHoldEffect__ct(Hold_8036D0C0 *o, u8 *parent, s32 type, s32 arg3) {
    __ct__8TObjBaseFP7TObject(o, tl_07);
    o->vt = __vt__17TObjEneHoldEffect;
    o->x90 = NULL;
    if (parent != NULL) {
        o->x0 = lbl_805D44E8;
        VecCopy((Vec *)&o->pos, (const Vec *)(parent + 0x38));
        o->x94 = get_entity_id(parent);
        o->x9c = arg3;
        switch (type) {
        case 1:
            o->x98 = 0x12F;
            break;
        case 2:
            o->x98 = 0x20F;
            break;
        case 3:
            o->x98 = 0x223;
            break;
        default:
            queue_destruction__7TObjectFv(o);
            return o;
        }
        o->x90 = create_particle_emitter(&o->pos, o->x98);
    } else {
        queue_destruction__7TObjectFv(o);
    }
    return o;
}

}
