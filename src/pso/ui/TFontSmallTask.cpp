#include "types.h"
#include "pso/system/vector.h"
#include "pso/TFontSmallTask.h"
#include "pso/enemy/TObjEneEpsilonGuard.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOCtrlDubchik.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowKeyBoardHard.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/map/FloorArea.h"

struct Vec_800FD4D4 {
    f32 x, y, z;
};

struct TFontSmallTask_800FD4D4 {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vt;
    Vec_800FD4D4 pos;
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
TFontSmallTask_800FD4D4 *__ct__14TFontSmallTaskFv(TFontSmallTask_800FD4D4 *self, Vec_800FD4D4 *pos, u32 color, s32 life, s32 delay, const char *text, u16 view);
}

struct Vec_800FCD40 { f32 x, y, z; };
static const Vec_800FCD40 font_small_forward_vec = {0.0f, 0.0f, -1.0f};
extern "C" {
void allow_rendering__7TObjectFv(TObject *arg0);
void disallow_rendering__7TObjectFv(TObject *arg0);
void queue_destruction__7TObjectFv(void *arg0);
void TBoss3Volopt__sub_800FD344(s32 arg0, s32 arg1, s32 arg2, void *arg3, void *arg4);
s32 create_font_small_task(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 arg5, s32 arg6);
s32 create_font_small_task_default_color(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 arg5);
void fn_800FCCC8(s32 arg0, s32 arg1);
s32 fn_800FCCF4(void* p);
s32 *get_shared_text_buffer(void);
void TWindowSubStatusDisp__sub_80228F5C(s32 arg0);
void text_builder_append(u8 *str);
s32 __nw__7TObjectFUl(s32);

void fn_800FCCC8(s32 arg0, s32 arg1) {
    TWindowKeyBoardHard::set_card_window_flags((void *)arg0, (s32)(arg1 << 0xD), (s32)0xFFFF1FFF);
}
s32 fn_800FCCF4(void* p) { return *(s32*)((char*)p + 0x874); }
}
extern const f32 lbl_805DAA30;
extern const f32 lbl_805DAA00;
extern const f32 lbl_805DAA04;
f32 calc_small_font_scale(void);
void text_builder_reset(void);

extern s32 lbl_805DAA34;

f32 calc_small_font_scale(void) {
    f32 view_scale;
    view_scale = TCameraCtrl::get_view_scale();
    if (view_scale >= 1.0) {
        return lbl_805DAA00;
    }
    return lbl_805DAA04 / view_scale;
}

struct Quad_800FCD40 { f32 x, y, right, bottom, u, v, u2, v2; };
extern "C" {

void push_matrix_from(void *);
void rotate_matrix_y(int, s32);
void rotate_matrix_x(int, s32);
void rotate_matrix_z(int, s32);
void rotate_vector_by_matrix(int, Vec_800FCD40 *, Vec_800FCD40 *);
void pop_matrix(void);
f32 vec3_dot(Vec_800FCD40 *, Vec_800FCD40 *);
void push_matrix(void);
void project_world_to_screen(int, f32 *, f32 *);
s32 is_split_screen(void);
s32 get_screen_height__11TCameraCtrlFv(void);
s32 get_screen_width__11TCameraCtrlFv(void);
f32 get_scale__15TWindowCtrlMainFv(s32);
void begin_screen_draw(int);
void render_forward__20TWindowSubStatusDispFPv(void);
void set_draw_texture_and_color(int, u32);
void build_small_font_glyph_quad(u8, Quad_800FCD40 *);
void draw_textured_quad_at_depth(Quad_800FCD40 *, f32);
u8 get_small_font_glyph_width(u8);
}
extern u8 identity_matrix[];
extern u8 *camera_ctrl_instance;
extern const f32 lbl_805DAA08;
extern const f32 lbl_805DAA0C;
extern const f32 lbl_805DAA10;
extern const f32 lbl_805DAA14;
extern const f32 lbl_805DAA18;
extern const f32 lbl_805DAA1C;
extern const f32 lbl_805DAA20;
extern const f32 lbl_805DAA24;
extern const f32 lbl_805DAA28;
extern const f32 lbl_805DAA2C;

