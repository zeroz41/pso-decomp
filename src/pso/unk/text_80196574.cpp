#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/object/TObjQuestColALock.h"

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_80196574_lbl_804A7428 {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {
s32 fn_80141CBC(void *, void *, int, f32);
void debug_draw_sphere(const Vec *pos, const NJS_ARGB *color, f32 radius);
extern RecoveredGlobal_80196574_lbl_804A7428 debug_color_purple_half_alpha;
extern const NJS_ARGB debug_color_green_half_alpha;
extern const f32 lbl_805DBEF8;
extern const f32 lbl_805DBEFC;
extern const f32 lbl_805DBF00;
typedef char RecoveredGlobal_80196574_lbl_804A7428_size[sizeof(RecoveredGlobal_80196574_lbl_804A7428) == 0x10 ? 1 : -1];
void TObjQuestColALock::update_room_id_check() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r5;
    if (((VObj_18_26a62c *)(arg0))->m8(lbl_805DBEF8, lbl_805DBEFC) != 0) {
        debug_draw_sphere(&position, &debug_color_green_half_alpha, lbl_805DBF00 * *(f32 *)&this->unk_AC);
        temp_r5 = (u8 *)this->bodies;
        fn_80141CBC((u8 *)&this->position, &debug_color_purple_half_alpha.value, (int)temp_r5, (f32) (lbl_805DBF00 * *(f32 *)((s8 *)temp_r5 + 0xC)));
    }
}

}
