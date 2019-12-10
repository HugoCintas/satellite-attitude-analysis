/*
 * complementary_filter.c
 *
 *  Created on: 26 nov. 2019
 *      Author: simu04
 */

#include "complementary_filter.h"

angle_format complementary_filter(data_format data_i, angle_format angles_i_1)
{
    angle_format angles;
    data_format data;
    float A, dt;
    float RAD_to_DEG;

    A = 0.98;
    dt = 1/10;
    RAD_to_DEG = 360/(2*3.14159);

    data.acc_x = atan2(data_i.acc_y,sqrt(data_i.acc_x*data_i.acc_x+data_i.acc_z*data_i.acc_z))*RAD_to_DEG;
    data.acc_y = atan2(-1*data_i.acc_x,sqrt(data_i.acc_y*data_i.acc_y+data_i.acc_z*data_i.acc_z))*RAD_to_DEG;
    data.acc_z = data_i.acc_z;
    data.gyr_x = data_i.gyr_x;
    data.gyr_y = data_i.gyr_y;
    data.gyr_z = data_i.gyr_z;
    data.mag_x = data_i.mag_x;
    data.mag_y = data_i.mag_y;
    data.mag_z = data_i.mag_z;

    angles.theta_x = A * (angles_i_1.theta_x + data.gyr_x*dt) + (1-A)*data.acc_x;
    angles.theta_y = A * (angles_i_1.theta_y + data.gyr_y*dt) + (1-A)*data.acc_y;
    angles.theta_z= angles_i_1.theta_z;

    return angles;
}


