#include <windows.h>
#include <GL/glut.h>
#include <cstdio>
#include <cmath>
#include <utility>
#include <vector>


double x_min, y_min, x_max, y_max;
double line_x1, line_y1, line_x2, line_y2;

int final_point_count = 0;
std::pair<double, double> final_p1;
std::pair<double, double> final_p2;

/* GLUT callback Handlers */
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
    glColor3f(1, 1, 1);

    // line 1
    glVertex2f(x_min, 1);
    glVertex2f(x_min, -1);

    // line 2
    glVertex2f(x_max, 1);
    glVertex2f(x_max, -1);

    // line 3
    glVertex2f(1, y_max);
    glVertex2f(-1, y_max);

    // line 4
    glVertex2f(1, y_min);
    glVertex2f(-1, y_min);

    glColor3f(1, 0, 0);
    // inspected line
    glVertex2f(line_x1, line_y1);
    glVertex2f(line_x2, line_y2);

    if(final_point_count == 2){
        glColor3f(0, 1, 0);
        // accepted line
        /*
        printf("%lf %lf\n", final_p1.first, final_p1.second);
        printf("%lf %lf\n", final_p2.first, final_p2.second);
        */
        glVertex2f(final_p1.first, final_p1.second);
        glVertex2f(final_p2.first, final_p2.second);
    }

    glEnd();

    glFlush();
}


