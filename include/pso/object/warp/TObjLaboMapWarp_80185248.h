#ifndef PSO_OBJECT_WARP_TOBJLABOMAPWARP_80185248_H
#define PSO_OBJECT_WARP_TOBJLABOMAPWARP_80185248_H

#include "types.h"

struct TObjCityMainWarp;
struct TObjCityAreaWarp;
struct TObjCityMapWarp;
struct TObjLaboMapWarp;
extern "C" {
void clear_enabled_main_warps(void);
void unlock_main_warp_destination(s32 id);
}

#endif
