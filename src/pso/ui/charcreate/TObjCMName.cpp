#pragma defer_codegen on
#pragma readonly_strings on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/MenuText.h"
#include "pso/ui/charcreate/CreationInput.h"
#include "types.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/UISprite.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/charcreate/TObjCMName.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/ui/charcreate/TObjCMAssignMenu.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"
#include "pso/ui/charcreate/TObjCMMainMenu_8028D9A8.h"
#include "pso/camera/CreationCamera.h"
#include "pso/ui/charcreate/TObjCMProportion.h"
#include "pso/ui/charcreate/TObjCMAutoMkData.h"
#include "pso/ui/charcreate/CharacterCreationModels.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/ui/charcreate/TChCrEffCtrlPl.h"
#include "pso/ui/charcreate/TChCrEffTag.h"
#include "pso/ui/charcreate/TObjCMIcon.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/unk/text_80131ADC.h"
#include "pso/object/TObjLuker.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/unk/text_801E3F24.h"
#include "pso/system/task/TObject.h"

struct Menu_80296D68
{
  u8 pad0[0x1C];
  u8 *app;
  s32 enabled;
  s32 index;
  s32 value;
  s32 limit;
  s32 wrap;
  u8 pad34[4];
  s32 ticks;
  s32 active;
  f32 fade;
  s32 step;
  s32 target;
  s32 columns;
  u8 pad50[8];
  f32 scroll;
};

struct Menu_80297B18 {
    u8 pad0[0x1C];
    void *f1C;
    u8 pad20[0x24 - 0x20];
    s32 *ids;
    s32 count;
    s32 sel;
    s32 f30;
    s32 pulse;
    f32 t;
    f32 tmax;
};

extern "C" {
extern const char *lbl_804DBC0C[];
extern s32 lbl_804DBC40[];
}

typedef void (TObjCMMainMenu::*MenuFn_802987AC)();

struct Making_802952E0
{
  u8 pad0[0x38];
  s16 sel[5];
  s16 color[3];
  f32 shape[2];
};

struct Limits_802952E0
{
  s16 lim[22];
};

struct Auto_802952E0
{
  u8 pad0[0x1C];
  Making_802952E0 *app;
  s32 state;
  s32 ticks;
  s16 color[3];
  u8 pad2E[2];
  f32 shape[2];
  f32 fade;
};

extern "C" {
s32 queue_destruction__7TObjectFv(void *);
s32 play_sound_effect(s32, s32, s32, s32);
void run_task__16TObjCMAssignMenuFv(void *arg0);
f32 fabs_float(f32);
void TCameraCtrl__sub_80068EF0(void);
s32 TQuestVmDownLoadServer__sub_8006EF6C(s32 arg0);
u32 calc_text_width(char *s);
s32 is_active__23TAdSinglePlyChrSelectGCFv();
void TObjCMIcon__sub_802994C8(s32 arg0, s32 *arg1);
s32 TAdSinglePlyChrSelectGC__sub_802905B8();
s32 rand();
void TObjCMMainMenu__sub_80298DA0(int a0);
}

extern s32 creation_resource_ready_state;
extern s32 TObjCMMainMenu__data_805D659C;
void request_creation_motion(s32 arg0);

struct Ent_802964B0 {
    u8 pad0[8];
    s16 f8;
    u8 pad[0x2C - 0xA];
};

struct Hair_802964B0 {
    const char *name;
    u8 pad4[0x14];
    void *vt;
    s32 f1c;
    s32 f20;
    s32 f24;
    s32 f28;
    u8 pad2c[4];
    s32 f30;
    f32 f34;
    s32 a38[3];
};

struct Menu_80296560 {
    u8 pad[0x30];
    s32 count;
    u32 mask;
    u8 pad2[0x8];
    f32 timer;
};

struct Menu_80296648 {
    u8 pad[0x30];
    s32 count;
    u32 mask;
    u8 pad2[0x8];
    f32 timer;
};

struct Chara_80297128 {
    u8 pad0[0x34];
    u32 flags;
    s16 f38[4];
};

struct Menu_80297128 {
    const char *name;
    u8 pad4[0x18 - 0x4];
    void *vt;
    Chara_80297128 *chara;
    s32 f20;
    s32 kind;
    s32 f28;
    s32 count;
    s32 n;
    u32 mask;
    s32 f38;
    s32 f3C;
    f32 f40;
    u8 pad44[0x48 - 0x44];
    s32 f48;
    u8 pad4C[0x58 - 0x4C];
    f32 f58;
};

struct Row_80297128 { s16 v[0x16]; };

struct Menu_80296744 {
    u8 pad[0x30];
    s32 total;
    u8 pad34[0x40 - 0x34];
    f32 timer;
    s32 per;
    u8 pad48[4];
    s32 pages;
    u8 pad50[0x58 - 0x50];
    f32 scroll;
};

struct Owner_80296928 {
    u8 pad[0x34];
    u32 flags;
};

struct Menu_80296928 {
    u8 pad0[0x1C];
    Owner_80296928 *owner;
    u8 pad20[4];
    s32 state;
    u8 pad28[0x38 - 0x28];
    s32 frame;
    u8 pad3C[4];
    f32 timer;
    s32 level;
    s32 page;
    s32 pages;
    s32 count;
    s32 cursor;
};

struct Quad_80297DB8 {
    vec2f p[4];
};

struct Cols_80297DB8 {
    u32 c[4];
};

struct Prim_80297DB8 {
    vec2f *pts;
    u32 *colors;
    s32 start;
    s32 count;
};

struct Menu_80297DB8 {
    u8 pad[0x38];
    f32 alpha;
};

// One entry of the creation main menu: the TObjCMAssignMenu kind it opens and the member it runs
// when chosen (name inferred from its uses).
struct CreationMenuEntry {
    s32 kind;
    void (TObjCMMainMenu::*select)(void *);
};

struct RecoveredGlobal_80298DD4_lbl_8051C07C {
    s32 value;
    u8 remaining[0x14];
};

struct CreationMenuModeList {
    s32 count;
    s32 *entries;
};

typedef char RecoveredGlobal_80298DD4_lbl_8051C07C_size[sizeof(RecoveredGlobal_80298DD4_lbl_8051C07C) == 0x18 ? 1 : -1];

struct Menu_802975DC {
    u8 pad0[0x1C];
    void *f1C;
    u8 pad20[0x24 - 0x20];
    s32 *ids;
    s32 count;
    s32 sel;
    u8 pad30[0x34 - 0x30];
    s32 pulse;
    f32 t;
    f32 tmax;
};

struct M_80298450 { u8 pad[0x38]; f32 f38; };

extern "C" {
void copy_player_visual_record(void *, void *);
void * get_char_index__23TAdSinglePlyChrSelectGCFUi(s32);
s32 __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);
s32 __dt__7TObjectFv(void *, s32);
void __ct__7TObjectFP7TObject(void *);
u8 calc_section_id_from_name();
s32 get_creation_sprite_id__14TObjCMMainMenuFl(int);
void fn_802947A8(void);
int TObjCMName__sub_802948F4(TObjCMName *, char *);
TKeyBoardControl *TKeyBoardControl__ct(void *, TObject *, s32, s32, s32, s32);
int get_keyboard_field_6c__15TWindowMakeTeamFv(TKeyBoardControl *, char *);
void mem_free(void *p);
Hair_802964B0 * __ct__14TObjCMHairMenuFv(Hair_802964B0 *arg0, void *arg1);
void render__16TObjCMAssignMenuFv(Menu_80296928 *self);
void * create__16TObjCMAssignMenuFPvPv(void *arg0, void *arg1);
void * __ct__16TObjCMAssignMenuFv(void *arg0, void *parent, void *kind);
void fn_802972BC(void);
void fn_802972C0(void);
void TObjCMMainMenu__sub_80298310(void);
u8 is_not_dressing_room_mode__14TObjCMMainMenuFv(void);
s32 * TObjCMMainMenu__sub_80298DD4(void);
void fn_802993F0(void);
void fn_8029945C(const vec2f *position);
u32 __cvt_fp2unsigned(f32);
char * strncpy(char *, const char *, u32);
extern u8 __vt__14TObjCMHairMenu[];
extern void *__vt__16TObjCMAssignMenu[];
extern Ent_802964B0 class_appearance_table[];
extern Cols_80297DB8 footer_divider_colors[2];
extern Quad_80297DB8 footer_divider_vertices[2];
extern vec2f lbl_804DBCC8[];
extern RecoveredGlobal_80298DD4_lbl_8051C07C character_creation_name_buffer;
extern f32 ui_sprite_scale;
extern s32 creation_dressing_room_mode_flag;
extern int creation_figure_rotation_y;
extern void *creation_figure_object;
extern s32 lbl_804DBA68[8];
extern s32 lbl_804DBA88[6];
extern s32 lbl_804DBAA0[2];
extern s32 lbl_804DBAA8[3];
extern s32 lbl_804DBAB4[5];

const char *TObjCMMainMenu__name = "TObjCMMainMenu";

// inferred: main_menu_icon_position (fn_8029945C copies it into cm_icon_screen_position)
const vec2f lbl_80464F50 = {614.0f, 434.0f};

CreationMenuEntry TObjCMMainMenu__data_804DB9C8[10] = {
    {3, &TObjCMMainMenu::open_assign_menu},
    {2, &TObjCMMainMenu::open_assign_menu},
    {4, &TObjCMMainMenu::open_hair_menu},
    {0, &TObjCMMainMenu::open_assign_menu},
    {1, &TObjCMMainMenu::open_assign_menu},
    {1, &TObjCMMainMenu::open_assign_menu},
    {-1, &TObjCMMainMenu::open_proportion_menu},
    {-1, &TObjCMMainMenu::open_name_menu},
    {-1, &TObjCMMainMenu::open_auto_mk_menu},
    {-1, &TObjCMMainMenu::confirm_selection},
};

s32 lbl_804DBA68[8] = {1, 2, 3, 4, 6, 7, 8, 9};

s32 lbl_804DBA88[6] = {0, 5, 6, 7, 8, 9};

__declspec(section ".data") s32 lbl_804DBAA0[2] = {7, 9};

s32 lbl_804DBAA8[3] = {2, 3, 9};

s32 lbl_804DBAB4[5] = {0, 5, 9, 7, 9};

