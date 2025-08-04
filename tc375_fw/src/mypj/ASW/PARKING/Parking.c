/**********************************************************************************************************************
 * file Parking.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include "Parking.h"

static int state = 0;
static float space_detect_threshold = 15.0;
static float rear_stop_threshold = 10.0;

static uint64 start_time = 0;
static uint64 end_time = 0;
static uint64 space_duration_us = 0;
static int measuring_space = 0;

void Parking_On()
{

}
