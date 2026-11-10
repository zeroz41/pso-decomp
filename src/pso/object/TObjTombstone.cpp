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

struct Off_800753DC { s16 x, y; };
struct P_800753DC { f32 x, y; };

extern "C" {
f32 xyz_distance(void *, void *);
extern s32 TLobby__designated_client_id;
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void free_bin_model_request(void *, int);
// TCameraCtrl.h declares these short; the callers here take an int (no extsh).
s32 get_screen_width__11TCameraCtrlFv();
s32 get_screen_height__11TCameraCtrlFv();
s32 PPCSync();
u32 calc_text_width(const char *);
void draw_menu_font_string(const char *, u32, s32, f32, f32, f32);
const char *TQuestVmDownLoadServer__sub_8006EF6C(s32);
s32 TWindowCtrlMain__sub_8024CE58();
void fn_80074E04(s32 i, Vec *pos);
void TObjTombstone__sub_80075DFC(TObjTombstone *self);
}

struct CameraView_800751BC {
    u8 pad0[0x178];
    Vec pos;
    u8 pad184[0xC];
    s32 f190;
    s32 f194;
    s32 f198;
};
extern "C" CameraView_800751BC *camera_ctrl_instance;

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
u32 TObjTombstone__shared_resource_object;
s32 tombstone_first_run_flag;
Vec tombstone_position_table[4];
}

// The unit is compiled -inline off,deferred, which emits functions last-defined
// first: they are written here from the last (0x8007666C) back to the first.
void *TObjTombstone::create(void *arg0, void *arg1, void *arg2) {
    return new TObjTombstone((TObject *)arg0, (s32)arg1, (TObjTombstoneRecord *)arg2);
}

void *TLobby::create_tombstone(void *arg0, void *arg1, void *arg2) {
    return new TObjTombstone((TObject *)arg0, (s32)arg1, (TObjTombstoneSpot *)arg2);
}

void TObjTombstone::load_resources() {
    s32 mem;
    s32 res;
    if (TObjTombstone__shared_resource_object == 0) {
        mem = (int)::operator new(0x440);
        res = mem;
        if (res != 0) {
            res = (long)load_resource_from_descriptor((void *)mem, 1, &tombstone_resource_descriptor, 0, 0, 0);
        }
        TObjTombstone__shared_resource_object = res;
        TObjTombstone::reset_matrix();
    }
}

void TObjTombstone::destroy() {
    if (TObjTombstone__shared_resource_object != 0U) {
        free_bin_model_request((void *)TObjTombstone__shared_resource_object, 1);
        TObjTombstone__shared_resource_object = 0U;
        TObjTombstone::reset_matrix();
    }
}

TObjTombstone::TObjTombstone(TObject *parent, s32 client, TObjTombstoneRecord *src) : TObjCollidable(parent) {
    this->m_name = TObjTombstone__class_name;
    if (TObjTombstone__shared_resource_object == 0U) {
        return;
    }
    setup(client, src);
    init_parts();
    this->m_234 = 0;
    if (local_client_id != TLobby__designated_client_id) {
        this->m_234 = 1;
    }
}

// Spawns the tombstone from a short spot record (TLobby::create_tombstone).
TObjTombstone::TObjTombstone(TObject *parent, s32 client, TObjTombstoneSpot *spot)
    : TObjCollidable(parent) {
    TObjTombstoneRecord record;
    this->m_name = TObjTombstone__class_name;
    if (TObjTombstone__shared_resource_object == 0U) {
        return;
    }
    record.unk_0 = spot->unk_0;
    record.unk_1 = spot->unk_1;
    record.floor = spot->unk_2;
    VecCopy(&record.position, &spot->position);
    setup(client, &record);
    reset_entries_and_format_name();
    this->m_234 = 0;
}

void TObjTombstone::setup(s32 client, TObjTombstoneRecord *src) {
    this->texlist = TObjFish__sub_8001EDB0(TObjTombstone__shared_resource_object, 0);
    *(s32 *)&this->model = get_bml_model(TObjTombstone__shared_resource_object, 0);
    this->client_id = client;
    this->record = *src;
    VecCopy(&this->position, &this->record.position);
    this->rotation_y = this->client_id << 0xD;
    this->m_b0 = 0.0f;
    this->m_b4 = 0.0f;
    this->m_b8 = 0.0f;
    this->m_bc = 0.0f;
    this->m_230 = 0;
    fn_80074E04(this->client_id, &this->position);
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
        TObjTombstone__sub_80075DFC(this);
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
    } else if (local_client_id != TLobby__designated_client_id) {
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
extern "C" void TObjTombstone__sub_80075DFC(TObjTombstone *self) {
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
    sprintf(this->labels[1], "%s%d", TQuestVmDownLoadServer__sub_8006EF6C(0x4D), this->record.unk_4);
    this->labels[1][0x2F] = 0;
}

void TObjTombstone::build_name_text() {
    char *buf = this->labels[2];
    if (this->record.unk_1C[0] == 0 || TWindowSubComCard::contains_profanity(this->record.unk_1C) != 0) {
        buf[0] = 0;
    } else {
        sprintf(buf, "%s%s", TQuestVmDownLoadServer__sub_8006EF6C(0x4C), this->record.unk_1C);
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
            strncpy(fmt, TQuestVmDownLoadServer__sub_8006EF6C(0x4E), 0x2F);
            fmt[0x2F] = 0;
            sprintf(text, fmt, name);
        }
    }
    text[0x2F] = 0;
}

