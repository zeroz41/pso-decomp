#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
// TObject's helpers are out-of-line functions for this TU (run_task calls
// TObject::queue_destruction, defined elsewhere).
#define TOBJECT_OUT_OF_LINE_HELPERS
#include <stdlib.h>
#include "pso/object/TObjTombstone.h"
#include "pso/system/vector.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/unk/TLobby.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/object/TObjLuker_801329B0.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemData.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/network/client_id.h"
#include "pso/ui/Language.h"
#include <string.h>
#include <stdio.h>
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/TLobby_80291D94.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/player/PlayerSlots.h"

struct Off_800753DC { s16 x, y; };

extern "C" {


s32 PPCSync();
u32 calc_text_width(const char *);
void draw_menu_font_string(const char *, u32, s32, f32, f32, f32);
const char *get_message_text(s32);
void set_tombstone_position(s32 i, Vec *pos);
void TObjTombstone__drop_recovery_items(TObjTombstone *self);
}

__declspec(section ".data") const char *re_b_mark_base_model_names[2] = { "re_b_mark_base.gj", NULL };
__declspec(section ".sdata") const char *re_b_mark_base_motion_names[1] = { NULL };
BmlResourceDescriptor tombstone_resource_descriptor = {
    "re_b_mark_base.bml", re_b_mark_base_model_names, re_b_mark_base_motion_names, 1, 0
};
extern "C" {
const char *TObjTombstone__class_name = "TObjTombstone";
}
extern "C" {
TObjTombstoneDropRates TObjTombstone__base_matrix = { { 0.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f } };
// Six template items: data 03 00 00/01/02 and 03 01 00/01/02 (inferred:
// Monomate, Dimate, Trimate, Monofluid, Difluid, Trifluid), id 0xFFFFFFFF.
TItemData lbl_8048D278[6] = {
    { { { 3, 0, 0, 0, 0, 1 } }, 0xFFFFFFFF, { { 0 } } },
    { { { 3, 0, 1, 0, 0, 1 } }, 0xFFFFFFFF, { { 0 } } },
    { { { 3, 0, 2, 0, 0, 1 } }, 0xFFFFFFFF, { { 0 } } },
    { { { 3, 1, 0, 0, 0, 1 } }, 0xFFFFFFFF, { { 0 } } },
    { { { 3, 1, 1, 0, 0, 1 } }, 0xFFFFFFFF, { { 0 } } },
    { { { 3, 1, 2, 0, 0, 1 } }, 0xFFFFFFFF, { { 0 } } },
};
Off_800753DC tombstone_name_label_offset_table[8] = {
    { 0, -2 }, { 2, -2 }, { 2, 0 }, { 2, 2 }, { 0, 2 }, { -2, 2 }, { -2, 0 }, { -2, -2 },
};
BmlResource *TObjTombstone__shared_resource_object;
s32 tombstone_first_run_flag;
Vec tombstone_position_table[4];
}

// The unit is compiled -inline off,deferred, which emits functions last-defined
// first: they are written here from the last back to the first.
s32 TCameraCtrl::get_viewport_x() { return TCameraCtrl::viewport_x; }

s32 TCameraCtrl::get_viewport_y() { return TCameraCtrl::viewport_y; }

TObjTombstone *TObjTombstone::create(TObject *parent, s32 client, const TObjTombstoneRecord *record) {
    return new TObjTombstone(parent, client, record);
}

TObjTombstone *TLobby::create_tombstone(TObject *parent, s32 client, const TObjTombstoneSpot *spot) {
    return new TObjTombstone(parent, client, spot);
}

void TObjTombstone::load_resources() {
    BmlResource *res;
    if (TObjTombstone__shared_resource_object == NULL) {
        res = new BmlResource(1, &tombstone_resource_descriptor, 0, 0, NULL);
        TObjTombstone__shared_resource_object = res;
        TObjTombstone::reset_matrix();
    }
}

void TObjTombstone::destroy() {
    if (TObjTombstone__shared_resource_object != NULL) {
        delete TObjTombstone__shared_resource_object;
        TObjTombstone__shared_resource_object = NULL;
        TObjTombstone::reset_matrix();
    }
}

TObjTombstone::TObjTombstone(TObject *parent, s32 client, const TObjTombstoneRecord *src) : TObjCollidable(parent) {
    this->m_name = TObjTombstone__class_name;
    if (TObjTombstone__shared_resource_object == NULL) {
        return;
    }
    setup(client, src);
    init_parts();
    this->m_234 = 0;
    if (local_client_id != designated_client_id) {
        this->m_234 = 1;
    }
}

