#include "types.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_803F339C.h"

#pragma scheduling off

#include "pso/network/NetworkInfoLoader.h"
#include "pso/network/NetworkInfoCodec.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"

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
extern u32 lobby_net_config_mode;
extern Big_803F47BC *lobby_net_config_buffer;
extern void *lobby_net_config_card_base;
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
        network_info_load_state.card_result = TAdPlayerLoadGC::take_card_mount_result(get_network_config_card_channel(), &network_info_load_state.card_detail);
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
        network_info_load_state.card_result = TAdPlayerLoadGC::take_card_open_result(get_network_config_card_channel(), &network_info_load_state.card_detail);
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
        network_info_load_state.card_result = TAdPlayerLoadGC::request_card_read((s32)network_info_load_state.file_handle, TAdPlayerLoadGC__network_config_buffer, (s32)(get_network_info_file_size()), 0);
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
        network_info_load_state.card_result = TAdPlayerLoadGC::take_card_read_result(get_network_config_card_channel(), &network_info_load_state.card_detail);
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
                            if (lobby_net_config_mode != 4) {
                                (*(s16 * *)&lobby_net_config_buffer)[1] = (*(s16 * *)&lobby_net_config_buffer)[2];
                            } else {
                                (*(s16 * *)&lobby_net_config_buffer)[1] = (*(s16 * *)&lobby_net_config_buffer)[3];
                            }
                            memcpy(network_info_trailer_buffer, TAdPlayerLoadGC__network_config_buffer->tail, 0x400);
                            if (get_network_config_backup_mode() == 1) {
                                memcpy(lobby_net_config_card_base, (*(s16 * *)&lobby_net_config_buffer), 0x19D4);
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
        network_info_load_state.card_result = TAdPlayerLoadGC::request_card_find(s->card_channel, "sega_network_information");
        if (network_info_load_state.card_result < 0) {
            TAdPlayerLoadGC::get_or_set_channel_flag(s->card_channel, 0);
            network_info_load_state.result = -209;
            s->phase = 27;
            break;
        }
        s->phase = 2;
    case 2:
        t = &network_info_load_state;
        network_info_load_state.card_result = TAdPlayerLoadGC::take_card_find_result(t->card_channel, &t->card_detail);
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
    if (lobby_net_config_mode != 4) {
        lobby_net_config_buffer->cur = lobby_net_config_buffer->x4;
    } else {
        lobby_net_config_buffer->cur = lobby_net_config_buffer->x6;
    }
    if (get_network_config_backup_mode() == 1) {
        memcpy(lobby_net_config_card_base, lobby_net_config_buffer, 0x19D4);
    }
}

// Default entry names, Shift-JIS katakana: "provider 0".."provider 5", "isao.net provider", "isao.net mail account".
char lbl_804FCEA4[] = "\x83\x76\x83\x8D\x83\x6F\x83\x43\x83\x5F\x82\x4F";
char lbl_804FCEB4[] = "\x83\x76\x83\x8D\x83\x6F\x83\x43\x83\x5F\x82\x50";
char lbl_804FCEC4[] = "\x83\x76\x83\x8D\x83\x6F\x83\x43\x83\x5F\x82\x51";
char default_player_name[] = "\x83\x76\x83\x8D\x83\x6F\x83\x43\x83\x5F\x82\x52";
char lbl_804FCEE4[] = "\x83\x76\x83\x8D\x83\x6F\x83\x43\x83\x5F\x82\x53";
char default_network_entry_name[] = "\x83\x76\x83\x8D\x83\x6F\x83\x43\x83\x5F\x82\x54";
char lbl_804FCF04[] = "isao.net\x83\x76\x83\x8D\x83\x6F\x83\x43\x83\x5F";
char lbl_804FCF18[] = "isao.net\x83\x81\x81\x5B\x83\x8B\x83\x41\x83\x4A\x83\x45\x83\x93\x83\x67";

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

s32 network_config_card_channel = 2;

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

// CRC-32 (polynomial 0xEDB88320) lookup table, defined after its user.
extern u32 crc32_table[];

#pragma push
#pragma scheduling off
#pragma peephole off
#pragma optimization_level 2

