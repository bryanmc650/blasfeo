/**************************************************************************************************
*                                                                                                 *
* This file is part of BLASFEO.                                                                   *
*                                                                                                 *
* BLASFEO -- BLAS For Embedded Optimization.                                                      *
* Copyright (C) 2016-2017 by Gianluca Frison.                                                     *
* Developed at IMTEK (University of Freiburg) under the supervision of Moritz Diehl.              *
* All rights reserved.                                                                            *
*                                                                                                 *
* HPMPC is free software; you can redistribute it and/or                                          *
* modify it under the terms of the GNU Lesser General Public                                      *
* License as published by the Free Software Foundation; either                                    *
* version 2.1 of the License, or (at your option) any later version.                              *
*                                                                                                 *
* HPMPC is distributed in the hope that it will be useful,                                        *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                                  *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                                            *
* See the GNU Lesser General Public License for more details.                                     *
*                                                                                                 *
* You should have received a copy of the GNU Lesser General Public                                *
* License along with HPMPC; if not, write to the Free Software                                    *
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA                  *
*                                                                                                 *
* Author: Gianluca Frison, giaf (at) dtu.dk                                                       *
*                          gianluca.frison (at) imtek.uni-freiburg.de                             *
*                                                                                                 *
**************************************************************************************************/

#include <stdio.h>



