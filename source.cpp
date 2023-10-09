#include <iostream>
#include "functions.h"
#include "vector2.h"
#include "vector3.h"
#include <cmath>

int main() {
    int width = 120;
    int height = 30;

    float screenAspect = (float) width / height;
    float pixelAspect = (float) 11.0f / 24.0f;

    char gradient[] = " .:!/r(l1Z4H9W8$@";
    int gradientSize = sizeof(gradient) - 2;

    char *screen = new char[height * width + 1];
    screen[height * width] = '\0';

    for (int t = 0; t < 100000; t++) {
        vector3 light = normalize(vector3(sin(t * 0.001), cos(t * 0.001), -1.0));

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                vector2 uv = vector2(i, j) / vector2(width, height) * 2.0f - 1.0f;
                uv.x *= screenAspect * pixelAspect;

                vector3 ro = vector3(-2, 0, 0);
                vector3 rd = normalize(vector3(1, uv));

                char pixel = ' ';
                int colour = 0;
                vector2 intersection = sphereRaycast(ro, rd, 1);

                if (intersection.x > 0) {
                    vector3 lightPoint = ro + rd * intersection.x;
                    vector3 n = normalize(lightPoint);
                    float diff = dot(n, light);
                    colour = (int) (diff * 20);
                }
                colour = clamp(colour, 0, gradientSize);
                pixel = gradient[colour];
                screen[i + j * width] = pixel;
            }
        }

        printf("%s", screen);
    }
    getchar();
    return 0;
}