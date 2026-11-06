#ifndef PSO_RENDER_CHUNKTEXTURESTRIPCOLLECTOR_H
#define PSO_RENDER_CHUNKTEXTURESTRIPCOLLECTOR_H

#include "types.h"

void collect_plist_strips_by_texture(void *ctx, s16 *p, s32 tex);
void count_plist_strips_by_texture(void *ctx, void *plist, void *arg);

#endif
