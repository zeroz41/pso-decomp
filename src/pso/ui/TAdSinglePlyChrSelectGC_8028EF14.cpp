#include "types.h"
#include "pso/misc/CharacterAppearanceTables.h"
#include "pso/system/BmlResource.h"
#include "pso/TObject.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TCMCharacter.h"
#include "pso/misc/CharacterShape.h"
#include "pso/misc/CharacterCreationTextureCache.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/misc/TCharaMaking.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct W_80290250 { u8 pad[0xfc]; s32 bufp; s32 rc; u8 data[4]; };


struct Opaque_80290088;

extern const f32 lbl_805DD944;
extern const f32 lbl_805DD948;
extern const f32 lbl_805DD94C;
extern const f32 lbl_805DD950;
extern const f32 lbl_805DD954;
s32 find_shape_triangle_region(u8 *arg0);
TChCrLoadAfsTextureReq *create_ch_cr_load_afs_texture_req(void *figure, void *list, void *slot, void *index);
extern "C" {
void calc_shape_region_coefficients(void *point);
void blend_shape_chunk_vertices(void);
}
struct CreationShapeModel { u8 pad[8]; f32 center[3]; };
struct CreationShapeNode { u32 eval_flags; CreationShapeModel *model; f32 pos[3]; s32 ang[3]; f32 scl[3]; };
extern "C" {
void TAdSinglePlyChrSelectGC__sub_802905A4(void* p, void* q);
}
void reset_creation_shape_set(s32 arg0);
extern void ***char_creation_data_block;
void reset_creation_body_shapes();
void reset_creation_head_shapes();
#pragma common off
CreationHeadModelStates creation_head_shape_destination;
CreationHeadModelStates creation_head_shape_samples[7];
CreationBodyModelStates creation_body_shape_destination;
CreationBodyModelStates creation_body_shape_samples[7];
CreationShapeBlend creation_shape_blend;
CreationTextureCacheEntry creation_texture_cache[CREATION_TEXTURE_CACHE_CAPACITY];
CreationModelPart creation_hair_model_parts[10];
CreationModelPart creation_cap_model_parts[10];
CreationModelPart creation_head_model_parts[5];
__declspec(section ".data") u32 creation_models_ready;
#pragma common reset
extern "C" {
s32 is_entry_equal__23TAdSinglePlyChrSelectGCFPvPv(void *, void *);
s32 creation_motion_group(CharacterAppearanceFields *);
void load_creation_shape_rel(W_80290250 *arg0);
void TCharaMaking__sub_8028E3A0();
void TAdSinglePlyChrSelectGC__sub_80290884(void* p, void* q);
extern u8 lbl_80451CD0[];
s32 count_char_diffs__23TAdSinglePlyChrSelectGCFPvPv(void *, void *);
extern CreationTextureCacheEntry *char_select_current_entry;
void advance_animation_playback(s32);
void TAdSinglePlyChrSelectGC__sub_8028ED54(void);
void blend_creation_proportion_shapes(void *);
s32 TLobby__sub_8001FE7C(void *, int);
void *__dt__10TObjMotionFv(void *arg0, s16 arg1);
void mem_free(void *p);
s32 __dl__7TObjectFPv(void *);
void TAdSinglePlyChrSelectGC__sub_8028F084(CreationTextureCacheEntry *entry, TCharaMaking *appearance);
void TCharaMaking__bind_appearance_texture_lists(s32 *hair, s32 *head, s32 *body, TCharaMaking *appearance);
void copy_slot_data__23TAdSinglePlyChrSelectGCFPvPv(void *dst, void *src);
extern s32 lbl_805D49B4;
extern int char_creation_figure_draw_flag;
extern s32 creation_resource_ready_state;
u8 *TAdSinglePlyChrSelectGC__sub_802908CC(u8 *arg0, s16 arg1);
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
void rotate_matrix_y(int, u32);
void push_matrix_from();
void push_matrix();
s32 pop_matrix(void);
int fn_8001ED90(void *p);
void update_pair__23TAdSinglePlyChrSelectGCFPv(void* p);
int TAdSinglePlyChrSelectGC__sub_802905B8(void);
void close_if_active__23TAdSinglePlyChrSelectGCFv(u8 * _w0);
s32 release_texture_list(void *);
int set_motion_interpolation_flag__10TObjMotionFv(void*);
int draw_model_with_callback__10TObjPlayerFv(void*);

extern "C" {
void run_task__12TCMCharacterFv();
}
extern "C" {
void vfunc_6__13TUnk_804B9870FPsl();
}
extern "C" {
void interact__13TUnk_804AF8A0Fl();
}
extern "C" {
void get_name__13TUnk_804B9870Fv();
}
extern "C" {
void vfunc_9__13TUnk_804B9870Fv();
}
extern "C" {
void apply_object_set_data__13TUnk_804B9870FPv();
}
extern "C" {
void classify_actor_view_detail__13TUnk_804B9870Ffff();
}
extern "C" {
extern u8 lbl_804512A0[];
}
extern "C" {
extern u8 lbl_804512AC[];
}
extern "C" {
extern u8 lbl_804512B8[];
}
extern "C" {
extern u8 lbl_804512C4[];
}
extern "C" {
extern u8 lbl_804512D0[];
}
extern "C" {
extern u8 lbl_804512DC[];
}
extern "C" {
extern u8 lbl_804512E8[];
}
extern "C" {
extern u8 lbl_804512F4[];
}
extern "C" {
extern u8 lbl_80451300[];
}
extern "C" {
extern u8 lbl_8045130C[];
}
extern "C" {
extern u8 lbl_80451318[];
}
extern "C" {
extern u8 lbl_80451324[];
}
extern "C" {
extern u8 lbl_80451330[];
}
extern "C" {
extern u8 lbl_8045133C[];
}
extern "C" {
extern u8 lbl_80451348[];
}
extern "C" {
extern u8 lbl_80451354[];
}
extern "C" {
extern u8 lbl_80451360[];
}
extern "C" {
extern u8 lbl_8045136C[];
}
extern "C" {
extern u8 lbl_80451378[];
}
extern "C" {
extern u8 lbl_80451384[];
}
extern "C" {
extern u8 lbl_80451390[];
}
extern "C" {
extern u8 lbl_8045139C[];
}
extern "C" {
extern u8 lbl_804513A8[];
}
extern "C" {
extern u8 lbl_804513B4[];
}
extern "C" {
extern u8 lbl_804513C0[];
}
extern "C" {
extern u8 lbl_804513CC[];
}
extern "C" {
extern u8 lbl_804513D8[];
}
extern "C" {
extern u8 lbl_804513E4[];
}
extern "C" {
extern u8 lbl_804513F0[];
}
extern "C" {
extern u8 lbl_804513FC[];
}
extern "C" {
extern u8 lbl_80451408[];
}
extern "C" {
extern u8 lbl_80451414[];
}
extern "C" {
extern u8 lbl_80451420[];
}
extern "C" {
extern u8 lbl_8045142C[];
}
extern "C" {
extern u8 lbl_80451438[];
}
extern "C" {
extern u8 lbl_80451444[];
}
extern "C" {
extern u8 lbl_80451450[];
}
extern "C" {
extern u8 lbl_8045145C[];
}
extern "C" {
extern u8 lbl_80451468[];
}
extern "C" {
extern u8 lbl_80451474[];
}
extern "C" {
extern u8 lbl_80451480[];
}
extern "C" {
extern u8 lbl_8045148C[];
}
extern "C" {
extern u8 lbl_80451498[];
}
extern "C" {
extern u8 lbl_804514A4[];
}
extern "C" {
extern u8 lbl_804514B0[];
}
extern "C" {
extern u8 lbl_804514BC[];
}
extern "C" {
extern u8 lbl_804514C8[];
}
extern "C" {
extern u8 lbl_804514D4[];
}
extern "C" {
extern u8 lbl_804514E0[];
}
extern "C" {
extern u8 lbl_804514EC[];
}
extern "C" {
extern u8 lbl_804514F8[];
}
extern "C" {
extern u8 lbl_80451504[];
}
extern "C" {
extern u8 lbl_80451510[];
}
extern "C" {
extern u8 lbl_8045151C[];
}
extern "C" {
extern u8 lbl_80451528[];
}
extern "C" {
extern u8 lbl_80451534[];
}
extern "C" {
extern u8 lbl_80451540[];
}
extern "C" {
extern u8 lbl_8045154C[];
}
extern "C" {
extern u8 lbl_80451558[];
}
extern "C" {
extern u8 lbl_80451564[];
}
extern "C" {
extern u8 lbl_80451570[];
}
extern "C" {
extern u8 lbl_8045157C[];
}
extern "C" {
extern u8 lbl_80451588[];
}
extern "C" {
extern u8 lbl_80451594[];
}
extern "C" {
extern u8 lbl_804515A0[];
}
extern "C" {
extern u8 lbl_804515AC[];
}
extern "C" {
extern u8 lbl_804515B8[];
}
extern "C" {
extern u8 lbl_804515C4[];
}
extern "C" {
extern u8 lbl_804515D0[];
}
extern "C" {
extern u8 lbl_804515DC[];
}
extern "C" {
extern u8 lbl_804515E8[];
}
extern "C" {
extern u8 lbl_804515F4[];
}
extern "C" {
extern u8 lbl_80451600[];
}
extern "C" {
extern u8 lbl_8045160C[];
}
extern "C" {
extern u8 lbl_80451618[];
}
extern "C" {
extern u8 lbl_80451624[];
}
extern "C" {
extern u8 lbl_80451630[];
}
extern "C" {
extern u8 lbl_8045163C[];
}
extern "C" {
extern u8 lbl_80451648[];
}
extern "C" {
extern u8 lbl_80451654[];
}
extern "C" {
extern u8 lbl_80451660[];
}
extern "C" {
extern u8 lbl_8045166C[];
}
extern "C" {
extern u8 lbl_80451678[];
}
extern "C" {
extern u8 lbl_80451684[];
}
extern "C" {
extern u8 lbl_80451690[];
}
extern "C" {
extern u8 lbl_8045169C[];
}
extern "C" {
extern u8 lbl_804516A8[];
}
extern "C" {
extern u8 lbl_804516B4[];
}
extern "C" {
extern u8 lbl_804516C0[];
}
extern "C" {
extern u8 lbl_804516CC[];
}
extern "C" {
extern u8 lbl_804516D8[];
}
extern "C" {
extern u8 lbl_804516E4[];
}
extern "C" {
extern u8 lbl_804516F0[];
}
extern "C" {
extern u8 lbl_804516FC[];
}
extern "C" {
extern u8 lbl_80451708[];
}
extern "C" {
extern u8 lbl_80451714[];
}
extern "C" {
extern u8 lbl_80451720[];
}
extern "C" {
extern u8 lbl_8045172C[];
}
extern "C" {
extern u8 lbl_80451738[];
}
extern "C" {
extern u8 lbl_80451744[];
}
extern "C" {
extern u8 lbl_80451750[];
}
extern "C" {
extern u8 lbl_8045175C[];
}
extern "C" {
extern u8 lbl_80451768[];
}
extern "C" {
extern u8 lbl_80451774[];
}
extern "C" {
extern u8 lbl_80451780[];
}
extern "C" {
extern u8 lbl_8045178C[];
}
extern "C" {
extern u8 lbl_80451798[];
}
extern "C" {
extern u8 lbl_804517A4[];
}
extern "C" {
extern u8 lbl_804517B0[];
}
extern "C" {
extern u8 lbl_804517BC[];
}
extern "C" {
extern u8 lbl_804517C8[];
}
extern "C" {
extern u8 lbl_804517D4[];
}
extern "C" {
extern u8 lbl_804517E0[];
}
extern "C" {
extern u8 lbl_804517EC[];
}
extern "C" {
extern u8 lbl_804517F8[];
}
extern "C" {
extern u8 lbl_80451804[];
}
extern "C" {
extern u8 lbl_80451810[];
}
extern "C" {
extern u8 lbl_8045181C[];
}
extern "C" {
extern u8 lbl_80451828[];
}
extern "C" {
extern u8 lbl_80451834[];
}
extern "C" {
extern u8 lbl_80451840[];
}
extern "C" {
extern u8 lbl_8045184C[];
}
extern "C" {
extern u8 lbl_80451858[];
}
extern "C" {
extern u8 lbl_80451864[];
}
extern "C" {
extern u8 lbl_80451870[];
}
extern "C" {
extern u8 lbl_8045187C[];
}
extern "C" {
extern u8 lbl_80451888[];
}
extern "C" {
extern u8 lbl_80451894[];
}
extern "C" {
extern u8 lbl_804518A0[];
}
extern "C" {
extern u8 lbl_804518AC[];
}
extern "C" {
extern u8 lbl_804518B8[];
}
extern "C" {
extern u8 lbl_804518C4[];
}
extern "C" {
extern u8 lbl_804518D0[];
}
extern "C" {
extern u8 lbl_804518DC[];
}
extern "C" {
extern u8 lbl_804518E8[];
}
extern "C" {
extern u8 lbl_804518F4[];
}
extern "C" {
extern u8 lbl_80451900[];
}
extern "C" {
extern u8 lbl_8045190C[];
}
extern "C" {
extern u8 lbl_80451918[];
}
extern "C" {
extern u8 lbl_80451924[];
}
extern "C" {
extern u8 lbl_80451930[];
}
extern "C" {
extern u8 lbl_8045193C[];
}
extern "C" {
extern u8 lbl_80451948[];
}
extern "C" {
extern u8 lbl_80451954[];
}
extern "C" {
extern u8 lbl_80451960[];
}
extern "C" {
extern u8 lbl_8045196C[];
}
extern "C" {
extern u8 lbl_80451978[];
}
extern "C" {
extern u8 lbl_80451984[];
}
extern "C" {
extern u8 lbl_80451990[];
}
extern "C" {
extern u8 lbl_8045199C[];
}
extern "C" {
extern u8 lbl_804519A8[];
}
extern "C" {
extern u8 lbl_804519B4[];
}
extern "C" {
extern u8 lbl_804519C0[];
}
extern "C" {
extern u8 lbl_804519CC[];
}
extern "C" {
extern u8 lbl_804519D8[];
}
extern "C" {
extern u8 lbl_804519E4[];
}
extern "C" {
extern u8 lbl_804519F0[];
}
extern "C" {
extern u8 lbl_804519FC[];
}
extern "C" {
extern u8 lbl_80451A08[];
}
extern "C" {
extern u8 lbl_80451A14[];
}
extern "C" {
extern u8 lbl_80451A20[];
}
extern "C" {
extern u8 lbl_80451A2C[];
}
extern "C" {
extern u8 lbl_80451A38[];
}
extern "C" {
extern u8 lbl_80451A44[];
}
extern "C" {
extern u8 lbl_80451A50[];
}
extern "C" {
extern u8 lbl_80451A5C[];
}
extern "C" {
extern u8 lbl_80451A68[];
}
extern "C" {
extern u8 lbl_80451A74[];
}
extern "C" {
extern u8 lbl_80451A80[];
}
extern "C" {
extern u8 lbl_80451A8C[];
}
extern "C" {
extern u8 lbl_80451A98[];
}
extern "C" {
extern u8 lbl_80451AA4[];
}
extern "C" {
extern u8 lbl_80451AB0[];
}
extern "C" {
extern u8 lbl_80451ABC[];
}
extern "C" {
extern u8 lbl_80451AC8[];
}
extern "C" {
extern u8 lbl_80451AD4[];
}
extern "C" {
extern u8 lbl_80451AE0[];
}
extern "C" {
extern u8 lbl_80451AEC[];
}
extern "C" {
extern u8 lbl_80451AF8[];
}
extern "C" {
extern u8 lbl_80451B04[];
}
extern "C" {
extern u8 lbl_80451B10[];
}
extern "C" {
extern u8 lbl_80451B1C[];
}
extern "C" {
extern u8 lbl_80451B28[];
}
extern "C" {
extern u8 lbl_80451B34[];
}
extern "C" {
extern u8 lbl_80451B40[];
}
extern "C" {
extern u8 lbl_80451B4C[];
}
extern "C" {
extern u8 lbl_80451B58[];
}
extern "C" {
extern u8 lbl_80451B64[];
}
extern "C" {
extern u8 lbl_80451B70[];
}
extern "C" {
extern u8 lbl_80451B7C[];
}
extern "C" {
extern u8 lbl_80451B88[];
}
extern "C" {
extern u8 lbl_80451B94[];
}
extern "C" {
extern u8 lbl_80451BA0[];
}
extern "C" {
extern u8 lbl_80451BAC[];
}
extern "C" {
extern u8 lbl_80451BB8[];
}
extern "C" {
extern u8 lbl_80451BC4[];
}
extern "C" {
extern u8 lbl_80451BD0[];
}
extern "C" {
extern u8 lbl_80451BDC[];
}
extern "C" {
extern u8 lbl_80451BE8[];
}
extern "C" {
extern u8 lbl_80451BF4[];
}
extern "C" {
extern u8 lbl_80451C00[];
}
extern "C" {
extern u8 lbl_80451C0C[];
}
extern "C" {
extern u8 lbl_80451C18[];
}
extern "C" {
extern u8 lbl_80451C24[];
}
extern "C" {
extern u8 lbl_80451C30[];
}
extern "C" {
extern u8 lbl_80451C3C[];
}
extern "C" {
extern u8 lbl_80451C48[];
}
extern "C" {
extern u8 lbl_80451C54[];
}
extern "C" {
extern u8 lbl_80451C60[];
}
extern "C" {
extern u8 lbl_80451C6C[];
}
extern "C" {
extern u8 lbl_80451C78[];
}
extern "C" {
extern u8 lbl_80451C84[];
}
extern "C" {
extern u8 lbl_80451C90[];
}
extern "C" {
extern u8 lbl_80451C9C[];
}
extern "C" {
extern u8 lbl_80451CA8[];
}
extern "C" {
extern u8 lbl_80451CB4[];
}
extern "C" {
extern u8 lbl_805D3B70[];
}
extern "C" {
extern u8 lbl_805D3B74[];
}
extern "C" {
extern u8 lbl_805D3B78[];
}
extern "C" {
extern u8 lbl_805D3B7C[];
}
extern "C" {
extern u8 lbl_805D3B80[];
}
extern "C" {
extern u8 lbl_805D3B84[];
}
extern "C" {
extern u8 lbl_805D3B88[];
}
extern "C" {
extern u8 lbl_805D3B8C[];
}
extern "C" {
extern u8 lbl_805D3B90[];
}
extern "C" {
extern u8 lbl_805D3B94[];
}
extern "C" {
extern u8 lbl_805D3B98[];
}
extern "C" {
extern u8 lbl_805D3B9C[];
}
extern "C" {
extern u8 lbl_805D3BA0[];
}
extern "C" {
extern u8 lbl_805D3BA4[];
}
extern "C" {
extern u8 lbl_805D3BA8[];
}
extern "C" {
extern u8 lbl_805D3BAC[];
}
extern "C" {
extern u8 lbl_805D3BB0[];
}
extern "C" {
extern u8 lbl_805D3BB4[];
}
extern "C" {
extern u8 lbl_805D3BB8[];
}
extern "C" {
void render_shadows__7TObjectFv();
}
extern "C" {
void reset_motion_fields__10TObjMotionFv();
}
extern "C" {
void update_object_view_visibility__13TUnk_804B9870Fff();
}
extern void *lbl_804D3A08[14];
extern void *lbl_804D3A40[4];
extern void *lbl_804D3A50[13];
extern void *lbl_804D3A84[4];
extern void *lbl_804D3A94[7];
extern void *lbl_804D3AB0[4];
extern void *lbl_804D3AC0[23];
extern void *lbl_804D3B1C[4];
extern void *lbl_804D3B2C[7];
extern void *lbl_804D3B48[4];
extern void *lbl_804D3B58[7];
extern void *lbl_804D3B74[4];
extern void *lbl_804D3B84[23];
extern void *lbl_804D3BE0[4];
extern void *lbl_804D3BF0[23];
extern void *lbl_804D3C4C[4];
extern void *lbl_804D3C5C[23];
extern void *lbl_804D3CB8[4];
extern void *lbl_804D3CC8[7];
extern void *lbl_804D3CE4[4];
extern void *lbl_804D3CF4[23];
extern void *lbl_804D3D50[4];
extern void *lbl_804D3D60[23];
extern void *lbl_804D3DBC[4];
extern void *lbl_804D3DCC[4];
extern void *lbl_804D3DDC[4];
extern void *lbl_804D3DEC[4];
extern void *lbl_804D3DFC[4];
extern void *lbl_804D3E0C[3];
extern void *lbl_804D3E18[4];
extern void *lbl_804D3E28[3];
extern void *lbl_804D3E34[4];
extern void *lbl_804D3E44[3];
extern void *lbl_804D3E50[4];
extern void *lbl_804D3E60[3];
extern void *lbl_804D3E6C[4];
extern void *lbl_804D3E7C[3];
extern void *lbl_804D3E88[4];
void *lbl_804D3A08[14] = {
    (void *)&lbl_804512A0, (void *)&lbl_804512AC, (void *)&lbl_804512B8, (void *)&lbl_804512C4,
    (void *)&lbl_804512D0, (void *)&lbl_804512DC, (void *)&lbl_804512E8, (void *)&lbl_804512F4,
    (void *)&lbl_80451300, (void *)&lbl_8045130C, (void *)&lbl_80451318, (void *)&lbl_80451324,
    (void *)&lbl_80451330, (void *)0x0,
};
void *lbl_804D3A40[4] = {
    (void *)&lbl_8045133C, (void *)&lbl_804D3A08, (void *)&lbl_805D3B70, (void *)0xd0000,
};
void *lbl_804D3A50[13] = {
    (void *)&lbl_80451348, (void *)&lbl_80451354, (void *)&lbl_80451360, (void *)&lbl_8045136C,
    (void *)&lbl_80451378, (void *)&lbl_80451384, (void *)&lbl_80451390, (void *)&lbl_8045139C,
    (void *)&lbl_804513A8, (void *)&lbl_804513B4, (void *)&lbl_804513C0, (void *)&lbl_804513CC,
    (void *)0x0,
};
void *lbl_804D3A84[4] = {
    (void *)&lbl_804513D8, (void *)&lbl_804D3A50, (void *)&lbl_805D3B74, (void *)0xc0000,
};
void *lbl_804D3A94[7] = {
    (void *)&lbl_804513E4, (void *)&lbl_804513F0, (void *)&lbl_804513FC, (void *)&lbl_80451408,
    (void *)&lbl_80451414, (void *)&lbl_80451420, (void *)0x0,
};
void *lbl_804D3AB0[4] = {
    (void *)&lbl_8045142C, (void *)&lbl_804D3A94, (void *)&lbl_805D3B78, (void *)0x60000,
};
void *lbl_804D3AC0[23] = {
    (void *)&lbl_80451438, (void *)&lbl_80451444, (void *)&lbl_80451450, (void *)&lbl_8045145C,
    (void *)&lbl_80451468, (void *)&lbl_80451474, (void *)&lbl_80451480, (void *)&lbl_8045148C,
    (void *)&lbl_80451498, (void *)&lbl_804514A4, (void *)&lbl_804514B0, (void *)&lbl_804514BC,
    (void *)&lbl_804514C8, (void *)&lbl_804514D4, (void *)&lbl_804514E0, (void *)&lbl_804514EC,
    (void *)&lbl_804514F8, (void *)&lbl_80451504, (void *)&lbl_80451510, (void *)&lbl_8045151C,
    (void *)&lbl_80451528, (void *)&lbl_80451534, (void *)0x0,
};
void *lbl_804D3B1C[4] = {
    (void *)&lbl_80451540, (void *)&lbl_804D3AC0, (void *)&lbl_805D3B7C, (void *)0x160000,
};
void *lbl_804D3B2C[7] = {
    (void *)&lbl_8045154C, (void *)&lbl_80451558, (void *)&lbl_80451564, (void *)&lbl_80451570,
    (void *)&lbl_8045157C, (void *)&lbl_80451588, (void *)0x0,
};
void *lbl_804D3B48[4] = {
    (void *)&lbl_80451594, (void *)&lbl_804D3B2C, (void *)&lbl_805D3B80, (void *)0x60000,
};
void *lbl_804D3B58[7] = {
    (void *)&lbl_804515A0, (void *)&lbl_804515AC, (void *)&lbl_804515B8, (void *)&lbl_804515C4,
    (void *)&lbl_804515D0, (void *)&lbl_804515DC, (void *)0x0,
};
void *lbl_804D3B74[4] = {
    (void *)&lbl_804515E8, (void *)&lbl_804D3B58, (void *)&lbl_805D3B84, (void *)0x60000,
};
void *lbl_804D3B84[23] = {
    (void *)&lbl_804515F4, (void *)&lbl_80451600, (void *)&lbl_8045160C, (void *)&lbl_80451618,
    (void *)&lbl_80451624, (void *)&lbl_80451630, (void *)&lbl_8045163C, (void *)&lbl_80451648,
    (void *)&lbl_80451654, (void *)&lbl_80451660, (void *)&lbl_8045166C, (void *)&lbl_80451678,
    (void *)&lbl_80451684, (void *)&lbl_80451690, (void *)&lbl_8045169C, (void *)&lbl_804516A8,
    (void *)&lbl_804516B4, (void *)&lbl_804516C0, (void *)&lbl_804516CC, (void *)&lbl_804516D8,
    (void *)&lbl_804516E4, (void *)&lbl_804516F0, (void *)0x0,
};
void *lbl_804D3BE0[4] = {
    (void *)&lbl_804516FC, (void *)&lbl_804D3B84, (void *)&lbl_805D3B88, (void *)0x160000,
};
void *lbl_804D3BF0[23] = {
    (void *)&lbl_80451708, (void *)&lbl_80451714, (void *)&lbl_80451720, (void *)&lbl_8045172C,
    (void *)&lbl_80451738, (void *)&lbl_80451744, (void *)&lbl_80451750, (void *)&lbl_8045175C,
    (void *)&lbl_80451768, (void *)&lbl_80451774, (void *)&lbl_80451780, (void *)&lbl_8045178C,
    (void *)&lbl_80451798, (void *)&lbl_804517A4, (void *)&lbl_804517B0, (void *)&lbl_804517BC,
    (void *)&lbl_804517C8, (void *)&lbl_804517D4, (void *)&lbl_804517E0, (void *)&lbl_804517EC,
    (void *)&lbl_804517F8, (void *)&lbl_80451804, (void *)0x0,
};
void *lbl_804D3C4C[4] = {
    (void *)&lbl_80451810, (void *)&lbl_804D3BF0, (void *)&lbl_805D3B8C, (void *)0x160000,
};
void *lbl_804D3C5C[23] = {
    (void *)&lbl_8045181C, (void *)&lbl_80451828, (void *)&lbl_80451834, (void *)&lbl_80451840,
    (void *)&lbl_8045184C, (void *)&lbl_80451858, (void *)&lbl_80451864, (void *)&lbl_80451870,
    (void *)&lbl_8045187C, (void *)&lbl_80451888, (void *)&lbl_80451894, (void *)&lbl_804518A0,
    (void *)&lbl_804518AC, (void *)&lbl_804518B8, (void *)&lbl_804518C4, (void *)&lbl_804518D0,
    (void *)&lbl_804518DC, (void *)&lbl_804518E8, (void *)&lbl_804518F4, (void *)&lbl_80451900,
    (void *)&lbl_8045190C, (void *)&lbl_80451918, (void *)0x0,
};
void *lbl_804D3CB8[4] = {
    (void *)&lbl_80451924, (void *)&lbl_804D3C5C, (void *)&lbl_805D3B90, (void *)0x160000,
};
void *lbl_804D3CC8[7] = {
    (void *)&lbl_80451930, (void *)&lbl_8045193C, (void *)&lbl_80451948, (void *)&lbl_80451954,
    (void *)&lbl_80451960, (void *)&lbl_8045196C, (void *)0x0,
};
void *lbl_804D3CE4[4] = {
    (void *)&lbl_80451978, (void *)&lbl_804D3CC8, (void *)&lbl_805D3B94, (void *)0x60000,
};
void *lbl_804D3CF4[23] = {
    (void *)&lbl_80451984, (void *)&lbl_80451990, (void *)&lbl_8045199C, (void *)&lbl_804519A8,
    (void *)&lbl_804519B4, (void *)&lbl_804519C0, (void *)&lbl_804519CC, (void *)&lbl_804519D8,
    (void *)&lbl_804519E4, (void *)&lbl_804519F0, (void *)&lbl_804519FC, (void *)&lbl_80451A08,
    (void *)&lbl_80451A14, (void *)&lbl_80451A20, (void *)&lbl_80451A2C, (void *)&lbl_80451A38,
    (void *)&lbl_80451A44, (void *)&lbl_80451A50, (void *)&lbl_80451A5C, (void *)&lbl_80451A68,
    (void *)&lbl_80451A74, (void *)&lbl_80451A80, (void *)0x0,
};
void *lbl_804D3D50[4] = {
    (void *)&lbl_80451A8C, (void *)&lbl_804D3CF4, (void *)&lbl_805D3B98, (void *)0x160000,
};
void *lbl_804D3D60[23] = {
    (void *)&lbl_80451A98, (void *)&lbl_80451AA4, (void *)&lbl_80451AB0, (void *)&lbl_80451ABC,
    (void *)&lbl_80451AC8, (void *)&lbl_80451AD4, (void *)&lbl_80451AE0, (void *)&lbl_80451AEC,
    (void *)&lbl_80451AF8, (void *)&lbl_80451B04, (void *)&lbl_80451B10, (void *)&lbl_80451B1C,
    (void *)&lbl_80451B28, (void *)&lbl_80451B34, (void *)&lbl_80451B40, (void *)&lbl_80451B4C,
    (void *)&lbl_80451B58, (void *)&lbl_80451B64, (void *)&lbl_80451B70, (void *)&lbl_80451B7C,
    (void *)&lbl_80451B88, (void *)&lbl_80451B94, (void *)0x0,
};
void *lbl_804D3DBC[4] = {
    (void *)&lbl_80451BA0, (void *)&lbl_804D3D60, (void *)&lbl_805D3B9C, (void *)0x160000,
};
void *lbl_804D3DCC[4] = {
    (void *)&lbl_80451BAC, (void *)&lbl_80451BB8, (void *)&lbl_80451BC4, (void *)0x0,
};
void *lbl_804D3DDC[4] = {
    (void *)&lbl_80451BD0, (void *)&lbl_804D3DCC, (void *)&lbl_805D3BA0, (void *)0x30000,
};
void *lbl_804D3DEC[4] = {
    (void *)&lbl_80451BDC, (void *)&lbl_80451BE8, (void *)&lbl_80451BF4, (void *)0x0,
};
void *lbl_804D3DFC[4] = {
    (void *)&lbl_80451C00, (void *)&lbl_804D3DEC, (void *)&lbl_805D3BA4, (void *)0x30000,
};
void *lbl_804D3E0C[3] = {
    (void *)&lbl_80451C0C, (void *)&lbl_80451C18, (void *)0x0,
};
void *lbl_804D3E18[4] = {
    (void *)&lbl_80451C24, (void *)&lbl_804D3E0C, (void *)&lbl_805D3BA8, (void *)0x20000,
};
void *lbl_804D3E28[3] = {
    (void *)&lbl_80451C30, (void *)&lbl_80451C3C, (void *)0x0,
};
void *lbl_804D3E34[4] = {
    (void *)&lbl_80451C48, (void *)&lbl_804D3E28, (void *)&lbl_805D3BAC, (void *)0x20000,
};
void *lbl_804D3E44[3] = {
    (void *)&lbl_80451C54, (void *)&lbl_80451C60, (void *)0x0,
};
void *lbl_804D3E50[4] = {
    (void *)&lbl_80451C6C, (void *)&lbl_804D3E44, (void *)&lbl_805D3BB0, (void *)0x20000,
};
void *lbl_804D3E60[3] = {
    (void *)&lbl_80451C78, (void *)&lbl_80451C84, (void *)0x0,
};
void *lbl_804D3E6C[4] = {
    (void *)&lbl_80451C90, (void *)&lbl_804D3E60, (void *)&lbl_805D3BB4, (void *)0x20000,
};
void *lbl_804D3E7C[3] = {
    (void *)&lbl_80451C9C, (void *)&lbl_80451CA8, (void *)0x0,
};
void *lbl_804D3E88[4] = {
    (void *)&lbl_80451CB4, (void *)&lbl_804D3E7C, (void *)&lbl_805D3BB8, (void *)0x20000,
};
void *character_making_resource_descriptor_table[19] = {
    (void *)&lbl_804D3A40, (void *)&lbl_804D3A84, (void *)&lbl_804D3AB0, (void *)&lbl_804D3B1C,
    (void *)&lbl_804D3B48, (void *)&lbl_804D3B74, (void *)&lbl_804D3BE0, (void *)&lbl_804D3C4C,
    (void *)&lbl_804D3CB8, (void *)&lbl_804D3CE4, (void *)&lbl_804D3D50, (void *)&lbl_804D3DBC,
    (void *)&lbl_804D3DDC, (void *)&lbl_804D3DFC, (void *)&lbl_804D3E18, (void *)&lbl_804D3E34,
    (void *)&lbl_804D3E50, (void *)&lbl_804D3E6C, (void *)&lbl_804D3E88,
};
void *character_making_action_table[36] = {
    (void *)0x10000, (void *)0x21, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x1, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x1f, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x20, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x1e, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x2f, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x30, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x2e, (void *)0x3f800000, (void *)0x0,
};
__declspec(section ".data") CreationModelNodeState creation_empty_model_node = {0,0};

struct Sel_802902CC {
    u8 pad0[4];
    s32 a4;
    s32 a8;
    s32 c[3];
    s32 d[3];
    s32 e[3];
};

s32 load_resource_from_descriptor(s32, s32, s32, s32, s32, s32);
s32 TObjMotion__ct(void *, void *);
void *mem_alloc(u32 size);
}
extern u32 creation_figure_object;
void request_creation_motion(s32 arg0);
extern s32 chara_select_creation_shape_rel_files[];
extern u32 creation_figure_rotation_y;
void map_shape_region_samples(s32 region, s32 *samples);
extern CreationShapeBlend creation_shape_blend;
s32 clear_creation_shape_eval_masks(f32 *dst, const f32 *a, const f32 *b, const f32 *c);
s32 scan_creation_resources(void *arg0);
u32 relocate_data_block_pointers(u32 arg0, u32 arg1);
extern s32 char_select_active_flag;
void reset_character_creation_figure_rotation(void);
extern s32 lbl_805D3BBC;
extern void *creation_menu_main_obj;
extern const f32 lbl_805DD940;
extern "C" {

void TCharaMaking__bind_head_shape_nodes(CharacterAppearanceFields *appearance, void *model);
void TCharaMaking__bind_body_shape_nodes(CharacterAppearanceFields *appearance, void *model);
void *TCMCharacter__ct(void *arg0, void *arg1);
extern void* creation_region_sample_index_table[24]; extern void* lbl_804D400C[18]; extern void* lbl_804D4054[21];
#define creation_region_sample_index_table ((s32 *)creation_region_sample_index_table)
#define lbl_804D4054 ((s32 *)lbl_804D4054)
#pragma defer_codegen on
}

