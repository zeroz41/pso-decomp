#ifndef PSO_RENDER_PSOLOADTEXTURE_H
#define PSO_RENDER_PSOLOADTEXTURE_H

#include "types.h"

struct GvmFileHeader {
    u8 magic[4];
    u32 size;
    u16 flags;
    u16 count;
};

// A GVR texture in memory: the GBIX chunk, the GVRT chunk header, then the texels.
struct GvrTexture {
    u8 gbix_magic[4];
    u32 gbix_size;
    u16 global_index[2];
    u8 pad_0c[4];
    u8 gvrt_magic[4];
    u32 gvrt_size;
    u16 flags;
    u8 pixel_format;
    u8 data_format;
    u16 width;
    u16 height;
    u16 texels[1];
};

struct NJS_TEXLIST;

s32 psoLoadTexturePvmFile(const char *name, NJS_TEXLIST *texlist);
s32 psoLoadTexture(NJS_TEXLIST *texlist);
NJS_TEXLIST *LoadPvmFileTls(const char *filename);
void free_if_valid(NJS_TEXLIST *texlist);

#endif
