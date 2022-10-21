
void danger_identification(int N,float (*slopes)[4],int *danger)
{
    for (int i = 0;i < N;i++)
    {
        float nums[3] = {slopes[i][0],slopes[i][1],slopes[i][2]};
        bubbleSort(nums, 3);
        float high_boundary = nums[2];
        float low_boundary = nums[0];

        if (low_boundary <= slopes[i][3] <= high_boundary)
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



