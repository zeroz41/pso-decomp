#include "types.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_803F339C.h"
#include "pso/unk/text_803F4D10.h"

#pragma scheduling off

#include "pso/network/NetworkInfoLoader.h"
#include "pso/network/NetworkInfoCodec.h"
#include "pso/TAdPlayerLoadGC.h"

typedef struct Ent_803F47BC {
    char name[0x20];
    s16 id;
    s16 a;
    s16 b;
    s16 c;
} Ent_803F47BC;

typedef struct Id_803F47BC {
    s16 id;
    s16 a;
    s16 b;
    s16 c;
    char name[0x20];
} Id_803F47BC;

typedef struct Rec_803F47BC {
    char name[0x10E];
    s16 kind;
    u8 pad[0x210 - 0x110];
} Rec_803F47BC;

typedef struct Big_803F47BC {
    s16 f0;
    s16 cur;
    s16 x4;
    s16 x6;
    Ent_803F47BC ent[6];
    Rec_803F47BC rec[6];
    u8 padD58[0xE5C - 0xD58];
    char strE5C[0x19D4 - 0xE5C];
} Big_803F47BC;

typedef struct Save_803F3F64 {
    u8 pad0[0x5840];
    u8 data[0x23B8];
    u32 crc;
    s32 size;
    u8 tail[0x400];
} Save_803F3F64;

s32 get_or_set_network_config_mode(s32 arg0);
s32 get_or_set_network_config_backup_mode(s32 arg0);
extern NetworkInfoLoadState network_info_load_state;
extern "C" {

s32 CARDGetSerialNo(s32 chan, u64 *serialNo);
s32 CARDGetUniqueCode(s32 chan, u64 *code);
void *memset(void *, int, u32);
void *memcpy(void *, const void *, u32);
char *strcpy(char *dest, const char *src);
extern char lbl_804FCEA4[];
extern char lbl_804FCEB4[];
extern char lbl_804FCEC4[];
extern char default_player_name[];
extern char lbl_804FCEE4[];
extern char default_network_entry_name[];
extern char lbl_804FCF04[];
extern char lbl_804FCF18[];
extern u32 lbl_805D7980;
extern Big_803F47BC *lobby_net_config_buffer;
extern void *lbl_805D79E0;
void *OSAllocFromHeap(s32 heap, u32 size);
void OSFreeToHeap(s32 heap, void *p);
}
extern s32 __OSCurrHeap;

extern u8 TAdPlayerLoadGC__network_info_payload_buffer[];
extern u8 network_info_trailer_buffer[];
extern u8 network_info_trailer_backup[];
Save_803F3F64 *TAdPlayerLoadGC__network_config_buffer;
s32 network_config_mode;

