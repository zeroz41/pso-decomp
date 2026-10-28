#include "types.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/misc/TWindowHelpItem_802531A0.h"
#include "pso/misc/TWindowHelpItem_802540AC.h"
#include "pso/player/TObjPlayer_800A7764.h"
#include "pso/unk/text_80253974.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/item/TItem.h"
#include "pso/misc/TWindowDuelResult.h"
#include "pso/misc/TWindowSubMag.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"

struct VBase_18_eecf68 { char pad[0x18]; };

struct VObj_18_eecf68 : VBase_18_eecf68 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual s32 m14();
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Pair_80254F18 {
    s32 x;
    s32 y;
};

struct Vec3_80254F18 {
    Pair_80254F18 xy;
    s32 z;
};

struct HelpItem_80254F18 {
    u8 pad0[0xb0];
    Vec3_80254F18 pos;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Pair_802541E0 {
    s32 x;
    s32 y;
};

struct Vec3_802541E0 {
    Pair_802541E0 xy;
    s32 z;
};

struct HelpItem_802541E0 {
    u8 pad0[0x20];
    s16 player;
    u8 pad22[2];
    u8 disp[0x70 - 0x24];
    u32 item;
    u8 pad74[0xA4 - 0x74];
    s32 itemId;
    u8 padA8[0xB0 - 0xA8];
    Vec3_802541E0 pos;
};

struct Stats_802541E0 {
    u8 pad0[0xC];
    s16 atp;
    s16 dfp;
    s16 mst;
    s16 ata;
    s16 evp;
    u8 pad16[2];
};

class Entry_802544D8 {
public:
    virtual void m0();
};

typedef void (Entry_802544D8::*EntryFn_802544D8)(s32);

struct Op_802544D8 {
    u8 slot;
    s8 value;
};

struct Pair_8025500C {
    s32 x;
    s32 y;
};

struct Vec3_8025500C {
    Pair_8025500C xy;
    s32 z;
};

struct HelpItem_8025500C {
    u8 pad0[0x20];
    s16 player;
    u8 pad22[0x68 - 0x22];
    s32 itemId;
    u8 pad6C[0xB0 - 0x6C];
    Vec3_8025500C pos;
};

struct Pair_802551C4 {
    s32 x;
    s32 y;
};

struct Vec3_802551C4 {
    Pair_802551C4 xy;
    s32 z;
};

struct HelpItem_802551C4 {
    u8 pad0[0x20];
    s16 player;
    u8 pad22[0x68 - 0x22];
    s32 itemId;
    u8 pad6C[0xB0 - 0x6C];
    Vec3_802551C4 pos;
};

typedef struct Stats_80254CE4 {
    s16 atp;
    s16 pad2;
    s16 mst;
    s16 ata;
    u8 pad8[0x10];
} Stats_80254CE4;

typedef struct Pmt_80254CE4 {
    u8 pad0[0xE];
    u16 req_atp;
    u16 req_mst;
    u16 req_ata;
} Pmt_80254CE4;

typedef struct Help_80254CE4 {
    u8 pad0[0x20];
    s16 client;
    u8 pad22[0x46];
    s32 item;
} Help_80254CE4;

typedef struct Stats_802549B0 {
    s16 atp;
    s16 ata;
    s16 hp;
    s16 dfp;
    s16 evp;
    s16 lck;
    u8 padC[0xC];
} Stats_802549B0;

typedef struct Quest_802549B0 {
    u8 pad0[2];
    s16 f2;
    u8 pad4[8];
    s16 fc;
} Quest_802549B0;

typedef struct Help_802549B0 {
    u8 pad0[0x20];
    s16 client;
    u8 pad22[0x4E];
    u32 item;
    u8 pad74[0x30];
    s32 slot;
} Help_802549B0;

struct T_802553F8 {
    u8 pad[0xB0];
    void (T_802553F8::*pmf)();
};

struct T_80255440;
typedef void (T_80255440::*Fn_80255440)();

struct Tbl_80255440 {
    Fn_80255440 e[3];
};

struct Item_80255440 {
    u8 type;
    s8 sub;
};

struct T_80255440 {
    u8 pad0[0x24];
    u8 disp[0x60 - 0x24];
    u8 flags;
    u8 pad61[3];
    s32 entry;
    Item_80255440 *item;
    u8 pad6C[0x9C - 0x6C];
    s32 id;
    u8 padA0[4];
    s32 techId;
    u8 padA8[0xB0 - 0xA8];
    Fn_80255440 pmf;
};

extern "C" {
s32 is_wrapped__9TItemDataFPv(void *);
s8 get_type__20TWindowSubStatusDispFv(s32);
extern s8 lbl_805D6448;
extern s8 lbl_805D6449;
extern s8 lbl_805D644A;
extern s8 lbl_805D644B;

s32 get_array_entry__13TUnk_804CE018Fi(void *, s32);
s32 get_message_10__20TWindowSubStatusDispFl(s32);
s32 check_equip_requirements(s32, s32, s32 *);
void *get_player_by_client_id(s32 i);
u32 get_quest_id__12TQuestListVMFv();
void *lookup_item_pmt_record(u8 *item);
s32 init_window_layout_entries(void *, void *, int);
s32 set_help_text__15TWindowHelpItemFUl(void *, int);
void TWindowHelpItem__vt9(HelpItem_80254F18 *self);
void preview_unequip_stats__10TObjPlayerFv(s32, Stats_802541E0 *, s32);
s32 preview_equip_stats__10TObjPlayerFv(u8 *arg0, s16 *out, u8 *incoming);
void set_flag8_and_field20__15TWindowHelpItemFl(s32, s32);
void set_flag4_and_field1c__15TWindowHelpItemFl(s32, s32);
}
extern Vec3_802541E0 item_help_resistance_stat_callback;
void set_sprite_uv_from_pixels(u8 *arg0, f32 farg0, f32 farg1);
extern const f32 TWindowHelpItem__data_805DCDE4;
extern const f32 lbl_805DCE00;
extern const f32 lbl_805DCE04;
extern const f32 lbl_805DCE08;
extern const f32 lbl_805DCDEC;
extern const f32 lbl_805DCE0C;
extern "C" {
s32 build_player_equipment_requirement_stats(s32, Stats_80254CE4 *);
void update_requirements__15TWindowHelpItemFv(Help_80254CE4 *self);
void update_stat_comparison__15TWindowHelpItemFv(Help_802549B0 *self);
extern "C" void TWindowHelpItem__vt0(HelpItem_802551C4 *self);
extern "C" void TWindowHelpItem__vt3(HelpItem_8025500C *self);
extern "C" Op_802544D8 *get_attribute_entry__10TObjPlayerFl(s32, s32);
extern "C" void set_percentage_rows__15TWindowHelpItemFPvPvi(void *self, Op_802544D8 *ops, EntryFn_802544D8 fn);
extern "C" u8 lbl_8044EDD8[];
extern "C" u8 lbl_8044EDE0[];
extern "C" u8 lbl_8044EDE8[];
extern "C" u8 lbl_8044EDF0[];
extern "C" u8 lbl_805DCDFC[4];
extern "C" void sub_802534B0__15TWindowHelpItemFv(void *);
extern "C" u8 lbl_8044EDB8[];
extern "C" u8 lbl_8044EDC0[];
extern "C" u8 localized_alphabet_list[];
extern "C" u8 lbl_805D63F0[];
extern "C" u8 lbl_805DCDC8[];
extern "C" u8 lbl_805DCDCC[];
extern "C" u8 lbl_805DCDD0[];
extern "C" u8 lbl_805DCDD4[];
extern "C" u8 lbl_805DCDD8[];
extern "C" u8 lbl_805DCDDC[];
void *TWindowHelpItem__item_layout_entries[67] = {
    (void *)0xc, (void *)0x1, (void *)0xb, (void *)0x0,
    (void *)0x0, (void *)0xb, (void *)0x0, (void *)0x41a00000,
    (void *)0xb, (void *)0x0, (void *)0x42200000, (void *)0xb,
    (void *)0x0, (void *)0x42700000, (void *)0xb, (void *)0x0,
    (void *)0x42a00000, (void *)0xb, (void *)0x0, (void *)0x42c80000,
    (void *)0x6, (void *)0x0, (void *)0x42f60000, (void *)0x42fe0000,
    (void *)0x41a00000, (void *)0x0, (void *)0x43040000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)&localized_alphabet_list, (void *)0x1, (void *)0x4,
    (void *)0x3, (void *)0x42ce0000, (void *)0x42f80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCDC8, (void *)0x4,
    (void *)0x43170000, (void *)0x42f80000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x3, (void *)0x43170000,
    (void *)0x42f80000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)&lbl_805DCDCC, (void *)0x4, (void *)0x43500000, (void *)0x42f80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x43500000, (void *)0x42f80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCDD0,
};
void *lbl_804CF24C[17] = {
    (void *)0x5, (void *)0x1, (void *)0xb, (void *)0x0,
    (void *)0x0, (void *)0xb, (void *)0x0, (void *)0x41a00000,
    (void *)0xb, (void *)0x0, (void *)0x42200000, (void *)0xb,
    (void *)0x0, (void *)0x42700000, (void *)0xb, (void *)0x0,
    (void *)0x42a00000,
};
void *TWindowHelpItem__resistance_layout_entries[31] = {
    (void *)0x7, (void *)0x1, (void *)0xb, (void *)0x0,
    (void *)0x0, (void *)0xb, (void *)0x0, (void *)0x41a00000,
    (void *)0xb, (void *)0x0, (void *)0x42200000, (void *)0xb,
    (void *)0x0, (void *)0x42700000, (void *)0xb, (void *)0x0,
    (void *)0x42a00000, (void *)0x3, (void *)0x425c0000, (void *)0x42f60000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x4, (void *)0x43530000, (void *)0x42f60000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0,
};
void *lbl_804CF30C[118] = {
    (void *)0x10, (void *)0x1, (void *)0xb, (void *)0x0,
    (void *)0x0, (void *)0xb, (void *)0x0, (void *)0x41a00000,
    (void *)0xb, (void *)0x0, (void *)0x42200000, (void *)0x3,
    (void *)0x0, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DCDD4, (void *)0x4, (void *)0x42ac0000,
    (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x2, (void *)0x42c40000, (void *)0x42820000,
    (void *)0x3f000000, (void *)0xff0034ff, (void *)0x18, (void *)0x42c80000,
    (void *)0x42c80000, (void *)0x0, (void *)0xff00ca9e, (void *)0xffff2924,
    (void *)0x3, (void *)0x0, (void *)0x42a00000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCDD8, (void *)0x4,
    (void *)0x42ac0000, (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)0x0, (void *)0x2, (void *)0x42c40000,
    (void *)0x42aa0000, (void *)0x3f000000, (void *)0xffe1000d, (void *)0x18,
    (void *)0x42c80000, (void *)0x42c80000, (void *)0x0, (void *)0xff00ca9e,
    (void *)0xffff2924, (void *)0x3, (void *)0x0, (void *)0x42c80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCDDC,
    (void *)0x4, (void *)0x42ac0000, (void *)0x42c80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x2,
    (void *)0x42c40000, (void *)0x42d20000, (void *)0x3f000000, (void *)0xffffe000,
    (void *)0x18, (void *)0x42c80000, (void *)0x42c80000, (void *)0x0,
    (void *)0xff00ca9e, (void *)0xffff2924, (void *)0x3, (void *)0x0,
    (void *)0x42f00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)&lbl_8044EDB8, (void *)0x4, (void *)0x42ac0000, (void *)0x42f00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
    (void *)0x2, (void *)0x42c40000, (void *)0x42fa0000, (void *)0x3f000000,
    (void *)0xff00ff14, (void *)0x18, (void *)0x42c80000, (void *)0x42c80000,
    (void *)0x0, (void *)0xff00ca9e, (void *)0xffff2924, (void *)0x3,
    (void *)0x0, (void *)0x0, (void *)0x3f000000, (void *)0xffffff00,
    (void *)0x0, (void *)&lbl_8044EDC0,
};
void *lbl_804CF4E4[50] = {
    (void *)0x4, (void *)0x1, (void *)0x6, (void *)0x420c0000,
    (void *)0x41900000, (void *)0x43160000, (void *)0x42d60000, (void *)0x0,
    (void *)0x0, (void *)0x3f19999a, (void *)0xffffffff, (void *)&lbl_805D63F0,
    (void *)0x2, (void *)0x4, (void *)0x6, (void *)0x42aa0000,
    (void *)0x42480000, (void *)0x42480000, (void *)0x422c0000, (void *)0x43160000,
    (void *)0x42ac0000, (void *)0x3f333333, (void *)0xffffffff, (void *)&lbl_805D63F0,
    (void *)0x4, (void *)0x4, (void *)0x6, (void *)0x43010000,
    (void *)0x41c00000, (void *)0x42480000, (void *)0x422c0000, (void *)0x43160000,
    (void *)0x42ac0000, (void *)0x3f333333, (void *)0xffffffff, (void *)&lbl_805D63F0,
    (void *)0x4, (void *)0x4, (void *)0x6, (void *)0x42240000,
    (void *)0x42980000, (void *)0x42480000, (void *)0x422c0000, (void *)0x43160000,
    (void *)0x42ac0000, (void *)0x3f333333, (void *)0xffffffff, (void *)&lbl_805D63F0,
    (void *)0x4, (void *)0x4,
};
void *window_help_item_layout_entries[12] = {
    (void *)0x2, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0xa, (void *)0x0, (void *)0x43000000,
};
void *help_item_tech_disk_window_layout_table[56] = {
    (void *)0x7, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x6, (void *)0x0, (void *)0x42f60000,
    (void *)0x42fe0000, (void *)0x41a00000, (void *)0x0, (void *)0x43040000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)&localized_alphabet_list, (void *)0x1,
    (void *)0x4, (void *)0x3, (void *)0x42ce0000, (void *)0x42f80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCDC8,
    (void *)0x4, (void *)0x43170000, (void *)0x42f80000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3,
    (void *)0x43170000, (void *)0x42f80000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x0, (void *)&lbl_805DCDCC, (void *)0x4, (void *)0x43500000,
    (void *)0x42f80000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0, (void *)0x3, (void *)0x43500000, (void *)0x42f80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)&lbl_805DCDD0,
};
void *TWindowHelpItem__description_text_layout[9] = {
    (void *)0x1, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x0,
    (void *)0x0,
};
void *__vt__15TWindowHelpItem[5] = {
    (void *)0x43640000, (void *)0x43380000, (void *)0x4717f400, (void *)0x0,
    (void *)0x3,
};
void *lbl_804CF6F4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TWindowHelpItem__vt0,
};
void *lbl_804CF700[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TWindowHelpItem__vt1,
};
void *lbl_804CF70C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&sub_802534B0__15TWindowHelpItemFv,
};
void *lbl_804CF718[9] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *lbl_804CF73C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TWindowHelpItem__vt3,
};
void *lbl_804CF748[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TWindowHelpItem__vt4,
};
void *lbl_804CF754[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&sub_802534B0__15TWindowHelpItemFv,
};
void *lbl_804CF760[9] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *lbl_804CF784[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TWindowHelpItem__vt3,
};
void *lbl_804CF790[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TWindowHelpItem__vt7,
};
void *lbl_804CF79C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&sub_802534B0__15TWindowHelpItemFv,
};
void *lbl_804CF7A8[9] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *lbl_804CF7CC[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TWindowHelpItem__vt9,
};
void *lbl_804CF7D8[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TWindowHelpItem__vt10,
};
void *lbl_804CF7E4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TWindowHelpItem__vt11,
};
void *lbl_804CF7F0[9] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *TWindowHelpItem__requirements_update_callback[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_requirements__15TWindowHelpItemFv,
};
void *item_help_level_requirement_callback[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_level_requirement__15TWindowHelpItemFPv,
};
void *TWindowHelpItem__stat_comparison_callback[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_stat_comparison__15TWindowHelpItemFv,
};
void *lbl_804CF838[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_stat_disp2__15TWindowHelpItemFPv,
};
void *lbl_804CF844[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&set_flag4_and_field1c__15TWindowHelpItemFl,
};
void *lbl_804CF850[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&set_flag8_and_field20__15TWindowHelpItemFl,
};
void *lbl_804CF85C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&set_flag8_and_field20__15TWindowHelpItemFl,
};
#define TWindowHelpItem__item_layout_entries ((s32 *)TWindowHelpItem__item_layout_entries)
#define TWindowHelpItem__resistance_layout_entries ((u8 *)TWindowHelpItem__resistance_layout_entries)
#define TWindowHelpItem__requirements_update_callback (*(Vec3_802551C4 *)TWindowHelpItem__requirements_update_callback)
#define item_help_level_requirement_callback (*(Vec3_8025500C *)item_help_level_requirement_callback)
#define TWindowHelpItem__stat_comparison_callback (*(Vec3_80254F18 *)TWindowHelpItem__stat_comparison_callback)

