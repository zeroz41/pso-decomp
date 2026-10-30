#include "pso/unk/TObjEneEpsilonBody.h"
#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/object/TObject_80019A50.h"
struct Eps_803622B0 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x414];
    void *x430;
    void *x434;
    u8 pad438[0x88];
    u8 x4c0[0x1C];
    u16 h[4];
};

extern "C" {
void *find_entity_by_id(u16 id);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
u8 *__dt__14TObjEneEpsilonFv(u8 *arg0, s16 arg1);
extern void *lbl_804F22DC[];
Eps_803622B0 *__dt__18TObjEneEpsilonBodyFv(Eps_803622B0 *o, s16 arg1);
Eps_803622B0 *__dt__18TObjEneEpsilonBodyFv(Eps_803622B0 *o, s16 arg1) {
    s32 i;
    if (o != NULL) {
        o->vt = lbl_804F22DC;
        free_collision_body_parts(o);
        if (o->x430 != NULL) {
            queue_destruction__7TObjectFv(o->x430);
            o->x430 = NULL;
        }
        if (o->x434 != NULL) {
            queue_destruction__7TObjectFv(o->x434);
            o->x434 = NULL;
        }
        for (i = 0; i < 4; i++) {
            if (o->h[i] != 0) {
                u32 p = (u32)find_entity_by_id(o->h[i]);
                if (p != 0) {
                    queue_destruction__7TObjectFv((void *)p);
                }
            }
        }
        ((TObjEneEpsilonBody *)o)->fade.MaterialOpacityFade::~MaterialOpacityFade();
        __dt__14TObjEneEpsilonFv((u8 *)o, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(o);
        }
    }
    return o;
}

}
