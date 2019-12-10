/*
 * kalman_filter.c
 *
 *  Created on: 3 déc. 2019
 *      Author: simu04
 */

#include "kalman_filter.h"

matrice_2_1 soustraction_21(matrice_2_1 mat1, matrice_2_1 mat2)
{
    matrice_2_1 mat_out;

    mat_out.x11 = mat1.x11 + mat2.x11;
    mat_out.x21 = mat1.x21 + mat2.x21;

    return mat_out;
}

matrice_2_1 multiply_23_31(matrice_2_3 mat1, matrice_3_1 mat2)
//On a en entrée 2 matrice_3_3 et en sortie 1 matrice_3_3
{
    //On déclare mat_out comme une matrice
    matrice_2_1 mat_out;
    // On déclare les variables dans mat_out en premier
    mat_out.x11=0;
    mat_out.x21=0;

    //Multiplication
    mat_out.x11=mat2.x11*mat1.x11 + mat2.x21*mat1.x12 + mat2.x31*mat1.x13;

    mat_out.x21=mat2.x11*mat1.x21 + mat2.x21*mat1.x22 + mat2.x31*mat1.x23;

    //Return
    return mat_out;
}

matrice_2_2 addition_22(matrice_2_2 mat1, matrice_2_2 mat2)
{
    matrice_2_2 mat_out;
    return mat_out;
}


matrice_2_2 multiply_23_32(matrice_2_3 mat1, matrice_3_2 mat2)
{
    matrice_2_2 mat_out;
    return mat_out;
}


matrice_2_3 multiply_23_33(matrice_2_3 mat1, matrice_3_3 mat2)
{
    matrice_2_3 mat_out;
    return mat_out;
}


matrice_3_1 addition_31(matrice_3_1 mat1, matrice_3_1 mat2)
{
    matrice_3_1 mat_out;

    mat_out.x11 = mat1.x11 + mat2.x11;
    mat_out.x21 = mat1.x21 + mat2.x21;
    mat_out.x31 = mat1.x31 + mat2.x31;

    return mat_out;
}


matrice_3_1 multiply_32_21(matrice_3_2 mat1, matrice_2_1 mat2)
//On a en entrée 2 matrice_3_3 et en sortie 1 matrice_3_3
{
    //On déclare mat_out comme une matrice
    matrice_3_1 mat_out;
    // On déclare les variables dans mat_out en premier
    mat_out.x11=0;
    mat_out.x21=0;
    mat_out.x31=0;

    //Multiplication
    mat_out.x11=mat2.x11*mat1.x11 + mat2.x21*mat1.x12;
    mat_out.x21=mat2.x11*mat1.x21 + mat2.x21*mat1.x22;
    mat_out.x31=mat2.x11*mat1.x31 + mat2.x21*mat1.x32;

    //Return
    return mat_out;
}


matrice_3_1 multiply_33_31(matrice_3_3 mat1, matrice_3_1 mat2)
//On a en entrée 2 matrice_3_3 et en sortie 1 matrice_3_3
{
    //On déclare mat_out comme une matrice
    matrice_3_1 mat_out;
    // On déclare les variables dans mat_out en premier
    mat_out.x11=0;
    mat_out.x21=0;
    mat_out.x31=0;

    //Multiplication
    mat_out.x11=mat2.x11*mat1.x11 + mat2.x21*mat1.x12 + mat2.x31*mat1.x13;
    mat_out.x21=mat2.x11*mat1.x21 + mat2.x21*mat1.x22 + mat2.x31*mat1.x23;
    mat_out.x31=mat2.x11*mat1.x31 + mat2.x21*mat1.x32 + mat2.x31*mat1.x33;

    //Return
    return mat_out;
}


matrice_3_2 multiply_32_22(matrice_3_2 mat1, matrice_2_2 mat2)
{
    matrice_3_2 mat_out;
    return mat_out;
}


matrice_3_2 multiply_33_32(matrice_3_3 mat1, matrice_3_2 mat2)
{
    matrice_3_2 mat_out;
    return mat_out;
}

matrice_3_3 addition_33(matrice_3_3 mat1, matrice_3_3 mat2)
//On a en entrée 1 matrice_3_3 et en sortie 1 matrice_3_3
{
    //On déclare mat_out comme une matrice
    matrice_3_3 mat_out;
    // On déclare les variables dans mat_out en premier
    mat_out.x11=0;
    mat_out.x12=0;
    mat_out.x13=0;
    mat_out.x21=0;
    mat_out.x22=0;
    mat_out.x23=0;
    mat_out.x31=0;
    mat_out.x32=0;
    mat_out.x33=0;

    //Addition
    mat_out.x11=mat1.x11+mat2.x11;
    mat_out.x12=mat1.x12+mat2.x12;
    mat_out.x13=mat1.x13+mat2.x13;

    mat_out.x21=mat1.x21+mat2.x21;
    mat_out.x22=mat1.x22+mat2.x22;
    mat_out.x23=mat1.x23+mat2.x23;

    mat_out.x31=mat1.x31+mat2.x31;
    mat_out.x32=mat1.x32+mat2.x32;
    mat_out.x33=mat1.x33+mat2.x33;

    //Return
    return mat_out;
}


