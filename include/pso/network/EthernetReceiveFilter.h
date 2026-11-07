#ifndef PSO_NETWORK_ETHERNET_RECEIVE_FILTER_H
#define PSO_NETWORK_ETHERNET_RECEIVE_FILTER_H
#include "types.h"

typedef struct EthernetProtocolRegistration {
    u16 delivery_mode;
    u16 ether_type;
} EthernetProtocolRegistration;
typedef struct EthernetMulticastEntry {
    s16 references;
    u8 address[6];
} EthernetMulticastEntry;
typedef struct EthernetReceiveFilter {
    u8 local_address[6];
    EthernetMulticastEntry multicast[6];
    s16 protocol_count;
    EthernetProtocolRegistration protocols[5];
} EthernetReceiveFilter;
typedef struct EthernetFrameHeader {
    u8 destination[6];
    u8 source[6];
    u16 ether_type;
} EthernetFrameHeader;

#include <stddef.h>
typedef char EthernetProtocolsOffset[offsetof(EthernetReceiveFilter, protocols) == 0x38 ? 1 : -1];
typedef char EthernetTypeOffset[offsetof(EthernetFrameHeader, ether_type) == 0x0C ? 1 : -1];
#endif
