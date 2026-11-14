#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/hud/TObjRaderIcon.h"
#include "pso/object/collision/TObjRaderHideCol.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject.h"

struct RecoveredGlobal_8019733C___vt__13TObjRaderIcon {
    s32 value;
    u8 remaining[0x30];
};

struct Icon_80197110 { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0x1C]; s32 f60; u8 pad64[0x2C]; s32 f90; s32 f94; s32 f98; f32 f9C; u32 fA0; };

struct RecoveredGlobal_80197490___vt__16TObjRaderHideCol {
    s32 value;
    u8 remaining[0x30];
};

struct Pl_801973B0 { u8 pad0[0x38]; f32 pos[3]; };

struct Hide_801973B0 { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0x4C]; f32 f90; s32 f94; };

extern "C" {
s32 __ct__8TObjBaseFP7TObject(void *);
extern s32 __vt__13TObjRaderIcon[];
extern s32 lbl_805D3418;
void add_radar_scaled_gate(void *, u32, u16, s32, s32, f32);
u8 is_current_floor_switch_set(u16);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

extern void *tl_05;
extern s32 __vt__16TObjRaderHideCol[];
extern s32 TObjRaderHideCol__name;
void *get_player_by_client_id(s32 i);
extern s32 local_client_id;
}

typedef char RecoveredGlobal_8019733C___vt__13TObjRaderIcon_size[sizeof(RecoveredGlobal_8019733C___vt__13TObjRaderIcon) == 0x34 ? 1 : -1];
typedef char RecoveredGlobal_80197490___vt__16TObjRaderHideCol_size[sizeof(RecoveredGlobal_80197490___vt__16TObjRaderHideCol) == 0x34 ? 1 : -1];

// Deferred TU: code is generated last-defined-first, so the functions are written in
// reverse address order (vtables and .text then come out in the original order).
#pragma defer_codegen on

extern "C" {
u8 *TObjRaderHideCol__ct(u8 *rader_hide_col, s32 arg1, s32 arg2) {
    __ct__8TObjBaseFP7TObject(rader_hide_col);
    *(s32 **)((s8 *)rader_hide_col + 0x18) = &(*(RecoveredGlobal_80197490___vt__16TObjRaderHideCol *)&__vt__16TObjRaderHideCol).value;
    *(s32 *)((s8 *)rader_hide_col + 0) = (s32) TObjRaderHideCol__name;
    ((TObjRaderHideCol *)(rader_hide_col))->apply_object_set_data((void *)arg2);
    *(f32 *)((s8 *)rader_hide_col + 0x90) = (f32) ((TObjRaderHideCol *)rader_hide_col)->scale.x;
    ((TObjRaderHideCol *)rader_hide_col)->m_94 = 0;
    ((TObject *)(rader_hide_col))->disallow_rendering();
    return rader_hide_col;
}
}

TObjRaderHideCol::~TObjRaderHideCol() {

}

void TObjRaderHideCol::run_task() {
    Hide_801973B0 *arg0 = (Hide_801973B0 *)this;
    Pl_801973B0 *p = (Pl_801973B0 *)get_player_by_client_id(local_client_id);
    if (p != 0) {
        if (xyz_distance_squared((Vec *)arg0->pos, (Vec *)p->pos) < arg0->f90 * arg0->f90) {
            if (!(arg0->f94 & 1)) {
                TRaderMapCore::hide_radar();
                arg0->f94 = 1;
            }
        } else if (arg0->f94 & 1) {
            TRaderMapCore::show_radar();
            arg0->f94 = 0;
        }
    }
}

void TObjRaderHideCol::render() {  }

extern "C" {
u8 *TObjRaderIcon__ct(u8 *rader_icon, s32 arg1, s32 arg2) {
    __ct__8TObjBaseFP7TObject(rader_icon);
    *(s32 **)((s8 *)rader_icon + 0x18) = &(*(RecoveredGlobal_8019733C___vt__13TObjRaderIcon *)&__vt__13TObjRaderIcon).value;
    *(s32 *)((s8 *)rader_icon + 0) = (s32) lbl_805D3418;
    ((TObjRaderIcon *)(rader_icon))->apply_object_set_data((void *)arg2);
    ((TObjRaderIcon *)rader_icon)->initialize_from_placement();
    ((TObject *)(rader_icon))->disallow_rendering();
    return rader_icon;
}
}

TObjRaderIcon::~TObjRaderIcon() {

}

void TObjRaderIcon::initialize_from_placement() {
    s32 temp_r0;
    *(s32 *)&this->m_90 = 0;
    *(s32 *)&this->m_94 = 1;
    *(s32 *)&this->m_98 = 0;
    *(f32 *)&this->_pad9C = 1.0f;
    *(s32 *)&this->m_a0 = 0;
    *(s32 *)&this->m_90 = (s32) this->set_params[0];
    if ((s32) *(s32 *)&this->m_90 < 0) {
        *(s32 *)&this->m_90 = 0;
    }
    if ((s32) *(s32 *)&this->m_90 > 1) {
        *(s32 *)&this->m_90 = 1;
    }
    *(f32 *)&this->_pad9C = (f32) this->scale.x;
    if (*(f32 *)&this->_pad9C < 0.0f) {
        *(f32 *)&this->_pad9C = 0.0f;
    }
    *(s32 *)&this->m_a0 = (s32) *(s32 *)&this->set_params[2];
    *(s32 *)&this->m_94 = (s32) (u16) ((s32) *(s32 *)&this->set_params[1] >> 0x10);
    *(s32 *)&this->m_98 = (s32) (u16) *(s32 *)&this->set_params[1];
    if ((s32) *(s32 *)&this->m_94 < 0) {
        *(s32 *)&this->m_94 = 0;
    }
    if ((s32) *(s32 *)&this->m_94 > 0xC) {
        *(s32 *)&this->m_94 = 0xC;
    }
    if ((s32) *(s32 *)&this->m_98 < 0) {
        *(s32 *)&this->m_98 = 0;
    }
    if ((s32) *(s32 *)&this->m_98 > 0xFF - *(s32 *)&this->m_94) {
        *(s32 *)&this->m_98 = 0xFF - *(s32 *)&this->m_94;
    }
}

void TObjRaderIcon::run_task() {
    Icon_80197110 *arg0 = (Icon_80197110 *)this;
    s32 all;
    s32 i;
    switch (arg0->f90) {
    case 0:
        all = 1;
        for (i = 0; i < arg0->f94; i++) {
            if (is_current_floor_switch_set(arg0->f98 + i) == 0) {
                all = 0;
            }
        }
        if (all == 1) {
            add_radar_scaled_gate(arg0->pos, 0xFF00FF00, arg0->f60, 0, 0, arg0->f9C);
        } else {
            add_radar_scaled_gate(arg0->pos, 0xFFFF0000, arg0->f60, 0, 0, arg0->f9C);
        }
        break;
    case 1:
        add_radar_scaled_gate(arg0->pos, arg0->fA0, arg0->f60, 0, 0, arg0->f9C);
        break;
    }
}

void TObjRaderIcon::render() {  }

extern "C" {
void *TObjRaderIcon__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xA4);
    if (o != NULL) {
        o = TObjRaderIcon__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}
}
