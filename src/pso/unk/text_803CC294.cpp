#include "pso/audio/AdxStreamFile.h"
#include "pso/system/Adxf.h"
#include <string.h>

#include "types.h"
#include "pso/audio/AdxfInternal.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/unk/text_803CC294.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/SjRingBuffer.h"

struct Chunk_803CC294 { u16 id; u16 len; s32 off; };

struct Ent_803CC294 {
    struct Ent_803CC294 *next; s32 f4; s32 f8; u16 fc; s8 fe; u8 pad_f; char name[0x100];
    s32 mode; u16 f114; u16 arr[1];
};

struct Ent_803CD5C4 {
    u8 pad_0[4]; s32 f4; s32 f8; u16 fc; u8 pad_e[0x114 - 0xE]; s16 f114; s16 arr[1];
};


extern Ent_803CC294 *afs_archive_toc_table[];
extern s32 lobby_adxf_current_file_id;
extern s32 lobby_afs_toc_entry_index;
s32 lbl_805D75E8;
u8 * lbl_805D75EC;
u8 *lbl_805D75F0;
extern s32 adxf_log_write_index;
extern s32 lbl_805D75E4;


// Command history: one entry per call (phase 0) and per return (phase 1) of an ADXF command.
template <typename LastArgument>
inline void hist_803CC294(s32 cmd, s32 phase, u16 &sequence, AdxfHandle *a, s32 b, LastArgument c) {
    LogEnt_803CD16C *e;
    adxf_log_write_index %= 256;
    e = &lbl_8057B7D0[adxf_log_write_index];
    if (phase == 0) {
        sequence++;
    }
    e->type = cmd;
    e->phase = phase;
    e->seq = sequence;
    e->handle = a;
    e->b = b;
    e->set_last_argument(c);
    adxf_log_write_index++;
}

