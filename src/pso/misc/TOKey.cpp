#include "pso/protocol/protocol_types.h"
#include "pso/object/TObjMotion.h"
#include "types.h"
#include "pso/system/byteswap.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/misc/TOKey.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyAncient01.h"
#include "pso/npc/TObjNpcEnemy.h"

extern "C" {
void debug_printf_at(s32, const char *, ...);
extern char lbl_80441958[];
// Slot 5 of the base table (apply_object_set_data) is called here without
// an argument, so it still goes through a no-argument view of the table.
struct Base0_8016ab58_8016A8D0 { char pad[0x18]; };
struct VObj0_8016ab58_8016A8D0 : Base0_8016ab58_8016A8D0 { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); };

u8 is_current_floor_switch_set(u16);
}

void TOKey::trigger_activate_sound() {
    this->play_activate_sound();
}

void TOKey::update_lock_state() {
    u8 temp_r3;

    if ((s32) this->m_d0 != 2) {
        temp_r3 = is_current_floor_switch_set((u16) this->m_e4);
        if (temp_r3 == 0) {
            this->m_d4 = 0;
        }
        if (temp_r3 == 1) {
            this->m_d4 = 1;
        }
    }
}

void TOKey::update_armed_switch() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0_2;
    this->update_lock_state();
    switch (this->m_d4) {
    case 0:
        if ((s32) *(s32 *)((s8 *)arg0 + 0xE0) != 0) {
            temp_r0_2 = *(s32 *)((s8 *)arg0 + 0xDC) - 1;
            *(s32 *)((s8 *)arg0 + 0xDC) = temp_r0_2;
            if (temp_r0_2 < 0) {
                this->send_switch_on();
                *(s32 *)((s8 *)arg0 + 0xE0) = 0;
            }
        }
        this->vfunc_17();
        return;
    case 1:
        this->vfunc_16();
        *(s32 *)((s8 *)arg0 + 0xE0) = 0;
        return;
    }
}

void TOKey::debug_draw_key_id() {
    this->set_params[0] = this->set_params[0] % 256;
    if (this->set_params[0] < 0 || this->set_params[0] > 0xFF) {
        this->m_e4 = -1;
        this->m_d0 = 2;
    } else {
        this->m_e4 = this->set_params[0];
        this->m_d0 = 0;
    }
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, lbl_80441958, this->m_e4);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    this->vfunc_25();
}

void TOKey::run_task() {
    u8 *arg0 = (u8 *)this;
    this->update_armed_switch();
    *(s32 *)((s8 *)arg0 + 0xE4) = 0;
}

void TOKey::init_switch_id() {
    s32 temp_r0;

    temp_r0 = this->set_params[0];
    if ((temp_r0 < 0) || (temp_r0 > 0xFF)) {
        this->m_e4 = -1;
        this->m_d0 = 2;
        return;
    }
    this->m_e4 = temp_r0;
    this->m_d0 = 0;
}

void TOKey::init_key() {
    u8 *arg0 = (u8 *)this;
    ((VObj0_8016ab58_8016A8D0*)arg0)->m5();
    init_switch_id();
    VecCopy(&this->center, (const Vec *)&this->position);
    *(s32 *)((s8 *)arg0 + 0x20) = 2;
}

// The destructor is still written out by hand: TOKey's vtable comes ahead of
// the switch tables of the unit before (one deferred-generation unit with
// this one), which a compiled destructor here cannot give.
extern "C" {
extern void *__vt__5TOKey[];
void __dl__7TObjectFPv(void *);

void *__dt__5TOKeyFv(void *self, s16 del) {
    if (self != NULL) {
        *(void **)((u8 *)self + 0x18) = __vt__5TOKey;
        __dt__13TUnk_804AFBF8Fv(self, 0);
        if (del > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}

extern const f32 lbl_805DB6E0;
extern const char *TOKey__class_name;

TOKey::TOKey(TObject *parent) : TUnk_804AFBF8(parent) {
    this->m_name = TOKey__class_name;
    this->m_e4 = -1;
    *(f32 *)((s8 *)this + 0xCC) = lbl_805DB6E0;
    this->m_d0 = 2;
    this->m_d4 = 0;
    *(u32 *)((s8 *)this + 0xE0) = 0;
    *(u32 *)((s8 *)this + 0xD8) = 28;
    *(u32 *)((s8 *)this + 0xDC) = 28;
    this->cursor_action.set_use();
    *(u32 *)((s8 *)this + 0xE4) = 0;
}

void TOKey::vfunc_16() {  }
void TOKey::vfunc_17() {  }
void TOKey::vfunc_25() {  }

void TOKey::bswap_6x05_switch_flag() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x8)); }
