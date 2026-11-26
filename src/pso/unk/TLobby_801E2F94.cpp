#include "pso/ui/window/WindowVertexBufferAbi.h"
#include "pso/audio/AdxUiBridge.h"
#include "pso/system/Adxf.h"
#include "pso/system/memory.h"
#include "pso/render/TriangleFan3D.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/animation/MotionContext.h"

#include "pso/unk/TLobby_80227AA0.h"
#include "pso/render/DebugFont.h"
#include "pso/render/render_util.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/unk/TLobby_80228154.h"
#include "pso/render/ScreenPrimitiveDraw.h"
#include "pso/enemy/sorcerer/TObjEneRe4Sorcerer_801E3F14.h"
#include "pso/unk/text_801E3F24.h"
#include "pso/system/byteswap.h"
#include "pso/system/main_loop.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "types.h"
#include "pso/render/gjSystem.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include <dolphin/os/OSCache.h>
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/ParticleStrip.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/render/Draw2D.h"
#include "pso/render/GinjaView.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/TLobby_803DE778.h"
#include "pso/system/vector.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#include "pso/unk/text_803DD5E0.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/unk/text_803DA798.h"
#include "pso/unk/TLobby_803382E4.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#undef PSO_SDK_COMPACT_MATH

void TLobby::draw_with_camera(NJS_SPRITE *sprite, s32 frame_index, s32 flags, f32 depth) {
    TCameraCtrl::restore_full_screen_view();
    draw_screen_sprite(sprite, frame_index, flags, depth);
    TCameraCtrl::restore_saved_view();
}

void draw_shadow_quad(NJS_SPRITE *sprite, s32 frame, s32 flags) {
    ParticleStripVertex v[4];
    f32 ey, ex, cx, cy, z;
    f32 u0, v0, u1, v1;

    set_texture_list(reinterpret_cast<NJS_TEXLIST *>(sprite->tlist));
    set_texture_num(sprite->tanim->texid);
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
    cx = sprite->p.x + 0.5f * (f32)sprite->tanim->sx;
    cy = sprite->p.y + 0.5f * (f32)sprite->tanim->sy;
    ex = 0.5f * (f32)sprite->tanim->sx - (f32)sprite->tanim->cx;
    ey = 0.5f * (f32)sprite->tanim->sy - (f32)sprite->tanim->cy;
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
    z = sprite->p.z;
    v[0].z = z;
    v[0].color = 0xFF000000;
    v[1].z = z;
    v[1].color = 0xFF000000;
    v[2].z = z;
    v[2].color = 0xFF000000;
    v[3].z = z;
    v[3].color = 0xFF000000;
    draw_particle_strip(v, 4, 1);
}

extern "C" {
int current_line_width = 12;
s32 lbl_805D3584 = 1;
f32 viewport_scissor_origin_x = 320.0f;
f32 camera_viewport_center_y = 240.0f;
}