void TCMCharacter::reset_model_parts() {
    for (s32 i = 0; i < 10; i++) {
        creation_hair_model_parts[i].present = creation_cap_model_parts[i].present = 0;
    }
    for (s32 i = 0; i < 5; i++) {
        creation_head_model_parts[i].present = 0;
    }
    creation_models_ready = 0;
}

s32 TCMCharacter::bind_model_parts(u32 *selected, const char **names, CreationModelPart *parts,
                                 s32 part, s32 model_index) {
    *selected = 0;
    if (names == NULL) {
        return model_index;
    }
    CharacterAppearanceFields *appearance = (CharacterAppearanceFields *)creation_player_character;
    s32 count = class_appearance_table[((TCharaMaking *)creation_player_character)->get_display_index()].counts[part];
    if (count == 0) {
        count = 1;
    }
    s32 i = 0;
    while (i < count) {
        if (*names == NULL) {
            parts->present = 0;
            parts->model = 0;
        } else {
            parts->present = 1;
            parts->model = get_bml_model((BmlResource *)chara_select_preview_resource, model_index++);
        }
        i++;
        names++;
        parts++;
    }
    chara_select_head_node = parts[(&appearance->costume)[part]].model;
    return model_index;
}

void TCMCharacter::load_model_parts() {
    TCharaMaking *appearance = (TCharaMaking *)creation_player_character;
    CharacterClassAppearance *entry = &class_appearance_table[((TCharaMaking *)creation_player_character)->get_display_index()];
    creation_models_ready = 1;
    model = (void *)get_bml_model((BmlResource *)chara_select_preview_resource, 0);
    s32 next = bind_model_parts(&chara_select_hair_node_b, entry->capModels, creation_cap_model_parts, 4, 1);
    next = bind_model_parts(&chara_select_hair_node_a, entry->hairModels, creation_hair_model_parts, 4, next);
    bind_model_parts(&chara_select_head_node, entry->headModels, creation_head_model_parts, 3, next);
    appearance->get_display_index();
}

