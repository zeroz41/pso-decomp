#ifndef PSO_ITEM_TITEMTEXLOAD_H
#define PSO_ITEM_TITEMTEXLOAD_H
#include "pso/system/task/TObject.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/item/TItemData.h"

class TItemTexLoad : public TObject {
public:
    void* m_archive_buffer;
    s32 m_state;
    s32 m_texture_index;
    u32 m_archive_handle;
    GinjaTextureList m_texture_list;
    GinjaTextureEntry m_texture_entry;

    TItemTexLoad(TObject* parent);
    virtual ~TItemTexLoad();
    virtual void run_task();
    void load_texture_archive();
    void unload_texture();
    s32 load_texture(s32 index);
    s32 load_item_icon(TItemData* item);
    GinjaTextureList* ready_texture_list();
    static TItemTexLoad* create(TObject* parent);
    static void free_textures();
};
#include <stddef.h>
typedef char ItemTexBaseSize[(sizeof(TObject)==0x1C)?1:-1];
typedef char ItemTexLoadSize[(sizeof(TItemTexLoad)==0x40)?1:-1];
typedef char ItemTexBufferOffset[(offsetof(TItemTexLoad,m_archive_buffer)==0x1C)?1:-1];
typedef char ItemTexStateOffset[(offsetof(TItemTexLoad,m_state)==0x20)?1:-1];
typedef char ItemTexIndexOffset[(offsetof(TItemTexLoad,m_texture_index)==0x24)?1:-1];
typedef char ItemTexHandleOffset[(offsetof(TItemTexLoad,m_archive_handle)==0x28)?1:-1];
typedef char ItemTexListOffset[(offsetof(TItemTexLoad,m_texture_list)==0x2C)?1:-1];
typedef char ItemTexEntryOffset[(offsetof(TItemTexLoad,m_texture_entry)==0x34)?1:-1];
typedef char GinjaTextureListSize[(sizeof(GinjaTextureList)==8)?1:-1];
typedef char GinjaTextureListEntries[(offsetof(GinjaTextureList,entries)==0)?1:-1];
typedef char GinjaTextureListCount[(offsetof(GinjaTextureList,count)==4)?1:-1];
typedef char GinjaTextureEntrySize[(sizeof(GinjaTextureEntry)==12)?1:-1];
typedef char GinjaTextureEntryName[(offsetof(GinjaTextureEntry,name)==0)?1:-1];
typedef char GinjaTextureEntryValue04[(offsetof(GinjaTextureEntry,value04)==4)?1:-1];
typedef char GinjaTextureEntryTexture[(offsetof(GinjaTextureEntry,texture)==8)?1:-1];

void load_item_kt_afs(void);

// --- C functions defined in TItemTexLoad.cpp ---
void load_item_kt_afs(void);
// --- end of C functions

#endif
