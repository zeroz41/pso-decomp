#ifndef PSO_OBJECT_WARP_TOBJLABOMAPWARP_80185248_H
#define PSO_OBJECT_WARP_TOBJLABOMAPWARP_80185248_H

#include "types.h"

struct TObjCityMainWarp;
struct TObjCityAreaWarp;
struct TObjCityMapWarp;
struct TObjLaboMapWarp;
extern "C" {
void *TObjCityAreaWarp__ct(TObjCityAreaWarp *arg0);
void *TObjCityMainWarp__ct(void *arg0, void *arg1, void *arg2);
void *TObjCityMapWarp__ct(void *arg0);
void *TObjLaboMapWarp__ct(void *arg0);
void clear_enabled_main_warps(void);
void unlock_main_warp_destination(s32 id);
}

#endif
