#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/object/fence/TLazerFenceSw.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/object/container/TContainerAncient01R.h"

void TContainerAncient01R::trigger_spawn(const Vec *position, s32 effect_id) {
    spawn_particle_effect(position, effect_id);
}

// Texture archives load_forest_box_resources (TObjContainerItem) loads. They sit
// in this unit's .rodata, between that unit's literals and TContainerAncient01's
// (an 8-aligned start and a 4-byte pad after), and the original addresses them
// by symbol while it pools TObjContainerItem's own data, so they are not that
// unit's.
extern const char seabed_container_texture_filename[] = "obj_seabed_con.GVM";
extern const char forest_box_texture_filename_a[] = "fs_obj_hako01_a.gvm";
extern const char forest_box_texture_filename_n[] = "fs_obj_hako01_n.gvm";
