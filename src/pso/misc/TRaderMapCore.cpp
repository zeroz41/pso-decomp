#include "pso/system/NinjaTypes.h"
#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/system/vector.h"
#include "pso/TObject.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/map/FloorArea.h"
#include "pso/render/render_util.h"

struct RecoveredGlobal_801FA964_lbl_804C8784 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_801F9720_TRaderMapCore__data_80513708 {
    s32 value;
    u8 remaining[0x74];
};

#include <stddef.h>
#include "pso/THeap.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjLight.h"
#include "pso/TObjCMHairMenu.h"
#include "pso/player/TObjPlayer.h"
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

struct RecoveredGlobal_801FA9D8_lbl_8044A770 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_801FA9D8_lbl_8044A77C {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801FA9D8_lbl_804C8748 {
    s32 value;
    u8 remaining[0x38];
};

struct RecoveredGlobal_801FA9D8_lbl_804C8784 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_801FA9D8_TRaderMapCore__data_80513708 {
    s32 value;
    u8 remaining[0x74];
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

struct RecoveredGlobal_801F9B8C_TRaderMapCore__data_80512D08 {
    s32 value;
    u8 remaining[0x9FC];
};

typedef Vec Vec_801F9B8C;

struct Dot_801F9B8C { f32 x, z, w; s16 c; s16 type; s32 color; };

struct Vec_801F9D84 { f32 x, y, z; };

struct Model_801F9D84 { u8 pad[8]; Vec_801F9D84 a; Vec_801F9D84 b; };

struct ModelRef_801F9D84 { void *p0; Model_801F9D84 *m; };

struct Region_801F9D84 {
    s16 id; s16 flags; f32 x, y, z;
    u32 angles[3]; f32 fade, radius; ModelRef_801F9D84 *model;
};

struct Map_801F9D84 { Region_801F9D84 *regions; void *textures; s32 count; };

struct Vec3_801F9314 { f32 x, y, z; };

struct Cam_801F9314 { Vec3_801F9314 dir; Vec3_801F9314 pos; s32 rot; };

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

struct RecoveredGlobal_801FA1E0_lbl_8050BEC0 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_801FA1E0_TRaderMapCore__data_80512D08 {
    s32 value;
    u8 remaining[0x9FC];
};

struct Gate_801FA1E0 { f32 x; f32 z; f32 scale; u16 rot; s16 kind; s32 color; };

struct RecoveredGlobal_801FA1E0_lbl_8058D4C0 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801FA350_lbl_8050BEC0 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_801FA350_lbl_8058D4C0 {
    s32 value;
    u8 remaining[0xC];
};

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

struct Pair_801F9770 { f32 x; f32 y; };

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

struct RadarVec2_801FA880 { f32 x, y; };

extern "C" {
s32 TCameraCtrl__sub_80068EF0();
void draw_compass__13TRaderMapCoreFv(TRaderMapCore *self, s32 mode);
extern const f32 lbl_805DC588;
extern RadarSpriteFrame_801FA6CC lbl_804C87E4[];
extern f32 lbl_804C87B4[][4];
extern const f32 lbl_805DC574;
extern f32 lbl_805D35F0;
extern u32 TRaderMapCore__floor_map_resource;
extern s32 lbl_805D5F2C;
extern s32 TRaderMapCore__data_805D5F30;
extern s32 TRaderMapCore__view_mode;
void disallow_rendering__7TObjectFv(TObject *);
extern void *TRaderMapCore__instance;
void allow_rendering__7TObjectFv(TObject *);
void TCameraCtrl__sub_801E32D8(f32 farg0, f32 farg1);
s32 GXSetScissorBoxOffset(int, int);
extern Rect_801F9228 radar_map_view_scissor_table[3];
extern s32 camera_ctrl_instance;
extern const f32 radar_screen_center_x_f32;
extern const f32 radar_screen_center_y_f32;
extern RecoveredGlobal_801F9720_TRaderMapCore__data_80513708 TRaderMapCore__map_view_state;
extern f32 lbl_805D35F4;
extern f32 lbl_805D35F8;
s32 memset(void *, int, int);
extern RecoveredGlobal_801FA9D8_lbl_8044A770 lbl_8044A770;
extern RecoveredGlobal_801FA9D8_lbl_8044A77C lbl_8044A77C;
extern RadarViewRect_801FA9D8 radar_map_view_rect_table[3];
extern const f32 TRaderMapCore__data_805DC534;
void begin_map_view__13TRaderMapCoreFii(s32 arg0, s32 arg1);
extern s16 *TRaderMapCore__floor_discovery_table[];
extern int TRaderMapCore__map_heap;
s32 init_radar_floor_flags(s32 floor, RadarInitMap_801F9474 *map);
extern const f32 TRaderMapCore__data_805DC568;
s32 save_floor_discovery__13TRaderMapCoreFiPv(s32 arg0, Map_801F9418* arg1);
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
extern const f32 lbl_805DC564;
s32 minimap_render_dot(Vec_801F9B8C *arg0, s32 arg1, s16 arg2, s32 arg3);
s32 minimap_render_gate(Vec *pos, u32 color, u16 rot, s16 kind, s32 flags);
s32 add_radar_scaled_marker(Vec_801F9B8C *arg0, s32 arg1, s16 arg2, s32 arg3, f32 scale);
void update_radar_auto_discovery(s32 arg0, s32 arg1, void *arg2);
void set_perspective_projection_from_fov(s32, f32, f32, f32);
void rotate_vector_by_matrix(void *, Vec3_801F9314 *, Vec3_801F9314 *);
void rotate_matrix_y(void *, s32);
s32 push_matrix_from(void *src);
s32 pop_matrix(void);
extern Vec3_801F9314 lbl_8044A794;
extern u8 identity_matrix[];
extern f32 lbl_805D3608;
extern f32 radar_overhead_projection_scale;
extern const f32 lbl_805DC548;
extern const f32 lbl_805DC54C;
extern const f32 lbl_805DC550;
void setup_overhead_projection__13TRaderMapCoreFv(s32 arg0, Cam_801F9314 *arg1);
void rotate_matrix_zyx(void *m, s32 x, s32 y, s32 z);
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
extern const f32 lbl_805DC590;
void TRaderMapCore__sub_801F967C(TRaderMapCore *self, u32 color);
void scale_matrix(s32, f32, f32, f32);
void draw_ginja_object(void *child);
extern const f32 TRaderMapCore__data_805DC528;
extern const f32 lbl_805DC57C;
extern const f32 lbl_805DC580;
extern const f32 lbl_805DC584;
int get_entity_id(void*);
s32 get_current_floor(void);
s32 get_floor__10TObjPlayerFv(void);
s32 TLobby__sub_801C19D0(void *);
s32 should_show_map__13TRaderMapCoreFv(void);
extern Vec4_801F9E9C radar_player_slot_color_table[];
extern s32 local_client_id;
extern const f32 lbl_805DC560;
extern const f32 lbl_805DC570;
extern const f32 lbl_805DC578;
Pair_801F9770 TRaderMapCore__sub_801F9D38(TRaderMapCore *self);
extern const Pair_801F9770 lbl_8044A78C;
s32 has_flag__13TRaderMapCoreFv(void *, s32);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 is_on_current_screen__11TCameraCtrlFv(void *, s32);
s32 apply_packed_flags__13TRaderMapCoreFllll(void *, s32, s32, s32);
extern Pad_801FAF24 controller_input_state[];
extern const f32 TRaderMapCore__data_805DC58C;
extern const f32 lbl_805DC598;
void GXSetViewport(f32, f32, f32, f32, f32, f32);
extern const f32 radar_screen_width_f32;
extern const f32 radar_screen_height_f32;

int __dt__5THeapFv(void*, void*);
s32 is_card_flag_set__19TWindowKeyBoardHardFv(u16);
s32 is_technique_ready__8TTecCtrlFv();

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
    return is_technique_ready__8TTecCtrlFv();
}
void TRaderMapCore::reset_counter() { this->m_184 = 0; }

void TRaderMapCore::hide_radar() {
    if ((void *) (*(u8 * *)&TRaderMapCore__instance) != NULL) {
        ((TRaderMapCore *)(*(u8 * *)&TRaderMapCore__instance))->reset_counter();
        disallow_rendering__7TObjectFv((TObject *)(*(u8 * *)&TRaderMapCore__instance));
    }
}

void TRaderMapCore::show_radar() {
    if ((void *) (*(u8 * *)&TRaderMapCore__instance) != NULL) {
        ((TRaderMapCore *)(*(u8 * *)&TRaderMapCore__instance))->reset_counter();
        allow_rendering__7TObjectFv((TObject *)(*(u8 * *)&TRaderMapCore__instance));
    }
}
}
void set_camera_look_at(u8 *eye, u8 *target, u8 *up);
#pragma fp_contract on

void TRaderMapCore::configure_viewport(const RadarViewportParameters* view) {
    f32 temp_f31;
    f32 temp_f2;
    f32 temp_f30;
    f32 temp_f1;
    GXSetViewport(TRaderMapCore__data_805DC528, TRaderMapCore__data_805DC528, radar_screen_width_f32, radar_screen_height_f32, TRaderMapCore__data_805DC528, TRaderMapCore__data_805DC534);
    GXSetScissorBoxOffset(0, 0);
    temp_f1 = view->center_x;
    temp_f2 = view->center_y;
    temp_f31 = -(temp_f1 - radar_screen_center_x_f32);
    temp_f30 = -(temp_f2 - radar_screen_center_y_f32);
    TCameraCtrl__sub_801E32D8(temp_f1, temp_f2);
    GXSetScissorBoxOffset((int)((s32) temp_f31), (int)((s32) temp_f30));
}

s32 TRaderMapCore::set_view_scissor(void *self, int mode, void *arg2) {
    Rect_801F9228 *rect = (Rect_801F9228 *)arg2;
    u32 w;
    u32 h;
    u32 y;
    if (mode == 2) {
        w = 32.0f * (rect->x1 - rect->x0);
        h = 32.0f * (rect->y1 - rect->y0);
        y = radar_screen_center_y_f32 - 0.5f * h;
        GXSetScissor((u32)(radar_screen_center_x_f32 - 0.5f * w), y, w, h);
    } else {
        GXSetScissor(0, 0, 0x280, 0x1E0);
    }
}
#pragma fp_contract reset

void setup_overhead_projection__13TRaderMapCoreFv(s32 arg0, Cam_801F9314 *arg1) {
    Vec3_801F9314 up = lbl_8044A794;
    Vec3_801F9314 eye;
    Vec3_801F9314 at;
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
    set_perspective_projection_from_fov((s32)(lbl_805DC548 * radar_overhead_projection_scale), lbl_805DC54C, TRaderMapCore__data_805DC534, lbl_805DC550);
    set_camera_look_at((u8 *)&eye, (u8 *)&at, (u8 *)&up);
}

s32 save_floor_discovery__13TRaderMapCoreFiPv(s32 arg0, Map_801F9418* arg1) {
    s16* saved = ((s16* *)&TRaderMapCore__floor_discovery_table)[arg0];
    s16* p;
    Piece_801F9418* piece;
    s32 i;
    if (saved != NULL) {
        for (i = 0, piece = arg1->pieces, p = saved; i < arg1->count; i++, piece++, p++) {
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

typedef char RecoveredGlobal_801F9720_TRaderMapCore__data_80513708_size[sizeof(RecoveredGlobal_801F9720_TRaderMapCore__data_80513708) == 0x78 ? 1 : -1];

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

typedef char RecoveredGlobal_801F9B8C_TRaderMapCore__data_80512D08_size[sizeof(RecoveredGlobal_801F9B8C_TRaderMapCore__data_80512D08) == 0xA00 ? 1 : -1];

void TRaderMapCore::open_free_map_view() {
    s32 g = (s32)&TRaderMapCore__map_view_state;
    TRaderMapCore__view_mode = 1;
    {
        Pair_801F9770 p = TRaderMapCore__sub_801F9D38((TRaderMapCore *)TRaderMapCore__instance);
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

s32 add_radar_scaled_marker(Vec_801F9B8C *pos, s32 arg1, s16 arg2, s32 arg3, f32 scale) {
    Vec_801F9B8C *cam = (Vec_801F9B8C *)&TRaderMapCore__map_view_state;
    Vec_801F9B8C v;
    u8 pad[0x10];
    Dot_801F9B8C *d;
    if (TRaderMapCore__data_805D5F30 > 0x7F) {
        return 0;
    }
    if (!(arg3 & 1)) {
        v.x = cam->x;
        v.z = cam->z;
        if (xz_distance_squared(pos, &v) > lbl_805DC564) {
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
    Vec_801F9B8C *cam = (Vec_801F9B8C *)&TRaderMapCore__map_view_state;
    Vec_801F9B8C v;
    u8 pad[0x10];
    if (TRaderMapCore__data_805D5F30 > 0x7F) {
        return 0;
    }
    if (!(flags & 1)) {
        v.x = cam->x;
        v.z = cam->z;
        if (xz_distance_squared(pos, &v) > lbl_805DC564) {
            return 0;
        }
    }
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].x = pos->x;
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].z = pos->z;
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].scale = TRaderMapCore__data_805DC534;
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].color = color;
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].kind = kind;
    TRaderMapCore__marker_buffer[TRaderMapCore__data_805D5F30].rot = rot;
    TRaderMapCore__data_805D5F30++;
    return 1;
}

s32 minimap_render_dot(Vec_801F9B8C *pos, s32 arg1, s16 arg2, s32 arg3) {
    Vec_801F9B8C *cam = (Vec_801F9B8C *)&TRaderMapCore__map_view_state;
    Vec_801F9B8C v;
    u8 pad[0x10];
    Dot_801F9B8C *d;
    if (TRaderMapCore__data_805D5F30 > 0x7F) {
        return 0;
    }
    if (!(arg3 & 1)) {
        v.x = cam->x;
        v.z = cam->z;
        if (xz_distance_squared(pos, &v) > lbl_805DC564) {
            return 0;
        }
    }
    ((Dot_801F9B8C *)&TRaderMapCore__marker_buffer)[TRaderMapCore__data_805D5F30].x = pos->x;
    d = &((Dot_801F9B8C *)&TRaderMapCore__marker_buffer)[TRaderMapCore__data_805D5F30];
    d->z = pos->z;
    d->w = TRaderMapCore__data_805DC534;
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
            MAP_801F9CB8->regions[i].fade = TRaderMapCore__data_805DC568;
            return 1;
        }
    }
    return 0;
}

#define MAP_801F9D84 ((Map_801F9D84 *) TRaderMapCore__floor_map_resource)
Pair_801F9770 TRaderMapCore__sub_801F9D38(TRaderMapCore *self) {
    Pair_801F9770 p = lbl_8044A78C;
    if (self->m_134 >= 0) {
        p.x = ((Core_801F9E9C *)self)->e[self->m_134].x;
        p.y = ((Core_801F9E9C *)self)->e[self->m_134].z;
    }
    return p;
}

void update_radar_auto_discovery(s32 arg0, s32 arg1, void *pos) {
    Vec_801F9D84 v;
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
                    r->fade = TRaderMapCore__data_805DC568;
                }
            }
        }
    }
}