#pragma scheduling off
#pragma peephole off
void update_network_info_load(void) {
    NetworkInfoLoadState *s;
    u32 crc;
    u32 sum;
    u8 key[0x10];
    s = &network_info_load_state;
    switch (s->phase) {
    case 3:
        network_info_load_state.card_result = TAdPlayerLoadGC__sub_803F3998(get_network_config_card_channel());
        if (network_info_load_state.card_result < 0) {
            network_info_load_state.result = -200;
            s->phase = 27;
            break;
        }
        s->phase = 4;
    case 4:
        network_info_load_state.card_result = TAdPlayerLoadGC::take_network_info_load_result(get_network_config_card_channel(), &network_info_load_state.card_detail);
        if (network_info_load_state.card_result < 0) {
            network_info_load_state.result = -200;
            s->phase = 27;
            break;
        }
        if (network_info_load_state.card_result == 200) {
            break;
        }
        s->phase = 7;
    case 7:
        TAdPlayerLoadGC::get_or_set_channel_flag(get_network_config_card_channel(), 1);
        network_info_load_state.file_handle = TAdPlayerLoadGC::begin_card_file_request(get_network_config_card_channel(), "sega_network_information");
        if (network_info_load_state.file_handle < 0) {
            TAdPlayerLoadGC::get_or_set_channel_flag(get_network_config_card_channel(), 0);
            network_info_load_state.card_result = network_info_load_state.file_handle;
            TAdPlayerLoadGC::unmount_card(get_network_config_card_channel());
            network_info_load_state.result = -204;
            s->phase = 27;
            break;
        }
        s->phase = 8;
    case 8:
        network_info_load_state.card_result = TAdPlayerLoadGC::finish_load_slot_state3(get_network_config_card_channel(), &network_info_load_state.card_detail);
        if (network_info_load_state.card_result < 0) {
            TAdPlayerLoadGC::get_or_set_channel_flag(get_network_config_card_channel(), 0);
            TAdPlayerLoadGC::unmount_card(get_network_config_card_channel());
            network_info_load_state.result = -204;
            s->phase = 27;
            break;
        }
        if (network_info_load_state.card_result == 200) {
            break;
        }
        TAdPlayerLoadGC::get_or_set_channel_flag(get_network_config_card_channel(), 0);
        s->phase = 9;
    case 9:
        TAdPlayerLoadGC::get_or_set_channel_flag(get_network_config_card_channel(), 1);
        if ((void *)(&network_info_load_state)[0].caller_buffer == NULL) {
            if (TAdPlayerLoadGC__network_config_buffer != NULL) {
                OSFreeToHeap(__OSCurrHeap, TAdPlayerLoadGC__network_config_buffer);
            }
            TAdPlayerLoadGC__network_config_buffer = (Save_803F3F64 *)OSAllocFromHeap(__OSCurrHeap, get_network_info_file_size());
            if (TAdPlayerLoadGC__network_config_buffer == NULL) {
                TAdPlayerLoadGC::close_card_slot(network_info_load_state.file_handle);
                TAdPlayerLoadGC::get_or_set_channel_flag(get_network_config_card_channel(), 0);
                TAdPlayerLoadGC::unmount_card(get_network_config_card_channel());
                network_info_load_state.result = -4;
                s->phase = 27;
                break;
            }
        } else {
            TAdPlayerLoadGC__network_config_buffer = (Save_803F3F64 *)network_info_load_state.caller_buffer;
        }
        network_info_load_state.card_result = TAdPlayerLoadGC::queue_network_request((s32)network_info_load_state.file_handle, (s32)TAdPlayerLoadGC__network_config_buffer, (s32)(get_network_info_file_size()), 0);
        if (network_info_load_state.card_result < 0) {
            if ((void *)(&network_info_load_state)[0].caller_buffer == NULL) {
                if (TAdPlayerLoadGC__network_config_buffer != NULL) {
                    OSFreeToHeap(__OSCurrHeap, TAdPlayerLoadGC__network_config_buffer);
                }
            } else {
                network_info_load_state.caller_buffer = 0;
            }
            TAdPlayerLoadGC__network_config_buffer = NULL;
            TAdPlayerLoadGC::close_card_slot(network_info_load_state.file_handle);
            TAdPlayerLoadGC::get_or_set_channel_flag(get_network_config_card_channel(), 0);
            TAdPlayerLoadGC::unmount_card(get_network_config_card_channel());
            network_info_load_state.result = -205;
            s->phase = 27;
            break;
        }
        s->phase = 10;
    case 10:
        network_info_load_state.card_result = TAdPlayerLoadGC::finish_load_slot_state4(get_network_config_card_channel(), &network_info_load_state.card_detail);
        if (network_info_load_state.card_result == 0) {
            if (TAdPlayerLoadGC__network_config_buffer->size <= 0 || (u32)TAdPlayerLoadGC__network_config_buffer->size > 0x23B8) {
                TAdPlayerLoadGC::close_card_slot(network_info_load_state.file_handle);
                TAdPlayerLoadGC::get_or_set_channel_flag(get_network_config_card_channel(), 0);
                TAdPlayerLoadGC::unmount_card(get_network_config_card_channel());
                network_info_load_state.result = -30;
                s->phase = 27;
            } else {
                network_info_load_state.card_result = get_network_info_card_key(get_network_config_card_channel(), key);
                if (network_info_load_state.card_result != 0) {
                    TAdPlayerLoadGC::close_card_slot(network_info_load_state.file_handle);
                    TAdPlayerLoadGC::get_or_set_channel_flag(get_network_config_card_channel(), 0);
                    TAdPlayerLoadGC::unmount_card(get_network_config_card_channel());
                    network_info_load_state.result = -31;
                    s->phase = 27;
                } else {
                    crc = TAdPlayerLoadGC__network_config_buffer->crc;
                    TAdPlayerLoadGC__network_config_buffer->crc = 0;
                    sum = calc_crc32((s32)TAdPlayerLoadGC__network_config_buffer, 0x8000);
                    if (sum != crc) {
                        init_network_config_defaults();
                        TAdPlayerLoadGC::close_card_slot(network_info_load_state.file_handle);
                        TAdPlayerLoadGC::get_or_set_channel_flag(get_network_config_card_channel(), 0);
                        TAdPlayerLoadGC::unmount_card(get_network_config_card_channel());
                        network_info_load_state.result = -32;
                        s->phase = 27;
                    } else {
                        memcpy(TAdPlayerLoadGC__network_info_payload_buffer, TAdPlayerLoadGC__network_config_buffer->data, 0x23B8);
                        memset((*(s16 * *)&lobby_net_config_buffer), 0, 0x19D4);
                        network_info_load_state.card_result = decode_network_info_payload(key, TAdPlayerLoadGC__network_info_payload_buffer, TAdPlayerLoadGC__network_config_buffer->size, ((NetworkInfoConfig *)lobby_net_config_buffer));
                        if (network_info_load_state.card_result != 0) {
                            init_network_config_defaults();
                            TAdPlayerLoadGC::close_card_slot(network_info_load_state.file_handle);
                            TAdPlayerLoadGC::get_or_set_channel_flag(get_network_config_card_channel(), 0);
                            TAdPlayerLoadGC::unmount_card(get_network_config_card_channel());
                            network_info_load_state.result = -33;
                            s->phase = 27;
                        } else {
                            if (lbl_805D7980 != 4) {
                                (*(s16 * *)&lobby_net_config_buffer)[1] = (*(s16 * *)&lobby_net_config_buffer)[2];
                            } else {
                                (*(s16 * *)&lobby_net_config_buffer)[1] = (*(s16 * *)&lobby_net_config_buffer)[3];
                            }
                            memcpy(network_info_trailer_buffer, TAdPlayerLoadGC__network_config_buffer->tail, 0x400);
                            if (get_network_config_backup_mode() == 1) {
                                memcpy(lbl_805D79E0, (*(s16 * *)&lobby_net_config_buffer), 0x19D4);
                                memcpy(network_info_trailer_backup, network_info_trailer_buffer, 0x400);
                            }
                            network_info_load_state.result = 0;
                            s->phase = 25;
                        }
                    }
                }
            }
        } else {
            if (network_info_load_state.card_result == 200) {
                break;
            }
            network_info_load_state.result = -205;
            s->phase = 27;
        }
        if ((void *)(&network_info_load_state)[0].caller_buffer == NULL) {
            if (TAdPlayerLoadGC__network_config_buffer != NULL) {
                OSFreeToHeap(__OSCurrHeap, TAdPlayerLoadGC__network_config_buffer);
            }
        } else {
            network_info_load_state.caller_buffer = 0;
        }
        TAdPlayerLoadGC__network_config_buffer = NULL;
        TAdPlayerLoadGC::close_card_slot(network_info_load_state.file_handle);
        TAdPlayerLoadGC::get_or_set_channel_flag(get_network_config_card_channel(), 0);
        TAdPlayerLoadGC::unmount_card(get_network_config_card_channel());
        break;
    }
}