#pragma push
#pragma fp_contract on
void TFontSmallTask::render() {
    Vec_800FCD40 forward = font_small_forward_vec;
    Vec_800FCD40 diff;
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
    rotate_matrix_y(0, *(s32 *)(camera_ctrl_instance + 0x194));
    rotate_matrix_x(0, *(s32 *)(camera_ctrl_instance + 0x190));
    rotate_matrix_z(0, *(s32 *)(camera_ctrl_instance + 0x198));
    rotate_vector_by_matrix(0, &forward, &forward);
    pop_matrix();
    diff.x = position[0] - *(f32 *)(camera_ctrl_instance + 0x178);
    diff.y = position[1] - *(f32 *)(camera_ctrl_instance + 0x17C);
    diff.z = position[2] - *(f32 *)(camera_ctrl_instance + 0x180);
    if (is_boss_area() == 0) {
        f32 xx = diff.x * diff.x;
        f32 yy = diff.y * diff.y;
        f32 zz = diff.z * diff.z;
        if (zz + (xx + yy) > lbl_805DAA08) {
            return;
        }
    }
    if (vec3_dot(&forward, &diff) <= lbl_805DAA0C) {
        return;
    }
    push_matrix();
    project_world_to_screen(0, position, screen);
    pop_matrix();
    if (is_split_screen() != 0) {
        screen[0] -= (f32)get_screen_height__11TCameraCtrlFv();
        screen[0] /= TCameraCtrl::get_view_scale();
        screen[1] -= (f32)get_screen_width__11TCameraCtrlFv();
        screen[1] /= TCameraCtrl::get_fov();
    }
    x = screen[0] += offset_x;
    y = screen[1] += offset_y;
    {
        f32 sc = get_scale__15TWindowCtrlMainFv(TCameraCtrl::get_camera_no());
        depth = lbl_805DAA10 / (lbl_805DAA14 + sc);
    }
    cursor = text;
    reveal = (f32)age;
    if (reveal > (f32)lifetime - lbl_805DAA1C) {
        fade = lbl_805DAA18 * ((f32)lifetime - reveal);
    } else {
        fade = lbl_805DAA04;
    }
    scale = ((f32 (*)(void *))calc_small_font_scale)(this);
    begin_screen_draw(1);
    render_forward__20TWindowSubStatusDispFPv();
    while (*cursor != 0) {
        u8 c = *cursor++;
        u32 alpha;
        f32 adv;
        if (reveal <= lbl_805DAA0C) {
            continue;
        }
        if (reveal < lbl_805DAA28) {
            alpha = lbl_805DAA20 * (lbl_805DAA24 * reveal);
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
        reveal = reveal - lbl_805DAA2C * (adv / text_width);
    }
    TWindowSubStatusDisp::get_player();
}
#pragma pop

void TFontSmallTask::run_task() {
    switch (active) {
    case 0:
        if (--delay < 0) {
            active = 1;
            allow_rendering__7TObjectFv(this);
        }
        break;
    default:
        offset_y += lbl_805DAA30;
        if (++age >= lifetime) {
            disallow_rendering__7TObjectFv(this);
            queue_destruction__7TObjectFv(this);
        }
        break;
    }
}

s32 create_font_small_task(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 arg5, s32 arg6) {
    s32 var_r31;

    text_builder_reset();
    text_builder_append((u8 *)arg4);
    if (arg5 >= 0) {
        text_builder_append((u8 *)&lbl_805DAA34);
    }
    TWindowSubStatusDisp__sub_80228F5C(arg5);
    var_r31 = __nw__7TObjectFUl(0x58);
    if (var_r31 != 0) {
        var_r31 = ((s32 (*)(s32, s32, s32, s32, s32, s32, s32))__ct__14TFontSmallTaskFv)(var_r31, arg0, arg1, arg2, arg3, (s32)(get_shared_text_buffer()), arg6);
    }
    return var_r31;
}

s32 create_font_small_task_default_color(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 arg5) {
    s32 var_r31;

    text_builder_reset();
    text_builder_append((u8 *)arg4);
    if (arg5 >= 0) {
        text_builder_append((u8 *)&lbl_805DAA34);
    }
    TWindowSubStatusDisp__sub_80228F5C(arg5);
    var_r31 = __nw__7TObjectFUl(0x58);
    if (var_r31 != 0) {
        var_r31 = ((s32 (*)(s32, s32, s32, s32, s32, s32, s32))__ct__14TFontSmallTaskFv)(var_r31, arg0, arg1, arg2, arg3, (s32)(get_shared_text_buffer()), 0xFFFF);
    }
    return var_r31;
}

void TBoss3Volopt__sub_800FD344(s32 arg0, s32 arg1, s32 arg2, void *arg3, void *arg4) {
    create_font_small_task((s32)arg0, (s32)arg1, (s32)arg2, 0, (s32 *)arg3, (s32)arg4, 0xFFFF);
}

s32 TObjEneEpsilonGuard::create_damage_font(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_r31;

    text_builder_reset();
    TWindowSubStatusDisp__sub_80228F5C(arg3);
    var_r31 = __nw__7TObjectFUl(0x58);
    if (var_r31 != 0) {
        var_r31 = ((s32 (*)(s32, s32, s32, s32, s32, s32, s32))__ct__14TFontSmallTaskFv)(var_r31, arg0, arg1, arg2, 0, (s32)get_shared_text_buffer(), 0xFFFF);
    }
    return var_r31;
}

s32 TOCtrlDubchik::create_font(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_r31;

    text_builder_reset();
    text_builder_append((u8 *)arg3);
    var_r31 = __nw__7TObjectFUl(0x58);
    if (var_r31 != 0) {
        var_r31 = ((s32 (*)(s32, s32, s32, s32, s32, s32, s32))__ct__14TFontSmallTaskFv)(var_r31, arg0, arg1, arg2, 0, (s32)get_shared_text_buffer(), 0xFFFF);
    }
    return var_r31;
}

TFontSmallTask::~TFontSmallTask() {}

struct RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270 {
    s32 value;
    u8 remaining[0xAC];
};

struct RecoveredGlobal_8000F7FC_lbl_80515F48 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_8000F9E4_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F90C_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F9CC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F8FC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F8EC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F91C_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct Ent_800FD6A0 { u32 id; void (*fn)(void); };

struct Ent_800FD6F8 { void (*fn)(void); u32 id; };

struct VBase_800FD614 { u8 pad[0x18]; };

struct VObj_800FD614 : VBase_800FD614 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual s32 m14();
};

