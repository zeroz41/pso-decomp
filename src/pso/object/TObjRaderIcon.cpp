#include "types.h"
#include "pso/object/TObjRaderIcon.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/object/TObjRaderIcon.h"

struct RecoveredGlobal_8019733C___vt__13TObjRaderIcon {
    s32 value;
    u8 remaining[0x30];
};

struct Icon_80197110 { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0x1C]; s32 f60; u8 pad64[0x2C]; s32 f90; s32 f94; s32 f98; f32 f9C; u32 fA0; };

extern "C" {
s32 __ct__13TUnk_804B9870FP7TObject(void *);
extern s32 __vt__13TObjRaderIcon[];
extern s32 lbl_805D3418;
void add_radar_scaled_gate(void *, u32, u16, s32, s32, f32);
u8 is_current_floor_switch_set(u16);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

extern void *tl_05;

void *TObjRaderIcon__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xA4);
    if (o != NULL) {
        o = TObjRaderIcon__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TObjRaderIcon::render() {  }

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

}
TObjRaderIcon::~TObjRaderIcon() {

}
extern "C" {
typedef char RecoveredGlobal_8019733C___vt__13TObjRaderIcon_size[sizeof(RecoveredGlobal_8019733C___vt__13TObjRaderIcon) == 0x34 ? 1 : -1];
u8 *TObjRaderIcon__ct(u8 *rader_icon, s32 arg1, s32 arg2) {
    __ct__13TUnk_804B9870FP7TObject(rader_icon);
    *(s32 **)((s8 *)rader_icon + 0x18) = &(*(RecoveredGlobal_8019733C___vt__13TObjRaderIcon *)&__vt__13TObjRaderIcon).value;
    *(s32 *)((s8 *)rader_icon + 0) = (s32) lbl_805D3418;
    ((TObjRaderIcon *)(rader_icon))->apply_object_set_data((void *)arg2);
    ((TObjRaderIcon *)rader_icon)->initialize_from_placement();
    disallow_rendering__7TObjectFv((TObject *)(rader_icon));
    return rader_icon;
}

}
