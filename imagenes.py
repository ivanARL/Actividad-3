#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include "imagenes.h"
#include <omp.h>


void bmp_grises(const char* inputPath, const char* outputPath)
{
    FILE *image = fopen(inputPath, "rb");
    if (!image) { printf("No se pudo abrir %s\n", inputPath); return; }

    FILE *outputImage = fopen(outputPath, "wb");
    if (!outputImage) { printf("No se pudo crear %s\n", outputPath); fclose(image); return; }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image);
    fwrite(header, sizeof(unsigned char), 54, outputImage);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int row_padded = (width * 3 + 3) & (~3);

    unsigned char** buffer = (unsigned char**)malloc(height * sizeof(unsigned char*));
    for (int i = 0; i < height; i++) {
        buffer[i] = (unsigned char*)malloc(row_padded);
        fread(buffer[i], sizeof(unsigned char), row_padded, image);
    }

    // PROCESO EN PARALELO (OpenMP)

    #pragma omp parallel for
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pos = x * 3;
            unsigned char b = buffer[y][pos];
            unsigned char g = buffer[y][pos + 1];
            unsigned char r = buffer[y][pos + 2];

            unsigned char pixel = (0.21*r + 0.72*g + 0.07*b);
            pixel = (pixel > 127) ? 255 : 0;

            buffer[y][pos]     = pixel;
            buffer[y][pos + 1] = pixel;
            buffer[y][pos + 2] = pixel;
        }
    }

    for (int i = 0; i < height; i++) {
        fwrite(buffer[i], sizeof(unsigned char), row_padded, outputImage);
        free(buffer[i]);
    }

    free(buffer);
    fclose(image);
    fclose(outputImage);

    printf("Imagen en grises generada: %s\n", outputPath);
}
void bmp_flip_vertical(const char* inputPath, const char* outputPath)
{
    FILE *image = fopen(inputPath, "rb");
    if (!image) { printf("No se pudo abrir %s\n", inputPath); return; }

    FILE *outputImage = fopen(outputPath, "wb");
    if (!outputImage) { printf("No se pudo crear %s\n", outputPath); fclose(image); return; }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image);
    fwrite(header, sizeof(unsigned char), 54, outputImage);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int row_padded = (width * 3 + 3) & (~3);

    unsigned char** buffer = (unsigned char**)malloc(height * sizeof(unsigned char*));
    for (int i = 0; i < height; i++) {
        buffer[i] = (unsigned char*)malloc(row_padded);
        fread(buffer[i], sizeof(unsigned char), row_padded, image);
    }

    // PROCESO EN PARALELO
    #pragma omp parallel for
    for (int y = 0; y < height / 2; y++) {
        int opposite = height - 1 - y;

        for (int x = 0; x < row_padded; x++) {
            unsigned char temp = buffer[y][x];
            buffer[y][x] = buffer[opposite][x];
            buffer[opposite][x] = temp;
        }
    }

    for (int i = 0; i < height; i++) {
        fwrite(buffer[i], sizeof(unsigned char), row_padded, outputImage);
        free(buffer[i]);
    }

    free(buffer);
    fclose(image);
    fclose(outputImage);

    printf("Imagen invertida verticalmente: %s\n", outputPath);
}
void bmp_flip_horizontal(const char* inputPath, const char* outputPath)
{
    FILE *image = fopen(inputPath, "rb");
    if (!image) { printf("No se pudo abrir %s\n", inputPath); return; }

    FILE *outputImage = fopen(outputPath, "wb");
    if (!outputImage) { printf("No se pudo crear %s\n", outputPath); fclose(image); return; }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image);
    fwrite(header, sizeof(unsigned char), 54, outputImage);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int row_padded = (width * 3 + 3) & (~3);

    unsigned char** buffer = (unsigned char**)malloc(height * sizeof(unsigned char*));
    for (int i = 0; i < height; i++) {
        buffer[i] = (unsigned char*)malloc(row_padded);
        fread(buffer[i], sizeof(unsigned char), row_padded, image);
    }

    // PROCESO EN PARALELO
    #pragma omp parallel for
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {

            int left  = x * 3;
            int right = (width - 1 - x) * 3;

            for (int k = 0; k < 3; k++) {
                unsigned char tmp = buffer[y][left + k];
                buffer[y][left + k] = buffer[y][right + k];
                buffer[y][right + k] = tmp;
            }
        }
    }

    for (int i = 0; i < height; i++) {
        fwrite(buffer[i], sizeof(unsigned char), row_padded, outputImage);
        free(buffer[i]);
    }

    free(buffer);
    fclose(image);
    fclose(outputImage);

    printf("Imagen invertida horizontalmente: %s\n", outputPath);
}
void bmp_blur_omp(const char* inputPath, const char* outputPath, int mm)
{
    FILE *image = fopen(inputPath, "rb");
    if (!image) { printf("No se pudo abrir %s\n", inputPath); return; }

    FILE *outputImage = fopen(outputPath, "wb");
    if (!outputImage) { printf("No se pudo crear %s\n", outputPath); fclose(image); return; }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image);
    fwrite(header, sizeof(unsigned char), 54, outputImage);

    int width  = *(int*)&header[18];
    int height = *(int*)&header[22];
    int row_padded = (width * 3 + 3) & (~3);

    int kernelRadius = (mm - 1) / 2;

    
   
    unsigned char** buffer = (unsigned char**)malloc(height * sizeof(unsigned char*));
    for (int i = 0; i < height; i++) {
        buffer[i] = (unsigned char*)malloc(row_padded);
        fread(buffer[i], sizeof(unsigned char), row_padded, image);
    }


 
    unsigned char** copia = (unsigned char**)malloc(height * sizeof(unsigned char*));
    for (int i = 0; i < height; i++) {
        copia[i] = (unsigned char*)malloc(row_padded);
        memcpy(copia[i], buffer[i], row_padded);
    }

    printf("Aplicando blur %dx%d...\n", mm, mm);

 
    // PROCESAMIENTO EN PARALELO (OpenMP)

    #pragma omp parallel for
    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            int sumB = 0, sumG = 0, sumR = 0;
            int count = 0;

            // Kernel deslizante
            for (int dy = -kernelRadius; dy <= kernelRadius; dy++) {
                for (int dx = -kernelRadius; dx <= kernelRadius; dx++) {

                    int ny = y + dy;
                    int nx = x + dx;

                    if (ny < 0 || ny >= height || nx < 0 || nx >= width)
                        continue;

                    int pos = nx * 3;

                    sumB += copia[ny][pos];
                    sumG += copia[ny][pos + 1];
                    sumR += copia[ny][pos + 2];

                    count++;
                }
            }

            int pos = x * 3;
            buffer[y][pos]     = sumB / count;
            buffer[y][pos + 1] = sumG / count;
            buffer[y][pos + 2] = sumR / count;
        }
    }

    // GUARDAR RESULTADO

    for (int i = 0; i < height; i++) {
        fwrite(buffer[i], sizeof(unsigned char), row_padded, outputImage);
        free(buffer[i]);
        free(copia[i]);
    }

    free(buffer);
    free(copia);
    fclose(image);
    fclose(outputImage);

    printf("Blur %dx%d generado: %s\n", mm, mm, outputPath);
}