void TObjTombstone::format_quoted_name() {
    char *buf = this->labels[4];
    if (this->record.unk_30[0] == 0 || TWindowSubComCard::contains_profanity(this->record.unk_30) != 0) {
        buf[0] = 0;
    } else {
        sprintf(buf, "\"%s\"", this->record.unk_30);
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

    if (TWindowCtrlMain__sub_8024CE58() == 0) {
        return 0;
    }
    i = 0;
loop_3:
    player = get_player_by_client_id(i);
    if (player != NULL && player->obj_testFlags30(0x02000000) != 0) {
        return 0;
    }
    i += 1;
    if (i >= 4) {
        return 1;
    }
    goto loop_3;
}

void TObjTombstone::update_render_flags() {
    u8 *material;
    s32 *flags;

    if (TObjTombstone__shared_resource_object != 0U) {
        if (tombstone_first_run_flag == 0) {
            scroll_ginja_mesh_uvs((void *) (*(s32 *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)this->model + 0x2C)) + 0x30)) + 4)), -8, 0, 0, 1);
            tombstone_first_run_flag = 1;
            PPCSync();
        }
        material = (unsigned char *) (*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)this->model + 0x2C)) + 0x30)) + 0x30));
        flags = *(s32 **)((s8 *)material + 0x30);
        if (this->m_230 & 0x10) {
            *(s32 *)((s8 *)material + 0) = (s32) (*(s32 *)((s8 *)material + 0) & 0xFFFFFFF7);
            *flags |= 8;
        } else {
            *(s32 *)((s8 *)material + 0) = (s32) (*(s32 *)((s8 *)material + 0) | 8);
            *flags &= 0xFFFFFFF7;
        }
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_object(this->model);
        pop_matrix();
    }
}

void TObjTombstone::draw_name_labels() {
    u32 c2;
    u32 c1;
    P_800753DC screen;
    Vec pos;
    f32 m;
    f32 a;
    f32 b;
    u32 alpha;
    if (0.0f == this->m_b4) return;
    VecCopy(&pos, &this->position);
    pos.y += 14.0f;
    if (TObjTombstone::project_to_screen(this, &screen.x, &pos) == 0) return;
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
        P_800753DC p = screen;
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

s32 TObjTombstone::project_to_screen(void *arg0, f32 *arg1, Vec *arg2) {
    Vec d;
    Vec v = { 0.0f, 0.0f, -1.0f };
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, camera_ctrl_instance->f194);
    rotate_matrix_x(0, camera_ctrl_instance->f190);
    rotate_matrix_z(0, camera_ctrl_instance->f198);
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrix();
    VecCopy(&d, arg2);
    subtract_vector(&d, &camera_ctrl_instance->pos);
    if (vec3_dot(&v, &d) <= 0.0f) {
        return 0;
    }
    push_matrix();
    project_world_to_screen(0, arg2, arg1);
    pop_matrix();
    if (is_split_screen() != 0) {
        arg1[0] -= (f32)get_screen_height__11TCameraCtrlFv();
        arg1[0] /= TCameraCtrl::get_view_scale();
        arg1[1] -= (f32)get_screen_width__11TCameraCtrlFv();
        arg1[1] /= TCameraCtrl::get_fov();
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
    TObjTombstone__base_matrix.copy_matrix(rates.count);
}

void TObjTombstoneDropRates::copy_matrix(f32 *src) {
    count[0] = src[0];
    count[1] = src[1];
    count[2] = src[2];
    count[3] = src[3];
    kind[0] = src[4];
    kind[1] = src[5];
    kind[2] = src[6];
    kind[3] = src[7];
    kind[4] = src[8];
    kind[5] = src[9];
}

// Sets the drop rates (inferred: called by qst_op_set_cmode_grave_rates), unless
// a weight is negative or a group adds up to more than 1.
extern "C" void TObjTombstone__sub_80074E74(f32 *w) {
    f32 one;
    f32 sum;

    sum = w[0] + w[1 & 0xFFu] + w[2] + w[3];
    if (w[0] < 0.0f || w[1] < 0.0f || w[2] < 0.0f || w[3] < 0.0f || sum > 1.0f) {
        return;
    }
    sum = w[4] + w[5] + w[6] + w[7] + w[8] + w[9];
    one = 1.0f;
    if (w[4] < 0.0f || w[5] < 0.0f || w[6] < 0.0f || w[7] < 0.0f || w[8] < 0.0f || w[9] < 0.0f ||
        sum > one) {
        return;
    }
    TObjTombstone__base_matrix.copy_matrix(w);
}

void TLobby::reset_tombstone_values() {
    s32 i;
    for (i = 0; i < 4; i++) {
        tombstone_position_table[i].y = -10000.0f;
    }
}

extern "C" {
void fn_80074E04(s32 i, Vec *pos) {
    if (i < 0 || i >= 4) {
        return;
    }
    VecCopy(&tombstone_position_table[i], pos);
}
}
