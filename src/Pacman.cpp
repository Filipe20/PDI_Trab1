#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Pacman.hpp"

Pacman::Pacman(float x1,float y1,float z1,float raio)
{
x=x1;
y=y1;
z=z1;
r=raio;
}

void Pacman::vertex(double th2, double ph2, double raio,float xi,float yi,float zi)
{
    double xd = (raio*sin(th2 * M_PI / 180) * cos(ph2 * M_PI / 180))+xi;
    double yd = (raio*cos(th2 * M_PI / 180) * cos(ph2 * M_PI / 180))+yi;
    double zd = (raio*sin(ph2 * M_PI / 180))+zi;
    glVertex3d(xd, yd, zd);
    glNormal3f(xd, yd, zd);
}

void Pacman::vertex2(double th2, double ph2, double raio,float xi,float yi,float zi)
{
    double xd = (raio*sin(th2 * M_PI / 180) * cos(ph2 * M_PI / 180))+xi;
    double yd = (raio*cos(th2 * M_PI / 180) * cos(ph2 * M_PI / 180))+yi;
    double zd = (raio*sin(ph2 * M_PI / 180))+zi;
    glVertex3d(xd, yd, zd);
    glNormal3f(-xd, -yd, -zd);
}

// Função callback chamada para fazer o desenho
void Pacman::desenha()
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
        //rotação pacman
        if(direc==1)
        {
        glTranslatef(x,y,z);
        glRotatef(-90, 1, 0, 0);
        glTranslatef(-x,-y,-z);
        direcimag=1;
        }
        else if(direc==2)
        {
        glTranslatef(x,y,z);
        glRotatef(-270, 1, 0, 0);
        glTranslatef(-x,-y,-z);
        direcimag=2;
        }

        else if(direc==3)
        {
        glTranslatef(x,y,z);
        glRotatef(-180, 1, 0, 0);
        glTranslatef(-x,-y,-z);
        direcimag=3;
        }

        else if(direc==4)
        {
        direcimag=4;
        }

        else
        {
        if(direcimag==1)
        {
        glTranslatef(x,y,z);
        glRotatef(-90, 1, 0, 0);
        glTranslatef(-x,-y,-z);
        }

        else if(direcimag==2)
        {
        glTranslatef(x,y,z);
        glRotatef(-270, 1, 0, 0);
        glTranslatef(-x,-y,-z);
        }

        else if(direcimag==3)
        {
        glTranslatef(x,y,z);
        glRotatef(-180, 1, 0, 0);
        glTranslatef(-x,-y,-z);
        }
        }



        //corpo pacman
        for (ph2 = -90; ph2 < 90; ph2 += 1)
        {
            //abre e fecha boca
            if(((direc==3||direc==4)&&(int(x*37)%2)==0)||((direc==1||direc==2)&&(int(z*3)%2)==0))
            {
            glBegin(GL_TRIANGLE_STRIP);
            for (th2 = 15; th2 <= 345; th2 += 1 )
            {
                glColor3f(1, 1, 0);
                vertex(th2, ph2,r,x,y,z);
                glColor3f(1, 1, 0);
                vertex(th2, ph2 + 1,r,x,y,z); 
            }
            glEnd();
            }
            else
            {
            glBegin(GL_TRIANGLE_STRIP);
            for (th2 = 0; th2 <= 360; th2 += 1 )
            {
                glColor3f(1, 1, 0);
                vertex(th2, ph2,r,x,y,z);
                glColor3f(1, 1, 0);
                vertex(th2, ph2 + 1,r,x,y,z); 
            }
            glEnd();
            }
            
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
                glColor3f(1, 0, 0);
                vertex(th2, ph2,rolhos,xeye,yeye,zeye);
                glColor3f(1, 0, 0);
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
                glColor3f(10, 0, 0);
                vertex(th2, ph2,rolhos,xeye,yeye,zeye);
                glColor3f(10, 0, 0);
                vertex(th2, ph2 + 1,rolhos,xeye,yeye,zeye); 
            }
            glEnd();
            
        }


        
    glEnd();
    }
    glPopMatrix();
    
}

void Pacman::direcao(int key)
{
    switch (key) {
            case GLUT_KEY_RIGHT :
                            direc=1;
				            break;
			case GLUT_KEY_LEFT : 
                            direc=2;                         
							break;
			case GLUT_KEY_UP :
                            direc=3;
							break;
			case GLUT_KEY_DOWN : 
							direc=4;
							break;
    }

}

void Pacman::move()
{
    if(direc==1)
    {
        z=z-0.8;
    }
    else if(direc==2)
    {
        z=z+0.8;
    }
    else if(direc==3)
    {
        x=x-0.8;
    }
    else if(direc==4)
    {
        x=x+0.8;
    }
}

void Pacman::stop(int bateu)
{


    if(bateu==1)
    {
        x=x-0.1;
        direc=0;
    }

    if(bateu==2)
    {
        x=x+0.1;
        direc=0;
    }

    if(bateu==3)
    {
        z=z-0.1;
        direc=0;
    }
    if(bateu==4)
    {
        z=z+0.1;
        direc=0;
    }



}

float* Pacman::hitbox()
{
    float* param;
    param[0]=x;
    param[1]=z;
    param[2]=r;
    return param;

}

Pacman::~Pacman()
{
    
}