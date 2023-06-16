#include <stdio.h>
#include <stdint.h>

#define MAX_PACKET_DATA_LENGTH (50)

typedef struct data_packet_t {
    uint8_t id;
    uint8_t data_length;
    uint8_t data[MAX_PACKET_DATA_LENGTH];
    uint16_t crc;
} data_packet_t;

// CRC calculation function
uint16_t calculateCRC(const data_packet_t* packet) {
    uint16_t crc = 0;
    uint8_t* ptr = (uint8_t*)packet;
    int i;

    for (i = 0; i < sizeof(data_packet_t) - sizeof(uint16_t); i++) {
        crc ^= (uint16_t)(*ptr++) << 8;
        int j;
        for (j = 0; j < 8; j++) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ 0x1021;
            } else {
                crc = crc << 1;
            }
        }
    }

    return crc;
}

// Method to verify if the data packet is corrupted
int isPacketCorrupted(const data_packet_t* packet) {
    uint16_t calculatedCRC = calculateCRC(packet);
    return (calculatedCRC != packet->crc);
}

int main() {
    data_packet_t packet;
    packet.id = 1;
    packet.data_length = 4;
    packet.data[0] = 10;
    packet.data[1] = 20;
    packet.data[2] = 30;
    packet.data[3] = 40;
    packet.crc = calculateCRC(&packet);

    // Simulating corruption
    packet.data[1] = 25;

    if (isPacketCorrupted(&packet)) {
        printf("Data packet is corrupted.\n");
    } else {
        printf("Data packet is not corrupted.\n");
    }

    return 0;
}