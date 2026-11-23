#ifndef PSO_ITEM_TITEMTEXLOAD_H
#define PSO_ITEM_TITEMTEXLOAD_H

struct AdxfHandle;
#include "pso/system/task/TObject.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/item/TItemData.h"

class TItemTexLoad : public TObject {
public:
    void* m_archive_buffer;
    s32 m_state;
    s32 m_texture_index;
    AdxfHandle *m_archive_handle;
    NJS_TEXLIST m_texture_list;
    NJS_TEXNAME m_texture_entry;

    TItemTexLoad(TObject* parent);
    virtual ~TItemTexLoad();
    virtual void run_task();
    void load_texture_archive();
    void unload_texture();
    s32 load_texture(s32 index);
    s32 load_item_icon(TItemData* item);
    NJS_TEXLIST* ready_texture_list();
    static TItemTexLoad* create(TObject* parent);
    static void free_textures();
};
#include <stddef.h>
LAYOUT_ASSERT(ItemTexBaseSize, sizeof(TObject)==0x1C);
LAYOUT_ASSERT(ItemTexLoadSize, sizeof(TItemTexLoad)==0x40);
LAYOUT_ASSERT(ItemTexBufferOffset, offsetof(TItemTexLoad,m_archive_buffer)==0x1C);
LAYOUT_ASSERT(ItemTexStateOffset, offsetof(TItemTexLoad,m_state)==0x20);
LAYOUT_ASSERT(ItemTexIndexOffset, offsetof(TItemTexLoad,m_texture_index)==0x24);
LAYOUT_ASSERT(ItemTexHandleOffset, offsetof(TItemTexLoad,m_archive_handle)==0x28);
LAYOUT_ASSERT(ItemTexListOffset, offsetof(TItemTexLoad,m_texture_list)==0x2C);
LAYOUT_ASSERT(ItemTexEntryOffset, offsetof(TItemTexLoad,m_texture_entry)==0x34);
LAYOUT_ASSERT(GinjaTextureListSize, sizeof(NJS_TEXLIST)==8);
LAYOUT_ASSERT(GinjaTextureListEntries, offsetof(NJS_TEXLIST,textures)==0);
LAYOUT_ASSERT(GinjaTextureListCount, offsetof(NJS_TEXLIST,nbTexture)==4);
LAYOUT_ASSERT(GinjaTextureEntrySize, sizeof(NJS_TEXNAME)==12);
LAYOUT_ASSERT(GinjaTextureEntryName, offsetof(NJS_TEXNAME,filename)==0);
LAYOUT_ASSERT(GinjaTextureEntryValue04, offsetof(NJS_TEXNAME,attr)==4);
LAYOUT_ASSERT(GinjaTextureEntryTexture, offsetof(NJS_TEXNAME,texture)==8);

void load_item_kt_afs(void);

// --- C functions defined in TItemTexLoad.cpp ---
void load_item_kt_afs(void);
// --- end of C functions

#endif