#pragma push
#pragma scheduling off
s32 request_network_info_exists(s32 arg0) {
    NetworkInfoLoadState *s;
    switch (get_network_config_mode()) {
    case 0:
        return -1;
    case 1:
    case 2:
    case 3:
        break;
    default:
        return -5;
    }
    s = &network_info_load_state;
    if (s->request_kind != 0) {
        return -4;
    }
    s->request_kind = 1;
    s->phase = 1;
    s->card_channel = arg0;
    s->result = 200;
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
s32 take_network_info_exists_result(s32 *arg0, s32 *arg1) {
    NetworkInfoLoadState *s;
    s32 r;
    s32 res;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    s = &network_info_load_state;
    if (s->request_kind == 1) {
        *arg0 = s->card_result;
        *arg1 = s->card_detail;
        res = s->result;
        r = res;
        if (res != 200) {
            s->request_kind = 0;
            s->phase = 0;
        }
    } else {
        *arg0 = 0;
        *arg1 = 0;
        r = -4;
    }
    return r;
}
#pragma pop

#pragma push
#pragma scheduling off
void update_network_info_exists(void) {
    NetworkInfoLoadState *s;
    NetworkInfoLoadState *t;
    s = &network_info_load_state;
    switch (s->phase) {
    case 1:
        TAdPlayerLoadGC::get_or_set_channel_flag(s->card_channel, 1);
        network_info_load_state.card_result = TAdPlayerLoadGC::request_card_open(s->card_channel, "sega_network_information");
        if (network_info_load_state.card_result < 0) {
            TAdPlayerLoadGC::get_or_set_channel_flag(s->card_channel, 0);
            network_info_load_state.result = -209;
            s->phase = 27;
            break;
        }
        s->phase = 2;
    case 2:
        t = &network_info_load_state;
        network_info_load_state.card_result = TAdPlayerLoadGC::take_network_info_poll_result(t->card_channel, &t->card_detail);
        switch (network_info_load_state.card_result) {
        case 0:
        case -102:
            TAdPlayerLoadGC::get_or_set_channel_flag(t->card_channel, 0);
            network_info_load_state.result = 0;
            s->phase = 25;
            break;
        case 200:
            break;
        default:
            TAdPlayerLoadGC::get_or_set_channel_flag(t->card_channel, 0);
            network_info_load_state.result = -209;
            s->phase = 27;
            break;
        }
        break;
    }
}
#pragma pop

#pragma scheduling off
#pragma optimization_level 2
void init_network_config_defaults(void) {
    s16 i;
    memset(lobby_net_config_buffer, 0, 0x19D4);
    lobby_net_config_buffer->cur = -1;
    for (i = 0; i < 6; i++) {
        lobby_net_config_buffer->ent[i].id = i;
        lobby_net_config_buffer->ent[i].a = -1;
        lobby_net_config_buffer->ent[i].b = -1;
        lobby_net_config_buffer->ent[i].c = -1;
        switch (i) {
        case 0:
            strcpy(lobby_net_config_buffer->ent[i].name, lbl_804FCEA4);
            strcpy(lobby_net_config_buffer->rec[i].name, lbl_804FCEA4);
            break;
        case 1:
            strcpy(lobby_net_config_buffer->ent[i].name, lbl_804FCEB4);
            strcpy(lobby_net_config_buffer->rec[i].name, lbl_804FCEB4);
            break;
        case 2:
            strcpy(lobby_net_config_buffer->ent[i].name, lbl_804FCEC4);
            strcpy(lobby_net_config_buffer->rec[i].name, lbl_804FCEC4);
            break;
        case 3:
            strcpy(lobby_net_config_buffer->ent[i].name, default_player_name);
            strcpy(lobby_net_config_buffer->rec[i].name, default_player_name);
            break;
        case 4:
            strcpy(lobby_net_config_buffer->ent[i].name, lbl_804FCEE4);
            strcpy(lobby_net_config_buffer->rec[i].name, lbl_804FCEE4);
            break;
        case 5:
            strcpy(lobby_net_config_buffer->ent[i].name, default_network_entry_name);
            strcpy(lobby_net_config_buffer->rec[i].name, default_network_entry_name);
            break;
        }
    }
    lobby_net_config_buffer->ent[0].id = 0;
    lobby_net_config_buffer->ent[0].a = 0;
    strcpy(lobby_net_config_buffer->ent[0].name, lbl_804FCF04);
    strcpy(lobby_net_config_buffer->rec[0].name, lbl_804FCF04);
    strcpy(lobby_net_config_buffer->strE5C, lbl_804FCF18);
    lobby_net_config_buffer->rec[0].kind = 1;
    lobby_net_config_buffer->rec[1].kind = 1;
    lobby_net_config_buffer->rec[2].kind = 1;
    lobby_net_config_buffer->rec[3].kind = 1;
    lobby_net_config_buffer->rec[4].kind = 4;
    lobby_net_config_buffer->rec[5].kind = 4;
    lobby_net_config_buffer->x4 = 1;
    lobby_net_config_buffer->x6 = 4;
    if (lbl_805D7980 != 4) {
        lobby_net_config_buffer->cur = lobby_net_config_buffer->x4;
    } else {
        lobby_net_config_buffer->cur = lobby_net_config_buffer->x6;
    }
    if (get_network_config_backup_mode() == 1) {
        memcpy(lbl_805D79E0, lobby_net_config_buffer, 0x19D4);
    }
}

s32 get_network_config_mode(void) { return get_or_set_network_config_mode(4); }

s32 get_or_set_network_config_mode(s32 arg0) {
    if (arg0 < 4) {
        network_config_mode = arg0;
    }
    return network_config_mode;
}

s32 TAdPlayerLoadGC__player_load_value;

s32 get_network_config_backup_mode(void) { return get_or_set_network_config_backup_mode(2); }

s32 get_or_set_network_config_backup_mode(s32 arg0) {
    if (arg0 < 2) {
        TAdPlayerLoadGC__player_load_value = arg0;
    }
    return TAdPlayerLoadGC__player_load_value;
}

extern s32 network_config_card_channel;

s32 get_network_config_card_channel(void) {
    return network_config_card_channel;
}

void set_network_config_card_channel(s32 arg0) {
    if (get_network_config_mode() >= 1) {
        network_config_card_channel = arg0;
        init_network_config_defaults();
    }
}

#pragma push
#pragma scheduling off
s32 get_network_config_buffer_size(s32 mode) {
    s32 n = 0x19D4;
    if (mode == 1) {
        n <<= 1;
    }
    return n;
}
#pragma pop

s32 get_network_info_file_size(void) {
    return 0x8000;
}
#pragma push
#pragma scheduling off
s32 get_network_info_card_key(int chan, u8 *out) {
  u64 serial;
  u64 code;
  s32 rc;
  rc = CARDGetSerialNo(chan, &serial);
  if (rc != 0)
  {
    return rc;
  }
  rc = CARDGetUniqueCode(chan, &code);
  if (rc != 0)
  {
    return rc;
  }
  out[0] = serial & 0xFF;
  out[1] = (serial >> 8) & 0xFF;
  out[2] = (serial >> 16) & 0xFF;
  out[3] = (serial >> 24) & 0xFF;
  out[4] = (serial >> 32) & 0xFF;
  out[5] = (serial >> 40) & 0xFF;
  out[6] = (serial >> 48) & 0xFF;
  out[7] = (serial >> 56) & 0xFF;
  out[8] = code & 0xFF;
  out[9] = (code >> 8) & 0xFF;
  out[10] = (code >> 16) & 0xFF;
  out[11] = (code >> 24) & 0xFF;
  out[12] = (code >> 32) & 0xFF;
  out[13] = (code >> 40) & 0xFF;
  out[14] = (code >> 48) & 0xFF;
  out[15] = (code >> 56) & 0xFF;
  return rc;
}
#pragma pop

u8 TAdPlayerLoadGC__network_info_payload_buffer[0x23C0];
NetworkInfoLoadState network_info_load_state;
u8 network_info_trailer_buffer[0x400];
u8 network_info_trailer_backup[0x404];
typedef char NetworkInfoPayloadBufferExtent[
    sizeof(TAdPlayerLoadGC__network_info_payload_buffer) == 0x23C0 ? 1 : -1];
typedef char NetworkInfoTrailerExtent[sizeof(network_info_trailer_buffer) == 0x400 ? 1 : -1];
typedef char NetworkInfoTrailerBackupExtent[sizeof(network_info_trailer_backup) == 0x404 ? 1 : -1];
