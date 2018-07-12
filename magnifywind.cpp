#include<iostream>
#include<graphics.h>
using namespace std;

struct vertex
{
    float x;
    float y;
};

void hermite(vertex p0, vertex p3, vertex r0, vertex r3, int xc, int yc)      //xc, yc are starting points, to shift shape formed
{
    float x, y, z;
    for (float t=0; t<=1; t=t+0.001)
    {
        float e = 2*t*t*t - 3*t*t + 1;
        float f = -2*t*t*t + 3*t*t;
        float g = t*t*t - 2*t*t + t;
        float h = t*t*t - t*t;

        x = e*p0.x + f*p3.x + g*r0.x + h*r3.x;
        y = e*p0.y + f*p3.y + g*r0.y + h*r3.y;

        putpixel(x+xc, y+yc, WHITE);
    }
}

void sign()
{
    vertex p0 = {10, 100};
    vertex p3 = {50, 100};
    vertex r0 = {10, 100};
    vertex r3 = {10, -100};
    hermite(p0, p3, r0, r3, 0, 0);      //r0, r3 represent tangent vectors

    p0 = {50, 100};
    p3 = {50, 200};
    r0 = {0, 100};
    r3 = {0, 100};
    hermite(p0, p3, r0, r3, 0, 0);

    p0 = {50, 200};
    p3 = {20, 180};
    r0 = {-20, 30};
    r3 = {-20, -40};                    //magnitude of x or y in tangent determines how much the curve flows along it
    hermite(p0, p3, r0, r3, 0, 0);      //i.e. very high magnitudes => curve follows tangent very closely at starting and ending point

    p0 = {50, 200};
    p3 = {70, 140};
    r0 = {50, -20};
    r3 = {20, -50};
    hermite(p0, p3, r0, r3, 0, 0);

    p0 = {70, 140};
    p3 = {110, 140};
    r0 = {0, 200};
    r3 = {0, -200};
    hermite(p0, p3, r0, r3, 0, 0);

    p0 = {110, 140};
    p3 = {180, 80};
    r0 = {100, 300};
    r3 = {0, -200};
    hermite(p0, p3, r0, r3, 0, 0);

    p0 = {180, 80};
    p3 = {170, 200};
    r0 = {-50, 80};
    r3 = {0, 200};
    hermite(p0, p3, r0, r3, 0, 0);

    p0 = {170, 200};
    p3 = {200, 200};
    r0 = {0, -200};
    r3 = {0, 200};
    hermite(p0, p3, r0, r3, 0, 0);

    p0 = {200, 200};
    p3 = {230, 150};
    r0 = {30, 5};
    r3 = {0, -200};
    hermite(p0, p3, r0, r3, 0, 0);

    p0 = {230, 110};
    p3 = {230, 110};
    r0 = {-30, -40};
    r3 = {-30, 40};
    hermite(p0, p3, r0, r3, 0, 0);

    p0 = {230, 150};
    p3 = {260, 150};
    r0 = {0, 350};
    r3 = {30, -10};
    hermite(p0, p3, r0, r3, 0, 0);

    p0 = {260, 150};
    p3 = {280, 200};
    r0 = {60, -60};
    r3 = {0, 100};
    hermite(p0, p3, r0, r3, 0, 0);

    p0 = {280, 200};
    p3 = {340, 200};
    r0 = {30, -180};
    r3 = {60, 240};
    hermite(p0, p3, r0, r3, 0, 0);

    p0 = {340, 200};
    p3 = {400, 160};
    r0 = {100, -50};
    r3 = {100, 90};
    hermite(p0, p3, r0, r3, 0, 0);

    p0 = {400, 160};
    p3 = {400, 165};
    r0 = {-180, -120};
    r3 = {50, -280};
    hermite(p0, p3, r0, r3, 0, 0);

    p0 = {400, 165};
    p3 = {460, 210};
    r0 = {50, 200};
    r3 = {100, -30};
    hermite(p0, p3, r0, r3, 0, 0);

    p0 = {460, 210};
    p3 = {30, 250};
    r0 = {-5, 1};
    r3 = {-5, 1};
    hermite(p0, p3, r0, r3, 0, 0);

    p0 = {30, 250};
    p3 = {420, 230};
    r0 = {10, 1};
    r3 = {10, 1};
    hermite(p0, p3, r0, r3, 0, 0);

}

void magnifywind()
{
    char ch;
    for (int i=0; i<580; i+=5)
    {
        cleardevice();
        sign();
        rectangle(i, 20, i+50, 200);
        for (int x=i; x<=i+50; x++)
        {
            for (int y=20; y<=200; y++)
            {
                if (getpixel(x,y) == WHITE)
                {
                    putpixel(1.3*x, 1.3*y+200, WHITE);
                }
            }
        }
        delay(100);
    }

}

int main()
{
    int gd=DETECT, gm=0;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    sign();
    magnifywind();

    getch();
    closegraph();
    return 0;
}
