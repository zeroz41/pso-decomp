#include "pso/protocol/protocol_types.h"
#include "pso/object/TObjMotion.h"
#include "types.h"
#include "pso/misc/TOKey_8015845C.h"
#include "pso/system/byteswap.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/misc/TOKey.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyAncient01.h"
#include "pso/npc/TObjNpcEnemy.h"

struct Base_8016A8D0 { char pad[0x18]; };
struct VObj_8016A8D0 : Base_8016A8D0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
};

struct VBase_8016AA20 { char pad[0x18]; };

struct VObj_8016AA20 : VBase_8016AA20 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    u8 pad1C[0x84 - 0x1C];
    s32 f84;
    u8 pad88[0xC8 - 0x88];
    s32 fC8;
    u8 padCC[4];
    s32 fD0;
};

extern "C" {
void debug_printf_at(s32, const char *, ...);
extern char lbl_80441958[];
struct Base0_8016ab58_8016A8D0 { char pad[0x18]; };
struct VObj0_8016ab58_8016A8D0 : Base0_8016ab58_8016A8D0 { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); };

void *TOKey__ct(TOKey *arg0);
void *__dt__5TOKeyFv(void *arg0, s16 arg1);
u8 is_current_floor_switch_set(u16);
void __dl__7TObjectFPv(void *);

void TOKey::trigger_activate_sound() {
    struct VObj_8016A8D0 *o = (struct VObj_8016A8D0 *)this;
    o->m20();
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
    VObj_8016AA20 *arg0 = (VObj_8016AA20 *)this;
    arg0->f84 = arg0->f84 % 256;
    if (arg0->f84 < 0 || arg0->f84 > 0xFF) {
        arg0->fC8 = -1;
        arg0->fD0 = 2;
    } else {
        arg0->fC8 = arg0->f84;
        arg0->fD0 = 0;
    }
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, lbl_80441958, arg0->fC8);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    arg0->m23();
}

void TOKey::reset_and_notify() {
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

extern s32 __vt__5TOKey[];

void *__dt__5TOKeyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__5TOKey;
        ((TUnk_804AFBF8 *)arg0)->destroy_key_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern const f32 lbl_805DB6E0;
extern void *TOKey__class_name;

void *TOKey__ct(TOKey *arg0) {
    init_map_object_base(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__5TOKey;
    *(void * *)&arg0->m_name = TOKey__class_name;
    arg0->m_e4 = -1;
    *(f32 *)((s8 *)arg0 + 0xCC) = lbl_805DB6E0;
    arg0->m_d0 = 2;
    arg0->m_d4 = 0;
    *(u32 *)((s8 *)arg0 + 0xE0) = 0;
    *(u32 *)((s8 *)arg0 + 0xD8) = 28;
    *(u32 *)((s8 *)arg0 + 0xDC) = 28;
    ((TOKey *)arg0)->cursor_action.set_use();
    *(u32 *)((s8 *)arg0 + 0xE4) = 0;
    return arg0;
}

void TOKey::vfunc_16() {  }
void TOKey::vfunc_17() {  }
void TOKey::vfunc_25() {  }

void TOKey::bswap_6x05_switch_flag() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x8)); }

}
