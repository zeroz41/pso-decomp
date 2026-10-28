#include "types.h"
#include "pso/misc/TOMonumentAncient01_801726D4.h"
#include "pso/unk/text_801F43B4.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOMonumentAncient02.h"
#include "pso/misc/TUnk_804B27D8.h"
#include "pso/misc/TOMonumentAncient01.h"
#include "pso/misc/TOHealGeneral.h"
#include "pso/misc/TOKey.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80172758_lbl_804B38E0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80172758_lbl_804B38E0_size[sizeof(RecoveredGlobal_80172758_lbl_804B38E0) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80172810_lbl_804B38F0 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_80172810___vt__19TOMonumentAncient01 {
    s32 value;
    u8 remaining[0x40];
};

extern "C" {
s32 start_camera_pan__10TObjPlayerFs(int, int, void *);
void *get_player_by_client_id(s32 i);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80172758_lbl_804B38E0 bm_fs_obj_o_sekihi01_resource_descriptor;
extern u32 TOMonumentAncient01__resource_bundle;
s32 TObjFish__sub_8001EDB0(int, int);
s32 get_bml_model(int, int);
s32 init_collision_body_parts(void *, void *, int);
extern RecoveredGlobal_80172810_lbl_804B38F0 lbl_804B38F0;
extern s32 __vt__19TOMonumentAncient01[];
extern s32 TOMonumentAncient01__name;
extern const f32 lbl_805DB918;
extern const f32 lbl_805DB91C;
s32 dispatch_by_main_phase__14TBoss4DarkFalzFUs(s32);
void TLobby__sub_8001FE7C(void*, int);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

extern void *tl_05;

void *TOMonumentAncient01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xE4);
    if (o != NULL) {
        o = TOMonumentAncient01__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOMonumentAncient01::release_static_resource() {
    if ((u32) TOMonumentAncient01__resource_bundle != 0U) {
        TLobby__sub_8001FE7C((void*)TOMonumentAncient01__resource_bundle, 1);
        TOMonumentAncient01__resource_bundle = 0U;
    }
}

void TOMonumentAncient01::load_resource_instance() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &bm_fs_obj_o_sekihi01_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TOMonumentAncient01__resource_bundle) = var_r0;
}

void *__dt__19TOMonumentAncient01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TOMonumentAncient01;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B27D8 *)arg0)->destroy_key_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80172810_lbl_804B38F0_size[sizeof(RecoveredGlobal_80172810_lbl_804B38F0) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_80172810___vt__19TOMonumentAncient01_size[sizeof(RecoveredGlobal_80172810___vt__19TOMonumentAncient01) == 0x44 ? 1 : -1];
u8 *TOMonumentAncient01__ct(u8 *arg0, s32 arg1, s32 arg2) {
    ((TUnk_804B27D8 *)arg0)->init();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80172810___vt__19TOMonumentAncient01 *)&__vt__19TOMonumentAncient01).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TOMonumentAncient01__name;
    ((TOMonumentAncient01 *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model((int) ((*(s32 *)&TOMonumentAncient01__resource_bundle)), 2);
    ((TOMonumentAncient01 *)arg0)->texlist = TObjFish__sub_8001EDB0((int) ((*(s32 *)&TOMonumentAncient01__resource_bundle)), 2);
    init_collision_body_parts(arg0, &lbl_804B38F0.value, 1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TOHealGeneral *)arg0)->update_heal_gauge_state();
    ((TOMonumentAncient01 *)arg0)->m_c0 = (f32) lbl_805DB918;
    *(f32 *)((s8 *)arg0 + 0xC4) = (f32) lbl_805DB91C;
    return arg0;
}

void TOMonumentAncient02::vfunc_6(s16 *arg1, s32) {
    this->m_ac = (s32) *arg1;
    switch (this->m_ac) {
    case 2:
        dispatch_by_main_phase__14TBoss4DarkFalzFUs(this->m_d0);
        this->m_c8 = 1;
        break;
    default:
        if (get_story_flag(this->m_d0) != 0) {
            this->m_ac = 2;
            this->m_c8 = 1;
        }
        break;
    }
    if ((get_story_flag(0x2C) != 0) && (get_story_flag(0x2D) != 0) && (get_story_flag(0x2E) != 0)) {
        dispatch_by_main_phase__14TBoss4DarkFalzFUs(0x2F);
    }
    access_object_saved_state(arg1, 0);
}

void TOMonumentAncient02__vt11(u8 *monument_ancient02, u16 arg1) {
    s16 sp8;
    s32 player;
    switch (((TOMonumentAncient02 *)monument_ancient02)->m_ac) {
    case 1:
        player = (s32)get_player_by_client_id((arg1));
        if (player != 0) {
            ((TOMonumentAncient02 *)monument_ancient02)->m_ac = 2;
            start_camera_pan__10TObjPlayerFs(player, 0xC, (void *) (((TObjPlayer *)(player + 0x38))->calc_angle_to(monument_ancient02 + 0x38)));
            if (((TUnk_804AF8A0 *)monument_ancient02)->access_object_saved_state(&sp8, 1) != 0) {
                sp8 = (s16) ((TOMonumentAncient02 *)monument_ancient02)->m_ac;
                ((TUnk_804AF8A0 *)monument_ancient02)->access_object_saved_state(&sp8, 0);
                ((TUnk_804AF8A0 *)monument_ancient02)->send_object_state_update(&sp8);
            }
        }
        break;
    }
}

}