void TWindowHelpItem::update_stat_disp() {
    s32 sp8;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 player;

    player = (s32)get_player_by_client_id(this->m_20);
    if (player != 0) {
        a = get_array_entry__13TUnk_804CE018Fi(this, 0);
        b = get_array_entry__13TUnk_804CE018Fi(this, 1);
        c = get_array_entry__13TUnk_804CE018Fi(this, 2);
        d = get_array_entry__13TUnk_804CE018Fi(this, 3);
        e = get_array_entry__13TUnk_804CE018Fi(this, 4);
        if (this->m_70 != 0) {
            if (check_equip_requirements(player, this->m_70, &sp8) != 0) {
                TWindowHelpItem::set_flag_0x10((u16 *)a, 1);
                TWindowHelpItem::set_flag_0x10((u16 *)b, 1);
                TWindowHelpItem::set_flag_0x10((u16 *)c, 1);
                TWindowHelpItem::set_flag_0x10((u16 *)d, 1);
                TWindowHelpItem::set_flag_0x10((u16 *)e, 1);
                return;
            }
            TWindowHelpItem::set_flag_0x10((u16 *)a, 0);
            TWindowHelpItem::set_flag_0x10((u16 *)b, 0);
            TWindowHelpItem::set_flag_0x10((u16 *)c, 0);
            TWindowHelpItem::set_flag_0x10((u16 *)d, 0);
            TWindowHelpItem::set_flag_0x10((u16 *)e, 0);
        }
    }
}

