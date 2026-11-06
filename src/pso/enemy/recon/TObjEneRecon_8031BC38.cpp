#include "types.h"
#include "pso/enemy/recon/TObjEneReconBomb.h"
#include "pso/enemy/recon/TObjEneRecon_8031BC38.h"
#include "pso/enemy/recon/TObjEneRecobox_8031FCB0.h"
#include "pso/enemy/recon/TObjEneRecon.h"

extern "C" {

void *__nw__7TObjectFUl(int);

void TObjEneRecon__sub_8031BC38(void) {  }

void *TObjEneRecon::create_bomb(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x364);
    if (o != NULL) {
        o = TObjEneReconBomb__ct((TObjEneReconBomb *)((u8 *)o), (s32)arg0, (s32)arg1, (s32)arg2);
    }
    return o;
}

    extern int recon_bomb_bml_resource;
void TObjEneRecon__sub_8031BC94(void) { recon_bomb_bml_resource = TObjEneRecobox__sub_803201D0(); }

}
