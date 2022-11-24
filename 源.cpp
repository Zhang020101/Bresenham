#include <iostream>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;
void DrawBresenhamline(int x0, int y0, int x1, int y1)
{
    Mat im(500, 500, CV_8UC3, Scalar(255, 255, 255));
    int dx = x1 - x0;//xƫ����
    int dy = y1 - y0;//yƫ����
    int ux = dx > 0 ? 1 : -1;//x��չ����
    int uy = dy > 0 ? 1 : -1;//y��չ����
    dx = abs(dx);
    dy = abs(dy);
    int dx2 = dx << 1;//xƫ������2
    int dy2 = dy << 1;//yƫ������2
    if (dx > dy)
    {//��xΪ�����������
        int e = -dx; //e = -0.5 * 2 * dx,��e ��2 * dx* e�滻
        int x = x0;//���x����
        int y = y0;//���y����

        for (x = x0; x != x1; x += ux)
        {
           
            im.at<Vec3b>(x, y) = Vec3b(255, 0, 0);
            e = e + dy2;//���� 2*e*dx= 2*e*dx + 2dy  ��ԭ���� e = e + k��
            if (e > 0)//e�������Ҵ���0ʱ��ʾҪȡ���ϵĵ㣨���������µĵ㣩
            {
                y += uy;
                e = e - dx2;//2*e*dx = 2*e*dx - 2*dx  (ԭ���� e = e -1)
            }
        }


    }
    else
    {//��yΪ�����������
        int e = -dy; //e = -0.5 * 2 * dy,��e ��2 * dy* e�滻
        int x = x0;//���x����
        int y = y0;//���y����
        for (y = y0; y != y1; y += uy)
        {
            
            im.at<Vec3b>(x, y) = Vec3b(255, 0, 0);
            e = e + dx2;//���� 2*e*dy= 2*e*dy + 2dy  ��ԭ���� e = e + k��
            if (e > 0)//e�������Ҵ���0ʱ��ʾҪȡ���ϵĵ㣨���������µĵ㣩
            {
                x += ux;
                e = e - dy2;//2*e*dy = 2*e*dy - 2*dy  (ԭ���� e = e -1)
            }
        }

    }
    
    im.at<Vec3b>(x1, y1) = Vec3b(255, 0, 0);
    imshow("Bresenham", im);

}


int main()
{

    DrawBresenhamline(400, 50, 50,100);

    waitKey(0);
    return 0;
}