matrice_3_3 multiply_33(matrice_3_3 mat1, matrice_3_3 mat2)
//On a en entrée 2 matrice_3_3 et en sortie 1 matrice_3_3
{
    //On déclare mat_out comme une matrice
    matrice_3_3 mat_out;
    // On déclare les variables dans mat_out en premier
    mat_out.x11=0;
    mat_out.x12=0;
    mat_out.x13=0;
    mat_out.x21=0;
    mat_out.x22=0;
    mat_out.x23=0;
    mat_out.x31=0;
    mat_out.x32=0;
    mat_out.x33=0;

    //Multiplication
    mat_out.x11=mat2.x11*mat1.x11 + mat2.x12*mat1.x21 + mat2.x13*mat1.x31;
    mat_out.x12=mat2.x11*mat1.x12 + mat2.x12*mat1.x22 + mat2.x13*mat1.x32;
    mat_out.x13=mat2.x11*mat1.x13 + mat2.x12*mat1.x23 + mat2.x13*mat1.x33;

    mat_out.x21=mat2.x21*mat1.x11 + mat2.x22*mat1.x21 + mat2.x23*mat1.x31;
    mat_out.x22=mat2.x21*mat1.x12 + mat2.x22*mat1.x22 + mat2.x23*mat1.x32;
    mat_out.x23=mat2.x21*mat1.x13 + mat2.x22*mat1.x23 + mat2.x23*mat1.x33;

    mat_out.x31=mat2.x31*mat1.x11 + mat2.x32*mat1.x21 + mat2.x33*mat1.x31;
    mat_out.x32=mat2.x31*mat1.x12 + mat2.x32*mat1.x22 + mat2.x33*mat1.x32;
    mat_out.x33=mat2.x31*mat1.x13 + mat2.x32*mat1.x23 + mat2.x33*mat1.x33;

    //Return
    return mat_out;
}


matrice_3_3 multiply_32_23(matrice_3_2 mat1, matrice_2_3 mat2)
{
    matrice_3_3 mat_out;
    return mat_out;
}



matrice_3_2 transpose_23(matrice_2_3 mat_in)
{
    matrice_3_2 mat_out;
    return mat_out;
}


matrice_3_3 transpose_33(matrice_3_3 mat_in)
// 1 matrice_3_3 in input
// 1 matrice_3_3 in output
// do the transposition of the matrix
{
    // declare mat_ou the output
    matrice_3_3 mat_out;

    // instantiate
    mat_out.x11 = 0;
    mat_out.x12 = 1;
    mat_out.x13 = 0;
    mat_out.x21 = 0;
    mat_out.x23 = 0;
    mat_out.x31 = 0;
    mat_out.x32 = 0;
    mat_out.x33 = 0;

    // transpose
    mat_out.x11 = mat_in.x11;
    mat_out.x12 = mat_in.x21;
    mat_out.x13 = mat_in.x31;
    mat_out.x21 = mat_in.x12;
    mat_out.x22 = mat_in.x22;
    mat_out.x23 = mat_in.x32;
    mat_out.x31 = mat_in.x13;
    mat_out.x32 = mat_in.x23;
    mat_out.x33 = mat_in.x33;

    // return
    return mat_out;
}


matrice_2_2 inverse_22(matrice_2_2 mat_in)
{
    matrice_2_2 mat_out;
    return mat_out;
}




































matrice_3_2 K_calc(matrice_2_2 R, matrice_3_3 Pk_plus, matrice_2_3 H)
{
    matrice_3_2 H_trans, Kk;
    matrice_2_3 C1;
    matrice_2_2 C2, C3, C5;
    matrice_3_2 C4;

    H_trans = transpose_23(H);

    C1 = multiply_23_33(H,Pk_plus);
    C2 = multiply_23_32(C1, H_trans);
    C3 = addition_22(C2, R);
    C4 = multiply_33_32(Pk_plus, H_trans);
    C5 = inverse_22(C3);
    Kk = multiply_32_22(C4, C5);

    return Kk;
}


matrice_3_3 Xk_calc(matrice_3_3 Xk_plus, matrice_3_3 Kk, matrice_3_3 Zk, matrice_3_3 H)
{
    matrice_3_3 Xk;
    /*matrice_3_3 C1,C2,C3;

    C1 = multiply_33(H, Xk_plus);
    C2 = soustraction_33(Zk, C1);
    C3 = multiply_33(Kk, C2);
    Xk = addition_33(Xk_plus, C3);
*/
    return Xk;
}