#define self ((HelpItem_802541E0 *)arg0)
void TWindowHelpItem::update_resistance_rows(void *arg0) {
    Stats_802541E0 st;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 pl;
    ((TWindowSubStatusDisp *)(&st))->clear_fields();
    pl = (s32)get_player_by_client_id(self->player);
    if (pl != 0) {
        init_window_layout_entries(self->disp, TWindowHelpItem__resistance_layout_entries, self->player);
        self->pos = item_help_resistance_stat_callback;
        a = get_array_entry__13TUnk_804CE018Fi(self, 0);
        b = get_array_entry__13TUnk_804CE018Fi(self, 1);
        c = get_array_entry__13TUnk_804CE018Fi(self, 2);
        d = get_array_entry__13TUnk_804CE018Fi(self, 3);
        e = get_array_entry__13TUnk_804CE018Fi(self, 4);
        set_help_text__15TWindowHelpItemFUl((void *)a, get_message_10__20TWindowSubStatusDispFl(0x89));
        set_help_text__15TWindowHelpItemFUl((void *)b, get_message_10__20TWindowSubStatusDispFl(0x8A));
        set_help_text__15TWindowHelpItemFUl((void *)c, get_message_10__20TWindowSubStatusDispFl(0x8B));
        set_help_text__15TWindowHelpItemFUl((void *)d, get_message_10__20TWindowSubStatusDispFl(0x8C));
        set_help_text__15TWindowHelpItemFUl((void *)e, get_message_10__20TWindowSubStatusDispFl(0x8D));
        ((TWindowHelpItem *)a)->set_flag4_and_field1c(((TWindowSubStatusDisp *)pl)->get_stat());
        ((TWindowHelpItem *)b)->set_flag4_and_field1c(((TObjPlayer *)pl)->get_class_id());
        ((TWindowHelpItem *)c)->set_flag4_and_field1c(((TObjPlayer *)pl)->get_item_index());
        ((TWindowHelpItem *)d)->set_flag4_and_field1c(((TWindowSubStatusDisp *)pl)->get_field_2F8());
        ((TWindowHelpItem *)e)->set_flag4_and_field1c(((TWindowSubStatusDisp *)pl)->get_item_type());
        if (self->item != 0) {
            if (((TWindowHelpItem *)self)->is_item_already_equipped() != 0) {
                preview_unequip_stats__10TObjPlayerFv(pl, &st, self->itemId);
            } else {
                preview_equip_stats__10TObjPlayerFv((u8 *)pl, (s16 *)&st, (u8 *)self->item);
            }
            ((TWindowHelpItem *)a)->set_flag8_and_field20(st.atp);
            ((TWindowHelpItem *)b)->set_flag8_and_field20(st.dfp);
            ((TWindowHelpItem *)c)->set_flag8_and_field20(st.mst);
            ((TWindowHelpItem *)d)->set_flag8_and_field20(st.evp);
            ((TWindowHelpItem *)e)->set_flag8_and_field20(st.ata);
        }
    }
}
#undef self

