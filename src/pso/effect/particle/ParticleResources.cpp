#include "pso/system/memory.h"
#include "types.h"
#include <stdio.h>
#include <string.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/ParticleParam.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/map/FloorArea.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/ResourceFile.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#pragma readonly_strings on

const char *bm_tec_regurar_motion_names[1] = {0};
const char *bm_tec_regurar_model_names[4] = {"eff_f_foie.gj", "eff_sinowahamon.gj", "jungle_hamon.gj", 0};
BmlResourceDescriptor particle_regular_bml_descriptor = {"bm_tec_regurar.bml", bm_tec_regurar_model_names, bm_tec_regurar_motion_names, 3, 0};
const char *particle_entry_path = "particleentry.dat";

void TParticleCtrl::free_system() { mem_free(particle_global_entry_table); particle_global_entry_table = 0; }

void TParticleCtrl::free_all() {
    mem_free(particle_area_entry_table);
    particle_area_entry_table = 0;
    if (TParticleCtrl::regular_bml_resource != NULL) {
        delete TParticleCtrl::regular_bml_resource;
        TParticleCtrl::regular_bml_resource = NULL;
    }
    if (TParticleCtrl::texture_list != NULL) {
        release_texture_list(TParticleCtrl::texture_list);
        safe_free(TParticleCtrl::texture_list);
        TParticleCtrl::texture_list = NULL;
    }
}

void TParticleCtrl::init_particle_buffer() {
    s32 size;
    particle_global_entry_table = reinterpret_cast<ParticleParam *>(mem_alloc(0x13000));
    size = read_disc_file(particle_entry_path, particle_global_entry_table);
    particle_pool_limit = 0;
    if (size >= 0) {
        particle_pool_limit = (u32)size / sizeof(ParticleParam);
    }
}

ParticleParam *TParticleCtrl::get_particle_by_index(s32 particle_index) {
    if (particle_index >= 0x200) {
        return &particle_area_entry_table[particle_index - 0x200];
    }
    return &particle_global_entry_table[particle_index];
}


extern char particle_entry_file_name[];
extern char particle_area_entry_file_format_0[];
extern char particle_area_entry_file_format[];
extern char particle_texture_file_name[];

void load_particle_entry_resources(void) {
    char name[0x20];
    s32 area;
    memset(name, 0, 0x20);
    strcpy(name, particle_entry_file_name);
    area = get_current_floor_area();
    if (area < 10) {
        if (area < 0) {
            return;
        }
        sprintf(name, particle_area_entry_file_format_0, area);
    } else {
        sprintf(name, particle_area_entry_file_format, area);
    }
    particle_area_entry_table = reinterpret_cast<ParticleParam *>(mem_alloc(0x2600));
    read_disc_file(name, particle_area_entry_table);
    TParticleCtrl::regular_bml_resource =
        new BmlResource(1, &particle_regular_bml_descriptor, 0, 0, NULL);
    TParticleCtrl::texture_list = load_gvm_texture_file(particle_texture_file_name);
}

__declspec(section ".rodata") extern char particle_entry_file_name[] = "particleentrya";
__declspec(section ".rodata") extern char particle_area_entry_file_format_0[] = "particleentrya0%d.dat";
__declspec(section ".rodata") extern char particle_area_entry_file_format[] = "particleentrya%d.dat";
__declspec(section ".rodata") extern char particle_texture_file_name[] = "tecregular.gvm";

s32 particle_pool_limit = 1;