s32 lbl_805D3CD4[1] = {9};

CreationMenuModeList creation_menu_mode_lists[6] = {
    {8, lbl_804DBA68}, {6, lbl_804DBA88},
    {2, lbl_804DBAA0}, {3, lbl_804DBAA8},
    {3, lbl_804DBAB4}, {1, lbl_805D3CD4},
};
}

void reset_character_creation_figure_rotation(void);
void draw_creation_ruler_lines(f32 farg0);
extern NJS_POINT2COL lbl_804DBD08;
extern NJS_POINT2COL lbl_804DBD18;
NJS_COLOR lbl_80540988[4];
NJS_POINT2 lbl_80540998[4];
NJS_COLOR lbl_805409B8[4];

// RGBA colour of the hair colour bars (inferred: the alpha byte is set from the fade).
union HairBarColor {
    u32 rgba;
    u8 c[4];
};

extern vec2f lbl_804DBCD0[3];

extern "C" {
void restore_saved_depth_alpha_state();
void render_nodes__7TObjectFv(void*);
void update_menu_reveal__14TObjCMMainMenuFv(M_80298450 *self);
}

s32 *TObjCMMainMenu__sub_80298DD4(void) {
    return &character_creation_name_buffer.value;
}

u8 is_not_dressing_room_mode__14TObjCMMainMenuFv(void) {
    return (u8) (creation_dressing_room_mode_flag == 0);
}

void TObjCMMainMenu::set_speed(f32 farg0) {
    if ((void *) creation_figure_object != NULL) {
        *(f32 *)((s8 *)creation_figure_object + 0x38) = farg0;
    }
}

void TObjCMMainMenu__sub_80298DA0(int a0) { creation_figure_rotation_y = (creation_figure_rotation_y + a0); }

void TObjCMMainMenu::set_selection(int a0) { creation_camera_mode = a0; }

f32 TObjCMMainMenu::get_proportion() {
    return creation_view_shift;
}

f32 TObjCMMainMenu::get_scale() {
    return ui_sprite_scale;
}

void TObjCMMainMenu::clear_task_state() { (*(int *)&TObjCMMainMenu__data_805D659C) = 0; }

TObjCMMainMenu::TObjCMMainMenu(TObject *parent) : TObject(parent) {
    m_name = TObjCMMainMenu__name;
    character = creation_player_character;
    if (!(character->flags & 0xA) && character->classId == TObjCMMainMenu__sub_8028D9A8()->classId) {
        copy_player_visual_record(character, TObjCMMainMenu__sub_8028D9A8());
    }
    strncpy(character->name, (const char *)TObjCMMainMenu__sub_80298DD4(), 0xC);
    character->name[0xC] = 0;
    character->extraModel = 0;
    character->flags &= ~0xA;
    if (character->section == -1) {
        if (character->flags & 0xA) {
            mode = 2;
        } else if (!(character->classFlags & 0x10)) {
            mode = 0;
        } else {
            mode = 1;
        }
    } else if (character->flags & 0xA) {
        mode = 5;
    } else if (!(character->classFlags & 0x10)) {
        mode = 3;
    } else {
        mode = 4;
    }
    entry_count = creation_menu_mode_lists[mode].count;
    entries = creation_menu_mode_lists[mode].entries;
    TObjCMMainMenu__data_805D659C = 0;
    selected_entry = 0;
    creation_menu_selected_entry = entries[selected_entry];
    fn_802993F0();
    reveal = 0.0f;
    submenu_fade = 0.0f;
    slide_offset = 0.0f;
    unknown44 = 0.0f;
    progress = 0.0f;
    idle_ticks = 0;
    preview = 0.0f;
    set_speed(30.0f);
    nodes = new TObject(NULL);
    fn_802947A8();
    fn_8029945C(&lbl_80464F50);
    sub_802972C4();
}

TObjCMMainMenu::~TObjCMMainMenu() {
    if (nodes != NULL) {
        delete nodes;
        nodes = NULL;
    }
    character->nameColor = -1;
    character->version = 2;
}

TObjCMMainMenu *TObjCMMainMenu::create(TObject *parent) {
    return new TObjCMMainMenu(parent);
}

#pragma push
#pragma fp_contract on
void TObjCMMainMenu::run_task() {
    f32 sp8;

    TChCrCharSelect::reset_proportions();
    rand();
    ((void (*)(void *, int))update_menu_reveal__14TObjCMMainMenuFv)(this, this->reveal_ticks++);
    update_submenu_fade();
    update_slide_offset();
    static MenuFn_802987AC table[7] = {
        &TObjCMMainMenu::handle_creation_input, &TObjCMMainMenu::sub_8029862C, &TObjCMMainMenu::sub_80298534,
        &TObjCMMainMenu::sub_8029862C, &TObjCMMainMenu::sub_8029862C, &TObjCMMainMenu::sub_80298518,
        &TObjCMMainMenu::sub_802984FC,
    };
    (this->*table[TObjCMMainMenu__data_805D659C])();
    creation_menu_selected_entry = this->entries[this->selected_entry];
    TObjCMMainMenu::update_random_proportion_action(this);
    ((void (*)(void *))TObjCMMainMenu__sub_80298310)(this);
    switch (TObjCMMainMenu__data_805D659C) {
    case 4:
    case 6:
        if (this->preview > 0.0f) {
            if ((this->preview += -0.2f) < 0.0f) {
                this->preview = 0.0f;
            }
        }
        break;
    default:
        if (is_active__23TAdSinglePlyChrSelectGCFv() != 0 && TAdSinglePlyChrSelectGC__sub_802905B8() != 0) {
            if (this->preview < 1.0f) {
                f32 step = 0.083333336f;
                if (this->preview > 0.5833333f) {
                    step *= -0.8f * ((this->preview - 0.5833333f) / 0.4166667f) + 1.0f;
                }
                f32 v = (this->preview += step);
                if (v > 1.0f) {
                    this->preview = 1.0f;
                }
            }
        } else {
            this->preview = 0.0f;
        }
        break;
    }
    TObjCMMainMenu::set_speed(30.0f * (1.0f - this->preview));
    get_creation_pad_stick(0, &sp8);
    if (sp8 > 0.0f || creation_buttons_held(0xF0) != 0) {
        if (this->idle_ticks > 0) {
            request_creation_motion(0);
        }
        this->idle_ticks = 0;
    } else {
        this->idle_ticks++;
        if (this->idle_ticks == 0x384) {
            request_creation_motion(1);
        } else if (this->idle_ticks == 0x546) {
            request_creation_motion(2);
        } else if (this->idle_ticks > 0x546) {
            this->idle_ticks = 0x546;
        }
    }
    ((TObject *)(this->nodes))->run_tasks();
    ((void (*)(void *))fn_802972C0)(this);
}

#pragma pop
void TObjCMMainMenu::handle_creation_input() {
    s32 temp_r0;
    s32 temp_r3;
    if (((s32 (*)(void))is_not_dressing_room_mode__14TObjCMMainMenuFv)() != 0) {
        TChCrEffTag::set_eff_tag(1);
    } else {
        TChCrEffTag::set_eff_tag(2);
    }
    if (is_active__23TAdSinglePlyChrSelectGCFv() != 0) {
        if (character->section == -1 && creation_buttons_pressed(2) != 0) {
            play_sound_effect(0x53704, 0, 0, 0);
            TObjCMMainMenu__sub_8028D9B4(character);
            this->delay = 7;
            TObjCMMainMenu__data_805D659C = 6;
            return;
        }
        if (creation_direction_repeated(0x20) != 0) {
            temp_r3 = this->selected_entry + 1;
            this->selected_entry = temp_r3;
            if (temp_r3 >= (s32) this->entry_count) {
                this->selected_entry = 0;
            }
            play_sound_effect(0x54100, 0, 0, 0);
        } else if (creation_direction_repeated(0x10) != 0) {
            temp_r0 = this->selected_entry - 1;
            this->selected_entry = temp_r0;
            if (temp_r0 < 0) {
                this->selected_entry = (this->entry_count - 1);
            }
            play_sound_effect(0x54100, 0, 0, 0);
        }
        if (creation_buttons_pressed(4) != 0) {
            CreationMenuEntry *entry = &TObjCMMainMenu__data_804DB9C8[entries[selected_entry]];
            (this->*entry->select)(entry);
        }
    }
}

void TObjCMMainMenu::sub_8029862C() {  }

#pragma push
#pragma fp_contract on
void TObjCMMainMenu::sub_80298534() {
    f32 temp_f2;
    f32 fv;
    s32 temp_r0;
    this->progress += 0.013333334f;
    temp_r0 = this->delay - 1;
    this->delay = temp_r0;
    if (temp_r0 < 0) {
        this->delay = 0;
    }
    if (((s32) creation_resource_ready_state == 2) || ((s32) this->delay == 0)) {
        temp_f2 = this->progress;
        if (temp_f2 < 0.8f) {
            this->progress = (f32) ((0.25f * (0.8f - temp_f2)) + temp_f2);
        }
        fv = this->progress;
        if (fv > 1.0f) {
            this->progress = 1.0f;
        }
        if (creation_buttons_pressed(4) != 0) {
            play_sound_effect(0x52D01, 0, 0, 0);
            this->delay = 7;
            TObjCMMainMenu__data_805D659C = 5;
            TObjCMMainMenu::create_fade((void *)7, (void *)1);
        }
    } else {
        fv = this->progress;
        if (fv > 0.8f) {
            this->progress = 0.8f;
        }
    }
}

#pragma pop
void TObjCMMainMenu::sub_80298518() {
    s32 temp_r0;

    temp_r0 = this->delay - 1;
    this->delay = temp_r0;
    if (temp_r0 < 0) {
        TObjCMMainMenu__data_805D659C = 3;
    }
}

void TObjCMMainMenu::sub_802984FC() {
    s32 temp_r0;

    temp_r0 = this->delay - 1;
    this->delay = temp_r0;
    if (temp_r0 < 0) {
        TObjCMMainMenu__data_805D659C = 4;
    }
}

