// Emit the follower vtable before the status-icon jump table.
#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/window/TWindowSubStatusDisp_8025B050.h"
#include "types.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/player/GuildCardEntry.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_8026CB5C.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowTradeRequest.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowComCard.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowComCardFollower.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/object/TObjLuker.h"


extern "C" {
void render__14TWindowComCardFv(saddr arg0);
s32 TWindowSubComCard__sub_8007B070(s32);
extern s32 local_client_id;
void TWindowComCard__sub_80249920(saddr arg0, s32 arg1, s32 arg2);
s8 TWindowComCard__sub_80249C18(void* p);
s8 TWindowComCard__sub_80249C20(void* p);
void *__dt__14TWindowComCardFv(void *arg0, s16 arg1);
void run_task__14TWindowComCardFv(void* p);
int initialize_subwindow__9TWindowDDFv(void*);

extern "C" u8 lbl_805D63F0[];
extern "C" void render_shadows__7TObjectFv();
extern void *lbl_804CE820[44];
extern void *lbl_804CE918[14];
void *lbl_804CE820[44] = {
    (void *)0x6, (void *)0x1, (void *)0x3, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)0x40,
    (void *)0x0, (void *)0x3, (void *)0x43460000, (void *)0x41a00000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x40, (void *)0x0,
    (void *)0x3, (void *)0x0, (void *)0x42200000, (void *)0x3f000000,
    (void *)0xffffffff, (void *)0x40, (void *)0x0, (void *)0x3,
    (void *)0x0, (void *)0x42700000, (void *)0x3f000000, (void *)0xffffffff,
    (void *)0x40, (void *)0x0, (void *)0x3, (void *)0x0,
    (void *)0x42a00000, (void *)0x3f000000, (void *)0xffffffff, (void *)0x40,
    (void *)0x0, (void *)0x3, (void *)0x0, (void *)0x42c80000,
    (void *)0x3f000000, (void *)0xffffffff, (void *)0x0, (void *)0x0,
};
void *TWindowComCard__window_desc[5] = {
    (void *)0x434e0000, (void *)0x43340000, (void *)0x4743b400, (void *)&lbl_804CE820,
    (void *)0x23,
};
const char *TWindowComCard__class_name = "TWindowComCard";
void *com_card_status_text_table[6] = {
    (void *)"Jpn.", (void *)"Eng.", (void *)"Ger.", (void *)"Fr.",
    (void *)"Span.", (void *)"??????",
};
struct ComCardHelpRect { f32 x, y; };
const ComCardHelpRect com_card_help_panel_rect_table[14] = {
    {0.0f, 180.0f}, {32.0f, 180.0f}, {64.0f, 180.0f}, {96.0f, 180.0f}, {128.0f, 180.0f},
    {0.0f, 208.0f}, {32.0f, 208.0f}, {64.0f, 208.0f}, {96.0f, 208.0f}, {128.0f, 208.0f},
    {72.0f, 167.0f}, {104.0f, 167.0f}, {136.0f, 167.0f}, {168.0f, 167.0f},
};
void *__vt__14TWindowComCard[7] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__14TWindowComCardFv, (void *)&run_task__14TWindowComCardFv,
    (void *)&render__14TWindowComCardFv, (void *)&render_shadows__7TObjectFv, (void *)0x0,
};
void *lbl_804CE918[14] = {
    (void *)0x1, (void *)0x1, (void *)0x6, (void *)0x0,
    (void *)0x0, (void *)0x42000000, (void *)0x41e00000, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)&lbl_805D63F0,
    (void *)0x1, (void *)0x4,
};
void *TWindowComCard__window_desc_b[5] = {
    (void *)0x42000000, (void *)0x41e00000, (void *)0x4788d100, (void *)&lbl_804CE918,
    (void *)0x82b,
};
#define __vt__14TWindowComCard ((s32 *)__vt__14TWindowComCard)
}

// The text set of the com card display: its six text entries (name, card id, class, status, stat, keyboard).
struct ComCardText { u16 flags; u8 pad2[6]; f32 x; u8 padC[4]; f32 w; };

struct ComCardTextSet { void *t0; ComCardText *t4; void *t8; void *tC; void *t10; void *t14; };

struct ComCardDisplay { u8 pad[4]; ComCardTextSet *set; };
extern "C" void update_com_card_display(ComCardDisplay *display, void *data);

extern "C" {
s8 TWindowSubComCard__sub_8007B6EC(void *);
s32 TWindowSubComCard__sub_8007B6F4(void *);
}
s32 get_class_name_text(s32 arg0);

extern u8 *text_language_group_table;

TWindowCtrl *TWindowCtrl::instance;
u16 lbl_805D63FC;