void TWindowHelpItem__vt7(s32 arg0) {
    s32 temp_r31;
    s32 temp_r31_2;
    TWindowHelpItem::update_resistance_rows((void *)arg0);
    temp_r31 = get_array_entry__13TUnk_804CE018Fi((void *)arg0, 5);
    temp_r31_2 = get_array_entry__13TUnk_804CE018Fi((void *)arg0, 6);
    ((TWindowHelpItem *)temp_r31)->set_flag0_bit2();
    ((TWindowHelpItem *)temp_r31_2)->set_flag0_bit2();
}
void TWindowHelpItem__vt4(void *arg0) {
    void *temp_r30;
    void *temp_r31;
    TWindowHelpItem::update_resistance_rows(arg0);
    temp_r30 = ((void *)get_array_entry__13TUnk_804CE018Fi(arg0, 5));
    temp_r31 = ((void *)get_array_entry__13TUnk_804CE018Fi(arg0, 6));
    TWindowDuelResult::set_default_status(temp_r30, get_message_10__20TWindowSubStatusDispFl(0xA1));
    ((TWindowHelpItem *)temp_r30)->reset_float_field();
    *(s32 *)((s8 *)temp_r31 + 0x20) = (s32) *(u8 *)((s8 *)(*(void **)((s8 *)arg0 + 0x68)) + 5);
}
void set_percentage_rows__15TWindowHelpItemFPvPvi(void *self, Op_802544D8 *ops, EntryFn_802544D8 fn) {
    u32 i;
    Entry_802544D8 *e0;
    Entry_802544D8 *e1;
    Entry_802544D8 *e2;
    Entry_802544D8 *e3;
    Entry_802544D8 *e4;

    e0 = (Entry_802544D8 *)get_array_entry__13TUnk_804CE018Fi(self, 0);
    e1 = (Entry_802544D8 *)get_array_entry__13TUnk_804CE018Fi(self, 1);
    e2 = (Entry_802544D8 *)get_array_entry__13TUnk_804CE018Fi(self, 2);
    e3 = (Entry_802544D8 *)get_array_entry__13TUnk_804CE018Fi(self, 3);
    e4 = (Entry_802544D8 *)get_array_entry__13TUnk_804CE018Fi(self, 4);
    (e0->*fn)(0);
    (e1->*fn)(0);
    (e2->*fn)(0);
    (e3->*fn)(0);
    if (ops != NULL) {
        for (i = 0; i < 3; i++, ops++) {
            switch (ops->slot) {
            case 1:
                (e0->*fn)(ops->value);
                break;
            case 2:
                (e1->*fn)(ops->value);
                break;
            case 3:
                (e2->*fn)(ops->value);
                break;
            case 4:
                (e3->*fn)(ops->value);
                break;
            case 5:
                (e4->*fn)(ops->value);
                break;
            }
        }
    }
}
void update_stat_disp2__15TWindowHelpItemFPv(void *arg0) {
    s32 sp8;
    s32 temp_r31;
    s32 temp_r30;
    s32 temp_r29;
    s32 temp_r28;
    s32 temp_r27;
    s32 player;
    u32 temp_r4;
    player = (s32)get_player_by_client_id(*(s16 *)((s8 *)arg0 + 0x20));
    if ((player != 0) && (temp_r31 = get_array_entry__13TUnk_804CE018Fi(arg0, 0), temp_r30 = get_array_entry__13TUnk_804CE018Fi(arg0, 1), temp_r29 = get_array_entry__13TUnk_804CE018Fi(arg0, 2), temp_r28 = get_array_entry__13TUnk_804CE018Fi(arg0, 3), temp_r27 = get_array_entry__13TUnk_804CE018Fi(arg0, 4), (temp_r4 = *(u32 *)((s8 *)arg0 + 0x70), (temp_r4 == 0U) == 0))) {
        if (check_equip_requirements(player, temp_r4, &sp8) != 0) {
            TWindowHelpItem::set_flag_0x10((u16 *)temp_r31, 1);
            TWindowHelpItem::set_flag_0x10((u16 *)temp_r30, 1);
            TWindowHelpItem::set_flag_0x10((u16 *)temp_r29, 1);
            TWindowHelpItem::set_flag_0x10((u16 *)temp_r28, 1);
            TWindowHelpItem::set_flag_0x10((u16 *)temp_r27, 1);
            return;
        }
        TWindowHelpItem::set_flag_0x10((u16 *)temp_r31, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)temp_r30, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)temp_r29, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)temp_r28, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)temp_r27, 0);
    }
}

