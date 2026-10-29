#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/MenuText.h"
#include "pso/menu/CreationInput.h"
#include "types.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/UISprite.h"
#include "pso/render/render_util.h"
#include "pso/misc/TWindowCtrlMain.h"
#include "pso/TObjCMName.h"
#include "pso/TObjCMHairMenu.h"
#include "pso/TObjCMAssignMenu.h"
#include "pso/object/TObjCMMainMenu.h"
#include "pso/camera/CreationCamera.h"
#include "pso/object/TObjCMProportion.h"
#include "pso/object/TObjCMAutoMkData.h"
#include "pso/TChCrCharSelect.h"
#include "pso/TChCrEffCtrlPl.h"
#include "pso/TChCrEffTag.h"
#include "pso/TObjCMIcon.h"
#include "pso/TObject.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TCharaMaking.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/misc/TWindowMakeTeam.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/unk/text_80131ADC.h"
#include "pso/object/TObjLuker.h"

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

struct Pair_80297B18 { s32 a, b; };

struct CreationCharaRecord {
    char name[0x18];
    u32 name_color;
    u8 pad_1C[0x30 - 0x1C];
    s8 section_id;
    s8 char_class;
    u8 flags;
};

extern "C" {
extern const char *lbl_804DBC0C[];
extern s32 lbl_804DBC40[];
extern char lbl_805D3CD8[4];
extern const u32 lbl_805DDBB8;
}

typedef void (TObjCMMainMenu::*MenuFn_802987AC)();

struct M_802983A0 { u8 pad[0x40]; f32 f40; };

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

struct Icons_802952E0
{
  s32 a;
  s32 b;
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
extern const f32 lbl_805DDA70;
extern const f32 lbl_805DDA90;
extern const f32 lbl_805DDAA8;
extern const f32 lbl_805DDAAC;
extern const f32 lbl_805DDB80;
void run_task__16TObjCMAssignMenuFv(void *arg0);
f32 fabs_float(f32);
void TCameraCtrl__sub_80068EF0(void);
s32 TQuestVmDownLoadServer__sub_8006EF6C(s32 arg0);
u32 calc_text_width(char *s);
s32 is_active__23TAdSinglePlyChrSelectGCFv();
void TObjCMIcon__sub_802994C8(s32 arg0, s32 *arg1);
s32 TAdSinglePlyChrSelectGC__sub_802905B8();
s32 rand();
extern const f32 lbl_805DDC10;
void TObjCMMainMenu__sub_80298DA0(int a0);
}
extern Pair_80297B18 lbl_80464FC8[];
extern s32 creation_resource_ready_state;
extern s32 TObjCMMainMenu__data_805D659C;
extern const s32 lbl_805DDA5C;
extern const s32 lbl_805DDA60;
extern const s32 lbl_805DDA64;
extern const s32 lbl_805DDA68;
extern const f32 TObjCMMainMenu__data_805DDB44;
extern const f32 lbl_805DDBA0;
extern const f32 lbl_805DDBA4;
extern const f32 lbl_805DDBA8;
extern const f32 lbl_805DDBAC;
void request_creation_motion(s32 arg0);
extern const f32 lbl_805DDBF4;
extern const f32 lbl_805DDBF8;
extern const f32 lbl_805DDBFC;
extern const f32 TObjCMMainMenu__data_805DDC00;
extern const Icons_802952E0 lbl_80465118;
extern const f32 lbl_805DDAC8;
extern const f32 lbl_805DDAE0;
extern const f32 lbl_805DDAF0;
extern const f32 lbl_805DDAF4;
extern const f32 lbl_805DDAF8;
extern const f32 lbl_805DDAFC;
extern const f32 lbl_805DDB00;
struct Ent_802964B0 {
    u8 pad0[8];
    s16 f8;
    u8 pad[0x2C - 0xA];
};

