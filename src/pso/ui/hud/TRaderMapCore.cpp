#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/NinjaTypes.h"
#include "pso/camera/TCameraCtrl_803D676C.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/map/FloorArea.h"
#include "pso/render/render_util.h"

#include "pso/technique/TTecCtrl.h"

#include <stddef.h>
#include "pso/system/THeap.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/hud/TRaderMapCore_801FB2B8.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/system/scene/TScene.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/hud/TRaderMapCore_801FB964.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
struct Stack_801FA9D8 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    RadarViewportParameters viewport;
};

typedef struct RadarInitPiece_801F9474 {
    s16 id, flags;
    f32 translation[3]; u32 rotation[3];
    f32 fade, radius; void *object;
} RadarInitPiece_801F9474;

typedef struct RadarInitMap_801F9474 { RadarInitPiece_801F9474 *pieces; void *textures; s32 count; } RadarInitMap_801F9474;

struct Region_801F9C54 {
    s16 id; s16 flags; f32 x, y, z;
    u32 angles[3]; f32 fade, radius; void *model;
};

struct Map_801F9C54 { struct Region_801F9C54 *regions; void *textures; s32 count; };

struct Region_801F9CB8 {
    s16 id; s16 flags; f32 x, y, z;
    u32 angles[3]; f32 fade, radius; void *model;
};

struct Map_801F9CB8 { struct Region_801F9CB8 *regions; void *textures; s32 count; };

struct Piece_801F9418 {
    s16 a;
    s16 flags;
    u8 rest[0x24];
};

struct Map_801F9418 {
    Piece_801F9418* pieces;
    s32 b;
    s32 count;
};

struct Piece_801F9630 {
    s16 a;
    s16 flags;
    u8 rest[0x24];
};

struct Map_801F9630 {
    Piece_801F9630* pieces;
    s32 b;
    s32 count;
};

struct Rect_801F9228 {
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
};

struct Radar_801FADF0 {
    u8 pad0[0x90];
    s32 f90;
    u8 pad94[0x184 - 0x94];
    u32 f184;
};

struct Dot_801F9B8C { f32 x, z, w; s16 c; s16 type; s32 color; };

struct Model_801F9D84 { u8 pad[8]; Vec a; Vec b; };

struct ModelRef_801F9D84 { void *p0; Model_801F9D84 *m; };

struct Region_801F9D84 {
    s16 id; s16 flags; f32 x, y, z;
    u32 angles[3]; f32 fade, radius; ModelRef_801F9D84 *model;
};

struct Map_801F9D84 { Region_801F9D84 *regions; void *textures; s32 count; };

struct Cam_801F9314 { Vec dir; Vec pos; s32 rot; };

struct Color_801FAAEC { f32 r, g, b, a; };

struct Model_801FAAEC { u8 pad[4]; s32 obj; };

struct Rec_801FAAEC {
    s16 id; s16 flags;
    f32 x, y, z;
    s32 rx, ry, rz;
    f32 alpha;
    u8 pad20[4];
    Model_801FAAEC *model;
};

struct Map_801FAAEC { Rec_801FAAEC *recs; u32 tex; s32 count; };

struct Gate_801FA1E0 { f32 x; f32 z; f32 scale; u16 rot; s16 kind; s32 color; };

typedef struct Vec4_801F9E9C {
    f32 v[4];
} Vec4_801F9E9C;

typedef struct Entry_801F9E9C {
    f32 x;
    f32 y;
    f32 z;
    s32 unkC;
    f32 unk10;
    u8 pad14[2];
    s16 id;
    Vec4_801F9E9C color;
} Entry_801F9E9C;

typedef struct Core_801F9E9C {
    u8 pad0[0x94];
    Entry_801F9E9C e[4];
    s32 unk134;
    u8 pad138[0x34];
    s32 mode;
} Core_801F9E9C;

typedef struct Player_801F9E9C {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0x1C];
    s32 unk60;
    u8 pad64[0x828 - 0x64];
    u8 sub828[4];
} Player_801F9E9C;

struct Glob_801F97C4 {
    u8 pad0[0x28];
    f32 f28;
    u8 pad2c[0x4];
    f32 f30;
    u8 rest[0x44];
};

struct Glob_801F986C {
    u8 pad0[0x28];
    f32 f28;
    u8 pad2c[0x4];
    f32 f30;
    u8 rest[0x44];
};

struct Glob_801F9770 {
    u8 pad0[0x28];
    f32 f28;
    u8 pad2c[0x4];
    f32 f30;
    u8 rest[0x44];
};

struct Pad_801FAF24 {
    u8 pad0[0x20];
    u8 ctl[0x30];
};

struct Radar_801FAF24 {
    u8 pad0[0x184];
    u32 f184;
    f32 f188;
    f32 f18C;
    f32 f190;
};

struct RadarSpriteFrame_801FA6CC {
    s16 width;
    s16 height;
    s16 x;
    s16 y;
    s16 u0;
    s16 v0;
    s16 u1;
    s16 v1;
    s16 unk10;
    s16 unk12;
};

struct RadarViewRect_801FA9D8 {
    f32 center_x;
    f32 center_y;
    f32 screen_width;
    f32 screen_height;
    f32 depth;
};

struct RadarFanDesc_801FA880 {
    f32 *pos;
    u32 *col;
    s32 a;
    s32 n;
};