struct HelpItem_802547C0 {
    u8 pad0[0x20];
    s16 player;
    u8 pad22[2];
    u8 disp[0x70 - 0x24];
    u32 item;
    u8 pad74[0xA4 - 0x74];
    s32 itemId;
    u8 padA8[0xB0 - 0xA8];
    EntryFn_802544D8 pos;
};
#define lbl_804CF838 (*(EntryFn_802544D8 *)lbl_804CF838)
#define lbl_804CF844 (*(EntryFn_802544D8 *)lbl_804CF844)
#define lbl_804CF850 (*(EntryFn_802544D8 *)lbl_804CF850)
#define lbl_804CF85C (*(EntryFn_802544D8 *)lbl_804CF85C)
#define self ((HelpItem_802547C0 *)arg0)
void TWindowHelpItem__vt1(void *arg0) {
    s32 player;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;

    player = (s32)get_player_by_client_id(self->player);
    if (player != 0) {
        init_window_layout_entries(self->disp, lbl_804CF24C, self->player);
        self->pos = lbl_804CF838;
        a = get_array_entry__13TUnk_804CE018Fi(self, 0);
        b = get_array_entry__13TUnk_804CE018Fi(self, 1);
        c = get_array_entry__13TUnk_804CE018Fi(self, 2);
        d = get_array_entry__13TUnk_804CE018Fi(self, 3);
        e = get_array_entry__13TUnk_804CE018Fi(self, 4);
        set_help_text__15TWindowHelpItemFUl((void *)a, (int)lbl_8044EDD8);
        set_help_text__15TWindowHelpItemFUl((void *)b, (int)lbl_8044EDE0);
        set_help_text__15TWindowHelpItemFUl((void *)c, (int)lbl_8044EDE8);
        set_help_text__15TWindowHelpItemFUl((void *)d, (int)lbl_8044EDF0);
        set_help_text__15TWindowHelpItemFUl((void *)e, (int)lbl_805DCDFC);
        ((TWindowHelpItem *)a)->set_flag0_bit20();
        ((TWindowHelpItem *)b)->set_flag0_bit20();
        ((TWindowHelpItem *)c)->set_flag0_bit20();
        ((TWindowHelpItem *)d)->set_flag0_bit20();
        ((TWindowHelpItem *)e)->set_flag0_bit20();
        set_percentage_rows__15TWindowHelpItemFPvPvi(self, get_attribute_entry__10TObjPlayerFl(player, 0), lbl_804CF844);
        if (self->item != 0) {
            if (((TWindowHelpItem *)self)->is_item_already_equipped() != 0) {
                set_percentage_rows__15TWindowHelpItemFPvPvi(self, 0, lbl_804CF850);
            } else {
                set_percentage_rows__15TWindowHelpItemFPvPvi(self, (Op_802544D8 *)(self->item + 6), lbl_804CF85C);
            }
            ((TWindowHelpItem *)e)->update_visible_flags();
        }
    }
}
#undef self
#undef lbl_804CF838
#undef lbl_804CF844
#undef lbl_804CF850
#undef lbl_804CF85C

void update_stat_comparison__15TWindowHelpItemFv(Help_802549B0 *self) {
    s32 flags;
    Stats_802549B0 st;
    s32 e0;
    s32 e3;
    s32 e1;
    s32 e4;
    s32 e2;
    s32 e5;
    Quest_802549B0 *q;
    s32 pl;
    ((TWindowSubStatusDisp *)((struct Stats_802541E0 *)&st))->clear_fields();
    pl = (s32)get_player_by_client_id(self->client);
    if (pl == 0) {
        return;
    }
    q = (Quest_802549B0 *)get_quest_id__12TQuestListVMFv();
    if (q == NULL) {
        return;
    }
    e0 = get_array_entry__13TUnk_804CE018Fi(self, 0);
    e3 = get_array_entry__13TUnk_804CE018Fi(self, 3);
    e1 = get_array_entry__13TUnk_804CE018Fi(self, 1);
    e4 = get_array_entry__13TUnk_804CE018Fi(self, 4);
    e2 = get_array_entry__13TUnk_804CE018Fi(self, 2);
    e5 = get_array_entry__13TUnk_804CE018Fi(self, 5);
    ((TWindowHelpItem *)e0)->set_flag4_and_field1c(((TObjPlayer *)pl)->get_field_2c8() + ((TUnk_804806E8 *)pl)->get_actor_attack_params_atp_min() + TObjPlayer__sub_800A776C((void *)pl));
    ((TWindowHelpItem *)e3)->set_flag4_and_field1c(((TObjPlayer *)pl)->get_ata());
    ((TWindowHelpItem *)e1)->set_flag4_and_field1c(((TWindowSubStatusDisp *)pl)->get_value());
    ((TWindowHelpItem *)e4)->set_flag4_and_field1c(((TObjPlayer *)pl)->get_hp());
    ((TWindowHelpItem *)e2)->set_flag4_and_field1c(q->f2);
    ((TWindowHelpItem *)e5)->set_flag4_and_field1c(q->fc);
    if (self->item == 0) {
        return;
    }
    if (((TWindowHelpItem *)self)->is_item_already_equipped() != 0) {
        preview_unequip_stats__10TObjPlayerFv(pl, (Stats_802541E0 *)((struct Stats_802541E0 *)&st), self->slot);
    } else {
        preview_equip_stats__10TObjPlayerFv((u8 *)pl, (s16 *)((Stats_802541E0 *)((struct Stats_802541E0 *)&st)), (u8 *)self->item);
    }
    ((TWindowHelpItem *)e0)->set_flag8_and_field20(st.atp);
    ((TWindowHelpItem *)e3)->set_flag8_and_field20(st.dfp);
    ((TWindowHelpItem *)e1)->set_flag8_and_field20(st.ata);
    ((TWindowHelpItem *)e4)->set_flag8_and_field20(st.evp);
    ((TWindowHelpItem *)e2)->set_flag8_and_field20(st.hp);
    ((TWindowHelpItem *)e5)->set_flag8_and_field20(st.lck);
    if (check_equip_requirements(pl, self->item, &flags) != 0) {
        TWindowHelpItem::set_flag_0x10((u16 *)e0, 1);
        TWindowHelpItem::set_flag_0x10((u16 *)e3, 1);
        TWindowHelpItem::set_flag_0x10((u16 *)e1, 1);
        TWindowHelpItem::set_flag_0x10((u16 *)e4, 1);
        TWindowHelpItem::set_flag_0x10((u16 *)e2, 1);
        TWindowHelpItem::set_flag_0x10((u16 *)e5, 1);
    } else {
        TWindowHelpItem::set_flag_0x10((u16 *)e0, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)e3, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)e1, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)e4, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)e2, 0);
        TWindowHelpItem::set_flag_0x10((u16 *)e5, 0);
    }
}