#pragma push
#pragma fp_contract on
void TObjCMMainMenu::update_menu_reveal() {
    switch (TObjCMMainMenu__data_805D659C) {
    case 3:
    case 4:
    case 5:
    case 6:
        if ((reveal += -0.16666667f) < 0.0f) {
            reveal = 0.0f;
        }
        break;
    default:
        reveal += 0.008333334f;
        if (is_active__23TAdSinglePlyChrSelectGCFv() != 0) {
            reveal += 0.25f * (1.0f - reveal);
        }
        if (reveal > 1.0f) {
            reveal = 1.0f;
        }
        break;
    }
}

#pragma pop
void TObjCMMainMenu::update_submenu_fade() {
    switch (TObjCMMainMenu__data_805D659C) {
    case 0:
        if ((submenu_fade += 0.083333336f) > 1.0f) {
            submenu_fade = 1.0f;
        }
        break;
    default:
        if ((submenu_fade += -0.22222222f) < 0.0f) {
            submenu_fade = 0.0f;
        }
        break;
    }
}

void TObjCMMainMenu::update_slide_offset() {
    switch (TObjCMMainMenu__data_805D659C) {
    case 1:
        if ((slide_offset += -0.22222222f) < 0.0f) {
            slide_offset = 0.0f;
        }
        break;
    default:
        if ((slide_offset += 0.083333336f) > 1.0f) {
            slide_offset = 1.0f;
        }
        break;
    }
}

void TObjCMMainMenu::update_random_proportion_action(void * _w0) {
    f32 right_trigger_ratio;
    f32 temp_f31_2;
    if (is_active__23TAdSinglePlyChrSelectGCFv() != 0) {
        switch (TObjCMMainMenu__data_805D659C) {
        case 0:
        case 1:
            right_trigger_ratio = TObjCMProportion::get_right_trigger_ratio();
            temp_f31_2 = TObjCMProportion::get_ratio() - right_trigger_ratio;
            if (fabs_float(temp_f31_2) > 0.05f) {
                TObjCMMainMenu__sub_80298DA0((s32) (1092.0f * temp_f31_2));
            }
            break;
        }
    }
}

void TObjCMMainMenu__sub_80298310(void) {  }

void TObjCMMainMenu::render() {
    set_depth_buffer_settings_1();
    draw_footer_divider();
    sub_80297B18();
    sub_802979BC();
    render_nodes__7TObjectFv(nodes);
    draw_root_menu();
    static void (TObjCMMainMenu::*table[7])() = {
        &TObjCMMainMenu::sub_802981BC, 0, &TObjCMMainMenu::sub_80297EF4,
        0, 0, 0, 0,
    };
    void (TObjCMMainMenu::*action)() = table[TObjCMMainMenu__data_805D659C];
    if (action) (this->*action)();
    restore_saved_depth_alpha_state();
    ((void (*)(void*))fn_802972BC)(this);
}

void TObjCMMainMenu::sub_802981BC() {  }

const char *lbl_804DBC0C[13] = {
    "HUmar", "HUnewearl", "HUcast", "RAmar", "RAcast", "RAcaseal", "FOmarl",
    "FOnewm", "FOnewearl", "HUcaseal", "FOmar", "RAmarl", "???",
};
s32 lbl_804DBC40[10] = {42, 43, 44, 45, 46, 47, 48, 49, 50, 51};
char lbl_805D3CD8[4] = "???";

void TObjCMMainMenu::sub_80297EF4() {
    f32 scale = get_scale();
    f32 alpha;
    if (progress >= 0.8f) {
        alpha = 1.0f;
    } else {
        alpha = progress / 0.8f;
    }
    vec2f pos;
    pos.x = 243.0f - get_creation_sprite_id__14TObjCMMainMenuFl(154);
    pos.y = 173.0f;
    draw_ui_sprite(154, &pos, -3.0625f, alpha);
    pos.x = 242.0f - get_creation_sprite_id__14TObjCMMainMenuFl(150);
    pos.y = 210.0f;
    draw_ui_sprite(150, &pos, -3.0625f, alpha);
    pos.x = 202.0f - get_creation_sprite_id__14TObjCMMainMenuFl(153);
    pos.y = 246.0f;
    draw_ui_sprite(153, &pos, -3.0625f, alpha);

    u32 color = ((u32)(255.0f * alpha) << 24) | 0xFFFFFF;
    int char_class = character->classId;
    if (character->flags & 2) {
        char_class = 12;
    }
    TCameraCtrl::restore_full_screen_view();
    draw_menu_text(263.0f, 172.0f * scale, lbl_804DBC0C[char_class], color);
    TCameraCtrl__sub_80068EF0();

    u32 name_color = character->nameColor;
    if (!(name_color & 0xFF000000)) {
        name_color = 0xFFFFFFFF;
    }
    // the name keeps its RGB; the alpha comes from the fade
    static const u32 rgb_mask = 0x00FFFFFF;
    name_color &= rgb_mask;
    TCameraCtrl::restore_full_screen_view();
    draw_menu_text(263.0f, 209.0f * scale, character->name, name_color | (color & 0xFF000000));
    TCameraCtrl__sub_80068EF0();

    if (progress <= 0.8f) {
        return;
    }
    f32 section_alpha = (progress - 0.8f) / 0.19999999f;
    if (!(character->flags & 1)) {
        vec2f icon_pos;
        icon_pos.x = 212.0f;
        icon_pos.y = 234.0f;
        draw_ui_sprite(lbl_804DBC40[character->section], &icon_pos, -3.0625f, section_alpha);
    }
    const char *section_name = (const char *)TObjLuker::get_stat_table_entry(character->section);
    if (character->flags & 1) {
        section_name = lbl_805D3CD8;
    }
    TCameraCtrl::restore_full_screen_view();
    draw_menu_text(263.0f, 247.0f * scale, section_name, ((u32)(255.0f * section_alpha) << 24) | 0xFFFFFF);
    TCameraCtrl__sub_80068EF0();
}
Cols_80297DB8 footer_divider_colors[2] = {
    {{0x00C7C7C7, 0x80C7C7C7, 0x80C7C7C7, 0x00C7C7C7}},
    {{0x80C7C7C7, 0x80C7C7C7, 0x80C7C7C7, 0x80C7C7C7}},
};
Quad_80297DB8 footer_divider_vertices[2] = {
    {{{275.0f, 0.0f}, {400.0f, 0.0f}, {400.0f, 0.0f}, {275.0f, 0.0f}}},
    {{{400.0f, 0.0f}, {640.0f, 0.0f}, {640.0f, 0.0f}, {400.0f, 0.0f}}},
};

extern "C" {
void TObjCMMainMenu::draw_footer_divider() {
    Menu_80297DB8 *self = (Menu_80297DB8 *)this;
    Prim_80297DB8 prim;
    u32 cols[4];
    f32 s = TObjCMMainMenu::get_scale();
    f32 top = 416.0f * s;
    f32 bot = top + 3.0f * s;
    Cols_80297DB8 *src;
    Quad_80297DB8 *q;
    s32 i;
    s32 j;
    prim.start = 0;
    prim.count = 4;
    for (i = 0; i < 2; i++) {
        q = &footer_divider_vertices[i];
        src = &footer_divider_colors[i];
        q->p[1].y = top;
        q->p[0].y = top;
        q->p[3].y = bot;
        q->p[2].y = bot;
        for (j = 0; j < 4; j++) {
            u32 c = src->c[j];
            cols[j] = (c & 0x00FFFFFF) | (__cvt_fp2unsigned((f32)(c >> 24) * self->alpha) << 24);
        }
        prim.colors = cols;
        prim.pts = q->p;
        ((TWindowCtrlMain *)(&prim))->draw_strip_swap_color(4, 6, -1.8125f);
    }
}
}

#pragma push
#pragma fp_contract on

extern "C" {
void TObjCMMainMenu::sub_80297B18() {
    Menu_80297B18 *m = (Menu_80297B18 *)this;
    u32 color;
    s32 i;
    f32 s;
    f32 step;
    f32 y;
    if (m->ids[m->sel] == 9 && TObjCMMainMenu::validate_character_name((s8 *)m->f1C) == 0) {
        color = ((u32)(255.0f * (1.0f - 0.35f * fabs_float(sin_table_lookup(m->pulse << 10)))) << 24) | 0xFFFFFF;
        s = TObjCMMainMenu::get_scale();
        step = 19.0f * s;
        y = 396.0f * s - step;
        for (i = 0; i < 2; i++) {
            const char *str = (const char *)TQuestVmDownLoadServer__sub_8006EF6C(i + 0x3B);
            f32 x = 604.0f - (f32)calc_text_width((char *)str);
            TCameraCtrl::restore_full_screen_view();
            draw_menu_text(x, y, str, color);
            TCameraCtrl__sub_80068EF0();
            y += step;
        }
    }
    switch (TObjCMMainMenu__data_805D659C) {
    case 0:
        if (is_active__23TAdSinglePlyChrSelectGCFv() != 0) {
            if (m->ids[m->sel] == 9 && TObjCMMainMenu::validate_character_name((s8 *)m->f1C) == 0) {
                s32 icon_ids[] = {1};
                TObjCMIcon__sub_802994C8(1, icon_ids);
            } else if (((s8 *)m->f1C)[0x30] == -1) {
                s32 icon_ids[] = {1, 4};
                TObjCMIcon__sub_802994C8(2, icon_ids);
            } else {
                s32 icon_ids[] = {4};
                TObjCMIcon__sub_802994C8(1, icon_ids);
            }
        } else {
            TObjCMIcon::reset_icon_flags();
        }
        break;
    case 1:
        switch (m->ids[m->sel]) {
        case 7:
            TObjCMIcon::reset_icon_flags();
            break;
        case 8:
            break;
        default:
            s32 icon_ids[] = {3};
            TObjCMIcon__sub_802994C8(1, icon_ids);
            break;
        }
        break;
    case 2:
        if (m->f30 == 0 || creation_resource_ready_state == 2) {
            s32 icon_ids[] = {6};
            TObjCMIcon__sub_802994C8(1, icon_ids);
        } else {
            TObjCMIcon::reset_icon_flags();
        }
        break;
    default:
        TObjCMIcon::reset_icon_flags();
        break;
    }
}
}

#pragma pop

