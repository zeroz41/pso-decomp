#ifndef PSO_UI_TMENULIST_H
#define PSO_UI_TMENULIST_H

#include "pso/forward.h"
#include "pso/network/protocol/protocol.h"
#include "pso/macros.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "types.h"

#define TMenuListEntry(name, members) \
class name { \
public: \
    void bswap() { \
        tag.bswap(); \
    }; \
public: \
    TPlyGuildCardTag tag; \
    members \
} __packed__

template <typename T, int num_entries, int num_pad_entries>
class TMenuList {
public:
    void bswap() {
        header.bswap();
        if (num_pad_entries) {
            for (int i = 0; i < num_pad_entries; i++) {
                pad_entries[i].bswap();
            }
        }
        if (num_entries) {
            for (int i = 0; i < num_entries; i++) {
                entries[i].bswap();
            }
        }
    };
public:
    packet_header header;
    T pad_entries[num_pad_entries];
    T entries[num_entries];
} __packed__;

template <typename T, int num_entries>
class TMenuList<T, num_entries, 0> {
public:
    void bswap() {
        header.bswap();
        for (int i = 0; i < num_entries; i++) {
            entries[i].bswap();
        }
    };
public:
    packet_header header;
    T entries[num_entries];
} __packed__;

template <typename T, int num_pad_entries>
class TMenuList<T, 0, num_pad_entries> {
public:
    void bswap() {
        header.bswap();
        for (int i = 0; i < num_pad_entries; i++) {
            pad_entries[i].bswap();
        }
    };
public:
    packet_header header;
    T pad_entries[num_pad_entries];
} __packed__;

#endif
