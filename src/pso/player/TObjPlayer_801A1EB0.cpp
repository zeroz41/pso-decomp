#include "types.h"
#include "pso/player/TObjPlayer_801A1EB0.h"
#include "pso/unk/text_801A210C.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TContainerAncient01.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"

struct Vec_801A1F48 { f32 x, y, z; };

struct Src_801A1F48 { u8 pad[4]; u16 id; u8 pad6[2]; s16 kind; u8 padA[2]; Vec_801A1F48 pos; Vec_801A1F48 rot; Vec_801A1F48 v24; s32 vals[3]; };



extern u16 lbl_805D5CD4;
extern u16 lbl_805D5CD6;
extern u16 lbl_805D5CD2;
extern u16 lbl_805D5CD8;

s16 TUnk_804B9870::get_stat_by_key_state() {
    s32 global_state;

    if ((get_current_area() == 0) || (get_current_area() == 0x12)) {
        return 0;
    }
    if ((u16) this->entity_id < 0x1000U) {
        global_state = get_current_area();
        if (((global_state - 1) <= 1U) || (TContainerAncient01::is_global_state_in_table() != 0) || (global_state == 0xC) || (global_state == 0x20)) {
            return alt_room;
        }
        return room;
    }
    return room;
}

void TUnk_804B9870::apply_object_set_data(void *src_arg) {
    Src_801A1F48 *src = (Src_801A1F48 *)src_arg;
    s32 i;
    entity_id = src->id;
    VecCopy(&home_position, VecCopy(&position, (const Vec *)&src->pos));
    ((TObjPlayer *)&rotation_x)->copy_xyz(&src->rot);
    VecCopy(&scale, (const Vec *)&src->v24);
    room = src->kind;
    for (i = 0; i < 3; i++) {
        set_params[i] = src->vals[i];
    }
}

void TUnk_804B9870::vfunc_6(s16 *, s32) {  }
u16 TUnk_804806E8::get_or_assign_actor_id(s32 arg1) {

    if (this->entity_id == 0xFFFF) {
        switch (this->actorFlags & 0x70000000) {
        case 0x10000000:
            this->entity_id = fn_801A210C(arg1);
            break;
        case 0x20000000:
            this->entity_id = TLobby__sub_801A20C8(arg1);
            break;
        default:
        case 0x40000000:
            this->entity_id = TLobby::alloc_actor_ids(arg1);
            break;
        }
    }
    return this->entity_id;
}
u16 TLobby::alloc_actor_ids(s32 arg) {
    u16 n = arg;
    s32 id = lbl_805D5CD4;
    if (id + n + 1 >= 0xFFFF) {
        lbl_805D5CD4 = lbl_805D5CD6;
        id = lbl_805D5CD4;
        lbl_805D5CD4 = id + (n + 1);
    } else {
        lbl_805D5CD4 = id + (n + 1);
    }
    return id;
}

u16 TLobby__sub_801A20C8(s32 arg) {
    u16 n = arg;
    s32 id = lbl_805D5CD2;
    if (id + n + 1 >= 0x4000) {
        lbl_805D5CD2 = lbl_805D5CD8;
        id = lbl_805D5CD2;
        lbl_805D5CD2 = id + (n + 1);
    } else {
        lbl_805D5CD2 = id + (n + 1);
    }
    return id;
}