extern "C" {
void TCameraCtrl__sub_80068EF0(void);
extern u32 TRaderMapCore__data_805D5F4C;
extern RadarSpriteFrame_801FA6CC lbl_804C87E4[];
extern f32 lbl_804C87B4[][4];
extern f32 lbl_805D35F0;
extern u8 *TRaderMapCore__floor_map_resource;
extern s32 lbl_805D5F2C;
extern s32 TRaderMapCore__data_805D5F30;
extern s32 TRaderMapCore__view_mode;
extern void *TRaderMapCore__instance;
void TCameraCtrl__sub_801E32D8(f32 farg0, f32 farg1);
s32 GXSetScissorBoxOffset(int, int);
extern Rect_801F9228 radar_map_view_scissor_table[3];
extern s32 camera_ctrl_instance;
struct TRaderMapCoreMapViewState { s32 value; u8 remaining[0x74]; };
extern TRaderMapCoreMapViewState TRaderMapCore__map_view_state;
extern f32 lbl_805D35F4;
extern f32 lbl_805D35F8;
s32 memset(void *, int, int);
struct RecoveredGlobal_lbl_8044A770 { s32 value; u8 remaining[0x8]; };
extern RecoveredGlobal_lbl_8044A770 lbl_8044A770;
struct RecoveredGlobal_lbl_8044A77C { s32 value; u8 remaining[0xC]; };
extern RecoveredGlobal_lbl_8044A77C lbl_8044A77C;
extern RadarViewRect_801FA9D8 radar_map_view_rect_table[3];
void begin_map_view__13TRaderMapCoreFii(s32 arg0, s32 arg1);
extern s16 *TRaderMapCore__floor_discovery_table[];
extern int TRaderMapCore__map_heap;
s32 init_radar_floor_flags(s32 floor, RadarInitMap_801F9474 *map);
void* __ct__5THeapFUli(void*, u32, s32);
void* __nw__5THeapFUl(u32);
void TRaderMapCore__sub_801F95CC(void);
void GXSetScissor(u32, u32, u32, u32);
s32 TCameraCtrl__sub_80069304();
int check_flag_100__10TObjPlayerFPv(void *p);
void *get_player_by_client_id(s32 i);
extern u8 TCameraCtrl__view_state[];
extern s32 TRaderMapCore__render_mode;
f32 xz_distance_squared(void *, void *);
extern Gate_801FA1E0 TRaderMapCore__marker_buffer[128];
s32 minimap_render_dot(Vec *arg0, s32 arg1, s16 arg2, s32 arg3);
s32 minimap_render_gate(Vec *pos, u32 color, u16 rot, s16 kind, s32 flags);
s32 add_radar_scaled_marker(Vec *arg0, s32 arg1, s16 arg2, s32 arg3, f32 scale);
s32 add_radar_scaled_gate(Vec *pos, s32 color, u16 rot, s16 kind, s32 flags, f32 scale);
}
void update_radar_auto_discovery(TRaderMapCore *core, s32 arg1, void *arg2);
extern "C" {
void rotate_vector_by_matrix(void *, Vec *, Vec *);
void rotate_matrix_y(void *, s32);
s32 push_matrix_from(void *src);
s32 pop_matrix(void);
extern Vec lbl_8044A794;
extern u8 identity_matrix[];
extern f32 lbl_805D3608;
extern f32 radar_overhead_projection_scale;
void setup_overhead_projection__13TRaderMapCoreFv(s32 arg0, Cam_801F9314 *arg1);
}
void rotate_matrix_zyx(void *m, s32 x, s32 y, s32 z);
extern "C" {
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
void push_matrix(void);
void draw_ginja_model(s32);
void set_chunk_material_override_pair(s32, s32);
extern Color_801FAAEC radar_map_backdrop_color;
extern u8 saved_model_draw_color[];
extern u8 model_material_color[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
void TRaderMapCore__sub_801F967C(TRaderMapCore *self, u32 color);
void scale_matrix(s32, f32, f32, f32);
void draw_ginja_object(void *child);
int get_entity_id(void*);
s32 get_current_floor(void);
s32 get_floor__10TObjPlayerFv(void);
s32 TLobby__sub_801C19D0(void *);
s32 should_show_map__13TRaderMapCoreFv(void);
extern Vec4_801F9E9C radar_player_slot_color_table[];
extern s32 local_client_id;
NJS_POINT2 TRaderMapCore__sub_801F9D38(TRaderMapCore *self);
extern const NJS_POINT2 lbl_8044A78C;
s32 has_flag__13TRaderMapCoreFv(void *, s32);
s32 is_on_current_screen__11TCameraCtrlFv(void *, s32);
s32 apply_packed_flags__13TRaderMapCoreFllll(void *, s32, s32, s32);
extern Pad_801FAF24 controller_input_state[];
void GXSetViewport(f32, f32, f32, f32, f32, f32);

int __dt__5THeapFv(void*, void*);
s32 is_card_flag_set__19TWindowKeyBoardHardFv(u16);

s32 TRaderMapCore::is_render_admitted_default() {
    return is_render_admitted((void *)TRaderMapCore__view_mode);
}

s32 TRaderMapCore::is_active() {
    if ((void *) TRaderMapCore__instance != NULL) {
        if (((TRaderMapCore *)TRaderMapCore__instance)->m_flags & 0x10) {
            return 0;
        }
        return ((TRaderMapCore *)TRaderMapCore__instance)->is_render_admitted_default();
    }
    return 0;
}

s32 should_show_map__13TRaderMapCoreFv(void) {
    if ((TRaderMapCore::is_not_split_screen() == 1) && (TLobby::is_ready() == 0)) {
        return 0;
    }
    return TTecCtrl::is_technique_ready();
}
}
void TRaderMapCore::reset_counter() { this->m_184 = 0; }

void TRaderMapCore::hide_radar() {
    if ((void *) (*(u8 * *)&TRaderMapCore__instance) != NULL) {
        ((TRaderMapCore *)(*(u8 * *)&TRaderMapCore__instance))->reset_counter();
        ((TObject *)(*(u8 * *)&TRaderMapCore__instance))->disallow_rendering();
    }
}

void TRaderMapCore::show_radar() {
    if ((void *) (*(u8 * *)&TRaderMapCore__instance) != NULL) {
        ((TRaderMapCore *)(*(u8 * *)&TRaderMapCore__instance))->reset_counter();
        ((TObject *)(*(u8 * *)&TRaderMapCore__instance))->allow_rendering();
    }
}
void set_camera_look_at(u8 *eye, u8 *target, u8 *up);
#pragma fp_contract on

void TRaderMapCore::configure_viewport(const RadarViewportParameters* view) {
    f32 offset_x;
    f32 offset_y;
    GXSetViewport(0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
    GXSetScissorBoxOffset(0, 0);
    offset_x = -(view->center_x - 320.0f);
    offset_y = -(view->center_y - 240.0f);
    TCameraCtrl__sub_801E32D8(view->center_x, view->center_y);
    GXSetScissorBoxOffset(offset_x, offset_y);
}

s32 TRaderMapCore::set_view_scissor(void *self, int mode, void *arg2) {
    Rect_801F9228 *rect = (Rect_801F9228 *)arg2;
    u32 w;
    u32 h;
    u32 y;
    if (mode == 2) {
        w = 32.0f * (rect->x1 - rect->x0);
        h = 32.0f * (rect->y1 - rect->y0);
        y = 240.0f - 0.5f * h;
        GXSetScissor((u32)(320.0f - 0.5f * w), y, w, h);
    } else {
        GXSetScissor(0, 0, 0x280, 0x1E0);
    }
}
#pragma fp_contract reset

void setup_overhead_projection__13TRaderMapCoreFv(s32 arg0, Cam_801F9314 *arg1) {
    Vec up = lbl_8044A794;
    Vec eye;
    Vec at;
    eye.x = arg1->dir.x * lbl_805D3608;
    eye.y = arg1->dir.y * lbl_805D3608;
    eye.z = arg1->dir.z * lbl_805D3608;
    at.x = arg1->pos.x + eye.x;
    at.y = arg1->pos.y + eye.y;
    at.z = arg1->pos.z + eye.z;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, 0x8000 - arg1->rot);
    rotate_vector_by_matrix(0, &up, &up);
    pop_matrix();
    set_perspective_projection_from_fov((182.04445f * radar_overhead_projection_scale), 1.1333334f, 1.0f, 10000.0f);
    set_camera_look_at((u8 *)&eye, (u8 *)&at, (u8 *)&up);
}

s32 TRaderMapCore::save_floor_discovery(int floor, void *map_data) {
    Map_801F9418 *map = (Map_801F9418 *)map_data;
    s16* saved = ((s16* *)&TRaderMapCore__floor_discovery_table)[floor];
    s16* p;
    Piece_801F9418* piece;
    s32 i;
    if (saved != NULL) {
        for (i = 0, piece = map->pieces, p = saved; i < map->count; i++, piece++, p++) {
            *p = piece->flags;
        }
    } else {
        return 0;
    }
    return 1;
}

s32 init_radar_floor_flags(s32 floor, RadarInitMap_801F9474 *map) {
    s16 *saved = TRaderMapCore__floor_discovery_table[floor];
    s16 *p;
    RadarInitPiece_801F9474 *piece;
    s32 i;
    s32 j;
    if (saved != NULL) {
        for (i = 0, piece = map->pieces, p = saved; i < map->count; i++, piece++, p++) {
            piece->flags = *p;
        }
    } else {
        saved = (s16 *) ((THeap *)TRaderMapCore__map_heap)->heap_zalloc((u32) map->count * 2);
        if (saved != NULL) {
            TRaderMapCore__floor_discovery_table[floor] = saved;
        } else {
            return 0;
        }
        for (j = 0, piece = map->pieces; j < map->count; j++, piece++) {
            piece->flags |= 1;
        }
    }
    return 1;
}

void TRaderMapCore::free_map_data() {
    s32 i;
    for (i = 0x11; i >= 0; i--) {
        if (((s16* *)&TRaderMapCore__floor_discovery_table)[i] != NULL) {
            ((THeap *)TRaderMapCore__map_heap)->heap_free(((s16* *)&TRaderMapCore__floor_discovery_table)[i]);
            ((s16* *)&TRaderMapCore__floor_discovery_table)[i] = NULL;
        }
    }
}

void TRaderMapCore::free_heap() { __dt__5THeapFv((void*)TRaderMapCore__map_heap, (void*)1); TRaderMapCore__map_heap = 0; }

void TRaderMapCore__sub_801F95CC(void) {
    s32 i;
    void* p = __nw__5THeapFUl(0x14);
    if (p != NULL) {
        p = __ct__5THeapFUli(p, 0x1000, 0x20);
    }
    TRaderMapCore__map_heap = (int)p;
    for (i = 0; i < 0x12; i++) {
        ((s16* *)&TRaderMapCore__floor_discovery_table)[i] = NULL;
    }
}

void TRaderMapCore::set_piece_flags(s32 arg0) {
    if (TRaderMapCore__floor_map_resource != 0) {
        Map_801F9630* m = (Map_801F9630*)TRaderMapCore__floor_map_resource;
        if (m->pieces != 0) {
            Piece_801F9630* piece = m->pieces;
            s32 i;
            for (i = 0; i < ((Map_801F9630*)TRaderMapCore__floor_map_resource)->count; i++, piece++) {
                piece->flags |= arg0;
            }
        }
    }
}

void TRaderMapCore__sub_801F967C(TRaderMapCore *self, u32 color) {
    f32 rgba[4];
    rgba[0] = (f32)(color >> 24) / 255.0f;
    rgba[1] = (f32)(u8)(color >> 16) / 255.0f;
    rgba[2] = (f32)(u8)(color >> 8) / 255.0f;
    rgba[3] = (f32)(u8)color / 255.0f;
    set_constant_material((const NJS_ARGB *)rgba);
}

void TRaderMapCore::add_zoom_distance(f32 farg0) {
    f32 temp_f0;
    if (((s32) TRaderMapCore__view_mode == 1) || ((s32) TRaderMapCore__view_mode == 2)) {
        temp_f0 = *(f32 *)((s8 *)&TRaderMapCore__map_view_state.value + 0x2C) + farg0;
        *(f32 *)((s8 *)&TRaderMapCore__map_view_state.value + 0x2C) = temp_f0;
        if (temp_f0 < lbl_805D35F4) {
            *(f32 *)((s8 *)&TRaderMapCore__map_view_state.value + 0x2C) = (f32) lbl_805D35F4;
        }
        if (*(f32 *)((s8 *)&TRaderMapCore__map_view_state.value + 0x2C) > lbl_805D35F8) {
            *(f32 *)((s8 *)&TRaderMapCore__map_view_state.value + 0x2C) = (f32) lbl_805D35F8;
        }
    }
}

#define MAP_801F9C54 ((struct Map_801F9C54 *) TRaderMapCore__floor_map_resource)

void TRaderMapCore::open_free_map_view() {
    s32 g = (s32)&TRaderMapCore__map_view_state;
    TRaderMapCore__view_mode = 1;
    {
        NJS_POINT2 p = TRaderMapCore__sub_801F9D38((TRaderMapCore *)TRaderMapCore__instance);
        ((Glob_801F9770 *)g)->f28 = p.x;
        ((Glob_801F9770 *)g)->f30 = p.y;
    }
}

void TRaderMapCore::pan_vertical(f32 farg0) {
    if (TRaderMapCore__view_mode == 1 || TRaderMapCore__view_mode == 2) {
        Glob_801F97C4 *g = (Glob_801F97C4 *)&TRaderMapCore__map_view_state;
        g->f30 -= farg0;
        switch (get_current_floor_area()) {
        case AREA_VOL_OPT:
        case AREA_DARK_FALZ:
        case AREA_OLGA_FLOW:
        case AREA_TOWER:
            return;
        default:
            if (g->f30 < -6000.0f) {
                g->f30 = -6000.0f;
            }
            if (g->f30 > 6000.0f) {
                g->f30 = 6000.0f;
            }
            break;
        }
    }
}

void TRaderMapCore::pan_horizontal(f32 farg0) {
    if (TRaderMapCore__view_mode == 1 || TRaderMapCore__view_mode == 2) {
        Glob_801F986C *g = (Glob_801F986C *)&TRaderMapCore__map_view_state;
        g->f28 -= farg0;
        switch (get_current_floor_area()) {
        case AREA_VOL_OPT:
        case AREA_DARK_FALZ:
        case AREA_OLGA_FLOW:
        case AREA_TOWER:
            return;
        default:
            if (g->f28 < -6000.0f) {
                g->f28 = -6000.0f;
            }
            if (g->f28 > 6000.0f) {
                g->f28 = 6000.0f;
            }
            break;
        }
    }
}

// Dead-stripped from the DOL: no code of it survives, only its literal 22.0f (0x805DC560, pooled
// between pan_horizontal's and add_radar_scaled_gate's). It gives every player marker the scale
// that the constructor and gather_player_markers (map modes 0 and 1) store. Name inferred.
void TRaderMapCore::reset_marker_scale() {
    for (s32 i = 0; i < 4; i++) {
        player_marker_records[i].scale = 22.0f;
    }
}

s32 add_radar_scaled_gate(Vec *pos, s32 color, u16 rot, s16 kind, s32 flags, f32 scale) {
    Vec *cam = (Vec *)&TRaderMapCore__map_view_state;
    Vec v;
    if (TRaderMapCore__data_805D5F30 > 0x7F) {
        return 0;
    }
    if (!(flags & 1)) {
        v.x = cam->x;
        v.z = cam->z;
        if (xz_distance_squared(pos, &v) > 90000.0f) {
            return 0;
        }
    }
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].x = pos->x;
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].z = pos->z;
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].scale = scale;
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].color = color;
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].kind = kind;
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].rot = rot;
    TRaderMapCore__data_805D5F30++;
    return 1;
}

