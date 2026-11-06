#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_8028A8F8.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

extern "C" {
f32 calc_sq_offset__12TBoss8DragonFf(s32, void *, f32);
extern void *lbl_805D4DD8;
    extern int green_door_texture_handle;
int TBoss8Dragon::get_instance() {  return green_door_texture_handle; }
void TBoss8Dragon__sub_8028A900(void *self, s32 arg1, s32 arg2) {
    f32 temp_f31;
    void *temp_r31;
    void *temp_r4;
    void *var_r31;
    temp_r4 = *(void **)((s8 *)lbl_805D4DD8 + 0x42C);
    temp_r31 = *(void **)((s8 *)temp_r4 + 0x78);
    temp_f31 = calc_sq_offset__12TBoss8DragonFf(arg2, temp_r4, 15.0f);
    for (var_r31 = *(void **)((s8 *)temp_r31 + 0x2C); var_r31 != NULL; var_r31 = *(void **)((s8 *)var_r31 + 0x30)) {
        if (!(*(s32 *)((s8 *)var_r31 + 0) & 0x10) && (((TBoss8Dragon *)arg1)->is_within_xz_distance((u8 *)var_r31, (f32)temp_f31) != 0)) {
            *(s32 *)((s8 *)var_r31 + 0) |= 0x10;
        }
    }
}

}
