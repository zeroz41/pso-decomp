#include "types.h"
#include "pso/item/TItem.h"
#include "pso/misc/TWindowHelpItem_80243408.h"
#include "pso/misc/TWindowSubStatusDisp_802598E4.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct Base_80243464 { char pad[0x18]; };
struct VObj_80243464 : Base_80243464 {
    virtual void m0();   virtual void m1();   virtual void m2();   virtual void m3();
    virtual void m4();   virtual void m5();   virtual void m6();   virtual void m7();
    virtual void m8();   virtual void m9();   virtual void m10();  virtual void m11();
    virtual void m12();  virtual void m13();  virtual void m14();  virtual void m15();
    virtual void m16();  virtual void m17();  virtual void m18();  virtual void m19();
    virtual void m20();  virtual void m21();  virtual void m22();  virtual void m23();
    virtual void m24();  virtual void m25();  virtual void m26();  virtual void m27();
    virtual void m28();  virtual void m29();  virtual void m30();  virtual void m31();
    virtual void m32();  virtual void m33();  virtual s32 m34();
};

struct Icon_80243630 {
    u8 pad0[0x1C];
    f32 u0;
    f32 v0;
    f32 u1;
    f32 v1;
    u8 pad2c[0x34 - 0x2C];
    s32 kind;
};

struct UV_80243630 { f32 u; f32 v; };

struct PaletteItemKind { u8 group; u8 index; };

extern "C" {
void *get_player_by_client_id(s32 i);
s8 clamp_char_at__10TObjPlayerFl(u32, s32);
extern const f32 lbl_805DCA28;
extern const f32 lbl_805DCA2C;
extern const f32 lbl_805DCA30;
extern const f32 lbl_805DCA34;
extern const f32 lbl_805DCA38;
extern const f32 lbl_805DCA3C;
extern const f32 lbl_805DCA40;
extern const f32 lbl_805DCA44;
void draw_action_palette_icon(Icon_80243630 *icon, u16 group, u16 index);
s32 fn_801B7CEC(void *player, s32 kind, u8 group, u8 index);
}
s32 get_palette_consumable_count(u16 slot, s32 client_id);
extern const PaletteItemKind lbl_8044E5E8[13];
void set_sprite_uv_from_pixels(u8 *arg0, f32 farg0, f32 farg1);

extern f32 lbl_805DCA1C;
extern f32 lbl_805DCA20;
extern f32 lbl_805DCA24;

void TWindowHelpItem::set_help_text(s32 arg0, s32 arg1) {
    if (((TBoss8Dragon *)arg1)->test_card_flag_2() != 0) {
        set_sprite_uv_from_pixels((u8 *)arg0, lbl_805DCA1C, lbl_805DCA20);
        return;
    }
    set_sprite_uv_from_pixels((u8 *)arg0, lbl_805DCA1C, lbl_805DCA24);
}

s32 get_help_value__15TWindowHelpItemFv(void) {
    struct VObj_80243464 *o;

    s32 id = ((s32 (*)(void))get_palette_consumable_count)();
    if (id == -1) {
        return 0;
    }
    o = (struct VObj_80243464 *)find_item_by_id(id);
    if (o == NULL) {
        return 0;
    }
    return o->m34();
}

s32 get_palette_consumable_count(u16 slot, s32 client_id) {
    void *player = get_player_by_client_id(client_id);
    if (player == NULL) {
        return -1;
    }
    if (slot >= 13) {
        if (clamp_char_at__10TObjPlayerFl((u32)player + 0x7C4, slot - 13) > 0) {
            return slot;
        }
        return -1;
    }
    const PaletteItemKind *kind = &lbl_8044E5E8[slot];
    return fn_801B7CEC(player, 3, kind->group, kind->index);
}
#pragma push
#pragma fp_contract on
void update_palette_item_count_label(TWindowHelpItem *window_help_item, u8 *arg1, u16 arg2, u16 arg3, s32 arg4) {
    s32 v;
    u32 p;
    if (arg2 != 4) {
        window_help_item->set_flag0_bit2();
        return;
    }
    if (arg3 >= 0xD) {
        p = (u32)get_player_by_client_id(arg4);
        if (p == 0) {
            v = 0;
        } else {
            v = clamp_char_at__10TObjPlayerFl(p + 0x7C4, arg3 - 0xD);
        }
    } else {
        v = ((s32 (*)(u16, s32))get_help_value__15TWindowHelpItemFv)(arg3, arg4);
    }
    if (v <= 0) {
        window_help_item->set_flag0_bit2();
        return;
    }
    ((TWindowSubStatusDisp *)window_help_item)->clear_visible_flag();
    *(s32 *)((s8 *)window_help_item + 0x1C) = *(s32 *)((s8 *)arg1 + 0x2C);
    *(s32 *)((s8 *)window_help_item + 0x20) = v;
    draw_right_aligned_number(window_help_item);
    window_help_item->m_8 = lbl_805DCA2C * *(f32 *)((s8 *)window_help_item + 0x10) + (*(f32 *)((s8 *)arg1 + 8) - lbl_805DCA28);
    *(f32 *)((s8 *)window_help_item + 0xC) = *(f32 *)((s8 *)arg1 + 0xC) - lbl_805DCA30;
}
#pragma pop

