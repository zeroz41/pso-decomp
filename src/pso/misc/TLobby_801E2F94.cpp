#include "pso/animation/MotionContext.h"
#include "pso/render/DebugFont.h"
#include "pso/render/render_util.h"
#include "pso/misc/TLobby_801E2F94.h"
#include "pso/player/TObjPlayer_803E21B8.h"
#include "pso/enemy/TObjEneRe4Sorcerer_801E3F14.h"
#include "pso/unk/text_801E3F24.h"
#include "pso/unk/text_803E20B0.h"
#include "pso/system/byteswap.h"
#include "pso/system/main_loop.h"
#include "pso/misc/TWindowCtrlMain.h"
#include "types.h"
#include "pso/TObjCMHairMenu.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/TObjFish.h"
#include "pso/misc/TCameraCtrl_803D6538.h"

extern "C" {

s32 TCameraCtrl__sub_80068EF0();
s32 TLobby__sub_80228154(s32, s32, s32, f32);

void TLobby::draw_with_camera(s32 arg0, s32 arg1, s32 arg2, f32 farg0) {
    TCameraCtrl::restore_full_screen_view();
    TLobby__sub_80228154(arg0, arg1, arg2, farg0);
    TCameraCtrl__sub_80068EF0();
}
}

typedef struct Vtx_801E2FEC { f32 x, y, z; f32 u, v; u32 color; } Vtx_801E2FEC;
typedef struct Rect_801E2FEC { s16 x, y, w, h; u8 pad8[8]; s16 tex; } Rect_801E2FEC;
typedef struct Self_801E2FEC { f32 x, y, z; u8 padC[0xC]; s32 param; Rect_801E2FEC *rect; } Self_801E2FEC;

s32 set_texture_num(s32 i);
void draw_particle_strip(void *arg0, void *arg1, void *arg2);

void TObjPlayer::draw_shadow_quad(s32 arg1, s32 flags) {
    Self_801E2FEC *self = (Self_801E2FEC *)this;
    Vtx_801E2FEC v[4];
    f32 ey, ex, cx, cy, z;
    f32 u0, v0, u1, v1;

    TObjFish::set_global_param(self->param);
    set_texture_num(self->rect->tex);
    u0 = 0.01f;
    u1 = 0.99f;
    v0 = u0;
    v1 = u1;
    if (flags & 4) {
        u0 = u1;
        u1 = v0;
    }
    if (flags & 8) {
        v0 = 0.99f;
        v1 = 0.01f;
    }
    cx = self->x + 0.5f * (f32)self->rect->x;
    cy = self->y + 0.5f * (f32)self->rect->y;
    ex = 0.5f * (f32)self->rect->x - (f32)self->rect->w;
    ey = 0.5f * (f32)self->rect->y - (f32)self->rect->h;
    v[0].x = cx - ex;
    v[0].y = cy - ey;
    v[1].x = cx - ex;
    v[1].y = cy + ey;
    v[2].x = cx + ex;
    v[2].y = cy - ey;
    v[3].x = cx + ex;
    v[3].y = cy + ey;
    v[0].u = u0;
    v[0].v = v0;
    v[1].u = u0;
    v[1].v = v1;
    v[2].u = u1;
    v[2].v = v0;
    v[3].u = u1;
    v[3].v = v1;
    z = self->z;
    v[0].z = z;
    v[0].color = 0xFF000000;
    v[1].z = z;
    v[1].color = 0xFF000000;
    v[2].z = z;
    v[2].color = 0xFF000000;
    v[3].z = z;
    v[3].color = 0xFF000000;
    draw_particle_strip((void *)v, (void *)(4), (void *)(1));
}

struct Rect_801E317C { f32 x0, y0, x1, y1; };

