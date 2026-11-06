#include "types.h"
#include "pso/item/item_param.h"
#include "pso/player/TObjPlayer.h"

extern "C" void* item_pmt_tbl;

struct PmtSub {
    s32   count;
    char* records;
};

extern "C" {

void*TObjPlayer::get_pmt_record(int i) {
    PmtSub* c = *(PmtSub**)((char*)item_pmt_tbl + 0x10);
    if (i < c->count) {
        return &c->records[i * 24];
    }
    return &c->records[c->count * 24];
}

void*TObjPlayer::get_item_pmt_record(int type, int id) {
    if (type > 0) {
        char* cat = *(char**)((char*)item_pmt_tbl + 0x00);
        if (type < 170) {
            PmtSub* s = (PmtSub*)(cat + type * 8);
            if (id < s->count) {
                return &s->records[id * 40];
            }
        }
        return *(void**)(cat + 1364);
    }
    return NULL;
}

void*TObjPlayer::get_pmt_record_by_type_id(int type, int id) {
    char* cat = *(char**)((char*)item_pmt_tbl + 0x0C);
    if (type < 24) {
        PmtSub* s = (PmtSub*)(cat + type * 8);
        if (id < s->count) {
            return &s->records[id * 20];
        }
    }
    return *(void**)(cat + 196);
}

void*TObjPlayer::get_pmt_record_by_index(int i) {
    PmtSub* c = *(PmtSub**)((char*)item_pmt_tbl + 0x08);
    if (i < c->count) {
        return &c->records[i * 0x10];
    }
    return &c->records[c->count * 0x10];
}

void* get_armor_pmt_record(int type, int id) {
    if (type > 0 && type < 3) {
        PmtSub* s = (PmtSub*)(*(char**)((char*)item_pmt_tbl + 0x04) + (type - 1) * 8);
        if (id < s->count) {
            return &s->records[id * 28];
        }
        return &s->records[s->count * 28];
    }
    return NULL;
}
}

void* get_photon_color_record(int i) {
    if (i < 32) {
        return *(char**)((char*)item_pmt_tbl + 0x18) + i * 36;
    }
    return NULL;
}