s32 add_radar_scaled_marker(Vec *pos, s32 arg1, s16 arg2, s32 arg3, f32 scale) {
    Vec *cam = (Vec *)&TRaderMapCore__map_view_state;
    Vec v;
    u8 pad[0x10];
    Dot_801F9B8C *d;
    if (TRaderMapCore__data_805D5F30 > 0x7F) {
        return 0;
    }
    if (!(arg3 & 1)) {
        v.x = cam->x;
        v.z = cam->z;
        if (xz_distance_squared(pos, &v) > 90000.0f) {
            return 0;
        }
    }
    ((Dot_801F9B8C *)&TRaderMapCore__marker_buffer)[TRaderMapCore__data_805D5F30].x = pos->x;
    d = &((Dot_801F9B8C *)&TRaderMapCore__marker_buffer)[TRaderMapCore__data_805D5F30];
    d->z = pos->z;
    d->w = scale;
    d->color = arg1;
    d->type = arg2;
    d->c = 0;
    TRaderMapCore__data_805D5F30++;
    return 1;
}

s32 minimap_render_gate(Vec *pos, u32 color, u16 rot, s16 kind, s32 flags) {
    Vec *cam = (Vec *)&TRaderMapCore__map_view_state;
    Vec v;
    u8 pad[0x10];
    if (TRaderMapCore__data_805D5F30 > 0x7F) {
        return 0;
    }
    if (!(flags & 1)) {
        v.x = cam->x;
        v.z = cam->z;
        if (xz_distance_squared(pos, &v) > 90000.0f) {
            return 0;
        }
    }
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].x = pos->x;
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].z = pos->z;
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].scale = 1.0f;
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].color = color;
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].kind = kind;
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].rot = rot;
    TRaderMapCore__data_805D5F30++;
    return 1;
}

s32 minimap_render_dot(Vec *pos, s32 arg1, s16 arg2, s32 arg3) {
    Vec *cam = (Vec *)&TRaderMapCore__map_view_state;
    Vec v;
    u8 pad[0x10];
    Dot_801F9B8C *d;
    if (TRaderMapCore__data_805D5F30 > 0x7F) {
        return 0;
    }
    if (!(arg3 & 1)) {
        v.x = cam->x;
        v.z = cam->z;
        if (xz_distance_squared(pos, &v) > 90000.0f) {
            return 0;
        }
    }
    ((Dot_801F9B8C *)&TRaderMapCore__marker_buffer)[TRaderMapCore__data_805D5F30].x = pos->x;
    d = &((Dot_801F9B8C *)&TRaderMapCore__marker_buffer)[TRaderMapCore__data_805D5F30];
    d->z = pos->z;
    d->w = 1.0f;
    d->color = arg1;
    d->type = arg2;
    d->c = 0;
    TRaderMapCore__data_805D5F30++;
    return 1;
}

s32 TRaderMapCore::block_region_by_id(s16 id) {
    s32 i;
    if (MAP_801F9C54 == NULL) {
        return 0;
    }
    for (i = 0; i < MAP_801F9C54->count; i++) {
        if (MAP_801F9C54->regions[i].id == id) {
            MAP_801F9C54->regions[i].flags |= 2;
            return 1;
        }
    }
    return 0;
}

#define MAP_801F9CB8 ((struct Map_801F9CB8 *) TRaderMapCore__floor_map_resource)
s32 TRaderMapCore::reveal_region_by_id(s16 id) {
    s32 i;
    if (MAP_801F9CB8 == NULL) {
        return 0;
    }
    for (i = 0; i < MAP_801F9CB8->count; i++) {
        if (MAP_801F9CB8->regions[i].id == id && (MAP_801F9CB8->regions[i].flags & 1)) {
            MAP_801F9CB8->regions[i].flags &= ~1;
            MAP_801F9CB8->regions[i].fade = -1.0f;
            return 1;
        }
    }
    return 0;
}

#define MAP_801F9D84 ((Map_801F9D84 *) TRaderMapCore__floor_map_resource)
NJS_POINT2 TRaderMapCore__sub_801F9D38(TRaderMapCore *self) {
    NJS_POINT2 p = lbl_8044A78C;
    if (self->m_134 >= 0) {
        p.x = ((Core_801F9E9C *)self)->e[self->m_134].x;
        p.y = ((Core_801F9E9C *)self)->e[self->m_134].z;
    }
    return p;
}