// Spawns the tombstone from a short spot record (TLobby::create_tombstone).
TObjTombstone::TObjTombstone(TObject *parent, s32 client, const TObjTombstoneSpot *spot)
    : TObjCollidable(parent) {
    TObjTombstoneRecord record;
    this->m_name = TObjTombstone__class_name;
    if (TObjTombstone__shared_resource_object == NULL) {
        return;
    }
    volatile TObjTombstoneRecord &output = record;
    const volatile TObjTombstoneSpot *input = spot;
    output.phase = input->phase;
    output.layout = input->layout;
    output.floor = input->floor;
    VecCopy(&record.position, &spot->position);
    setup(client, &record);
    reset_entries_and_format_name();
    this->m_234 = 0;
}

void TObjTombstone::setup(s32 client, const TObjTombstoneRecord *src) {
    this->texlist = get_bml_texlist(TObjTombstone__shared_resource_object, 0);
    this->model = get_bml_model(TObjTombstone__shared_resource_object, 0);
    this->client_id = client;
    this->record = *src;
    VecCopy(&this->position, &this->record.position);
    this->rotation_y = this->client_id << 0xD;
    this->m_b0 = 0.0f;
    this->m_b4 = 0.0f;
    this->m_b8 = 0.0f;
    this->m_bc = 0.0f;
    this->m_230 = 0;
    set_tombstone_position(this->client_id, &this->position);
}

TObjTombstone::~TObjTombstone() {
}

void TObjTombstone::run_task() {
    if (check_owner() != 0) {
        queue_destruction();
        return;
    }
    this->m_b0 = get_distance_to_local_player_xz();
    update_rise();
    if (is_player_nearby() != 0) {
        TObjTombstone__drop_recovery_items(this);
    }
    this->m_230 = this->m_230 + 1;
    tombstone_first_run_flag = 0;
}

void TObjTombstone::update_rise() {
    if (is_other_tombstone_closer() == 0 && this->m_b0 < 50.0f) {
        if ((this->m_b4 += 0.13333334f) > 1.0f) {
            this->m_b4 = 1.0f;
        }
    } else {
        if ((this->m_b4 += -0.044444446f) < 0.0f) {
            this->m_b4 = 0.0f;
        }
    }
}

s32 TObjTombstone::is_player_nearby() {
    Vec d;
    f32 best;
    f32 len;
    s32 i;
    TObjPlayer *player;
    if (this->m_234 != 0) {
        return 0;
    } else if (local_client_id != designated_client_id) {
        this->m_234 = 1;
        return 0;
    }
    if (check_all_players_active() == 0) {
        return 0;
    }
    best = 10.0f;
    for (i = 0; i < 4; i++) {
        player = get_player_by_client_id(i);
        if (player != NULL) {
            VecCopy(&d, &player->position);
            subtract_vector(&d, &this->position);
            d.y = 0.0f;
            len = vector_length(&d);
            if (best > len) {
                best = len;
            }
        }
    }
    return best < 10.0f;
}

// Drops recovery items around the tombstone, once.
extern "C" void TObjTombstone__drop_recovery_items(TObjTombstone *self) {
    s32 count;
    s32 players;
    s32 kind;
    s32 i;
    s32 j;
    f32 roll;
    f32 sum;
    f32 *rate;

    self->m_234 = 1;
    count = 0;
    roll = 0.000030517578f * rand();
    rate = TObjTombstone__base_matrix.count;
    sum = *rate;
    for (i = 1; i < 5; i++) {
        if (0.0f != sum && roll <= sum) {
            count = i;
            break;
        }
        sum += *++rate;
    }
    if (count != 0) {
        players = 0;
        for (s32 client = 0; client < 4; client++) {
            if (get_player_by_client_id(client) != NULL) {
                players++;
            }
        }
        if (count > players) {
            count = players;
        }
        kind = -1;
        roll = 0.000030517578f * rand();
        rate = TObjTombstone__base_matrix.kind;
        sum = rate[0];
        for (j = 0; j < 6; j++, rate++) {
            if (0.0f != sum && roll <= sum) {
                kind = j;
                break;
            }
            sum += rate[1];
        }
        if (kind != -1) {
            s32 angle = self->rotation_y - ((count - 1) * 0x2000) / 2;
            TItemData item = lbl_8048D278[kind];
            s32 dropped = 0;
            s32 step;
            for (step = 0; step < 0x10000; step += 0x2000) {
                Vec pos = self->position;
                pos.x += 7.5f * cos_table_lookup(angle);
                pos.z += 7.5f * sin_table_lookup(angle);
                pos.y += 10.0f;
                if (project_actor_to_ground((TObjChara *)self, &pos, 0) != 0) {
                    pos.y += 10.0f;
                    item.id = 0xFFFFFFFF;
                    drop_stacked_item(&item, local_client_id, &pos.x);
                    if (++dropped >= count) {
                        return;
                    }
                }
                angle += 0x2000;
            }
        }
    }
}

