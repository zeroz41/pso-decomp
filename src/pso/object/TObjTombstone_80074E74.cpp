#include "types.h"
#include "pso/system/vector.h"
#include "pso/object/TObjTombstone.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TWindowSubStatusDisp.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_28 { u8 bytes[0x28]; };

struct RecoveredGlobal_80074FAC_lbl_8043878C {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_80074FAC_TObjTombstone__data_8048D250 {
    s32 value;
    u8 remaining[0x24];
};

struct V_80075070 { f32 x, y, z; };

struct Obj_80075070 {
    u8 pad0[0x38];
    V_80075070 pos;
    u8 pad44[0xAC - 0x44];
    s32 fac;
};

struct V_800751BC { f32 x, y, z; };

struct View_800751BC {
    u8 pad0[0x178];
    V_800751BC pos;
    u8 pad184[0xC];
    s32 f190;
    s32 f194;
    s32 f198;
};

struct V_800753DC { f32 x, y, z; };

struct P_800753DC { f32 x, y; };

struct Off_800753DC { s16 x, y; };

struct Obj_800753DC {
    u8 pad0[0x38];
    V_800753DC pos;
    u8 pad44[0xB4 - 0x44];
    f32 scale;
    f32 alphaA;
    f32 alphaB;
    u8 padC0[0x110 - 0xC0];
    char names[6][0x30];
    s32 timer;
};

extern "C" {
u16 get_nth_view_player_id__11TCameraCtrlFl();
void *get_player_by_client_id(s32 i);
f32 xyz_distance(void *, void *);
extern const f32 TObjTombstone__data_805D9174;
extern f32 TObjTombstone__data_805D9178;
extern f32 TObjTombstone__data_805D917C;
extern const f32 lbl_805D9180;
extern f32 TObjTombstone__data_805D9184;
extern RecoveredGlobal_80074FAC_lbl_8043878C tombstone_reset_matrix_template;
extern RecoveredGlobal_80074FAC_TObjTombstone__data_8048D250 TObjTombstone__base_matrix;
f32 vector_length(void *);
void subtract_vector(void *, void *);
extern V_80075070 tombstone_position_table[];
extern s32 local_client_id;
extern const f32 lbl_805D9170;
s32 is_split_screen();
s32 get_screen_width__11TCameraCtrlFv();
s32 get_screen_height__11TCameraCtrlFv();
f32 vec3_dot(void *, void *);
void project_world_to_screen(s32, void *, void *);
void rotate_vector_by_matrix(s32, void *, void *);
void rotate_matrix_y(s32, s32);
void rotate_matrix_z(s32, s32);
void rotate_matrix_x(s32, s32);
void push_matrix_from(void *);
void push_matrix();
void pop_matrix();
extern V_800751BC lbl_80438780;
extern u8 identity_matrix[];
extern View_800751BC *camera_ctrl_instance;
u32 calc_text_width(const char *);
void draw_menu_font_string(const char *, u32, s32, f32, f32, f32);
f32 sin_table_lookup(s32);
u32 strlen(const char *);
s32 is_challenge_mode_active();
s32 get_current_floor();
s32 is_flag_set__6TLobbyFv();

void TObjTombstone__sub_80074E74(f32 *w) {
    f32 one;
    f32 sum;

    sum = w[0] + w[1 & 0xFFu] + w[2] + w[3];
    if (w[0] < TObjTombstone__data_805D9174 || w[1] < TObjTombstone__data_805D9174 ||
        w[2] < TObjTombstone__data_805D9174 || w[3] < TObjTombstone__data_805D9174 ||
        sum > TObjTombstone__data_805D9178) {
        return;
    }
    sum = w[4] + w[5] + w[6] + w[7] + w[8] + w[9];
    one = TObjTombstone__data_805D9178;
    if (w[4] < TObjTombstone__data_805D9174 || w[5] < TObjTombstone__data_805D9174 ||
        w[6] < TObjTombstone__data_805D9174 || w[7] < TObjTombstone__data_805D9174 ||
        w[8] < TObjTombstone__data_805D9174 || w[9] < TObjTombstone__data_805D9174 ||
        sum > one) {
        return;
    }
    ((TObjTombstone *)(&TObjTombstone__base_matrix.value))->copy_matrix(w);
}

void TObjTombstone::copy_matrix(void* q) { *(f32 *)&this->m_name = *(f32*)((char*)q + 0x0); *(f32 *)&this->m_flags = *(f32*)((char*)q + 0x4); *(f32 *)&this->m_prev = *(f32*)((char*)q + 0x8); *(f32 *)&this->m_next = *(f32*)((char*)q + 0xc); *(f32 *)&this->m_up = *(f32*)((char*)q + 0x10); *(f32 *)&this->m_down = *(f32*)((char*)q + 0x14); *(f32*)((char*)this + 0x18) = *(f32*)((char*)q + 0x18); *(f32 *)&this->entity_id = *(f32*)((char*)q + 0x1c); *(f32 *)&this->m_20 = *(f32*)((char*)q + 0x20); *(f32 *)&this->texlist = *(f32*)((char*)q + 0x24); }

typedef char RecoveredGlobal_80074FAC_lbl_8043878C_size[sizeof(RecoveredGlobal_80074FAC_lbl_8043878C) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_80074FAC_TObjTombstone__data_8048D250_size[sizeof(RecoveredGlobal_80074FAC_TObjTombstone__data_8048D250) == 0x28 ? 1 : -1];
void TObjTombstone::reset_matrix() {
    ByteBlock_28 sp8;
    sp8 = *(const ByteBlock_28 *)((s32) ((u8 *)&tombstone_reset_matrix_template.value + -4) + 4);
    ((TObjTombstone *)(&TObjTombstone__base_matrix.value))->copy_matrix((void*)&sp8);
}
}
extern Off_800753DC tombstone_name_label_offset_table[];
extern const f32 lbl_805D9188;
extern const f32 lbl_805D918C;
extern const f32 lbl_805D9190;
extern const f32 lbl_805D91A0;
void handle_6x96(void);
void handle_6x96(void) {  }
s32 TObjTombstone::check_owner() {
    s32 var_r3;

    if (TRaderMapCore::is_not_split_screen() == 1) {
        var_r3 = is_challenge_mode_active();
    } else {
        var_r3 = is_flag_set__6TLobbyFv();
    }
    if ((var_r3 == 0) || ((s8) this->m_c2 != get_current_floor())) {
        return 1;
    }
    return 0;
}

s32 TObjTombstone::is_other_tombstone_closer() {
    Obj_80075070 *arg0 = (Obj_80075070 *)this;
    f32 best;
    f32 d;
    u32 pl;
    void *ppos;
    s32 i;
    best = TObjTombstone__data_805D917C;
    pl = (u32)get_player_by_client_id(local_client_id);
    if (pl == 0) {
        return 0;
    }
    ppos = (void *)(pl + 0x38);
    for (i = 0; i < 4; i++) {
        if (i != arg0->fac && lbl_805D9170 != tombstone_position_table[i].y) {
            V_80075070 v = tombstone_position_table[i];
            subtract_vector(&v, ppos);
            v.y = TObjTombstone__data_805D9174;
            d = vector_length(&v);
            if (best > d) {
                best = d;
            }
        }
    }
    if (TObjTombstone__data_805D917C == best) {
        return 0;
    }
    V_80075070 w = arg0->pos;
    subtract_vector(&w, ppos);
    w.y = TObjTombstone__data_805D9174;
    d = vector_length(&w);
    if (d < best || (d == best && arg0->fac == local_client_id)) {
        return 0;
    }
    return 1;
}

s32 TObjTombstone::project_to_screen(void *arg0, f32 *arg1, void *arg2) {
    V_800751BC d;
    V_800751BC v = lbl_80438780;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, camera_ctrl_instance->f194);
    rotate_matrix_x(0, camera_ctrl_instance->f190);
    rotate_matrix_z(0, camera_ctrl_instance->f198);
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrix();
    VecCopy((Vec *)&d, (const Vec *)arg2);
    subtract_vector(&d, &camera_ctrl_instance->pos);
    if (vec3_dot(&v, &d) <= TObjTombstone__data_805D9174) {
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

void TObjTombstone::update_fade_by_distance() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    u32 player;
    TCameraCtrl::get_camera_no();
    player = (u32)get_player_by_client_id((get_nth_view_player_id__11TCameraCtrlFl()));
    if (player != 0U) {
        temp_f1 = xyz_distance((void *)(player + 0x38), (void *)(arg0 + 0x38));
        if (temp_f1 <= lbl_805D9180) {
            *(f32 *)&this->unk_B4 = (f32) TObjTombstone__data_805D9178;
        } else if (temp_f1 >= TObjTombstone__data_805D917C) {
            *(f32 *)&this->unk_B4 = (f32) TObjTombstone__data_805D9174;
        } else {
            *(f32 *)&this->unk_B4 = (f32) ((TObjTombstone__data_805D917C - temp_f1) / TObjTombstone__data_805D9184);
        }
        TObjTombstone::draw_name_labels(arg0);
    }
}
#pragma push
#pragma fp_contract on
#define self ((Obj_800753DC *)arg0_)
s32 TObjTombstone::draw_name_labels(void *arg0_) {
    u32 c2;
    u32 c1;
    P_800753DC screen;
    V_800753DC pos;
    f32 m;
    f32 a;
    f32 b;
    u32 alpha;
    if (TObjTombstone__data_805D9174 == self->scale) return;
    VecCopy((Vec *)&pos, (const Vec *)&self->pos);
    pos.y += lbl_805D9188;
    if (TObjTombstone::project_to_screen(self, (f32 *)&screen, &pos) == 0) return;
    m = TObjTombstone__data_805D9174;
    for (s32 i = 0; i < 6; i++) {
        f32 w = calc_text_width(self->names[i]);
        if (m < w) m = w;
    }
    m *= lbl_805D918C;
    if (screen.x - m < TObjTombstone__data_805D9174 || screen.x + m > lbl_805D9190) {
        if ((self->alphaA += -0.16666667f) < 0.0f) self->alphaA = 0.0f;
        if ((self->alphaB += -0.016666668f) < 0.0f) self->alphaB = 0.0f;
    } else {
        if ((self->alphaA += 0.16666667f) > 1.0f) self->alphaA = 1.0f;
        if ((self->alphaB += 0.16666667f) > 1.0f) self->alphaB = 1.0f;
    }
    a = self->scale * self->alphaA;
    b = self->scale * self->alphaB;
    alpha = (s32)(lbl_805D9180 * sin_table_lookup(self->timer << 8)) + 200;
    c1 = (u32)(alpha * a) << 24;
    c2 = ((u32)(alpha * b) << 24) | 0xFFFFFF;
    for (s32 i = 0; i < 6; i++) {
        char *name;
        P_800753DC p = screen;
        name = self->names[i];
        if (strlen(name) != 0) {
            p.x -= lbl_805D918C * TWindowSubStatusDisp::calc_text_width(name);
            if (a > TObjTombstone__data_805D9174) {
                s32 j;
                for (j = 0; j < 8; j++) {
                    Off_800753DC o = tombstone_name_label_offset_table[j];
                    draw_menu_font_string(name, c1, 1, p.x + o.x, p.y + o.y, lbl_805D918C);
                }
            }
            if (b > TObjTombstone__data_805D9174) {
                draw_menu_font_string(name, c2, 1, p.x, p.y, lbl_805D918C);
            }
            screen.y += lbl_805D91A0;
        }
    }
}
#undef self
#pragma pop