void update_radar_auto_discovery(TRaderMapCore *core, s32 arg1, void *pos) {
    Vec v;
    Region_801F9D84 *r;
    s32 i;
    if (MAP_801F9D84 != NULL) {
        r = MAP_801F9D84->regions;
        for (i = 0; i < MAP_801F9D84->count; i++, r++) {
            if (!(r->flags & 2) && (r->flags & 1)) {
                if (r->flags & 4) {
                    v.x = r->x + r->model->m->b.x;
                    v.y = r->y + r->model->m->b.y;
                    v.z = r->z + r->model->m->b.z;
                } else {
                    v.x = r->x + r->model->m->a.x;
                    v.y = r->y + r->model->m->a.y;
                    v.z = r->z + r->model->m->a.z;
                }
                if (xz_distance_squared(&v, pos) < r->radius * r->radius) {
                    r->flags &= ~1;
                    r->fade = -1.0f;
                }
            }
        }
    }
}

// The m_168 bit update_target sets while TWindowKeyBoardHard::is_card_flag_set holds for the
// target's entity id. It is a const object, not a literal: update_target loads it (lwz), and its
// definition here puts it in the pool between reveal_region_by_id's -1.0f and the 10.0f below.
extern const u32 lbl_805DC56C = 1;

// Dead-stripped from the DOL: no code of it survives, only its literals 10.0f and -10.0f
// (0x805DC570, 0x805DC574), pooled in that order between lbl_805DC56C and gather_player_markers'
// 15.4f. gather_player_markers lifts a shown player's marker to 10.0f; this reconstruction drops
// a hidden one below the map. Name inferred.
void TRaderMapCore::set_marker_shown(s32 slot, s32 shown) {
    player_marker_records[slot].y = shown ? 10.0f : -10.0f;
}

#define SHOW(t) ((s32 (*)(void *))should_show_map__13TRaderMapCoreFv)(t)
void TRaderMapCore::gather_player_markers() {
    s32 floor;
    Entry_801F9E9C *e;
    s32 team;
    s32 i;
    Player_801F9E9C *p;
    Entry_801F9E9C *me;
    team = 0;
    floor = get_current_floor();
    ((Core_801F9E9C *)this)->unk134 = -1;
    p = (Player_801F9E9C *)get_player_by_client_id(local_client_id);
    me = &((Core_801F9E9C *)this)->e[0];
    if (p != NULL) {
        team = TLobby__sub_801C19D0(p->sub828);
        if (((TObjPlayer *)p)->is_body_collision_inactive() == 0) {
            VecCopy((Vec *)me, (const Vec *)p->pos);
            me->y = 10.0f;
            me->unkC = p->unk60;
            me->id = local_client_id;
            ((Core_801F9E9C *)this)->unk134 = 0;
            if (SHOW(this) != 0) {
                if (team == 1) {
                    copy_argb((NJS_ARGB *)&me->color, (NJS_ARGB *)&radar_player_slot_color_table[0]);
                } else if (team == 2) {
                    copy_argb((NJS_ARGB *)&me->color, (NJS_ARGB *)&radar_player_slot_color_table[1]);
                } else {
                    copy_argb((NJS_ARGB *)&me->color, (NJS_ARGB *)&radar_player_slot_color_table[2]);
                }
            } else {
                copy_argb((NJS_ARGB *)&me->color, (NJS_ARGB *)(&radar_player_slot_color_table[(u16)get_entity_id(p)]));
            }
        } else {
            ((TRaderMapCore *)me)->reset();
        }
    } else {
        ((TRaderMapCore *)me)->reset();
    }
    e = &((Core_801F9E9C *)this)->e[1];
    for (i = 0; i < 4; i++) {
        if (i == local_client_id) {
            continue;
        }
        if (SHOW(this) == 0) {
            p = (Player_801F9E9C *)get_player_by_client_id(i);
            if (p != NULL && floor == get_floor__10TObjPlayerFv() &&
                ((TObjPlayer *)p)->is_body_collision_inactive() == 0) {
                VecCopy((Vec *)e, (const Vec *)p->pos);
                e->y = 10.0f;
                e->unkC = p->unk60;
                e->id = i;
                copy_argb((NJS_ARGB *)&e->color, (NJS_ARGB *)(&radar_player_slot_color_table[(u16)get_entity_id(p)]));
            } else {
                ((TRaderMapCore *)e)->reset();
            }
        } else if (team != 0) {
            p = (Player_801F9E9C *)get_player_by_client_id(i);
            if (p != NULL && floor == get_floor__10TObjPlayerFv() &&
                team == TLobby__sub_801C19D0(p->sub828) &&
                ((TObjPlayer *)p)->is_body_collision_inactive() == 0) {
                VecCopy((Vec *)e, (const Vec *)p->pos);
                e->y = 10.0f;
                e->unkC = p->unk60;
                e->id = i;
                if (team == 1) {
                    copy_argb((NJS_ARGB *)&e->color, (NJS_ARGB *)&radar_player_slot_color_table[0]);
                } else if (team == 2) {
                    copy_argb((NJS_ARGB *)&e->color, (NJS_ARGB *)&radar_player_slot_color_table[1]);
                } else {
                    copy_argb((NJS_ARGB *)&e->color, (NJS_ARGB *)&radar_player_slot_color_table[2]);
                }
            } else {
                ((TRaderMapCore *)e)->reset();
            }
        } else {
            ((TRaderMapCore *)e)->reset();
        }
        e++;
    }
    switch (((Core_801F9E9C *)this)->mode) {
    case 0:
        for (s32 j = 0; j < 4; j++) {
            player_marker_records[j].scale = 22.0f;
        }
        break;
    case 1:
        for (s32 j = 0; j < 4; j++) {
            player_marker_records[j].scale = 22.0f;
        }
        break;
    case 2:
        for (s32 j = 0; j < 4; j++) {
            player_marker_records[j].scale = 15.4f;
        }
        break;
    }
}

void TRaderMapCore::draw_enemy_gate_markers() {
    Gate_801FA1E0 *g;
    s32 i;
    saved_model_render_flags = model_render_flags;
    copy_argb((NJS_ARGB *)&saved_model_draw_color, (NJS_ARGB *)&model_material_color);
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= this->m_194;
    set_chunk_material_override_pair(-0xFF01, 0x100);
    for (i = 0, g = (Gate_801FA1E0 *)&TRaderMapCore__marker_buffer; i < TRaderMapCore__data_805D5F30; i++, g++) {
        TRaderMapCore__sub_801F967C(this, g->color);
        push_matrix();
        translate_matrix(0, g->x, 0.0f, g->z);
        rotate_matrix_y(0, g->rot);
        switch (g->kind) {
        case 0:
            scale_matrix(0, 13.6f * g->scale, 8.0f, 5.6f * g->scale);
            draw_ginja_object(this->m_180);
            break;
        case 1:
            scale_matrix(0, 8.0f * g->scale, 8.0f, 8.0f * g->scale);
            draw_ginja_object(this->m_17c);
            break;
        }
        pop_matrix();
    }
    set_constant_material(&chunk_material_color_half_alpha_f32);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    copy_argb((NJS_ARGB *)&model_material_color, (NJS_ARGB *)&saved_model_draw_color);
    model_render_flags = saved_model_render_flags;
}

void TRaderMapCore::draw_player_markers() {
    u8 *var_r31;
    s32 var_r30;
    saved_model_render_flags = model_render_flags;
    copy_argb((NJS_ARGB *)&saved_model_draw_color, (NJS_ARGB *)&model_material_color);
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= this->m_194;
    set_chunk_material_override_pair(-0xFF01, 0x100);
    var_r31 = ((u8 *)&this->player_marker_records);
    var_r30 = 0;
    do {
        if ((s16) *(s16 *)((s8 *)var_r31 + 0x16) != -1) {
            set_constant_material((const NJS_ARGB *)((var_r31 + 0x18)));
            push_matrix();
            translate_matrix(0, *(f32 *)((s8 *)var_r31 + 0x0), 0.0f, *(f32 *)((s8 *)var_r31 + 0x8));
            rotate_matrix_y(0, *(s32 *)((s8 *)var_r31 + 0xC));
            scale_matrix(0, *(f32 *)((s8 *)var_r31 + 0x10), *(f32 *)((s8 *)var_r31 + 0x10), *(f32 *)((s8 *)var_r31 + 0x10));
            draw_ginja_object(this->m_178);
            pop_matrix();
            set_constant_material(&chunk_material_color_half_alpha_f32);
        }
        var_r30 += 1;
        var_r31 = (var_r31 + 0x28);
    } while (var_r30 < 4);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    copy_argb((NJS_ARGB *)&model_material_color, (NJS_ARGB *)&saved_model_draw_color);
    model_render_flags = saved_model_render_flags;
}

