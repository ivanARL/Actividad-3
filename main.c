#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "imagenes.h"

int main(void) {

    omp_set_num_threads(64);

    printf("\n============================================\n");
    printf("   PROCESAMIENTO PARALELO DE 30 IMAGENES (SECTIONS)\n");
    printf("============================================\n\n");

    double t0 = omp_get_wtime();

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp taskwait 
        }

        #pragma omp sections
        {
            /* 01 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_01.bmp", "salida/img_01_gray.bmp");
                bmp_flip_vertical("imagenes/img_01.bmp", "salida/img_01_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_01.bmp", "salida/img_01_hflip.bmp");
                bmp_blur_omp("imagenes/img_01.bmp", "salida/img_01_blur.bmp", 57);
            }

            /* 02 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_02.bmp", "salida/img_02_gray.bmp");
                bmp_flip_vertical("imagenes/img_02.bmp", "salida/img_02_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_02.bmp", "salida/img_02_hflip.bmp");
                bmp_blur_omp("imagenes/img_02.bmp", "salida/img_02_blur.bmp", 57);
            }

            /* 03 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_03.bmp", "salida/img_03_gray.bmp");
                bmp_flip_vertical("imagenes/img_03.bmp", "salida/img_03_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_03.bmp", "salida/img_03_hflip.bmp");
                bmp_blur_omp("imagenes/img_03.bmp", "salida/img_03_blur.bmp", 57);
            }

            /* 04 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_04.bmp", "salida/img_04_gray.bmp");
                bmp_flip_vertical("imagenes/img_04.bmp", "salida/img_04_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_04.bmp", "salida/img_04_hflip.bmp");
                bmp_blur_omp("imagenes/img_04.bmp", "salida/img_04_blur.bmp", 57);
            }

            /* 05 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_05.bmp", "salida/img_05_gray.bmp");
                bmp_flip_vertical("imagenes/img_05.bmp", "salida/img_05_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_05.bmp", "salida/img_05_hflip.bmp");
                bmp_blur_omp("imagenes/img_05.bmp", "salida/img_05_blur.bmp", 57);
            }

            /* 06 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_06.bmp", "salida/img_06_gray.bmp");
                bmp_flip_vertical("imagenes/img_06.bmp", "salida/img_06_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_06.bmp", "salida/img_06_hflip.bmp");
                bmp_blur_omp("imagenes/img_06.bmp", "salida/img_06_blur.bmp", 57);
            }

            /* 07 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_07.bmp", "salida/img_07_gray.bmp");
                bmp_flip_vertical("imagenes/img_07.bmp", "salida/img_07_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_07.bmp", "salida/img_07_hflip.bmp");
                bmp_blur_omp("imagenes/img_07.bmp", "salida/img_07_blur.bmp", 57);
            }

            /* 08 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_08.bmp", "salida/img_08_gray.bmp");
                bmp_flip_vertical("imagenes/img_08.bmp", "salida/img_08_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_08.bmp", "salida/img_08_hflip.bmp");
                bmp_blur_omp("imagenes/img_08.bmp", "salida/img_08_blur.bmp", 57);
            }

            /* 09 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_09.bmp", "salida/img_09_gray.bmp");
                bmp_flip_vertical("imagenes/img_09.bmp", "salida/img_09_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_09.bmp", "salida/img_09_hflip.bmp");
                bmp_blur_omp("imagenes/img_09.bmp", "salida/img_09_blur.bmp", 57);
            }

            /* 10 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_10.bmp", "salida/img_10_gray.bmp");
                bmp_flip_vertical("imagenes/img_10.bmp", "salida/img_10_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_10.bmp", "salida/img_10_hflip.bmp");
                bmp_blur_omp("imagenes/img_10.bmp", "salida/img_10_blur.bmp", 57);
            }

            /* 11 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_11.bmp", "salida/img_11_gray.bmp");
                bmp_flip_vertical("imagenes/img_11.bmp", "salida/img_11_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_11.bmp", "salida/img_11_hflip.bmp");
                bmp_blur_omp("imagenes/img_11.bmp", "salida/img_11_blur.bmp", 57);
            }

            /* 12 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_12.bmp", "salida/img_12_gray.bmp");
                bmp_flip_vertical("imagenes/img_12.bmp", "salida/img_12_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_12.bmp", "salida/img_12_hflip.bmp");
                bmp_blur_omp("imagenes/img_12.bmp", "salida/img_12_blur.bmp", 57);
            }

            /* 13 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_13.bmp", "salida/img_13_gray.bmp");
                bmp_flip_vertical("imagenes/img_13.bmp", "salida/img_13_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_13.bmp", "salida/img_13_hflip.bmp");
                bmp_blur_omp("imagenes/img_13.bmp", "salida/img_13_blur.bmp", 57);
            }

            /* 14 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_14.bmp", "salida/img_14_gray.bmp");
                bmp_flip_vertical("imagenes/img_14.bmp", "salida/img_14_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_14.bmp", "salida/img_14_hflip.bmp");
                bmp_blur_omp("imagenes/img_14.bmp", "salida/img_14_blur.bmp", 57);
            }

            /* 15 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_15.bmp", "salida/img_15_gray.bmp");
                bmp_flip_vertical("imagenes/img_15.bmp", "salida/img_15_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_15.bmp", "salida/img_15_hflip.bmp");
                bmp_blur_omp("imagenes/img_15.bmp", "salida/img_15_blur.bmp", 57);
            }

            /* 16 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_16.bmp", "salida/img_16_gray.bmp");
                bmp_flip_vertical("imagenes/img_16.bmp", "salida/img_16_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_16.bmp", "salida/img_16_hflip.bmp");
                bmp_blur_omp("imagenes/img_16.bmp", "salida/img_16_blur.bmp", 57);
            }

            /* 17 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_17.bmp", "salida/img_17_gray.bmp");
                bmp_flip_vertical("imagenes/img_17.bmp", "salida/img_17_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_17.bmp", "salida/img_17_hflip.bmp");
                bmp_blur_omp("imagenes/img_17.bmp", "salida/img_17_blur.bmp", 57);
            }

            /* 18 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_18.bmp", "salida/img_18_gray.bmp");
                bmp_flip_vertical("imagenes/img_18.bmp", "salida/img_18_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_18.bmp", "salida/img_18_hflip.bmp");
                bmp_blur_omp("imagenes/img_18.bmp", "salida/img_18_blur.bmp", 57);
            }

            /* 19 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_19.bmp", "salida/img_19_gray.bmp");
                bmp_flip_vertical("imagenes/img_19.bmp", "salida/img_19_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_19.bmp", "salida/img_19_hflip.bmp");
                bmp_blur_omp("imagenes/img_19.bmp", "salida/img_19_blur.bmp", 57);
            }

            /* 20 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_20.bmp", "salida/img_20_gray.bmp");
                bmp_flip_vertical("imagenes/img_20.bmp", "salida/img_20_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_20.bmp", "salida/img_20_hflip.bmp");
                bmp_blur_omp("imagenes/img_20.bmp", "salida/img_20_blur.bmp", 57);
            }

            /* 21 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_21.bmp", "salida/img_21_gray.bmp");
                bmp_flip_vertical("imagenes/img_21.bmp", "salida/img_21_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_21.bmp", "salida/img_21_hflip.bmp");
                bmp_blur_omp("imagenes/img_21.bmp", "salida/img_21_blur.bmp", 57);
            }

            /* 22 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_22.bmp", "salida/img_22_gray.bmp");
                bmp_flip_vertical("imagenes/img_22.bmp", "salida/img_22_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_22.bmp", "salida/img_22_hflip.bmp");
                bmp_blur_omp("imagenes/img_22.bmp", "salida/img_22_blur.bmp", 57);
            }

            /* 23 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_23.bmp", "salida/img_23_gray.bmp");
                bmp_flip_vertical("imagenes/img_23.bmp", "salida/img_23_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_23.bmp", "salida/img_23_hflip.bmp");
                bmp_blur_omp("imagenes/img_23.bmp", "salida/img_23_blur.bmp", 57);
            }

            /* 24 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_24.bmp", "salida/img_24_gray.bmp");
                bmp_flip_vertical("imagenes/img_24.bmp", "salida/img_24_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_24.bmp", "salida/img_24_hflip.bmp");
                bmp_blur_omp("imagenes/img_24.bmp", "salida/img_24_blur.bmp", 57);
            }

            /* 25 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_25.bmp", "salida/img_25_gray.bmp");
                bmp_flip_vertical("imagenes/img_25.bmp", "salida/img_25_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_25.bmp", "salida/img_25_hflip.bmp");
                bmp_blur_omp("imagenes/img_25.bmp", "salida/img_25_blur.bmp", 57);
            }

            /* 26 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_26.bmp", "salida/img_26_gray.bmp");
                bmp_flip_vertical("imagenes/img_26.bmp", "salida/img_26_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_26.bmp", "salida/img_26_hflip.bmp");
                bmp_blur_omp("imagenes/img_26.bmp", "salida/img_26_blur.bmp", 57);
            }

            /* 27 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_27.bmp", "salida/img_27_gray.bmp");
                bmp_flip_vertical("imagenes/img_27.bmp", "salida/img_27_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_27.bmp", "salida/img_27_hflip.bmp");
                bmp_blur_omp("imagenes/img_27.bmp", "salida/img_27_blur.bmp", 57);
            }

            /* 28 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_28.bmp", "salida/img_28_gray.bmp");
                bmp_flip_vertical("imagenes/img_28.bmp", "salida/img_28_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_28.bmp", "salida/img_28_hflip.bmp");
                bmp_blur_omp("imagenes/img_28.bmp", "salida/img_28_blur.bmp", 57);
            }

            /* 29 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_29.bmp", "salida/img_29_gray.bmp");
                bmp_flip_vertical("imagenes/img_29.bmp", "salida/img_29_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_29.bmp", "salida/img_29_hflip.bmp");
                bmp_blur_omp("imagenes/img_29.bmp", "salida/img_29_blur.bmp", 57);
            }

            /* 30 */
            #pragma omp section
            {
                bmp_grises("imagenes/img_30.bmp", "salida/img_30_gray.bmp");
                bmp_flip_vertical("imagenes/img_30.bmp", "salida/img_30_vflip.bmp");
                bmp_flip_horizontal("imagenes/img_30.bmp", "salida/img_30_hflip.bmp");
                bmp_blur_omp("imagenes/img_30.bmp", "salida/img_30_blur.bmp", 57);
            }
        }
    }

    double t1 = omp_get_wtime();
    printf("\nTIEMPO TOTAL: %.3f segundos\n", t1 - t0);

    printf("\nPROCESAMIENTO COMPLETADO. Salida en carpeta 'salida/'\n");
    return 0;
}
