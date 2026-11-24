#ifndef PSO_UI_CHARCREATE_TCHCRLOADAFS_H
#define PSO_UI_CHARCREATE_TCHCRLOADAFS_H

struct AdxfHandle;

#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

class TChCrLoadAfs : public TObject {
public:
    TChCrLoadAfs(TObject *parent, u32 archive, u32 entry);
    virtual ~TChCrLoadAfs();
    void release_load_slot();
    s32 try_begin_load();
    virtual void run_task();
    void start_download();
    void poll_load();
    void sub_8028B944();
    void sub_8028B940();
    AdxfHandle *load_handle;
    u32 source_20;
    u32 source_24;
    u8 *buffer_address;
    s32 load_state;
    s32 state_30;
    s32 timer;

public:
    s32 is_load_complete();
    u8 *get_load_buffer();
    static TChCrLoadAfs *create(TObject *parent, u32 archive, u32 entry);
};

LAYOUT_ASSERT(TChCrLoadAfs_size, sizeof(TChCrLoadAfs) == 0x38);
LAYOUT_ASSERT(TChCrLoadAfs_load_handle_offset, offsetof(TChCrLoadAfs, load_handle) == 0x1c);
LAYOUT_ASSERT(TChCrLoadAfs_buffer_address_offset, offsetof(TChCrLoadAfs, buffer_address) == 0x28);
LAYOUT_ASSERT(TChCrLoadAfs_load_state_offset, offsetof(TChCrLoadAfs, load_state) == 0x2c);
LAYOUT_ASSERT(TChCrLoadAfs_timer_offset, offsetof(TChCrLoadAfs, timer) == 0x34);

s32 find_player_texture_name_ordinal(u8 *object);

#endif