void TObjTombstone::init_parts() {
    format_player_name();
    format_label();
    build_name_text();
    format_enemy_text();
    format_quoted_name();
    format_date_text();
}

void TObjTombstone::reset_entries_and_format_name() {
    s32 i;
    for (i = 0; i < 6; i++) {
        this->labels[i][0] = 0;
    }
    format_player_name();
}

void TObjTombstone::format_player_name() {
    char buf[0x30];
    char *p;
    TObjPlayer *player;
    char *dst = this->labels[0];
    player = get_player_by_client_id(this->client_id);
    dst[0] = 0;
    if (player != NULL) {
        strncpy(buf, player->name, 0x2F);
        buf[0x2F] = 0;
        for (p = buf + strlen(buf) - 1; p > buf && *p == ' '; p--) {
            *p = 0;
        }
        sprintf(dst, "< %s >", buf);
    }
    dst[0x2F] = 0;
}

void TObjTombstone::format_label() {
    sprintf(this->labels[1], "%s%d", get_message_text(0x4D), this->record.unk_4);
    this->labels[1][0x2F] = 0;
}

void TObjTombstone::build_name_text() {
    char *buf = this->labels[2];
    if (this->record.display_name[0] == 0 || TWindowSubComCard::contains_profanity(this->record.display_name) != 0) {
        buf[0] = 0;
    } else {
        sprintf(buf, "%s%s", get_message_text(0x4C), this->record.display_name);
    }
    buf[0x2F] = 0;
}

void TObjTombstone::format_enemy_text() {
    char fmt[0x30];
    char *text = this->labels[3];
    s32 name;
    text[0] = 0;
    if (this->record.rt_index > 0) {
        name = enemy_name_for_rt_index(this->record.rt_index);
        if (name != 0) {
            strncpy(fmt, get_message_text(0x4E), 0x2F);
            fmt[0x2F] = 0;
            sprintf(text, fmt, name);
        }
    }
    text[0x2F] = 0;
}

void TObjTombstone::format_quoted_name() {
    char *buf = this->labels[4];
    if (this->record.unit_name[0] == 0 || TWindowSubComCard::contains_profanity(this->record.unit_name) != 0) {
        buf[0] = 0;
    } else {
        sprintf(buf, "\"%s\"", this->record.unit_name);
    }
    buf[0x2F] = 0;
}

void TObjTombstone::format_date_text() {
    char *text;
    s32 month;
    s32 day;
    s32 hour;
    s32 minute;
    s32 year;
    u32 d;
    text = this->labels[5];
    text[0] = 0;
    if (this->client_id != local_client_id) {
        return;
    }
    d = this->record.date;
    year = d >> 28;
    month = (d >> 24) & 0xF;
    day = (d >> 16) & 0x1F;
    hour = (d >> 8) & 0x1F;
    minute = d & 0x3F;
    if (year == 15 || month <= 0 || month > 12 || day <= 0 || day > 31
        || hour < 0 || hour >= 24 || minute < 0 || minute >= 60) {
        return;
    }
    switch (current_language) {
    case LANGUAGE_JAPANESE:
        sprintf(text, "%d/%02d/%02d %02d:%02d", year + 2000, month, day, hour, minute);
        break;
    default:
        sprintf(text, "%02d/%02d/%d %02d:%02d", month, day, year + 2000, hour, minute);
        break;
    }
}

f32 TObjTombstone::get_distance_to_local_player_xz() {
    TObjPlayer *p = get_player_by_client_id(local_client_id);
    if (p == NULL) {
        return 65536.0f;
    }
    Vec v = this->position;
    subtract_vector(&v, &p->position);
    v.y = 0.0f;
    return vector_length(&v);
}

void TObjTombstone::render() {
    if (check_height_ready() != 0) {
        update_render_flags();
        switch (TWindowSubStatusDisp::resolve_player_slot(-1)) {
        case 2:
        case 3:
            update_fade_by_distance();
            break;
        default:
            draw_name_labels();
            break;
        }
    }
}

