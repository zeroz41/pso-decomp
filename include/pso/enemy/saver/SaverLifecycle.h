#ifndef PSO_ENEMY_SAVER_SAVERLIFECYCLE_H
#define PSO_ENEMY_SAVER_SAVERLIFECYCLE_H

#include "types.h"

struct TObjEneSaver;
extern "C" {
void TObjPlayer__sub_800A4294(void);
void sub_800A4D9C__12TObjEneSaverFv(u8 *arg0);
void sub_800A5FA8__12TObjEneSaverFv(u8 *arg0);
void render__12TObjEneSaverFv(u8 *arg0);
void run_task__12TObjEneSaverFv(u8 *arg0);
void *create_ene_saver(void *arg0);
void initialize_saver_resources(void);
void update_collapse_and_destroy__12TObjEneSaverFv(u8 *arg0);
}

#endif