#ifdef __cplusplus
extern "C" {
#endif



/************************************************
* d_aux_lib.c
************************************************/

// returns the memory size (in bytes) needed for a smat
int blasfeo_memsize_smat(int m, int n);
// returns the memory size (in bytes) needed for the diagonal of a smat
int blasfeo_memsize_diag_smat(int m, int n);
// returns the memory size (in bytes) needed for a svec
int blasfeo_memsize_svec(int m);
// create a strmat for a matrix of size m*n by using memory passed by a pointer (pointer is not updated)
void blasfeo_create_smat(int m, int n, struct blasfeo_smat *sA, void *memory);
// create a strvec for a vector of size m by using memory passed by a pointer (pointer is not updated)
void blasfeo_create_svec(int m, struct blasfeo_svec *sA, void *memory);
void blasfeo_pack_smat(int m, int n, float *A, int lda, struct blasfeo_smat *sA, int ai, int aj);
void blasfeo_pack_svec(int m, float *a, struct blasfeo_svec *sa, int ai);
void blasfeo_pack_tran_smat(int m, int n, float *A, int lda, struct blasfeo_smat *sA, int ai, int aj);
void blasfeo_unpack_smat(int m, int n, struct blasfeo_smat *sA, int ai, int aj, float *A, int lda);
void blasfeo_unpack_svec(int m, struct blasfeo_svec *sa, int ai, float *a);
void blasfeo_unpack_tran_smat(int m, int n, struct blasfeo_smat *sA, int ai, int aj, float *A, int lda);
void s_cast_mat2strmat(float *A, struct blasfeo_smat *sA);
void s_cast_diag_mat2strmat(float *dA, struct blasfeo_smat *sA);
void s_cast_vec2vecmat(float *a, struct blasfeo_svec *sa);

void blasfeo_sgein1(float a, struct blasfeo_smat *sA, int ai, int aj);
float blasfeo_sgeex1(struct blasfeo_smat *sA, int ai, int aj);
void blasfeo_svecin1(float a, struct blasfeo_svec *sx, int xi);
float blasfeo_svecex1(struct blasfeo_svec *sx, int xi);

// A <= alpha
void blasfeo_sgese(int m, int n, float alpha, struct blasfeo_smat *sA, int ai, int aj);
// a <= alpha
void blasfeo_svecse(int m, float alpha, struct blasfeo_svec *sx, int xi);

// copy and scale
// void sgecp_lib(int m, int n, int offsetA, float *A, int sda, int offsetB, float *B, int sdb);
//
void blasfeo_sgecpsc(int m, int n, float alpha, struct blasfeo_smat *sA, int ai, int aj, struct blasfeo_smat *sC, int ci, int cj);
void blasfeo_sgecp(int m, int n, struct blasfeo_smat *sA, int ai, int aj, struct blasfeo_smat *sC, int ci, int cj);
void blasfeo_sgesc(int m, int n, float alpha, struct blasfeo_smat *sA, int ai, int aj);

void blasfeo_sveccp(int m, struct blasfeo_svec *sa, int ai, struct blasfeo_svec *sc, int ci);
void blasfeo_svecsc(int m, float alpha, struct blasfeo_svec *sa, int ai);
void blasfeo_sveccpsc(int m, float alpha, struct blasfeo_svec *sa, int ai, struct blasfeo_svec *sc, int ci);

void strcp_l_lib(int m, float alpha, int offsetA, float *A, int sda, int offsetB, float *B, int sdb);
void blasfeo_strcp_l(int m, struct blasfeo_smat *sA, int ai, int aj, struct blasfeo_smat *sC, int ci, int cj);

void sgead_lib(int m, int n, float alpha, int offsetA, float *A, int sda, int offsetB, float *B, int sdb);
void blasfeo_sgead(int m, int n, float alpha, struct blasfeo_smat *sA, int ai, int aj, struct blasfeo_smat *sC, int ci, int cj);
void blasfeo_svecad(int m, float alpha, struct blasfeo_svec *sa, int ai, struct blasfeo_svec *sc, int ci);

void sgetr_lib(int m, int n, float alpha, int offsetA, float *pA, int sda, int offsetC, float *pC, int sdc);
void sgetr_libstr(int m, int n, struct blasfeo_smat *sA, int ai, int aj, struct blasfeo_smat *sC, int ci, int cj);

void strtr_l_lib(int m, float alpha, int offsetA, float *pA, int sda, int offsetC, float *pC, int sdc);
void strtr_l_libstr(int m, struct blasfeo_smat *sA, int ai, int aj, struct blasfeo_smat *sC, int ci, int cj);
void strtr_u_lib(int m, float alpha, int offsetA, float *pA, int sda, int offsetC, float *pC, int sdc);
void strtr_u_libstr(int m, struct blasfeo_smat *sA, int ai, int aj, struct blasfeo_smat *sC, int ci, int cj);

void sdiareg_lib(int kmax, float reg, int offset, float *pD, int sdd);
void sdiare_libstr(int kmax, float alpha, struct blasfeo_smat *sA, int ai, int aj);
void sdiaex_libstr(int kmax, float alpha, struct blasfeo_smat *sA, int ai, int aj, struct blasfeo_svec *sx, int xi);
void sdiain_libstr(int kmax, float alpha, struct blasfeo_svec *sx, int xi, struct blasfeo_smat *sA, int ai, int aj);
void sdiain_sqrt_lib(int kmax, float *x, int offset, float *pD, int sdd);
void sdiaex_lib(int kmax, float alpha, int offset, float *pD, int sdd, float *x);
void sdiaad_lib(int kmax, float alpha, float *x, int offset, float *pD, int sdd);
void sdiain_libsp(int kmax, int *idx, float alpha, float *x, float *pD, int sdd);
void sdiain_sp_libstr(int kmax, float alpha, struct blasfeo_svec *sx, int xi, int *idx, struct blasfeo_smat *sD, int di, int dj);
void sdiaex_libsp(int kmax, int *idx, float alpha, float *pD, int sdd, float *x);
void sdiaex_sp_libstr(int kmax, float alpha, int *idx, struct blasfeo_smat *sD, int di, int dj, struct blasfeo_svec *sx, int xi);
void sdiaad_libstr(int kmax, float alpha, struct blasfeo_svec *sx, int xi, struct blasfeo_smat *sA, int ai, int aj);
void sdiaad_libsp(int kmax, int *idx, float alpha, float *x, float *pD, int sdd);
void sdiaad_sp_libstr(int kmax, float alpha, struct blasfeo_svec *sx, int xi, int *idx, struct blasfeo_smat *sD, int di, int dj);
void sdiaadin_libsp(int kmax, int *idx, float alpha, float *x, float *y, float *pD, int sdd);
void sdiaadin_sp_libstr(int kmax, float alpha, struct blasfeo_svec *sx, int xi, struct blasfeo_svec *sy, int yi, int *idx, struct blasfeo_smat *sD, int di, int dj);
void srowin_lib(int kmax, float alpha, float *x, float *pD);
void srowin_libstr(int kmax, float alpha, struct blasfeo_svec *sx, int xi, struct blasfeo_smat *sA, int ai, int aj);
void srowex_lib(int kmax, float alpha, float *pD, float *x);
void srowex_libstr(int kmax, float alpha, struct blasfeo_smat *sA, int ai, int aj, struct blasfeo_svec *sx, int xi);
void srowad_lib(int kmax, float alpha, float *x, float *pD);
void srowad_libstr(int kmax, float alpha, struct blasfeo_svec *sx, int xi, struct blasfeo_smat *sA, int ai, int aj);
void srowin_libsp(int kmax, float alpha, int *idx, float *x, float *pD);
void srowad_libsp(int kmax, int *idx, float alpha, float *x, float *pD);
void srowad_sp_libstr(int kmax, float alpha, struct blasfeo_svec *sx, int xi, int *idx, struct blasfeo_smat *sD, int di, int dj);
void srowadin_libsp(int kmax, int *idx, float alpha, float *x, float *y, float *pD);
void srowsw_lib(int kmax, float *pA, float *pC);
void srowsw_libstr(int kmax, struct blasfeo_smat *sA, int ai, int aj, struct blasfeo_smat *sC, int ci, int cj);
void srowpe_libstr(int kmax, int *ipiv, struct blasfeo_smat *sA);
void srowpei_libstr(int kmax, int *ipiv, struct blasfeo_smat *sA);
void scolin_lib(int kmax, float *x, int offset, float *pD, int sdd);
void scolin_libstr(int kmax, struct blasfeo_svec *sx, int xi, struct blasfeo_smat *sA, int ai, int aj);
void scolad_lib(int kmax, float alpha, float *x, int offset, float *pD, int sdd);
void scolin_libsp(int kmax, int *idx, float *x, float *pD, int sdd);
void scolad_libsp(int kmax, float alpha, int *idx, float *x, float *pD, int sdd);
void scolsw_lib(int kmax, int offsetA, float *pA, int sda, int offsetC, float *pC, int sdc);
void scolsw_libstr(int kmax, struct blasfeo_smat *sA, int ai, int aj, struct blasfeo_smat *sC, int ci, int cj);
void scolpe_libstr(int kmax, int *ipiv, struct blasfeo_smat *sA);
void scolpei_libstr(int kmax, int *ipiv, struct blasfeo_smat *sA);
void svecin_libsp(int kmax, int *idx, float *x, float *y);
void svecad_libsp(int kmax, int *idx, float alpha, float *x, float *y);
void svecad_sp_libstr(int m, float alpha, struct blasfeo_svec *sx, int xi, int *idx, struct blasfeo_svec *sz, int zi);
void svecin_sp_libstr(int m, float alpha, struct blasfeo_svec *sx, int xi, int *idx, struct blasfeo_svec *sz, int zi);
void svecex_sp_libstr(int m, float alpha, int *idx, struct blasfeo_svec *sx, int x, struct blasfeo_svec *sz, int zi);
void sveccl_libstr(int m, struct blasfeo_svec *sxm, int xim, struct blasfeo_svec *sx, int xi, struct blasfeo_svec *sxp, int xip, struct blasfeo_svec *sz, int zi);
void sveccl_mask_libstr(int m, struct blasfeo_svec *sxm, int xim, struct blasfeo_svec *sx, int xi, struct blasfeo_svec *sxp, int xip, struct blasfeo_svec *sz, int zi, struct blasfeo_svec *sm, int mi);
void svecze_libstr(int m, struct blasfeo_svec *sm, int mi, struct blasfeo_svec *sv, int vi, struct blasfeo_svec *se, int ei);
void svecnrm_inf_libstr(int m, struct blasfeo_svec *sx, int xi, float *ptr_norm);
void svecpe_libstr(int kmax, int *ipiv, struct blasfeo_svec *sx, int xi);
void svecpei_libstr(int kmax, int *ipiv, struct blasfeo_svec *sx, int xi);



#ifdef __cplusplus
}
#endif