struct RadarView_801FA46C {
    f32 x;
    f32 distance;
    f32 z;
    u8 padC[0xC];
    s32 rot;
    u8 pad1C[0xC];
};

void TRaderMapCore::update_follow_projection(s32 mode) {
    RadarView_801FA46C *view = (RadarView_801FA46C *)&TRaderMapCore__map_view_state;
    RadarView_801FA46C *free_view = view + 1;
    RadarView_801FA46C *out = view + 2;
    if (this->m_134 >= 0) {
        view->x = this->player_marker_records[this->m_134].x;
        view->z = this->player_marker_records[this->m_134].z;
    }
    if (this->m_168 & 1) {
        view->rot = 0x8000 - ((TCameraCtrl *)camera_ctrl_instance)->yaw;
        if (get_current_floor_area() == AREA_DE_ROL_LE) {
            free_view->rot = 0;
            this->m_174 = 0x8000 - ((TCameraCtrl *)camera_ctrl_instance)->yaw;
        } else {
            free_view->rot = 0x8000;
            this->m_174 = -((TCameraCtrl *)camera_ctrl_instance)->yaw;
        }
    } else if (get_current_floor_area() == AREA_DE_ROL_LE) {
        view->rot = 0;
        free_view->rot = 0;
        this->m_174 = 0;
    } else {
        view->rot = 0x8000;
        free_view->rot = 0x8000;
        this->m_174 = 0;
    }
    if (this->m_168 & 2) {
        switch (this->m_16c) {
        case 0:
            this->m_170 *= 1.2f;
            view->distance += this->m_170;
            if (view->distance > lbl_805D35F0) {
                view->distance = lbl_805D35F0;
            }
            break;
        case 1:
            this->m_170 *= 1.2f;
            view->distance += this->m_170;
            if (view->distance > lbl_805D35F8) {
                view->distance = lbl_805D35F8;
            }
            break;
        case 2:
            this->m_170 *= 1.2f;
            view->distance -= this->m_170;
            if (view->distance < lbl_805D35F4) {
                view->distance = lbl_805D35F4;
            }
            break;
        }
    } else {
        view->distance = lbl_805D35F0;
    }
    if (mode == 2) {
        ((TRaderMapCore *)out)->copy_transform(free_view);
    } else {
        ((TRaderMapCore *)out)->copy_transform(view);
    }
}

void TRaderMapCore::copy_transform(void* q) { *(f32 *)&this->m_name = *(f32*)((char*)q + 0x0); *(f32 *)&this->m_flags = *(f32*)((char*)q + 0x4); *(f32 *)&this->m_prev = *(f32*)((char*)q + 0x8); *(f32 *)&this->m_next = *(f32*)((char*)q + 0xc); *(f32 *)&this->m_up = *(f32*)((char*)q + 0x10); *(f32 *)&this->m_down = *(f32*)((char*)q + 0x14); *(u32*)((char*)this + 0x18) = *(u32*)((char*)q + 0x18); *(u32 *)&this->entity_id = *(u32*)((char*)q + 0x1c); *(f32 *)&this->m_20 = *(f32*)((char*)q + 0x20); *(f32 *)&this->texlist = *(f32*)((char*)q + 0x24); }

Color_801FAAEC radar_map_backdrop_color = { 1.0f, 0.3f, 0.3f, 0.3f };
RadarViewRect_801FA9D8 radar_map_view_rect_table[3] = {
    { 544.0f, 128.0f, 640.0f, 480.0f, 500.0f },
    { 256.0f, 352.0f, 640.0f, 480.0f, 500.0f },
    { 320.0f, 240.0f, 640.0f, 480.0f, 500.0f },
};
Rect_801F9228 radar_map_view_scissor_table[3] = {
    { 15.0f, 2.0f, 19.0f, 6.0f },
    { 1.0f, 9.0f, 15.0f, 13.0f },
    { 1.0f, 9.0f, 15.0f, 13.0f },
};
f32 lbl_804C87B4[3][4] = {
    { 575.0f, 149.0f, 575.0f, 159.0f },
    { 450.0f, 373.0f, 450.0f, 383.0f },
    { 450.0f, 373.0f, 450.0f, 383.0f },
};
RadarSpriteFrame_801FA6CC lbl_804C87E4[2] = {
    { 32, 32, 16, 27, 0, 0, 256, 256, 0, 0 },
    { 32, 32, 16, 16, 0, 0, 256, 256, 1, 0 },
};

// The sprite block draw_compass_sprite reads: screen position, depth, scale,
// rotation, the texture list and the frame table.
struct RadarCompassSprite_801FA6CC {
    f32 x;
    f32 y;
    f32 z;
    f32 scale_x;
    f32 scale_y;
    s32 rotation;
    u32 texlist;
    RadarSpriteFrame_801FA6CC *frames;
};

void TRaderMapCore::draw_compass(s32 mode) {
    RadarCompassSprite_801FA6CC sprite;
    u32 color;
    f32 *compass_xy;
    f32 *marker_xy;
    if (apply_compass_param(&m_90) != 0) {
        sprite.x = 0.0f;
        sprite.y = 0.0f;
        sprite.z = 0.0f;
        sprite.scale_x = 1.0f;
        sprite.scale_y = 1.0f;
        sprite.rotation = 0;
        sprite.texlist = TRaderMapCore__data_805D5F4C;
        sprite.frames = lbl_804C87E4;
        color = 0xFFFFFFFF;
        TParticleCtrl::begin_effect_render();
        compass_xy = &lbl_804C87B4[mode][0];
        marker_xy = compass_xy + 2;
        sprite.x = marker_xy[0] + lbl_804C87E4[1].x;
        sprite.y = marker_xy[1] + lbl_804C87E4[1].y;
        set_default_alpha_blend();
        ((u8 *)&color)[3] = (u8)m_19c;
        ((TObjPlayer *)&sprite)->draw_compass_sprite(1, ((color & 0xFF00) << 16) | (color >> 16) | ((color & 0xFF) << 16), 0x21, 0.8f);
        sprite.x = compass_xy[0] + lbl_804C87E4[0].x;
        sprite.y = compass_xy[1] + lbl_804C87E4[0].y;
        sprite.rotation = m_174;
        set_additive_blend();
        ((TObjPlayer *)&sprite)->draw_compass_sprite(0, -1, 0x21, 0.8f);
        TParticleCtrl::end_effect_render();
    }
}

static NJS_POINT2 radar_backdrop_origin[3] = { { 480.0f, 64.0f }, { 32.0f, 288.0f }, { 96.0f, 176.0f } };
static NJS_POINT2 radar_backdrop_size[3] = { { 128.0f, 128.0f }, { 448.0f, 128.0f }, { 448.0f, 128.0f } };
static f32 radar_backdrop_alpha[3] = { 64.0f, 64.0f, 128.0f };

void TRaderMapCore::draw_backdrop(TRaderMapCore *self, s32 mode) {
    f32 pos[8];
    RadarFanDesc_801FA880 desc;
    u32 colors[4];
    u32 color;
    NJS_POINT2 *origin;
    NJS_POINT2 *size;
    desc.pos = pos;
    desc.col = colors;
    desc.a = 0;
    desc.n = 4;
    color = 0;
    ((u8 *)&color)[3] = (u8)radar_backdrop_alpha[mode];
    origin = &radar_backdrop_origin[mode];
    size = &radar_backdrop_size[mode];
    pos[0] = origin->x;
    pos[1] = origin->y;
    pos[2] = origin->x + size->x;
    pos[3] = origin->y;
    pos[4] = origin->x + size->x;
    pos[5] = origin->y + size->y;
    pos[6] = origin->x;
    pos[7] = origin->y + size->y;
    colors[0] = color;
    colors[1] = color;
    colors[2] = color;
    colors[3] = color;
    set_default_alpha_blend();
    TParticleCtrl::begin_effect_render();
    ((TObjCMHairMenu *)&desc)->draw_tri_fan_2d(4, 0x16, -10.0f);
    TParticleCtrl::end_effect_render();
}


