#include "pso/system/TEndingAB.h"
#include "pso/ui/TAdEndText.h"
#include "pso/misc/TEndingAB_8008CE08.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"

#include "types.h"
#include "pso/misc/TScene.h"

struct EndingTextureName {
    const char *name;
    u32 attributes;
    void *texture;
};
struct EndingTextureList {
    EndingTextureName *entries;
    u32 count;
};
struct EndingWallTextureSet {
    EndingTextureName names[14];
    EndingTextureList list;
};
typedef char EndingTextureNameSize[sizeof(EndingTextureName) == 12 ? 1 : -1];
typedef char EndingWallTextureSetSize[sizeof(EndingWallTextureSet) == 0xB0 ? 1 : -1];

const char ending_texture_name_ed_512kabe_a[] = "ed_512kabe_A";
const char ending_texture_name_ed_512kabe_b[] = "ed_512kabe_B";
const char ending_texture_name_ed_256pict00a[] = "ed_256pict00a";
const char ending_texture_name_ed_256pict01[] = "ed_256pict01";
const char ending_texture_name_ed_256pict02a[] = "ed_256pict02a";
const char ending_texture_name_ed_256pict03a[] = "ed_256pict03a";
const char ending_texture_name_ed_256pict04[] = "ed_256pict04";
const char ending_texture_name_ed_256pict05a[] = "ed_256pict05a";
const char ending_texture_name_ed_256pict06a[] = "ed_256pict06a";
const char ending_texture_name_ed_256pict07a[] = "ed_256pict07a";
const char ending_texture_name_ed_256pict08[] = "ed_256pict08";
const char ending_texture_name_ed_256pict09[] = "ed_256pict09";
const char ending_texture_name_ed_256pict10a[] = "ed_256pict10a";
const char ending_texture_name_ed_256pict11a[] = "ed_256pict11a";
const char ending_texture_name_ed_256pict00b[] = "ed_256pict00b";
const char ending_texture_name_ed_256pict02b[] = "ed_256pict02b";
const char ending_texture_name_ed_256pict03b[] = "ed_256pict03b";
const char ending_texture_name_ed_256pict05b[] = "ed_256pict05b";
const char ending_texture_name_ed_256pict06b[] = "ed_256pict06b";
const char ending_texture_name_ed_256pict07b[] = "ed_256pict07b";
const char ending_texture_name_ed_256pict10b[] = "ed_256pict10b";
const char ending_texture_name_ed_256pict11b[] = "ed_256pict11b";
const char ending_texture_name_edu_256pict00[] = "edu_256pict00";
const char ending_texture_name_edu_256pict01[] = "edu_256pict01";
const char ending_texture_name_edu_256pict02[] = "edu_256pict02";
const char ending_texture_name_edu_256pict03[] = "edu_256pict03";
const char ending_texture_name_edu_256pict04[] = "edu_256pict04";
const char ending_texture_name_edu_256pict05[] = "edu_256pict05";
const char ending_texture_name_edu_256pict06[] = "edu_256pict06";
const char ending_texture_name_edu_256pict07[] = "edu_256pict07";
const char ending_texture_name_edu_256pict08[] = "edu_256pict08";
const char ending_texture_name_edu_256pict09[] = "edu_256pict09";
const char ending_texture_name_edu_256pict10[] = "edu_256pict10";
const char ending_texture_name_edu_256pict11[] = "edu_256pict11";
const char ending_texture_name_edura_256pict00[] = "edura_256pict00";
const char ending_texture_name_edura_256pict01[] = "edura_256pict01";
const char ending_texture_name_edura_256pict02[] = "edura_256pict02";
const char ending_texture_name_edura_256pict03[] = "edura_256pict03";
const char ending_texture_name_edura_256pict04[] = "edura_256pict04";
const char ending_texture_name_edura_256pict05[] = "edura_256pict05";
const char ending_texture_name_edura_256pict06[] = "edura_256pict06";
const char ending_texture_name_edura_256pict07[] = "edura_256pict07";
const char ending_texture_name_edura_256pict08[] = "edura_256pict08";
const char ending_texture_name_edura_256pict09[] = "edura_256pict09";
const char ending_texture_name_edura_256pict10[] = "edura_256pict10";
const char ending_texture_name_edura_256pict11[] = "edura_256pict11";
const char ending_ab_class_name_text[] = "TEndingAB";
extern const char ending_wall_archive_secret[];
extern const char ending_wall_archive_nh[];
extern const char ending_wall_archive_sh[];
extern const char ending_wall_archive_ul[];