void set_viewport_scissor(int mode, const TileRect *r) {
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

void set_screen_center(f32 x, f32 y) {
    viewport_scissor_origin_x = x;
    camera_viewport_center_y = y;
}

void camera_renderer_setup_nop(NJS_CAMERA *camera, s32 angle) {  }

void draw_window_vertices(WindowVertex *vertices, s32 count, u32 surface_id, s32 blended) { select_texture_by_surface_id(surface_id); draw_screen_textured_strip((ScreenTexturedVertex *)vertices, count, blended); }




extern "C" {
void draw_line_list(DrawTransformedPrimitiveLines *l, s32 count, u32 flags);
}


void draw_color_lines(ColorLineList *l, s32 count, s32 flags, f32 scale) {
    u32 c;
    load_screen_space_matrix();
    if (flags & 4) {
        setup_blended_color_draw();
    } else {
        setup_opaque_color_draw();
    }
    GXSetLineWidth(0xC, GX_TO_ZERO);
    if (flags & 0x10) {
        GXBegin(GX_LINESTRIP, GX_VTXFMT4, count);
    } else {
        GXBegin(GX_LINES, GX_VTXFMT4, count);
    }
    while (count > 0) {
        count--;
        gx_write_f32x3(scale * l->verts[count].x, scale * l->verts[count].y, scale);
        c = l->colors[count];
        gx_write_u32((c << 8) | (c >> 24));
    }
    TObjEneRe4Sorcerer__sub_801E3F20();
}

void draw_line_list(DrawTransformedPrimitiveLines *l, s32 count, u32 flags) {
    Vec *p;
    u32 *c;
    load_camera_view_matrix();
    if (flags & 4) {
        setup_blended_color_draw();
    } else {
        setup_opaque_color_draw();
    }
    GXSetLineWidth((u8)current_line_width, GX_TO_ZERO);
    if (flags & 0x10) {
        GXBegin(GX_LINESTRIP, GX_VTXFMT4, count * 2);
    } else {
        GXBegin(GX_LINES, GX_VTXFMT4, count * 2);
    }
    p = l->positions;
    c = l->colors;
    while (count > 0) {
        gx_write_f32x3(p->x, p->y, p->z);
        gx_write_u32((*c << 8) | (*c >> 24));
        c++;
        p++;
        gx_write_f32x3(p->x, p->y, p->z);
        gx_write_u32((*c << 8) | (*c >> 24));
        if (!(flags & 0x10)) {
            p++;
            c++;
        }
        count--;
    }
    TObjEneRe4Sorcerer__sub_801E3F20();
    reset_line_width();
}

void reset_line_width(void) { current_line_width = 12; }

void set_line_width(int a0) { current_line_width = a0; }
void ColorLineList::draw_strip_swap_color(s32 count, s32 flags, f32 scale) {
    s32 i;
    u32 x;
    u32 *p;
    if (!(flags & 2)) {
        draw_polygon_2d((NJS_POINT2COL *)this, count, flags, scale);
        return;
    }
    p = colors;
    for (i = 0; i < count; i++) {
        x = *p;
        *p = (x << 8) | (x >> 24);
        p++;
    }
    draw_polygon_2d((NJS_POINT2COL *)this, count, flags, scale);
    {
    u32 *q = colors;
    u32 y;
    for (i = 0; i < count; i++) {
        y = *q;
        *q = (y >> 8) | (y << 24);
        q++;
    }
    }
}
void draw_polygon_2d(NJS_POINT2COL *poly, s32 count, u32 flags, f32 depth) {
    ColorLineList tmp;
    ColorLineVertex v[2];
    u32 c[2];
    u32 tex;
    NJS_POINT2 *pts;
    s32 i;
    s16 *cols;
    if (!(flags & 2)) {
        tmp.verts = v;
        tmp.colors = c;
        tmp.tex = poly->tex;
        tmp.count = 2;
        draw_color_lines(reinterpret_cast<ColorLineList *>(poly), count, flags | 0x10, depth);
        copy_vec2((&v[0]), &poly->p[0]);
        copy_vec2((&v[1]), &poly->p[poly->num - 1]);
        copy_u32(&c[0], &poly->col[0].color);
        copy_u32(&c[1], &poly->col[poly->num - 1].color);
        draw_color_lines(&tmp, 2, flags, depth);
        return;
    }
    load_screen_space_matrix();
    tex = flags & 8;
    if (tex) {
        if (flags & 4) {
            setup_blended_textured_draw();
        } else {
            setup_opaque_textured_draw();
        }
    } else if (flags & 4) {
        setup_blended_color_draw();
    } else {
        setup_opaque_color_draw();
    }
    GXBegin(GX_TRIANGLEFAN, GX_VTXFMT4, count);
    pts = poly->p;
    cols = reinterpret_cast<s16 *>(poly->col);
    for (i = 0; i < count; pts++, cols += 2, i++) {
        gx_write_f32x3(pts->x * depth, pts->y * depth, depth);
        gx_write_u32(*(u32 *)cols);
        if (tex) {
            gx_write_f32x2((f32)cols[0] / 255.0f, (f32)cols[1] / 255.0f);
        }
    }
    TObjEneRe4Sorcerer__sub_801E3F20();
}
void draw_tri_fan_3d(NJS_POINT3COL *fan, s32 count, u32 flags) {
    Vec *p;
    NJS_TEX *uv;
    u32 *c;
    s32 i;
    load_camera_view_matrix();
    if (flags & 8) {
        if (flags & 4) {
            setup_blended_textured_draw();
        } else {
            setup_opaque_textured_draw();
        }
        load_context_texture_obj();
    } else if (flags & 4) {
        setup_blended_color_draw();
    } else {
        setup_opaque_color_draw();
    }
    GXBegin(GX_TRIANGLEFAN, GX_VTXFMT4, count);
    c = fan->col;
    p = fan->p;
    uv = fan->tex;
    for (i = 0; i < count; i++) {
        gx_write_f32x3(p->x, p->y, p->z);
        gx_write_u32(*c);
        if (flags & 8) {
            gx_write_f32x2(uv->u / 255.0f, uv->v / 255.0f);
            uv++;
        }
        p++;
        c++;
    }
    TObjEneRe4Sorcerer__sub_801E3F20();
    end_primitive_draw();
}

// Reads one Ninja chunk (NJCM, NJTL, NMDM, ...) at file + *offset into dst (or a fresh
// allocation), stores its type, then applies the POF0 pointer-offset list that follows.
void *TLobby__sub_801E38A0(const u8 *file, u32 *offset, u32 *type, void *destination, u32 *size_out) {
    const u8 *p;
    void *buf;
    s32 pos;
    s32 tag;
    u32 size;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 off;

    pos = 0;
    p = (u8 *)(file + *offset);
    move_data(((&tag)), (const void *)(p), 4);
    bswap_u32_in_place((u32 *)&tag);
    move_data(((&size)), (const void *)(p + 4), 4);
    bswap_u32_in_place(&size);
    p += 8;
    *offset += 8;
    tag = bswap32_value(tag);
    switch (tag) {
    case 0x4E4A494E:
        *type = 0x4E4A494E;
        break;
    case 0x4E4A434D:
    case 0x474A434D:
        *type = 0x4E4A434D;
        break;
    case 0x474A424D:
        *type = 0x4E4A424D;
        break;
    case 0x4E4A544C:
    case 0x474A544C:
        *type = 0x4E4A544C;
        break;
    case 0x4E4A4C49:
        *type = 0x4E4A4C49;
        break;
    case 0x4E4A4341:
        *type = 0x4E4A4341;
        break;
    case 0x4E4D444D:
    case 0x474D444D:
        *type = 0x4E4D444D;
        break;
    case 0x474C494D:
        *type = 0x4E4C494D;
        break;
    case 0x4743414D:
        *type = 0x4E43414D;
        break;
    case 0x4E53534D:
    case 0x4753534D:
        *type = 0x4E53534D;
        break;
    default:
        goto bad;
    }
    if (destination == NULL) {
        buf = (void *)TQuestVmDownLoadServer::alloc(size);
    } else {
        buf = destination;
    }
    if (buf == 0) {
        return 0;
    }
    if (size_out != 0) {
        *size_out = size;
    }
    move_data((buf), (const void *)(p), size);
    DCFlushRange(buf, size);
    p += size;
    *offset += size;
    goto next;
bad:
    *type = 0x2A2A2A2A;
    return 0;
next:
    move_data(((&tag)), (const void *)(p), 4);
    bswap_u32_in_place((u32 *)&tag);
    *offset += 4;
    tag = bswap32_value(tag);
    if (tag == 0x504F4630) {
        move_data(((&size)), (const void *)(p + 4), 4);
        bswap_u32_in_place(&size);
        p += 8;
        *offset += 4;
        while (size != 0) {
            move_data(((&b0)), (const void *)(p), 1);
            p++;
            *offset += 1;
            size--;
            switch (b0 & 0xC0) {
            case 0:
                continue;
            case 0x40:
                off = b0 & 0x3F;
                break;
            case 0x80:
                move_data(((&b1)), (const void *)(p), 1);
                p++;
                size--;
                *offset += 1;
                off = ((b0 << 8) & 0x3F00) | b1;
                break;
            case 0xC0:
                move_data(((&b1)), (const void *)(p), 1);
                size--;
                move_data(((&b2)), (const void *)(p + 1), 1);
                size--;
                move_data(((&b3)), (const void *)(p + 2), 1);
                p += 3;
                size--;
                *offset += 3;
                off = (((b0 << 24) & 0x3F000000) | (b1 << 16) | (b2 << 8)) | b3;
                break;
            default:
                continue;
            }
            pos += off * 4;
            if (*(u32 *)((u8 *)buf + pos) != 0) {
                *(u32 *)((u8 *)buf + pos) += (uaddr)buf;
            }
        }
    }
    return buf;
}

void bswap_u32_in_place(u32 *p) {
    u32 v = *p;
    *p = (v >> 24) | ((v >> 8) & 0xFF00) | ((v << 8) & 0xFF0000) | (v << 24);
}


void draw_motion(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame) {
    bind_motion_context(motion, frame);
    TObjPlayer::render_tree(model);
}



void TObjPlayer::render_tree(void *model) {
    void *node;

    node = model;
    do {
        push_matrix();
        compose_motion_node_matrix(node);
        if (chunk_model_node_callback != NULL) {
            chunk_model_node_callback(static_cast<NJS_OBJECT *>(node));
        }
        if ((u32) *(u32 *)((s8 *)node + 0x2C) != 0U) {
            TObjPlayer::render_tree((void *)(*(void **)((s8 *)node + 0x2C)));
        }
        pop_matrix();
        node = *(void **)((s8 *)node + 0x30);
    } while (node != NULL);
}


void render_tick(void) {
    TKeyBoardControl::run_tasks();
    TParticleCtrl::begin_effect_render();
    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_FALSE);
    TCameraCtrl::restore_full_screen_view();
    set_cull_none();
    render_debug_text(lbl_805D3584);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetViewport((0.0f), (0.0f), (6.4e+02f), (4.8e+02f), (0.0f), (1.0f));
    set_cull_none();
    TParticleCtrl::end_effect_render();
    copy_efb_to_framebuffer();
    present_frame();
    run_end_of_render_tasks();
}

