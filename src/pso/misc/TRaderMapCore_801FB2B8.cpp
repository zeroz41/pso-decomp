#include "types.h"
#include "pso/misc/TRaderMapCore_801FB2B8.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjMotion.h"

#pragma fp_contract on

struct RecoveredGlobal_801FB430___vt__13TRaderMapCore {
    s32 value;
    u8 remaining[0x30];
};

struct GRec_801FB490 { u8 pad0[4]; f32 f4; u8 pad8[8]; f32 f10; f32 f14; s32 f18; u8 pad1c[0x28 - 0x1C]; };

struct MRec_801FB490 { f32 v[3]; s32 a0; f32 a4; s16 h[2]; u8 padac[0x28 - 0x18]; };

struct Core_801FB490 {
    s32 f0;
    u8 pad4[0x14];
    s32 *vt;
    u8 pad1c[0x90 - 0x1C];
    s32 f90;
    MRec_801FB490 recs[4];
    s32 f134;
    u8 pad138[0x140 - 0x138];
    f32 f140, f144;
    u8 pad148[0x150 - 0x148];
    f32 f150;
    u8 pad154[0x160 - 0x154];
    f32 f160, f164;
    s32 f168, f16c;
    f32 f170;
    s32 f174, f178, f17c, f180, f184;
    f32 f188, f18c, f190;
    s32 f194, f198;
    f32 f19c, f1a0;
};