const char *ending_ab_class_name = ending_ab_class_name_text;

EndingWallTextureSet ending_wall_texture_sets[4] = {
    {
        {
            {ending_texture_name_ed_512kabe_a, 0, 0},
            {ending_texture_name_ed_512kabe_b, 0, 0},
            {ending_texture_name_ed_256pict00a, 0, 0},
            {ending_texture_name_ed_256pict01, 0, 0},
            {ending_texture_name_ed_256pict02a, 0, 0},
            {ending_texture_name_ed_256pict03a, 0, 0},
            {ending_texture_name_ed_256pict04, 0, 0},
            {ending_texture_name_ed_256pict05a, 0, 0},
            {ending_texture_name_ed_256pict06a, 0, 0},
            {ending_texture_name_ed_256pict07a, 0, 0},
            {ending_texture_name_ed_256pict08, 0, 0},
            {ending_texture_name_ed_256pict09, 0, 0},
            {ending_texture_name_ed_256pict10a, 0, 0},
            {ending_texture_name_ed_256pict11a, 0, 0},
        },
        {ending_wall_texture_sets[0].names, 14}
    },
    {
        {
            {ending_texture_name_ed_512kabe_a, 0, 0},
            {ending_texture_name_ed_512kabe_b, 0, 0},
            {ending_texture_name_ed_256pict00b, 0, 0},
            {ending_texture_name_ed_256pict01, 0, 0},
            {ending_texture_name_ed_256pict02b, 0, 0},
            {ending_texture_name_ed_256pict03b, 0, 0},
            {ending_texture_name_ed_256pict04, 0, 0},
            {ending_texture_name_ed_256pict05b, 0, 0},
            {ending_texture_name_ed_256pict06b, 0, 0},
            {ending_texture_name_ed_256pict07b, 0, 0},
            {ending_texture_name_ed_256pict08, 0, 0},
            {ending_texture_name_ed_256pict09, 0, 0},
            {ending_texture_name_ed_256pict10b, 0, 0},
            {ending_texture_name_ed_256pict11b, 0, 0},
        },
        {ending_wall_texture_sets[1].names, 14}
    },
    {
        {
            {ending_texture_name_ed_512kabe_a, 0, 0},
            {ending_texture_name_ed_512kabe_b, 0, 0},
            {ending_texture_name_edu_256pict00, 0, 0},
            {ending_texture_name_edu_256pict01, 0, 0},
            {ending_texture_name_edu_256pict02, 0, 0},
            {ending_texture_name_edu_256pict03, 0, 0},
            {ending_texture_name_edu_256pict04, 0, 0},
            {ending_texture_name_edu_256pict05, 0, 0},
            {ending_texture_name_edu_256pict06, 0, 0},
            {ending_texture_name_edu_256pict07, 0, 0},
            {ending_texture_name_edu_256pict08, 0, 0},
            {ending_texture_name_edu_256pict09, 0, 0},
            {ending_texture_name_edu_256pict10, 0, 0},
            {ending_texture_name_edu_256pict11, 0, 0},
        },
        {ending_wall_texture_sets[2].names, 14}
    },
    {
        {
            {ending_texture_name_ed_512kabe_a, 0, 0},
            {ending_texture_name_ed_512kabe_b, 0, 0},
            {ending_texture_name_edura_256pict00, 0, 0},
            {ending_texture_name_edura_256pict01, 0, 0},
            {ending_texture_name_edura_256pict02, 0, 0},
            {ending_texture_name_edura_256pict03, 0, 0},
            {ending_texture_name_edura_256pict04, 0, 0},
            {ending_texture_name_edura_256pict05, 0, 0},
            {ending_texture_name_edura_256pict06, 0, 0},
            {ending_texture_name_edura_256pict07, 0, 0},
            {ending_texture_name_edura_256pict08, 0, 0},
            {ending_texture_name_edura_256pict09, 0, 0},
            {ending_texture_name_edura_256pict10, 0, 0},
            {ending_texture_name_edura_256pict11, 0, 0},
        },
        {ending_wall_texture_sets[3].names, 14}
    },
};