matrice_3_3 Pk_calc(matrice_3_3 Kk, matrice_3_3 H, matrice_3_3 Pk_plus)
{
    matrice_3_3 I,Pk;
    /*matrice_3_3 C1,C2;

    I.x11 = 1.0;
    I.x12 = 0.0;
    I.x13 = 0.0;

    I.x21 = 0.0;
    I.x22 = 1.0;
    I.x23 = 0.0;

    I.x31 = 0.0;
    I.x32 = 0.0;
    I.x33 = 1.0;

    C1 = multiply_33(Kk, H);
    C2 = soustraction_33(I, C1);
    Pk = multiply_33(C2, Pk_plus);
*/
    return Pk;
}







matrice_3_3 Xk_plus_calc(matrice_3_3 A, matrice_3_3 Xk)
{
    matrice_3_3 Xk_plus;

    Xk_plus = multiply_33(A, Xk);

    return Xk_plus;
}

matrice_3_3 Pk_plus_calc(matrice_3_3 A, matrice_3_3 Pk, matrice_3_3 Q)
{
    matrice_3_3 A_trans, Pk_plus;
    matrice_3_3 C1, C2;

    A_trans = transpose_33(A);

    C1 = multiply_33(A, Pk);
    C2 = multiply_33(C1, A_trans);

    Pk_plus = addition_33(C2, Q);

    return Pk_plus;
}















/*matrice_3_3 soustraction_33(matrice_3_3 mat1, matrice_3_3 mat2)
//On a en entrée 1 matrice_3_3 et en sortie 1 matrice_3_3
{
    //On déclare mat_out comme une matrice
    matrice_3_3 mat_out;
    // On déclare les variables dans mat_out en premier
    mat_out.x11=0;
    mat_out.x12=0;
    mat_out.x13=0;
    mat_out.x21=0;
    mat_out.x22=0;
    mat_out.x23=0;
    mat_out.x31=0;
    mat_out.x32=0;
    mat_out.x33=0;

    //Addition
    mat_out.x11=mat1.x11-mat2.x11;
    mat_out.x12=mat1.x12-mat2.x12;
    mat_out.x13=mat1.x13-mat2.x13;

    mat_out.x21=mat1.x21-mat2.x21;
    mat_out.x22=mat1.x22-mat2.x22;
    mat_out.x23=mat1.x23-mat2.x23;

    mat_out.x31=mat1.x31-mat2.x31;
    mat_out.x32=mat1.x32-mat2.x32;
    mat_out.x33=mat1.x33-mat2.x33;

    //Return
    return mat_out;
}*/







/*matrice_3_3 inverse_33(matrice_3_3 mat_in)
// 1 matrice_3_3 in input
// 1 matrice_3_3 in output
// do the transposition of the matrix
{
    // declare mat_ou the output
    matrice_3_3 mat_out, mat_x;
    float det, det1, det2, det3;

    // instantiate
    mat_out.x11 = mat_in.x11;
    mat_out.x12 = mat_in.x12;
    mat_out.x13 = mat_in.x13;
    mat_out.x21 = mat_in.x21;
    mat_out.x22 = mat_in.x22;
    mat_out.x23 = mat_in.x23;
    mat_out.x31 = mat_in.x31;
    mat_out.x32 = mat_in.x32;
    mat_out.x33 = mat_in.x33;

    // determinant
    det1 = mat_in.x11 * (mat_in.x22*mat_in.x33 - mat_in.x23*mat_in.x32);
    det2 = mat_in.x12 * (mat_in.x21*mat_in.x33 - mat_in.x23*mat_in.x31);
    det3 = mat_in.x13 * (mat_in.x21*mat_in.x32 - mat_in.x22*mat_in.x31);

    det = det1 - det2 + det3;

    if (det != 0)
    {
        mat_x = transpose_33(mat_in);

        mat_out.x11 = ( 1/det * (mat_x.x22*mat_x.x33 - mat_x.x23*mat_x.x32) );
        mat_out.x12 = ( -1/det * (mat_x.x21*mat_x.x33 - mat_x.x23*mat_x.x31) );
        mat_out.x13 = ( 1/det * (mat_x.x21*mat_x.x32 - mat_x.x22*mat_x.x31) );
        mat_out.x21 = ( -1/det * (mat_x.x12*mat_x.x33 - mat_x.x13*mat_x.x32) );
        mat_out.x22 = ( 1/det * (mat_x.x11*mat_x.x33 - mat_x.x13*mat_x.x31) );
        mat_out.x23 = ( -1/det * (mat_x.x11*mat_x.x32 - mat_x.x12*mat_x.x31) );
        mat_out.x31 = ( 1/det * (mat_x.x12*mat_x.x23 - mat_x.x13*mat_x.x22) );
        mat_out.x32 = ( -1/det * (mat_x.x11*mat_x.x23 - mat_x.x13*mat_x.x21) );
        mat_out.x33 = ( 1/det * (mat_x.x11*mat_x.x22 - mat_x.x12*mat_x.x21) );

        return mat_out;
    }
    // return
    mat_out.x11 = 0;
    return mat_out;
}*/