extern "C" {
void TObjCMMainMenu::sub_802979BC() {
    char *name = character->name;
    if ((TObjCMMainMenu__data_805D659C == 0 ||
         (TObjCMMainMenu__data_805D659C == 1 && entries[selected_entry] != 7)) &&
        validate_character_name((s8 *)name)) {
        if ((unknown44 += 0.16666667f) > 1.0f) {
            unknown44 = 1.0f;
        }
    } else if ((unknown44 += -0.083333336f) < 0.0f) {
        unknown44 = 0.0f;
        return;
    }
    if (unknown44 <= 0.0f) {
        return;
    }
    f32 x = 604.0f - (f32)calc_text_width(name);
    u32 name_color = character->nameColor;
    if (!(name_color & 0xFF000000)) {
        name_color = 0xFFFFFFFF;
    }
    // the name keeps its RGB; the alpha comes from the fade
    static const u32 rgb_mask = 0x00FFFFFF;
    name_color &= rgb_mask;
    u32 color = ((u32)(255.0f * unknown44) << 24) | name_color;
    TCameraCtrl::restore_full_screen_view();
    draw_menu_text(x, 396.0f * get_scale(), name, color);
    TCameraCtrl__sub_80068EF0();
}
}

const s32 char_creation_root_menu_tab_table[15] = {
    0xA7, 0xB4, 0xC1, 0xCE, 0xDB, 0xE7, 0xF3, 0x101, 0x10F, 0x11C, 0x129, 0x136, 0x143, 0x14F, 0x15B,
};

#pragma push
#pragma fp_contract on

extern "C" {
void TObjCMMainMenu::draw_root_menu() {
    u8 *arg0 = (u8 *)this;
    Menu_802975DC *m = (Menu_802975DC *)arg0;
    vec2f a;
    vec2f b;
    vec2f c;
    vec2f d;
    f32 t;
    f32 ratio;
    f32 x;
    f32 sq;
    f32 base;
    f32 alpha;
    f32 s;
    s32 i;
    s32 j;
    s32 v;
    s32 e;
    s32 k;
    u8 flag;
    s32 n;
    s32 o;
    s32 q;
    s32 r;

    t = m->t < m->tmax ? m->t : m->tmax;
    if (!(t <= 0.33f)) {
        if (t >= 0.66f) {
            ratio = 1.0f;
        } else {
            ratio = (t - 0.33f) / 0.33f;
        }
        b.y = 1.0f;
        a.y = 80.0f;
        for (i = 0; i < m->count; i++) {
            k = 0;
            v = get_creation_sprite_id__14TObjCMMainMenuFl(m->ids[i] + 0x8F) + 0x90;
            for (j = 0; j < 15; j++) {
                e = char_creation_root_menu_tab_table[j];
                if (v < e) {
                    break;
                }
            }
            x = ratio * ((f32) e - 115.0f) + 115.0f;
            a.x = 115.0f;
            if (is_active__23TAdSinglePlyChrSelectGCFv() != 0 && i == m->sel) {
                k = 2;
                a.x += 9.0f * ((f32 (*)(int))sin_table_lookup)(m->pulse << 10);
            }
            b.x = (x - a.x) / 48.0f;
            draw_ui_sprite_opaque(k + 6, &a, &b, -2.125f);
            a.x = x;
            b.x = 1.0f;
            draw_ui_sprite_opaque(k + 7, &a, &b, -2.125f);
            a.y += 44.0f;
        }
    }
    if (!(t <= 0.0f)) {
        if (t >= 0.33f) {
            alpha = 1.0f;
        } else {
            alpha = t / 0.33f;
        }
        c.x = 95.0f;
        c.y = 80.0f;
        for (n = 0; n < m->count; n++) {
            o = 0;
            if (is_active__23TAdSinglePlyChrSelectGCFv() != 0 && n == m->sel) {
                o = -1;
            }
            draw_ui_sprite(o + 1, &c, -1.8125f, alpha);
            c.y += 44.0f;
        }
    }
    if (!(t <= 0.66f)) {
        x = (t - 0.66f) / 0.33999997f;
        d.x = 144.0f;
        d.y = 93.0f;
        sq = x * x;
        base = 0.6f * sq;
        for (q = 0; q < m->count; q++) {
            flag = 0;
            if (m->ids[q] == 9 && TObjCMMainMenu::validate_character_name((s8 *)m->f1C) == 0) {
                flag = 1;
            }
            r = flag;
            if (is_active__23TAdSinglePlyChrSelectGCFv() != 0 && q == m->sel) {
                s = ((f32 (*)(int))sin_table_lookup)(m->pulse << 10);
                s = 0.25f * s + 1.0f;
                if (s > 1.0f) {
                    s = 1.0f;
                }
                alpha = s * sq;
                if (r) {
                    alpha *= 0.4f;
                }
                draw_ui_sprite(m->ids[q] + 0x8F, &d, -1.8125f, alpha);
            } else {
                alpha = base;
                if (r) {
                    alpha *= 0.4f;
                }
                draw_ui_sprite(m->ids[q] + 0x8F, &d, -1.8125f, alpha);
            }
            d.y += 44.0f;
        }
    }
}
}

#pragma pop

extern "C" {
void TObjCMMainMenu::open_assign_menu(void *) {
    play_sound_effect(0x52D01, 0, 0, 0);
    TObjCMMainMenu__data_805D659C = 1;
    create__16TObjCMAssignMenuFPvPv(nodes, (void *)TObjCMMainMenu__data_804DB9C8[entries[selected_entry]].kind);
}

void TObjCMMainMenu::open_hair_menu(void *) {
    play_sound_effect(0x52D01, 0, 0, 0);
    TObjCMMainMenu__data_805D659C = 1;
    ((TObjCMHairMenu *)nodes)->create();
}

void TObjCMMainMenu::open_auto_mk_menu(void *) {
    play_sound_effect(0x52D01, 0, 0, 0);
    TObjCMMainMenu__data_805D659C = 1;
    TObjCMAutoMkData::create(nodes);
}

void TObjCMMainMenu::open_proportion_menu(void *) {
    play_sound_effect(0x52D01, 0, 0, 0);
    TObjCMMainMenu__data_805D659C = 1;
    TObjCMProportion::create(nodes);
}

void TObjCMMainMenu::open_name_menu(void *) {
    play_sound_effect(0x52D01, 0, 0, 0);
    TObjCMMainMenu__data_805D659C = 1;
    TObjCMName::create(nodes);
}

void TObjCMMainMenu::confirm_selection(void *) {
    if (validate_character_name((s8 *)character->name) == 0) {
        play_sound_effect(0x53F06, 0, 0, 0);
        return;
    }
    play_sound_effect(0x52D01, 0, 0, 0);
    if (character->section == -1) {
        character->section = calc_section_id_from_name();
    } else {
        try_pay_fee();
    }
    set_selection(1);
    reset_character_creation_figure_rotation();
    delay = 60;
    TObjCMMainMenu__data_805D659C = 2;
}

s32 TObjCMMainMenu::try_pay_fee() {
    s32 temp_r4;
    void *temp_r3;

    if (get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF) == NULL) {
        play_sound_effect(0x40018519, 0, 0, 0);
        return 0;
    }
    temp_r3 = get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF);
    temp_r4 = *(s32 *)((s8 *)temp_r3 + 0x36C);
    if (temp_r4 < 0x2710) {
        *(s32 *)((s8 *)temp_r3 + 0x36C) = 0;
        play_sound_effect(0xB20C, 0, 0, 0);
        return 0;
    }
    *(s32 *)((s8 *)temp_r3 + 0x36C) = (temp_r4 - 0x2710);
    play_sound_effect(0x44E03, 0, 0, 0);
    return 1;
}

void TObjCMMainMenu::sub_802972C4() {  }

void fn_802972C0(void) {  }

void fn_802972BC(void) {  }

const char *TObjCMAssignMenu__name = "TObjCMAssignMenu";

void *__ct__16TObjCMAssignMenuFv(void *obj_cm_assign_menu, void *parent, void *kind) {
    u32 bit;
    s32 i;
    ((void (*)(void *, void *))__ct__7TObjectFP7TObject)(obj_cm_assign_menu, parent);
    ((Menu_80297128 *)obj_cm_assign_menu)->vt = __vt__16TObjCMAssignMenu;
    ((Menu_80297128 *)obj_cm_assign_menu)->name = TObjCMAssignMenu__name;
    ((Menu_80297128 *)obj_cm_assign_menu)->chara = (*(Chara_80297128 * *)&creation_player_character);
    ((Menu_80297128 *)obj_cm_assign_menu)->f20 = 0;
    ((Menu_80297128 *)obj_cm_assign_menu)->kind = (s32)kind;
    ((Menu_80297128 *)obj_cm_assign_menu)->count = ((Row_80297128 *)&class_appearance_table)[((TCharaMaking *)(((Menu_80297128 *)obj_cm_assign_menu)->chara))->get_display_index()].v[((Menu_80297128 *)obj_cm_assign_menu)->kind];
    ((Menu_80297128 *)obj_cm_assign_menu)->f28 = ((Menu_80297128 *)obj_cm_assign_menu)->chara->f38[((Menu_80297128 *)obj_cm_assign_menu)->kind];
    ((Menu_80297128 *)obj_cm_assign_menu)->n = 0;
    ((Menu_80297128 *)obj_cm_assign_menu)->mask = 0;
    bit = 1;
    for (i = 0; i < ((Menu_80297128 *)obj_cm_assign_menu)->count; i++) {
        ((Menu_80297128 *)obj_cm_assign_menu)->n++;
        ((Menu_80297128 *)obj_cm_assign_menu)->mask |= bit;
        bit <<= 1;
    }
    ((TObjCMAssignMenu *)obj_cm_assign_menu)->calc_grid_layout();
    ((Menu_80297128 *)obj_cm_assign_menu)->f58 = ((Menu_80297128 *)obj_cm_assign_menu)->f48;
    ((Menu_80297128 *)obj_cm_assign_menu)->f3C = 1;
    ((Menu_80297128 *)obj_cm_assign_menu)->f40 = 0.0f;
    switch (((Menu_80297128 *)obj_cm_assign_menu)->kind) {
    case 0:
        TChCrEffTag::set_eff_tag(6);
        break;
    case 1:
        if (((Menu_80297128 *)obj_cm_assign_menu)->chara->flags & 0x10) {
            TChCrEffTag::set_eff_tag(8);
        } else {
            TChCrEffTag::set_eff_tag(7);
        }
        break;
    case 2:
        TChCrEffTag::set_eff_tag(4);
        break;
    case 3:
        TChCrEffTag::set_eff_tag(3);
        break;
    }
    return obj_cm_assign_menu;
}
}

