#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjHashi.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80191730_lbl_804B7C60 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80191730_lbl_804B7C60_size[sizeof(RecoveredGlobal_80191730_lbl_804B7C60) == 0x10 ? 1 : -1];

struct RecoveredGlobal_801917E8_lbl_804B7CA0 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_801917E8___vt__9TObjHashi {
    s32 value;
    u8 remaining[0x34];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80191730_lbl_804B7C60 fe_obj_hashi_resource_descriptor;
extern u32 TObjHashi__bml_resource;
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
u32 init_collision_body_parts(void *, s32, s32);
u8 * __ct__13TObjHashiBaseFP7TObjectPv(void *, s32);
extern RecoveredGlobal_801917E8_lbl_804B7CA0 bridge_collision_body;
extern s32 __vt__9TObjHashi[];
extern s32 lbl_805D3378;
u8 *TObjHashi__ct(u8 *arg0, s32 arg1, s32 _w2);
void *TObjHashi__create(void *arg0);
void *__dt__9TObjHashiFv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__dt__13TObjHashiBaseFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

extern void *tl_05;

void *TObjHashi__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD4);
    if (o != NULL) {
        o = TObjHashi__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TObjHashi::unload_static_data() {
    if ((u32) TObjHashi__bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjHashi__bml_resource, 1);
        TObjHashi__bml_resource = 0U;
    }
}

void TObjHashi::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &fe_obj_hashi_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjHashi__bml_resource) = var_r0;
}

void *__dt__9TObjHashiFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__9TObjHashi;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TObjHashiBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_801917E8_lbl_804B7CA0_size[sizeof(RecoveredGlobal_801917E8_lbl_804B7CA0) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_801917E8___vt__9TObjHashi_size[sizeof(RecoveredGlobal_801917E8___vt__9TObjHashi) == 0x38 ? 1 : -1];
u8 *TObjHashi__ct(u8 *player, s32 arg1, s32 _w2) {
    __ct__13TObjHashiBaseFP7TObjectPv(player, arg1);
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_801917E8___vt__9TObjHashi *)&__vt__9TObjHashi).value;
    *(s32 *)((s8 *)player + 0) = (s32) lbl_805D3378;
    *(s32 *)((s8 *)player + 0x34) = get_bml_model((*(u8 * *)&TObjHashi__bml_resource), 0);
    *(s32 *)((s8 *)player + 0x24) = TObjFish__sub_8001EDB0((*(u8 * *)&TObjHashi__bml_resource), 0);
    init_collision_body_parts(player, (s32) &bridge_collision_body.value, 1);
    *(s32 *)((s8 *)player + 0x30) = (s32) (*(s32 *)((s8 *)player + 0x30) | 0x40000000);
    ((TObjPlayer *)player)->register_object_by_id();
    return player;
}

}