extern "C" {
void *TCMCharacter__ct(void *motion, void *arg1) {
    CreationTextureCacheEntry *p;
    s32 res;
    CharacterAppearanceFields *cm;

    TObjMotion__ct(motion, arg1);
    *(void **)((s8 *)motion + 0x18) = (void *)lbl_804D4054;
    *(s32 *)((s8 *)motion + 0) = lbl_805D3BBC;
    lbl_805D49B4 = 1;
    cm = creation_player_character;
    char_select_active_flag = 0;
    char_creation_figure_draw_flag = 0;
    creation_figure_object = (u32)motion;
    res = (s32)(int)::operator new(0x440);
    if (res != 0) {
        res = load_resource_from_descriptor(res, 6, ((s32 *)character_making_resource_descriptor_table)[((TCharaMaking *)cm)->get_display_index()], 0, 0, 0);
    }
    chara_select_preview_resource = res;
    for (p = ((CreationTextureCacheEntry *)creation_texture_cache); p < ((CreationTextureCacheEntry *)creation_texture_cache) + 0x80; p++) {
        p->in_use = 0;
        p->hair_textures.present = 0;
        p->head_textures.present = 0;
        p->body_textures.present = 0;
        p->hair_textures.complete = 0;
        p->head_textures.complete = 0;
        p->body_textures.complete = 0;
    }
    char_select_current_entry = 0;
    ((void (*)(int))TAdSinglePlyChrSelectGC__sub_8028ED54)(0);
    char_select_current_entry = 0;
    ((TObjMotion *)motion)->set_field_d8((s32)((void *)character_making_action_table));
    ((TObjMotion *)motion)->set_field_dc(*(s32 *)((s8 *)creation_menu_main_obj + 0x430));
    ((TObjMotion *)motion)->m_b8 = creation_motion_group(creation_player_character);
    ((TObjMotion *)motion)->set_animation(((TObjMotion *)motion)->m_b8);
    *(s32 *)((s8 *)motion + 0xE0) = (s32)mem_alloc(0xC00);
    *(f32 *)((s8 *)motion + 0x40) = lbl_805DD940;
    *(f32 *)((s8 *)motion + 0x3C) = lbl_805DD940;
    *(f32 *)((s8 *)motion + 0x38) = lbl_805DD940;
    ((TObjMotion *)motion)->rotation_z = 0;
    ((TObjMotion *)motion)->rotation_y = 0;
    *(s32 *)((s8 *)motion + 0x5C) = 0;
    load_creation_shape_rel((W_80290250 *)motion);
    reset_character_creation_figure_rotation();
    creation_resource_ready_state = 0;
    return motion;
}
u8 *TAdSinglePlyChrSelectGC__sub_802908CC(u8 *arg0, s16 arg1) {
    CreationTextureCacheEntry *p;
    CreationTextureCacheEntry *end;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804D4054;
        for (p = creation_texture_cache, end = creation_texture_cache + 128; p < end; p++) {
            if (p->in_use != 0) {
                ((TAdSinglePlyChrSelectGC *)p)->update_char_panels();
            }
        }
        ((TAdSinglePlyChrSelectGC *)arg0)->free_field_FC();
        TLobby__sub_8001FE7C((void *)chara_select_preview_resource, 1);
        chara_select_preview_resource = 0;
        ((TCMCharacter *)arg0)->reset_model_parts();
        (*(s32 *)&chara_select_head_node) = 0;
        (*(s32 *)&chara_select_hair_node_b) = 0;
        (*(s32 *)&chara_select_hair_node_a) = 0;
        ((TAdSinglePlyChrSelectGC *)arg0)->m_34 = 0;
        mem_free((void *)(*(s32 *)((s8 *)arg0 + 0xE0)));
        creation_resource_ready_state = 0;
        creation_figure_object = 0;
        lbl_805D49B4 = 0;
        char_creation_figure_draw_flag = 0;
        __dt__10TObjMotionFv((arg0), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
void update_pair__23TAdSinglePlyChrSelectGCFPv(void* p) { TAdSinglePlyChrSelectGC::init_entry_tables(p); ((TCMCharacter *)p)->load_model_parts(); }
void TAdSinglePlyChrSelectGC__sub_80290884(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); }
void TAdSinglePlyChrSelectGC::init_entry_tables(void* _w0) {
    for (s32 i = 0; i < 10; i++) {
        TAdSinglePlyChrSelectGC__sub_80290884(&creation_hair_model_parts[i], lbl_80451CD0);
        TAdSinglePlyChrSelectGC__sub_80290884(&creation_cap_model_parts[i], lbl_80451CD0);
    }
    for (s32 i = 0; i < 5; i++) {
        TAdSinglePlyChrSelectGC__sub_80290884(&creation_head_model_parts[i], lbl_80451CD0);
    }
}
u8 TAdSinglePlyChrSelectGC::is_active() {
    return (u8) (char_select_active_flag == 1);
}
int TAdSinglePlyChrSelectGC__sub_802905B8(void) {  return char_creation_figure_draw_flag; }
void TAdSinglePlyChrSelectGC__sub_802905A4(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); }
}
void reset_creation_shape_set(s32 arg0) {
    TAdSinglePlyChrSelectGC__sub_802905A4((void*)arg0, (void*)((void *)&creation_empty_model_node));
}
#pragma push
#pragma fp_contract on
#pragma opt_common_subs on
#pragma scheduling on
void reset_creation_head_shapes() {
  CreationModelNodeState *p = creation_head_shape_destination.nodes;
  s32 i = 0;
  do
  {
    reset_creation_shape_set((s32)p);
    ++i;
    ++p;
  }
  while (i < 5);
  s32 group = 0;
  do
  {
    CreationModelNodeState *q = creation_head_shape_samples[group].nodes;
    s32 j = 0;
    do
    {
      reset_creation_shape_set((s32)q);
      ++j;
      ++q;
    }
    while (j < 5);
    ++group;
  }
  while (group < 7);
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_common_subs on
#pragma scheduling on
void reset_creation_body_shapes() {
  CreationModelNodeState *p = creation_body_shape_destination.nodes;
  s32 i = 0;
  do
  {
    reset_creation_shape_set((s32)p);
    ++i;
    ++p;
  }
  while (i < 65);
  s32 group = 0;
  do
  {
    CreationModelNodeState *q = creation_body_shape_samples[group].nodes;
    s32 j = 0;
    do
    {
      reset_creation_shape_set((s32)q);
      ++j;
      ++q;
    }
    while (j < 65);
    ++group;
  }
  while (group < 7);
}
#pragma pop

void TCharaMaking__bind_body_shape_nodes(CharacterAppearanceFields *appearance, void *model) {
    reset_creation_body_shapes();
    TObjPlayer::clear_next_entry((s32)model, (u8 *)&creation_body_shape_destination);
    for (s32 i = 0; i < 7; ++i) {
        TObjPlayer::clear_next_entry((s32)char_creation_data_block[0][i], (u8 *)&creation_body_shape_samples[i]);
    }
}
void TCharaMaking__bind_head_shape_nodes(CharacterAppearanceFields *appearance, void *model) {
    reset_creation_head_shapes();
    TObjPlayer::clear_next_entry((s32)model, (u8 *)&creation_head_shape_destination);
    s32 head = appearance->head + 1;
    for (s32 i = 0; i < 7; ++i) {
        TObjPlayer::clear_next_entry((s32)char_creation_data_block[head][i], (u8 *)&creation_head_shape_samples[i]);
    }
}
void TAdSinglePlyChrSelectGC::reset_creation_parts() {
    Sel_802902CC *arg0 = (Sel_802902CC *)this;
    s32 i;
    reset_creation_head_shapes();
    reset_creation_body_shapes();
    TObjPlayer::clear_next_entry((s32)((void *)arg0->a4), (u8 *)((void *)&creation_head_shape_destination));
    TObjPlayer::clear_next_entry((s32)((void *)arg0->a8), (u8 *)((void *)&creation_body_shape_destination));
    for (i = 0; i < 3; i++) {
        s32 t = arg0->c[i];
        TObjPlayer::clear_next_entry((s32)((void *)arg0->d[i]), (u8 *)((u8 *)creation_head_shape_samples + t * 0x28));
        TObjPlayer::clear_next_entry((s32)((void *)arg0->e[i]), (u8 *)((u8 *)creation_body_shape_samples + t * 0x208));
    }
}
void load_creation_shape_rel(W_80290250 *arg0) {
    s32 rc;
    arg0->bufp = ((TQuestVmDownLoadServer *)0x44000)->alloc();
    rc = TLobby::request_file_read((s32)(chara_select_creation_shape_rel_files[((TCharaMaking *)(*(void * *)&creation_player_character))->get_display_index()]), (s32)arg0->bufp, (s32 *)arg0->data, (void **)0);
    arg0->rc = rc;
    if (rc >= 0) {
        if (arg0->rc > 0x44000) {
            return;
        }
    }
}
void TAdSinglePlyChrSelectGC::free_field_FC() {
    TAdSinglePlyChrSelectGC::safe_free(*(s32 *)((s8 *)this + 0xFC));
    *(s32 *)((s8 *)this + 0xFC) = 0;
}

void TCMCharacter::run_task() {
    static void (TCMCharacter::*modes[2])() = {
        &TCMCharacter::apply_character_appearance, &TCMCharacter::update_chara_preview,
    };
    (this->*modes[char_select_active_flag])();
}

#undef creation_region_sample_index_table
#undef lbl_804D4054

void *creation_region_sample_index_table[24] = {
    (void *)0x1, (void *)0x3, (void *)0x0, (void *)0x0,
    (void *)0x4, (void *)0x3, (void *)0x3, (void *)0x5,
    (void *)0x4, (void *)0x1, (void *)0x3, (void *)0x2,
    (void *)0x2, (void *)0x6, (void *)0x3, (void *)0x3,
    (void *)0x5, (void *)0x6, (void *)0x2, (void *)0x6,
    (void *)0x7, (void *)0x8, (void *)0x7, (void *)0x2,
};
void *lbl_804D400C[18] = {
    (void *)0x0, (void *)0x0, (void *)0x3eaaaaab, (void *)0x0,
    (void *)0x3f2aaaab, (void *)0x0, (void *)0x3eaaaaab, (void *)0x3f000000,
    (void *)0x0, (void *)0x3f800000, (void *)0x3eaaaaab, (void *)0x3f800000,
    (void *)0x3f2aaaab, (void *)0x3f800000, (void *)0x3f800000, (void *)0x3f800000,
    (void *)0x3f800000, (void *)0x0,
};
void *lbl_804D4054[21] = {
    (void *)0x0, (void *)0x0, (void *)&TAdSinglePlyChrSelectGC__sub_802908CC, (void *)&run_task__12TCMCharacterFv,
    (void *)&close_if_active__23TAdSinglePlyChrSelectGCFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__10TObjMotionFv, (void *)&vfunc_9__13TUnk_804B9870Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__13TUnk_804B9870Fv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};

#define creation_region_sample_index_table ((s32 *)creation_region_sample_index_table)
#define lbl_804D4054 ((s32 *)lbl_804D4054)

void TCMCharacter::apply_character_appearance() {
    struct Opaque_80290088 *app;
    CharacterAppearanceFields *raw;
    s32 hair;
    s32 head;
    if (fn_8001ED90((void *)chara_select_preview_resource) == 0 || this->shape_rel_ready == 0) {
        return;
    }
    update_pair__23TAdSinglePlyChrSelectGCFPv(this);
    raw = (CharacterAppearanceFields *)creation_player_character;
    app = (struct Opaque_80290088 *)raw;
    hair = raw->hair;
    if ((s32)creation_hair_model_parts[hair].present == 1) {
        chara_select_hair_node_a = creation_hair_model_parts[hair].model;
    }
    if ((s32)creation_cap_model_parts[hair].present == 1) {
        chara_select_hair_node_b = creation_cap_model_parts[hair].model;
    }
    head = ((CharacterAppearanceFields *)app)->head;
    if ((s32)creation_head_model_parts[head].present == 1) {
        chara_select_head_node = creation_head_model_parts[head].model;
    }
    char_creation_data_block = (void ***)relocate_data_block_pointers(this->shape_rel, this->shape_rel_size);
    TCharaMaking__bind_body_shape_nodes((CharacterAppearanceFields *)((CharacterAppearanceFields *)app), this->model);
    TCharaMaking__bind_head_shape_nodes((CharacterAppearanceFields *)((CharacterAppearanceFields *)app), (void *)((void *)chara_select_head_node));
    blend_creation_proportion_shapes(&((CharacterAppearanceFields *)creation_player_character)->width);
    lbl_805D49B4 = 0;
    char_select_active_flag = 1;
}

void TCMCharacter::update_chara_preview() {
    s32 state;
    state = TCharaMaking::query_state();
    TAdSinglePlyChrSelectGC__sub_8028ED54();
    switch (state) {
    case 3:
        if (chara_select_head_node != 0) {
            TCharaMaking__bind_head_shape_nodes((CharacterAppearanceFields *)((CharacterAppearanceFields *)creation_player_character), (void *)((void *)(chara_select_head_node = creation_head_model_parts[((CharacterAppearanceFields *)creation_player_character)->head].model)));
        }
        break;
    case 4: {
        s32 hair = ((CharacterAppearanceFields *)creation_player_character)->hair;
        u32 a = creation_hair_model_parts[hair].model;
        u32 b = creation_cap_model_parts[hair].model;
        chara_select_hair_node_a = a;
        chara_select_hair_node_b = b;
        break;
    }
    }
    blend_creation_proportion_shapes(&((CharacterAppearanceFields *)creation_player_character)->width);
    advance_animation_playback((s32)this);
}

void request_creation_motion(s32 arg0) {
    if (creation_figure_object == 0 || creation_player_character == 0) {
        return;
    }
    ((TObjMotion *)creation_figure_object)->set_field_b8(arg0 * 3 + creation_motion_group(creation_player_character));
}

void TAdSinglePlyChrSelectGC::draw_player_model() { set_motion_interpolation_flag__10TObjMotionFv(this); draw_model_with_callback__10TObjPlayerFv(this); }
void close_if_active__23TAdSinglePlyChrSelectGCFv(u8 * ad_single_ply_chr_select_gc) {
    if ((s32) char_select_active_flag != 0) {
        ((TAdSinglePlyChrSelectGC *)ad_single_ply_chr_select_gc)->draw_creation_figure();
    }
}
void TAdSinglePlyChrSelectGC::draw_creation_figure() {
    u32 v;
    TParticleCtrl::begin_effect_render();
    if (scan_creation_resources(this) == 0) {
        char_creation_figure_draw_flag = 0;
        return;
    }
    {
        char_creation_figure_draw_flag = 1;
        push_matrix();
        translate_matrix_vec3(0, ((u8 *)this) + 0x38);
        rotate_matrix_y(0, creation_figure_rotation_y);
        TObjFish::set_global_param((s32)((u8 *)char_select_current_entry + 0x460));
        this->draw_player_model();
        ((TObjMotion *)((u8 *)this))->get_item_ptr(0x3A);
        push_matrix_from();
        TObjFish::set_global_param((s32)((u8 *)char_select_current_entry + 0x2EC));
        TObjPlayer::play_phase_transition_sound(creation_head_model_parts[*(s16 *)((s8 *)char_select_current_entry + 0xA)].model);
        pop_matrix();
        v = creation_cap_model_parts[*(s16 *)((s8 *)char_select_current_entry + 0xC)].model;
        if (v != 0) {
            TCharaMaking::enable_making();
            ((TObjMotion *)((u8 *)this))->get_item_ptr(0x3B);
            push_matrix_from();
            TObjFish::set_global_param((s32)((u8 *)char_select_current_entry + 0x178));
            TObjPlayer::play_phase_transition_sound(v);
            pop_matrix();
            TCharaMaking::clear_flag_bit0();
        }
        v = creation_hair_model_parts[*(s16 *)((s8 *)char_select_current_entry + 0xC)].model;
        if (v != 0) {
            TCharaMaking::enable_making();
            ((TObjMotion *)((u8 *)this))->get_item_ptr(0x3B);
            push_matrix_from();
            TObjFish::set_global_param((s32)((u8 *)char_select_current_entry + 0x178));
            TCharaMaking::setup_from_data(v, creation_player_character);
            pop_matrix();
            TCharaMaking::clear_flag_bit0();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}
s32 scan_creation_resources(void *arg0) {
    CreationTextureCacheEntry *p;
    CreationTextureCacheEntry *end;
    end = &((CreationTextureCacheEntry *)&creation_texture_cache)[0x80];
    for (p = (CreationTextureCacheEntry *)&creation_texture_cache; p < end; p++) {
        if (p->in_use == 0) {
            continue;
        }
        if (p->hair_textures.present != 0 && p->hair_textures.complete == 0) {
            continue;
        }
        if (p->head_textures.present != 0 && p->head_textures.complete == 0) {
            continue;
        }
        if (p->body_textures.complete == 0) {
            continue;
        }
        if (is_entry_equal__23TAdSinglePlyChrSelectGCFPvPv(p, (void *)creation_player_character) != 0) {
            break;
        }
    }
    if (p == end) {
        if (char_select_current_entry == NULL) {
            creation_resource_ready_state = 0;
            return 0;
        }
        creation_resource_ready_state = 1;
        return 1;
    }
    char_select_current_entry = p;
    creation_resource_ready_state = 2;
    return 1;
}
s32 find_shape_triangle_region(u8 *arg0) {
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f4_2;
    temp_f3 = *(f32 *)((s8 *)arg0 + 0);
    if (temp_f3 > lbl_805DD948) {
        if ((lbl_805DD94C * (temp_f3 - lbl_805DD948)) <= *(f32 *)((s8 *)arg0 + 4)) {
            return 6;
        }
        return 7;
    }
    if (temp_f3 <= lbl_805DD950) {
        temp_f4 = *(f32 *)((s8 *)arg0 + 4);
        if (temp_f3 >= (lbl_805DD948 * temp_f4)) {
            return 0;
        }
        if (temp_f3 <= (lbl_805DD954 * (temp_f4 - lbl_805DD944))) {
            return 1;
        }
        return 2;
    }
    temp_f4_2 = *(f32 *)((s8 *)arg0 + 4);
    if (temp_f3 <= (lbl_805DD954 * (temp_f4_2 - lbl_805DD944))) {
        return 3;
    }
    if (temp_f3 >= (lbl_805DD948 * temp_f4_2)) {
        return 4;
    }
    return 5;
}
void map_shape_region_samples(s32 region, s32 *samples) {
    s32 i;
    for (i = 0; i < 3; i++) {
        s32 sample = creation_region_sample_index_table[i + region * 3];
        if (sample == 7) {
            sample = 4;
        } else if (sample == 8) {
            sample = 0;
        }
        samples[i] = sample;
    }
}

void TAdSinglePlyChrSelectGC::get_sorted_region_samples(s32 *samples) {
    s32 j;
    s32 y;
    s32 x;
    s32 i;
    TCharaMaking__sub_8028E3A0();
    map_shape_region_samples((s32)(((void *)find_shape_triangle_region((u8 *)this))), (s32 *)samples);
    for (i = 0; i < 2; i++) {
        for (j = 2; j > i; j--) {
            x = samples[j];
            y = samples[j - 1];
            if (x < y) {
                samples[j - 1] = x;
                samples[j] = y;
            }
        }
    }
}
#pragma push
#pragma fp_contract on
s32 clear_creation_shape_eval_masks(f32 *dst, const f32 *a, const f32 *b, const f32 *c) {
    s32 i;
    for (i = 0; i < 3; i++) {
        *dst++ = creation_shape_blend.weights[2] * *c++ + (creation_shape_blend.weights[0] * *a++ + creation_shape_blend.weights[1] * *b++);
    }
    return 1;
}

void blend_creation_proportion_shapes(void *point) {
    s32 samples[3];
    u32 flags;
    s32 n;
    s32 m;
    TCharaMaking__sub_8028E3A0();
    calc_shape_region_coefficients(point);
    map_shape_region_samples(creation_shape_blend.region, samples);
    creation_shape_blend.destination = creation_head_shape_destination.nodes;
    creation_shape_blend.sources[0] = creation_head_shape_samples[samples[0]].nodes;
    creation_shape_blend.sources[1] = creation_head_shape_samples[samples[1]].nodes;
    creation_shape_blend.sources[2] = creation_head_shape_samples[samples[2]].nodes;
    for (n = 5; n > 0; n--) {
        if (creation_shape_blend.destination->node != NULL) {
            CreationShapeModel *dst = ((CreationShapeNode *)creation_shape_blend.destination->node)->model;
            if (dst != NULL) {
                f32 *a;
                f32 *b;
                f32 *c;
                s32 k;
                for (k = 0; k < 3; k++) {
                }
                a = ((CreationShapeNode *)creation_shape_blend.sources[0]->node)->model->center;
                b = ((CreationShapeNode *)creation_shape_blend.sources[1]->node)->model->center;
                c = ((CreationShapeNode *)creation_shape_blend.sources[2]->node)->model->center;
                dst->center[0] = creation_shape_blend.weights[2] * c[0] + (creation_shape_blend.weights[0] * a[0] + creation_shape_blend.weights[1] * b[0]);
                dst->center[1] = creation_shape_blend.weights[2] * c[1] + (creation_shape_blend.weights[0] * a[1] + creation_shape_blend.weights[1] * b[1]);
                dst->center[2] = creation_shape_blend.weights[2] * c[2] + (creation_shape_blend.weights[0] * a[2] + creation_shape_blend.weights[1] * b[2]);
            }
            if ((creation_shape_blend.sources[0]->flags | creation_shape_blend.sources[1]->flags | creation_shape_blend.sources[2]->flags) & 1) {
                ((CreationShapeNode *)creation_shape_blend.destination->node)->eval_flags &= ~1;
                clear_creation_shape_eval_masks(((CreationShapeNode *)creation_shape_blend.destination->node)->pos,
                    ((CreationShapeNode *)creation_shape_blend.sources[0]->node)->pos,
                    ((CreationShapeNode *)creation_shape_blend.sources[1]->node)->pos,
                    ((CreationShapeNode *)creation_shape_blend.sources[2]->node)->pos);
            }
            if (creation_shape_blend.sources[0]->flags & 0x10) {
                blend_shape_chunk_vertices();
            }
        }
        creation_shape_blend.destination++;
        creation_shape_blend.sources[0]++;
        creation_shape_blend.sources[1]++;
        creation_shape_blend.sources[2]++;
    }
    creation_shape_blend.destination = creation_body_shape_destination.nodes;
    creation_shape_blend.sources[0] = creation_body_shape_samples[samples[0]].nodes;
    creation_shape_blend.sources[1] = creation_body_shape_samples[samples[1]].nodes;
    creation_shape_blend.sources[2] = creation_body_shape_samples[samples[2]].nodes;
    for (m = 64; m > 0; m--) {
        CreationShapeModel *dst = ((CreationShapeNode *)creation_shape_blend.destination->node)->model;
        if (dst != NULL) {
            f32 *a = ((CreationShapeNode *)creation_shape_blend.sources[0]->node)->model->center;
            f32 *b = ((CreationShapeNode *)creation_shape_blend.sources[1]->node)->model->center;
            f32 *c = ((CreationShapeNode *)creation_shape_blend.sources[2]->node)->model->center;
            dst->center[0] = creation_shape_blend.weights[2] * c[0] + (creation_shape_blend.weights[0] * a[0] + creation_shape_blend.weights[1] * b[0]);
            dst->center[1] = creation_shape_blend.weights[2] * c[1] + (creation_shape_blend.weights[0] * a[1] + creation_shape_blend.weights[1] * b[1]);
            dst->center[2] = creation_shape_blend.weights[2] * c[2] + (creation_shape_blend.weights[0] * a[2] + creation_shape_blend.weights[1] * b[2]);
        }
        flags = creation_shape_blend.sources[0]->flags | creation_shape_blend.sources[1]->flags | creation_shape_blend.sources[2]->flags;
        if (flags & 1) {
            ((CreationShapeNode *)creation_shape_blend.destination->node)->eval_flags &= ~1;
            clear_creation_shape_eval_masks(((CreationShapeNode *)creation_shape_blend.destination->node)->pos,
                ((CreationShapeNode *)creation_shape_blend.sources[0]->node)->pos,
                ((CreationShapeNode *)creation_shape_blend.sources[1]->node)->pos,
                ((CreationShapeNode *)creation_shape_blend.sources[2]->node)->pos);
        }
        if (flags & 4) {
            ((CreationShapeNode *)creation_shape_blend.destination->node)->eval_flags &= ~4;
            clear_creation_shape_eval_masks(((CreationShapeNode *)creation_shape_blend.destination->node)->scl,
                ((CreationShapeNode *)creation_shape_blend.sources[0]->node)->scl,
                ((CreationShapeNode *)creation_shape_blend.sources[1]->node)->scl,
                ((CreationShapeNode *)creation_shape_blend.sources[2]->node)->scl);
        }
        if (flags & 0x10) {
            blend_shape_chunk_vertices();
        }
        creation_shape_blend.destination++;
        creation_shape_blend.sources[0]++;
        creation_shape_blend.sources[1]++;
        creation_shape_blend.sources[2]++;
    }
}
#pragma pop

s32 TAdSinglePlyChrSelectGC::map_button_code(s32 arg0) {
    switch (arg0) {
    case 0x29:
        return 3;
    case 0x2C:
        return 4;
    case 0xFF:
        return -1;
    default:
        return -2;
    }
}
s32 TAdSinglePlyChrSelectGC::count_remaining_slots() {
    CreationTextureCacheEntry *p;
    s32 n;
    n = 2;
    for (p = ((CreationTextureCacheEntry *)&creation_texture_cache); p < &((CreationTextureCacheEntry *)&creation_texture_cache)[0x80]; p++) {
        if (p->in_use != 0) {
            if (p->hair_textures.present != 0 && p->hair_textures.complete == 0) {
                n--;
            }
            if (p->head_textures.present != 0 && p->head_textures.complete == 0) {
                n--;
            }
            if (p->body_textures.complete == 0) {
                n--;
            }
        }
    }
    return n;
}
s32 TAdSinglePlyChrSelectGC::has_matching_entry(void *arg0) {
    CreationTextureCacheEntry *p;
    CreationTextureCacheEntry *end;
    end = (CreationTextureCacheEntry *)((u8 *)((CreationTextureCacheEntry *)&creation_texture_cache) + 0x23600);
    for (p = ((CreationTextureCacheEntry *)&creation_texture_cache); p < end; p++) {
        if (p->in_use != 0 && is_entry_equal__23TAdSinglePlyChrSelectGCFPvPv(p, arg0) != 0) return 1;
    }
    return 0;
}
CreationTextureCacheEntry *TAdSinglePlyChrSelectGC::find_free_slot() {
    CreationTextureCacheEntry *p;
    for (p = creation_texture_cache; p < (CreationTextureCacheEntry *)((u8 *)creation_texture_cache + 0x23600); p++) {
        if (p->in_use == 0) return p;
    }
    return 0;
}
void TAdSinglePlyChrSelectGC__sub_8028F084(CreationTextureCacheEntry *entry, TCharaMaking *appearance) {
    CreationTextureLoadSlot *slot;
    s32 index;
    TCharaMaking__bind_appearance_texture_lists(&entry->hair_textures.present, &entry->head_textures.present, &entry->body_textures.present, appearance);
    index = appearance->get_display_index();
    slot = &entry->hair_textures;
    if (slot->present != 0) {
        slot->request = create_ch_cr_load_afs_texture_req((void *)creation_figure_object, &slot->list, slot, (void *)index);
    }
    slot = &entry->head_textures;
    if (slot->present != 0) {
        slot->request = create_ch_cr_load_afs_texture_req((void *)creation_figure_object, &slot->list, slot, (void *)index);
    }
    slot = &entry->body_textures;
    slot->request = create_ch_cr_load_afs_texture_req((void *)creation_figure_object, &slot->list, slot, (void *)index);
    entry->in_use = 1;
    copy_slot_data__23TAdSinglePlyChrSelectGCFPvPv(entry, appearance);
}
s32 TAdSinglePlyChrSelectGC::evict_char_entries(s32 arg0) {
    s32 n;
    s32 k;
    CreationTextureCacheEntry *p;
    TCharaMaking::query_state();
    n = 0;
    for (k = 4; k >= 1; k--) {
        for (p = (CreationTextureCacheEntry *)&creation_texture_cache[127]; p >= (CreationTextureCacheEntry *)creation_texture_cache; p--) {
            if (p != char_select_current_entry && p->in_use != 0 && (p->hair_textures.present == 0 || p->hair_textures.complete != 0) && (p->head_textures.present == 0 || p->head_textures.complete != 0) && p->body_textures.complete != 0 &&
                count_char_diffs__23TAdSinglePlyChrSelectGCFPvPv(p, creation_player_character) >= k) {
                p->in_use = 0;
                ((TAdSinglePlyChrSelectGC *)p)->update_char_panels();
                if (++n == arg0) {
                    return n;
                }
            }
        }
    }
    return n;
}
void TAdSinglePlyChrSelectGC::update_char_panels() {
    u8 *arg0 = (u8 *)this;
    if (((s32) this->m_down != 0) && ((s32) this->m_up != 0)) {
        release_texture_list(arg0 + 0x178);
    }
    if (((s32) *(s32 *)((s8 *)arg0 + 0x188) != 0) && ((s32) *(s32 *)((s8 *)arg0 + 0x184) != 0)) {
        release_texture_list(arg0 + 0x2EC);
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x2F8) != 0) {
        release_texture_list(arg0 + 0x460);
    }
}

#pragma defer_codegen off
