#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/vector.h"
#include "pso/ui/font/TFontSmallTask.h"
#include "pso/enemy/epsilon/TObjEneEpsilonGuard.h"
#include "pso/network/TLobby.h"
#include "pso/enemy/dubchik/TOCtrlDubchik.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include <string.h>
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/enemy/BattleParamTables.h"
#include "pso/ui/window/TextBuilder.h"
#include "pso/system/MallocLoadFilePrc.h"
#include "pso/object/base/TObjBase.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixReflect.h"
#include "pso/math/MatrixVector.h"
#include "pso/render/DebugFont.h"
#include "pso/system/MatrixStack.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/SmallFontText.h"
#include "pso/map/area/AreaScene.h"
const char *font_small_task_class_name = "TFontSmallTask";

static const Vec font_small_forward_vec = {0.0f, 0.0f, -1.0f};

void update_card_window_flags(saddr client_id, s32 card_status_bits) {
    TWindowKeyBoardHard::set_card_window_flags(client_id, (s32)(card_status_bits << 0xD), (s32)0xFFFF1FFF);
}
s32 get_player_status_color(TObjPlayer *player) { return player->appearance.nameColor; }

f32 TFontSmallTask::calc_font_scale() {
    f32 view_scale;
    view_scale = TCameraCtrl::get_view_scale();
    if (view_scale >= 1.0) {
        return 1.4f;
    }
    return 1.0f / view_scale;
}

#pragma push
#pragma fp_contract on
void TFontSmallTask::render() {
    Vec forward = font_small_forward_vec;
    Vec diff;
    f32 screen[2];
    GlyphQuad q;
    f32 depth;
    f32 y;
    f32 x;
    f32 reveal;
    f32 fade;
    f32 scale;
    char *cursor;

    if (active == 0) {
        return;
    }
    if (view != 0xFFFF) {
        s32 cam = (u16)TCameraCtrl::get_nth_view_player_id(TCameraCtrl::get_camera_no());
        if (cam != view) {
            return;
        }
    }
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, camera_ctrl_instance->yaw);
    rotate_matrix_x(0, camera_ctrl_instance->pitch);
    rotate_matrix_z(0, camera_ctrl_instance->roll);
    rotate_vector_by_matrix(0, &forward, &forward);
    pop_matrix();
    diff.x = position.x - camera_ctrl_instance->pos.x;
    diff.y = position.y - camera_ctrl_instance->pos.y;
    diff.z = position.z - camera_ctrl_instance->pos.z;
    if (is_boss_area() == 0) {
        f32 xx = diff.x * diff.x;
        f32 yy = diff.y * diff.y;
        f32 zz = diff.z * diff.z;
        if (zz + (xx + yy) > 122500.0f) {
            return;
        }
    }
    if (vec3_dot(&forward, &diff) <= 0.0f) {
        return;
    }
    push_matrix();
    project_world_to_screen(0, &position, screen);
    pop_matrix();
    if (is_split_screen() != 0) {
        screen[0] -= (f32)TCameraCtrl::get_viewport_x();
        screen[0] /= TCameraCtrl::get_view_scale();
        screen[1] -= (f32)TCameraCtrl::get_viewport_y();
        screen[1] /= TCameraCtrl::get_fov();
    }
    x = screen[0] += offset_x;
    y = screen[1] += offset_y;
    {
        f32 sc = TWindowCtrlMain::get_scale(TCameraCtrl::get_camera_no());
        depth = -1.0f / (0.1495f + sc);
    }
    cursor = text;
    reveal = (f32)age;
    if (reveal > (f32)lifetime - 8.0f) {
        fade = 0.125f * ((f32)lifetime - reveal);
    } else {
        fade = 1.0f;
    }
    scale = calc_font_scale();
    begin_screen_draw(1);
    TWindowSubStatusDisp::render_forward();
    while (*cursor != 0) {
        u8 c = *cursor++;
        u32 alpha;
        f32 adv;
        if (reveal <= 0.0f) {
            continue;
        }
        if (reveal < 2.0f) {
            alpha = 0.5f * (255.0f * reveal);
        } else {
            alpha = 0xFF;
        }
        alpha = (f32)alpha * fade;
        set_draw_texture_and_color(0, (alpha << 24) | rgb);
        q.x = x;
        q.y = y;
        build_small_font_glyph_quad(c, &q);
        q.right = scale * (q.right - x) + x;
        q.bottom = scale * (q.bottom - y) + y;
        draw_textured_quad_at_depth((f32 *)&q, depth);
        adv = (f32)(u8)get_small_font_glyph_width(c);
        x = adv * scale + x;
        reveal = reveal - 5.5f * (adv / text_width);
    }
    end_screen_draw();
}
#pragma pop

