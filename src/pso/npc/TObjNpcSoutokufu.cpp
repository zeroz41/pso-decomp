#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/npc/TObjNpcSoutokufu.h"
#include "pso/npc/TUnk_804A9F50.h"

#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"

#pragma readonly_strings on

extern "C" {
extern const char *bm_npc_soutokufu_motion_names[1];
extern const char *bm_npc_soutokufu_model_names[2];
const char *bm_npc_soutokufu_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_npc_soutokufu_model_names[2] = { "soutokufu_body.nj", NULL };
BmlResourceDescriptor bm_npc_soutokufu_resource_descriptor = { "bm_npc_soutokufu.bml", bm_npc_soutokufu_model_names, bm_npc_soutokufu_motion_names, 1, 0 };
const char *TObjNpcSoutokufu__name = "TObjNpcSoutokufu";
BmlResource *TObjNpcSoutokufu__shared_model_resource;
}


struct Nd_80289710 { u32 flags; u8 pad4[4]; f32 f8; f32 fc; f32 f10; u8 pad14[0x1C]; Nd_80289710 *next; };

struct Ls_80289710 { u8 pad[0x2C]; Nd_80289710 *head; };

struct Ow_80289710 { u8 pad[0x58]; Ls_80289710 *list; };

struct Gl_80289710 { u8 pad[0x42C]; Ow_80289710 *owner; };


extern void *lbl_805D4DD8;

void TObjNpcSoutokufu::close_dialog_window() {
    if (TObjNpcSoutokufu__shared_model_resource != NULL) {
        delete TObjNpcSoutokufu__shared_model_resource;
        TObjNpcSoutokufu__shared_model_resource = NULL;
    }
}

void TObjNpcSoutokufu::load_shared_resource() {
    TObjNpcSoutokufu__shared_model_resource = new BmlResource(1, &bm_npc_soutokufu_resource_descriptor, 0, 0, NULL);
}

TObjNpcSoutokufu::~TObjNpcSoutokufu() {}


TObjNpcSoutokufu::TObjNpcSoutokufu(TObject *parent, void *arg2) : TUnk_804A9F50(parent) {
    *(s32 *)((s8 *)this + 0) = (saddr) TObjNpcSoutokufu__name;
    ((TObjNpcSoutokufu *)this)->apply_set_data(arg2);
    init_position_vectors();
    model = get_bml_model(TObjNpcSoutokufu__shared_model_resource, 0);
    texlist = (saddr)get_bml_texlist(TObjNpcSoutokufu__shared_model_resource, 0);
    ((TObjNpcBase *)this)->setup_common();
}

void TBoss8Dragon::trigger_switches_in_range(void *floor_stone, void *pos, void *prm) {
    f32 sp[3];
    f32 off;
    Ls_80289710 *list;
    Nd_80289710 *n;
    Ow_80289710 *ow;
    ow = (*(Gl_80289710 * *)&lbl_805D4DD8)->owner;
    list = ow->list;
    off = ((TBoss8Dragon *)prm)->calc_sq_offset(50.0f);
    for (n = list->head; n != NULL; n = n->next) {
        if (!(n->flags & 8) && ((TBoss8Dragon *)pos)->is_within_xz_distance((u8 *)n, (f32)off) != 0) {
            sp[0] = n->f8;
            sp[1] = n->fc;
            sp[2] = n->f10;
            ((TBoss8Dragon *)sp)->spawn_attack_effect();
            ((TBoss8Dragon *)sp)->spawn_switch_attack();
            n->flags |= 8;
        }
    }
}

