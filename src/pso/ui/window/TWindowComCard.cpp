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
s32 TWindowSubComCard__sub_8007B070(s32);
extern s32 local_client_id;
void TWindowComCard__sub_80249920(saddr arg0, s32 arg1, s32 arg2);
s8 TWindowComCard__sub_80249C18(void* p);
s8 TWindowComCard__sub_80249C20(void* p);
}

ComCardLayout com_card_layout_entries = {
    6, 1,
    {
        {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
        {3, {198.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
        {3, {0.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
        {3, {0.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
        {3, {0.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0x40, NULL},
        {3, {0.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    },
};

WindowDescriptor com_card_window_descriptor = {
    {206.0f, 180.0f}, 50100.0f, &com_card_layout_entries, 0x23,
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

// The text set of the com card display: its six text entries (name, card id, class, status, stat, keyboard).
struct ComCardText { u16 flags; u8 pad2[6]; f32 x; u8 padC[4]; f32 w; };

struct ComCardTextSet { void *t0; ComCardText *t4; void *t8; void *tC; void *t10; void *t14; };

struct ComCardDisplay { u8 pad[4]; ComCardTextSet *set; };
extern "C" void update_com_card_display(ComCardDisplay *display, void *data);

extern "C" {
s8 TWindowSubComCard__sub_8007B6EC(void *);
s32 TWindowSubComCard__sub_8007B6F4(void *);
}

extern u8 *text_language_group_table;


void*TWindowComCard::get_card_name_ptr() { return (char*)this + 0xa; }

void TWindowComCard::set_help_mode(s32 help_mode) {
    const ComCardHelpRect *temp_r4;

    if (help_mode == 0xE) {
        *(u16 *)&this->m_name = (u16) (*(u16 *)&this->m_name | 2);
        return;
    }
    *(u16 *)&this->m_name = (u16) (*(u16 *)&this->m_name & 0xFFFFFFFD);
    if (help_mode < 0xA) {
        reinterpret_cast<WindowSpritePart *>(this)->kind = 1;
    } else {
        reinterpret_cast<WindowSpritePart *>(this)->kind = 2;
    }
    temp_r4 = &com_card_help_panel_rect_table[help_mode];
    set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(this), temp_r4->x, temp_r4->y);
}

s32 get_class_name_text(s32 class_index) {
    return *(s32 *)((s8 *)(*(saddr *)((s8 *)text_language_group_table + 0x1C)) + (class_index * 4));
}

extern "C" s8 TWindowComCard__sub_80249C20(void* p) { return *(s8*)((char*)p + 0x8d); }

extern "C" s8 TWindowComCard__sub_80249C18(void* p) { return *(s8*)((char*)p + 0x8e); }

void*TWindowComCard::get_kbd_ptr() { return (char*)this + 0x20; }

TWindowComCard::TWindowComCard(void *position, void *data)
    : TWindowBase((u8 *)&com_card_window_descriptor, 4, (u8 *)position) {
    m_name = TWindowComCard__class_name;
    update_com_card_display((ComCardDisplay *)&entry_list, data);
}

TWindowComCard::~TWindowComCard() {}

void TWindowComCard::run_task() {
    ((TWindowDD *)this)->initialize_subwindow();
    update_fade();
    update_window_entry_list(&entry_list);
}

void TWindowComCard::render() {
    WindowDrawContext *context = draw_default_entry();
    draw_window_frame(context);
    draw_visible_window_entries(this, &entry_list, context);
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
    void *entry = TWindowSubComCard::get_card_entry(static_cast<s32>(reinterpret_cast<saddr>(index)));
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

void TWindowComCard::set_display_value(s32 card_index, s32 cards) {
    saddr arg0 = (saddr)this;
    saddr temp = cards + (card_index << 8);
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