extern "C" {
extern f32 viewport_scissor_origin_x;
extern f32 camera_viewport_center_y;
void TCameraCtrl__sub_801E32D8(f32 farg0, f32 farg1);
void GXSetScissor(u32, u32, u32, u32);
void set_viewport_scissor__11TCameraCtrlFiPv(s32 mode, Rect_801E317C *r);
void camera_renderer_setup_nop(void);
s32 TObjPlayer__sub_803DAD28(u32 arg0);
int draw_textured_vertices__10TObjPlayerFPvii(void*, void*, void*);

void set_viewport_scissor__11TCameraCtrlFiPv(s32 mode, Rect_801E317C *r) {
    f32 adj;
    f32 x;
    f32 y;
    f32 ox;
    f32 w;
    f32 h;
    f32 oy;
    if (mode == 2) {
        x = 32.0f * r->x0;
        y = 32.0f * r->y0;
        w = 32.0f * (r->x1 - r->x0);
        h = 32.0f * (1.0f + (r->y1 - r->y0));
        if (h >= 480.0f) {
            h = 480.0f;
        }
        if (w >= 640.0f) {
            w = 640.0f;
        }
        ox = viewport_scissor_origin_x - 320.0f;
        oy = camera_viewport_center_y - 240.0f;
        if (oy >= 0.0f) {
            adj = -oy;
            oy = 0.0f;
        }
        GXSetScissor(x - ox, y + adj, w, h - oy);
    } else {
        GXSetScissor(0, 0, 640, 480);
    }
}

void TCameraCtrl__sub_801E32D8(f32 farg0, f32 farg1) {
    viewport_scissor_origin_x = farg0;
    camera_viewport_center_y = farg1;
}

void camera_renderer_setup_nop(void) {  }

void TWindowDD::draw_transformed_primitive(void* a1, void* a2, void* a3) { TObjPlayer__sub_803DAD28((u32)a2); draw_textured_vertices__10TObjPlayerFPvii(this, a1, a3); }

}

struct Ctrl_801E352C {
    u8 pad[4];
    u32 *data;
};

struct Vec3_801E341C { f32 x, y, z; };

struct Lines_801E341C {
    Vec3_801E341C *positions;
    u32 *colors;
};

struct Vec3_801E3784 { f32 x, y, z; };

struct UV_801E3784 { s16 u, v; };

struct Tris_801E3784 {
    Vec3_801E3784 *positions;
    u32 *colors;
    UV_801E3784 *uvs;
};

