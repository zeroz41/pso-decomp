#include "types.h"
#include "pso/unk/text_8028A820.h"
#include "pso/boss/goldragon/TBoss8Dragon_8028A8F8.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

extern "C" {
extern void *lbl_805D4DD8;

NJS_TEXLIST *get_green_door_textures() {
    return green_door_texture_handle;
}
void TBoss8Dragon__sub_8028A900(void *self, Vec *pos, DragonAttackParams *params) {
    f32 off;
    void *temp_r31;
    void *temp_r4;
    void *var_r31;
    temp_r4 = *(void **)((s8 *)lbl_805D4DD8 + 0x42C);
    temp_r31 = *(void **)((s8 *)temp_r4 + 0x78);
    off = ((TBoss8Dragon *)params)->calc_sq_offset(15.0f);
    for (var_r31 = *(void **)((s8 *)temp_r31 + 0x2C); var_r31 != NULL; var_r31 = *(void **)((s8 *)var_r31 + 0x30)) {
        if (!(*(s32 *)((s8 *)var_r31 + 0) & 0x10) && (((TBoss8Dragon *)pos)->is_within_xz_distance((u8 *)var_r31, (f32)off) != 0)) {
            *(s32 *)((s8 *)var_r31 + 0) |= 0x10;
        }
    }
}

}
