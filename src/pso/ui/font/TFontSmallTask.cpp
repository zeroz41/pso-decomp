#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/vector.h"
#include "pso/ui/font/TFontSmallTask.h"
#include "pso/enemy/epsilon/TObjEneEpsilonGuard.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/dubchik/TOCtrlDubchik.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include <string.h>
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/unk/TLobby_800F8AA8.h"
#include "pso/object/base/TObjBase.h"
const char *TFontSmallTask__name = "TFontSmallTask";

struct TFontSmallTask_800FD4D4 {
    const char *f0;
    u8 pad4[0x18 - 4];
    void *vt;
    Vec pos;
    f32 ofs_x;
    f32 ofs_y;
    f32 width;
    char text[0x10];
    u32 rgb;
    s32 f48;
    s32 life;
    s32 delay;
    s16 f54;
    u16 view;
};
extern "C" {
TFontSmallTask_800FD4D4 *__ct__14TFontSmallTaskFv(TFontSmallTask_800FD4D4 *self, Vec *pos, u32 color, s32 life, s32 delay, const char *text, u16 view);
}

static const Vec font_small_forward_vec = {0.0f, 0.0f, -1.0f};
extern "C" {
void TBoss3Volopt__sub_800FD344(s32 arg0, s32 arg1, s32 arg2, void *arg3, void *arg4);
s32 create_font_small_task(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 arg5, s32 arg6);
s32 create_font_small_task_default_color(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 arg5);
void fn_800FCCC8(saddr arg0, s32 arg1);
s32 fn_800FCCF4(void* p);

void fn_800FCCC8(saddr arg0, s32 card_status_bits) {
    TWindowKeyBoardHard::set_card_window_flags((void *)arg0, (s32)(card_status_bits << 0xD), (s32)0xFFFF1FFF);
}
s32 fn_800FCCF4(void* p) { return *(s32*)((char*)p + 0x874); }
}
f32 calc_small_font_scale(void);
void text_builder_reset(void);


f32 calc_small_font_scale(void) {
    f32 view_scale;
    view_scale = TCameraCtrl::get_view_scale();
    if (view_scale >= 1.0) {
        return 1.4f;
    }
    return 1.0f / view_scale;
}

struct Quad_800FCD40 { f32 x, y, right, bottom, u, v, u2, v2; };
extern "C" {

void rotate_matrix_y(int, s32);
void rotate_matrix_x(int, s32);
void rotate_matrix_z(int, s32);
void rotate_vector_by_matrix(int, Vec *, Vec *);
f32 vec3_dot(Vec *, Vec *);
void project_world_to_screen(int, f32 *, f32 *);
s32 is_split_screen(void);
void begin_screen_draw(int);
void set_draw_texture_and_color(int, u32);
void build_small_font_glyph_quad(u8, Quad_800FCD40 *);
void draw_textured_quad_at_depth(Quad_800FCD40 *, f32);
u8 get_small_font_glyph_width(u8);
}
extern u8 identity_matrix[];

#pragma push
#pragma fp_contract on
void TFontSmallTask::render() {
    Vec forward = font_small_forward_vec;
    Vec diff;
    f32 screen[2];
    Quad_800FCD40 q;
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
    diff.x = position[0] - camera_ctrl_instance->pos.x;
    diff.y = position[1] - camera_ctrl_instance->pos.y;
    diff.z = position[2] - camera_ctrl_instance->pos.z;
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
    project_world_to_screen(0, position, screen);
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
        TCameraCtrl::get_camera_no();
        f32 sc = TWindowCtrlMain::get_scale();
        depth = -1.0f / (0.1495f + sc);
    }
    cursor = text;
    reveal = (f32)age;
    if (reveal > (f32)lifetime - 8.0f) {
        fade = 0.125f * ((f32)lifetime - reveal);
    } else {
        fade = 1.0f;
    }
    scale = ((f32 (*)(void *))calc_small_font_scale)(this);
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
        draw_textured_quad_at_depth(&q, depth);
        adv = (f32)(u8)get_small_font_glyph_width(c);
        x = adv * scale + x;
        reveal = reveal - 5.5f * (adv / text_width);
    }
    TWindowSubStatusDisp::get_player();
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

s32 create_font_small_task(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *str, s32 arg5, s32 arg6) {
    s32 var_r31;

    text_builder_reset();
    text_builder_append((u8 *)str);
    if (arg5 >= 0) {
        text_builder_append((u8 *)"+");
    }
    text_builder_append_int(arg5);
    var_r31 = (saddr)TObject::operator new(0x58);
    if (var_r31 != 0) {
        var_r31 = ((s32 (*)(s32, s32, s32, s32, s32, s32, s32))__ct__14TFontSmallTaskFv)(var_r31, arg0, arg1, arg2, arg3, (saddr)(get_shared_text_buffer()), arg6);
    }
    return var_r31;
}