s32 open_afs_file_wait_input(s32 id, const char *name, void *buf, s32 size) {
    s32 handle;
    handle = TLobby::adxf_open_file(id, (void *)name, 0, buf);
    if (handle >= 0) {
loop_2:
        if (ADXF_GetPtStat(id) != 3) {
            TLobby::run_disk_error_check();
            flush_input();
            update_global_sound_frame();
            read_pads();
            hardware_keyboard_state.disable_disconnected_ports();
            TLobby::reset_state_byte();
            goto loop_2;
        }
    }
    return handle;
}

s32 open_afs_file_wait_render(s32 id, const char *name, void *buf, s32 size) {
    s32 handle;
    handle = TLobby::adxf_open_file(id, (void *)name, 0, buf);
    if (handle >= 0) {
loop_1:
        if (ADXF_GetPtStat(id) != 3) {
            TLobby::run_disk_error_check();
            TLobby__sub_803382E4();
            TLobby::run_frame();
            goto loop_1;
        }
    }
    return handle;
}
void bswap_16(u16 *val) {
    u32 v = *val;
    *val = (u16) (((v >> 8) & 0xFF) | ((v << 8) & 0xFF00));
}

void bswap_32(u32 *val) {
    u32 v = *val;
    *val = (v >> 24) | ((v >> 8) & 0xFF00) | ((v << 8) & 0xFF0000) | (v << 24);
}

// Empty hooks after the byte-swap helpers; callers in the battle, Dark Falz and Sorcerer code.
void TObjEneRe4Sorcerer__sub_801E3F14(void) {  }
void TObjEneRe4Sorcerer__sub_801E3F18(void) {  }

void TObjEneRe4Sorcerer__sub_801E3F1C(f32, f32) {  }

void TObjEneRe4Sorcerer__sub_801E3F20(void) {  }

// GX FIFO write helpers and a word copy used by the draw helpers above; the 6x subcommand
// handlers after them open TGameProtocol.cpp.
void gx_write_u32(s32 value) {
    *(s32 *)0xCC008000 = value;
}

void gx_write_f32x3(f32 x, f32 y, f32 z) {
    *(f32 *)0xCC008000 = x;
    *(f32 *)0xCC008000 = y;
    *(f32 *)0xCC008000 = z;
}

void gx_write_f32x2(f32 x, f32 y) {
    *(f32 *)0xCC008000 = x;
    *(f32 *)0xCC008000 = y;
}

u32 *copy_u32(u32 *p, const u32 *q) {
    *p = *q;
    return p;
}
