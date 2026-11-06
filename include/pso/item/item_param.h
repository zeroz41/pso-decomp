#ifndef PSO_ITEM_ITEM_PARAM_H
#define PSO_ITEM_ITEM_PARAM_H

#include "types.h"

extern "C" {
void *get_armor_pmt_record(int type, int id);
}
void *get_photon_color_record(int i);

// --- C functions defined in item_param.cpp ---
extern "C" {
void *get_armor_pmt_record(int type, int id);
}
// --- end of C functions

#endif
