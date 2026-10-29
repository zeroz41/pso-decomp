#include "types.h"
#include "pso/boss/TBoss8Dragon_80065C90.h"
#include "pso/enemy/TObjEneMe3Stelth_800F0AE4.h"
#include "pso/map/CsnQuery.h"
#include "pso/unk/text_80087278.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneMe3Stelth.h"
#include "pso/TParticleCtrl.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

#pragma readonly_strings on


struct Stack_800F0B4C
{
  s32 sp8;
  f32 spC;
  u8 trailing_storage[0x4];
};

extern "C" {
u8 *load_gvm_texture_file(s32 arg0);
extern u32 blob_shadow_texture_list;
s32 TObjEneGibbles__sub_800D8988(void *);
extern const f32 TObjEneMe3Stelth__data_805DA808;
extern const f32 TObjEneMe3Stelth__data_805DA80C;
s32 play_sound_effect(s32, s32, s32, s32);
extern const f32 lbl_805DA814;
extern const f32 lbl_805DA818;
s32 release_texture_list(void*);

void TObjEneMe3Stelth::destroy_resources() {
    if ((u32) blob_shadow_texture_list != 0U) {
        release_texture_list((void*)blob_shadow_texture_list);
        TAdSinglePlyChrSelectGC::safe_free(blob_shadow_texture_list);
        blob_shadow_texture_list = 0U;
    }
}
}
void load_ha_u032_kage(void) { (*(int *)&blob_shadow_texture_list) = (int)load_gvm_texture_file((s32)(unsigned char *)"ha_u032_kage.gvm"); }

s32 TObjEneMe3Stelth::try_spawn_ground_effect(s32 arg1) {
    s32 arg0 = (s32)this;
  Stack_800F0B4C stack;
  s32 temp_r31;
  s32 particle_effect;
  u8 *temp_r3;
  VecCopy((Vec *)(&stack.sp8), (const Vec *)arg1);
  stack.spC += TObjEneMe3Stelth__data_805DA808;
  temp_r3 = (u8 *) csnVectorUnder((Vec *)&stack.sp8, (u32 *)(arg0 + 0x120), 0x15);
  if ((temp_r3 != 0) && ((*((s32 *) (((s8 *) temp_r3) + 0))) & 4))
  {
    particle_effect = ((s32)spawn_particle_effect((void *)((int) ((*((s32 *) (((s8 *) temp_r3) + 4))) + 0x38)), 0x49));
    if (particle_effect != 0)
    {
      ;
      attach_particle_model((u8 *)particle_effect, (int) TParticleCtrl::get_particle_model(2), (int) TParticleCtrl::get_instance(), 0, 1, (f32) TObjEneMe3Stelth__data_805DA80C);
    }
    spawn_particle_effect((void *)((int) ((*((s32 *) (((s8 *) temp_r3) + 4))) + 0x38)), 0xA4);
    TObjEneGibbles__sub_800D8988((void *)(arg0 + 0x38));
    return 1;
  }
  return 0;
}
void TObjEneMe3Stelth::play_hit_effect() {
    s32 arg0 = (s32)this;
    if (try_spawn_ground_effect(arg0 + 0x38) != 0) {
        play_sound_effect(0x3A836, arg0 + 0x38, 0, 0);
        return;
    }
    spawn_particle_effect((void *)(arg0 + 0x38), 0xF3);
    play_sound_effect(0x3A836, arg0 + 0x38, 0, 0);
}
void TObjEneMe3Stelth__sub_800F0C90(u8 *arg0) {
    if ((((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DA814) != 0) || (((TObjMotion *)arg0)->is_passing_frame((f32)((f32)lbl_805DA818)) != 0)) {
        ((TObjEneMe3Stelth *)arg0)->try_spawn_ground_effect((s32)(arg0 + 0x38));
    }
}

typedef struct Stack_800F0B4C Stack_800F0B4C;
