#include "pso/network/TProtocol.h"
#include "pso/network/TProtocol_801DA140.h"

extern "C" void bswap__17TSendDownloadHeadFv(TSendDownloadHead *);

void fn_801DA140(TProtocol *self, s8 flags, const char *filename) {
    TSendDownloadHead pkt;
    memset(&pkt, 0, sizeof(pkt));
    pkt.header.command = 0xD7;
    pkt.header.flags = flags;
    strncpy(pkt.filename, filename, sizeof(pkt.filename));
    pkt.header.size = sizeof(pkt);
    strncpy(pkt.filename, filename, sizeof(pkt.filename));
    bswap__17TSendDownloadHeadFv(&pkt);
    self->send((u8 *)&pkt, sizeof(pkt));
}

void TProtocol::send_message_box_closed() {
    packet_header header;
    header.command = 0xD6;
    header.flags = 0;
    header.size = sizeof(header);
    header.bswap();
    send((u8*)&header, sizeof(header));
}
