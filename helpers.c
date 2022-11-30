//  ALUNO: ANTONIO ALDENI ALVES VASCONCELOS FILHO
//  MATRÍCULA: 20212045050541
//  https://github.com/Aldenivsclls
//  manipulação de imagens
#include "helpers.h"
#include <math.h>
void grayscale(int height, int wid, RGBTRIPLE image[height][wid])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < wid; j++)
        {
            int rgbt = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = rgbt;
        }
    }
    return;
}
void reflect(int height, int wid, RGBTRIPLE image[height][wid])
{
    for (int i = 0; i < height; i++)
    {
        if (wid % 2 == 0)
        {
            for (int j = 0; j < wid / 2; j++)
            {
                RGBTRIPLE temp[height][wid];
                temp[i][j] = image[i][j];
                image[i][j] = image[i][wid - (j + 1)];
                image[i][wid - (j + 1)] = temp[i][j];
            }
        }
        else
        {
            for (int j = 0; j < (wid - 1) / 2; j++)
            {
                RGBTRIPLE temp[height][wid];
                temp[i][j] = image[i][j];
                image[i][j] = image[i][wid - (j + 1)];
                image[i][wid - (j + 1)] = temp[i][j];
            }
        }
    }
    return;
}
void blur(int height, int wid, RGBTRIPLE image[height][wid])
{
    RGBTRIPLE temp[height][wid];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < wid; j++)
        {
            float sumBlue = 0;
            float sumGreen = 0;
            float sumRed = 0;
            float counter = 0;
            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if (i + r < 0 || i + r > height - 1)
                    {
                        continue;
                    }
                    if (j + c < 0 || j + c > wid - 1)
                    {
                        continue;
                    }
                    sumBlue += image[i + r][j + c].rgbtBlue;
                    sumGreen += image[i + r][j + c].rgbtGreen;
                    sumRed += image[i + r][j + c].rgbtRed;
                    counter++;
                }
            }
            temp[i][j].rgbtBlue = round(sumBlue / counter);
            temp[i][j].rgbtGreen = round(sumGreen / counter);
            temp[i][j].rgbtRed = round(sumRed / counter);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < wid; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}
void edges(int height, int wid, RGBTRIPLE image[height][wid])
{
    RGBTRIPLE temp[height][wid];
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < wid; j++)
        {
            int gxBlue = 0;
            int gyBlue = 0;
            int gxGreen = 0;
            int gyGreen = 0;
            int gxRed = 0;
            int gyRed = 0;
            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if (i + r < 0 || i + r > height - 1)
                    {
                        continue;
                    }
                    if (j + c < 0 || j + c > wid - 1)
                    {
                        continue;
                    }
                    gxBlue += image[i + r][j + c].rgbtBlue * gx[r + 1][c + 1];
                    gyBlue += image[i + r][j + c].rgbtBlue * gy[r + 1][c + 1];
                    gxGreen += image[i + r][j + c].rgbtGreen * gx[r + 1][c + 1];
                    gyGreen += image[i + r][j + c].rgbtGreen * gy[r + 1][c + 1];
                    gxRed += image[i + r][j + c].rgbtRed * gx[r + 1][c + 1];
                    gyRed += image[i + r][j + c].rgbtRed * gy[r + 1][c + 1];
                }
            }
            int blue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));
            int green = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            int red = round(sqrt(gxRed * gxRed + gyRed * gyRed));

            temp[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
            temp[i][j].rgbtGreen = (green > 255) ? 255 : green;
            temp[i][j].rgbtRed = (red > 255) ? 255 : red;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < wid; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }

    return;
}