s32 TObjTombstone::check_height_ready() {
    if (TObjTombstone::check_all_players_active() == 0) {
        return 0;
    }
    return (u32)__cntlzw(this->m_b0 > 500.0f) >> 5;
}

s32 TObjTombstone::check_all_players_active() {
    s32 i;
    TObjPlayer *player;

    if (has_window_task_root() == 0) {
        return 0;
    }
    i = 0;
loop_3:
    player = get_player_by_client_id(i);
    if (player != NULL && player->test_actor_flags(0x02000000) != 0) {
        return 0;
    }
    i += 1;
    if (i >= 4) {
        return 1;
    }
    goto loop_3;
}

void TObjTombstone::update_render_flags() {
    NJS_OBJECT *material;
    u32 *flags;

    if (TObjTombstone__shared_resource_object != NULL) {
        if (tombstone_first_run_flag == 0) {
            scroll_ginja_mesh_uvs(static_cast<GinjaModel *>(static_cast<NJS_OBJECT *>(model)->child->sibling->model), -8, 0, 0, 1);
            tombstone_first_run_flag = 1;
            PPCSync();
        }
        material = static_cast<NJS_OBJECT *>(model)->child->sibling->sibling;
        flags = &material->sibling->evalflags;
        if (this->m_230 & 0x10) {
            material->evalflags &= ~NJD_EVAL_HIDE;
            *flags |= NJD_EVAL_HIDE;
        } else {
            material->evalflags |= NJD_EVAL_HIDE;
            *flags &= ~NJD_EVAL_HIDE;
        }
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        draw_ginja_object(this->model);
        pop_matrix();
    }
}

void TObjTombstone::draw_name_labels() {
    u32 c2;
    u32 c1;
    NJS_POINT2 screen;
    Vec pos;
    f32 m;
    f32 a;
    f32 b;
    u32 alpha;
    if (0.0f == this->m_b4) return;
    VecCopy(&pos, &this->position);
    pos.y += 14.0f;
    if (TObjTombstone::project_to_screen(this, &screen, &pos) == 0) return;
    m = 0.0f;
    for (s32 i = 0; i < 6; i++) {
        f32 w = calc_text_width(this->labels[i]);
        if (m < w) m = w;
    }
    m *= 0.5f;
    if (screen.x - m < 0.0f || screen.x + m > 640.0f) {
        if ((this->m_b8 += -0.16666667f) < 0.0f) this->m_b8 = 0.0f;
        if ((this->m_bc += -0.016666668f) < 0.0f) this->m_bc = 0.0f;
    } else {
        if ((this->m_b8 += 0.16666667f) > 1.0f) this->m_b8 = 1.0f;
        if ((this->m_bc += 0.16666667f) > 1.0f) this->m_bc = 1.0f;
    }
    a = this->m_b4 * this->m_b8;
    b = this->m_b4 * this->m_bc;
    alpha = (s32)(40.0f * sin_table_lookup(this->m_230 << 8)) + 200;
    c1 = (u32)(alpha * a) << 24;
    c2 = ((u32)(alpha * b) << 24) | 0xFFFFFF;
    for (s32 i = 0; i < 6; i++) {
        char *name;
        NJS_POINT2 p = screen;
        name = this->labels[i];
        if (strlen(name) != 0) {
            p.x -= 0.5f * TWindowSubStatusDisp::calc_text_width(name);
            if (a > 0.0f) {
                s32 j;
                for (j = 0; j < 8; j++) {
                    Off_800753DC o = tombstone_name_label_offset_table[j];
                    draw_menu_font_string(name, c1, 1, p.x + o.x, p.y + o.y, 0.5f);
                }
            }
            if (b > 0.0f) {
                draw_menu_font_string(name, c2, 1, p.x, p.y, 0.5f);
            }
            screen.y += 25.0f;
        }
    }
}

void TObjTombstone::update_fade_by_distance() {
    f32 dist;
    TObjPlayer *player;
    player = get_player_by_client_id(TCameraCtrl::get_nth_view_player_id(TCameraCtrl::get_camera_no()));
    if (player != NULL) {
        dist = xyz_distance(&player->position, &this->position);
        if (dist <= 40.0f) {
            this->m_b4 = 1.0f;
        } else if (dist >= 50.0f) {
            this->m_b4 = 0.0f;
        } else {
            this->m_b4 = (50.0f - dist) / 10.0f;
        }
        draw_name_labels();
    }
}