TObjCMAssignMenu::~TObjCMAssignMenu() {}

void * create__16TObjCMAssignMenuFPvPv(void *parent, void *kind) {
    void *o;
    o = __nw__7TObjectFUl(0x5C);
    if (o != NULL) {
        o = __ct__16TObjCMAssignMenuFv(o, parent, kind);
    }
    return o;
}

#pragma push
#pragma opt_common_subs off
void run_task__16TObjCMAssignMenuFv(void *arg0) {
  s32 step;
  s32 wrap;
  s32 old;
  s16 r;
  s16 *new_var;
  s16 v;
  s32 t;
  f32 fade;
  s32 off;
  Menu_80296D68 *self = (Menu_80296D68 *) arg0;
  u8 *app;
  s32 delta;
  self->ticks++;
  if (self->active == 0)
  {
    if ((self->fade += -0.083333336f) <= 0.0f)
    {
      self->fade = 0.0f;
      ((TObject *)self)->queue_destruction();
    }
    return;
  }
  if ((self->fade += 0.16666667f) > 1.0f)
  {
    self->fade = 1.0f;
  }
  delta = 0;
  if (self->enabled != 0)
  {
    if (creation_direction_repeated(0x80) != 0)
    {
      delta = 1;
    }
    else
      if (creation_direction_repeated(0x40) != 0)
    {
      delta = -1;
    }
    if (self->columns > 1)
    {
      if (creation_direction_repeated(0x20) != 0)
      {
        delta = self->step;
      }
      else
        if (creation_direction_repeated(0x10) != 0)
      {
        delta = -self->step;
      }
    }
  }
  if (delta != 0)
  {
    app = self->app;
    off = (self->index * 2) + 0x38;
    old = *((s16 *) (((s8 *) app) + off));
    *((s16 *) (((s8 *) app) + off)) = old + delta;
    if ((delta == 1) || (delta == (-1)))
    {
      v = *((s16 *) (((s8 *) app) + off));
      if (v >= self->limit)
      {
        *((s16 *) (((s8 *) app) + off)) = 0;
      }
      else
        if (v < 0)
      {
        *((s16 *) (((s8 *) app) + off)) = self->limit - 1;
      }
    }
    else
    {
      step = self->step;
      v = *((s16 *) (((s8 *) app) + off));
      r = old % step;
      wrap = self->wrap;
      if (v >= wrap)
      {
        *((s16 *) (((s8 *) app) + off)) = r;
      }
      else
      {
        if (self->fade)
        {
        }
        if (v < 0)
        {
          t = r;
          while ((t + step) < wrap)
          {
            t += step;
          }
          *((s16 *) (((s8 *) app) + off)) = t;
        }
      }
    }
    new_var = (s16 *) (((s8 *) app) + off);
    if ((*new_var) != old)
    {
      play_sound_effect(0x54100, 0, 0, 0);
    }
    self->value = *new_var;
  }
  ((TObjCMAssignMenu *)self)->calc_grid_layout();
  if (self->scroll < ((f32) self->target))
  {
    self->scroll += 0.33333334f;
    if (self->scroll > ((f32) self->target))
    {
      self->scroll = (f32) self->target;
    }
  }
  else
    if (self->scroll > ((f32) self->target))
  {
    self->scroll -= 0.33333334f;
    if (self->scroll < ((f32) self->target))
    {
      self->scroll = (f32) self->target;
    }
  }
  if ((self->enabled != 0) && (creation_buttons_pressed(6) != 0))
  {
    play_sound_effect(0x53704, 0, 0, 0);
    TObjCMMainMenu::clear_task_state();
    self->active = 0;
  }
  else
    if (self->enabled == 0)
  {
    self->enabled = 1;
  }
}

#pragma pop
void TObjCMAssignMenu::calc_grid_layout() {
    s32 temp_r0;
    s32 var_ctr;
    s32 var_r4;
    s32 var_r6;

    temp_r0 = *(s32 *)((s8 *)this + 0x2C);
    var_r6 = 0;
    var_r4 = 0;
    for (var_ctr = temp_r0; var_ctr > 0; var_ctr--) {
        if (var_r4 == (s32) *(s32 *)((s8 *)this + 0x28)) {
            break;
        }
        var_r6 += 1;
        var_r4 += 1;
    }
    *(s32 *)((s8 *)this + 0x44) = (s32) *(s32 *)((s8 *)this + 0x30);
    *(s32 *)((s8 *)this + 0x48) = 0;
    *(s32 *)((s8 *)this + 0x4C) = 1;
    *(s32 *)((s8 *)this + 0x50) = (s32) *(s32 *)((s8 *)this + 0x30);
    *(s32 *)((s8 *)this + 0x54) = var_r6;
    if ((s32) *(s32 *)((s8 *)this + 0x30) > 0xA) {
        *(s32 *)((s8 *)this + 0x44) = 9;
        *(s32 *)((s8 *)this + 0x48) = (s32) (var_r6 / 9);
        *(s32 *)((s8 *)this + 0x4C) = (s32) ((s32) (*(s32 *)((s8 *)this + 0x30) + 8) / 9);
        *(s32 *)((s8 *)this + 0x54) = (s32) (var_r6 % 9);
        *(s32 *)((s8 *)this + 0x50) = (s32) (*(s32 *)((s8 *)this + 0x30) - (*(s32 *)((s8 *)this + 0x48) * 9));
        if ((s32) *(s32 *)((s8 *)this + 0x50) > 9) {
            *(s32 *)((s8 *)this + 0x50) = 9;
        }
    }
}

__declspec(section ".data") vec2f lbl_804DBCC8[1] = {{56.0f, 146.0f}};

const f32 char_creation_assign_menu_tab_positions[10] = {
    206.0f, 219.0f, 243.0f, 271.0f, 271.0f, 284.0f, 297.0f, 323.0f, 347.0f, 347.0f,
};
const vec2f lbl_80465048 = {0.75f, 0.75f};
const vec2f lbl_80465050 = {1.0f, 0.5f};
const vec2f lbl_80465058 = {0.75f, 0.75f};
const s32 char_creation_assign_sprite_id_table[7] = {0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x29};
const s32 char_creation_assign_icon_sprite_id_table[4] = {0x29, 0x28, 0x27, 0x26};

#pragma push
#pragma fp_contract on
#pragma opt_loop_invariants off
void render__16TObjCMAssignMenuFv(Menu_80296928 *self) {
    vec2f pos;
    vec2f scl;
    vec2f pos2;
    vec2f pos3;
    f32 pulse;
    f32 base;
    f32 alpha;
    f32 w;
    f32 t;
    f32 a;
    f32 step;
    s32 idx;
    s32 i;
    s32 sprite;
    ((TObjCMAssignMenu *)self)->render_assign_slots();
    pulse = 0.25f * sin_table_lookup(self->frame << 10) + 1.0f;
    if (pulse > 1.0f) {
        pulse = 1.0f;
    }
    idx = self->level - 1;
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 10) {
        idx = 9;
    }
    base = char_creation_assign_menu_tab_positions[idx];
    if (!(self->timer <= 0.33f)) {
        if (self->timer >= 0.66f) {
            t = 1.0f;
        } else {
            t = (self->timer - 0.33f) / 0.33f;
        }
        scl.y = 1.0f;
        pos.y = 146.0f;
        w = t * (base - 75.0f) + 75.0f;
        pos.x = 75.0f;
        pos.x = 9.0f * sin_table_lookup(self->frame << 10) + pos.x;
        scl.x = (w - pos.x) / 48.0f;
        draw_ui_sprite_opaque(8, &pos, &scl, -2.75f);
        pos.x = w;
        scl.x = 1.0f;
        draw_ui_sprite_opaque(9, &pos, &scl, -2.75f);
    }
    if (!(self->timer <= 0.0f)) {
        draw_ui_sprite(0, lbl_804DBCC8, -2.4375f,
                       self->timer >= 0.33f ? 1.0f : self->timer / 0.33f);
    }
    if (!(self->timer <= 0.66f)) {
        a = (self->timer - 0.66f) / 0.33999997f;
        pos2.x = 103.0f;
        pos2.y = 150.0f;
        step = 17.0f;
        alpha = a * a;
        for (i = 0; i < self->count; i++) {
            f32 s = alpha;
            sprite = 0x1F;
            if (i == self->cursor) {
                sprite = 0x20;
                if (creation_resource_ready_state != 2) {
                    s = alpha * (0.2f * fabs_float(sin_table_lookup(self->frame << 12)) + 0.2f);
                } else {
                    s = alpha * pulse;
                }
            }
            draw_ui_sprite(sprite, &pos2, -2.4375f, s);
            pos2.x += step;
        }
        if (self->pages > 1) {
            s32 n = self->page;
            pos2.x += 6.0f;
            pos2.y += 20.0f;
            draw_ui_sprite_scaled(n + 0x14, &pos2, &lbl_80465048, -2.4375f, alpha);
        }
        w = base - 347.0f;
        pos3.x = 299.0f + w;
        pos3.y = 149.0f;
        draw_ui_sprite(self->cursor + 0x14, &pos3, -2.4375f, alpha * pulse);
        pos3.x = 305.0f + w;
        pos3.y = 150.0f;
        draw_ui_sprite(0x1E, &pos3, -2.4375f, alpha);
        pos3.x = 324.0f + w;
        pos3.y = 167.0f;
        draw_ui_sprite(self->count + 0x13, &pos3, -2.4375f, alpha);
    }
    switch (self->state) {
    case 0:
        ((TObjCMAssignMenu *)self)->sub_80296648();
        break;
    case 1:
        if (self->owner->flags & 0x10) {
            ((TObjCMAssignMenu *)self)->sub_80296648();
        } else {
            ((TObjCMAssignMenu *)self)->draw_assign_icons();
        }
        break;
    }
}

