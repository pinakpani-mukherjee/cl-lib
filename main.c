#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
};

#define train_count sizeof(train) / sizeof(train[0])

float rand_float(void)
{
    return (float)rand() / (float)RAND_MAX;
}

int main(int argc, char const *argv[])
{
    srand(time(0));
    // y = x*w;

    float w = rand_float() * 10.0f;
    float square_of_error = 0.0f;
    for (size_t i = 0; i < train_count; i++)
    {
        float x = train[i][0];
        float y = x * w;
        float d = y - train[i][1];
        square_of_error += d * d;

        printf("actual: %f, expected:%f \n", y, train[i][1]);
    }
    printf("rmse : %f", sqrtf(square_of_error / train_count));

    return 0;
}
