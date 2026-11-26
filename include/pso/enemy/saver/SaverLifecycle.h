#ifndef PSO_ENEMY_SAVER_SAVERLIFECYCLE_H
#define PSO_ENEMY_SAVER_SAVERLIFECYCLE_H

#include "types.h"

// Points fake_tec_texlist at the technique ring-wave textures and picks its first texture.
void init_fake_tec_texlist();

void *create_ene_saver(void *set_data);
void initialize_saver_resources(void);

// Where render's node callback last placed the particle node (node 0x1A), in world space. 16 bytes in the
// original; only the first 12 are used, as a point.
struct SaverNodePoint { Vec pos; u8 pad_c[4]; };

#endif