#pragma pop
#pragma push
#pragma fp_contract on
void TObjCMAssignMenu::render_assign_slots() {
    Menu_80296744 *self = (Menu_80296744 *)this;
    f32 zero;
    f32 a;
    f32 step;
    f32 d;
    f32 t;
    s32 i;
    s32 n;
    s32 j;
    vec2f pos;
    if (self->pages == 1) return;
    t = self->timer;
    a = t * (t * (0.4f * t));
    if (a <= 1e-05f) return;
    zero = 0.0f;
    for (i = 0; i < self->pages; i++) {
        n = self->per;
        d = (f32)i - self->scroll;
        if (i == self->pages - 1) {
            n = self->total - i * self->per;
        }
        if (zero == d) continue;
        if (d < zero) {
            t = 1.0f - d;
            pos.x = 22.0f * t + 84.0f;
            pos.y = -20.0f * t + 168.0f;
        } else if (d > zero) {
            t = 1.0f + d;
            pos.x = -22.0f * t + 124.0f;
            pos.y = 20.0f * t + 148.0f;
        }
        step = 17.0f;
        for (j = 0; j < n; j++) {
            draw_ui_sprite_scaled(0x1F, &pos, &lbl_80465050, -3.0625f, a);
            pos.x += step;
        }
        pos.x += 10.0f;
        pos.y += 5.0f;
        draw_ui_sprite_scaled(i + 0x14, &pos, &lbl_80465058, -3.0625f, a);
    }
}

void TObjCMAssignMenu::sub_80296648() {
    Menu_80296648 *self = (Menu_80296648 *)this;
    s32 off;
    s32 idx;
    u32 bit;
    s32 i;
    f32 step;
    f32 a;
    vec2f pos;
    if (!(self->timer <= 0.66f)) {
        a = (self->timer - 0.66f) / 0.33999997f;
        pos.x = 113.0f;
        step = 17.0f;
        idx = 0;
        off = 0;
        pos.y = 152.0f;
        bit = 1;
        a = a * a;
        for (i = 0; i < self->count; bit <<= 1, off += 4, idx++, i++, pos.x += step) {
            while (!(bit & self->mask)) {
                bit <<= 1;
                idx++;
                off += 4;
            }
            if (idx < 7) draw_ui_sprite(*(s32 *)((u8 *)char_creation_assign_sprite_id_table + off), &pos, -2.4375f, a);
        }
    }
}

void TObjCMAssignMenu::draw_assign_icons() {
    Menu_80296560 *self = (Menu_80296560 *)this;
    s32 idx;
    u32 bit;
    s32 i;
    f32 step;
    f32 a;
    vec2f pos;
    if (!(self->timer <= 0.66f)) {
        a = (self->timer - 0.66f) / 0.33999997f;
        pos.x = 113.0f;
        step = 17.0f;
        idx = 0;
        pos.y = 152.0f;
        bit = 1;
        a = a * a;
        for (i = 0; i < self->count; i++, pos.x += step) {
            while (!(bit & self->mask)) {
                bit <<= 1;
                idx++;
            }
            draw_ui_sprite(char_creation_assign_icon_sprite_id_table[idx], &pos, -2.4375f, a);
            bit <<= 1;
            idx++;
        }
    }
}

#pragma pop
const char *TObjCMHairMenu__name = "TObjCMHairMenu";

Hair_802964B0 *__ct__14TObjCMHairMenuFv(Hair_802964B0 *arg0, void *arg1) {
    s32 i;
    ((void * (*)(void *, void *))__ct__7TObjectFP7TObject)(arg0, arg1);
    arg0->vt = __vt__14TObjCMHairMenu;
    arg0->name = TObjCMHairMenu__name;
    arg0->f1c = (*(s32 *)&creation_player_character);
    arg0->f20 = 0;
    arg0->f24 = 0;
    arg0->f28 = class_appearance_table[((TCharaMaking *)(arg0->f1c))->get_display_index()].f8;
    arg0->f30 = 1;
    arg0->f34 = 0.0f;
    for (i = 0; i < 3; i++) {
        arg0->a38[i] = 0;
    }
    TChCrEffTag::set_eff_tag(5);
    return arg0;
}

TObjCMHairMenu::~TObjCMHairMenu() {}

void *TObjCMHairMenu::create() {
    void *o = __nw__7TObjectFUl(0x44);
    if (o != NULL) {
        o = __ct__14TObjCMHairMenuFv((Hair_802964B0 *)(o), this);
    }
    return o;
}

void TObjCMHairMenu::run_task() {
    s32 temp_r0;
    s32 temp_r0_2;
    s16 temp_r0_4;
    s32 temp_r3;
    CharacterAppearanceFields *app;
    s32 off;

    ticks++;
    if (initialized == 0) {
        initialized = 1;
        return;
    }
    if (active == 0) {
        if ((fade += -0.083333336f) <= 0.0f) {
            fade = 0.0f;
            queue_destruction__7TObjectFv(this);
        }
    } else {
        if ((fade += 0.16666667f) > 1.0f) {
            fade = 1.0f;
        }
        if (creation_direction_repeated(0x20) != 0) {
            temp_r0 = selection + 1;
            selection = temp_r0;
            if (temp_r0 >= 4) {
                selection = 0;
            }
            ((s32 (*)(int, int, int, int))play_sound_effect)(0x54100, 0, 0, 0);
        } else if (creation_direction_repeated(0x10) != 0) {
            temp_r0_2 = selection - 1;
            selection = temp_r0_2;
            if (temp_r0_2 < 0) {
                selection = 3;
            }
            ((s32 (*)(int, int, int, int))play_sound_effect)(0x54100, 0, 0, 0);
        }
        temp_r3 = selection;
        if (temp_r3 == 0) {
            app = appearance;
            if (creation_direction_repeated(0x80) != 0) {
                if (++app->hair >= count) {
                    app->hair = 0;
                }
                ((s32 (*)(int, int, int, int))play_sound_effect)(0x54100, 0, 0, 0);
            } else if (creation_direction_repeated(0x40) != 0) {
                if (--app->hair < 0) {
                    app->hair = count - 1;
                }
                ((s32 (*)(int, int, int, int))play_sound_effect)(0x54100, 0, 0, 0);
            }
        } else {
            app = appearance;
            off = (temp_r3 + 4) * 2 + 0x38;
            if (creation_buttons_pressed(0x80) != 0) {
                *(s16 *)((s8 *)app + off) = *(s16 *)((s8 *)app + off) + 1;
            } else if (creation_buttons_pressed(0x40) != 0) {
                *(s16 *)((s8 *)app + off) = *(s16 *)((s8 *)app + off) - 1;
            } else if (creation_buttons_held(0x80) != 0) {
                *(s16 *)((s8 *)app + off) = *(s16 *)((s8 *)app + off) + 5;
            } else if (creation_buttons_held(0x40) != 0) {
                *(s16 *)((s8 *)app + off) = *(s16 *)((s8 *)app + off) - 5;
            }
            temp_r0_4 = *(s16 *)((s8 *)app + off);
            if (temp_r0_4 > 0xFF) {
                *(s16 *)((s8 *)app + off) = 0xFF;
            } else if (temp_r0_4 < 0) {
                *(s16 *)((s8 *)app + off) = 0;
            }
        }
        if (creation_buttons_pressed(6) != 0) {
            ((s32 (*)(int, int, int, int))play_sound_effect)(0x53704, 0, 0, 0);
            TObjCMMainMenu::clear_task_state();
            active = 0;
        }
    }
}

vec2f lbl_804DBCD0[3] = {{105.0f, 194.0f}, {105.0f, 238.0f}, {105.0f, 282.0f}};

#pragma push
#pragma fp_contract on
const f32 lbl_8046509C[10] = {
    206.0f, 219.0f, 243.0f, 271.0f, 271.0f, 284.0f, 297.0f, 323.0f, 347.0f, 347.0f,
};
const f32 lbl_804650C4[4] = {0.0f, 244.0f, 244.0f, 244.0f};
const vec2f lbl_804650D4[4] = {{107.0f, 210.0f}, {99.0f, 224.0f}, {241.0f, 224.0f}, {249.0f, 210.0f}};
const HairBarColor lbl_804650F4[4] = {{0xFF000000}, {0x00FF0000}, {0x0000FF00}, {0x80808000}};