typedef char RecoveredGlobal_801FA1E0_lbl_8050BEC0_size[sizeof(RecoveredGlobal_801FA1E0_lbl_8050BEC0) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_801FA1E0_TRaderMapCore__data_80512D08_size[sizeof(RecoveredGlobal_801FA1E0_TRaderMapCore__data_80512D08) == 0xA00 ? 1 : -1];
typedef char RecoveredGlobal_801FA1E0_lbl_8058D4C0_size[sizeof(RecoveredGlobal_801FA1E0_lbl_8058D4C0) == 0x10 ? 1 : -1];

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
            me->y = lbl_805DC570;
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
                e->y = lbl_805DC570;
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
                e->y = lbl_805DC570;
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
            ((Core_801F9E9C *)this)->e[j].unk10 = lbl_805DC560;
        }
        break;
    case 1:
        for (s32 j = 0; j < 4; j++) {
            ((Core_801F9E9C *)this)->e[j].unk10 = lbl_805DC560;
        }
        break;
    case 2:
        for (s32 j = 0; j < 4; j++) {
            ((Core_801F9E9C *)this)->e[j].unk10 = lbl_805DC578;
        }
        break;
    }
}

void TRaderMapCore::draw_enemy_gate_markers() {
    Gate_801FA1E0 *g;
    s32 i;
    saved_model_render_flags = model_render_flags;
    copy_argb((NJS_ARGB *)(&(*(RecoveredGlobal_801FA1E0_lbl_8050BEC0 *)&saved_model_draw_color).value), (NJS_ARGB *)(&(*(RecoveredGlobal_801FA1E0_lbl_8058D4C0 *)&model_material_color).value));
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= this->m_194;
    set_chunk_material_override_pair(-0xFF01, 0x100);
    for (i = 0, g = (Gate_801FA1E0 *)&TRaderMapCore__marker_buffer; i < TRaderMapCore__data_805D5F30; i++, g++) {
        TRaderMapCore__sub_801F967C(this, g->color);
        push_matrix();
        translate_matrix(0, g->x, TRaderMapCore__data_805DC528, g->z);
        rotate_matrix_y(0, g->rot);
        switch (g->kind) {
        case 0:
            scale_matrix(0, lbl_805DC57C * g->scale, lbl_805DC580, lbl_805DC584 * g->scale);
            draw_ginja_object(this->m_180);
            break;
        case 1:
            scale_matrix(0, lbl_805DC580 * g->scale, lbl_805DC580, lbl_805DC580 * g->scale);
            draw_ginja_object(this->m_17c);
            break;
        }
        pop_matrix();
    }
    set_constant_material(&chunk_material_color_half_alpha_f32);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    copy_argb((NJS_ARGB *)(&(*(RecoveredGlobal_801FA1E0_lbl_8058D4C0 *)&model_material_color).value), (NJS_ARGB *)(&(*(RecoveredGlobal_801FA1E0_lbl_8050BEC0 *)&saved_model_draw_color).value));
    model_render_flags = saved_model_render_flags;
}

