#include "PowerPC_EABI_Support/MetroTRK/trk.h"

static TRKFramingState gTRKFramingState;

void* gTRKInputPendingPtr;

static inline BOOL TRKPacketHasData(TRKBuffer* buffer) {
    if (buffer->length < 2) {
        TRKStandardACK(buffer, DSMSG_ReplyNAK, DSREPLY_PacketSizeError);
        if (gTRKFramingState.msgBufID != -1) {
            TRKReleaseBuffer(gTRKFramingState.msgBufID);
            gTRKFramingState.msgBufID = -1;
        }
        gTRKFramingState.buffer = NULL;
        gTRKFramingState.receiveState = DSRECV_Wait;
        return FALSE;
    }
    buffer->position = 0;
    buffer->length--;
    return TRUE;
}

int TRKTestForPacket(void) {
    s32 error;
    s32 readError;
    s8 byte;
    s32 bufferId;

    error = 0;
    readError = TRKReadUARTPoll(&byte);
    while (readError == 0 && error == 0) {
        if (gTRKFramingState.receiveState != DSRECV_InFrame) {
            gTRKFramingState.isEscape = FALSE;
        }
        switch (gTRKFramingState.receiveState) {
            case DSRECV_Wait:
                if (byte == 0x7E) {
                    error = TRKGetFreeBuffer(&gTRKFramingState.msgBufID, &gTRKFramingState.buffer);
                    gTRKFramingState.fcsType = 0;
                    gTRKFramingState.receiveState = DSRECV_Found;
                }
                break;
            case DSRECV_Found:
                if (byte == 0x7E) {
                    break;
                }
                gTRKFramingState.receiveState = DSRECV_InFrame;
            case DSRECV_InFrame:
                if (byte == 0x7E) {
                    if (gTRKFramingState.isEscape) {
                        TRKStandardACK(gTRKFramingState.buffer, DSMSG_ReplyNAK, DSREPLY_EscapeError);
                        if (gTRKFramingState.msgBufID != -1) {
                            TRKReleaseBuffer(gTRKFramingState.msgBufID);
                            gTRKFramingState.msgBufID = -1;
                        }
                        gTRKFramingState.buffer = NULL;
                        gTRKFramingState.receiveState = DSRECV_Wait;
                        break;
                    }
                    if (TRKPacketHasData(gTRKFramingState.buffer)) {
                        bufferId = gTRKFramingState.msgBufID;
                        gTRKFramingState.msgBufID = -1;
                        gTRKFramingState.buffer = NULL;
                        gTRKFramingState.receiveState = DSRECV_Wait;
                        return bufferId;
                    }
                    gTRKFramingState.receiveState = DSRECV_Wait;
                } else {
                    if (gTRKFramingState.isEscape) {
                        byte ^= 0x20;
                        gTRKFramingState.isEscape = FALSE;
                    } else if (byte == 0x7D) {
                        gTRKFramingState.isEscape = TRUE;
                        break;
                    }
                    error = TRKAppendBuffer1_ui8(gTRKFramingState.buffer, byte);
                    gTRKFramingState.fcsType += byte;
                }
                break;
            case DSRECV_FrameOverflow:
                if (byte == 0x7E) {
                    if (gTRKFramingState.msgBufID != -1) {
                        TRKReleaseBuffer(gTRKFramingState.msgBufID);
                        gTRKFramingState.msgBufID = -1;
                    }
                    gTRKFramingState.buffer = NULL;
                    gTRKFramingState.receiveState = DSRECV_Wait;
                }
                break;
        }
        readError = TRKReadUARTPoll(&byte);
    }
    return -1;
}

void TRKGetInput(void)
{
    TRKBuffer* msgBuffer;
    int id;
    u8 command;

    id = TRKTestForPacket();
    if (id == -1)
        return;

    msgBuffer = TRKGetBuffer(id);
    TRKSetBufferPosition(msgBuffer, 0);
    TRKReadBuffer1_ui8(msgBuffer, &command);
    if (command < DSMSG_ReplyACK) {
        TRKProcessInput(id);
    } else {
        TRKReleaseBuffer(id);
    }
}

void TRKProcessInput(int bufferIdx)
{
    TRKEvent event;

    TRKConstructEvent(&event, NUBEVENT_Request);
    gTRKFramingState.msgBufID = -1;
    event.msgBufID            = bufferIdx;
    TRKPostEvent(&event);
}

DSError TRKInitializeSerialHandler(void)
{
    gTRKFramingState.msgBufID     = -1;
    gTRKFramingState.receiveState = DSRECV_Wait;
    gTRKFramingState.isEscape     = FALSE;

    return DS_NoError;
}

DSError TRKTerminateSerialHandler(void) { return DS_NoError; }
