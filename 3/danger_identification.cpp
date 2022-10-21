
void danger_identification(int N,float (*slopes)[4],int *danger)
{
    for (int i = 0;i < N;i++)
    {
        float nums[50] = {slopes[i][0],slopes[i][1],slopes[i][2]};
        bubbleSort(nums, 3);
        float max1 = nums[2];
        float max3 = nums[0];

        if (max1 <= slopes[i][3] <= max3)
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
                float temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}



