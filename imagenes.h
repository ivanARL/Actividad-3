#ifndef IMAGENES_H
#define IMAGENES_H

// Convierte imagen BMP a escala de grises (OpenMP)
void bmp_grises(const char* inputPath, const char* outputPath);

// Invierte imagen verticalmente (OpenMP)
void bmp_flip_vertical(const char* inputPath, const char* outputPath);

// Invierte imagen horizontalmente (OpenMP)
void bmp_flip_horizontal(const char* inputPath, const char* outputPath);

// Blur con kernel mm x mm (OpenMP)
void bmp_blur_omp(const char* inputPath, const char* outputPath, int mm);

#endif