s32 create_font_small_task_default_color(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *str, s32 arg5) {
    s32 var_r31;

    text_builder_reset();
    text_builder_append((u8 *)str);
    if (arg5 >= 0) {
        text_builder_append((u8 *)"+");
    }
    text_builder_append_int(arg5);
    var_r31 = (saddr)TObject::operator new(0x58);
    if (var_r31 != 0) {
        var_r31 = ((s32 (*)(s32, s32, s32, s32, s32, s32, s32))__ct__14TFontSmallTaskFv)(var_r31, arg0, arg1, arg2, arg3, (saddr)(get_shared_text_buffer()), 0xFFFF);
    }
    return var_r31;
}

void TBoss3Volopt__sub_800FD344(s32 arg0, s32 arg1, s32 arg2, void *str, void *arg4) {
    create_font_small_task((s32)arg0, (s32)arg1, (s32)arg2, 0, (s32 *)str, (saddr)arg4, 0xFFFF);
}

s32 TObjEneEpsilonGuard::create_damage_font(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_r31;

    text_builder_reset();
    text_builder_append_int(arg3);
    var_r31 = (saddr)TObject::operator new(0x58);
    if (var_r31 != 0) {
        var_r31 = ((s32 (*)(s32, s32, s32, s32, s32, s32, s32))__ct__14TFontSmallTaskFv)(var_r31, arg0, arg1, arg2, 0, (saddr)get_shared_text_buffer(), 0xFFFF);
    }
    return var_r31;
}

saddr TOCtrlDubchik::create_font(saddr pos, s32 color, s32 life, const char *text) {
    saddr task;

    text_builder_reset();
    text_builder_append((u8 *)text);
    task = (saddr)TObject::operator new(0x58);
    if (task != 0) {
        task = ((saddr (*)(saddr, saddr, s32, s32, s32, saddr, s32))__ct__14TFontSmallTaskFv)(task, pos, color, life, 0, (saddr)get_shared_text_buffer(), 0xFFFF);
    }
    return task;
}

TFontSmallTask::~TFontSmallTask() {}

struct Ent_800FD6A0 { u32 id; void (*fn)(void); };

struct Ent_800FD6F8 { void (*fn)(void); u32 id; };

LeaderSelection leader_selection;
extern "C" {
void call_funcs_reverse__6TLobbyFPvUi(Ent_800FD6A0 *arr, u32 size);
s32 run_load_callback_table(Ent_800FD6F8 *p, u32 size);
void __ct__7TObjectFP7TObject(void *, void *);
}
u32 calc_small_font_text_width(const char *s);
extern u8 __vt__14TFontSmallTask[];

#pragma push
#pragma fp_contract on

TFontSmallTask_800FD4D4 *__ct__14TFontSmallTaskFv(TFontSmallTask_800FD4D4 *self, Vec *pos, u32 color, s32 life, s32 delay, const char *text, u16 view) {
    __ct__7TObjectFP7TObject(self, (void *)TWindowCtrlMain::get_instance());
    self->vt = __vt__14TFontSmallTask;
    self->f0 = TFontSmallTask__name;
    VecCopy((Vec *)&self->pos, (const Vec *)pos);
    self->ofs_x = 0.0f;
    self->ofs_y = 0.0f;
    self->rgb = color & 0xFFFFFF;
    self->f48 = 0;
    self->life = life;
    self->delay = delay;
    self->f54 = 0;
    self->view = view;
    if (self->view >= 4) {
        self->view = 0xFFFF;
    }
    ((TObject *)self)->disallow_rendering();
    strncpy(self->text, text, 0xF);
    self->text[0xF] = 0;
    self->width = calc_small_font_text_width(self->text);
    self->ofs_x -= 0.5f * self->width * ((f32 (*)(void *))calc_small_font_scale)(self);
    return self;
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
            section_id = ((TPlyPhotonChair *)player)->get_actor_section_id();
        }
    }
}

void call_funcs_reverse__6TLobbyFPvUi(Ent_800FD6A0 *arr, u32 size) {
    s32 n = size / sizeof(Ent_800FD6A0);
    Ent_800FD6A0 *p = arr + n;
    while (n > 0) {
        p--;
        if (p->fn != NULL) {
            p->fn();
        }
        n--;
    }
}

s32 run_load_callback_table(Ent_800FD6F8 *p, u32 size) {
    s32 n = size / sizeof(Ent_800FD6F8);
    while (n > 0) {
        if (is_area_transfer_pending() != 0) {
            return 0;
        }
        if (p->fn != NULL) {
            p->fn();
        }
        p++;
        n--;
    }
    return 1;
}

