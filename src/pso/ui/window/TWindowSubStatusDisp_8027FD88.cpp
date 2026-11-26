#include "pso/unk/WindowLayoutRecord.h"
#include "pso/unk/TWindowLayoutNumber.h"
#include "pso/player/TPlyDispData.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/PageIndicator.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80071774.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/enemy/dimedian/TObjEneDimedian.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/object/base/TObjChara.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/object/TObjLuker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/unk/text_8026C664.h"
#include "pso/player/PlayerRequirementStats.h"

const char *TWindowSubStatusDisp::class_name = "TWindowSubStatusDisp";

SummaryPageLayout TWindowSubStatusDisp::summary_page_layout = {
    18, 1,
    {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {210.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, "Lv"},
    {4, {269.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, 1},
    {3, {0.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {0.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {7, {271.0f, 20.0f}, {32.0f, 32.0f}, 0.0f, 0.0f, 1.0f, 1.0f, 0.5f, 0xFFFFFFFF, NULL, 0, 4},
    {3, {0.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {128.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {231.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {231.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, "pt"},
    {3, {0.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {128.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {231.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {231.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, "pt"},
    {3, {0.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {128.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {231.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {231.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
};

StatPageLayout TWindowSubStatusDisp::stat_page_layout = {
    36, 1,
    {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {56.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {113.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {115.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, "("},
    {4, {171.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {171.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, ")"},
    {3, {0.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {56.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {113.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {115.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, "("},
    {4, {171.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {171.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, ")"},
    {3, {0.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {56.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {113.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {115.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, "("},
    {4, {171.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {171.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, ")"},
    {3, {0.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {56.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {113.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {115.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, "("},
    {4, {171.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {171.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, ")"},
    {3, {0.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {56.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {113.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {115.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, "("},
    {4, {171.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {171.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, ")"},
    {3, {0.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {56.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {113.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {115.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, "("},
    {4, {171.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {171.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, ")"},
};

ResistanceLayout TWindowSubStatusDisp::resistance_layout = {
    30, 1,
    {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {56.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {113.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {115.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, "("},
    {4, {171.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {171.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, ")"},
    {3, {0.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {56.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {113.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {115.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, "("},
    {4, {171.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {171.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, ")"},
    {3, {0.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {56.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {113.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {115.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, "("},
    {4, {171.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {171.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, ")"},
    {3, {0.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {56.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {113.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {115.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, "("},
    {4, {171.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {171.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, ")"},
    {3, {0.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {56.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {113.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {115.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, "("},
    {4, {171.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {171.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, ")"},
};

RecordSummaryLayout TWindowSubStatusDisp::record_summary_layout = {
    16, 1,
    {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {0.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {56.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {138.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {0.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {56.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {138.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {0.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {56.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {138.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {0.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {56.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {138.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
    {3, {0.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {134.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, ":"},
    {4, {216.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 0, 0},
};

RankTimeRecordsLayout TWindowSubStatusDisp::rank_time_records_layout = {
    16, 1,
    {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {0.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {106.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 2, ":"},
    {3, {116.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {0.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {106.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 2, ":"},
    {3, {116.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {0.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {106.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 2, ":"},
    {3, {116.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {0.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {106.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 2, ":"},
    {3, {116.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {0.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {106.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 2, ":"},
    {3, {116.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
};

NumberedTimesLayout TWindowSubStatusDisp::numbered_times_layout = {
    10, 1,
    {3, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {0.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {0.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {0.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {0.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {0.0f, 100.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {160.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {160.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {160.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
    {3, {160.0f, 80.0f}, 0.5f, 0xFFFFFFFF, 2, NULL},
};

void *TWindowSubStatusDisp::window_layout[5] = {
    (void *)0x439c0000, (void *)0x43200000, (void *)0x47438200, (void *)0x0,
    (void *)0x3,
};

extern "C" {
s32 is_battle_mode_running();
}
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
extern "C" {
const s32 status_disp_vt5_message_ids[4] = {0x91, 0x92, 0x91, 0x92};
}

#include "types.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/TWindowComCard.h"
#include "pso/unk/TLobby_8001D6A0.h"


// list type of page_indicator per page: the page-flip list kind passed to fn_8026C7AC
const u8 status_page_list_kinds[4] = {3, 4, 4, 0};

TWindowSubStatusDisp::TWindowSubStatusDisp(s32 client)
    : TWindowBase((u8 *)TWindowSubStatusDisp::window_layout, client, (u8 *)get_window_layout_position(0x19)) {
    m_name = TWindowSubStatusDisp::class_name;
    client_index = client;
    page = 0;
    requested_page = page;
    scale_x = 1.0f;
    scale_y = 1.0f;
    page_indicator = new PageIndicator(0, 3, client);
    dispatch_page_init();
}

TWindowSubStatusDisp::~TWindowSubStatusDisp() {
    delete_if_allocated(page_indicator, 1);
}

void TWindowSubStatusDisp::run_task() {
  if (!((this->window_flags) & 2))
  {
    this->open_tick = 0x01000000;
  }
  if ((handle_list_page_flip_input(this->page_indicator) != 0) || ((this->page) != (this->requested_page)))
  {
    if ((this->page) != (this->requested_page))
    {
      this->page = this->requested_page;
      fn_8026C7AC(this->page_indicator, status_page_list_kinds[this->page]);
    }
    this->entry_list.destroy_all_items();
    this->dispatch_page_init();
  }
  this->dispatch_page_update();
  update_window();
  this->update_window_entry_list(&this->entry_list);
}

void TWindowSubStatusDisp::render() {
    WindowDrawContext *context;

    if (get_player_by_client_id(this->client_index) != 0U) {
        context = this->setup_window_draw_context(&this->scale_x);
        draw_window_frame(context);
        draw_visible_window_entries(
            this,
            &this->entry_list,
            context);
        draw_list_page_indicator(page_indicator, context);
    }
}

void TWindowSubStatusDisp::dispatch_page_init() {
    static void (TWindowSubStatusDisp::*page0[3])() = {
        &TWindowSubStatusDisp::vt0, &TWindowSubStatusDisp::vt1, &TWindowSubStatusDisp::vt2,
    };
    static void (TWindowSubStatusDisp::*page1[4])() = {
        &TWindowSubStatusDisp::vt3, &TWindowSubStatusDisp::vt4, &TWindowSubStatusDisp::vt5,
        &TWindowSubStatusDisp::vt5,
    };
    static void (TWindowSubStatusDisp::*page2[4])() = {
        &TWindowSubStatusDisp::vt7, &TWindowSubStatusDisp::vt4, &TWindowSubStatusDisp::vt5,
        &TWindowSubStatusDisp::vt5,
    };

    switch (page) {
    case 0:
        (this->*page0[page_indicator->get_type()])();
        break;
    case 1:
        (this->*page1[page_indicator->get_type()])();
        break;
    case 2:
        (this->*page2[page_indicator->get_type()])();
        break;
    }
}

void TWindowSubStatusDisp::dispatch_page_update() {
    static void (TWindowSubStatusDisp::*page0[3])() = {
        &TWindowSubStatusDisp::vt11, &TWindowSubStatusDisp::vt12, &TWindowSubStatusDisp::vt13,
    };
    static void (TWindowSubStatusDisp::*page1[4])() = {
        &TWindowSubStatusDisp::vt14, &TWindowSubStatusDisp::vt15, &TWindowSubStatusDisp::vt16,
        &TWindowSubStatusDisp::vt16,
    };
    static void (TWindowSubStatusDisp::*page2[4])() = {
        &TWindowSubStatusDisp::vt18, &TWindowSubStatusDisp::vt15, &TWindowSubStatusDisp::vt16,
        &TWindowSubStatusDisp::vt16,
    };

    switch (page) {
    case 0:
        (this->*page0[page_indicator->get_type()])();
        break;
    case 1:
        (this->*page1[page_indicator->get_type()])();
        break;
    case 2:
        (this->*page2[page_indicator->get_type()])();
        break;
    }
}
extern "C" {
void TWindowSubStatusDisp::vt0() {
    WindowTextEntry *e;
    WindowSpritePart *portrait;
    TObjPlayer *pl;
    const char *v;
    CharacterAppearanceFields *st;
    if ((f32) this->open_tick > 7.5f) {
        this->open_tick = 7;
    }
    init_window_layout_entries(
        &this->entry_list,
        &TWindowSubStatusDisp::summary_page_layout,
        this->client_index);
    e = (WindowTextEntry *)get_array_entry(6);
    set_text_entry_string(e, TWindowSubStatusDisp::get_message_10(0x80), 0x20);
    e = (WindowTextEntry *)get_array_entry(0xA);
    set_text_entry_string(e, TWindowSubStatusDisp::get_message_10(0x81), 0x20);
    e = (WindowTextEntry *)get_array_entry(0xE);
    set_text_entry_string(e, TWindowSubStatusDisp::get_message_10(0x82), 0x20);
    e = (WindowTextEntry *)get_array_entry(0x11);
    set_text_entry_string(e, TWindowSubStatusDisp::get_meseta_unit(), 0x20);
    pl = get_player_by_client_id(this->client_index);
    if (pl != NULL) {
        st = (CharacterAppearanceFields *)pl->name;
        if (st != NULL) {
            v = pl->get_name();
            set_text_entry_string((WindowTextEntry *)((void *)get_array_entry(0)), v, 0x20);
            v = get_class_name_text(st->classId);
            set_text_entry_string((WindowTextEntry *)((void *)get_array_entry(3)), v, 0);
            v = TObjLuker::get_stat_table_entry(st->section);
            set_text_entry_string((WindowTextEntry *)((void *)get_array_entry(4)), v, 0);
        }
        portrait = (WindowSpritePart *)get_array_entry(5);
        portrait->texture_list_slot = &this->body_textures;
        this->body_textures = &pl->body_textures;
    }
}

void TWindowSubStatusDisp::vt11() {
    TObjPlayer *p;
    player_stats *q;
    TWindowLayoutNumber *e;
    p = get_player_by_client_id(client_index);
    if (p != NULL) {
        q = p->get_stats();
        if (q != NULL) {
            e = static_cast<TWindowLayoutNumber *>(get_array_entry(2));
            e->value = p->get_actor_level_index() + 1;
            e = static_cast<TWindowLayoutNumber *>(get_array_entry(0x10));
            e->value = q->meseta;
            e = static_cast<TWindowLayoutNumber *>(get_array_entry(8));
            e->value = q->exp;
            e = static_cast<TWindowLayoutNumber *>(get_array_entry(0xC));
            e->value = p->get_next_level_exp() - q->exp;
        }
    }
}

void TWindowSubStatusDisp::vt1() {
    WindowTextEntry *e;
    if ((f32) this->open_tick > 7.5f) {
        this->open_tick = 7;
    }
    init_window_layout_entries(
        &this->entry_list,
        &TWindowSubStatusDisp::stat_page_layout,
        this->client_index);
    e = (WindowTextEntry *)get_array_entry(0);
    set_text_entry_string(e, TWindowSubStatusDisp::get_message_10(0x83), 0x20);
    e = (WindowTextEntry *)get_array_entry(6);
    set_text_entry_string(e, TWindowSubStatusDisp::get_message_10(0x84), 0x20);
    e = (WindowTextEntry *)get_array_entry(0xC);
    set_text_entry_string(e, TWindowSubStatusDisp::get_message_10(0x85), 0x20);
    e = (WindowTextEntry *)get_array_entry(0x12);
    set_text_entry_string(e, TWindowSubStatusDisp::get_message_10(0x86), 0x20);
    e = (WindowTextEntry *)get_array_entry(0x18);
    set_text_entry_string(e, TWindowSubStatusDisp::get_message_10(0x87), 0x20);
    e = (WindowTextEntry *)get_array_entry(0x1E);
    set_text_entry_string(e, TWindowSubStatusDisp::get_message_10(0x88), 0x20);
}

void TWindowSubStatusDisp::vt12() {
    PlayerRequirementStats cur;
    PlayerRequirementStats req;
    TWindowLayoutNumber *e2;
    TObjPlayer *pl;
    TWindowLayoutNumber *e;
    player_stats *q;
    cur.clear_fields();
    req.clear_fields();
    pl = get_player_by_client_id(this->client_index);
    if (pl != NULL) {
        e2 = (TWindowLayoutNumber *)get_array_entry(2);
        e2->value = pl->get_atp_range() + (pl->get_atp() + pl->get_actor_attack_params_atp_min());
        e = (TWindowLayoutNumber *)get_array_entry(8);
        e->value = pl->get_dfp();
        e = (TWindowLayoutNumber *)get_array_entry(0x14);
        e->value = pl->get_ata();
        e = (TWindowLayoutNumber *)get_array_entry(0x1A);
        e->value = pl->get_evp();
        q = pl->get_stats();
        if (q != NULL) {
            e = (TWindowLayoutNumber *)get_array_entry(0xE);
            e->value = q->stats.mst;
            e = (TWindowLayoutNumber *)get_array_entry(0x20);
            e->value = q->stats.lck;
        }
    }
    if (build_player_equipment_requirement_stats(pl, &cur) != 0) {
        build_player_class_stat_template(pl, &req);
#define ROW(idx, k) \
        e = (TWindowLayoutNumber *)get_array_entry(idx); \
        e->value = cur.k; \
        if (req.k <= cur.k) { e->color = -0x100; } else { e->color = -1; }
        ROW(4, atp)
        ROW(0xA, dfp)
        ROW(0x16, ata)
        ROW(0x1C, evp)
        ROW(0x10, mst)
        ROW(0x22, lck)
#undef ROW
    }
}
void TWindowSubStatusDisp::vt2() {
    WindowTextEntry *entry;
    if ((f32) this->open_tick > 7.5f) {
        this->open_tick = 7;
    }
    init_window_layout_entries(
        &this->entry_list,
        &TWindowSubStatusDisp::resistance_layout,
        this->client_index);
    entry = (WindowTextEntry *)get_array_entry(0);
    set_text_entry_string(entry, TWindowSubStatusDisp::get_message_10(0x89), 0x20);
    entry = (WindowTextEntry *)get_array_entry(6);
    set_text_entry_string(entry, TWindowSubStatusDisp::get_message_10(0x8A), 0x20);
    entry = (WindowTextEntry *)get_array_entry(0xC);
    set_text_entry_string(entry, TWindowSubStatusDisp::get_message_10(0x8B), 0x20);
    entry = (WindowTextEntry *)get_array_entry(0x12);
    set_text_entry_string(entry, TWindowSubStatusDisp::get_message_10(0x8C), 0x20);
    entry = (WindowTextEntry *)get_array_entry(0x18);
    set_text_entry_string(entry, TWindowSubStatusDisp::get_message_10(0x8D), 0x20);
}

void TWindowSubStatusDisp::vt13() {
    TObjPlayer *player;
    TWindowLayoutNumber *entry_2;
    TWindowLayoutNumber *entry_8;
    TWindowLayoutNumber *entry_e;
    TWindowLayoutNumber *entry_14;
    TWindowLayoutNumber *entry_1a;

    player = get_player_by_client_id(this->client_index);
    if (player != NULL) {
        entry_2 = static_cast<TWindowLayoutNumber *>(this->get_array_entry(2));
        entry_2->value = (s32) player->get_efr();
        entry_8 = static_cast<TWindowLayoutNumber *>(this->get_array_entry(8));
        entry_8->value = (s32) player->get_eic();
        entry_e = static_cast<TWindowLayoutNumber *>(this->get_array_entry(0xE));
        entry_e->value = (s32) player->get_eth();
        entry_14 = static_cast<TWindowLayoutNumber *>(this->get_array_entry(0x14));
        entry_14->value = (s32) player->get_edk();
        entry_1a = static_cast<TWindowLayoutNumber *>(this->get_array_entry(0x1A));
        entry_1a->value = (s32) player->get_elt();
    }
}

void TWindowSubStatusDisp::vt3() {
    s32 card_flag;
    WindowTextEntry *label;
    TWindowLayoutNumber *number;
    if ((f32) this->open_tick > 7.5f) {
        this->open_tick = 7;
    }
    init_window_layout_entries(
        &this->entry_list,
        &TWindowSubStatusDisp::record_summary_layout,
        this->client_index);
    label = (WindowTextEntry *)get_array_entry(0);
    set_text_entry_string(label, TWindowSubStatusDisp::get_message_10(0x8E), 0);
    label = (WindowTextEntry *)get_array_entry(1);
    set_text_entry_string(label, get_localized_text_entry(0x10, 6), 0);
    label = (WindowTextEntry *)get_array_entry(4);
    set_text_entry_string(label, get_localized_text_entry(0x10, 7), 0);
    label = (WindowTextEntry *)get_array_entry(7);
    set_text_entry_string(label, get_localized_text_entry(0x10, 8), 0);
    label = (WindowTextEntry *)get_array_entry(0xA);
    set_text_entry_string(label, get_localized_text_entry(0x10, 9), 0);
    label = (WindowTextEntry *)get_array_entry(0xD);
    set_text_entry_string(label, get_localized_text_entry(0x10, 0xE), 0);
    number = static_cast<TWindowLayoutNumber *>(get_array_entry(3));
    number->value = (s32)TAdSinglePlyChrSelectGC::get_online_first_place_count((u16) this->client_index);
    number = static_cast<TWindowLayoutNumber *>(get_array_entry(6));
    number->value = (s32)TAdSinglePlyChrSelectGC::get_online_second_place_count((u16) this->client_index);
    number = static_cast<TWindowLayoutNumber *>(get_array_entry(9));
    number->value = (s32)TAdSinglePlyChrSelectGC::get_online_third_place_count((u16) this->client_index);
    number = static_cast<TWindowLayoutNumber *>(get_array_entry(0xC));
    number->value = (s32)TAdSinglePlyChrSelectGC::get_online_fourth_place_count((u16) this->client_index);
    card_flag = TAdSinglePlyChrSelectGC::get_online_disconnect_count((u16) this->client_index);
    if (is_battle_mode_running() != 0) {
        card_flag -= 1;
    }
    static_cast<TWindowLayoutNumber *>(get_array_entry(0xF))->value = card_flag;
}

void TWindowSubStatusDisp::vt14() {  }

void TWindowSubStatusDisp::vt7() {
    WindowTextEntry *label;
    TWindowLayoutNumber *number;
    if ((f32) this->open_tick > 7.5f) {
        this->open_tick = 7;
    }
    init_window_layout_entries(
        &this->entry_list,
        &TWindowSubStatusDisp::record_summary_layout,
        this->client_index);
    label = (WindowTextEntry *)get_array_entry(0);
    set_text_entry_string(label, TWindowSubStatusDisp::get_message_10(0x8F), 0);
    label = (WindowTextEntry *)get_array_entry(1);
    set_text_entry_string(label, get_localized_text_entry(0x10, 6), 0);
    label = (WindowTextEntry *)get_array_entry(4);
    set_text_entry_string(label, get_localized_text_entry(0x10, 7), 0);
    label = (WindowTextEntry *)get_array_entry(7);
    set_text_entry_string(label, get_localized_text_entry(0x10, 8), 0);
    label = (WindowTextEntry *)get_array_entry(0xA);
    set_text_entry_string(label, get_localized_text_entry(0x10, 9), 0);
    ((WindowTextEntry *)get_array_entry(0xD))->hide();
    ((WindowTextEntry *)get_array_entry(0xE))->hide();
    number = static_cast<TWindowLayoutNumber *>(get_array_entry(3));
    number->value = (s32)TAdSinglePlyChrSelectGC::get_split_first_place_count((u16) this->client_index);
    number = static_cast<TWindowLayoutNumber *>(get_array_entry(6));
    number->value = (s32)TAdSinglePlyChrSelectGC::get_split_second_place_count((u16) this->client_index);
    number = static_cast<TWindowLayoutNumber *>(get_array_entry(9));
    number->value = (s32)TAdSinglePlyChrSelectGC::get_split_third_place_count((u16) this->client_index);
    number = static_cast<TWindowLayoutNumber *>(get_array_entry(0xC));
    number->value = (s32)TAdSinglePlyChrSelectGC::get_split_fourth_place_count((u16) this->client_index);
    ((TWindowLayoutNumber *)get_array_entry(0xF))->hide();
}

void TWindowSubStatusDisp::vt18() {  }

// rank letters by clear rank
const char *challenge_rank_letters[4] = {"", "B", "A", "S"};

// Best-time records page: page == 2 shows the split-screen record sets.
void TWindowSubStatusDisp::vt4() {
    enum { RecordEntryHidden = 2 };
    if ((f32)(s32)open_tick > 7.5f) {
        open_tick = 7;
    }
    init_window_layout_entries(&entry_list, &TWindowSubStatusDisp::rank_time_records_layout, client_index);
    page_indicator->get_type();
    s32 slot = page == 2 ? RECORD_SET_EP1_SPLIT : RECORD_SET_EP1;
    WindowTextEntry *title = (WindowTextEntry *)get_array_entry(0);
    if (slot == RECORD_SET_EP1) {
        set_text_entry_string(title, TWindowSubStatusDisp::get_message_10(0x90), 0);
    } else {
        set_text_entry_string(title, TWindowSubStatusDisp::get_message_10(0x93), 0);
    }

    title = (WindowTextEntry *)get_array_entry(1);
    WindowTextEntry *spacer = (WindowTextEntry *)get_array_entry(2);
    WindowTextEntry *value = (WindowTextEntry *)get_array_entry(3);
    const char *player_name = (const char *)get_challenge_rank_title(client_index);
    if (slot != RECORD_SET_EP1 || player_name == NULL || *player_name == 0) {
        title->flags |= RecordEntryHidden;
        spacer->flags |= RecordEntryHidden;
        value->flags |= RecordEntryHidden;
    } else {
        title->flags &= ~RecordEntryHidden;
        spacer->flags &= ~RecordEntryHidden;
        value->flags &= ~RecordEntryHidden;
        set_text_entry_string(title, TWindowSubStatusDisp::get_message_10(0x9B), 0);
        set_text_entry_string(value, player_name, 0x20);
        value->color = get_challenge_title_color(client_index);
    }

    title = (WindowTextEntry *)get_array_entry(4);
    spacer = (WindowTextEntry *)get_array_entry(5);
    value = (WindowTextEntry *)get_array_entry(6);
    s32 rank = get_challenge_rank(client_index, slot);
    if (rank == 0) {
        title->flags |= RecordEntryHidden;
        spacer->flags |= RecordEntryHidden;
        value->flags |= RecordEntryHidden;
    } else {
        title->flags &= ~RecordEntryHidden;
        spacer->flags &= ~RecordEntryHidden;
        value->flags &= ~RecordEntryHidden;
        if (slot == RECORD_SET_EP1) {
            set_text_entry_string(title, TWindowSubStatusDisp::get_message_10(0x98), 0);
        } else {
            set_text_entry_string(title, TWindowSubStatusDisp::get_message_10(0x9A), 0);
        }
        set_text_entry_string(value, challenge_rank_letters[rank], 0);
    }

    title = (WindowTextEntry *)get_array_entry(7);
    spacer = (WindowTextEntry *)get_array_entry(8);
    value = (WindowTextEntry *)get_array_entry(9);
    s32 time = get_challenge_set_time(client_index, slot);
    if (time == 0) {
        title->flags |= RecordEntryHidden;
        spacer->flags |= RecordEntryHidden;
        value->flags |= RecordEntryHidden;
    } else {
        title->flags &= ~RecordEntryHidden;
        spacer->flags &= ~RecordEntryHidden;
        value->flags &= ~RecordEntryHidden;
        if (slot == RECORD_SET_EP1) {
            set_text_entry_string(title, TWindowSubStatusDisp::get_message_10(0x95), 0);
        } else {
            set_text_entry_string(title, TWindowSubStatusDisp::get_message_10(0x97), 0);
        }
        text_builder_reset();
        TWindowSubStatusDisp::append_play_time(time);
        set_text_entry_string(value, get_shared_text_buffer(), 0x20);
    }

    slot = RECORD_SET_EP2;
    if (page == 2) {
        slot = RECORD_SET_EP2_SPLIT;
    }
    title = (WindowTextEntry *)get_array_entry(0xA);
    spacer = (WindowTextEntry *)get_array_entry(0xB);
    value = (WindowTextEntry *)get_array_entry(0xC);
    rank = get_challenge_rank(client_index, slot);
    if (rank == 0) {
        title->flags |= RecordEntryHidden;
        spacer->flags |= RecordEntryHidden;
        value->flags |= RecordEntryHidden;
    } else {
        title->flags &= ~RecordEntryHidden;
        spacer->flags &= ~RecordEntryHidden;
        value->flags &= ~RecordEntryHidden;
        set_text_entry_string(title, TWindowSubStatusDisp::get_message_10(0x99), 0);
        set_text_entry_string(value, challenge_rank_letters[rank], 0);
    }

    title = (WindowTextEntry *)get_array_entry(0xD);
    spacer = (WindowTextEntry *)get_array_entry(0xE);
    value = (WindowTextEntry *)get_array_entry(0xF);
    time = get_challenge_set_time(client_index, slot);
    if (time == 0) {
        title->flags |= RecordEntryHidden;
        spacer->flags |= RecordEntryHidden;
        value->flags |= RecordEntryHidden;
    } else {
        title->flags &= ~RecordEntryHidden;
        spacer->flags &= ~RecordEntryHidden;
        value->flags &= ~RecordEntryHidden;
        set_text_entry_string(title, TWindowSubStatusDisp::get_message_10(0x96), 0);
        text_builder_reset();
        TWindowSubStatusDisp::append_play_time(time);
        set_text_entry_string(value, get_shared_text_buffer(), 0x20);
    }
}

void TWindowSubStatusDisp::vt15() {  }

void TWindowSubStatusDisp::vt5() {
    s32 type;
    s32 stage_count;
    WindowTextEntry *e;
    s32 time;
    s32 i;
    int stage_in_set;
    if ((f32) this->open_tick > 7.5f) {
        this->open_tick = 7;
    }
    init_window_layout_entries(
        &this->entry_list,
        &TWindowSubStatusDisp::numbered_times_layout,
        this->client_index);
    type = get_display_mode();
    e = (WindowTextEntry *)get_array_entry(0);
    set_text_entry_string(e, TWindowSubStatusDisp::get_message_10(status_disp_vt5_message_ids[type]), 0);
    stage_count = challenge_set_stage_count(type);
    i = 0;
    do {
        e = (WindowTextEntry *)get_array_entry(i + 1);
        stage_in_set = stage_count > i;
        if (!stage_in_set) {
            e->flags |= 2;
        } else {
            time = get_challenge_stage_time(i, this->client_index, type);
            if (time == 0) {
                e->flags |= 2;
            } else {
                e->flags &= ~2;
                text_builder_reset();
                append_padded_number(i + 1, 2);
                text_builder_append(":");
                TWindowSubStatusDisp::append_play_time(time);
                set_text_entry_string(e, get_shared_text_buffer(), 0x20);
            }
        }
        i++;
    } while (i < 9);
}

void TWindowSubStatusDisp::vt16() {  }

// The record set this page shows: page 2 shows the split-screen sets.
s32 TWindowSubStatusDisp::get_display_mode() {
    s32 r;
    if (page == 2) {
        s8 t = page_indicator->get_type();
        r = RECORD_SET_EP2_SPLIT;
        if (t == 2) r = RECORD_SET_EP1_SPLIT;
        return r;
    }
    return page_indicator->get_type() != 2 ? RECORD_SET_EP2 : RECORD_SET_EP1;
}
}

void TWindowSubStatusDisp::set_requested_page(s16 value) { requested_page = value; }

void TWindowSubStatusDisp::set_scale(f32 x, f32 y) { scale_x = x; scale_y = y; }