void clip_line(std::pair<double, double> &p1, std::pair<double, double> &p2)
{
    double x1 = p1.first, y1 = p1.second, x2 = p2.first, y2 = p2.second;
    double xmin = x_min, xmax = x_max, ymin = y_min, ymax = y_max;
    double x3, y3, x4, y4;
    int flag1, flag2;

    //inside
    if(x1>=xmin && x1<=xmax && y1>=ymin && y1<=ymax)
    {
        printf("%f %f\n", x1, y1);
        flag1 = 0;

        final_p1.first = x1;
        final_p1.second = y1;

        final_point_count++;
    }


    //up-left
    else if(x1<xmin && y1>ymax)
    {
        flag1 = 1;
        x3 = xmin;
        y3 = y1+(y2-y1)*((xmin-x1)/(x2-x1));
        if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax)
        {
            printf("%f %f\n", x3, y3);
            final_p1.first = x3;
            final_p1.second = y3;

            final_point_count++;
        }
        x4 = x1+(x2-x1)*((ymax-y1)/(y2-y1));
        y4 = ymax;
        if(x4>=xmin && x4<=xmax && y4>=ymin && y4<=ymax)
        {
            printf("%f %f\n", x4, y4);
            final_p1.first = x4;
            final_p1.second = y4;

            final_point_count++;
        }
    }


    //up-right
    else if(x1>xmax && y1>ymax)
    {
        flag1 = 2;
        x3 = xmax;
        y3 = y1+(y2-y1)*((xmax-x1)/(x2-x1));
        if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax)
        {
            printf("%f %f\n", x3, y3);
            final_p1.first = x3;
            final_p1.second = y3;

            final_point_count++;
        }
        x4 = x1+(x2-x1)*((ymax-y1)/(y2-y1));
        y4 = ymax;
        if(x4>=xmin && x4<=xmax && y4>=ymin && y4<=ymax)
        {
            printf("%f %f\n", x4, y4);
            final_p1.first = x4;
            final_p1.second = y4;

            final_point_count++;
        }
    }


    //down-left
    else if(x1<xmin && y1<ymin)
    {
        flag1 = 3;
        x3 = xmin;
        y3 = y1+(y2-y1)*((xmin-x1)/(x2-x1));
        if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax)
        {
            printf("%f %f\n", x3, y3);
            final_p1.first = x3;
            final_p1.second = y3;

            final_point_count++;
        }
        x4 = x1+(x2-x1)*((ymin-y1)/(y2-y1));
        y4 = ymin;
        if(x4>=xmin && x4<=xmax && y4>=ymin && y4<=ymax)
        {
            printf("%f %f\n", x4, y4);
            final_p1.first = x4;
            final_p1.second = y4;

            final_point_count++;
        }
    }


    //down-right
    else if(x1>xmax && y1<ymin)
    {
        flag1 = 4;
        x3 = xmax;
        y3 = y1+(y2-y1)*((xmax-x1)/(x2-x1));
        if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax)
        {
            printf("%f %f\n", x3, y3);
            final_p1.first = x3;
            final_p1.second = y3;

            final_point_count++;
        }
        x4 = x1+(x2-x1)*((ymin-y1)/(y2-y1));
        y4 = ymin;
        if(x4>=xmin && x4<=xmax && y4>=ymin && y4<=ymax)
        {
            printf("%f %f\n", x4, y4);
            final_p1.first = x4;
            final_p1.second = y4;

            final_point_count++;
        }
    }
    //up
    else if(y1>ymax)
    {
        flag1 = 5;
        x3 = x1+(x2-x1)*((ymax-y1)/(y2-y1));
        y3 = ymax;
        if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax)
        {
            printf("%f %f\n", x3, y3);
            final_p1.first = x3;
            final_p1.second = y3;

            final_point_count++;
        }
    }
    //left
    else if(x1<xmin)
    {
        flag1 = 6;
        x3 = xmin;
        y3 = y1+(y2-y1)*((xmin-x1)/(x2-x1));
        if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax)
        {
            printf("%f %f\n", x3, y3);
            final_p1.first = x3;
            final_p1.second = y3;

            final_point_count++;
        }
    }
    //down
    else if(y1<ymin)
    {
        flag1 = 7;
        x3 = x1+(x2-x1)*((ymin-y1)/(y2-y1));
        y3 = ymin;
        if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax)
        {
            printf("%f %f\n", x3, y3);
            final_p1.first = x3;
            final_p1.second = y3;

            final_point_count++;
        }
    }
    //right
    else if(x1>xmax)
    {
        flag1 = 8;
        x3 = xmax;
        y3 = y1+(y2-y1)*((xmax-x1)/(x2-x1));
        if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax)
        {
            printf("%f %f\n", x3, y3);
            final_p1.first = x3;
            final_p1.second = y3;

            final_point_count++;
        }
    }




    //Second point
    //inside
    if(x2>=xmin && x2<=xmax && y2>=ymin && y2<=ymax)
    {
        printf("%f %f\n", x2, y2);
        flag2 = 0;
        final_p2.first = x2;
        final_p2.second = y2;

        final_point_count++;
    }


    //up-left
    else if(x2<xmin && y2>ymax)
    {
        flag2 = 1;
        x3 = xmin;
        y3 = y1+(y2-y1)*((xmin-x1)/(x2-x1));
        if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax)
        {
            printf("%f %f\n", x3, y3);
            final_p2.first = x3;
            final_p2.second = y3;

            final_point_count++;
        }
        x4 = x1+(x2-x1)*((ymax-y1)/(y2-y1));
        y4 = ymax;
        if(x4>=xmin && x4<=xmax && y4>=ymin && y4<=ymax)
        {
            printf("%f %f\n", x4, y4);
            final_p2.first = x4;
            final_p2.second = y4;

            final_point_count++;
        }
    }


    //up-right
    else if(x2>xmax && y2>ymax)
    {
        flag2 = 2;
        x3 = xmax;
        y3 = y1+(y2-y1)*((xmax-x1)/(x2-x1));
        if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax)
        {
            printf("%f %f\n", x3, y3);
            final_p2.first = x3;
            final_p2.second = y3;

            final_point_count++;
        }
        x4 = x1+(x2-x1)*((ymax-y1)/(y2-y1));
        y4 = ymax;
        if(x4>=xmin && x4<=xmax && y4>=ymin && y4<=ymax)
        {
            printf("%f %f\n", x4, y4);
            final_p2.first = x4;
            final_p2.second = y4;

            final_point_count++;
        }
    }


    //down-left
    else if(x1<xmin && y1<ymin)
    {
        flag2 = 3;
        x3 = xmin;
        y3 = y1+(y2-y1)*((xmin-x1)/(x2-x1));
        if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax)
        {
            printf("%f %f\n", x3, y3);
            final_p2.first = x3;
            final_p2.second = y3;

            final_point_count++;
        }
        x4 = x1+(x2-x1)*((ymin-y1)/(y2-y1));
        y4 = ymin;
        if(x4>=xmin && x4<=xmax && y4>=ymin && y4<=ymax)
        {
            printf("%f %f\n", x4, y4);
            final_p2.first = x4;
            final_p2.second = y4;

            final_point_count++;
        }
    }


    //down-right
    else if(x2>xmax && y2<ymin)
    {
        flag2 = 4;
        x3 = xmax;
        y3 = y1+(y2-y1)*((xmax-x1)/(x2-x1));
        if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax)
        {
            printf("%f %f\n", x3, y3);
            final_p2.first = x3;
            final_p2.second = y3;

            final_point_count++;
        }
        x4 = x1+(x2-x1)*((ymin-y1)/(y2-y1));
        y4 = ymin;
        if(x4>=xmin && x4<=xmax && y4>=ymin && y4<=ymax)
        {
            printf("%f %f\n", x4, y4);
            final_p2.first = x4;
            final_p2.second = y4;

            final_point_count++;
        }
    }
    //up
    else if(y2>ymax)
    {
        flag2 = 5;
        x3 = x1+(x2-x1)*((ymax-y1)/(y2-y1));
        y3 = ymax;
        if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax)
        {
            printf("%f %f\n", x3, y3);
            final_p2.first = x3;
            final_p2.second = y3;

            final_point_count++;
        }
    }
    //left
    else if(x2<xmin)
    {
        flag2 = 6;
        x3 = xmin;
        y3 = y1+(y2-y1)*((xmin-x1)/(x2-x1));
        if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax)
        {
            printf("%f %f\n", x3, y3);
            final_p2.first = x3;
            final_p2.second = y3;

            final_point_count++;
        }
    }
    //down
    else if(y2<ymin)
    {
        flag2 = 7;
        x3 = x1+(x2-x1)*((ymin-y1)/(y2-y1));
        y3 = ymin;
        if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax)
        {
            printf("%f %f\n", x3, y3);
            final_p2.first = x3;
            final_p2.second = y3;

            final_point_count++;
        }
    }
    //right
    else if(x2>xmax)
    {
        flag2 = 8;
        x3 = xmax;
        y3 = y1+(y2-y1)*((xmax-x1)/(x2-x1));
        if(x3>=xmin && x3<=xmax && y3>=ymin && y3<=ymax)
        {
            printf("%f %f\n", x3, y3);
            final_p2.first = x3;
            final_p2.second = y3;

            final_point_count++;
        }
    }


    printf("%d %d\n", flag1, flag2);
}

/* Program entry point */

int main(int argc, char **argv)
{
    scanf("%lf %lf %lf %lf", &x_min, &y_min, &x_max, &y_max);
    scanf("%lf %lf %lf %lf", &line_x1, &line_y1, &line_x2, &line_y2);

    std::pair<double, double> point1(line_x1, line_y1);
    std::pair<double, double> point2(line_x2, line_y2);

    /*
    std::vector<std::pair<double, double> > points;
    points.push_back(point1);
    points.push_back(point2);
    clip(points);
    */

    clip_line(point1, point2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("Kush");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
