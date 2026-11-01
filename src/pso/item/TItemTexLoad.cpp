#include "pso/item/TItemTexLoad.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/unk/text_803CC294.h"
#include "pso/misc/TLobby.h"

extern "C" {
void prs_decompress_alloc(void*, s32, s32);
void load_gvm_texture_archive(s32, void*);
u32 adxf_open_afs__6TLobbyFii(int, int);
void *lookup_item_pmt_record(u8 *item);
s32 TLobby__sub_803CC4C0(s32);
void mem_free(void*);
void* mem_alloc(u32);
void TObjPlayer__sub_803DD5E8(void*, void*, void*, int);
char* strncpy(char*, const char*, u32);
void TLobby__sub_801E3E9C(s32, const char*, void*, s32);
extern const char item_kt_archive_filename[] = "ItemKT.afs";
extern const char TItemTexLoad_class_name[] = "TItemTexLoad";
const char* TItemTexLoad_name = TItemTexLoad_class_name;
void* item_texture_afs_work_buffer;
char* item_texture_filename_buffer;
}

void TItemTexLoad::load_texture_archive() {
    char t[12] = "ItemTexLoad";
    s32 r = TLobby::tmp_buf_use_req((const char *)(&t));
    if (r != 0) {
        prs_decompress_alloc(m_archive_buffer, r, 0x40000);
        load_gvm_texture_archive(r, &m_texture_list);
        TLobby::tmp_buf_release((const char *)&t);
        m_state = 2;
    } else {
        unload_texture();
    }
}

void TItemTexLoad::unload_texture() {
    if (m_state == 2) free_texture_if_valid((u32)&m_texture_list);
    if (m_state == 1) ((TLobby *)m_archive_handle)->close_adxf_handle();
    m_state = 0;
    m_texture_index = -1;
}

s32 TItemTexLoad::load_texture(s32 index) {
    if ((index >= 0) && (index < 0x17B) && ((u32)m_archive_buffer != 0U)) {
        if (index == m_texture_index) return 1;
        unload_texture();
        m_texture_index = index;
        m_archive_handle = adxf_open_afs__6TLobbyFii(0xB8, m_texture_index);
        if (m_archive_handle == 0U) {
            unload_texture();
            return 0;
        }
        m_state = 1;
        {
            s32 r = TLobby__sub_803CC53C((u8 *)m_archive_handle);
            if (r < 0) {
                unload_texture();
                return 0;
            }
            TLobby::read_checked_align(m_archive_handle, r, (int)m_archive_buffer);
        }
        return 1;
    }
    return 0;
}

s32 TItemTexLoad::load_item_icon(TItemData* item) {
    s32* rec;
    s32 id;
    if (item != NULL) {
        rec = (s32 *)lookup_item_pmt_record((u8 *)item);
        id = *rec;
        if (rec != NULL) {
            switch (item->data1.data_u8[0]) {
            case 0:
                if (id >= 0x94 && id < 0x20E) return load_texture(id - 0x94);
                return load_texture(0x17A);
            case 1:
                break;
            case 2:
                if (item->data1.data_u8[1] < 0x42U) return load_texture(item->data1.data_u8[1] + 0x12E);
                return load_texture(0x12E);
            }
        }
    }
    return 0;
}

GinjaTextureList* TItemTexLoad::ready_texture_list() {
    if (m_state == 2) return &m_texture_list;
    return NULL;
}

void TItemTexLoad::run_task() {
    if (m_state == 1) {
        switch (TLobby__sub_803CC4C0(m_archive_handle)) {
        case 3:
            ((TLobby *)m_archive_handle)->close_adxf_handle();
            if (TLobby::tmp_buf_is_free() != 0) load_texture_archive();
            else m_state = 3;
            break;
        case 1:
        case 4: {
            s32 v = m_texture_index;
            unload_texture();
            load_texture(v);
            break;
        }
        }
    } else if (m_state == 3) {
        if (TLobby::tmp_buf_is_free() != 0) load_texture_archive();
    }
}

TItemTexLoad::~TItemTexLoad() {
    unload_texture();
    mem_free(m_archive_buffer);
    m_archive_buffer = nullptr;
}

TItemTexLoad::TItemTexLoad(TObject* parent) : TObject(parent) {
    m_name = TItemTexLoad_name;
    TObjPlayer__sub_803DD5E8(&m_texture_list, &m_texture_entry, item_texture_filename_buffer, 1);
    m_texture_entry.value04 = 0;
    m_texture_list.count = 1;
    m_texture_index = -1;
    m_state = 0;
    m_archive_buffer = mem_alloc(0x4800);
}

TItemTexLoad* TItemTexLoad::create(TObject* parent) {
    return new TItemTexLoad(parent);
}

void TItemTexLoad::free_textures() {
    mem_free(item_texture_filename_buffer);
    item_texture_filename_buffer = 0;
    mem_free(item_texture_afs_work_buffer);
    item_texture_afs_work_buffer = 0;
}

void load_item_kt_afs(void) {
    item_texture_afs_work_buffer = mem_alloc(0x40C);
    item_texture_filename_buffer = (char*)mem_alloc(0x1C);
    strncpy(item_texture_filename_buffer, item_kt_archive_filename, 0x1C);
    TLobby__sub_801E3E9C(0xB8, item_kt_archive_filename, item_texture_afs_work_buffer, 0);
}
