#ifndef PSO_ENEMY_SAVER_SAVERLIFECYCLE_H
#define PSO_ENEMY_SAVER_SAVERLIFECYCLE_H

#include "types.h"

// Points fake_tec_texlist at the technique ring-wave textures and picks its first texture.
void init_fake_tec_texlist();

extern "C" {
void *create_ene_saver(void *set_data);
void initialize_saver_resources(void);
}

#endif
