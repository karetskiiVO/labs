#include <stdio.h>

#include "specialtypes.h"

void input_ship (int N, struct position *ship)
{
    int lat_deg = 0;
    int lat_min = 0;
    int lat_sec = 0;
    int lon_deg = 0;
    int lon_min = 0;
    int lon_sec = 0;

    int exit_flag = 1;
    while (exit_flag)
    {
        exit_flag = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%d%d%d%d%d%d", &lat_deg, &lat_min, &lat_sec, &lon_deg, &lon_min, &lon_sec);
            if (lat_deg < 0 || lat_min < 0 || lat_sec < 0 || lon_deg < 0 ||lon_min < 0 || lon_sec < 0)
            {
                printf("Error, wrong data, enter again:\n");
                exit_flag = 1;
                break;
            }
            if (lat_deg > 90 || lat_min > 60 || lat_sec > 60 || lon_deg > 180 ||lon_min > 60 || lon_sec > 60)
            {
                printf("Error, wrong data, enter again:\n");
                exit_flag = 1;
                break;
            }

            ship[i].lat.degree = lat_deg;
            ship[i].lat.minute = lat_min;
            ship[i].lat.second = lat_sec;
            ship[i].longitude.degree = lon_deg;
            ship[i].longitude.minute = lon_min;
            ship[i].longitude.second = lon_sec;

        }
    }
}

struct fig input_triangle (void)
{
    struct fig triangle = {};
    int lat_deg = 0;
    int lat_min = 0;
    int lat_sec = 0;
    int lon_deg = 0;
    int lon_min = 0;
    int lon_sec = 0;

    int exit_flag = 1;
    while (exit_flag)
    {
        exit_flag = 0;
        scanf("%d%d%d%d%d%d", &lat_deg, &lat_min, &lat_sec, &lon_deg, &lon_min, &lon_sec);
        if (lat_deg < 0 || lat_min < 0 || lat_sec < 0 || lon_deg < 0 ||lon_min < 0 || lon_sec < 0)
        {
            printf("Error, wrong data, enter again:\n");
            exit_flag = 1;
            continue;
        }
        if (lat_deg > 90 || lat_min > 60 || lat_sec > 60 || lon_deg > 180 ||lon_min > 60 || lon_sec > 60)
        {
            printf("Error, wrong data, enter again:\n");
            exit_flag = 1;
            continue;
        }

        triangle.apex1.lat.degree = lat_deg;
        triangle.apex1.lat.minute = lat_min;
        triangle.apex1.lat.second = lat_sec;
        triangle.apex1.longitude.degree = lon_deg;
        triangle.apex1.longitude.minute = lon_min;
        triangle.apex1.longitude.second = lon_sec;


        scanf("%d%d%d%d%d%d", &lat_deg, &lat_min, &lat_sec, &lon_deg, &lon_min, &lon_sec);
        if (lat_deg < 0 || lat_min < 0 || lat_sec < 0 || lon_deg < 0 ||lon_min < 0 || lon_sec < 0)
        {
            printf("Error, wrong data, enter again:\n");
            exit_flag = 1;
            continue;
        }
        if (lat_deg > 90 || lat_min > 60 || lat_sec > 60 || lon_deg > 180 ||lon_min > 60 || lon_sec > 60)
        {
            printf("Error, wrong data, enter again:\n");
            exit_flag = 1;
            continue;
        }

        triangle.apex2.lat.degree = lat_deg;
        triangle.apex2.lat.minute = lat_min;
        triangle.apex2.lat.second = lat_sec;
        triangle.apex2.longitude.degree = lon_deg;
        triangle.apex2.longitude.minute = lon_min;
        triangle.apex2.longitude.second = lon_sec;


        scanf("%d%d%d%d%d%d", &lat_deg, &lat_min, &lat_sec, &lon_deg, &lon_min, &lon_sec);
        if (lat_deg < 0 || lat_min < 0 || lat_sec < 0 || lon_deg < 0 ||lon_min < 0 || lon_sec < 0)
        {
            printf("Error, wrong data, enter again:\n");
            exit_flag = 1;
            continue;
        }
        if (lat_deg > 90 || lat_min > 60 || lat_sec > 60 || lon_deg > 180 ||lon_min > 60 || lon_sec > 60)
        {
            printf("Error, wrong data, enter again:\n");
            exit_flag = 1;
            continue;
        }

        triangle.apex3.lat.degree = lat_deg;
        triangle.apex3.lat.minute = lat_min;
        triangle.apex3.lat.second = lat_sec;
        triangle.apex3.longitude.degree = lon_deg;
        triangle.apex3.longitude.minute = lon_min;
        triangle.apex3.longitude.second = lon_sec;
    }

    return triangle;
}

struct position input_port (void)
{
    struct position port = {};
    int lat_deg = 0;
    int lat_min = 0;
    int lat_sec = 0;
    int lon_deg = 0;
    int lon_min = 0;
    int lon_sec = 0;

    int exit_flag = 1;
    while (exit_flag)
    {
        exit_flag = 0;
        scanf("%d%d%d%d%d%d", &lat_deg, &lat_min, &lat_sec, &lon_deg, &lon_min, &lon_sec);
        if (lat_deg < 0 || lat_min < 0 || lat_sec < 0 || lon_deg < 0 ||lon_min < 0 || lon_sec < 0)
        {
            printf("Error, wrong data, enter again:\n");
            exit_flag = 1;
            continue;
        }
        if (lat_deg > 90 || lat_min > 60 || lat_sec > 60 || lon_deg > 180 ||lon_min > 60 || lon_sec > 60)
        {
            printf("Error, wrong data, enter again:\n");
            exit_flag = 1;
            continue;
        }

        port.lat.degree = lat_deg;
        port.lat.minute = lat_min;
        port.lat.second = lat_sec;
        port.longitude.degree = lon_deg;
        port.longitude.minute = lon_min;
        port.longitude.second = lon_sec;
    }

    return port;
}
