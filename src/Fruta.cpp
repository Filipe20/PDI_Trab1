#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Fruta.hpp"

Fruta::Fruta(float x1,float y1,float z1,float raio)
{
x=x1;
y=y1;
z=z1;
r=raio;
}

void Fruta::vertex(double th2, double ph2, double raio,float xi,float yi,float zi)
{
    double xd = (raio*sin(th2 * M_PI / 180) * cos(ph2 * M_PI / 180))+xi;
    double yd = (raio*cos(th2 * M_PI / 180) * cos(ph2 * M_PI / 180))+yi;
    double zd = (raio*sin(ph2 * M_PI / 180))+zi;
    glVertex3d(xd, yd, zd);
    glNormal3f(xd, yd, zd);
}

void Fruta::vertex2(double th2, double ph2, double raio,float xi,float yi,float zi)
{
    double xd = (raio*sin(th2 * M_PI / 180) * cos(ph2 * M_PI / 180))+xi;
    double yd = (raio*cos(th2 * M_PI / 180) * cos(ph2 * M_PI / 180))+yi;
    double zd = (raio*sin(ph2 * M_PI / 180))+zi;
    glVertex3d(xd, yd, zd);
    glNormal3f(-xd, -yd, -zd);
}

// Função callback chamada para fazer o desenho
void Fruta::desenha()
{
    float rho, theta;
    int i, j;
    glColor3f(1.0f, 1.0f, 0.0f);
    
    int th2, ph2;

    glPushMatrix();
    glTranslatef(x,y,z);
    glRotatef(-45, 0, 0, 1.0);
    glTranslatef(-x,-y,-z);
    {

        //corpo fruta
        for (ph2 = -90; ph2 < 90; ph2 += 1)
        {
            glBegin(GL_TRIANGLE_STRIP);
            for (th2 = 180; th2 <= 350; th2 += 1 )
            {
                glColor3f(1, 1, 0);
                vertex(th2, ph2,r,x,y,z);
                glColor3f(1, 1, 0);
                vertex(th2, ph2 + 1,r,x,y,z); 
            }
            glEnd();
            glBegin(GL_TRIANGLE_STRIP);
            for (th2 = 0; th2 <= 180; th2 += 1 )
            {
                glColor3f(1, 1, 1);
                vertex(th2, ph2,r,x,y,z);
                glColor3f(1, 1, 1);
                vertex(th2, ph2 + 1,r,x,y,z); 
            }
            glEnd();
            
        }

        //boca pacman
        glBegin(GL_POLYGON);
        glColor3f(1, 0, 0);
        for (ph2 = -90; ph2 < 90; ph2 += 1)
        {
            vertex2(15, ph2,r,x,y,z);
        }
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(1, 0, 0);
        for (ph2 = -90; ph2 < 90; ph2 += 1)
        {
            vertex2(345, ph2,r,x,y,z);
        }

        //olhos pacman

        double rolhos=0.2,pholhos=210,tholhos=120;
        double xeye = (r*sin(tholhos * M_PI / 180) * cos(pholhos * M_PI / 180))+x;
        double yeye = (r*cos(tholhos * M_PI / 180) * cos(pholhos * M_PI / 180))+y;
        double zeye = (r*sin(pholhos* M_PI / 180))+z;


        for (ph2 = -90; ph2 < 90; ph2 += 1)
        {
            
            glBegin(GL_TRIANGLE_STRIP);
            for (th2 = 0; th2 <= 360; th2 += 1 )
            {
                glColor3f(0.8, 0.8, 1);
                vertex(th2, ph2,rolhos,xeye,yeye,zeye);
                glColor3f(0.8, 0.8, 1);
                vertex(th2, ph2 + 1,rolhos,xeye,yeye,zeye); 
            }
            glEnd();
            
        }

        pholhos=150;
        tholhos=120;

        xeye = (r*sin(tholhos * M_PI / 180) * cos(pholhos * M_PI / 180))+x;
        yeye = (r*cos(tholhos * M_PI / 180) * cos(pholhos * M_PI / 180))+y;
        zeye = (r*sin(pholhos * M_PI / 180))+z;


        for (ph2 = -90; ph2 < 90; ph2 += 1)
        {
            
            glBegin(GL_TRIANGLE_STRIP);
            for (th2 = 0; th2 <= 360; th2 += 1 )
            {
                glColor3f(0.8, 0.8, 1);
                vertex(th2, ph2,rolhos,xeye,yeye,zeye);
                glColor3f(0.8, 0.8, 1);
                vertex(th2, ph2 + 1,rolhos,xeye,yeye,zeye); 
            }
            glEnd();
            
        }


        
    glEnd();
    }
    glPopMatrix();
    
}


float* Fruta::hitbox()
{
    float* param;
    param[0]=x;
    param[1]=z;
    param[2]=r;
    return param;

}

Fruta::~Fruta()
{
    
}