struct Out_800FD614 { s32 a; s32 b; };

void reset_leader_selection(void* p);
extern RecoveredGlobal_8000F7FC_lbl_80515F48 TLobby__data_805011D8;
extern "C" {
void call_funcs_reverse__6TLobbyFPvUi(Ent_800FD6A0 *arr, u32 size);
s32 is_area_transfer_pending(void);
s32 run_load_callback_table(Ent_800FD6F8 *p, u32 size);
int get_player_data__10TObjPlayerFi(int a0);
u16 get_entity_id();
s32 get_actor_section_id__15TPlyPhotonChairFv(void *);
void find_leader_section_id(struct Out_800FD614 *out, s32 arg1);
void *get_instance__15TWindowCtrlMainFv(void);
void __ct__7TObjectFP7TObject(void *, void *);
char *strncpy(char *, const char *, u32);
}
u32 calc_small_font_text_width(const char *s);
extern u8 __vt__14TFontSmallTask[];
extern s32 TFontSmallTask__name;
void set_world_section_id(void* p, s32 v);

#pragma push
#pragma fp_contract on

TFontSmallTask_800FD4D4 *__ct__14TFontSmallTaskFv(TFontSmallTask_800FD4D4 *self, Vec_800FD4D4 *pos, u32 color, s32 life, s32 delay, const char *text, u16 view) {
    __ct__7TObjectFP7TObject(self, get_instance__15TWindowCtrlMainFv());
    self->vt = __vt__14TFontSmallTask;
    self->f0 = TFontSmallTask__name;
    VecCopy((Vec *)&self->pos, (const Vec *)pos);
    self->ofs_x = lbl_805DAA0C;
    self->ofs_y = lbl_805DAA0C;
    self->rgb = color & 0xFFFFFF;
    self->f48 = 0;
    self->life = life;
    self->delay = delay;
    self->f54 = 0;
    self->view = view;
    if (self->view >= 4) {
        self->view = 0xFFFF;
    }
    disallow_rendering__7TObjectFv((TObject *)self);
    strncpy(self->text, text, 0xF);
    self->text[0xF] = 0;
    self->width = calc_small_font_text_width(self->text);
    self->ofs_x -= lbl_805DAA20 * self->width * ((f32 (*)(void *))calc_small_font_scale)(self);
    return self;
}
#pragma pop

void set_world_section_id(void* p, s32 v) { *(s32*)((char*)p + 0x4) = v; }
s32 TFontSmallTask::get_task_id() { return *(s32 *)&this->m_flags; }
void reset_leader_selection(void* p) { *(s32*)((char*)p + 0x0) = 0; *(s32*)((char*)p + 0x4) = 0; }
typedef char RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270_size[sizeof(RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270) == 0xB0 ? 1 : -1];
typedef char RecoveredGlobal_8000F7FC_lbl_80515F48_size[sizeof(RecoveredGlobal_8000F7FC_lbl_80515F48) == 0x28 ? 1 : -1];

void find_leader_section_id(struct Out_800FD614 *out, s32 arg1) {
    s32 n;
    s32 i;
    VObj_800FD614 *p;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = (VObj_800FD614 *)get_player_data__10TObjPlayerFi(i);
        if (p != NULL && arg1 == get_entity_id()) {
            out->a = p->m14();
            out->b = get_actor_section_id__15TPlyPhotonChairFv(p);
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

void TLobby::reset_leader_selection_static() {
    reset_leader_selection(&TLobby__data_805011D8.value);
}
typedef char RecoveredGlobal_8000F90C_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F90C_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F8FC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F8FC_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F8EC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F8EC_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F91C_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F91C_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F9E4_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F9E4_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F9CC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F9CC_lbl_804FE120) == 0x18 ? 1 : -1];

__declspec(section ".ctors") static void *const __sinit_TFontSmallTask_cpp_ref = (void *)TLobby::reset_leader_selection_static;