void TRaderMapCore::setup_view(s32 arg1) {
    s32 arg0 = (s32)this;
    GXSetScissorBoxOffset(0, 0);
    TCameraCtrl__sub_801E32D8(320.0f, 240.0f);
    ((TCameraCtrl *)camera_ctrl_instance)->setup_default_view(0);
    TRaderMapCore::set_view_scissor((void *)arg0, 0, (void *)((void *) ((u8 *)&radar_map_view_scissor_table + (arg1 * 0x10))));
    TObjLight::apply_distant_light();
    TParticleCtrl::end_effect_render();
}

#pragma push
#pragma opt_common_subs off
void begin_map_view__13TRaderMapCoreFii(s32 arg0, s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_801FA9D8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_801FA9D8, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_801FA9D8, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_801FA9D8, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_801FA9D8, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_801FA9D8, sp1C) == 0x14) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_801FA9D8, sp20) == 0x18) ? 1 : -1];
    typedef char viewport_offset[(offsetof(Stack_801FA9D8, viewport) == 0x1C) ? 1 : -1];
    Stack_801FA9D8 stack;
    u8 *temp_r5;
    TCameraCtrl::restore_full_screen_view();
    memset((void *)&stack.viewport, 0, 0x30);
    temp_r5 = (u8 *)&radar_map_view_rect_table + (arg1 * 0x14);
    stack.viewport.center_x = *(f32 *)((s8 *)temp_r5 + 0);
    stack.viewport.center_y = *(f32 *)((s8 *)temp_r5 + 4);
    stack.viewport.screen_width = *(f32 *)((s8 *)temp_r5 + 8);
    stack.viewport.screen_height = *(f32 *)((s8 *)temp_r5 + 0xC);
    stack.viewport.value18 = *(f32 *)((s8 *)temp_r5 + 0x10);
    ((TRaderMapCore*)arg0)->configure_viewport(&stack.viewport);
    TRaderMapCore::set_view_scissor((void *)arg0, 2, (void *)((void *) ((u8 *)&radar_map_view_scissor_table + (arg1 * 0x10))));
    setup_overhead_projection__13TRaderMapCoreFv((s32)arg0, (Cam_801F9314 *)((void *) ((u8 *)&TRaderMapCore__map_view_state.value + (arg1 * 0x28))));
    stack.sp18 = *(s32 *)((s8 *)&lbl_8044A770.value + 0);
    stack.sp1C = *(s32 *)((s8 *)&lbl_8044A770.value + 4);
    stack.sp20 = *(s32 *)((s8 *)&lbl_8044A770.value + 8);
    stack.sp8 = *(s32 *)((s8 *)&lbl_8044A77C.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_8044A77C.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_8044A77C.value + 8);
    stack.sp14 = *(s32 *)((s8 *)&lbl_8044A77C.value + 0xC);
    ((TObjLight *)(&stack.sp18))->set_light((void *)&stack.sp8, 1.0f);
    TParticleCtrl::begin_effect_render();
}
#pragma pop

#define MAP_801FAAEC ((Map_801FAAEC *)TRaderMapCore__floor_map_resource)
void TRaderMapCore::render_region_records(void * _w1) {
    TRaderMapCore *arg0 = this;
    Rec_801FAAEC *r;
    s32 i;
    saved_model_render_flags = model_render_flags;
    copy_argb((NJS_ARGB *)saved_model_draw_color, (NJS_ARGB *)model_material_color);
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= arg0->m_194;
    set_chunk_material_override_pair(-0xFF01, 0x900);
    if (MAP_801FAAEC->tex != 0) {
        TObjFish::set_global_param(MAP_801FAAEC->tex);
    }
    i = 0;
    {
    Color_801FAAEC c = radar_map_backdrop_color;
    r = MAP_801FAAEC->recs;
    for (; i < MAP_801FAAEC->count; i++, r++) {
        if (!(r->flags & 1)) {
            r->alpha += 0.08f;
            if (r->alpha > arg0->m_1a0) {
                r->alpha = arg0->m_1a0;
            }
            c.r = r->alpha;
            set_constant_material((const NJS_ARGB *)(((f32 *)&c)));
            push_matrix();
            translate_matrix(0, r->x, r->y, r->z);
            rotate_matrix_zyx(0, r->rx, r->ry, r->rz);
            draw_ginja_model(r->model->obj);
            pop_matrix();
            set_constant_material(&chunk_material_color_half_alpha_f32);
        }
    }
    }
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
    model_render_flags = saved_model_render_flags;
}

void TRaderMapCore::render() {
    u8 *arg0 = (u8 *)this;
    if ((u32) TRaderMapCore__floor_map_resource != 0U) {
        if (is_render_admitted((void *)TRaderMapCore__view_mode) == 0) {
            lbl_805D5F2C = 0;
            TRaderMapCore__data_805D5F30 = 0;
            return;
        }
        switch ((s32) TRaderMapCore__view_mode) {
        case 0:
            TRaderMapCore::draw_backdrop((TRaderMapCore *)arg0, TRaderMapCore__view_mode);
            begin_map_view__13TRaderMapCoreFii((s32)arg0, (s32)TRaderMapCore__view_mode);
            render_region_records((void *)TRaderMapCore__view_mode);
            ((TRaderMapCore *)arg0)->draw_enemy_gate_markers();
            draw_player_markers();
            setup_view(TRaderMapCore__view_mode);
            draw_compass(TRaderMapCore__view_mode);
            break;
        case 1:
            TCameraCtrl::restore_full_screen_view();
            TRaderMapCore::draw_backdrop((TRaderMapCore *)arg0, TRaderMapCore__view_mode);
            TCameraCtrl__sub_80068EF0();
            begin_map_view__13TRaderMapCoreFii((s32)arg0, (s32)TRaderMapCore__view_mode);
            render_region_records((void *)TRaderMapCore__view_mode);
            ((TRaderMapCore *)arg0)->draw_enemy_gate_markers();
            draw_player_markers();
            setup_view(TRaderMapCore__view_mode);
            TCameraCtrl::restore_full_screen_view();
            this->m_174 = 0;
            draw_compass(TRaderMapCore__view_mode);
            TCameraCtrl__sub_80068EF0();
            break;
        case 2:
            TRaderMapCore::draw_backdrop((TRaderMapCore *)arg0, TRaderMapCore__view_mode);
            begin_map_view__13TRaderMapCoreFii((s32)arg0, (s32)TRaderMapCore__view_mode);
            render_region_records((void *)TRaderMapCore__view_mode);
            ((TRaderMapCore *)arg0)->draw_enemy_gate_markers();
            draw_player_markers();
            setup_view(TRaderMapCore__view_mode);
            break;
        }
        lbl_805D5F2C = 0;
        TRaderMapCore__data_805D5F30 = 0;
    }
}

s32 TRaderMapCore::is_render_admitted(void *arg1) {
    s32 i;
    u32 p;
    if (TRaderMapCore__render_mode == 0) {
        return 0;
    }
    if (((Radar_801FADF0 *)this)->f184 != 0) {
        if (((TObjPlayer *)(((Radar_801FADF0 *)this)->f184))->is_body_collision_inactive() != 0) {
            return 0;
        }
        if (check_flag_100__10TObjPlayerFPv((void *)(((Radar_801FADF0 *)this)->f184)) != 0 && TRaderMapCore__view_mode != 1) {
            return 0;
        }
    } else {
        return 0;
    }
    if (TCameraCtrl__sub_80069304() != 0 && TWindowCtrl::get_flag_bit0() == 0) {
        return 0;
    }
    if (TCameraCtrl__view_state[0] == 5 || TCameraCtrl__view_state[0] == 9) {
        ((Radar_801FADF0 *)this)->f184 = 0;
        return 0;
    }
    if (((Radar_801FADF0 *)this)->f90 > 0) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        p = (u32)get_player_by_client_id(i);
        if (p != 0 && check_flag_100__10TObjPlayerFPv((void *)p) != 0 && (s32)arg1 == 2) {
            return 0;
        }
    }
    return all_parents_unqueued_for_destruction() != 0 ? 1 : 0;
}

// Dead-stripped from the DOL: no code of it survives, only its literal 500.0f (0x805DC594, pooled
// between render_region_records' 0.08f and update_pan_zoom_input's 6.0f). It stores the defaults
// the constructor gives m_150 and the viewport size, field by field. Name inferred.
void TRaderMapCore::set_default_view_size() {
    m_150 = 500.0f;
    viewport_width = 640.0f;
    viewport_height = 480.0f;
}

