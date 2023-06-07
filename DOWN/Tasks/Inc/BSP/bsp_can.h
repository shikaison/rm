//
// Created by 14685 on 2022/7/15.
//

#ifndef HNU_RM_DOWN_BSP_CAN_H
#define HNU_RM_DOWN_BSP_CAN_H
#include "can.h"

# define CHASSIS_CAN hcan1
#define CAN_UP_TX_INFO 0x134

/**
 * @brief  CAN��Ϣ��ID
 */
typedef enum
{
    //����ID
    CAN_3508_M1_ID       = 0x201,
    CAN_3508_M2_ID       = 0x202,
    CAN_3508_M3_ID       = 0x203,
    CAN_3508_M4_ID       = 0x204,
    CAN_YAW_MOTOR_ID     = 0x205,//ID 1 001
    CAN_PIT_MOTOR_ID     = 0x206,//ID 2 010
    CAN_TRIGGER_MOTOR_ID = 0x207,
    CAN_SUPERCAP_RECV    = 0x211,
    //����ID
    CAN_CHASSIS_ID       = 0x200,
    CAN_SUPER_CAP_ID      = 0X210,
    CAN_GIMBAL_ID        = 0x1ff,
} CANMsgIDType;

/**
 * @brief    ��ʼ��CAN
 */
void CAN_Init();

/**
 * @brief             ͨ��CAN��������
 * @param can         CAN1��CAN2
 * @param send_id     ����ID
 * @param send_data   ���͵�����
 */
void CAN_Send(CAN_HandleTypeDef can, uint32_t send_id, uint8_t send_data[]);

/**
 * @brief          CAN���ջص�����
 * @param hcan     CAN1��CAN2
 */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);

/**
 * @brief         �����������ݽ���
 * @param data    ���յ�������
 */
void PowerDataResolve(uint8_t data[]);


extern float PowerData[4];
#endif //HNU_RM_DOWN_BSP_CAN_H