struct RecoveredGlobal_8008CE80___vt__9TEndingAB { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8008CE80___vt__9TEndingAB_size[sizeof(RecoveredGlobal_8008CE80___vt__9TEndingAB) == 0x18 ? 1 : -1];

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_8008CE80___vt__9TEndingAB __vt__9TEndingAB;

extern s32 TEndingAB__fade_sequence_state;
void bind_gvm_texture_list(const char *, void *);

extern u32 ending_ab_wall_texture_list;
extern s32 game_difficulty_selection;
void release_texture_list(void*);

void TEndingAB::run_task() { advance_fade_sequence(); }

TEndingAB::~TEndingAB() {}
u8 *__ct__9TEndingABFv(u8 *ending_ab, u8 *arg1) {
    __ct__7TObjectFP7TObject(ending_ab, arg1);
    *(s32 **)((s8 *)ending_ab + 0x18) = &__vt__9TEndingAB.value;
    *(s32 *)((s8 *)ending_ab + 0) = (s32) ending_ab_class_name;
    *(s32 *)((s8 *)ending_ab + 0x1C) = -1;
    TEndingAB__fade_sequence_state = 0;
    *(s32 *)((s8 *)ending_ab + 0x20) = 0xFF;
    *(s32 *)((s8 *)ending_ab + 0x28) = 0;
    *(s32 *)((s8 *)ending_ab + 0x24) = 0;
    ((TEndingAB *)ending_ab)->init_float_table();
    switch (TKeyBoardControl__sub_8000F828()) {
    case 0:
        *(s32 *)((s8 *)ending_ab + 0xEC) = 0x1E;
        break;
    case 1:
        *(s32 *)((s8 *)ending_ab + 0xEC) = 0x19;
        break;
    }
    return ending_ab;
}

void TEndingAB::destroy_instance() {
    if ((u32) ending_ab_wall_texture_list != 0U) {
        release_texture_list((void*)ending_ab_wall_texture_list);
        ending_ab_wall_texture_list = 0U;
    }
}
void TScene::bind_ending_wall_textures() {
    EndingWallTextureSet *base = ending_wall_texture_sets;
    u8 *t;
    if (get_ending_scene_active() != 0) {
        t = (u8 *)&base[3].list;
        (*(u8 * *)&ending_ab_wall_texture_list) = t;
        bind_gvm_texture_list(ending_wall_archive_secret, t);
    } else {
        switch (game_difficulty_selection) {
        case 0:
        case 1:
            t = (u8 *)&base[0].list;
            (*(u8 * *)&ending_ab_wall_texture_list) = t;
            bind_gvm_texture_list(ending_wall_archive_nh, t);
            break;
        case 2:
            t = (u8 *)&base[1].list;
            (*(u8 * *)&ending_ab_wall_texture_list) = t;
            bind_gvm_texture_list(ending_wall_archive_sh, t);
            break;
        case 3:
            t = (u8 *)&base[2].list;
            (*(u8 * *)&ending_ab_wall_texture_list) = t;
            bind_gvm_texture_list(ending_wall_archive_ul, t);
            break;
        }
    }
}

}

__declspec(section ".rodata") extern const char ending_wall_archive_secret[] = "ed_512kabe_AB_Secret";
__declspec(section ".rodata") extern const char ending_wall_archive_nh[] = "ed_512kabe_AB_NH";
__declspec(section ".rodata") extern const char ending_wall_archive_sh[] = "ed_512kabe_AB_SH";
__declspec(section ".rodata") extern const char ending_wall_archive_ul[] = "ed_512kabe_AB_UL";