extern "C" {
void GXBegin(s32, s32, u16);
void GXSetLineWidth(s32, s32);
void reset_line_width(void);
extern int current_line_width;
void draw_line_list(Lines_801E341C *l, s32 n, u32 flags);
}
void setup_opaque_color_draw(void);
void setup_blended_textured_draw(void);
void load_context_texture_obj(void);
extern "C" {
void set_line_width(int a0);

void draw_color_lines(ColorLineList *l, s32 n, s32 flags, f32 scale) {
    u32 c;
    TObjPlayer::load_screen_space_matrix();
    if (flags & 4) {
        TObjPlayer__sub_803E21DC();
    } else {
        setup_opaque_color_draw();
    }
    GXSetLineWidth(0xC, 0);
    if (flags & 0x10) {
        GXBegin(0xB0, 4, n);
    } else {
        GXBegin(0xA8, 4, n);
    }
    while (n > 0) {
        n--;
        TObjPlayer__sub_801E3F30(scale * l->verts[n].x, scale * l->verts[n].y, scale);
        c = l->colors[n];
        TObjPlayer__sub_801E3F24((c << 8) | (c >> 24));
    }
    TObjEneRe4Sorcerer__sub_801E3F20();
}

void draw_line_list(Lines_801E341C *l, s32 n, u32 flags) {
    Vec3_801E341C *p;
    u32 *c;
    load_camera_view_matrix();
    if (flags & 4) {
        TObjPlayer__sub_803E21DC();
    } else {
        setup_opaque_color_draw();
    }
    GXSetLineWidth((u8)current_line_width, 0);
    if (flags & 0x10) {
        GXBegin(0xB0, 4, n * 2);
    } else {
        GXBegin(0xA8, 4, n * 2);
    }
    p = l->positions;
    c = l->colors;
    while (n > 0) {
        TObjPlayer__sub_801E3F30(p->x, p->y, p->z);
        TObjPlayer__sub_801E3F24((*c << 8) | (*c >> 24));
        c++;
        p++;
        TObjPlayer__sub_801E3F30(p->x, p->y, p->z);
        TObjPlayer__sub_801E3F24((*c << 8) | (*c >> 24));
        if (!(flags & 0x10)) {
            p++;
            c++;
        }
        n--;
    }
    TObjEneRe4Sorcerer__sub_801E3F20();
    reset_line_width();
}

void reset_line_width(void) { current_line_width = 12; }

void set_line_width(int a0) { current_line_width = a0; }
void TWindowCtrlMain::draw_strip_swap_color(s32 n, s32 flags, f32 scale) {
    s32 i;
    u32 x;
    u32 *p;
    if (!(flags & 2)) {
        ((TObjCMHairMenu *)this)->draw_tri_fan_2d(n, flags, scale);
        return;
    }
    p = ((Ctrl_801E352C *)this)->data;
    for (i = 0; i < n; i++) {
        x = *p;
        *p = (x << 8) | (x >> 24);
        p++;
    }
    ((TObjCMHairMenu *)this)->draw_tri_fan_2d(n, flags, scale);
    {
    u32 *q = ((Ctrl_801E352C *)this)->data;
    u32 y;
    for (i = 0; i < n; i++) {
        y = *q;
        *q = (y >> 8) | (y << 24);
        q++;
    }
    }
}
void TObjCMHairMenu::draw_tri_fan_2d(s32 count, s32 flags, f32 scale) {
    ColorLineList *self = (ColorLineList *)this;
    ColorLineList tmp;
    ColorLineVertex v[2];
    u32 c[2];
    u32 tex;
    ColorLineVertex *pts;
    s32 i;
    s16 *cols;
    if (!(flags & 2)) {
        tmp.verts = v;
        tmp.colors = c;
        tmp.unk_8 = self->unk_8;
        tmp.count = 2;
        draw_color_lines(self, count, flags | 0x10, scale);
        ((TWindowSubSymbolChatPartsSet *)(&v[0]))->copy_vec2(&self->verts[0]);
        ((TWindowSubSymbolChatPartsSet *)(&v[1]))->copy_vec2(&self->verts[self->count - 1]);
        TObjCMHairMenu__sub_801E3F54(&c[0], &self->colors[0]);
        TObjCMHairMenu__sub_801E3F54(&c[1], &self->colors[self->count - 1]);
        draw_color_lines(&tmp, 2, flags, scale);
        return;
    }
    TObjPlayer::load_screen_space_matrix();
    tex = flags & 8;
    if (tex) {
        if (flags & 4) {
            setup_blended_textured_draw();
        } else {
            TObjPlayer::setup_render();
        }
    } else if (flags & 4) {
        TObjPlayer__sub_803E21DC();
    } else {
        setup_opaque_color_draw();
    }
    GXBegin(0xA0, 4, count);
    pts = self->verts;
    cols = (s16 *)self->colors;
    for (i = 0; i < count; pts++, cols += 2, i++) {
        TObjPlayer__sub_801E3F30(pts->x * scale, pts->y * scale, scale);
        TObjPlayer__sub_801E3F24(*(u32 *)cols);
        if (tex) {
            fn_801E3F44((f32)cols[0] / 255.0f, (f32)cols[1] / 255.0f);
        }
    }
    TObjEneRe4Sorcerer__sub_801E3F20();
}
void TObjPlayer::draw_tri_fan_3d(s32 n, u32 flags) {
    Tris_801E3784 *t = (Tris_801E3784 *)this;
    Vec3_801E3784 *p;
    UV_801E3784 *uv;
    u32 *c;
    s32 i;
    load_camera_view_matrix();
    if (flags & 8) {
        if (flags & 4) {
            setup_blended_textured_draw();
        } else {
            TObjPlayer::setup_render();
        }
        load_context_texture_obj();
    } else if (flags & 4) {
        TObjPlayer__sub_803E21DC();
    } else {
        setup_opaque_color_draw();
    }
    GXBegin(0xA0, 4, n);
    c = t->colors;
    p = t->positions;
    uv = t->uvs;
    for (i = 0; i < n; i++) {
        TObjPlayer__sub_801E3F30(p->x, p->y, p->z);
        TObjPlayer__sub_801E3F24(*c);
        if (flags & 8) {
            fn_801E3F44(uv->u / 255.0f, uv->v / 255.0f);
            uv++;
        }
        p++;
        c++;
    }
    TObjEneRe4Sorcerer__sub_801E3F20();
    TObjPlayer__sub_803E2248();
}

void DCFlushRange(void *, u32);
void TLobby__sub_801E3CF0(u32 *);

s32 *TLobby__sub_801E38A0(s32 arg0, s32 *arg1, s32 *arg2, s32 *buf, s32 *arg4) {
    u8 *p;
    s32 pos;
    s32 tag;
    u32 size;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 off;

    pos = 0;
    p = (u8 *)(arg0 + *arg1);
    ((TLobby *)(&tag))->move_data(p, 4);
    TLobby__sub_801E3CF0((u32 *)&tag);
    ((TLobby *)(&size))->move_data(p + 4, 4);
    TLobby__sub_801E3CF0(&size);
    p += 8;
    *arg1 += 8;
    tag = TLobby::bswap32_value(tag);
    switch (tag) {
    case 0x4E4A494E:
        *arg2 = 0x4E4A494E;
        break;
    case 0x4E4A434D:
    case 0x474A434D:
        *arg2 = 0x4E4A434D;
        break;
    case 0x474A424D:
        *arg2 = 0x4E4A424D;
        break;
    case 0x4E4A544C:
    case 0x474A544C:
        *arg2 = 0x4E4A544C;
        break;
    case 0x4E4A4C49:
        *arg2 = 0x4E4A4C49;
        break;
    case 0x4E4A4341:
        *arg2 = 0x4E4A4341;
        break;
    case 0x4E4D444D:
    case 0x474D444D:
        *arg2 = 0x4E4D444D;
        break;
    case 0x474C494D:
        *arg2 = 0x4E4C494D;
        break;
    case 0x4743414D:
        *arg2 = 0x4E43414D;
        break;
    case 0x4E53534D:
    case 0x4753534D:
        *arg2 = 0x4E53534D;
        break;
    default:
        goto bad;
    }
    buf = (buf == 0) ? (s32 *)TQuestVmDownLoadServer::alloc(size) : buf;
    if (buf == 0) {
        return 0;
    }
    if (arg4 != 0) {
        *arg4 = size;
    }
    ((TLobby *)buf)->move_data(p, size);
    DCFlushRange(buf, size);
    p += size;
    *arg1 += size;
    goto next;
bad:
    *arg2 = 0x2A2A2A2A;
    return 0;
next:
    ((TLobby *)(&tag))->move_data(p, 4);
    TLobby__sub_801E3CF0((u32 *)&tag);
    *arg1 += 4;
    tag = TLobby::bswap32_value(tag);
    if (tag == 0x504F4630) {
        ((TLobby *)(&size))->move_data(p + 4, 4);
        TLobby__sub_801E3CF0(&size);
        p += 8;
        *arg1 += 4;
        while (size != 0) {
            ((TLobby *)(&b0))->move_data(p, 1);
            p++;
            *arg1 += 1;
            size--;
            switch (b0 & 0xC0) {
            case 0:
                continue;
            case 0x40:
                off = b0 & 0x3F;
                break;
            case 0x80:
                ((TLobby *)(&b1))->move_data(p, 1);
                p++;
                size--;
                *arg1 += 1;
                off = ((b0 << 8) & 0x3F00) | b1;
                break;
            case 0xC0:
                ((TLobby *)(&b1))->move_data(p, 1);
                size--;
                ((TLobby *)(&b2))->move_data(p + 1, 1);
                size--;
                ((TLobby *)(&b3))->move_data(p + 2, 1);
                p += 3;
                size--;
                *arg1 += 3;
                off = (((b0 << 24) & 0x3F000000) | (b1 << 16) | (b2 << 8)) | b3;
                break;
            default:
                continue;
            }
            pos += off * 4;
            if (*(u32 *)((u8 *)buf + pos) != 0) {
                *(u32 *)((u8 *)buf + pos) += (u32)buf;
            }
        }
    }
    return buf;
}

void TLobby__sub_801E3CF0(u32 *p) {
    u32 v = *p;
    *p = (v >> 24) | ((v >> 8) & 0xFF00) | ((v << 8) & 0xFF0000) | (v << 24);
}

}

