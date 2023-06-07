//
// Created by turboDog on 2021/11/16.
//

#ifndef BOARD_C_INFANTRY_BSP_UART_H
#define BOARD_C_INFANTRY_BSP_UART_H
#include "sys.h"
#include "Gimbal.h"

#define SBUS_RX_BUF_NUM 36u


/**
  * @brief     �������ң�������ݽṹ��
  */
typedef struct
{
    /* ң������ͨ�����ݣ���ֵ��Χ��-660 ~ 660 */
    int16_t ch1;   //�Ҳ�����
    int16_t ch2;   //�Ҳ�����
    int16_t ch3;   //�������
    int16_t ch4;   //�������

    /* ң�����Ĳ������ݣ������·ֱ�Ϊ��1��3��2 */
    uint8_t sw1;   //��ದ��
    uint8_t sw2;   //�Ҳದ��

    /* PC ������� */
    struct
    {
        /* ����ƶ���� */
        int16_t x;   //���ƽ��
        int16_t y;   //�������
        /* ��갴����أ�1Ϊ���£�0Ϊ�ɿ� */
        uint8_t l;   //��ఴ��
        uint8_t r;   //�Ҳఴ��
    }mouse;

    /* PC ���̰������� */
    union
    {
        uint16_t key_code;
        struct
        {
            uint16_t W:1;
            uint16_t S:1;
            uint16_t A:1;
            uint16_t D:1;
            uint16_t SHIFT:1;
            uint16_t CTRL:1;
            uint16_t Q:1;
            uint16_t E:1;
            uint16_t R:1;
            uint16_t F:1;
            uint16_t G:1;
            uint16_t Z:1;
            uint16_t X:1;
            uint16_t C:1;
            uint16_t V:1;
            uint16_t B:1;
        }bit;
    }kb;

    /* ң������ದ������ */
    int16_t wheel;
}RcTypeDef;
/**
  * @brief     ң������������ö��
  */
enum
{
    RC_UP = 1,
    RC_MI = 3,
    RC_DN = 2,
};

/**
  * @brief          remote control init
  * @param[in]      none
  * @retval         none
  */
extern void remote_control_init(void);

/**
  * @brief          ң������ʼ��
  * @param[in]      none
  * @retval         none
  */
extern void RC_init(uint8_t *rx1_buf, uint8_t *rx2_buf, uint16_t dma_buf_num);


/**
  * @brief     ����ң��������
  * @param     rc: �������ң�������ݽṹ��ָ��
  * @param     buff: ���ڽ��յ���ң����ԭʼ����ָ��
  */
static void remote_data_handle(RcTypeDef *rc, uint8_t *buff);
/**
  * @brief     ����ң�������ݸ��ϰ�
  * @param     _hcan: ��Ҫ���͵�can
  * @param     rc_data: ���ڽ��յ���ң����ԭʼ����ָ��
  */
void Send_RC_Data(CAN_HandleTypeDef *_hcan, uint8_t *rc_data);

/**
  * @brief     ���� UART ����
  * @param     uart_id: UART ID
  * @param     send_data: ��������ָ��
  * @param     size: �������ݵĳ���
  */
void write_uart(uint8_t uart_id, uint8_t *send_data, uint16_t size);

/* �������ң�������� */
extern RcTypeDef  rc;
extern uint8_t sbus_rx_buf[2][SBUS_RX_BUF_NUM];
extern uint8_t   bluetooth_recv[];
extern uint8_t   nuc_recv[];
extern uint8_t	 referee_recv[];
#endif //BOARD_C_INFANTRY_BSP_UART_H