void update_level_requirement__15TWindowHelpItemFPv(u8 *arg0) {
    s32 sp8;
    u8 *temp_r30;
    u8 *item_pmt_record;
    u8 *player;
    player = (u8 *)(((u8 *)get_player_by_client_id(*(s16 *)((s8 *)arg0 + 0x20))));
    if (player != NULL) {
        if (get_quest_id__12TQuestListVMFv() != 0U) {
            update_stat_comparison__15TWindowHelpItemFv((Help_802549B0 *)(arg0));
            temp_r30 = (u8 *)(((u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 0xA)));
            item_pmt_record = (u8 *)(lookup_item_pmt_record((u8 *)(*(s32 *)((s8 *)arg0 + 0x68))));
            if (check_equip_requirements((s32)player, (s32)((s32)((int) (*(s32 *)((s8 *)arg0 + 0x68)))), (s32 *)((s32 *)&sp8)) == 0) {
                if (!(sp8 & 1)) {
                    goto block_4;
                }
            } else {
block_4:
                if ((u8) *(u8 *)((s8 *)item_pmt_record + 0x10) != 0) {
                    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) (((VObj_18_eecf68 *)(player))->m14() + 1);
                }
            }
        }
    }
}

struct Stats_802541E0;
void update_requirements__15TWindowHelpItemFv(Help_80254CE4 *self) {
    s32 flags;
    Stats_80254CE4 st;
    s32 pl;
    u8 *entry;
    Pmt_80254CE4 *pmt;
    ((TWindowSubStatusDisp *)((struct Stats_802541E0 *)&st))->clear_fields();
    pl = (s32)get_player_by_client_id(self->client);
    if (pl == 0) {
        return;
    }
    update_stat_comparison__15TWindowHelpItemFv((Help_802549B0 *)(self));
    entry = (u8 *)get_array_entry__13TUnk_804CE018Fi(self, 10);
    pmt = (Pmt_80254CE4 *)lookup_item_pmt_record((u8 *)self->item);
    if (check_equip_requirements(pl, self->item, (s32 *)&flags) == 0 && (flags & 1)) {
        return;
    }
    if (pmt->req_atp != 0) {
        if (build_player_equipment_requirement_stats(pl, &st) != 0) {
            *(s32 *)(entry + 0x20) = st.atp;
        }
    } else if (pmt->req_mst != 0) {
        if (build_player_equipment_requirement_stats(pl, &st) != 0) {
            *(s32 *)(entry + 0x20) = st.mst;
        }
    } else if (pmt->req_ata != 0) {
        if (build_player_equipment_requirement_stats(pl, &st) != 0) {
            *(s32 *)(entry + 0x20) = st.ata;
        }
    }
}

void TWindowHelpItem::init_help_texts() {
    s32 temp_r31;
    s32 temp_r30;
    s32 temp_r29;
    s32 temp_r28;
    s32 temp_r27;
    s32 temp_r26;

    init_window_layout_entries((void *) ((u8 *) this + 0x24), TWindowHelpItem__item_layout_entries, this->m_20);
    temp_r31 = get_array_entry__13TUnk_804CE018Fi(this, 0);
    temp_r30 = get_array_entry__13TUnk_804CE018Fi(this, 1);
    temp_r29 = get_array_entry__13TUnk_804CE018Fi(this, 2);
    temp_r28 = get_array_entry__13TUnk_804CE018Fi(this, 3);
    temp_r27 = get_array_entry__13TUnk_804CE018Fi(this, 4);
    temp_r26 = get_array_entry__13TUnk_804CE018Fi(this, 5);
    set_help_text__15TWindowHelpItemFUl((void *)temp_r31, (int) (get_message_10__20TWindowSubStatusDispFl(0x83)));
    set_help_text__15TWindowHelpItemFUl((void *)temp_r30, (int) (get_message_10__20TWindowSubStatusDispFl(0x84)));
    set_help_text__15TWindowHelpItemFUl((void *)temp_r29, (int) (get_message_10__20TWindowSubStatusDispFl(0x85)));
    set_help_text__15TWindowHelpItemFUl((void *)temp_r28, (int) (get_message_10__20TWindowSubStatusDispFl(0x86)));
    set_help_text__15TWindowHelpItemFUl((void *)temp_r27, (int) (get_message_10__20TWindowSubStatusDispFl(0x87)));
    set_help_text__15TWindowHelpItemFUl((void *)temp_r26, (int) (get_message_10__20TWindowSubStatusDispFl(0x88)));
}

void TWindowHelpItem__vt9(HelpItem_80254F18 *self) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    ((TWindowHelpItem *)self)->init_help_texts();
    self->pos = TWindowHelpItem__stat_comparison_callback;
    a = get_array_entry__13TUnk_804CE018Fi(self, 6);
    b = get_array_entry__13TUnk_804CE018Fi(self, 7);
    c = get_array_entry__13TUnk_804CE018Fi(self, 8);
    d = get_array_entry__13TUnk_804CE018Fi(self, 9);
    e = get_array_entry__13TUnk_804CE018Fi(self, 10);
    f = get_array_entry__13TUnk_804CE018Fi(self, 11);
    ((TWindowHelpItem *)a)->set_flag0_bit2();
    ((TWindowHelpItem *)b)->set_flag0_bit2();
    ((TWindowHelpItem *)c)->set_flag0_bit2();
    ((TWindowHelpItem *)d)->set_flag0_bit2();
    ((TWindowHelpItem *)e)->set_flag0_bit2();
    ((TWindowHelpItem *)f)->set_flag0_bit2();
}