typedef char RecoveredGlobal_801FA350_lbl_8050BEC0_size[sizeof(RecoveredGlobal_801FA350_lbl_8050BEC0) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_801FA350_lbl_8058D4C0_size[sizeof(RecoveredGlobal_801FA350_lbl_8058D4C0) == 0x10 ? 1 : -1];
void TRaderMapCore::draw_player_markers() {
    u8 *var_r31;
    s32 var_r30;
    saved_model_render_flags = model_render_flags;
    copy_argb((NJS_ARGB *)(&(*(RecoveredGlobal_801FA350_lbl_8050BEC0 *)&saved_model_draw_color).value), (NJS_ARGB *)(&(*(RecoveredGlobal_801FA350_lbl_8058D4C0 *)&model_material_color).value));
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
            translate_matrix(0, *(f32 *)((s8 *)var_r31 + 0x0), TRaderMapCore__data_805DC528, *(f32 *)((s8 *)var_r31 + 0x8));
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
    copy_argb((NJS_ARGB *)(&(*(RecoveredGlobal_801FA350_lbl_8058D4C0 *)&model_material_color).value), (NJS_ARGB *)(&(*(RecoveredGlobal_801FA350_lbl_8050BEC0 *)&saved_model_draw_color).value));
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
        view->x = ((Entry_801F9E9C *)this->player_marker_records)[this->m_134].x;
        view->z = ((Entry_801F9E9C *)this->player_marker_records)[this->m_134].z;
    }
    if (this->m_168 & 1) {
        view->rot = 0x8000 - ((TCameraCtrl *)camera_ctrl_instance)->m_194;
        if (get_current_floor_area() == AREA_DE_ROL_LE) {
            free_view->rot = 0;
            this->m_174 = 0x8000 - ((TCameraCtrl *)camera_ctrl_instance)->m_194;
        } else {
            free_view->rot = 0x8000;
            this->m_174 = -((TCameraCtrl *)camera_ctrl_instance)->m_194;
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
            this->m_170 *= lbl_805DC588;
            view->distance += this->m_170;
            if (view->distance > lbl_805D35F0) {
                view->distance = lbl_805D35F0;
            }
            break;
        case 1:
            this->m_170 *= lbl_805DC588;
            view->distance += this->m_170;
            if (view->distance > lbl_805D35F8) {
                view->distance = lbl_805D35F8;
            }
            break;
        case 2:
            this->m_170 *= lbl_805DC588;
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
static RadarVec2_801FA880 radar_backdrop_origin[3] = { { 480.0f, 64.0f }, { 32.0f, 288.0f }, { 96.0f, 176.0f } };
static RadarVec2_801FA880 radar_backdrop_size[3] = { { 128.0f, 128.0f }, { 448.0f, 128.0f }, { 448.0f, 128.0f } };
static f32 radar_backdrop_alpha[3] = { 64.0f, 64.0f, 128.0f };

void TRaderMapCore::draw_backdrop(TRaderMapCore *self, s32 mode) {
    f32 pos[8];
    RadarFanDesc_801FA880 desc;
    u32 colors[4];
    u32 color;
    RadarVec2_801FA880 *origin;
    RadarVec2_801FA880 *size;
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
    ((TObjCMHairMenu *)&desc)->draw_tri_fan_2d(4, 0x16, lbl_805DC574);
    TParticleCtrl::end_effect_render();
}

extern s32 lbl_805DC56C;

typedef char RecoveredGlobal_801FA964_lbl_804C8784_size[sizeof(RecoveredGlobal_801FA964_lbl_804C8784) == 0x30 ? 1 : -1];
void TRaderMapCore::setup_view(s32 arg1) {
    s32 arg0 = (s32)this;
    GXSetScissorBoxOffset(0, 0);
    TCameraCtrl__sub_801E32D8(radar_screen_center_x_f32, radar_screen_center_y_f32);
    ((TCameraCtrl *)camera_ctrl_instance)->setup_default_view(0);
    TRaderMapCore::set_view_scissor((void *)arg0, 0, (void *)((void *) ((u8 *)&radar_map_view_scissor_table + (arg1 * 0x10))));
    TObjLight::apply_distant_light();
    TParticleCtrl::end_effect_render();
}

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_801FA9D8_lbl_8044A770_size[sizeof(RecoveredGlobal_801FA9D8_lbl_8044A770) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_801FA9D8_lbl_8044A77C_size[sizeof(RecoveredGlobal_801FA9D8_lbl_8044A77C) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_801FA9D8_lbl_804C8748_size[sizeof(RecoveredGlobal_801FA9D8_lbl_804C8748) == 0x3C ? 1 : -1];
typedef char RecoveredGlobal_801FA9D8_lbl_804C8784_size[sizeof(RecoveredGlobal_801FA9D8_lbl_804C8784) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_801FA9D8_TRaderMapCore__data_80513708_size[sizeof(RecoveredGlobal_801FA9D8_TRaderMapCore__data_80513708) == 0x78 ? 1 : -1];
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
    TRaderMapCore::set_view_scissor((void *)arg0, 2, (void *)((void *) ((u8 *)&(*(RecoveredGlobal_801FA9D8_lbl_804C8784 *)&radar_map_view_scissor_table).value + (arg1 * 0x10))));
    setup_overhead_projection__13TRaderMapCoreFv((s32)arg0, (Cam_801F9314 *)((void *) ((u8 *)&(*(RecoveredGlobal_801FA9D8_TRaderMapCore__data_80513708 *)&TRaderMapCore__map_view_state).value + (arg1 * 0x28))));
    stack.sp18 = *(s32 *)((s8 *)&lbl_8044A770.value + 0);
    stack.sp1C = *(s32 *)((s8 *)&lbl_8044A770.value + 4);
    stack.sp20 = *(s32 *)((s8 *)&lbl_8044A770.value + 8);
    stack.sp8 = *(s32 *)((s8 *)&lbl_8044A77C.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_8044A77C.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_8044A77C.value + 8);
    stack.sp14 = *(s32 *)((s8 *)&lbl_8044A77C.value + 0xC);
    ((TObjLight *)(&stack.sp18))->set_light((void *)&stack.sp8, TRaderMapCore__data_805DC534);
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
            r->alpha += lbl_805DC590;
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
            draw_compass__13TRaderMapCoreFv((TRaderMapCore *)arg0, TRaderMapCore__view_mode);
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
            draw_compass__13TRaderMapCoreFv((TRaderMapCore *)arg0, TRaderMapCore__view_mode);
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
            self->f18C += lbl_805DC598;
        }
        if (is_on_current_screen__11TCameraCtrlFv(controller_input_state[((TRaderMapCore *)(self->f184))->get_map_id()].ctl, 0x20) != 0) {
            self->f18C -= lbl_805DC598;
        }
        if (is_on_current_screen__11TCameraCtrlFv(controller_input_state[((TRaderMapCore *)(self->f184))->get_map_id()].ctl, 0x40) != 0) {
            self->f188 += lbl_805DC598;
        }
        if (is_on_current_screen__11TCameraCtrlFv(controller_input_state[((TRaderMapCore *)(self->f184))->get_map_id()].ctl, 0x80) != 0) {
            self->f188 -= lbl_805DC598;
        }
        if (apply_packed_flags__13TRaderMapCoreFllll(controller_input_state[((TRaderMapCore *)(self->f184))->get_map_id()].ctl, 0x20000, 0x27, 1) != 0) {
            self->f190 -= lbl_805DC598;
        }
        if (apply_packed_flags__13TRaderMapCoreFllll(controller_input_state[((TRaderMapCore *)(self->f184))->get_map_id()].ctl, 0x10000, 0x27, 1) != 0) {
            self->f190 += lbl_805DC598;
        }
        TRaderMapCore::pan_horizontal(self->f188);
        TRaderMapCore::pan_vertical(self->f18C);
        TRaderMapCore::add_zoom_distance(self->f190);
        self->f188 *= TRaderMapCore__data_805DC58C;
        self->f18C *= TRaderMapCore__data_805DC58C;
        self->f190 *= TRaderMapCore__data_805DC58C;
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
            self->f188 = TRaderMapCore__data_805DC528;
            self->f18C = TRaderMapCore__data_805DC528;
            self->f190 = TRaderMapCore__data_805DC528;
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
            this->m_168 = (s32) (this->m_168 | lbl_805DC56C);
            return;
        }
        this->m_168 = (s32) (this->m_168 & 0xFFFFFFFE);
    }
}