u32 fn_803F4D10(u32 crc, u8 *buf, s32 len) {
    s32 i;
    for (i = 0; i < len; i++) {
        crc = (crc >> 8) ^ crc32_table[(u8)(crc ^ buf[i])];
    }
    return crc;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
#pragma optimization_level 1
u32 calc_crc32(s32 buf, s32 len) {
    u32 r = fn_803F4D10(-1, (u8 *)buf, len);
    r ^= 0xFFFF0000;
    r ^= 0xFFFF;
    return r;
}
#pragma pop

u32 crc32_table[256] = {
    0x00000000, 0x77073096, 0xEE0E612C, 0x990951BA, 0x076DC419, 0x706AF48F, 0xE963A535, 0x9E6495A3,
    0x0EDB8832, 0x79DCB8A4, 0xE0D5E91E, 0x97D2D988, 0x09B64C2B, 0x7EB17CBD, 0xE7B82D07, 0x90BF1D91,
    0x1DB71064, 0x6AB020F2, 0xF3B97148, 0x84BE41DE, 0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7,
    0x136C9856, 0x646BA8C0, 0xFD62F97A, 0x8A65C9EC, 0x14015C4F, 0x63066CD9, 0xFA0F3D63, 0x8D080DF5,
    0x3B6E20C8, 0x4C69105E, 0xD56041E4, 0xA2677172, 0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B,
    0x35B5A8FA, 0x42B2986C, 0xDBBBC9D6, 0xACBCF940, 0x32D86CE3, 0x45DF5C75, 0xDCD60DCF, 0xABD13D59,
    0x26D930AC, 0x51DE003A, 0xC8D75180, 0xBFD06116, 0x21B4F4B5, 0x56B3C423, 0xCFBA9599, 0xB8BDA50F,
    0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924, 0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D,
    0x76DC4190, 0x01DB7106, 0x98D220BC, 0xEFD5102A, 0x71B18589, 0x06B6B51F, 0x9FBFE4A5, 0xE8B8D433,
    0x7807C9A2, 0x0F00F934, 0x9609A88E, 0xE10E9818, 0x7F6A0DBB, 0x086D3D2D, 0x91646C97, 0xE6635C01,
    0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E, 0x6C0695ED, 0x1B01A57B, 0x8208F4C1, 0xF50FC457,
    0x65B0D9C6, 0x12B7E950, 0x8BBEB8EA, 0xFCB9887C, 0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3, 0xFBD44C65,
    0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2, 0x4ADFA541, 0x3DD895D7, 0xA4D1C46D, 0xD3D6F4FB,
    0x4369E96A, 0x346ED9FC, 0xAD678846, 0xDA60B8D0, 0x44042D73, 0x33031DE5, 0xAA0A4C5F, 0xDD0D7CC9,
    0x5005713C, 0x270241AA, 0xBE0B1010, 0xC90C2086, 0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F,
    0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4, 0x59B33D17, 0x2EB40D81, 0xB7BD5C3B, 0xC0BA6CAD,
    0xEDB88320, 0x9ABFB3B6, 0x03B6E20C, 0x74B1D29A, 0xEAD54739, 0x9DD277AF, 0x04DB2615, 0x73DC1683,
    0xE3630B12, 0x94643B84, 0x0D6D6A3E, 0x7A6A5AA8, 0xE40ECF0B, 0x9309FF9D, 0x0A00AE27, 0x7D079EB1,
    0xF00F9344, 0x8708A3D2, 0x1E01F268, 0x6906C2FE, 0xF762575D, 0x806567CB, 0x196C3671, 0x6E6B06E7,
    0xFED41B76, 0x89D32BE0, 0x10DA7A5A, 0x67DD4ACC, 0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5,
    0xD6D6A3E8, 0xA1D1937E, 0x38D8C2C4, 0x4FDFF252, 0xD1BB67F1, 0xA6BC5767, 0x3FB506DD, 0x48B2364B,
    0xD80D2BDA, 0xAF0A1B4C, 0x36034AF6, 0x41047A60, 0xDF60EFC3, 0xA867DF55, 0x316E8EEF, 0x4669BE79,
    0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236, 0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F,
    0xC5BA3BBE, 0xB2BD0B28, 0x2BB45A92, 0x5CB36A04, 0xC2D7FFA7, 0xB5D0CF31, 0x2CD99E8B, 0x5BDEAE1D,
    0x9B64C2B0, 0xEC63F226, 0x756AA39C, 0x026D930A, 0x9C0906A9, 0xEB0E363F, 0x72076785, 0x05005713,
    0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0x0CB61B38, 0x92D28E9B, 0xE5D5BE0D, 0x7CDCEFB7, 0x0BDBDF21,
    0x86D3D2D4, 0xF1D4E242, 0x68DDB3F8, 0x1FDA836E, 0x81BE16CD, 0xF6B9265B, 0x6FB077E1, 0x18B74777,
    0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C, 0x8F659EFF, 0xF862AE69, 0x616BFFD3, 0x166CCF45,
    0xA00AE278, 0xD70DD2EE, 0x4E048354, 0x3903B3C2, 0xA7672661, 0xD06016F7, 0x4969474D, 0x3E6E77DB,
    0xAED16A4A, 0xD9D65ADC, 0x40DF0B66, 0x37D83BF0, 0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,
    0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6, 0xBAD03605, 0xCDD70693, 0x54DE5729, 0x23D967BF,
    0xB3667A2E, 0xC4614AB8, 0x5D681B02, 0x2A6F2B94, 0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B, 0x2D02EF8D,
};

u8 TAdPlayerLoadGC__network_info_payload_buffer[0x23C0];
NetworkInfoLoadState network_info_load_state;
u8 network_info_trailer_buffer[0x400];
u8 network_info_trailer_backup[0x404];
typedef char NetworkInfoPayloadBufferExtent[
    sizeof(TAdPlayerLoadGC__network_info_payload_buffer) == 0x23C0 ? 1 : -1];
typedef char NetworkInfoTrailerExtent[sizeof(network_info_trailer_buffer) == 0x400 ? 1 : -1];
typedef char NetworkInfoTrailerBackupExtent[sizeof(network_info_trailer_backup) == 0x404 ? 1 : -1];
