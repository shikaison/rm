//
// Created by 14685 on 2022/7/16.
//

#include "Transmission.h"
#include "Chassis.h"
#include "bsp_can.h"
#include "cmsis_os.h"
#include "bsp_uart.h"
#include "Referee_system.h"


void Transmission_Task(void const * argument){
    while (1){
        Chassis_Send_supercap();
        Chassis_Send_shoot();
        osDelay(100);
    }
}

void Chassis_Send_supercap(void)
{
    uint16_t temPower =(robot_status.chassis_power_limit)*100;//�����趨����0.01W����ΧΪ3000-13000��30W-130W��
//    uint16_t temPower =5000;//�����趨����0.01W����ΧΪ3000-13000��30W-130W��
    uint8_t sendbuf[8];//���͵���������
    sendbuf[0]=temPower >> 8;
    sendbuf[1]=temPower;
    CAN_Send(hcan1, CAN_SUPER_CAP_ID, sendbuf);

}

void Chassis_Send_shoot(void) //���Ͳ���ϵͳ��SHOOT�Ĺ������
{
    uint8_t sendbuf[8];//���͵���������
    sendbuf[0]=robot_status.mains_power_shooter_output;
    CAN_Send(hcan2,0x134, sendbuf);

}