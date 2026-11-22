#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5Pillar.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/galgryphon/TObjBoss5PillarCtrl.h"
#include "pso/system/task/TObject.h"

extern "C" {

void *TObjBoss5PillarSmoke__ct(void *, void *, void *);

struct Nd_8028B0DC { u8 pad[0x2C]; Nd_8028B0DC *head; Nd_8028B0DC *next; };
typedef Nd_8028B0DC Ls_8028B0DC;
struct Ow_8028B0DC { u8 pad[0x28]; Ls_8028B0DC *list; };
struct Gl_8028B0DC { u8 pad[0x42C]; Ow_8028B0DC *owner; };
struct Pc_8028B0DC { u8 pad[0x1C]; s32 count; void **a; };
extern Gl_8028B0DC *lbl_805D4DD8;
void *TObjBoss5Pillar::create_smoke(void *arg0, void *smokeParent) {
    void *o;
    o = TObject::operator new(0x28);
    if (o != NULL) {
        o = TObjBoss5PillarSmoke__ct(o, arg0, smokeParent);
    }
    return o;
}

void TBoss8Dragon__sub_8028B0DC(Pc_8028B0DC *pillar_controller, void *arg1, void *arg2) {
    f32 off;
    Nd_8028B0DC *n;
    s32 i;

    n = lbl_805D4DD8->owner->list;
    off = ((TBoss8Dragon *)arg2)->calc_sq_offset(50.0f);
    n = n->head;
    for (i = 0; i < pillar_controller->count; i++) {
        if (pillar_controller->a[i] != NULL && ((TBoss8Dragon *)arg1)->is_within_xz_distance((u8 *)n, (f32)off) != 0) {
            ((TObjBoss5PillarCtrl *)(pillar_controller->a[i]))->play_sound_once();
        }
        n = n->next;
    }
}

}
