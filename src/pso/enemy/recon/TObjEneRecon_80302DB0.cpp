#include "types.h"
#include "pso/render/reflection.h"

extern unsigned char scene_sora_recon_active_flag;
void request_reflection_render() { scene_sora_recon_active_flag = 1; }
