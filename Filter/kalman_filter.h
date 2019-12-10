/*
 * kalman_filter.h
 *
 *  Created on: 3 déc. 2019
 *      Author: simu04
 */

#ifndef FILTER_KALMAN_FILTER_H_
#define FILTER_KALMAN_FILTER_H_

typedef struct matrice_2_1 matrice_2_1;
struct matrice_2_1{
    float x11;
    float x21;
};

typedef struct matrice_2_2 matrice_2_2;
struct matrice_2_2{
    float x11;
    float x12;
    float x21;
    float x22;
};

typedef struct matrice_2_3 matrice_2_3;
struct matrice_2_3{
    float x11;
    float x12;
    float x13;
    float x21;
    float x22;
    float x23;
};

typedef struct matrice_3_1 matrice_3_1;
struct matrice_3_1{
    float x11;
    float x21;
    float x31;
};

typedef struct matrice_3_2 matrice_3_2;
struct matrice_3_2{
    float x11;
    float x12;
    float x21;
    float x22;
    float x31;
    float x32;
};

typedef struct matrice_3_3 matrice_3_3;
struct matrice_3_3{
    float x11;
    float x12;
    float x13;
    float x21;
    float x22;
    float x23;
    float x31;
    float x32;
    float x33;
};

matrice_2_1 soustraction_21(matrice_2_1 mat1, matrice_2_1 mat2);
matrice_2_1 multiply_23_31(matrice_2_3 mat1, matrice_3_1 mat2);
matrice_2_2 addition_22(matrice_2_2 mat1, matrice_2_2 mat2);
matrice_2_2 addition_23_32(matrice_2_3 mat1, matrice_3_2 mat2);
matrice_2_2 multiply_23_32(matrice_2_3 mat1, matrice_3_2 mat2);
matrice_3_1 addition_31(matrice_3_1 mat1, matrice_3_1 mat2);
matrice_3_1 multiply_32_21(matrice_3_2 mat1, matrice_2_1 mat2);
matrice_3_1 multiply_33_31(matrice_3_3 mat1, matrice_3_1 mat2);
matrice_3_2 multiply_32_22(matrice_3_2 mat1, matrice_2_2 mat2);
matrice_3_2 multiply_33_32(matrice_3_3 mat1, matrice_3_2 mat2);
matrice_3_3 addition_33(matrice_3_3 mat1, matrice_3_3 mat2);
matrice_3_3 multiply_33(matrice_3_3 mat1, matrice_3_3 mat2);
matrice_3_3 multiply_32_23(matrice_3_2 mat1, matrice_2_3 mat2);
matrice_3_2 transpose_23(matrice_2_3 mat_in);
matrice_3_3 transpose_33(matrice_3_3 mat_in);
matrice_2_2 inverse_22(matrice_2_2 mat_in);

matrice_3_2 K_calc(matrice_2_2 R, matrice_3_3 Pk_plus, matrice_2_3 H);
matrice_3_3 Xk_calc(matrice_3_3 Xk_plus, matrice_3_3 Kk, matrice_3_3 Zk, matrice_3_3 H);
matrice_3_3 Pk_calc(matrice_3_3 Kk, matrice_3_3 H, matrice_3_3 Pk_plus);
matrice_3_3 Xk_plus_calc(matrice_3_3 A, matrice_3_3 Xk);
matrice_3_3 Pk_plus_calc(matrice_3_3 A, matrice_3_3 Pk, matrice_3_3 Q);

#endif /* FILTER_KALMAN_FILTER_H_ */
