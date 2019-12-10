/*
 * complementary_filter.h
 *
 *  Created on: 26 nov. 2019
 *      Author: simu04
 */

#ifndef FILTER_COMPLEMENTARY_FILTER_H_
#define FILTER_COMPLEMENTARY_FILTER_H_

typedef struct data_format data_format;
struct data_format
{
    float acc_x;
    float acc_y;
    float acc_z;
    float gyr_x;
    float gyr_y;
    float gyr_z;
    float mag_x;
    float mag_y;
    float mag_z;
};

typedef struct angle_format angle_format;
struct angle_format
{
    float theta_x;
    float theta_y;
    float theta_z;
};

angle_format complementary_filter(data_format data_i, angle_format angles_i_1);

#endif /* FILTER_COMPLEMENTARY_FILTER_H_ */
