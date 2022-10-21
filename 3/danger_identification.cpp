
void danger_identification(int N,float (*slopes)[4],int *danger)
{
    for (int i = 0;i < N;i++)
    {
        float nums[5] = {slopes[i][0],slopes[i][1],slopes[i][2]};
        float max1 = max(3,nums);
        float max3 = max(1,nums);

        if (max1 <= slopes[i][3] && slopes[i][3] <= max3)
        {
            danger[i] = 1;
        }
        else
        {
            danger[i] = 0;
        }
    }
}

 
static void bubbleSort(float arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

static void swap(float* xp, float* yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

static float max(int size,float arr[])
{
    bubbleSort(arr, size);
    return arr[size-1];
}


