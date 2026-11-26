#ifndef PSO_RENDER_PSOLOADTEXTURE_H
#define PSO_RENDER_PSOLOADTEXTURE_H

#include "types.h"

struct GvmFileHeader {
    u8 magic[4];
    u32 size;
    u16 flags;
    u16 count;
};

struct NJS_TEXLIST;

s32 psoLoadTexturePvmFile(const char *name, NJS_TEXLIST *texlist);
s32 psoLoadTexture(NJS_TEXLIST *texlist);
NJS_TEXLIST *LoadPvmFileTls(const char *filename);

#endif