void TRaderMapCore::update_pan_zoom_input() {
    u8 *arg0 = (u8 *)this;
    Radar_801FAF24 *self = (Radar_801FAF24 *)arg0;
    u32 p;
    s32 i;
    s32 j;
    s32 k;
    for (i = 0; i < 4; i++) {
        p = (u32)get_player_by_client_id(i);
        if (p != 0 && check_flag_100__10TObjPlayerFPv((void *)p) != 0) {
            return;
        }
    }
    if (self->f184 != 0) {
        for (j = 0; j < 4; j++) {
            p = (u32)get_player_by_client_id(j);
            if (p != 0 && TWindowShortListCtrl__check_controller_button(controller_input_state[((TRaderMapCore *)p)->get_map_id()].ctl, 0x200) != 0) {
                self->f184 = 0;
                return;
            }
        }
        if (is_on_current_screen__11TCameraCtrlFv(controller_input_state[((TRaderMapCore *)(self->f184))->get_map_id()].ctl, 0x10) != 0) {
            self->f18C += 6.0f;
        }
        if (is_on_current_screen__11TCameraCtrlFv(controller_input_state[((TRaderMapCore *)(self->f184))->get_map_id()].ctl, 0x20) != 0) {
            self->f18C -= 6.0f;
        }
        if (is_on_current_screen__11TCameraCtrlFv(controller_input_state[((TRaderMapCore *)(self->f184))->get_map_id()].ctl, 0x40) != 0) {
            self->f188 += 6.0f;
        }
        if (is_on_current_screen__11TCameraCtrlFv(controller_input_state[((TRaderMapCore *)(self->f184))->get_map_id()].ctl, 0x80) != 0) {
            self->f188 -= 6.0f;
        }
        if (apply_packed_flags__13TRaderMapCoreFllll(controller_input_state[((TRaderMapCore *)(self->f184))->get_map_id()].ctl, 0x20000, 0x27, 1) != 0) {
            self->f190 -= 6.0f;
        }
        if (apply_packed_flags__13TRaderMapCoreFllll(controller_input_state[((TRaderMapCore *)(self->f184))->get_map_id()].ctl, 0x10000, 0x27, 1) != 0) {
            self->f190 += 6.0f;
        }
        TRaderMapCore::pan_horizontal(self->f188);
        TRaderMapCore::pan_vertical(self->f18C);
        TRaderMapCore::add_zoom_distance(self->f190);
        self->f188 *= 0.8f;
        self->f18C *= 0.8f;
        self->f190 *= 0.8f;
        return;
    }
    for (k = 0; k < 4; k++) {
        p = (u32)get_player_by_client_id(k);
        if (p != 0 && TWindowShortListCtrl__check_controller_button(controller_input_state[((TRaderMapCore *)p)->get_map_id()].ctl, 0x200) != 0 &&
            has_flag__13TRaderMapCoreFv(controller_input_state[((TRaderMapCore *)p)->get_map_id()].ctl, 0x10000) != 0) {
            self->f184 = p;
            u8 *cam = (u8 *)&TRaderMapCore__map_view_state;
            *(f32 *)((s8 *)cam + 0x28) = *(f32 *)((s8 *)self->f184 + 0x38);
            *(f32 *)((s8 *)cam + 0x30) = *(f32 *)((s8 *)self->f184 + 0x40);
            self->f188 = 0.0f;
            self->f18C = 0.0f;
            self->f190 = 0.0f;
            return;
        }
    }
}


void TRaderMapCore::update_target() {
    u32 temp_r3;

    temp_r3 = (u32)get_player_by_client_id(local_client_id);
    if (temp_r3 != 0U) {
        *(u32 *)&this->m_184 = temp_r3;
    }
    if ((u32) this->m_184 != 0U) {
        if (is_card_flag_set__19TWindowKeyBoardHardFv(get_entity_id((void*)this->m_184)) != 0) {
            this->m_168 |= lbl_805DC56C;
            return;
        }
        this->m_168 = (s32) (this->m_168 & 0xFFFFFFFE);
    }
}

Gate_801FA1E0 TRaderMapCore__marker_buffer[128];
TRaderMapCoreMapViewState TRaderMapCore__map_view_state;
s16 *TRaderMapCore__floor_discovery_table[18];

#pragma fp_contract on

struct RecoveredGlobal_801FB430___vt__13TRaderMapCore {
    s32 value;
    u8 remaining[0x30];
};

struct GRec_801FB490 { u8 pad0[4]; f32 f4; u8 pad8[8]; f32 f10; f32 f14; s32 f18; u8 pad1c[0x28 - 0x1C]; };

struct MRec_801FB490 { f32 v[3]; s32 a0; f32 a4; s16 h[2]; u8 padac[0x28 - 0x18]; };

struct Core_801FB490 {
    s32 f0;
    u8 pad4[0x14];
    s32 *vt;
    u8 pad1c[0x90 - 0x1C];
    s32 f90;
    MRec_801FB490 recs[4];
    s32 f134;
    u8 pad138[0x140 - 0x138];
    f32 f140, f144;
    u8 pad148[0x150 - 0x148];
    f32 f150;
    u8 pad154[0x160 - 0x154];
    f32 f160, f164;
    s32 f168, f16c;
    f32 f170;
    s32 f174, f178, f17c, f180, f184;
    f32 f188, f18c, f190;
    s32 f194, f198;
    f32 f19c, f1a0;
};

extern "C" {
s32 update_pan_zoom_input__13TRaderMapCoreFv();
extern RecoveredGlobal_801FB430___vt__13TRaderMapCore __vt__13TRaderMapCore;
s32 __ct__8TObjBaseFP7TObject(void *, void *);
s32 init_map_ptr__13TRaderMapCoreFv(void *, int);
s32 fn_803D64F8(void *);
extern f32 lbl_805D35FC;
extern s32 rader_map_core_name_ptr;
Core_801FB490 *TRaderMapCore__ct(Core_801FB490 *arg0, void *parent);
f32 sin_table_lookup(s32);


void TRaderMapCore::advance_scroll() {
    this->m_198 = (this->m_198 + 0x888);
    this->m_19c = 127.0f + 64.0f * (1.0f + sin_table_lookup(this->m_198));
}
void run_task__13TRaderMapCoreFv(TRaderMapCore *rader_map_core) {
    s32 player;
    s32 temp_r4;
    s32 var_r31;
    if ((u32) TRaderMapCore__floor_map_resource != 0U) {
        temp_r4 = rader_map_core->m_90;
        if (temp_r4 > 0) {
            rader_map_core->m_90 = (temp_r4 - 1);
            return;
        }
        switch ((s32) TRaderMapCore__view_mode) {
        case 0:
            rader_map_core->update_target();
            break;
        case 1:
            rader_map_core->update_target();
            break;
        case 2:
            update_pan_zoom_input__13TRaderMapCoreFv();
            break;
        }
        rader_map_core->gather_player_markers();
        if ((TRaderMapCore::is_not_split_screen() == 1) && ((u32) *(u32 *)((s8 *)rader_map_core + 0x184) != 0U)) {
            rader_map_core->m_134 = (u16)get_entity_id(rader_map_core->m_184);
        }
        ((TRaderMapCore *)rader_map_core)->update_follow_projection((s32)((void *)TRaderMapCore__view_mode));
        if (TRaderMapCore::is_not_split_screen() == 1) {
            var_r31 = 0;
            do {
                player = (s32)get_player_by_client_id(var_r31);
                if (player != 0) {
                    update_radar_auto_discovery(rader_map_core, 0, (void *)(player + 0x38));
                }
                var_r31 += 1;
            } while (var_r31 < 4);
        } else {
            update_radar_auto_discovery(rader_map_core, 0, (void *) ((u8 *)rader_map_core + rader_map_core->m_134 * 0x28 + 0x94));
        }
        rader_map_core->advance_scroll();
    }
}
typedef char RecoveredGlobal_801FB430___vt__13TRaderMapCore_size[sizeof(RecoveredGlobal_801FB430___vt__13TRaderMapCore) == 0x34 ? 1 : -1];
u8 *__dt__13TRaderMapCoreFv(u8 *base, s16 arg1) {
    if (base != NULL) {
        *(s32 **)((s8 *)base + 0x18) = &__vt__13TRaderMapCore.value;
        TRaderMapCore__instance = 0;
        __dt__8TObjBaseFv(base, 0);
        if (arg1 > 0) {
            TObject::operator delete(base);
        }
    }
    return base;
}
#pragma push
#pragma opt_common_subs off
Core_801FB490 *TRaderMapCore__ct(Core_801FB490 *arg0, void *parent) {
    GRec_801FB490 *g;
    s32 i;
    u32 j;
    __ct__8TObjBaseFP7TObject(arg0, parent);
    arg0->vt = &__vt__13TRaderMapCore.value;
    arg0->f0 = rader_map_core_name_ptr;
    arg0->f178 = init_map_ptr__13TRaderMapCoreFv(&arg0->f90, 2);
    arg0->f17c = init_map_ptr__13TRaderMapCoreFv(&arg0->f90, 0);
    arg0->f180 = init_map_ptr__13TRaderMapCoreFv(&arg0->f90, 1);
    for (i = 0; i < 3; i++) {
        g = (GRec_801FB490 *)&TRaderMapCore__map_view_state + i;
        fn_803D64F8(g);
        g->f4 = lbl_805D35F0;
        g->f10 = -1.0f;
        g->f14 = 0.0f;
        g->f18 = 0x8000;
    }
    arg0->f150 = 500.0f;
    arg0->f160 = 640.0f;
    arg0->f164 = 480.0f;
    arg0->f140 = 544.0f;
    arg0->f144 = 140.0f;
    for (j = 0; j < 4; j++) {
        arg0->recs[j].v[2] = 0.0f;
        arg0->recs[j].v[1] = 0.0f;
        arg0->recs[j].v[0] = 0.0f;
        arg0->recs[j].a0 = 0;
        arg0->recs[j].a4 = 22.0f;
        arg0->recs[j].h[1] = -1;
    }
    arg0->f134 = 0;
    arg0->f168 = 2;
    arg0->f16c = 0;
    arg0->f170 = lbl_805D35FC;
    TRaderMapCore__view_mode = 0;
    arg0->f174 = 0;
    TRaderMapCore__instance = arg0;
    arg0->f90 = 0x3C;
    arg0->f198 = 0;
    arg0->f19c = 0.0f;
    arg0->f184 = 0;
    arg0->f188 = 0.0f;
    arg0->f18c = 0.0f;
    arg0->f190 = 0.0f;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        arg0->f194 = 0x800810;
        TRaderMapCore__view_mode = 2;
    } else {
        arg0->f194 = 0x800810;
    }
    if (TRaderMapCore::is_not_split_screen() == 1) {
        arg0->f1a0 = 0.8f;
    } else {
        arg0->f1a0 = 0.8f;
    }
    if (TRaderMapCore__floor_map_resource == 0) {
        ((TObject *)arg0)->queue_destruction();
        return arg0;
    }
    return arg0;
}
#pragma pop

}

