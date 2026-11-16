#include "types.h"
#include "pso/technique/TTecFoie.h"
struct Tec_8022FB70 { u8 pad[0x20]; f32 pos[3]; u8 pad2c[0xC6 - 0x2C]; s16 band; };

extern "C" {
s32 play_sound_effect(s32 id, void *pos, s32 a, s32 b);
void update_technique_slot__10TTecRaFoieFl(s32 handle, s32 pitch, s32 c);
void TTecFoie::play_foie_cast_sound() {
    Tec_8022FB70 *self = (Tec_8022FB70 *)this;
    s32 h;
    switch (self->band) {
    case 0:
        h = play_sound_effect(0x4002A600, self->pos, 0, 0);
        if (h >= 0) {
            update_technique_slot__10TTecRaFoieFl(h, 0x100, 0);
        }
        break;
    case 1:
    case 2:
        play_sound_effect(0x4002A600, self->pos, 0, 0);
        break;
    case 3:
        h = play_sound_effect(0x4002A600, self->pos, 0, 0);
        if (h >= 0) {
            update_technique_slot__10TTecRaFoieFl(h, -0x180, 0);
        }
        break;
    case 4:
        h = play_sound_effect(0x4002A600, self->pos, 0, 0);
        if (h >= 0) {
            update_technique_slot__10TTecRaFoieFl(h, -0x250, 0);
        }
        break;
    case 5:
        h = play_sound_effect(0x4002A600, self->pos, 0, 0);
        if (h >= 0) {
            update_technique_slot__10TTecRaFoieFl(h, -0x100, 0);
        }
        break;
    }
}

}
