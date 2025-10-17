#ifndef _SOMEIP_RAW_UDP_SOMEIP_H_
#define _SOMEIP_RAW_UDP_SOMEIP_H_

#include "lwip/opt.h"
#include "lwip/debug.h"
#include "lwip/stats.h"
#include "lwip/udp.h"
#include "Led.h"
#include "Asclin.h"
#include "Configuration.h"
#include <string.h>
#include "Ifx_Lwip.h"
#include "Gpt12.h"
#include "Isr_Priority.h"
#include "Encoder.h"

#include "lwip/ip_addr.h" // ip_addr_t 타입을 위해 추가
#include "Gpt12.h"

/* Subscriber structure */
typedef struct {
    uint16 group_id; //서비스그룹id
    uint8 isSub; //구독여부
    uint8 timer; //timer event 여부
    ip_addr_t addr; //목적지 ip
    uint16 port; //목적지 port
} Subscriber;
//서비스랑 메서드의 정의는 있는데 누가(ip,port)하는지는 몰라서 SOMEIP-SD로 찾는것.
//service 설계할때 arxml에서 전체 서비스 리스트랑, 메서드 리스트 있어서 알고 있다고 가정.
typedef struct {
    uint16 service_id;
    uint16 port;
} Service; //ip는 사설 ip 제공



void SOMEIPSD_Init(void);
void SOMEIP_Init(void);
void SOMEIPSD_SendOfferService(unsigned char ip_a, unsigned char ip_b, unsigned char ip_c, unsigned char ip_d, int i);
void SOMEIPSD_SendSubEvtGrpAck(uint8* MSG_SubEvtGrpAck, unsigned char ip_a, unsigned char ip_b, unsigned char ip_c, unsigned char ip_d);

/* Functions for Event/Notification */
void SOMEIP_SendEvent(int i);
void SOMEIP_Periodic_Event_Trigger(void);
void SomeIp_Init_100ms_Interrupt(void); // 타이머 초기화 함수 선언 추가



extern volatile boolean g_100ms_event_flag; // 10ms 플래그 변수 선언 추가


#define SOMEIP_HEADER_LEN           16

//#pragma pack 2
// TTL 24비트와 Major Version 8비트를 처리하기 위한 공용체
// [Major Version 8bit] [TTL 24bit] 순서에 따라 바이트를 정의
typedef union {
    uint32_t val32;   // 32비트 값 전체 (엔디언 변환용)
    struct {
        uint8_t major_version; // 빅 엔디언에서 상위 8비트 (Offset 9)
        uint8_t ttl_msb;
        uint8_t ttl_mid;
        uint8_t ttl_lsb;       // 빅 엔디언에서 최하위 8비트 (Offset 12)
    } bytes;
} MajVerTtlUnion_t;
// 1. SOME/IP 표준 헤더 (16 바이트)
typedef struct {
    uint32_t message_id;
    uint32_t length;
    uint32_t request_id;
    uint8_t  protocol_version;
    uint8_t  interface_version;
    uint8_t  message_type;
    uint8_t  return_code;
} SomeIpHeader_t;
// 2. SD Offer Service Entry (중복 필드 제거, 16 바이트)
typedef struct {
    MajVerTtlUnion_t flags; //1B, 3B
    uint32_t length;            //4B
    uint8_t  type;             // 1B
    uint8_t  index_1;          // 1B
    uint8_t  index_2;          // 1B
    uint8_t  number_of_options; // 1B
    uint16_t service_id;       // 2B
    uint16_t instance_id;      // 2B
    // Major Version (8bit) + TTL (24bit)을 통합하는 4B 필드
    MajVerTtlUnion_t maj_ver_ttl_field; // 4B (Offset 8)
    uint32_t minor_version;    // 4B (Offset 12)
} SdOfferServiceEntry_t; // 총 4 + 4 + 16   바이트 (4+2+2+4+4+4+4)
// 3. SD Endpoint Option 구조체
typedef struct {
    uint32_t optionlength;
    uint16_t length;           // 2B: Option Data의 길이 (Type부터 Port Number까지)
    uint8_t  type;             // 1B: Option Type (e.g., IPv4 Endpoint)
    uint8_t  reserved1;        // 1B: Reserved
    uint32_t ipv4_address;     // 4B: IPv4 주소 (Network Byte Order)
    uint8_t  reserved2;        // 1B: Reserved
    uint8_t  l4_protocol;      // 1B: L4 프로토콜 (e.g., TCP 0x06)
    uint16_t port_number;      // 2B: 포트 번호 (Network Byte Order)
} SdEndpointOption_t;

typedef struct {
    SomeIpHeader_t somip_header;
    SdOfferServiceEntry_t service_entry;
    SdEndpointOption_t endoption;
} SD_Message;

//#pragma pack restore


#endif /* _SOMEIP_RAW_UDP_SOMEIP_H_ */