s32 TObjTombstone::project_to_screen(const TObjTombstone *, NJS_POINT2 *screen, const Vec *point) {
    Vec d;
    Vec v = { 0.0f, 0.0f, -1.0f };
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, camera_ctrl_instance->yaw);
    rotate_matrix_x(0, camera_ctrl_instance->pitch);
    rotate_matrix_z(0, camera_ctrl_instance->roll);
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrix();
    VecCopy(&d, point);
    subtract_vector(&d, &camera_ctrl_instance->pos);
    if (vec3_dot(&v, &d) <= 0.0f) {
        return 0;
    }
    push_matrix();
    project_world_to_screen(NULL, point, &screen->x);
    pop_matrix();
    if (is_split_screen() != 0) {
        screen->x -= (f32)TCameraCtrl::get_viewport_x();
        screen->x /= TCameraCtrl::get_view_scale();
        screen->y -= (f32)TCameraCtrl::get_viewport_y();
        screen->y /= TCameraCtrl::get_fov();
    }
    return 1;
}

s32 TObjTombstone::is_other_tombstone_closer() {
    f32 best;
    f32 d;
    TObjPlayer *player;
    Vec *ppos;
    s32 i;
    best = 50.0f;
    player = get_player_by_client_id(local_client_id);
    if (player == NULL) {
        return 0;
    }
    ppos = &player->position;
    for (i = 0; i < 4; i++) {
        if (i != this->client_id && -10000.0f != tombstone_position_table[i].y) {
            Vec v = tombstone_position_table[i];
            subtract_vector(&v, ppos);
            v.y = 0.0f;
            d = vector_length(&v);
            if (best > d) {
                best = d;
            }
        }
    }
    if (50.0f == best) {
        return 0;
    }
    Vec w = this->position;
    subtract_vector(&w, ppos);
    w.y = 0.0f;
    d = vector_length(&w);
    if (d < best || (d == best && this->client_id == local_client_id)) {
        return 0;
    }
    return 1;
}

s32 TObjTombstone::check_owner() {
    s32 active;

    if (TRaderMapCore::is_not_split_screen() == 1) {
        active = is_challenge_mode_active();
    } else {
        active = TLobby::is_flag_set();
    }
    if (active == 0 || (s8)this->record.floor != get_current_floor()) {
        return 1;
    }
    return 0;
}

void handle_6x96(void) {}

void TObjTombstone::reset_matrix() {
    TObjTombstoneDropRates rates = { { 0.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f } };
    TObjTombstone__base_matrix.copy_matrix(&rates);
}

void TObjTombstoneDropRates::copy_matrix(const TObjTombstoneDropRates *src) {
    volatile TObjTombstoneDropRates *out = this;
    const volatile TObjTombstoneDropRates *in = src;
    out->count[0] = in->count[0];
    out->count[1] = in->count[1];
    out->count[2] = in->count[2];
    out->count[3] = in->count[3];
    out->kind[0] = in->kind[0];
    out->kind[1] = in->kind[1];
    out->kind[2] = in->kind[2];
    out->kind[3] = in->kind[3];
    out->kind[4] = in->kind[4];
    out->kind[5] = in->kind[5];
}

// Sets the drop rates (inferred: called by qst_op_set_cmode_grave_rates), unless
// a weight is negative or a group adds up to more than 1.
extern "C" void set_tombstone_drop_rates(TObjTombstoneDropRates *rates) {
    const f32 *count = rates->count;
    const f32 *kind = rates->kind;
    f32 one;
    f32 sum;

    sum = count[0] + count[1] + count[2] + count[3];
    if (count[0] < 0.0f || count[1] < 0.0f || count[2] < 0.0f || count[3] < 0.0f || sum > 1.0f) {
        return;
    }
    sum = kind[0] + kind[1] + kind[2] + kind[3] + kind[4] + kind[5];
    one = 1.0f;
    if (kind[0] < 0.0f || kind[1] < 0.0f || kind[2] < 0.0f || kind[3] < 0.0f || kind[4] < 0.0f || kind[5] < 0.0f ||
        sum > one) {
        return;
    }
    TObjTombstone__base_matrix.copy_matrix(rates);
}

void TLobby::reset_tombstone_values() {
    s32 i;
    for (i = 0; i < 4; i++) {
        tombstone_position_table[i].y = -10000.0f;
    }
}

extern "C" {
void set_tombstone_position(s32 i, Vec *pos) {
    if (i < 0 || i >= 4) {
        return;
    }
    VecCopy(&tombstone_position_table[i], pos);
}
}