struct Hair_802964B0 {
    s32 f0;
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

struct RecoveredGlobal_8029756C_TObjCMMainMenu__data_804DB9C8 {
    s32 value;
    u8 remaining[0x9C];
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

typedef char RecoveredGlobal_8029756C_TObjCMMainMenu__data_804DB9C8_size[sizeof(RecoveredGlobal_8029756C_TObjCMMainMenu__data_804DB9C8) == 0xA0 ? 1 : -1];

typedef void (TObjCMMainMenu::*CreationMenuCallback)(void);

struct RecoveredGlobal_80298630_TObjCMMainMenu__data_804DB9C8 {
    s32 value;
    u8 remaining[0x9C];
};

typedef char RecoveredGlobal_80298630_TObjCMMainMenu__data_804DB9C8_size[sizeof(RecoveredGlobal_80298630_TObjCMMainMenu__data_804DB9C8) == 0xA0 ? 1 : -1];

struct Base_80298AD0_80298A88 { char pad[0x18]; };

struct VObj_80298AD0_80298A88 : Base_80298AD0_80298A88 { virtual void m0(int); };

struct RecoveredGlobal_80298F08_lbl_8050E3B8 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_80298DD4_lbl_8051C07C {
    s32 value;
    u8 remaining[0x14];
};

struct Chara_80298B70 {
    char name[0xC];
    s8 fC;
    u8 padD[0x1C - 0xD];
    s8 f1C;
    u8 pad1D[0x30 - 0x1D];
    s8 f30;
    s8 f31;
    s8 f32;
    u8 pad33;
    u32 f34;
};

struct CreationMenuModeList {
    s32 count;
    s32 *entries;
};

struct Menu_80298B70 {
    const char *name;
    u8 pad4[0x18 - 0x4];
    void *vt;
    Chara_80298B70 *chara;
    s32 mode;
    s32 *list;
    s32 f28;
    s32 f2C;
    u8 pad30[0x38 - 0x30];
    f32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    f32 f48;
    s32 f4C;
    void *f50;
    f32 f54;
};

typedef char RecoveredGlobal_80298F08_lbl_8050E3B8_size[sizeof(RecoveredGlobal_80298F08_lbl_8050E3B8) == 0x1B0 ? 1 : -1];

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

struct M_802983F8 { u8 pad[0x3c]; f32 f3c; };

struct M_80298450 { u8 pad[0x38]; f32 f38; };
extern "C" {

void copy_player_visual_record(void *, void *);
void * get_char_index__23TAdSinglePlyChrSelectGCFUi(s32);
s32 __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);
s32 __dt__7TObjectFv(void *, s32);
void __ct__7TObjectFP7TObject(void *);
Chara_80298B70 * TObjCMMainMenu__sub_8028D9A8(void);
s32 TObjCMMainMenu__sub_8028D9B4(void *);
u8 calc_section_id_from_name();
s32 get_creation_sprite_id__14TObjCMMainMenuFl(int);
void fn_802947A8(void);
int TObjCMName__sub_802948F4(TObjCMName *, char *);
TKeyBoardControl *TKeyBoardControl__ct(void *, TObject *, s32, s32, s32, s32);
int get_keyboard_field_6c__15TWindowMakeTeamFv(TKeyBoardControl *, char *);
void mem_free(void *p);
void * create__10TObjCMNameFPv(void *arg0);
void * __ct__10TObjCMNameFv(void *arg0);
void * create__16TObjCMProportionFPv(void *arg0);
void * __dt__16TObjCMProportionFv(void *arg0, s16 arg1);
void *TObjCMProportion__ct(TObjCMProportion *arg0);
void * create__16TObjCMAutoMkDataFPv(void *arg0);
void * __dt__16TObjCMAutoMkDataFv(void *arg0, s16 arg1);
u8 * TObjCMAutoMkData__ct(u8 *arg0);
Hair_802964B0 * __ct__14TObjCMHairMenuFv(Hair_802964B0 *arg0, void *arg1);
void render__16TObjCMAssignMenuFv(Menu_80296928 *self);
void * create__16TObjCMAssignMenuFPvPv(void *arg0, void *arg1);
void * __ct__16TObjCMAssignMenuFv(void *arg0, void *parent, void *kind);
void fn_802972BC(void);
void fn_802972C0(void);
void TObjCMMainMenu__sub_802972C4(void);
void confirm_selection__14TObjCMMainMenuFPv(void *arg0);
void open_name_menu__14TObjCMMainMenuFPv(void *arg0);
void open_proportion_menu__14TObjCMMainMenuFPv(void *arg0);
void open_auto_mk_menu__14TObjCMMainMenuFPv(void *arg0);
void open_hair_menu__14TObjCMMainMenuFPv(void *arg0);
void open_assign_menu__14TObjCMMainMenuFPv(u8 *arg0);
void TObjCMMainMenu__sub_80298310(void);
void * TObjCMMainMenu__ct(void *arg0, void *parent);
u8 is_not_dressing_room_mode__14TObjCMMainMenuFv(void);
s32 * TObjCMMainMenu__sub_80298DD4(void);
s32 get_creation_pad(void);
void fn_802993F0(void);
void fn_8029945C(u8 *arg0);
u32 __cvt_fp2unsigned(f32);
char * strncpy(char *, const char *, u32);

extern const f32 TObjCMAssignMenu__data_805DDB20;
extern s32 __vt__10TObjCMName[];
extern u8 __vt__14TObjCMHairMenu[];
extern void *__vt__16TObjCMAssignMenu[];
extern s32 __vt__16TObjCMAutoMkData[];
extern s32 __vt__16TObjCMProportion[];
extern u8 lbl_80464F50[];
extern s32 char_creation_root_menu_tab_table[];
extern f32 char_creation_assign_menu_tab_positions[];
extern vec2f lbl_80465048[];
extern vec2f lbl_80465050[];
extern vec2f lbl_80465058[];
extern s32 char_creation_assign_sprite_id_table[];
extern s32 char_creation_assign_icon_sprite_id_table[];
extern Ent_802964B0 class_appearance_table[];
extern Cols_80297DB8 footer_divider_colors[2];
extern Quad_80297DB8 footer_divider_vertices[2];
extern vec2f lbl_804DBCC8[];
extern s32 lbl_804DBDA8[];
extern RecoveredGlobal_80298F08_lbl_8050E3B8 controller_physical_port_bank;
extern RecoveredGlobal_80298DD4_lbl_8051C07C character_creation_name_buffer;
extern f32 ui_sprite_scale;
extern const char *lbl_805D3CD0;
extern const char *lbl_805D3CDC;
extern s32 lbl_805D3CE0;
extern s32 lbl_805D3CE4;
extern void *lbl_805D3CE8;
extern void *lbl_805D3CEC;
extern void *creation_player_character;
extern s32 creation_dressing_room_mode_flag;
extern int creation_figure_rotation_y;
extern void *creation_figure_object;
extern const f32 lbl_805DDA74;
extern const f32 lbl_805DDA78;
extern const f32 lbl_805DDA94;
extern const f32 lbl_805DDA98;
extern const f32 lbl_805DDAE4;
extern const f32 lbl_805DDAE8;
extern const f32 lbl_805DDAEC;
extern const f32 lbl_805DDB10;
extern const f32 lbl_805DDB48;
extern const f32 lbl_805DDB4C;
extern const f32 lbl_805DDB50;
extern const f32 lbl_805DDB54;
extern const f32 lbl_805DDB58;
extern const f32 lbl_805DDB5C;
extern const f32 lbl_805DDB60;
extern const f32 lbl_805DDB64;
extern const f32 lbl_805DDB68;
extern const f32 lbl_805DDB6C;
extern const f32 lbl_805DDB70;
extern const f32 lbl_805DDB74;
extern const f32 lbl_805DDB78;
extern const f32 lbl_805DDB90;
extern const f32 lbl_805DDBB0;
extern const f32 lbl_805DDBB4;
extern const f32 lbl_805DDBBC;
extern const f32 lbl_805DDC04;
extern const f32 lbl_805DDC08;
extern const f32 lbl_805DDC0C;

extern "C" {
extern u8 lbl_805D3CD4[];
}
extern void *lbl_804DBA68[8];
extern void *lbl_804DBA88[6];
extern void *lbl_804DBAA0[2];
extern void *lbl_804DBAA8[3];
extern void *lbl_804DBAB4[5];
void *TObjCMMainMenu__data_804DB950[30] = {
    (void *)0x0, (void *)0xffffffff, (void *)&open_assign_menu__14TObjCMMainMenuFPv, (void *)0x0,
    (void *)0xffffffff, (void *)&open_assign_menu__14TObjCMMainMenuFPv, (void *)0x0, (void *)0xffffffff,
    (void *)&open_hair_menu__14TObjCMMainMenuFPv, (void *)0x0, (void *)0xffffffff, (void *)&open_assign_menu__14TObjCMMainMenuFPv,
    (void *)0x0, (void *)0xffffffff, (void *)&open_assign_menu__14TObjCMMainMenuFPv, (void *)0x0,
    (void *)0xffffffff, (void *)&open_assign_menu__14TObjCMMainMenuFPv, (void *)0x0, (void *)0xffffffff,
    (void *)&open_proportion_menu__14TObjCMMainMenuFPv, (void *)0x0, (void *)0xffffffff, (void *)&open_name_menu__14TObjCMMainMenuFPv,
    (void *)0x0, (void *)0xffffffff, (void *)&open_auto_mk_menu__14TObjCMMainMenuFPv, (void *)0x0,
    (void *)0xffffffff, (void *)&confirm_selection__14TObjCMMainMenuFPv,
};
void *TObjCMMainMenu__data_804DB9C8[40] = {
    (void *)0x3, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x2, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x4, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x1, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x1, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804DBA68[8] = {
    (void *)0x1, (void *)0x2, (void *)0x3, (void *)0x4,
    (void *)0x6, (void *)0x7, (void *)0x8, (void *)0x9,
};
void *lbl_804DBA88[6] = {
    (void *)0x0, (void *)0x5, (void *)0x6, (void *)0x7,
    (void *)0x8, (void *)0x9,
};
__declspec(section ".data") void *lbl_804DBAA0[2] = {
    (void *)0x7, (void *)0x9,
};
void *lbl_804DBAA8[3] = {
    (void *)0x2, (void *)0x3, (void *)0x9,
};
void *lbl_804DBAB4[5] = {
    (void *)0x0, (void *)0x5, (void *)0x9, (void *)0x7,
    (void *)0x9,
};
CreationMenuModeList creation_menu_mode_lists[6] = {
    {8, (s32*)lbl_804DBA68}, {6, (s32*)lbl_804DBA88},
    {2, (s32*)lbl_804DBAA0}, {3, (s32*)lbl_804DBAA8},
    {3, (s32*)lbl_804DBAB4}, {1, (s32*)lbl_805D3CD4},
};
#define TObjCMMainMenu__data_804DB9C8 (*(RecoveredGlobal_8029756C_TObjCMMainMenu__data_804DB9C8 *)TObjCMMainMenu__data_804DB9C8)

int TObjCMName__sub_802948F4(TObjCMName *, char *) { return 0; }

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

void *create__10TObjCMNameFPv(void *arg0) {
    void *o = __nw__7TObjectFUl(0x34);
    if (o != NULL) {
        o = ((void * (*)(void *, void *))__ct__10TObjCMNameFv)(o, arg0);
    }
    return o;
}
}
void reset_character_creation_figure_rotation(void);
void draw_creation_ruler_lines(f32 farg0);
TObjCMName::~TObjCMName() {}

#pragma push
#pragma fp_contract on
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


void *__ct__10TObjCMNameFv(void *obj_cm_name) {
    __ct__7TObjectFP7TObject(obj_cm_name);
    *(s32 **)((s8 *)obj_cm_name + 0x18) = __vt__10TObjCMName;
    *(void * *)&((TObjCMName *)obj_cm_name)->m_name = lbl_805D3CEC;
    *(void **)((s8 *)obj_cm_name + 0x1C) = creation_player_character;
    *(u32 *)((s8 *)obj_cm_name + 0x20) = 0;
    *(u32 *)((s8 *)obj_cm_name + 0x28) = 0;
    *(u32 *)((s8 *)obj_cm_name + 0x24) = 0;
    *(u32 *)((s8 *)obj_cm_name + 0x2C) = 1;
    *(f32 *)((s8 *)obj_cm_name + 0x30) = lbl_805DDA90;
    TChCrEffTag::set_eff_tag(10);
    return obj_cm_name;
}

struct Vec2_80294D6C { f32 x, y; };

extern u8 lbl_804DBD08[];
extern u8 lbl_804DBD18[];
u32 lbl_80540988[4];
Vec2_80294D6C lbl_80540998[4];
u32 lbl_805409B8[4];

#pragma push
#pragma fp_contract on
void TObjCMProportion::render() {
    f32 alpha;
    u32 color;
    f32 x;
    f32 y;

    alpha = fade * fade;
    color = ((s32)(32.0f * alpha) << 24) | 0xFF0000 | 0xFFFF;
    lbl_80540988[3] = color;
    lbl_80540988[2] = color;
    lbl_80540988[1] = color;
    lbl_80540988[0] = color;
    ((TWindowCtrlMain *)lbl_804DBD08)->draw_strip_swap_color(4, 5, -2.0f);
    color = ((s32)(64.0f * alpha) << 24) | 0xFF0000 | 0xFFFF;
    lbl_805409B8[3] = color;
    lbl_805409B8[2] = color;
    lbl_805409B8[1] = color;
    lbl_805409B8[0] = color;
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
    ((TWindowCtrlMain *)lbl_804DBD18)->draw_strip_swap_color(4, 6, -2.0f);
    lbl_80540998[0].y = y - 2.0f;
    lbl_80540998[1].x = 230.0f;
    lbl_80540998[1].y = 2.0f + y;
    lbl_80540998[0].x = 230.0f;
    lbl_80540998[2].y = 2.0f + y;
    lbl_80540998[3].y = y - 2.0f;
    lbl_80540998[3].x = 410.0f;
    lbl_80540998[2].x = 410.0f;
    ((TWindowCtrlMain *)lbl_804DBD18)->draw_strip_swap_color(4, 6, -2.0f);
    draw_creation_ruler_lines(fade);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjCMProportion::run_task() {
    TObjCMProportion* arg0=this;
    s32 spC;
    f32 sp8;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_4;
    f32 temp_f2_2;
    f32 temp_f31;
    f32 var_f1;
    f32 var_f30;
    f32 var_f29;
    CharacterAppearanceFields *temp_r3;
    CharacterAppearanceFields *temp_r3_2;
    CharacterAppearanceFields *temp_r3_3;
    CharacterAppearanceFields *temp_r3_4;

    var_f1 = TObjCMMainMenu::get_proportion();
    if ((s32) arg0->active != 0) {
        if (lbl_805DDA70 == arg0->fade) {
            var_f1 += lbl_805DDAE0;
            if (var_f1 < 0.0f) {
                var_f1 = 0.0f;
            }
        }
    } else {
        temp_f0 = lbl_805DDA70 - arg0->fade;
        var_f1 = (var_f1 > temp_f0) ? var_f1 : temp_f0;
    }
    set_creation_projection_center(var_f1);
    if ((s32) arg0->initialized == 0) {
        arg0->initialized = 1;
        return;
    }
    if ((s32) arg0->active == 0) {
        temp_f1 = arg0->fade + lbl_805DDAA8;
        arg0->fade = temp_f1;
        if (temp_f1 <= 0.0f) {
            arg0->fade = 0.0f;
            ((void (*)(TObject*))queue_destruction__7TObjectFv)(arg0);
        }
    } else {
        temp_f1_2 = arg0->fade + lbl_805DDAAC;
        arg0->fade = temp_f1_2;
        if (temp_f1_2 > 1.0f) {
            arg0->fade = 1.0f;
        }
        get_creation_pad_stick(&spC, &sp8);
        var_f30 = lbl_805DDAE4 * (sp8 * sin_table_lookup(spC));
        var_f29 = lbl_805DDAE4 * (sp8 * -cos_table_lookup(spC));
        if (lbl_805DDA90 == (fabs_float(var_f30) + fabs_float(var_f29))) {
            if (creation_buttons_held(0x80) != 0) {
                var_f30 = lbl_805DDAE8;
            } else if (creation_buttons_held(0x40) != 0) {
                var_f30 = lbl_805DDAEC;
            }
            if (creation_buttons_held(0x20) != 0) {
                var_f29 = lbl_805DDAE8;
            } else if (creation_buttons_held(0x10) != 0) {
                var_f29 = lbl_805DDAEC;
            }
        }
        temp_r3 = arg0->appearance;
        temp_r3->width = (f32) (temp_r3->width + var_f30);
        temp_r3_2 = arg0->appearance;
        temp_r3_2->height = (f32) (temp_r3_2->height + var_f29);
        temp_r3_3 = arg0->appearance;
        temp_f2_2 = temp_r3_3->width;
        if (temp_f2_2 > lbl_805DDAF0) {
            temp_r3_3->width = (f32) (temp_f2_2 - lbl_805DDAF0);
        } else if (temp_f2_2 < lbl_805DDA90) {
            temp_r3_3->width = (f32) (temp_f2_2 + lbl_805DDAF0);
        }
        temp_r3_4 = arg0->appearance;
        temp_f1_4 = temp_r3_4->height;
        if (temp_f1_4 > lbl_805DDAF0) {
            temp_r3_4->height = (f32) lbl_805DDAF0;
        } else if (temp_f1_4 < lbl_805DDA90) {
            temp_r3_4->height = (f32) lbl_805DDA90;
        }
        if (creation_buttons_pressed(6) != 0) {
            ((void (*)(s32, s32, s32, s32))play_sound_effect)(0x53704, 0, 0, 0);
            TObjCMMainMenu::clear_task_state();
            arg0->active = 0;
        }
    }
}
#pragma pop

void *create__16TObjCMProportionFPv(void *arg0) {
    void *o = __nw__7TObjectFUl(0x2C);
    if (o != NULL) {
        o = ((void * (*)(void *, void *))TObjCMProportion__ct)(o, arg0);
    }
    return o;
}

void *__dt__16TObjCMProportionFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjCMProportion;
        set_creation_projection_center(lbl_805DDA70);
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *TObjCMProportion__ct(TObjCMProportion *obj_cm_proportion) {
    __ct__7TObjectFP7TObject(obj_cm_proportion);
    *(s32 **)((s8 *)obj_cm_proportion + 0x18) = __vt__16TObjCMProportion;
    *(void * *)&obj_cm_proportion->m_name = lbl_805D3CE8;
    *(void * *)&obj_cm_proportion->appearance = creation_player_character;
    *(u32 *)((s8 *)obj_cm_proportion + 0x20) = 0;
    *(u32 *)((s8 *)obj_cm_proportion + 0x24) = 1;
    obj_cm_proportion->fade = lbl_805DDA90;
    TChCrEffTag::set_eff_tag(9);
    return obj_cm_proportion;
}

void TObjCMAutoMkData::render() {
    draw_creation_ruler_lines(*(f32 *)((s8 *)this + 0x38));
}

#pragma push
#pragma fp_contract on
typedef struct Auto_802952E0 Auto_802952E0;
typedef struct Icons_802952E0 Icons_802952E0;
typedef struct Limits_802952E0 Limits_802952E0;
typedef struct Making_802952E0 Making_802952E0;
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
      x += lbl_805DDAE0;
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
    if ((self->fade += lbl_805DDAA8) <= 0.0f)
    {
      self->fade = 0.0f;
      queue_destruction__7TObjectFv(self);
    }
    return;
  }
  if ((self->fade += lbl_805DDAAC) > 1.0f)
  {
    self->fade = 1.0f;
  }
  switch (self->state)
  {
    case 1:
    {
      Icons_802952E0 icons = lbl_80465118;
      TObjCMIcon__sub_802994C8(2, &icons.a);
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
        v = (s16) ((lbl_805DDAF0 * ((f32) (*lim))) * (lbl_805DDAF4 * ((f32) ((int)rand()))));
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
      self->color[0] = (u8) ((s32) ((lbl_805DDAF8 * (lbl_805DDAF4 * ((f32) ((int)rand())))) + (self->color[0] + 0x40)));
      self->color[1] = (u8) ((s32) ((lbl_805DDAF8 * (lbl_805DDAF4 * ((f32) ((int)rand())))) + (self->color[1] + 0x40)));
      self->color[2] = (u8) ((s32) ((lbl_805DDAF8 * (lbl_805DDAF4 * ((f32) ((int)rand())))) + (self->color[2] + 0x40)));
      if ((self->shape[0] += (lbl_805DDAC8 * (lbl_805DDAF4 * ((f32) ((int)rand())))) + lbl_805DDAFC) >= 1.0f)
    {
      self->shape[0] -= 1.0f;
    }
      if ((self->shape[1] += (lbl_805DDAC8 * (lbl_805DDAF4 * ((f32) ((int)rand())))) + lbl_805DDAFC) >= 1.0f)
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
      t = ((f32) self->ticks) / lbl_805DDB00;
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

void *create__16TObjCMAutoMkDataFPv(void *arg0) {
    void *o = __nw__7TObjectFUl(0x3C);
    if (o != NULL) {
        o = ((void * (*)(void *, void *))TObjCMAutoMkData__ct)(o, arg0);
    }
    return o;
}

void *__dt__16TObjCMAutoMkDataFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjCMAutoMkData;
        set_creation_projection_center(lbl_805DDA70);
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TObjCMAutoMkData__ct(u8 *arg0) {
    ((s32 (*)(void))__ct__7TObjectFP7TObject)();
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TObjCMAutoMkData;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D3CE4;
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) (*(s32 *)&creation_player_character);
    ((TWindowSubSymbolChatPartsSet *)(arg0 + 0x30))->copy_vec2((void*)(*(s32 *)((s8 *)arg0 + 0x1C) + 0x48));
    *(f32 *)((s8 *)arg0 + 0x38) = (f32) lbl_805DDA90;
    *(s32 *)((s8 *)arg0 + 0x20) = 0;
    TChCrEffTag::set_eff_tag(0xB);
    return arg0;
}

#pragma push
#pragma opt_common_subs off
void TObjCMHairMenu::run_task() {
    f32 temp_f1;
    f32 temp_f1_2;
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
        temp_f1 = fade + lbl_805DDAA8;
        fade = temp_f1;
        if (temp_f1 <= lbl_805DDA90) {
            fade = lbl_805DDA90;
            queue_destruction__7TObjectFv(this);
        }
    } else {
        temp_f1_2 = fade + lbl_805DDAAC;
        fade = temp_f1_2;
        if (temp_f1_2 > lbl_805DDA70) {
            fade = lbl_805DDA70;
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
#pragma pop

void *TObjCMHairMenu::create() {
    void *o = __nw__7TObjectFUl(0x44);
    if (o != NULL) {
        o = __ct__14TObjCMHairMenuFv((Hair_802964B0 *)(o), this);
    }
    return o;
}
TObjCMHairMenu::~TObjCMHairMenu() {}

Hair_802964B0 *__ct__14TObjCMHairMenuFv(Hair_802964B0 *arg0, void *arg1) {
    s32 i;
    ((void * (*)(void *, void *))__ct__7TObjectFP7TObject)(arg0, arg1);
    arg0->vt = __vt__14TObjCMHairMenu;
    arg0->f0 = lbl_805D3CE0;
    arg0->f1c = (*(s32 *)&creation_player_character);
    arg0->f20 = 0;
    arg0->f24 = 0;
    arg0->f28 = class_appearance_table[((TCharaMaking *)(arg0->f1c))->get_display_index()].f8;
    arg0->f30 = 1;
    arg0->f34 = lbl_805DDA90;
    for (i = 0; i < 3; i++) {
        arg0->a38[i] = 0;
    }
    TChCrEffTag::set_eff_tag(5);
    return arg0;
}

#pragma push
#pragma fp_contract on
void TObjCMAssignMenu::draw_assign_icons() {
    Menu_80296560 *self = (Menu_80296560 *)this;
    s32 idx;
    u32 bit;
    s32 i;
    f32 step;
    f32 a;
    vec2f pos;
    if (!(self->timer <= lbl_805DDA74)) {
        a = (self->timer - lbl_805DDA74) / lbl_805DDB10;
        pos.x = lbl_805DDB48;
        step = TObjCMAssignMenu__data_805DDB20;
        idx = 0;
        pos.y = lbl_805DDB4C;
        bit = 1;
        a = a * a;
        for (i = 0; i < self->count; i++, pos.x += step) {
            while (!(bit & self->mask)) {
                bit <<= 1;
                idx++;
            }
            draw_ui_sprite(char_creation_assign_icon_sprite_id_table[idx], &pos, lbl_805DDA94, a);
            bit <<= 1;
            idx++;
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjCMAssignMenu::sub_80296648() {
    Menu_80296648 *self = (Menu_80296648 *)this;
    s32 off;
    s32 idx;
    u32 bit;
    s32 i;
    f32 step;
    f32 a;
    vec2f pos;
    if (!(self->timer <= lbl_805DDA74)) {
        a = (self->timer - lbl_805DDA74) / lbl_805DDB10;
        pos.x = lbl_805DDB48;
        step = TObjCMAssignMenu__data_805DDB20;
        idx = 0;
        off = 0;
        pos.y = lbl_805DDB4C;
        bit = 1;
        a = a * a;
        for (i = 0; i < self->count; bit <<= 1, off += 4, idx++, i++, pos.x += step) {
            while (!(bit & self->mask)) {
                bit <<= 1;
                idx++;
                off += 4;
            }
            if (idx < 7) draw_ui_sprite(*(s32 *)((u8 *)char_creation_assign_sprite_id_table + off), &pos, lbl_805DDA94, a);
        }
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
    a = t * (t * (lbl_805DDB50 * t));
    if (a <= lbl_805DDB54) return;
    zero = 0.0f;
    for (i = 0; i < self->pages; i++) {
        n = self->per;
        d = (f32)i - self->scroll;
        if (i == self->pages - 1) {
            n = self->total - i * self->per;
        }
        if (zero == d) continue;
        if (d < zero) {
            t = lbl_805DDA70 - d;
            pos.x = lbl_805DDB5C * t + lbl_805DDB58;
            pos.y = lbl_805DDB64 * t + lbl_805DDB60;
        } else if (d > zero) {
            t = lbl_805DDA70 + d;
            pos.x = lbl_805DDB68 * t + lbl_805DDA78;
            pos.y = lbl_805DDB6C * t + lbl_805DDA98;
        }
        step = TObjCMAssignMenu__data_805DDB20;
        for (j = 0; j < n; j++) {
            draw_ui_sprite_scaled(0x1F, &pos, lbl_80465050, lbl_805DDB70, a);
            pos.x += step;
        }
        pos.x += lbl_805DDB74;
        pos.y += lbl_805DDB78;
        draw_ui_sprite_scaled(i + 0x14, &pos, lbl_80465058, lbl_805DDB70, a);
    }
}
#pragma pop

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
            draw_ui_sprite_scaled(n + 0x14, &pos2, lbl_80465048, -2.4375f, alpha);
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

#pragma push
#pragma opt_common_subs off
typedef struct Menu_80296D68 Menu_80296D68;
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
    fade = self->fade + lbl_805DDAA8;
    self->fade = fade;
    if (fade <= lbl_805DDA90)
    {
      self->fade = lbl_805DDA90;
      queue_destruction__7TObjectFv(self);
    }
    return;
  }
  fade = self->fade + lbl_805DDAAC;
  self->fade = fade;
  if (fade > lbl_805DDA70)
  {
    self->fade = lbl_805DDA70;
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
    self->scroll += lbl_805DDB80;
    if (self->scroll > ((f32) self->target))
    {
      self->scroll = (f32) self->target;
    }
  }
  else
    if (self->scroll > ((f32) self->target))
  {
    self->scroll -= lbl_805DDB80;
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

void * create__16TObjCMAssignMenuFPvPv(void *parent, void *kind) {
    void *o;
    o = __nw__7TObjectFUl(0x5C);
    if (o != NULL) {
        o = __ct__16TObjCMAssignMenuFv(o, parent, kind);
    }
    return o;
}
TObjCMAssignMenu::~TObjCMAssignMenu() {}
extern "C" {

void *__ct__16TObjCMAssignMenuFv(void *obj_cm_assign_menu, void *parent, void *kind) {
    u32 bit;
    s32 i;
    ((void (*)(void *, void *))__ct__7TObjectFP7TObject)(obj_cm_assign_menu, parent);
    ((Menu_80297128 *)obj_cm_assign_menu)->vt = __vt__16TObjCMAssignMenu;
    ((Menu_80297128 *)obj_cm_assign_menu)->name = lbl_805D3CDC;
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
    ((Menu_80297128 *)obj_cm_assign_menu)->f40 = lbl_805DDA90;
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

void fn_802972BC(void) {  }

void fn_802972C0(void) {  }

void TObjCMMainMenu__sub_802972C4(void) {  }

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

void confirm_selection__14TObjCMMainMenuFPv(void *arg0) {
    if (TObjCMMainMenu::validate_character_name((s8 *)(*(void **)((s8 *)arg0 + 0x1C))) == 0) {
        play_sound_effect(0x53F06, 0, 0, 0);
        return;
    }
    play_sound_effect(0x52D01, 0, 0, 0);
    if ((s8) *(u8 *)((s8 *)(*(void **)((s8 *)arg0 + 0x1C)) + 0x30) == -1) {
        *(u8 *)((s8 *)(*(void **)((s8 *)arg0 + 0x1C)) + 0x30) = calc_section_id_from_name();
    } else {
        TObjCMMainMenu::try_pay_fee();
    }
    TObjCMMainMenu::set_selection(1);
    reset_character_creation_figure_rotation();
    *(s32 *)((s8 *)arg0 + 0x30) = 0x3C;
    TObjCMMainMenu__data_805D659C = 2;
}

void open_name_menu__14TObjCMMainMenuFPv(void *arg0) {
    play_sound_effect(0x52D01, 0, 0, 0);
    TObjCMMainMenu__data_805D659C = 1;
    ((s32 (*)(s32))create__10TObjCMNameFPv)(*(s32 *)((s8 *)arg0 + 0x50));
}

void open_proportion_menu__14TObjCMMainMenuFPv(void *arg0) {
    play_sound_effect(0x52D01, 0, 0, 0);
    TObjCMMainMenu__data_805D659C = 1;
    ((s32 (*)(s32))create__16TObjCMProportionFPv)(*(s32 *)((s8 *)arg0 + 0x50));
}

void open_auto_mk_menu__14TObjCMMainMenuFPv(void *arg0) {
    play_sound_effect(0x52D01, 0, 0, 0);
    TObjCMMainMenu__data_805D659C = 1;
    ((s32 (*)(s32))create__16TObjCMAutoMkDataFPv)(*(s32 *)((s8 *)arg0 + 0x50));
}

void open_hair_menu__14TObjCMMainMenuFPv(void *arg0) {
    play_sound_effect(0x52D01, 0, 0, 0);
    TObjCMMainMenu__data_805D659C = 1;
    ((TObjCMHairMenu *)(*(s32 *)((s8 *)arg0 + 0x50)))->create();
}

void open_assign_menu__14TObjCMMainMenuFPv(u8 *arg0) {
    play_sound_effect(0x52D01, (s32)(0U), 0, 0);
    TObjCMMainMenu__data_805D659C = 1;
    ((s32 (*)(s32, s32))create__16TObjCMAssignMenuFPvPv)(*(s32 *)((s8 *)arg0 + 0x50), *(s32 *)((s8 *)&TObjCMMainMenu__data_804DB9C8.value + (*(s32 *)((s8 *)(*(s32 *)((s8 *)arg0 + 0x24)) + (*(s32 *)((s8 *)arg0 + 0x2C) * 4)) * 0x10)));
}

#pragma push
#pragma fp_contract on
void TObjCMMainMenu::draw_root_menu() {
    u8 *arg0 = (u8 *)this;
    Menu_802975DC *m = (Menu_802975DC *)arg0;
    vec2f a;
    vec2f b;
    vec2f c;
    vec2f d;
    f32 t;
    f32 ratio;
    f32 step;
    f32 kA88;
    f32 kA7C;
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
                    alpha *= lbl_805DDB50;
                }
                draw_ui_sprite(m->ids[q] + 0x8F, &d, -1.8125f, alpha);
            } else {
                alpha = base;
                if (r) {
                    alpha = base * lbl_805DDB50;
                }
                draw_ui_sprite(m->ids[q] + 0x8F, &d, -1.8125f, alpha);
            }
            d.y += 44.0f;
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjCMMainMenu::sub_80297B18() {
    Menu_80297B18 *m = (Menu_80297B18 *)this;
    s32 v14;
    s32 v10;
    s32 vC;
    s32 v8;
    u32 color;
    s32 i;
    f32 s;
    f32 step;
    f32 y;
    if (m->ids[m->sel] == 9 && TObjCMMainMenu::validate_character_name((s8 *)m->f1C) == 0) {
        color = ((u32)(TObjCMMainMenu__data_805DDB44 * (lbl_805DDA70 - lbl_805DDBA8 * fabs_float(sin_table_lookup(m->pulse << 10)))) << 24) | 0xFFFFFF;
        s = TObjCMMainMenu::get_scale();
        step = lbl_805DDBAC * s;
        y = lbl_805DDBA4 * s - step;
        for (i = 0; i < 2; i++) {
            const char *str = (const char *)TQuestVmDownLoadServer__sub_8006EF6C(i + 0x3B);
            f32 x = lbl_805DDBA0 - (f32)calc_text_width((char *)str);
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
                v14 = lbl_805DDA5C;
                TObjCMIcon__sub_802994C8(1, &v14);
            } else if (((s8 *)m->f1C)[0x30] == -1) {
                Pair_80297B18 p18 = lbl_80464FC8[0];
                TObjCMIcon__sub_802994C8(2, (s32 *)&p18);
            } else {
                v10 = lbl_805DDA60;
                TObjCMIcon__sub_802994C8(1, &v10);
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
            vC = lbl_805DDA64;
            TObjCMIcon__sub_802994C8(1, &vC);
            break;
        }
        break;
    case 2:
        if (m->f30 == 0 || creation_resource_ready_state == 2) {
            v8 = lbl_805DDA68;
            TObjCMIcon__sub_802994C8(1, &v8);
        } else {
            TObjCMIcon::reset_icon_flags();
        }
        break;
    default:
        TObjCMIcon::reset_icon_flags();
        break;
    }
}
#pragma pop

void TObjCMMainMenu::draw_footer_divider() {
    Menu_80297DB8 *self = (Menu_80297DB8 *)this;
    Prim_80297DB8 prim;
    u32 cols[4];
    f32 s = TObjCMMainMenu::get_scale();
    f32 top = lbl_805DDBB0 * s;
    f32 bot = top + lbl_805DDBB4 * s;
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
        ((TWindowCtrlMain *)(&prim))->draw_strip_swap_color(4, 6, lbl_805DDB90);
    }
}

void restore_saved_depth_alpha_state(); void TObjCMMainMenu__sub_802979BC(void*); void render_nodes__7TObjectFv(void*);
void update_menu_reveal__14TObjCMMainMenuFv(M_80298450 *self);
}
#pragma defer_codegen on
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
        if (this->preview > lbl_805DDA90) {
            f32 v = this->preview + lbl_805DDC10;
            this->preview = v;
            if (v < lbl_805DDA90) {
                this->preview = lbl_805DDA90;
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
            this->preview = lbl_805DDA90;
        }
        break;
    }
    TObjCMMainMenu::set_speed(lbl_805DDB00 * (lbl_805DDA70 - this->preview));
    get_creation_pad_stick(0, &sp8);
    if (sp8 > lbl_805DDA90 || creation_buttons_held(0xF0) != 0) {
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
        if (((s8) *(u8 *)((s8 *)(*(u8 * *)&this->character) + 0x30) == -1) && (creation_buttons_pressed(2) != 0)) {
            play_sound_effect(0x53704, 0, 0, 0);
            TObjCMMainMenu__sub_8028D9B4((void *) (*(u8 * *)&this->character));
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
            (reinterpret_cast<TObjCMMainMenu*>(this)->*(*reinterpret_cast<CreationMenuCallback*>((u8*)&TObjCMMainMenu__data_804DB9C8 + (*(s32 *)((s8 *)((*(s32 *)&this->entries) + (this->selected_entry * 4)) + 0) * 0x10) + 4)))();
        }
    }
}

void TObjCMMainMenu::sub_8029862C() {  }

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
void TObjCMMainMenu::sub_80298534() {
    f32 temp_f2;
    f32 fv;
    f32 v1;
    f32 v2;
    f32 c1;
    f32 c2;
    s32 temp_r0;
    fv = this->progress;
    this->progress = (f32) (fv + lbl_805DDC0C);
    temp_r0 = this->delay - 1;
    this->delay = temp_r0;
    if (temp_r0 < 0) {
        this->delay = 0;
    }
    if (((s32) creation_resource_ready_state == 2) || ((s32) this->delay == 0)) {
        temp_f2 = this->progress;
        if (temp_f2 < lbl_805DDBBC) {
            this->progress = (f32) ((lbl_805DDAFC * (lbl_805DDBBC - temp_f2)) + temp_f2);
        }
        fv = this->progress;
        if (fv > lbl_805DDA70) {
            this->progress = lbl_805DDA70;
        }
        if (creation_buttons_pressed(4) != 0) {
            play_sound_effect(0x52D01, 0, 0, 0);
            this->delay = 7;
            TObjCMMainMenu__data_805D659C = 5;
            TObjCMMainMenu::create_fade((void *)7, (void *)1);
        }
    } else {
        fv = this->progress;
        if (fv > lbl_805DDBBC) {
            this->progress = lbl_805DDBBC;
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
    M_80298450 *self = (M_80298450 *)this;
    f32 v;
    switch (TObjCMMainMenu__data_805D659C) {
    case 3:
    case 4:
    case 5:
    case 6:
        v = self->f38 + lbl_805DDC04;
        self->f38 = v;
        if (v < 0.0f) {
            self->f38 = 0.0f;
        }
        break;
    default:
        self->f38 += lbl_805DDC08;
        if (is_active__23TAdSinglePlyChrSelectGCFv() != 0) {
            self->f38 += lbl_805DDAFC * (lbl_805DDA70 - self->f38);
        }
        if (self->f38 > 1.0f) {
            self->f38 = 1.0f;
        }
        break;
    }
}
#pragma pop
void TObjCMMainMenu::update_submenu_fade() {
    M_802983F8 *arg0 = (M_802983F8 *)this;
    f32 v;
    switch (TObjCMMainMenu__data_805D659C) {
    case 0:
        v = arg0->f3c + TObjCMMainMenu__data_805DDC00;
        arg0->f3c = v;
        if (v > 1.0f) {
            arg0->f3c = 1.0f;
        }
        break;
    default:
        v = arg0->f3c + lbl_805DDBFC;
        arg0->f3c = v;
        if (v < 0.0f) {
            arg0->f3c = 0.0f;
        }
        break;
    }
}
#pragma push
#pragma opt_common_subs off
void TObjCMMainMenu::update_slide_offset() {
    M_802983A0 *arg0 = (M_802983A0 *)this;
    f32 v;
    switch (TObjCMMainMenu__data_805D659C) {
    case 1:
        v = arg0->f40 + lbl_805DDBFC;
        arg0->f40 = v;
        if (v < lbl_805DDA90) {
            arg0->f40 = lbl_805DDA90;
        }
        break;
    default:
        v = arg0->f40 + TObjCMMainMenu__data_805DDC00;
        arg0->f40 = v;
        if (v > lbl_805DDA70) {
            arg0->f40 = lbl_805DDA70;
        }
        break;
    }
}
#pragma pop
void TObjCMMainMenu::update_random_proportion_action(void * _w0) {
    f32 right_trigger_ratio;
    f32 temp_f31_2;
    if (is_active__23TAdSinglePlyChrSelectGCFv() != 0) {
        switch (TObjCMMainMenu__data_805D659C) {
        case 0:
        case 1:
            right_trigger_ratio = TObjCMProportion::get_right_trigger_ratio();
            temp_f31_2 = TObjCMProportion::get_ratio() - right_trigger_ratio;
            if (fabs_float(temp_f31_2) > lbl_805DDBF4) {
                TObjCMMainMenu__sub_80298DA0((s32) (lbl_805DDBF8 * temp_f31_2));
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
    TObjCMMainMenu__sub_802979BC(this);
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
    int char_class = ((CreationCharaRecord *)character)->char_class;
    if (((CreationCharaRecord *)character)->flags & 2) {
        char_class = 12;
    }
    TCameraCtrl::restore_full_screen_view();
    draw_menu_text(263.0f, 172.0f * scale, lbl_804DBC0C[char_class], color);
    TCameraCtrl__sub_80068EF0();

    u32 name_color = ((CreationCharaRecord *)character)->name_color;
    if (!(name_color & 0xFF000000)) {
        name_color = 0xFFFFFFFF;
    }
    name_color &= lbl_805DDBB8;
    TCameraCtrl::restore_full_screen_view();
    draw_menu_text(263.0f, 209.0f * scale, ((CreationCharaRecord *)character)->name, name_color | (color & 0xFF000000));
    TCameraCtrl__sub_80068EF0();

    if (progress <= 0.8f) {
        return;
    }
    f32 section_alpha = (progress - 0.8f) / 0.19999999f;
    if (!(((CreationCharaRecord *)character)->flags & 1)) {
        vec2f icon_pos;
        icon_pos.x = 212.0f;
        icon_pos.y = 234.0f;
        draw_ui_sprite(lbl_804DBC40[((CreationCharaRecord *)character)->section_id], &icon_pos, -3.0625f, section_alpha);
    }
    const char *section_name = (const char *)TObjLuker::get_stat_table_entry(((CreationCharaRecord *)character)->section_id);
    if (((CreationCharaRecord *)character)->flags & 1) {
        section_name = lbl_805D3CD8;
    }
    TCameraCtrl::restore_full_screen_view();
    draw_menu_text(263.0f, 247.0f * scale, section_name, ((u32)(255.0f * section_alpha) << 24) | 0xFFFFFF);
    TCameraCtrl__sub_80068EF0();
}

void TObjCMMainMenu::sub_802981BC() {  }

#pragma defer_codegen off

void *TObjCMMainMenu::create() {
    void *o = __nw__7TObjectFUl(0x58);
    if (o != NULL) {
        o = TObjCMMainMenu__ct(o, this);
    }
    return o;
}

void *TObjCMMainMenu::destroy(s16 arg1) {
    void *temp_r3;

    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804DBDA8;
        temp_r3 = this->nodes;
        if (temp_r3 != NULL) {
            if (temp_r3 != NULL) {
                ((VObj_80298AD0_80298A88 *)temp_r3)->m0(1);
            }
            this->nodes = NULL;
        }
        *(s32 *)((s8 *)this->character + 0x18) = -1;
        *(s8 *)((s8 *)this->character + 0x33) = 2;
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void *TObjCMMainMenu__ct(void *arg0, void *parent) {
    void *o;
    ((void * (*)(void *, void *))__ct__7TObjectFP7TObject)(arg0, parent);
    ((Menu_80298B70 *)arg0)->vt = ((u8 *)&lbl_804DBDA8);
    ((Menu_80298B70 *)arg0)->name = lbl_805D3CD0;
    ((Menu_80298B70 *)arg0)->chara = (*(Chara_80298B70 * *)&creation_player_character);
    if (!(((Menu_80298B70 *)arg0)->chara->f32 & 0xA) && ((Menu_80298B70 *)arg0)->chara->f31 == TObjCMMainMenu__sub_8028D9A8()->f31) {
        copy_player_visual_record(((Menu_80298B70 *)arg0)->chara, TObjCMMainMenu__sub_8028D9A8());
    }
    strncpy(((Menu_80298B70 *)arg0)->chara->name, (const char *)TObjCMMainMenu__sub_80298DD4(), 0xC);
    ((Menu_80298B70 *)arg0)->chara->fC = 0;
    ((Menu_80298B70 *)arg0)->chara->f1C = 0;
    ((Menu_80298B70 *)arg0)->chara->f32 &= ~0xA;
    if (((Menu_80298B70 *)arg0)->chara->f30 == -1) {
        if (((Menu_80298B70 *)arg0)->chara->f32 & 0xA) {
            ((Menu_80298B70 *)arg0)->mode = 2;
        } else if (!(((Menu_80298B70 *)arg0)->chara->f34 & 0x10)) {
            ((Menu_80298B70 *)arg0)->mode = 0;
        } else {
            ((Menu_80298B70 *)arg0)->mode = 1;
        }
    } else if (((Menu_80298B70 *)arg0)->chara->f32 & 0xA) {
        ((Menu_80298B70 *)arg0)->mode = 5;
    } else if (!(((Menu_80298B70 *)arg0)->chara->f34 & 0x10)) {
        ((Menu_80298B70 *)arg0)->mode = 3;
    } else {
        ((Menu_80298B70 *)arg0)->mode = 4;
    }
    ((Menu_80298B70 *)arg0)->f28 = creation_menu_mode_lists[((Menu_80298B70 *)arg0)->mode].count;
    ((Menu_80298B70 *)arg0)->list = creation_menu_mode_lists[((Menu_80298B70 *)arg0)->mode].entries;
    (*(int *)&TObjCMMainMenu__data_805D659C) = 0;
    ((Menu_80298B70 *)arg0)->f2C = 0;
    creation_menu_selected_entry = ((Menu_80298B70 *)arg0)->list[((Menu_80298B70 *)arg0)->f2C];
    fn_802993F0();
    ((Menu_80298B70 *)arg0)->f38 = lbl_805DDA90;
    ((Menu_80298B70 *)arg0)->f3C = lbl_805DDA90;
    ((Menu_80298B70 *)arg0)->f40 = lbl_805DDA90;
    ((Menu_80298B70 *)arg0)->f44 = lbl_805DDA90;
    ((Menu_80298B70 *)arg0)->f48 = lbl_805DDA90;
    ((Menu_80298B70 *)arg0)->f4C = 0;
    ((Menu_80298B70 *)arg0)->f54 = lbl_805DDA90;
    TObjCMMainMenu::set_speed(lbl_805DDB00);
    o = __nw__7TObjectFUl(0x1C);
    if (o != 0) {
        o = ((void * (*)(void *, void *))__ct__7TObjectFP7TObject)(o, 0);
    }
    ((Menu_80298B70 *)arg0)->f50 = o;
    fn_802947A8();
    fn_8029945C(lbl_80464F50);
    ((void (*)(void *))TObjCMMainMenu__sub_802972C4)(arg0);
    return arg0;
}

void TObjCMMainMenu::clear_task_state() { (*(int *)&TObjCMMainMenu__data_805D659C) = 0; }

f32 TObjCMMainMenu::get_scale() {
    return ui_sprite_scale;
}

f32 TObjCMMainMenu::get_proportion() {
    return creation_view_shift;
}

void TObjCMMainMenu::set_selection(int a0) { creation_camera_mode = a0; }

void TObjCMMainMenu__sub_80298DA0(int a0) { creation_figure_rotation_y = (creation_figure_rotation_y + a0); }

void TObjCMMainMenu::set_speed(f32 farg0) {
    if ((void *) creation_figure_object != NULL) {
        *(f32 *)((s8 *)creation_figure_object + 0x38) = farg0;
    }
}

u8 is_not_dressing_room_mode__14TObjCMMainMenuFv(void) {
    return (u8) (creation_dressing_room_mode_flag == 0);
}

s32 *TObjCMMainMenu__sub_80298DD4(void) {
    return &character_creation_name_buffer.value;
}

s32 get_creation_pad(void) {
    return *(s32 *)((s8 *)&controller_physical_port_bank.value + (TChCrEffCtrlPl::get_clamped_player_index() * 4));
}