void draw_motion(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame) {
    bind_motion_context((NJS_MOTION *)motion, frame);
    TObjPlayer::render_tree(model);
}

struct RecoveredGlobal_801E3E24_TKeyBoardControl__data_80506270 { s32 value; u8 remaining[0xAC]; };
typedef char RecoveredGlobal_801E3E24_TKeyBoardControl__data_80506270_size[sizeof(RecoveredGlobal_801E3E24_TKeyBoardControl__data_80506270) == 0xB0 ? 1 : -1];

extern "C" {
void TLobby__sub_803382E4(void);
s32 read_afs_toc__6TLobbyFl(void *);
s32 adxf_open_file__6TLobbyFiPviPv(void *, void *, int, void *);
s32 TLobby__sub_801E3E9C(s32 arg0, s32 arg1, s32 arg2);
s32 disable_disconnected_ports__16TKeyBoardControlFv(void *);
void update_global_sound_frame(void);
extern RecoveredGlobal_801E3E24_TKeyBoardControl__data_80506270 TKeyBoardControl__global_key_state;
s32 TKeyBoardControl__sub_801E3E24(s32 arg0, s32 arg1, s32 arg2);
s32 GXSetViewport(f32, f32, f32, f32, f32, f32);
s32 GXSetZMode(s32, s32, s32);
extern s32 (*chunk_model_node_callback)(void *);
void TKeyBoardControl__sub_8000F7FC(void);
void compose_motion_node_matrix(void *arg0);

s32 push_matrix();
s32 pop_matrix();
void fn_803DCEC8(void);
void fn_803DCF0C(void);

void TObjPlayer::render_tree(void *arg0) {
    void *var_r31;

    var_r31 = arg0;
    do {
        push_matrix();
        compose_motion_node_matrix(var_r31);
        if (((s32 (*)(void *)) chunk_model_node_callback) != NULL) {
            chunk_model_node_callback(var_r31);
        }
        if ((u32) *(u32 *)((s8 *)var_r31 + 0x2C) != 0U) {
            TObjPlayer::render_tree((void *)(*(void **)((s8 *)var_r31 + 0x2C)));
        }
        pop_matrix();
        var_r31 = *(void **)((s8 *)var_r31 + 0x30);
    } while (var_r31 != NULL);
}

extern s32 lbl_805D3584;

}
void render_tick(void) {
    TKeyBoardControl::run_tasks();
    TParticleCtrl::begin_effect_render();
    GXSetZMode(1, 7, 0);
    TCameraCtrl::restore_full_screen_view();
    set_cull_none();
    render_debug_text(lbl_805D3584);
    GXSetZMode(1, 3, 1);
    GXSetViewport((0.0f), (0.0f), (6.4e+02f), (4.8e+02f), (0.0f), (1.0f));
    set_cull_none();
    TParticleCtrl::end_effect_render();
    fn_803DCEC8();
    fn_803DCF0C();
    TKeyBoardControl__sub_8000F7FC();
}