void TWindowHelpItem__vt3(HelpItem_8025500C *self) {
    s32 pl;
    u8 *item;
    s32 flags;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;

    pl = (s32)get_player_by_client_id(self->player);
    if (pl != 0) {
        ((TWindowHelpItem *)self)->init_help_texts();
        self->pos = item_help_level_requirement_callback;
        a = get_array_entry__13TUnk_804CE018Fi(self, 6);
        b = get_array_entry__13TUnk_804CE018Fi(self, 7);
        c = get_array_entry__13TUnk_804CE018Fi(self, 8);
        d = get_array_entry__13TUnk_804CE018Fi(self, 9);
        e = get_array_entry__13TUnk_804CE018Fi(self, 10);
        f = get_array_entry__13TUnk_804CE018Fi(self, 11);
        item = (u8 *)lookup_item_pmt_record((u8 *)self->itemId);
        if (check_equip_requirements(pl, self->itemId, &flags) == 0 && (flags & 1)) {
            set_sprite_uv_from_pixels((u8 *)a, TWindowHelpItem__data_805DCDE4, lbl_805DCE00);
            ((TWindowHelpItem *)b)->set_flag0_bit2();
            ((TWindowHelpItem *)c)->set_flag0_bit2();
            ((TWindowHelpItem *)d)->set_flag0_bit2();
            ((TWindowHelpItem *)e)->set_flag0_bit2();
            ((TWindowHelpItem *)f)->set_flag0_bit2();
            return;
        }
        if (item[0x10] != 0) {
            set_sprite_uv_from_pixels((u8 *)a, TWindowHelpItem__data_805DCDE4, lbl_805DCE04);
            ((TWindowHelpItem *)b)->reset_float_field();
            ((TWindowHelpItem *)d)->reset_float_field();
            ((TWindowHelpItem *)f)->reset_float_field();
            *(s32 *)(c + 0x20) = item[0x10] + 1;
            return;
        }
        ((TWindowHelpItem *)a)->set_flag0_bit2();
        ((TWindowHelpItem *)b)->set_flag0_bit2();
        ((TWindowHelpItem *)c)->set_flag0_bit2();
        ((TWindowHelpItem *)d)->set_flag0_bit2();
        ((TWindowHelpItem *)e)->set_flag0_bit2();
        ((TWindowHelpItem *)f)->set_flag0_bit2();
    }
}

void TWindowHelpItem__vt0(HelpItem_802551C4 *self) {
    s32 pl;
    u8 *item;
    s32 flags;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;

    pl = (s32)get_player_by_client_id(self->player);
    if (pl != 0) {
        ((TWindowHelpItem *)self)->init_help_texts();
        self->pos = TWindowHelpItem__requirements_update_callback;
        a = get_array_entry__13TUnk_804CE018Fi(self, 6);
        b = get_array_entry__13TUnk_804CE018Fi(self, 7);
        c = get_array_entry__13TUnk_804CE018Fi(self, 8);
        d = get_array_entry__13TUnk_804CE018Fi(self, 9);
        e = get_array_entry__13TUnk_804CE018Fi(self, 10);
        f = get_array_entry__13TUnk_804CE018Fi(self, 11);
        item = (u8 *)lookup_item_pmt_record((u8 *)self->itemId);
        if (check_equip_requirements(pl, self->itemId, &flags) == 0 && (flags & 1)) {
            set_sprite_uv_from_pixels((u8 *)a, TWindowHelpItem__data_805DCDE4, lbl_805DCE00);
            ((TWindowHelpItem *)b)->set_flag0_bit2();
            ((TWindowHelpItem *)c)->set_flag0_bit2();
            ((TWindowHelpItem *)d)->set_flag0_bit2();
            ((TWindowHelpItem *)e)->set_flag0_bit2();
            ((TWindowHelpItem *)f)->set_flag0_bit2();
            return;
        }
        if (*(u16 *)(item + 0xE) != 0) {
            set_sprite_uv_from_pixels((u8 *)a, TWindowHelpItem__data_805DCDE4, lbl_805DCE08);
            ((TWindowHelpItem *)b)->reset_float_field();
            ((TWindowHelpItem *)d)->reset_float_field();
            ((TWindowHelpItem *)f)->reset_float_field();
            *(s32 *)(c + 0x20) = *(u16 *)(item + 0xE);
            return;
        }
        if (*(u16 *)(item + 0x10) != 0) {
            set_sprite_uv_from_pixels((u8 *)a, TWindowHelpItem__data_805DCDE4, lbl_805DCDEC);
            ((TWindowHelpItem *)b)->reset_float_field();
            ((TWindowHelpItem *)d)->reset_float_field();
            ((TWindowHelpItem *)f)->reset_float_field();
            *(s32 *)(c + 0x20) = *(u16 *)(item + 0x10);
            return;
        }
        if (*(u16 *)(item + 0x12) != 0) {
            set_sprite_uv_from_pixels((u8 *)a, TWindowHelpItem__data_805DCDE4, lbl_805DCE0C);
            ((TWindowHelpItem *)b)->reset_float_field();
            ((TWindowHelpItem *)d)->reset_float_field();
            ((TWindowHelpItem *)f)->reset_float_field();
            *(s32 *)(c + 0x20) = *(u16 *)(item + 0x12);
            return;
        }
        ((TWindowHelpItem *)a)->set_flag0_bit2();
        ((TWindowHelpItem *)b)->set_flag0_bit2();
        ((TWindowHelpItem *)c)->set_flag0_bit2();
        ((TWindowHelpItem *)d)->set_flag0_bit2();
        ((TWindowHelpItem *)e)->set_flag0_bit2();
        ((TWindowHelpItem *)f)->set_flag0_bit2();
    }
}

void TWindowHelpItem::invoke_callback_pmf() {
    T_802553F8 *o = (T_802553F8 *)this;
    if (o->pmf) {
        (o->*(o->pmf))();
    }
}

#define lbl_804CF6F4 (*(Fn_80255440 *)lbl_804CF6F4)
#define lbl_804CF700 (*(Fn_80255440 *)lbl_804CF700)
#define lbl_804CF70C (*(Fn_80255440 *)lbl_804CF70C)
#define lbl_804CF73C (*(Fn_80255440 *)lbl_804CF73C)
#define lbl_804CF748 (*(Fn_80255440 *)lbl_804CF748)
#define lbl_804CF754 (*(Fn_80255440 *)lbl_804CF754)
#define lbl_804CF784 (*(Fn_80255440 *)lbl_804CF784)
#define lbl_804CF790 (*(Fn_80255440 *)lbl_804CF790)
#define lbl_804CF79C (*(Fn_80255440 *)lbl_804CF79C)
#define lbl_804CF7CC (*(Fn_80255440 *)lbl_804CF7CC)
#define lbl_804CF7D8 (*(Fn_80255440 *)lbl_804CF7D8)
#define lbl_804CF7E4 (*(Fn_80255440 *)lbl_804CF7E4)
#define lbl_804CF718 (*(Tbl_80255440 *)lbl_804CF718)
#define lbl_804CF760 (*(Tbl_80255440 *)lbl_804CF760)
#define lbl_804CF7A8 (*(Tbl_80255440 *)lbl_804CF7A8)
#define lbl_804CF7F0 (*(Tbl_80255440 *)lbl_804CF7F0)

