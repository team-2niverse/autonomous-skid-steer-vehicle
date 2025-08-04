/**********************************************************************************************************************
 * file Abe.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include "Abe.h"
#include "Motor.h"

#define MAX_VEL 7000
#define BRAKE_THRESHOLDA 1.2
#define BRAKE_THRESHOLDB 1.5
#define DIST_THRESHOLDA 15
#define DIST_THRESHOLDB 12

// Function Prototypes
void Abe_Check(float front_dist){
    int cnd = (Motor_Get_Dir(0)==0 && Motor_Get_Dir(1)==0);
    if (cnd==1){
        if (front_dist > 20) return;

        if (front_dist < 10) {
            Motor_Set_Brake(0, 1);
            Motor_Set_Brake(1, 1);
            Motor_Set_Left(0, 0, 1); //brake = 1;
            Motor_Set_Right(0, 0, 1); //brake = 1;
        }
        else{
            uint32 avg_vel = (Encoder_Get_V_Left() + Encoder_Get_V_Right()) / 2.0;
            if ((avg_vel < BRAKE_THRESHOLDA * MAX_VEL && front_dist < DIST_THRESHOLDA) ||
                (avg_vel < BRAKE_THRESHOLDB * MAX_VEL && front_dist < DIST_THRESHOLDB)) {
                Motor_Set_Brake(0, 1);
                Motor_Set_Brake(1, 1);
                Motor_Set_Left(0, 0, 1);
                Motor_Set_Right(0, 0, 1);
            }
        }
    }
}