s32 TKeyBoardControl__sub_801E3E24(s32 id, s32 name, s32 arg2) {
    s32 temp_r3;
    temp_r3 = adxf_open_file__6TLobbyFiPviPv((void *)id, (void *)name, 0, (void *)arg2);
    if (temp_r3 >= 0) {
loop_2:
        if (read_afs_toc__6TLobbyFl((void *)id) != 3) {
            TLobby::run_disk_error_check();
            TKeyBoardControl::flush_input();
            update_global_sound_frame();
            TKeyBoardControl::read_pads();
            disable_disconnected_ports__16TKeyBoardControlFv(&TKeyBoardControl__global_key_state.value);
            TLobby::reset_state_byte();
            goto loop_2;
        }
    }
    return temp_r3;
}

s32 TLobby__sub_801E3E9C(s32 id, s32 name, s32 arg2) {
    s32 temp_r3;
    temp_r3 = adxf_open_file__6TLobbyFiPviPv((void *)id, (void *)name, 0, (void *)arg2);
    if (temp_r3 >= 0) {
loop_1:
        if (read_afs_toc__6TLobbyFl((void *)id) != 3) {
            TLobby::run_disk_error_check();
            TLobby__sub_803382E4();
            TLobby::run_frame();
            goto loop_1;
        }
    }
    return temp_r3;
}
void bswap_16(u16 *p) {
    u32 v = *p;
    *p = (u16) (((v >> 8) & 0xFF) | ((v << 8) & 0xFF00));
}

void bswap_32(u32 *p) {
    u32 v = *p;
    *p = (v >> 24) | ((v >> 8) & 0xFF00) | ((v << 8) & 0xFF0000) | (v << 24);
}
