#ifndef PSO_UI_HUD_RADARMAPDATA_H
#define PSO_UI_HUD_RADARMAPDATA_H

#include "types.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/vector.h"

struct GinjaModel;

// Floor map resource formats read by TRaderMapCore: each map is an array of records, an optional texture list and a count.
typedef struct RadarPieceInit {
    s16 id, flags;
    f32 translation[3]; u32 rotation[3];
    f32 fade, radius; void *object;
} RadarPieceInit;

typedef struct RadarPieceInitMap { RadarPieceInit *pieces; void *textures; s32 count; } RadarPieceInitMap;

struct RadarRegion {
    s16 id; s16 flags; f32 x, y, z;
    u32 angles[3]; f32 fade, radius; void *model;
};

struct RadarRegionMap { struct RadarRegion *regions; void *textures; s32 count; };

struct RadarPiece {
    s16 a;
    s16 flags;
    u8 rest[0x24];
};

struct RadarPieceMap {
    RadarPiece* pieces;
    s32 b;
    s32 count;
};

struct RadarDot { f32 x, z, w; s16 c; s16 type; s32 color; };

struct RadarModelBounds { u8 pad[8]; Vec a; Vec b; };

struct RadarModelRef { void *p0; RadarModelBounds *m; };

struct RadarModelRegion {
    s16 id; s16 flags; f32 x, y, z;
    u32 angles[3]; f32 fade, radius; RadarModelRef *model;
};

struct RadarModelRegionMap { RadarModelRegion *regions; void *textures; s32 count; };

struct RadarBackdropColor { f32 r, g, b, a; };

struct RadarMeshModel { u8 pad[4]; GinjaModel *mesh; };

struct RadarBackdropRecord {
    s16 id; s16 flags;
    f32 x, y, z;
    s32 rx, ry, rz;
    f32 alpha;
    u8 pad20[4];
    RadarMeshModel *model;
};

struct RadarBackdropMap { RadarBackdropRecord *recs; NJS_TEXLIST *tex; s32 count; };

struct RadarMarker { f32 x; f32 z; f32 scale; u16 rot; s16 kind; s32 color; };

#endif