extern "C" void request_active_window_close(void) {
    if ((TWindowCtrl::instance != NULL) && (TWindowCtrl::instance->m_38 != 0U)) {
        ((TWindowCtrl *)((void*)TWindowCtrl::instance->m_38))->set_flag1e_bit8();
    }
}

void TWindowTradeRequest::close_request_window() {
    lbl_805D63FC &= 0xFFFFFFF7;
    TWindowCtrl *controller = reinterpret_cast<TWindowCtrl *>(TWindowCtrl::instance);
    if (controller != NULL) {
        TWindowTradeRequest *request = controller->trade_request;
        if (request != NULL) {
            request->queue_destruction();
            reinterpret_cast<TWindowCtrl *>(TWindowCtrl::instance)->trade_request = NULL;
        }
    }
}

#pragma push
#pragma fp_contract on
TWindowComCardFollower::TWindowComCardFollower(TWindowBase *parent, NJS_POINT2 *ofs, s32 col, s32 mode, s32 client)
    : TWindowBase((u8 *)TWindowComCard__window_desc_b, (s16)client, (u8 *)get_zero_vec2()) {
    m_60 = parent;
    offset.x = ofs->x;
    offset.y = ofs->y;
    m_6c = col;
    m_70 = mode;
    target_position[0] = 16.0f * (f32)m_6c + (m_60->frame_position[0] + offset.x);
    target_position[1] = m_60->frame_position[1] + offset.y;
    save_position();
    ((TWindowComCard *)get_array_entry(0))->set_help_mode(mode);
}
#pragma pop

TWindowComCardFollower::~TWindowComCardFollower() {}

void TWindowComCardFollower::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    u8 *temp_r4;
    temp_r4 = (unsigned char *) (this->m_60);
    temp_f1 = m_60->frame_position[1];
    this->target_position[1] = (f32) (temp_f1 + offset.y);
    this->frame_position[1] = (f32) this->target_position[1];
    ((s32 (*)(void *, int, f32))initialize_subwindow__9TWindowDDFv)((void *)arg0, (saddr)temp_r4, (f32)temp_f1);
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>(arg0 + 0x24));
}

void TWindowComCardFollower::render() {
    WindowDrawContext *context = draw_default_entry();
    draw_visible_window_entries(this, &entry_list, context);
}

#pragma push
#pragma fp_contract on
void TWindowComCardFollower::set_column(s32 column) {
    if (m_6c != column) {
        m_6c = column;
        target_position[0] = 16.0f * (f32)m_6c + (m_60->frame_position[0] + offset.x);
        tween_ticks = 0xF;
    }
}
#pragma pop

void TWindowComCardFollower::set_selected_index(s32 value) {
    if (m_70 != value) {
        m_70 = value;
        ((TWindowComCard *)get_array_entry(0))->set_help_mode(m_70);
    }
}

s32 get_status_effect_icon_index(u32 arg0) {
    switch (arg0) {
    case 3:
        return 1;
    case 9:
        return 6;
    case 10:
        return 8;
    case 11:
        return 7;
    case 12:
        return 9;
    case 15:
        return 3;
    case 16:
        return 4;
    case 17:
        return 5;
    case 18:
        return 0;
    case 2:
        return 2;
    default:
        return 0xE;
    }
}

void*TWindowComCard::get_card_name_ptr() { return (char*)this + 0xa; }

void TWindowComCard::set_help_mode(s32 arg1) {
    const ComCardHelpRect *temp_r4;

    if (arg1 == 0xE) {
        *(u16 *)&this->m_name = (u16) (*(u16 *)&this->m_name | 2);
        return;
    }
    *(u16 *)&this->m_name = (u16) (*(u16 *)&this->m_name & 0xFFFFFFFD);
    if (arg1 < 0xA) {
        reinterpret_cast<WindowSpritePart *>(this)->kind = 1;
    } else {
        reinterpret_cast<WindowSpritePart *>(this)->kind = 2;
    }
    temp_r4 = &com_card_help_panel_rect_table[arg1];
    set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(this), temp_r4->x, temp_r4->y);
}

s32 get_class_name_text(s32 arg0) {
    return *(s32 *)((s8 *)(*(saddr *)((s8 *)text_language_group_table + 0x1C)) + (arg0 * 4));
}

extern "C" s8 TWindowComCard__sub_80249C20(void* p) { return *(s8*)((char*)p + 0x8d); }

extern "C" s8 TWindowComCard__sub_80249C18(void* p) { return *(s8*)((char*)p + 0x8e); }

void*TWindowComCard::get_kbd_ptr() { return (char*)this + 0x20; }

TWindowComCard::TWindowComCard(void *position, void *data)
    : TWindowBase((u8 *)&TWindowComCard__window_desc, 4, (u8 *)position) {
    m_name = TWindowComCard__class_name;
    update_com_card_display((ComCardDisplay *)&entry_list, data);
}