void TFontSmallTask::run_task() {
    switch (active) {
    case 0:
        if (--delay < 0) {
            active = 1;
            allow_rendering();
        }
        break;
    default:
        offset_y += -1.4f;
        if (++age >= lifetime) {
            disallow_rendering();
            queue_destruction();
        }
        break;
    }
}

s32 create_font_small_task(Vec *pos, s32 color, s32 life, s32 delay, const char *str, s32 value, u16 view) {
    text_builder_reset();
    text_builder_append(str);
    if (value >= 0) {
        text_builder_append("+");
    }
    text_builder_append_int(value);
    return (saddr)new TFontSmallTask(pos, color, life, delay, get_shared_text_buffer(), view);
}

s32 create_font_small_task_default_color(Vec *pos, s32 color, s32 life, s32 delay, const char *str, s32 value) {
    text_builder_reset();
    text_builder_append(str);
    if (value >= 0) {
        text_builder_append("+");
    }
    text_builder_append_int(value);
    return (saddr)new TFontSmallTask(pos, color, life, delay, get_shared_text_buffer(), 0xFFFF);
}

void create_boss_health_font(Vec *pos, s32 color, s32 life, const char *label, s32 value) {
    create_font_small_task(pos, color, life, 0, label, value, 0xFFFF);
}

s32 TObjEneEpsilonGuard::create_damage_font(s32 pos, s32 color, s32 life, s32 damage) {
    text_builder_reset();
    text_builder_append_int(damage);
    return (saddr)new TFontSmallTask((Vec *)(saddr)pos, color, life, 0, get_shared_text_buffer(), 0xFFFF);
}

TFontSmallTask *TOCtrlDubchik::create_font(Vec *pos, s32 color, s32 life, const char *text) {
    text_builder_reset();
    text_builder_append(text);
    return new TFontSmallTask(pos, color, life, 0, get_shared_text_buffer(), 0xFFFF);
}

TFontSmallTask::~TFontSmallTask() {}

LeaderSelection leader_selection;

#pragma push
#pragma fp_contract on

TFontSmallTask::TFontSmallTask(Vec *pos, u32 color, s32 life, s32 delay, const char *str, u16 view)
    : TObject((TObject *)TWindowCtrlMain::get_instance()) {
    m_name = font_small_task_class_name;
    VecCopy(&position, pos);
    offset_x = 0.0f;
    offset_y = 0.0f;
    rgb = color & 0xFFFFFF;
    age = 0;
    lifetime = life;
    this->delay = delay;
    active = 0;
    this->view = view;
    if (this->view >= 4) {
        this->view = 0xFFFF;
    }
    disallow_rendering();
    strncpy(text, str, 0xF);
    text[0xF] = 0;
    text_width = calc_small_font_text_width(text);
    offset_x -= 0.5f * text_width * calc_font_scale();
}
#pragma pop

void LeaderSelection::set_section_id(s32 id) { section_id = id; }
s32 LeaderSelection::get_section_id() { return section_id; }
LeaderSelection::LeaderSelection() {
    level = 0;
    section_id = 0;
}

void LeaderSelection::find_leader_section_id(s32 client_id) {
    s32 count;
    s32 i;
    TObjPlayer *player;
    count = TLobby::get_game_mode();
    for (i = 0; i < count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player != NULL && client_id == player->get_entity_id()) {
            level = player->get_actor_level_index();
            section_id = player->get_section_id();
        }
    }
}

void call_funcs_reverse(void *table, unsigned int size) {
    s32 n = size / sizeof(LobbyFrameEntry);
    LobbyFrameEntry *p = (LobbyFrameEntry *)table + n;
    while (n > 0) {
        p--;
        if (p->fn != NULL) {
            p->fn();
        }
        n--;
    }
}

s32 run_load_callback_table(void *table, u32 size) {
    s32 n = size / sizeof(LoadFrameEntry);
    while (n > 0) {
        if (is_area_transfer_pending() != 0) {
            return 0;
        }
        LoadFrameEntry *entry = static_cast<LoadFrameEntry *>(table);
        if (entry->fn != NULL) {
            entry->fn();
        }
        table = entry + 1;
        n--;
    }
    return 1;
}