extern "C" {
u16 get_entity_id(void *);
s32 get_player_by_client_id(int);
s32 update_radar_auto_discovery(void *, int, void *);
s32 update_pan_zoom_input__13TRaderMapCoreFv();
extern u32 TRaderMapCore__floor_map_resource;
extern s32 TRaderMapCore__view_mode;
s32 __dl__7TObjectFPv(void *);
extern RecoveredGlobal_801FB430___vt__13TRaderMapCore __vt__13TRaderMapCore;
extern s32 TRaderMapCore__instance;
s32 __ct__13TUnk_804B9870FP7TObject(void *, void *);
s32 init_map_ptr__13TRaderMapCoreFv(void *, int);
s32 fn_803D64F8(void *);
extern GRec_801FB490 TRaderMapCore__map_view_state[];
extern f32 lbl_805D35F0;
extern f32 lbl_805D35FC;
extern s32 rader_map_core_name_ptr;
extern const f32 TRaderMapCore__data_805DC528;
extern const f32 radar_screen_width_f32;
extern const f32 radar_screen_height_f32;
extern const f32 lbl_805DC560;
extern const f32 TRaderMapCore__data_805DC568;
extern const f32 TRaderMapCore__data_805DC58C;
extern const f32 lbl_805DC594;
extern const f32 lbl_805DC5A4;
extern const f32 lbl_805DC5A8;
Core_801FB490 *TRaderMapCore__ct(Core_801FB490 *arg0, void *parent);
f32 sin_table_lookup(s32);

extern const f32 TRaderMapCore__data_805DC534;
extern const f32 lbl_805DC59C;
extern const f32 lbl_805DC5A0;

void TRaderMapCore::advance_scroll() {
    this->m_198 = (this->m_198 + 0x888);
    this->m_19c = lbl_805DC59C + lbl_805DC5A0 * (TRaderMapCore__data_805DC534 + sin_table_lookup(this->m_198));
}
void run_task__13TRaderMapCoreFv(TRaderMapCore *rader_map_core) {
    s32 player;
    s32 temp_r4;
    s32 var_r31;
    if ((u32) TRaderMapCore__floor_map_resource != 0U) {
        temp_r4 = rader_map_core->m_90;
        if (temp_r4 > 0) {
            rader_map_core->m_90 = (temp_r4 - 1);
            return;
        }
        switch ((s32) TRaderMapCore__view_mode) {
        case 0:
            rader_map_core->update_target();
            break;
        case 1:
            rader_map_core->update_target();
            break;
        case 2:
            update_pan_zoom_input__13TRaderMapCoreFv();
            break;
        }
        rader_map_core->gather_player_markers();
        if ((TRaderMapCore::is_not_split_screen() == 1) && ((u32) *(u32 *)((s8 *)rader_map_core + 0x184) != 0U)) {
            rader_map_core->m_134 = (s32) get_entity_id(rader_map_core->m_184);
        }
        ((TRaderMapCore *)rader_map_core)->update_follow_projection((s32)((void *)TRaderMapCore__view_mode));
        if (TRaderMapCore::is_not_split_screen() == 1) {
            var_r31 = 0;
            do {
                player = get_player_by_client_id(var_r31);
                if (player != 0) {
                    update_radar_auto_discovery(rader_map_core, 0, (void *)(player + 0x38));
                }
                var_r31 += 1;
            } while (var_r31 < 4);
        } else {
            update_radar_auto_discovery(rader_map_core, 0, (void *) ((u8 *)rader_map_core + rader_map_core->m_134 * 0x28 + 0x94));
        }
        rader_map_core->advance_scroll();
    }
}
typedef char RecoveredGlobal_801FB430___vt__13TRaderMapCore_size[sizeof(RecoveredGlobal_801FB430___vt__13TRaderMapCore) == 0x34 ? 1 : -1];
u8 *__dt__13TRaderMapCoreFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__13TRaderMapCore.value;
        TRaderMapCore__instance = 0;
        __dt__13TUnk_804B9870Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma push
#pragma opt_common_subs off
Core_801FB490 *TRaderMapCore__ct(Core_801FB490 *arg0, void *parent) {
    GRec_801FB490 *g;
    s32 i;
    u32 j;
    s32 off;
    s32 t8, t6, t5, t0;
    __ct__13TUnk_804B9870FP7TObject(arg0, parent);
    arg0->vt = &__vt__13TRaderMapCore.value;
    arg0->f0 = rader_map_core_name_ptr;
    arg0->f178 = init_map_ptr__13TRaderMapCoreFv(&arg0->f90, 2);
    arg0->f17c = init_map_ptr__13TRaderMapCoreFv(&arg0->f90, 0);
    arg0->f180 = init_map_ptr__13TRaderMapCoreFv(&arg0->f90, 1);
    for (i = 0; i < 3; i++) {
        g = &TRaderMapCore__map_view_state[i];
        fn_803D64F8(g);
        g->f4 = lbl_805D35F0;
        g->f10 = TRaderMapCore__data_805DC568;
        g->f14 = TRaderMapCore__data_805DC528;
        g->f18 = 0x8000;
    }
    arg0->f150 = lbl_805DC594;
    arg0->f160 = radar_screen_width_f32;
    arg0->f164 = radar_screen_height_f32;
    arg0->f140 = lbl_805DC5A4;
    arg0->f144 = lbl_805DC5A8;
    for (j = 0; j < 4; j++) {
        arg0->recs[j].v[2] = TRaderMapCore__data_805DC528;
        arg0->recs[j].v[1] = TRaderMapCore__data_805DC528;
        arg0->recs[j].v[0] = TRaderMapCore__data_805DC528;
        arg0->recs[j].a0 = 0;
        arg0->recs[j].a4 = lbl_805DC560;
        arg0->recs[j].h[1] = -1;
    }
    arg0->f134 = 0;
    arg0->f168 = 2;
    arg0->f16c = 0;
    arg0->f170 = lbl_805D35FC;
    TRaderMapCore__view_mode = 0;
    arg0->f174 = 0;
    TRaderMapCore__instance = (s32) arg0;
    arg0->f90 = 0x3C;
    arg0->f198 = 0;
    arg0->f19c = TRaderMapCore__data_805DC528;
    arg0->f184 = 0;
    arg0->f188 = TRaderMapCore__data_805DC528;
    arg0->f18c = TRaderMapCore__data_805DC528;
    arg0->f190 = TRaderMapCore__data_805DC528;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        arg0->f194 = 0x800810;
        TRaderMapCore__view_mode = 2;
    } else {
        arg0->f194 = 0x800810;
    }
    if (TRaderMapCore::is_not_split_screen() == 1) {
        arg0->f1a0 = TRaderMapCore__data_805DC58C;
    } else {
        arg0->f1a0 = TRaderMapCore__data_805DC58C;
    }
    if (TRaderMapCore__floor_map_resource == 0) {
        queue_destruction__7TObjectFv(arg0);
        return arg0;
    }
    return arg0;
}
#pragma pop

}