void TWindowHelpItem::dispatch_item_help() {
#define self ((T_80255440 *)this)
    s8 type;
    u8 sub;

    if (lbl_805D6448 == 0) {
        lbl_804CF718.e[0] = lbl_804CF6F4;
        lbl_804CF718.e[1] = lbl_804CF700;
        lbl_804CF718.e[2] = lbl_804CF70C;
        lbl_805D6448 = 1;
    }
    if (lbl_805D6449 == 0) {
        lbl_804CF760.e[0] = lbl_804CF73C;
        lbl_804CF760.e[1] = lbl_804CF748;
        lbl_804CF760.e[2] = lbl_804CF754;
        lbl_805D6449 = 1;
    }
    if (lbl_805D644A == 0) {
        lbl_804CF7A8.e[0] = lbl_804CF784;
        lbl_804CF7A8.e[1] = lbl_804CF790;
        lbl_804CF7A8.e[2] = lbl_804CF79C;
        lbl_805D644A = 1;
    }
    if (lbl_805D644B == 0) {
        lbl_804CF7F0.e[0] = lbl_804CF7CC;
        lbl_804CF7F0.e[1] = lbl_804CF7D8;
        lbl_804CF7F0.e[2] = lbl_804CF7E4;
        lbl_805D644B = 1;
    }
    ((TWindowSubStatusDisp *)(self->disp))->destroy_all_items();
    if (self->id == -1) {
        self->flags &= 0xF8;
        self->pmf = 0;
        return;
    }
    type = get_type__20TWindowSubStatusDispFv(self->entry);
    self->flags |= 2;
    ((TWindowHelpItem *)self)->sub_80255E24();
    if (self->item == NULL) {
        if (self->techId == -0xFF) {
            self->flags &= ~2;
            ((TWindowHelpItem *)self)->set_flag60_bit4();
            ((TWindowHelpItem *)self)->init_text((void *)(get_message_10__20TWindowSubStatusDispFl(0x10D)));
        } else {
            self->flags &= ~2;
            ((TWindowHelpItem *)self)->set_flag60_bit4();
            ((TWindowHelpItem *)self)->init_text((void *)(get_localized_text_entry(0x10, (self->techId & 0xF) + 0x18)));
        }
    } else if (is_wrapped__9TItemDataFPv(self->item) != 0) {
        self->flags &= ~2;
        ((TWindowHelpItem *)self)->set_flag60_bit4();
        ((TWindowHelpItem *)self)->update_displayed_item();
    } else {
        sub = self->item->sub;
        switch (self->item->type) {
        case 0:
            (self->*lbl_804CF718.e[type])();
            break;
        case 1:
            if (sub == 3) {
                self->flags &= ~2;
                ((TWindowHelpItem *)self)->set_flag60_bit4();
                ((TWindowHelpItem *)self)->sub_802534B0();
            } else if (sub == 2) {
                (self->*lbl_804CF7A8.e[type])();
            } else {
                (self->*lbl_804CF760.e[type])();
            }
            break;
        case 2:
            (self->*lbl_804CF7F0.e[type])();
            break;
        case 3:
            self->flags &= ~2;
            ((TWindowHelpItem *)self)->set_flag60_bit4();
            if (sub == 2) {
                ((TWindowHelpItem *)self)->update_tech_disk_details();
            } else {
                ((TWindowHelpItem *)self)->update_displayed_item();
            }
            break;
        default:
            self->flags &= 0xFC;
            self->pmf = 0;
            break;
        }
    }
    ((TWindowHelpItem *)self)->invoke_callback_pmf();
}

#undef self
#undef lbl_804CF6F4
#undef lbl_804CF700
#undef lbl_804CF70C
#undef lbl_804CF73C
#undef lbl_804CF748
#undef lbl_804CF754
#undef lbl_804CF784
#undef lbl_804CF790
#undef lbl_804CF79C
#undef lbl_804CF7CC
#undef lbl_804CF7D8
#undef lbl_804CF7E4
#undef lbl_804CF718
#undef lbl_804CF760
#undef lbl_804CF7A8
#undef lbl_804CF7F0

void TWindowHelpItem__set_displayed_item_by_id(u8 *window_help_item, s32 arg1) {
    u8 *item;
    if (arg1 == -1) {
        ((TWindowHelpItem *)window_help_item)->set_displayed_item_data(NULL, (void*)((void*)((void *)-1)));
        return;
    }
    item = (u8 *)(find_item_by_id(arg1));
    if (item == NULL) {
        ((TWindowHelpItem *)window_help_item)->set_displayed_item_data(NULL, (void*)((void*)((void *) arg1)));
        return;
    }
    ((TItem *)item)->copy_to_item_data((TItemData *)(window_help_item + 0x88));
    ((TWindowHelpItem *)window_help_item)->set_displayed_item_data(window_help_item + 0x88, (void*)((void*)((void *) arg1)));
}
void show_item_by_id__15TWindowHelpItemFPvi(u8 *window_help_item, s32 arg1) {
    u8 *item;
    if (arg1 == -1) {
        ((TWindowHelpItem *)window_help_item)->set_items_and_refresh(NULL, (void*)((void*)((void *)-1)));
        return;
    }
    item = (u8 *)(find_item_by_id(arg1));
    if (item == NULL) {
        ((TWindowHelpItem *)window_help_item)->set_items_and_refresh(NULL, (void*)((void*)((void *) arg1)));
        return;
    }
    ((TItem *)item)->copy_to_item_data((TItemData *)(window_help_item + 0x74));
    ((TWindowHelpItem *)window_help_item)->set_items_and_refresh(window_help_item + 0x74, (void*)((void*)((void *) arg1)));
}
void TWindowHelpItem::set_displayed_item_colored(u32 arg1) {
    s32 var_r5;
    var_r5 = -0x100;
    if (arg1 == 0U) {
        var_r5 = -1;
    }
    set_displayed_item_data((void*)arg1, (void*)var_r5);
}
void TWindowHelpItem::set_displayed_item_data(void* a1, void* a2) { *(void* *)&this->m_a4 = a2; *(void* *)&this->m_70 = a1; update_cursor_selection(); dispatch_item_help(); }
void TWindowHelpItem::set_items_and_refresh(void* a1, void* a2) { *(void* *)&this->m_a0 = a2; *(void* *)&this->m_6c = a1; update_cursor_selection(); dispatch_item_help(); }
}