// render reaches each of the four hair arrays with its own lis/addi (no shared base): pool_data off
#pragma pool_data off
void TObjCMHairMenu::render() {
    ColorLineVertex pts[4];
    u32 cols[4];
    ColorLineList list;
    vec2f pos;
    vec2f scl;
    vec2f pos2;
    vec2f pos3;
    vec2f pos4;
    f32 pulse;
    f32 v;
    f32 w;
    f32 off;
    f32 a;
    f32 base;
    f32 alpha;
    s32 idx;
    s32 hair;
    f32 step;
    f32 hi;
    f32 t;
    f32 r;
    f32 dim;
    f32 scale;

    hair = appearance->hair;
    pulse = 0.25f * sin_table_lookup(ticks << 10) + 1.0f;
    if (pulse > 1.0f) {
        pulse = 1.0f;
    }
    idx = count - 1;
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 10) {
        idx = 9;
    }
    base = lbl_8046509C[idx];
    if (!(fade <= 0.33f)) {
        if (fade >= 0.66f) {
            r = 1.0f;
        } else {
            r = (fade - 0.33f) / 0.33f;
        }
        scl.y = 1.0f;
        pos.y = 146.0f;
        for (s32 i = 0; i < 4; i++) {
            s32 sprite = 0;
            if (i == 0) {
                w = r * (base - 75.0f) + 75.0f;
            } else {
                w = r * (lbl_804650C4[i] - 75.0f) + 75.0f;
            }
            pos.x = 75.0f;
            if (i == selection) {
                sprite = 2;
                pos.x = 9.0f * sin_table_lookup(ticks << 10) + pos.x;
            }
            scl.x = (w - pos.x) / 48.0f;
            draw_ui_sprite_opaque(sprite + 6, &pos, &scl, -2.75f);
            pos.x = w;
            scl.x = 1.0f;
            draw_ui_sprite_opaque(sprite + 7, &pos, &scl, -2.75f);
            pos.y += 44.0f;
        }
    }
    if (!(fade <= 0.0f)) {
        if (fade >= 0.33f) {
            a = 1.0f;
        } else {
            a = fade / 0.33f;
        }
        pos2.x = 56.0f;
        pos2.y = 146.0f;
        for (s32 i = 0; i < 4; i++) {
            s32 sprite = 0;
            if (i == selection) {
                sprite = -1;
            }
            draw_ui_sprite(sprite + 1, &pos2, -2.4375f, a);
            pos2.y += 44.0f;
        }
    }
    if (!(fade <= 0.66f)) {
        t = (fade - 0.66f) / 0.33999997f;
        pos3.x = 103.0f;
        pos3.y = 150.0f;
        alpha = t * t;
        for (s32 i = 0; i < count; i++) {
            f32 s = alpha;
            s32 sprite = 0x1F;
            if (selection != 0) {
                s *= 0.6f;
            }
            if (i == hair) {
                sprite = 0x20;
                if (creation_resource_ready_state != 2) {
                    s *= 0.2f * fabs_float(sin_table_lookup(ticks << 12)) + 0.2f;
                } else if (selection == 0) {
                    s *= pulse;
                }
            }
            draw_ui_sprite(sprite, &pos3, -2.4375f, s);
            pos3.x += 17.0f;
        }
        off = base - 347.0f;
        dim = alpha;
        hi = alpha;
        if (selection == 0) {
            hi *= pulse;
        } else {
            hi *= 0.6f;
            dim = hi;
        }
        pos4.x = 299.0f + off;
        pos4.y = 149.0f;
        draw_ui_sprite(hair + 20, &pos4, -2.4375f, hi);
        pos4.x = 305.0f + off;
        pos4.y = 150.0f;
        draw_ui_sprite(0x1E, &pos4, -2.4375f, dim);
        pos4.x = 324.0f + off;
        pos4.y = 167.0f;
        draw_ui_sprite(count + 19, &pos4, -2.4375f, dim);
        for (s32 i = 1; i < 4; i++) {
            f32 s = alpha;
            if (i == selection) {
                s *= pulse;
            } else {
                s *= 0.6f;
            }
            draw_ui_sprite(i + 15, &lbl_804DBCD0[i - 1], -2.4375f, s);
        }

        TCameraCtrl::restore_full_screen_view();
        scale = TObjCMMainMenu::get_scale();
        step = 44.0f * scale;
        list.verts = pts;
        list.colors = cols;
        list.unk_8 = 0;
        pts[0].x = 0.1f * (lbl_804650D4[1].x - lbl_804650D4[0].x) + lbl_804650D4[0].x;
        pts[1].x = 1.1f * (lbl_804650D4[1].x - lbl_804650D4[0].x) + lbl_804650D4[0].x;
        pts[2].x = 1.1f * (lbl_804650D4[2].x - lbl_804650D4[3].x) + lbl_804650D4[3].x;
        pts[3].x = 0.1f * (lbl_804650D4[2].x - lbl_804650D4[3].x) + lbl_804650D4[3].x;
        pts[0].y = pts[3].y = 0.1f * (lbl_804650D4[1].y - lbl_804650D4[0].y) + lbl_804650D4[0].y;
        pts[1].y = pts[2].y = 1.1f * (lbl_804650D4[1].y - lbl_804650D4[0].y) + lbl_804650D4[0].y;
        HairBarColor color = lbl_804650F4[3];
        pts[0].y *= scale;
        pts[1].y *= scale;
        pts[2].y *= scale;
        pts[3].y *= scale;
        color.c[3] = 255.0f * t;
        TObjCMHairMenu__sub_801E3F54(&cols[0], TObjCMHairMenu__sub_801E3F54(&cols[1],
            TObjCMHairMenu__sub_801E3F54(&cols[2], TObjCMHairMenu__sub_801E3F54(&cols[3], &color))));
        for (s32 i = 0; i < 3; i++) {
            ((TObjCMHairMenu *)&list)->draw_tri_fan_2d(4, 6, -2.75f);
            pts[0].y += step;
            pts[1].y += step;
            pts[2].y += step;
            pts[3].y += step;
        }
        for (s32 i = 0; i < 3; i++) {
            v = (&appearance->red)[i] / 255.0f;
            if (v != 0.0f) {
                pts[0].x = lbl_804650D4[0].x;
                pts[1].x = lbl_804650D4[1].x;
                pts[2].x = v * (lbl_804650D4[2].x - lbl_804650D4[1].x) + lbl_804650D4[1].x;
                pts[3].x = v * (lbl_804650D4[3].x - lbl_804650D4[0].x) + lbl_804650D4[0].x;
                for (s32 j = 0; j < 4; j++) {
                    pts[j].y = scale * lbl_804650D4[j].y + i * step;
                }
                HairBarColor bar_color = lbl_804650F4[i];
                bar_color.c[3] = 255.0f * t;
                TObjCMHairMenu__sub_801E3F54(&cols[0], TObjCMHairMenu__sub_801E3F54(&cols[1],
                    TObjCMHairMenu__sub_801E3F54(&cols[2], TObjCMHairMenu__sub_801E3F54(&cols[3], &bar_color))));
                ((TObjCMHairMenu *)&list)->draw_tri_fan_2d(4, 6, -2.4375f);
            }
        }
        TCameraCtrl__sub_80068EF0();
    }
}

#pragma pop
const char *TObjCMAutoMkData__name = "TObjCMAutoMkData";

TObjCMAutoMkData::TObjCMAutoMkData(TObject *parent) : TObject(parent) {
    m_name = TObjCMAutoMkData__name;
    appearance = creation_player_character;
    ((TWindowSubSymbolChatPartsSet *)&width)->copy_vec2((u8 *)appearance + 0x48);
    fade = 0.0f;
    state = 0;
    TChCrEffTag::set_eff_tag(0xB);
}

TObjCMAutoMkData::~TObjCMAutoMkData() {
    set_creation_projection_center(1.0f);
}

TObjCMAutoMkData *TObjCMAutoMkData::create(TObject *parent) {
    return new TObjCMAutoMkData(parent);
}

#pragma push
#pragma fp_contract on
void TObjCMAutoMkData::run_task() {
    Auto_802952E0 *self = (Auto_802952E0 *)this;
  f32 x;
  f32 t;
  s16 *lim;
  s16 *sel;
  s32 i;
  s32 v;
  Making_802952E0 **new_var;
  x = TObjCMMainMenu::get_proportion();
  if (self->state != 2)
  {
    if (1.0f == self->fade)
    {
      x += -0.033333335f;
      if (x < 0.0f)
      {
        x = 0.0f;
      }
    }
  }
  else
  {
    x = (x > (1.0f - self->fade)) ? (x) : (1.0f - self->fade);
  }
  set_creation_projection_center(x);
  new_var = &self->app;
  if (self->state == 2)
  {
    if ((self->fade += -0.083333336f) <= 0.0f)
    {
      self->fade = 0.0f;
      queue_destruction__7TObjectFv(self);
    }
    return;
  }
  if ((self->fade += 0.16666667f) > 1.0f)
  {
    self->fade = 1.0f;
  }
  switch (self->state)
  {
    case 1:
    {
      s32 icon_ids[] = {2, 5};
      TObjCMIcon__sub_802994C8(2, icon_ids);
      break;
    }
    case 2:
      break;
    case 3:
      TObjCMIcon::reset_icon_flags();
      break;
  }
  switch (self->state)
  {
    case 0:
      self->state = 1;
      break;
    case 1:
      if (creation_buttons_pressed(2) != 0)
    {
      play_sound_effect(0x53704, 0, 0, 0);
      TObjCMMainMenu::clear_task_state();
      self->state = 2;
      break;
    }
      if (creation_buttons_pressed(4) == 0)
    {
      break;
    }
      lim = ((Limits_802952E0 *)&class_appearance_table)[((TCharaMaking *)(self->app))->get_display_index()].lim;
      sel = (*new_var)->sel;
      for (i = 0; i <= 4; i++, lim++, sel++)
    {
      if ((*lim) >= 2)
      {
        v = (s16) ((0.99f * ((f32) (*lim))) * (3.0517578e-05f * ((f32) ((int)rand()))));
        while (v == (*sel))
        {
          v++;
          if (v >= (*lim))
          {
            v = 0;
          }
        }
        *sel = v;
      }
    }
      self->color[0] = (u8) ((s32) ((128.0f * (3.0517578e-05f * ((f32) ((int)rand())))) + (self->color[0] + 0x40)));
      self->color[1] = (u8) ((s32) ((128.0f * (3.0517578e-05f * ((f32) ((int)rand())))) + (self->color[1] + 0x40)));
      self->color[2] = (u8) ((s32) ((128.0f * (3.0517578e-05f * ((f32) ((int)rand())))) + (self->color[2] + 0x40)));
      if ((self->shape[0] += (0.5f * (3.0517578e-05f * ((f32) ((int)rand())))) + 0.25f) >= 1.0f)
    {
      self->shape[0] -= 1.0f;
    }
      if ((self->shape[1] += (0.5f * (3.0517578e-05f * ((f32) ((int)rand())))) + 0.25f) >= 1.0f)
    {
      self->shape[1] -= 1.0f;
    }
      play_sound_effect(0x52D01, 0, 0, 0);
      self->ticks = 0;
      self->state = 3;
      break;
    case 2:
      break;
    case 3:
      self->ticks++;
      t = ((f32) self->ticks) / 30.0f;
      (*new_var)->color[0] = (s32) (((f32) self->app->color[0]) + (t * ((f32) (self->color[0] - (*new_var)->color[0]))));
      self->app->color[1] = (s32) (((f32) (*new_var)->color[1]) + (t * ((f32) (self->color[1] - self->app->color[1]))));
      self->app->color[2] = (s32) (((f32) self->app->color[2]) + (t * ((f32) (self->color[2] - (*new_var)->color[2]))));
      (*new_var)->shape[0] = (t * (self->shape[0] - self->app->shape[0])) + self->app->shape[0];
      self->app->shape[1] = (t * (self->shape[1] - (*new_var)->shape[1])) + self->app->shape[1];
      if (self->ticks >= 30)
    {
      if (creation_resource_ready_state == 2)
      {
        play_sound_effect(0x52802, 0, 0, 0);
        self->state = 1;
      }
      else
        if (self->ticks >= 150)
      {
        return;
      }
    }
      break;
  }
}

#pragma pop
void TObjCMAutoMkData::render() {
    draw_creation_ruler_lines(*(f32 *)((s8 *)this + 0x38));
}