struct Ent_801FB798 { s32 a; char *name; };

extern "C" {
void copy_name(s32 arg0);
s32 replace_file_extension__6TLobbyFPvPvPv(char *arg0, char *arg1, char *arg2);
}
s32 get_floor_scene_table(s32 arg0);
extern "C" {
void bind_gvm_texture_list(char *, u8 *);
}
extern s32 lbl_805D49B4;
extern s8 lbl_805D5F34;
extern s32 lbl_805D5F38;

void TRaderMapCore::create() {
    Core_801FB490 *obj;
    if ((TRaderMapCore::is_not_split_screen() != 1) || (TLobby::is_ready() != 1)) {
        if (TRaderMapCore::is_not_split_screen() == 1) {
            if ((obj = (Core_801FB490 *)TObject::operator new(0x1A4)) != 0) {
                TRaderMapCore__ct(obj, tl_clipout);
            }
        } else if ((obj = (Core_801FB490 *)TObject::operator new(0x1A4)) != 0) {
            TRaderMapCore__ct(obj, tl_radermap);
        }
    }
}

void TRaderMapCore::unload_floor_map() {
    GinjaTextureList *texlist;
    u8 *temp_r31;
    temp_r31 = (u8 *)TRaderMapCore__floor_map_resource;
    if (temp_r31 != NULL) {
        save_floor_discovery(get_current_floor(), temp_r31);
    }
    TRaderMapCore::free_statics();
    if ((void *) TRaderMapCore__floor_map_resource != NULL) {
        texlist = *(GinjaTextureList **)(TRaderMapCore__floor_map_resource + 4);
        if (texlist != NULL) {
            release_texture_list(texlist);
        }
    }
    if ((void *) TRaderMapCore__floor_map_resource != NULL) {
        TLobby::free_nodes_with_id((int)TRaderMapCore__floor_map_resource);
        TRaderMapCore__floor_map_resource = NULL;
    }
    TRaderMapCore__render_mode = 0;
}

void TRaderMapCore::load_map_resources() {
    char buf[32];
    Ent_801FB798 *e;
    s32 status;
    s32 area;
    area = get_current_floor_area();
    status = TScene::get_status();
    e = (Ent_801FB798 *)get_floor_scene_table(area);
    replace_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)e[status].name, (char *)"r.rel");
    TRaderMapCore__floor_map_resource = (u8 *)create_named_object((s32)buf);
    if (TRaderMapCore__floor_map_resource != NULL && *(u32 *)(TRaderMapCore__floor_map_resource + 4) != 0) {
        replace_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)e[status].name, "r");
        bind_gvm_texture_list(buf, *(u8 **)(TRaderMapCore__floor_map_resource + 4));
    }
    copy_name((s32)"..");
    lbl_805D49B4 = 0;
    TRaderMapCore::load_frame_texture();
    e = (Ent_801FB798 *)TRaderMapCore__floor_map_resource;
    if (e != NULL) {
        init_radar_floor_flags(get_current_floor(), (RadarInitMap_801F9474 *)e);
    }
    TRaderMapCore__data_805D5F30 = 0;
    lbl_805D5F34 = 0;
    lbl_805D5F38 = 0;
    TRaderMapCore__render_mode = 1;
}

s32 TRaderMapCore::apply_compass_param(s32 *counter) {
    if ((u32) TRaderMapCore__data_805D5F4C != 0U) {
        TObjFish::set_global_param((s32) TRaderMapCore__data_805D5F4C);
        return 1;
    }
    return -1;
}

extern "C" {
extern u32 TRaderMapCore__frame_model_resource;
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
struct ObjFEnemyResourceDescriptor { s32 value; u8 remaining[0xC]; };
extern ObjFEnemyResourceDescriptor obj_f_enemy_resource_descriptor;
void free_bin_model_request(void*, int);

void TRaderMapCore::free_statics() {
    if ((u32) TRaderMapCore__data_805D5F4C != 0U) {
        release_texture_list((GinjaTextureList *)TRaderMapCore__data_805D5F4C);
        TAdSinglePlyChrSelectGC::safe_free(TRaderMapCore__data_805D5F4C);
        TRaderMapCore__data_805D5F4C = 0U;
    }
    if ((u32) TRaderMapCore__frame_model_resource != 0U) {
        free_bin_model_request((void*)TRaderMapCore__frame_model_resource, 1);
        TRaderMapCore__frame_model_resource = 0U;
    }
}
void TRaderMapCore::load_frame_texture() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &obj_f_enemy_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TRaderMapCore__frame_model_resource) = var_r0;
    (*(u8 * *)&TRaderMapCore__data_805D5F4C) = load_gvm_texture_file((s32)"RaderMapFrame.gvm");
}

s32 get_bml_model(s32);
void __dt__7TObjectFv(void *, int);

void TRaderMapCore::reset() { *(float *)&this->m_prev = 0.0f; *(float *)&this->m_flags = 0.0f; *(float *)&this->m_name = 0.0f; *(int *)&this->m_next = 0; *(float *)&this->m_up = 1.0f; *(short *)&this->m_down = 0; *(short*)((char*)this + 0x16) = -1; *(float *)&this->texlist = 1.0f; *(float *)&this->m_20 = 1.0f; *(float *)&this->entity_id = 1.0f; *(float*)((char*)this + 0x18) = 1.0f; }


void TRaderMapCore::init_map_ptr() {
    get_bml_model(TRaderMapCore__frame_model_resource);
}

extern s32 lbl_804C88A8[];

void *__dt__13TUnk_804C88A8Fv(void *object, s16 arg1) {
    if (object != NULL) {
        *(s32 **)((s8 *)object + 0x18) = lbl_804C88A8;
        __dt__7TObjectFv(object, 0);
        if (arg1 > 0) {
            TObject::operator delete(object);
        }
    }
    return object;
}

}