#define TB(x) (x)
UV_80243630 action_palette_icon_uv_tables[19] = {
    {50.0f, 0.0f}, {50.0f, 43.0f}, {50.0f, 86.0f}, {100.0f, 0.0f},
    {100.0f, 43.0f}, {100.0f, 86.0f}, {0.0f, 0.0f}, {0.0f, 43.0f},
    {0.0f, 86.0f}, {200.0f, 0.0f}, {0.0f, 129.0f}, {50.0f, 172.0f},
    {0.0f, 172.0f}, {50.0f, 129.0f}, {200.0f, 86.0f}, {150.0f, 0.0f},
    {150.0f, 86.0f}, {150.0f, 43.0f}, {200.0f, 43.0f},
};
UV_80243630 lbl_804CDD40[17] = {
    {0.0f, 0.0f}, {0.0f, 43.0f}, {0.0f, 86.0f}, {50.0f, 0.0f},
    {50.0f, 43.0f}, {50.0f, 86.0f}, {100.0f, 0.0f}, {50.0f, 129.0f},
    {100.0f, 43.0f}, {0.0f, 172.0f}, {0.0f, 129.0f}, {150.0f, 43.0f},
    {50.0f, 172.0f}, {0.0f, 129.0f}, {0.0f, 0.0f}, {0.0f, 86.0f},
    {0.0f, 43.0f},
};
UV_80243630 lbl_804CDDC8[6] = {
    {200.0f, 172.0f}, {150.0f, 129.0f}, {150.0f, 172.0f}, {200.0f, 129.0f},
    {100.0f, 172.0f}, {100.0f, 129.0f},
};
UV_80243630 lbl_804CDDF8[3] = {
    {200.0f, 43.0f}, {200.0f, 0.0f}, {200.0f, 86.0f},
};
UV_80243630 lbl_804CDE10[8] = {
    {0.0f, 0.0f}, {100.0f, 129.0f}, {100.0f, 172.0f}, {200.0f, 129.0f},
    {200.0f, 172.0f}, {100.0f, 86.0f}, {100.0f, 86.0f}, {50.0f, 0.0f},
};
void draw_action_palette_icon(Icon_80243630 *icon, u16 group, u16 index) {
    UV_80243630 *row;
    switch (group) {
    case 0:
        icon->kind = 4;
        icon->u0 = lbl_805DCA34;
        icon->v0 = lbl_805DCA38;
        break;
    case 2:
        icon->kind = 4;
        row = TB(lbl_804CDDF8);
        icon->u0 = row[index].u;
        icon->v0 = row[index].v;
        break;
    case 3:
        icon->kind = 3;
        row = TB(action_palette_icon_uv_tables);
        icon->u0 = row[index].u;
        icon->v0 = row[index].v;
        break;
    case 4:
        if (index >= 13) {
            icon->kind = 5;
        } else {
            icon->kind = 4;
        }
        row = TB(lbl_804CDD40);
        icon->u0 = row[index].u;
        icon->v0 = row[index].v;
        break;
    case 5:
        icon->kind = 3;
        row = TB(lbl_804CDDC8);
        icon->u0 = row[index].u;
        icon->v0 = row[index].v;
        break;
    case 7:
        if (index >= 7) {
            icon->kind = 5;
        } else {
            icon->kind = 4;
        }
        row = TB(lbl_804CDE10);
        icon->u0 = row[index].u;
        icon->v0 = row[index].v;
        break;
    }
    icon->u1 = lbl_805DCA3C + icon->u0;
    icon->v1 = lbl_805DCA40 + icon->v0;
    icon->u0 = icon->u0 * lbl_805DCA44;
    icon->v0 = icon->v0 * lbl_805DCA44;
    icon->u1 = icon->u1 * lbl_805DCA44;
    icon->v1 = icon->v1 * lbl_805DCA44;
}
