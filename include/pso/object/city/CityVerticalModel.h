#ifndef PSO_OBJECT_CITY_CITYVERTICALMODEL_H
#define PSO_OBJECT_CITY_CITYVERTICALMODEL_H

#include "types.h"

u8 *construct_city_vertical_model(u8 *arg0, saddr parent, saddr set_data);
extern "C" {
void *create_city_vertical_model(void *arg0);
}
void *destroy_city_vertical_model(void *arg0, s16 arg1);

#endif
