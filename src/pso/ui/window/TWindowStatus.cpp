#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowStatus.h"
#include "pso/ui/window/TWindowSimpleStatus.h"
#include "pso/ui/window/TWindowBase.h"

#include "pso/item/mag/TItemMag.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/render/TextureState.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/unk/TWindowLayoutNumber.h"


const char *TWindowStatus::class_name = "TWindowStatus";


#pragma readonly_strings on

StatusWindowLayout status_window_layout_entries = {
    15, 1,
    {6, {27.0f, 16.0f}, {34.0f, 29.0f}, 112.0f, 84.0f, 0.5f, -1, &hud_texlist, 0, 4},
    {3, {124.0f, 67.0f}, 0.5f, 0xFFFFFFFF, 4, NULL},
    {4, {82.0f, 59.0f}, 0.5f, 0xFFFFFFFF, 4, 1},
    {{2, {90.0f, 24.0f}, 0.5f, 0xFF00FF15, 0x20, 120.0f, 0, 0}, 0xFF00CA9E, 0xFFFF2924},
    {{2, {90.0f, 48.0f}, 0.5f, 0xFF008CFC, 0x20, 120.0f, 0, 0}, 0xFF008DEE, 0xFFFF2924},
    {3, {30.0f, 59.0f}, 0.5f, 0xFFFFFFFF, 4, "Lv"},
    {3, {90.0f, 9.0f}, 0.5f, 0xFFFFFFFF, 4, "HP"},
    {4, {210.0f, 9.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {3, {210.0f, 9.0f}, 0.5f, 0xFFFFFFFF, 4, "/"},
    {4, {210.0f, 9.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {3, {90.0f, 33.0f}, 0.5f, 0xFFFFFFFF, 4, "TP"},
    {4, {210.0f, 33.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {3, {210.0f, 33.0f}, 0.5f, 0xFFFFFFFF, 4, "/"},
    {4, {210.0f, 33.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {5, {68.0f, 13.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
};

WindowDescriptor status_window_settings = {
    {228.0f, 76.0f}, 70050.0f, &status_window_layout_entries, 0xB28,
};


void TWindowStatus::update_hp_tp_values() {
    TObjPlayer *player;
    TWindowLayoutCountingNumber *charge;
    TWindowLayoutNumber *current;
    TWindowLayoutNumber *maximum;
    WindowTextEntry *label;
    WindowTextEntry *slash;
    s32 color;
    player = get_player_by_client_id(get_width());
    if (player != NULL) {
        current = (TWindowLayoutNumber *)get_array_entry(7);
        maximum = (TWindowLayoutNumber *)get_array_entry(9);
        label = (WindowTextEntry *)get_array_entry(6);
        slash = (WindowTextEntry *)get_array_entry(8);
        maximum->value = player->get_hpmax();
        current->value = player->hp;
        color = update_hp_entry();
        current->color = color;
        label->color = color;
        maximum->color = color;
        slash->color = color;
        maximum->calc_size();
        current->calc_size();
        current->x = maximum->x - maximum->width - 12.0f;
        slash->x = current->x;
        current = (TWindowLayoutNumber *)get_array_entry(0xB);
        maximum = (TWindowLayoutNumber *)get_array_entry(0xD);
        label = (WindowTextEntry *)get_array_entry(0xA);
        slash = (WindowTextEntry *)get_array_entry(0xC);
        maximum->value = player->get_tpmax();
        current->value = player->tp;
        color = update_hp_gauge();
        current->color = color;
        label->color = color;
        maximum->color = color;
        slash->color = color;
        maximum->calc_size();
        current->calc_size();
        current->x = maximum->x - maximum->width - 12.0f;
        slash->x = current->x;
        update_status_entry();
        charge = static_cast<TWindowLayoutCountingNumber *>(get_array_entry(0xE));
        charge->set_status_entry_target(player->get_photon_blast_charge());
    }
}

void TWindowStatus::draw_background(WindowDrawContext *context) {
    static const NJS_POINT2 pos = {44.0f, 30.5f};
    TexturedQuad q;
    f32 w;
    f32 s;

    {
        u8 *e = (u8 *)get_array_entry(0xE);
        draw_photon_blast_gauge_ring(this, context, &pos, *(s32 *)((s8 *)e + 0x20), 26.0f);
    }
    begin_screen_draw(1);
    set_texture_list(hud_texlist);
    set_draw_texture_and_color(0xB, context->color);
    { f32 r = get_transition_progress();
    s = -1.0f / (0.0598f + this->draw_depth);
    q.x0 = -(69.0f * (w = 1.0f - r)); }
    q.y0 = -(80.0f * w);
    q.x1 = 69.0f + q.x0;
    q.y1 = 80.0f + q.y0;
    q.u0 = 0.4609375f;
    q.v0 = 0.3125f;
    q.u1 = 0.73046875f;
    q.v1 = 0.625f;
    draw_textured_quad_at_depth(&q.x0, s);
    q.x0 = context->x;
    q.y0 = context->y;
    q.x1 = 228.0f + q.x0;
    q.y1 = 76.0f + q.y0;
    q.u0 = 0.0f;
    q.v0 = 0.0f;
    q.u1 = 0.890625f;
    q.v1 = 0.296875f;
    context->transform_quad(&q);
    draw_textured_quad_at_depth(&q.x0, s);
    end_screen_draw();
    if (scanline_crosses_window(context, &context->inner_x, &context->inner_w) != 0) {
        begin_window_sweep_draw(0xB);
        draw_window_sweep_strip(&q, context);
        end_window_sweep_draw(0xB);
    }
}

#pragma fp_contract on
void TWindowStatus::render() {
    TWindowLayoutNumber *entry = static_cast<TWindowLayoutNumber *>(get_array_entry(0xE));
    WindowDrawContext *ctx;
    entry->calc_size();
    entry->x = 0.5f * entry->width + 68.0f;
    ctx = draw_default_entry();
    draw_background(ctx);
    draw_visible_window_entries(this, &entry_list, ctx);
}

void TWindowStatus::run_task() {
    update_hp_tp_values();
    update_lockon_window(this);
    update_status_help_item(this);
    update_status_icons((void *)(get_window_layout_position(0x1D)));
    update_window();
    update_fade();
    update_window_entry_list(&entry_list);
}


TWindowStatus::~TWindowStatus() {

}



TWindowStatus::TWindowStatus(void *position, s32 client, u8 *descriptor)
    : TWindowSimpleStatus(position, client, descriptor) {
    m_name = TWindowStatus::class_name;
}

TWindowSimpleStatus *create_status_window(saddr client) {
    void *position = (void *)get_window_layout_position(0x1C);
    if (is_split_screen() != 0) {
        return TWindowSimpleStatus::create(position, (s32)client);
    }
    return new TWindowStatus(position, (s32)client, (u8 *)&status_window_settings);
}