const char *TObjCMProportion__name = "TObjCMProportion";

TObjCMProportion::TObjCMProportion(TObject *parent) : TObject(parent) {
    m_name = TObjCMProportion__name;
    appearance = creation_player_character;
    initialized = 0;
    active = 1;
    fade = 0.0f;
    TChCrEffTag::set_eff_tag(9);
}

TObjCMProportion::~TObjCMProportion() {
    set_creation_projection_center(1.0f);
}

TObjCMProportion *TObjCMProportion::create(TObject *parent) {
    return new TObjCMProportion(parent);
}

#pragma push
#pragma fp_contract on
void TObjCMProportion::run_task() {
    TObjCMProportion* arg0=this;
    s32 spC;
    f32 sp8;
    f32 temp_f0;
    f32 temp_f1_4;
    f32 var_f1;
    f32 var_f30;
    f32 var_f29;
    CharacterAppearanceFields *temp_r3_3;
    CharacterAppearanceFields *temp_r3_4;

    var_f1 = TObjCMMainMenu::get_proportion();
    if ((s32) arg0->active != 0) {
        if (1.0f == arg0->fade) {
            var_f1 += -0.033333335f;
            if (var_f1 < 0.0f) {
                var_f1 = 0.0f;
            }
        }
    } else {
        temp_f0 = 1.0f - arg0->fade;
        var_f1 = (var_f1 > temp_f0) ? var_f1 : temp_f0;
    }
    set_creation_projection_center(var_f1);
    if ((s32) arg0->initialized == 0) {
        arg0->initialized = 1;
        return;
    }
    if ((s32) arg0->active == 0) {
        if ((arg0->fade += -0.083333336f) <= 0.0f) {
            arg0->fade = 0.0f;
            ((void (*)(TObject*))queue_destruction__7TObjectFv)(arg0);
        }
    } else {
        if ((arg0->fade += 0.16666667f) > 1.0f) {
            arg0->fade = 1.0f;
        }
        get_creation_pad_stick(&spC, &sp8);
        var_f30 = 0.016666668f * (sp8 * sin_table_lookup(spC));
        var_f29 = 0.016666668f * (sp8 * -cos_table_lookup(spC));
        if (0.0f == (fabs_float(var_f30) + fabs_float(var_f29))) {
            if (creation_buttons_held(0x80) != 0) {
                var_f30 = 0.013333335f;
            } else if (creation_buttons_held(0x40) != 0) {
                var_f30 = -0.013333335f;
            }
            if (creation_buttons_held(0x20) != 0) {
                var_f29 = 0.013333335f;
            } else if (creation_buttons_held(0x10) != 0) {
                var_f29 = -0.013333335f;
            }
        }
        arg0->appearance->width += var_f30;
        arg0->appearance->height += var_f29;
        temp_r3_3 = arg0->appearance;
        if (temp_r3_3->width > 0.99f) {
            temp_r3_3->width -= 0.99f;
        } else if (temp_r3_3->width < 0.0f) {
            temp_r3_3->width += 0.99f;
        }
        temp_r3_4 = arg0->appearance;
        temp_f1_4 = temp_r3_4->height;
        if (temp_f1_4 > 0.99f) {
            temp_r3_4->height = (f32) 0.99f;
        } else if (temp_f1_4 < 0.0f) {
            temp_r3_4->height = (f32) 0.0f;
        }
        if (creation_buttons_pressed(6) != 0) {
            ((void (*)(s32, s32, s32, s32))play_sound_effect)(0x53704, 0, 0, 0);
            TObjCMMainMenu::clear_task_state();
            arg0->active = 0;
        }
    }
}

NJS_POINT2 lbl_804DBCE8[4] = {{245.0f, 165.0f}, {395.0f, 165.0f}, {395.0f, 315.0f}, {245.0f, 315.0f}};
NJS_POINT2COL lbl_804DBD08 = {lbl_804DBCE8, lbl_80540988, NULL, 4};
NJS_POINT2COL lbl_804DBD18 = {lbl_80540998, lbl_805409B8, NULL, 4};

void TObjCMProportion::render() {
    f32 alpha;
    u32 color;
    f32 x;
    f32 y;

    alpha = fade * fade;
    color = ((s32)(32.0f * alpha) << 24) | 0xFF0000 | 0xFFFF;
    lbl_80540988[3].color = color;
    lbl_80540988[2].color = color;
    lbl_80540988[1].color = color;
    lbl_80540988[0].color = color;
    ((TWindowCtrlMain *)&lbl_804DBD08)->draw_strip_swap_color(4, 5, -2.0f);
    color = ((s32)(64.0f * alpha) << 24) | 0xFF0000 | 0xFFFF;
    lbl_805409B8[3].color = color;
    lbl_805409B8[2].color = color;
    lbl_805409B8[1].color = color;
    lbl_805409B8[0].color = color;
    x = 75.0f * (2.0f * (appearance->width - 0.5f)) + 320.0f;
    y = 75.0f * (2.0f * (appearance->height - 0.5f)) + 240.0f;
    lbl_80540998[1].y = 150.0f;
    lbl_80540998[0].y = 150.0f;
    lbl_80540998[3].y = 330.0f;
    lbl_80540998[2].y = 330.0f;
    lbl_80540998[0].x = x - 2.0f;
    lbl_80540998[1].x = 2.0f + x;
    lbl_80540998[2].x = 2.0f + x;
    lbl_80540998[3].x = x - 2.0f;
    ((TWindowCtrlMain *)&lbl_804DBD18)->draw_strip_swap_color(4, 6, -2.0f);
    lbl_80540998[0].y = y - 2.0f;
    lbl_80540998[1].x = 230.0f;
    lbl_80540998[1].y = 2.0f + y;
    lbl_80540998[0].x = 230.0f;
    lbl_80540998[2].y = 2.0f + y;
    lbl_80540998[3].y = y - 2.0f;
    lbl_80540998[3].x = 410.0f;
    lbl_80540998[2].x = 410.0f;
    ((TWindowCtrlMain *)&lbl_804DBD18)->draw_strip_swap_color(4, 6, -2.0f);
    draw_creation_ruler_lines(fade);
}

#pragma pop
const char *TObjCMName__name = "TObjCMName";

TObjCMName::TObjCMName(TObject *parent) : TObject(parent) {
    m_name = TObjCMName__name;
    appearance = creation_player_character;
    initialized = 0;
    ticks = 0;
    keyboard = NULL;
    active = 1;
    fade = 0.0f;
    TChCrEffTag::set_eff_tag(10);
}

TObjCMName::~TObjCMName() {}

TObjCMName *TObjCMName::create(TObject *parent) {
    return new TObjCMName(parent);
}

extern "C" {
void TObjCMName::run_task() {
    f32 pos[2];
    char name[13];
    TKeyBoardControl *kb;
    char *buf;
    s32 sound;
    f32 scale;

    ticks++;
    if (initialized == 0) {
        if (ticks > 1) {
            kb = (TKeyBoardControl *)TObject::operator new(sizeof(TKeyBoardControl));
            if (kb != NULL) {
                kb = TKeyBoardControl__ct(kb, this, 12, 0, 0, TChCrEffCtrlPl::get_clamped_player_index());
            }
            keyboard = kb;
            get_keyboard_field_6c__15TWindowMakeTeamFv(keyboard, (char *)appearance->name);
            scale = TObjCMMainMenu::get_scale();
            pos[0] = 148.0f;
            pos[1] = 137.0f * scale;
            ((TWindowMakeTeam *)keyboard)->set_sub_position((u8 *)pos);
            pos[0] = 53.0f;
            pos[1] = 178.0f * scale;
            fn_80131ADC((u8 *)keyboard, (u8 *)pos);
            initialized = 1;
        }
    } else if (active == 0) {
        if ((fade += -0.083333336f) <= 0.0f) {
            fade = 0.0f;
            queue_destruction();
        }
    } else {
        if ((fade += 0.16666667f) > 1.0f) {
            fade = 1.0f;
        }
        if (((TWindowSubComCard *)keyboard)->update_keyboard() != 0) {
            buf = (char *)((TWindowSubComCard *)keyboard)->realloc_buffer();
            sound = 0x53704;
            strncpy(name, buf, 12);
            name[12] = 0;
            if (TObjCMMainMenu::validate_character_name((s8 *)name) == 0) {
                sound = 0x5280D;
            }
            if (TObjCMName__sub_802948F4(this, name) != 0) {
                sound = 0x52608;
                strncpy(name, (char *)appearance->name, 12);
                name[12] = 0;
            }
            ((TObjCMMainMenu *)name)->copy_char_name();
            strncpy((char *)appearance->name, name, 12);
            appearance->name[12] = 0;
            mem_free(buf);
            play_sound_effect(sound, 0, 0, 0);
            TObjCMMainMenu::clear_task_state();
            keyboard->queue_destruction();
            keyboard = NULL;
            active = 0;
        }
    }
}
}

#pragma push
#pragma fp_contract on
__declspec(section ".data") vec2f creation_name_panel_position[1] = {{95.0f, 124.0f}};

void TObjCMName::render()
{
  vec2f position;
  vec2f scale;
  float right_edge;
  if (!(this->fade <= 0.33f))
  {
    f32 amount = (this->fade >= 0.66f) ? (1.0f) : ((this->fade - 0.33f) / 0.33f);
    scale.y = 1.0f;
    position.y = 124.0f;
    right_edge = 115.0f + (232.0f * amount);
    position.x = 115.0f;
    f32 right = right_edge;
    f32 left = (9.0f * sin_table_lookup(this->ticks << 10)) + position.x;
    f32 width = right - left;
    position.x = left;
    scale.x = width / 48.0f;
    draw_ui_sprite_opaque(8, &position, &scale, -2.75f);
    position.x = right;
    scale.x = 1.0f;
    draw_ui_sprite_opaque(9, &position, &scale, -2.75f);
  }
  if (!(this->fade <= 0.0f))
  {
    draw_ui_sprite(0, creation_name_panel_position, -2.4375f, (this->fade >= 0.33f) ? (1.0f) : (this->fade / 0.33f));
  }
}

#pragma pop

extern "C" {
int TObjCMName__sub_802948F4(TObjCMName *, char *) { return 0; }
}
