#include "types.h"
#include "pso/enemy/beast/TObjEneBeast.h"
struct E_80092AE0 { u8 pad[8]; s32 x8; s32 xc; };

struct G_80092AE0 { u8 pad[0x42c]; E_80092AE0 *tbl; };

struct O_80092AE0 { u8 pad[0x24]; s32 x24; u8 pad2[0xc]; s32 x34; };

extern G_80092AE0 *ene_beast_bml_resource;

void TObjEneBeast::select_model_record(s32 i) {
    O_80092AE0 *self = (O_80092AE0 *)this;
    self->x34 = ene_beast_bml_resource->tbl[i].x8;
    self->x24 = ene_beast_bml_resource->tbl[i].xc;
}