extern "C" void *__dt__14TWindowComCardFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TWindowComCard;
        __dt__11TWindowBaseFv(arg0, 0);
        if (arg1 > 0) {
            TObject::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" void run_task__14TWindowComCardFv(void* p) { ((TWindowDD *)p)->initialize_subwindow(); ((TWindowBase *)p)->update_fade(); ((TWindowBase *)p)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((char*)p + 0x24)); }

extern "C" void render__14TWindowComCardFv(saddr arg0) {
    saddr temp_r3;
    temp_r3 = reinterpret_cast<saddr>(reinterpret_cast<TWindowBase *>(arg0)->draw_default_entry());
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(
        reinterpret_cast<const void *>(arg0),
        reinterpret_cast<const WindowLayoutEntries *>((void *)(arg0 + 0x24)),
        reinterpret_cast<WindowDrawContext *>(temp_r3));
}

s32 TWindowSubComCard::create_com_card_window(s32 position) {
    saddr keyboard_mode = TWindowSubComCard::get_keyboard_mode();
    if (keyboard_mode == 0) {
        return 0;
    }
    if (TWindowSubComCard__sub_8007B070(keyboard_mode) != 0) {
        ((TWindowSubComCard *)keyboard_mode)->clear_and_init((void *)(saddr)local_client_id);
    }
    return (s32)new TWindowComCard((void *)position, (void *)keyboard_mode);
}

void *TWindowComCard::create(void *position, void *index) {
    void *entry = get_card_entry__17TWindowSubComCardFi(static_cast<s32>(reinterpret_cast<saddr>(index)));
    if (entry == NULL) {
        return NULL;
    }
    return new TWindowComCard(position, entry);
}

u8 *TWindowComCard::create_for_card(s32 position, s32 index, s32 records) {
    if (index < 0) {
        return NULL;
    }
    s32 data = records + index * 0x90;
    return (u8 *)new TWindowComCard((void *)position, (void *)data);
}

void TWindowComCard::set_display_value(s32 arg1, s32 arg2) {
    saddr arg0 = (saddr)this;
    saddr temp = arg2 + (arg1 << 8);
    if (temp != 0) {
        update_com_card_display((ComCardDisplay *)(arg0 + 0x24), (void *)temp);
    }
}

extern "C" void TWindowComCard__sub_80249920(saddr arg0, s32 arg1, s32 arg2) {
    saddr temp = arg2 + (arg1 * 0x90);
    if (temp != 0) {
        update_com_card_display((ComCardDisplay *)(arg0 + 0x24), (void *)temp);
    }
}

extern "C" void update_com_card_display(ComCardDisplay *arg0, void *arg1) {
    ComCardText *t4;
    void *t14;
    void *t0;
    void *tC;
    void *t8;
    void *t10;
    ComCardTextSet *s;
    s32 n;
    s32 id;
    s = arg0->set;
    t0 = s->t0;
    tC = s->tC;
    t8 = s->t8;
    t10 = s->t10;
    t4 = s->t4;
    t14 = s->t14;
    set_text_entry_string((u8 *)t0, (uaddr)reinterpret_cast<GuildCardEntry *>(arg1)->get_name(), 0x220);
    n = TWindowComCard__sub_80249C20(arg1);
    if (n > 5) {
        n = 5;
    }
    TWindowDuelResult::set_default_status(tC, (saddr)com_card_status_text_table[n]);
    n = TWindowSubComCard__sub_8007B6EC(arg1);
    if (n > 0xC) {
        n = 0xC;
    }
    TWindowDuelResult::set_default_status(t8, get_class_name_text(n));
    n = TWindowComCard__sub_80249C18(arg1);
    if (n > 0xA) {
        n = 0xA;
    }
    TWindowDuelResult::set_default_status(t10, reinterpret_cast<saddr>(TObjLuker::get_stat_table_entry(n)));
    if (TWindowSubComCard__sub_8007B6F4(arg1) != 0) {
        id = reinterpret_cast<const GuildCardEntry *>(arg1)->get_card_id();
        if (id == 0) {
            t4->flags |= 2;
        } else {
            text_builder_reset();
            text_builder_append_int(id);
            set_text_entry_string((u8 *)t4, (uaddr)((void *)get_shared_text_buffer()), 0x20);
            measure_message_text_width_default(t4);
            t4->x = 198.0f - t4->w;
            t4->flags &= ~2;
        }
    } else {
        t4->flags |= 2;
    }
    set_text_entry_string((u8 *)t14, (uaddr)((void *)((TWindowComCard *)arg1)->get_kbd_ptr()), 0x220);
}