extern "C" {

// ADXF_SetReqRdSct (named by its message). The linker removed it; its message opens the TU's string pool.
void adxf_set_req_rd_sct(AdxfHandle *adxf, s32 nsct) {
    if (adxf->state == 2) {
        TLobby::notify_error("E0041201:state is reading(ADXF_SetReqRdSct)");
        return;
    }
    adxf->requested_read_sectors = nsct;
}

inline s32 check_803CC294(s32 arg0, s32 arg1) {
    if (arg0 < 0 || arg0 >= 0x100) {
        TLobby::notify_error("E9040828:'ptid' is range outside.");
        return -3;
    }
    if (afs_archive_toc_table[arg0] == NULL) {
        TLobby::notify_error("E9040828:'ptid' is range outside.");
        return -3;
    }
    if (arg1 < 0 || arg1 >= afs_archive_toc_table[arg0]->f8) {
        TLobby::notify_error("E9040828:'flid' is range outside.");
        return -3;
    }
    return 0;
}
s32 TLobby::get_afs_file_info(s32 arg0, s32 arg1, char *dest, s32 *arg3, s32 *arg4, s32 *arg5) {
    s32 st;
    Ent_803CC294 *e;
    u16 *arr;
    s32 sum;
    s32 i;
    Ent_803CC294 *next;
    st = check_803CC294(arg0, arg1);
    if (st < 0) {
        *arg3 = 0;
        *arg4 = -1;
        *arg5 = -1;
        return st;
    }
    e = afs_archive_toc_table[arg0];
    while ((next = e->next) != NULL) {
        Chunk_803CC294 *c = (Chunk_803CC294 *)&e->f114;
        for (i = 0; i < e->fc; i++, c++) {
            if (c->id == arg1) {
                strncpy(dest, e->name, 0x100);
                *arg3 = e->mode;
                *arg4 = c->off;
                *arg5 = c->len;
                return st;
            }
        }
        e = next;
    }
    sum = e->f114;
    arr = e->arr;
    for (i = 0; i < arg1; i++) {
        sum += arr[i];
    }
    strncpy(dest, e->name, 0x100);
    *arg3 = e->mode;
    *arg4 = sum;
    *arg5 = arr[arg1];
    return st;
}

s32 ADXF_GetStat(AdxfHandle *file) {
    if (file == NULL) {
        TLobby::notify_error("E9040832:'adxf' is NULL.(ADXF_GetStat)");
        return -3;
    }
    return file->state;
}

// ADXF_GetNumReadSct and ADXF_GetNumReqSct (named by their messages): removed by the linker, their
// messages stay in the string pool between ADXF_GetStat's and ADXF_GetFsizeByte's.
s32 adxf_get_num_read_sct(AdxfHandle *adxf) {
    if (adxf == NULL) {
        TLobby::notify_error("E9040831:'adxf' is NULL.(ADXF_GetNumReadSct)");
        return -3;
    }
    return adxf->sectors_read;
}

s32 adxf_get_num_req_sct(AdxfHandle *adxf) {
    if (adxf == NULL) {
        TLobby::notify_error("E9040830:'adxf' is NULL.(ADXF_GetNumReqSct)");
        return -3;
    }
    return adxf->read_sector_count;
}

s32 ADXF_GetFsizeByte(AdxfHandle *file) {
    if (file == NULL) {
        TLobby::notify_error("E9040829:'adxf' is NULL.(ADXF_GetFsizeByte)");
        return -3;
    }
    return file->byte_size;
}
s32 ADXF_GetFsizeSct(AdxfHandle *file) {
    if (file == NULL) {
        TLobby::notify_error("E9040828:'adxf' is NULL.(ADXF_GetFsizeSct)");
        return -3;
    }
    return file->sector_count;
}


// ADXF_Tell (named by its message): removed by the linker, its message stays in the string pool.
s32 adxf_tell(AdxfHandle *adxf) {
    if (adxf == NULL) {
        TLobby::notify_error("E9040827:'adxf' is NULL.(ADXF_Tell)");
        return -3;
    }
    return adxf->sector_position;
}

inline s32 stop_803CC980(AdxfHandle *adxf) {
    s32 sp8;
    hist_803CC294(5, 0, lbl_8057B7B0.stop_sequence, adxf, -1, -1);
    if (adxf == NULL) {
        TLobby::notify_error("E9040822:'adxf' is NULL.(ADXF_Stop)");
        return -3;
    }
    if (adxf->state == 1) {
        return adxf->sector_position;
    }
    if (adxf->state == 3) {
        adxf->state = 1;
        return adxf->sector_position;
    }
    if (adxf->stream == 0) {
        TLobby::notify_error("E9040823:'adxf->stm' is NULL.(ADXF_Stop)");
        return -1;
    }
    TLobby::init_once();
    stop_adx_stream(adxf->stream);
    get_adx_stream_position(adxf->stream, &sp8);
    adxf->sectors_read = sp8;
    if (adxf->buffer != NULL && adxf->f2 == 0) {
        if (lbl_805D75E4 == 1) {
            TLobby::invalidate_cache(adxf->read_destination, adxf->read_buffer_size);
        }
        adxf->buffer->interface->destroy(adxf->buffer);
        adxf->buffer = NULL;
    }
    adxf->state = 1;
    TLobby::release_ref();
    hist_803CC294(5, 1, lbl_8057B7B0.stop_sequence, adxf, -1, -1);
    return adxf->sector_position;
}

// ADXF_Seek (named by its messages)
s32 ADXF_Seek(AdxfHandle *adxf, s32 pos, s32 type) {
    hist_803CC294(6, 0, lbl_8057B7B0.seek_sequence, adxf, pos, type);
    if (adxf == NULL) {
        TLobby::notify_error("E9040825:'adxf' is NULL.(ADXF_Seek)");
        return -3;
    }
    if (adxf->state == 2) {
        stop_803CC980(adxf);
    }
    if (type == 0) {
        adxf->sector_position = pos;
    } else if (type == 1) {
        adxf->sector_position += pos;
    } else if (type == 2) {
        adxf->sector_position = adxf->sector_count + pos;
    } else {
        TLobby::notify_error("E9040826:'type' is illigal.(ADXF_Seek)");
        return -3;
    }
    if (adxf->sector_position < 0) {
        adxf->sector_position = 0;
    } else if (adxf->sector_position > adxf->sector_count) {
        adxf->sector_position = adxf->sector_count;
    }
    hist_803CC294(6, 1, lbl_8057B7B0.seek_sequence, adxf, pos, type);
    return adxf->sector_position;
}

void TLobby__sub_803CC884(void) {
    AdxfHandle *p;
    s32 i;
    s32 sp8;
    TLobby::init_once();
    for (i = 0; i < 0x10; i++) {
        p = &adxf_file_handle_pool[i];
        if (p->used == 1 && p->state == 2) {
            p->state = get_adx_stream_status(p->stream);
            get_adx_stream_position(p->stream, &sp8);
            p->sectors_read = sp8;
            if (p->state == 3 || p->state == 4) {
                p->sector_position += p->sectors_read;
                if (p->buffer != NULL && p->f2 == 0) {
                    if (lbl_805D75E4 == 1) {
                        TLobby::invalidate_cache(p->read_destination, p->read_buffer_size);
                    }
                    p->buffer->interface->destroy(p->buffer);
                    p->buffer = NULL;
                }
            }
        }
    }
    TLobby::release_ref();
}

s32 ADXF_Stop(AdxfHandle *adxf) {
    return stop_803CC980(adxf);
}

s32 ADXF_ReadNw(AdxfHandle *file, s32 sectors, void *destination) {
    if ((uaddr)destination & 0x1F) {
        TLobby::notify_error("E0120401:'buf' isn't 32byte alignment.(ADXF_ReadNw)");
        return -3;
    }
    return ADXF_ReadNw32(file, sectors, destination);
}
#define LE32_803CD5C4(p) ((p)[0] | ((p)[1] << 8) | ((p)[2] << 16) | ((p)[3] << 24))
// ADXF_ReadNw32 (named by its messages)
s32 ADXF_ReadNw32(AdxfHandle *adxf, s32 nsct, void *buf) {
    SjRingBuffer *sj;
    s32 rqsct;
    hist_803CC294(4, 0, lbl_8057B7B0.read_sequence, adxf, nsct, buf);
    if (adxf == NULL) {
        TLobby::notify_error("E9040816:'adxf' is NULL.(ADXF_ReadNw32)");
        return -3;
    }
    if (nsct < 0) {
        TLobby::notify_error("E9040817:'nsct' is negative.(ADXF_ReadNw32)");
        return -3;
    }
    if (buf == NULL) {
        TLobby::notify_error("E9040818:'buf' is NULL.(ADXF_ReadNw32)");
        return -3;
    }
    if (adxf->state == 2) {
        return 0;
    }
    if (adxf->buffer != NULL) {
        TLobby::notify_error("E9040821:'sj' is NULL.(ADXF_ReadNw32)");
        return -1;
    }
    sj = sj_ring_buffer_create(buf, nsct << 11, 0);
    if (sj == NULL) {
        return -2;
    }
    adxf->read_destination = buf;
    adxf->read_buffer_size = nsct << 11;
    TLobby::init_once();
    if (lbl_805D75E4 == 1) {
        TLobby::invalidate_cache(adxf->read_destination, adxf->read_buffer_size);
    }
    if (get_adx_stream_status(adxf->stream) != 1) {
        stop_adx_stream(adxf->stream);
    }
    TLobby::init_once();
    adxf->read_start_sector = adxf->archive_start_sector + adxf->sector_position;
    adxf->read_sector_count = nsct < adxf->sector_count - adxf->sector_position ? nsct : adxf->sector_count - adxf->sector_position;
    adxf->sectors_read = rqsct = 0;
    if (adxf->read_sector_count == 0) {
        adxf->state = 3;
    } else {
        set_adx_stream_size_sectors(adxf->stream, adxf->read_sector_count);
        set_adx_stream_end_sector(adxf->stream, -1);
        set_buffer__6TLobbyFPPv(adxf->stream, sj);
        set_field_10_and_notify__6TLobbyFl(adxf->stream, adxf->archive_start_sector + adxf->sector_position);
        set_adx_max_read_sectors(adxf->stream, adxf->requested_read_sectors);
        adxf->state = 2;
        init_stream_position__6TLobbyFv(adxf->stream);
        rqsct = adxf->read_sector_count;
    }
    TLobby::release_ref();
    if (rqsct <= 0) {
        sj->interface->destroy(sj);
    } else {
        adxf->buffer = sj;
    }
    adxf->f2 = 0;
    TLobby::release_ref();
    hist_803CC294(4, 1, lbl_8057B7B0.read_sequence, adxf, nsct, buf);
    return rqsct;
}

// ADXF_ReadSj32 (named by its messages): removed by the linker, its three messages stay in the string pool.
s32 adxf_read_sj32(AdxfHandle *adxf, s32 nsct, SjRingBuffer *sj) {
    s32 rqsct;
    if (adxf == NULL) {
        TLobby::notify_error("E9040811:'adxf' is NULL.(ADXF_ReadSj32)");
        return -3;
    }
    if (nsct < 0) {
        TLobby::notify_error("E9040812:'nsct'is negative.(ADXF_ReadSj32)");
        return -3;
    }
    if (sj == NULL) {
        TLobby::notify_error("E9040813:'sj'is NULL.(ADXF_ReadSj32)");
        return -3;
    }
    TLobby::init_once();
    adxf->read_start_sector = adxf->archive_start_sector + adxf->sector_position;
    adxf->read_sector_count = nsct < adxf->sector_count - adxf->sector_position ? nsct : adxf->sector_count - adxf->sector_position;
    adxf->sectors_read = rqsct = 0;
    if (adxf->read_sector_count == 0) {
        adxf->state = 3;
    } else {
        set_adx_stream_size_sectors(adxf->stream, adxf->read_sector_count);
        set_adx_stream_end_sector(adxf->stream, -1);
        set_buffer__6TLobbyFPPv(adxf->stream, sj);
        set_field_10_and_notify__6TLobbyFl(adxf->stream, adxf->archive_start_sector + adxf->sector_position);
        set_adx_max_read_sectors(adxf->stream, adxf->requested_read_sectors);
        adxf->state = 2;
        init_stream_position__6TLobbyFv(adxf->stream);
        rqsct = adxf->read_sector_count;
    }
    TLobby::release_ref();
    return rqsct;
}

inline s32 rd32_803CD5C4(u8 *p) {
    return p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
}
inline s32 state_803CD5C4(void) {
    if (lobby_adxf_open_file_handle == NULL) {
        TLobby::notify_error("E9040832:'adxf' is NULL.(ADXF_GetStat)");
        return -3;
    }
    return lobby_adxf_open_file_handle->state;
}

inline AdxfHandle *find_803CD16C(void) {
    AdxfHandle *r = NULL;
    s32 i;
    for (i = 0; i < 16; i++) {
        if (adxf_file_handle_pool[i].used == 0) {
            r = &adxf_file_handle_pool[i];
            break;
        }
    }
    return r;
}
inline AdxfHandle *alloc_803CD16C(void) {
    AdxfHandle *s = find_803CD16C();
    if (s == NULL) {
        return NULL;
    }
    s->state = 1;
    s->stream = 0;
    s->read_start_sector = 0;
    s->read_sector_count = 0;
    s->sectors_read = 0;
    s->requested_read_sectors = 0x200;
    s->f2 = 0;
    s->buffer = 0;
    s->used = 1;
    return s;
}
inline s32 open_803CD16C(AdxfHandle *s, s32 partition, s32 arg1) {
    char filename[0x10C];
    s32 c;
    s32 b;
    s32 a;
    AdxStreamFile *h;
    if (TLobby::get_afs_file_info(partition, arg1, filename, &a, &b, &c) < 0) {
        return -3;
    }
    s->archive_start_sector = b;
    h = adxstm_open_fname_range__6TLobbyFPviiii(filename, a, b, c, 0);
    s->stream = h;
    if (h == 0) {
        TLobby::notify_error("E0110902:can't open file.(ADXF_OpenAfs)");
        return -1;
    }
    s->sector_count = c;
    s->byte_size = c << 11;
    return 0;
}

void TLobby::release_used_slots() {
    s32 i;
    AdxfHandle *p;
    for (i = 0; i < 0x10; i++) {
        p = &adxf_file_handle_pool[i];
        if (p->used == 1) {
            ADXF_Close(p);
        }
    }
}

void ADXF_Close(AdxfHandle *adxf) {
    {
        LogEnt_803CD16C *e;
        s32 i = adxf_log_write_index % 256;
        u16 seq;
        e = &lbl_8057B7D0[i];
        adxf_log_write_index = i;
        seq = ++lbl_8057B7B0.close_sequence;
        e->type = 3;
        e->phase = 0;
        e->seq = seq;
        e->handle = adxf;
        e->b = -1;
        e->c = -1;
        adxf_log_write_index = i + 1;
    }
    if (adxf != NULL) {
        TLobby::init_once();
        if ((s32)(u8)adxf->state == 2) {
            stop_803CC980(adxf);
        }
        if (adxf->stream != 0) {
            adxstm_close(adxf->stream);
        }
        memset(adxf, 0, sizeof(*adxf));
        TLobby::release_ref();
        {
            s32 i = adxf_log_write_index % 256;
            LogEnt_803CD16C *e = &lbl_8057B7D0[adxf_log_write_index = i];
            e->type = 3;
            e->phase = 1;
            e->seq = lbl_8057B7B0.close_sequence;
            e->handle = adxf;
            e->b = -1;
            e->c = -1;
            adxf_log_write_index = i + 1;
        }
    }
}

AdxfHandle *ADXF_OpenAfs(s32 partition, s32 file) {
    AdxfHandle *s;
    {
        LogEnt_803CD16C *e;
        s32 i = adxf_log_write_index % 256;
        u16 seq;
        e = &lbl_8057B7D0[i];
        adxf_log_write_index = i;
        seq = lbl_8057B7B0.afs_open_sequence + 1;
        e->type = 2;
        e->phase = 0;
        e->seq = seq;
        e->a = partition;
        e->b = file;
        lbl_8057B7B0.afs_open_sequence = seq;
        e->c = -1;
        adxf_log_write_index = i + 1;
    }
    TLobby::init_once();
    s = alloc_803CD16C();
    if (s != NULL) {
        if (open_803CD16C(s, partition, file) < 0) {
            ADXF_Close(s);
            s = NULL;
        }
    }
    TLobby::release_ref();
    {
        s32 i = adxf_log_write_index % 256;
        LogEnt_803CD16C *e = &lbl_8057B7D0[adxf_log_write_index = i];
        e->type = 2;
        e->phase = 1;
        e->seq = lbl_8057B7B0.afs_open_sequence;
        e->a = partition;
        e->b = file;
        e->c = -1;
        adxf_log_write_index = i + 1;
    }
    return s;
}

inline s32 open_803CD3A8(AdxfHandle *s, const void *name, s32 mode) {
    AdxStreamFile *h;
    s32 sz;
    if (name == 0) {
        TLobby::notify_error("E9081901:illigal parameter fname=null.(ADXF_Open)");
        return -1;
    }
    h = adxstm_open_fname_attr((const char *)name, mode, 0);
    if (h == 0) {
        TLobby::notify_error("E0110901:can't open file.(ADXF_Open)");
        return -1;
    }
    s->stream = h;
    sz = get_field_14__6TLobbyFv(h);
    s->sector_count = (sz + 0x7FF) / 2048;
    s->byte_size = sz;
    return 0;
}
AdxfHandle *ADXF_Open(const void *name, s32 mode) {
    AdxfHandle *s;
    {
        LogEnt_803CD16C *e;
        s32 i = adxf_log_write_index % 256;
        u16 seq;
        e = &lbl_8057B7D0[i];
        adxf_log_write_index = i;
        seq = lbl_8057B7B0.open_sequence + 1;
        e->type = 1;
        e->phase = 0;
        e->seq = seq;
        e->name = name;
        e->b = mode;
        lbl_8057B7B0.open_sequence = seq;
        e->c = -1;
        adxf_log_write_index = i + 1;
    }
    TLobby::init_once();
    s = alloc_803CD16C();
    if (s != NULL) {
        if (open_803CD3A8(s, name, mode) < 0) {
            ADXF_Close(s);
            s = NULL;
        }
    }
    TLobby::release_ref();
    {
        s32 i = adxf_log_write_index % 256;
        LogEnt_803CD16C *e = &lbl_8057B7D0[adxf_log_write_index = i];
        e->type = 1;
        e->phase = 1;
        e->seq = lbl_8057B7B0.open_sequence;
        e->name = name;
        e->b = mode;
        e->c = -1;
        adxf_log_write_index = i + 1;
    }
    return s;
}

// adxf_ChkPrmPt (named by its messages): inlined into ADXF_LoadPartitionNw below.
s32 adxf_chk_prm_pt(s32 ptid, void *ptinfo) {
    if (ptid < 0 || ptid >= 0x100) {
        TLobby::notify_error("E9040801:partition ID is range outside.(adxf_ChkPrmPt)");
        return -3;
    }
    if (ptinfo == NULL) {
        TLobby::notify_error("E9040802:'ptinfo' is NULL.(adxf_ChkPrmPt)");
        return -3;
    }
    return 0;
}

// ADXF_AddPartition and ADXF_LoadPartition (named by their messages): removed by the linker.
// Only their messages are left, between adxf_ChkPrmPt's and ADXF_GetPtStat's in the string pool.
s32 adxf_add_partition(void) {
    TLobby::notify_error("E9040808:can't open.(ADXF_AddPartition)");
    return -1;
}

s32 adxf_load_partition(s32 broken) {
    if (broken) {
        TLobby::notify_error("E9040810:file is broken.(ADXF_LoadPartition)");
        return -1;
    }
    TLobby::notify_error("E9040809:read error.(ADXF_LoadPartition)");
    return -1;
}

s32 TLobby::read_afs_toc(s32 id) {
    s16 *arr;
    Ent_803CD5C4 *e;
    s32 st;
    s32 i;
    if (id != lobby_adxf_current_file_id) {
        TLobby::notify_error("E0041303:illigal parameter 'ptid'.(ADXF_GetPtStat)");
        return -3;
    }
    st = state_803CD5C4();
    if (st != 3) {
        return st;
    }
    e = ((Ent_803CD5C4 * *)&afs_archive_toc_table)[id];
    arr = e->arr;
    if (e->f8 == 0) {
        s32 n;
        if (memcmp(lbl_805D75EC, "AFS", 3) != 0) {
            TLobby::notify_error("E0040701:Illigal format(not AFS).(ADXF_GetPtStat)");
            TLobby__sub_803CD804();
            return 4;
        }
        n = rd32_803CD5C4(lbl_805D75EC + 4);
        if (n > 0x10000) {
            TLobby::notify_error("E0040702:Illigal number of file.(ADXF_GetPtStat)");
            TLobby__sub_803CD804();
            return 4;
        }
        e->fc = n;
        i = 3;
        e->f8 = (u16)n;
        e->f4 = ((e->f8 + 1) * 2 + 0x116) & ~3;
        e->f114 = LE32_803CD5C4(lbl_805D75EC + 8) / 2048;
    } else {
        i = 1;
    }
    for (; i < 0x200; i += 2) {
        u8 *q = lbl_805D75EC + i * 4;
        arr[lobby_afs_toc_entry_index++] = (LE32_803CD5C4(q) + 0x7FF) / 2048;
        if (lobby_afs_toc_entry_index >= e->f8) {
            st = 3;
            TLobby__sub_803CD804();
            break;
        }
    }
    if (i >= 0x200) {
        if (ADXF_ReadNw32(lobby_adxf_open_file_handle, 1, lbl_805D75EC) < 0) {
            st = 4;
            TLobby__sub_803CD804();
        } else {
            st = lobby_adxf_open_file_handle->state;
        }
    }
    return st;
}

void TLobby__sub_803CD804(void) {
    ADXF_Close(lobby_adxf_open_file_handle);
    lobby_adxf_open_file_handle = 0;
    lobby_adxf_current_file_id = -1;
    lobby_afs_toc_entry_index = 0;
    lbl_805D75E8 = 0;
}

u8 adxf_open_file_buffer[0x2080];

// ADXF_LoadPartitionNw (named by its messages)
s32 adxf_open_file__6TLobbyFiPviPv(s32 id, const char *name, s32 mode, Ent_803CC294 *e) {
    s32 r;
    u8 *buf;
    r = adxf_chk_prm_pt(id, e);
    if (r < 0) {
        return r;
    }
    if (lobby_adxf_current_file_id >= 0) {
        TLobby::notify_error("E0042401:multi-load partition.(ADXF_LoadPartitionNw)");
        return -1;
    }
    lobby_adxf_open_file_handle = ADXF_Open(name, mode);
    if (lobby_adxf_open_file_handle == NULL) {
        TLobby::notify_error("E9040804:can't open file.(ADXF_LoaddPartitionNw)");
        return -1;
    }
    lobby_adxf_current_file_id = id;
    lobby_afs_toc_entry_index = 0;
    memset(e, 0, 0x118);
    afs_archive_toc_table[id] = e;
    e->next = NULL;
    strncpy(e->name, name, 0x100);
    e->mode = mode;
    e->fe = 0;
    buf = (u8 *)((saddr)(adxf_open_file_buffer + 0x20) & ~0x1F);
    lbl_805D75F0 = buf;
    lbl_805D75EC = buf;
    r = ADXF_ReadNw32(lobby_adxf_open_file_handle, 1, buf);
    if (r < 0) {
        ADXF_Close(lobby_adxf_open_file_handle);
        return r;
    }
    e->f8 = 0;
    return 0;
}

// ADXF_LoadPtNwEx (named by its messages) and a second loader whose messages also say ADXF_LoadPartition
// (real name unknown): removed by the linker. Only their messages are left after ADXF_LoadPartitionNw's, at
// the end of the string pool; the bodies follow ADXF_LoadPartitionNw.
s32 adxf_load_pt_nw_ex(s32 ptid, const char *fname, s32 dir, Ent_803CC294 *ptinfo, void *tmpbuf, s32 tbsize) {
    if (tmpbuf == NULL) {
        TLobby::notify_error("E1110701:'tmpbuf' is null.(ADXF_LoadPtNwEx)");
        return -3;
    }
    if (tbsize <= 0) {
        TLobby::notify_error("E1110702:'tbsize' <= 0.(ADXF_LoadPtNwEx)");
        return -3;
    }
    if (adxf_chk_prm_pt(ptid, ptinfo) < 0) {
        return -3;
    }
    if (lobby_adxf_current_file_id >= 0) {
        TLobby::notify_error("E0042401:multi-load partition.(ADXF_LoadPtNwEx)");
        return -1;
    }
    lobby_adxf_open_file_handle = ADXF_Open(fname, dir);
    if (lobby_adxf_open_file_handle == NULL) {
        TLobby::notify_error("E9040804:can't open file.(ADXF_LoadPtNwEx)");
        return -1;
    }
    return 0;
}

s32 adxf_load_partition2(s32 ptid, const char *fname, s32 dir, Ent_803CC294 *ptinfo) {
    if (adxf_chk_prm_pt(ptid, ptinfo) < 0) {
        return -3;
    }
    if (ADXF_Open(fname, dir) == NULL) {
        TLobby::notify_error("E9040804:can't open file.(ADXF_LoadPartition)");
        return -1;
    }
    if (ptinfo->f8 == 0) {
        TLobby::notify_error("E9040806:file is broken.(ADXF_LoadPartition)");
        return -1;
    }
    TLobby::notify_error("E9040805:read error.(ADXF_LoadPartition)");
    return -1;
}

}
