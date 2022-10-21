#include "danger_identification.h"
#include <assert.h>

static float min(float *arr);

static float max(float *arr);


void danger_identification(int N,float (*slopes)[4],int *danger)
{
    assert(slopes != NULL);
    assert(danger != NULL);

    float low_boundary = 0, high_boundary = 0;

    for (int i = 0;i < N;i++)
    {
        float nums[3] = {slopes[i][0],slopes[i][1],slopes[i][2]};
        low_boundary = min(nums);
        high_boundary = max(nums);

        if ((low_boundary <= slopes[i][3]) && (slopes[i][3] <= high_boundary))
        {
            danger[i] = 1;
        }
        else
        {
            danger[i] = 0;
        }
    }
}

static float max(float *arr)
{
    assert(arr != NULL);

    float max = 0;
    for (int i = 0;i < 3;i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

static float min(float *arr)
{
    assert(arr != NULL);
    
    float min = 1000;
    for (int i = 0;i < 3;i++)
    {
        if(min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}



