// Jogo PacMan
// Jogo.cpp
// Prof. Giovani Bernardes Vitor
// ECO034 - 2018

#include <stdlib.h>
#include <stdio.h>
#include "jogo.hpp"

///////////////////////////////////////////////////////////////////////
// Jogo Class
Jogo::Jogo(int argc, char **argv)
{
    fruta = new Fruta(0, 1, 0, 1);
    pacman = new Pacman(0, 1, 0, 1);
    fantasma = new Fantasma(0, 1, 0, 1, 1.5);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(450, 400);
    glutCreateWindow("PACMAN GAME");
    Inicializa();
    insere_objetos();
}

//---------------------------------------------------------------------
Jogo::~Jogo()
{
}
//---------------------------------------------------------------------
void Jogo::Inicializa(void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

//---------------------------------------------------------------------
//void Jogo::DisplayFunc()
//{
//	glutDisplayFunc(Jogo::Desenha);
//}
//---------------------------------------------------------------------

void Jogo::desenha()
{
    //     glMatrixMode(GL_MODELVIEW);
    //     glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    pacman->desenha();
    fantasma->desenha();
    //fruta->desenha();

    for (list<Objetos *>::const_iterator it = mapa_.begin(); it != mapa_.end(); it++)
    {
        (*it)->desenha();
    }

    glutPostRedisplay();
    glutSwapBuffers();
}

//---------------------------------------------------------------------
void Jogo::atualizatamanho(GLsizei w, GLsizei h)
{
    // Especifica as dimensões da Viewport
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    fAspect = (GLfloat)w / (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angle, fAspect, 0.5, 500.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(40, 90, 0, 0, 0, 0, 0, 1, 0);
    glutPostRedisplay();
}

//---------------------------------------------------------------------
void Jogo::KeyboardHandle(unsigned char key, int x, int y)
{

    switch (key)
    {
        break;
    case 'R':
    case 'r': // muda a cor corrente para vermelho
        glColor3f(1.0f, 0.0f, 0.0f);
        break;
    case 'G':
    case 'g': // muda a cor corrente para verde
        glColor3f(0.0f, 1.0f, 0.0f);
        break;
    case 'B':
    case 'b': // muda a cor corrente para azul
        glColor3f(0.0f, 0.0f, 1.0f);
        time++;
        for (list<Objetos *>::const_iterator it = mapa_.begin(); it != mapa_.end(); ++it)
        {
            (*it)->atualiza(time);
        }
        break;
    case 27: // tecla Esc (encerra o programa)
        exit(0);
        break;
    }
    //glutPostRedisplay();
}

//---------------------------------------------------------------------
void Jogo::MouseHandle(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
        if (state == GLUT_DOWN)
        {
            // Troca o tamanho do retângulo, que vai do centro da
            // janela até a posição onde o usuário clicou com o mouse
            //xf = ( (2 * win * x) / view_w) - win;
            //yf = ( ( (2 * win) * (y-view_h) ) / -view_h) - win;
        }
    //glutPostRedisplay();
}

//---------------------------------------------------------------------
void Jogo::SpecialKeyHandle(int key, int x, int y)
{
    pacman->direcao(key);
    //glutPostRedisplay();
}
//---------------------------------------------------------------------
void Jogo::atualiza(int value, void (*func_ptr)(int))
{
    //time++;
    //std::cout << " Time: " << time << std::endl;

    //angle+=2.0f;

    //if(angle>360.f)
    //  angle-=360;
    float *coord = pacman->hitbox();
    int bateu;
    for (list<Objetos *>::const_iterator it = mapa_.begin(); it != mapa_.end(); it++)
    {
        bateu = (*it)->colisao(coord[0], coord[1], coord[2]);
        pacman->stop(bateu);
    }
    pacman->move();
    fantasma->animacao();
    glutPostRedisplay();
    glutTimerFunc(20, func_ptr, time);
}
//---------------------------------------------------------------------
bool Jogo::insere_objetos(void)
{
    Parede *obj;
    //Objects * node = reinterpret_cast<Objects*>(obj);

    // Paredes Laterais ---------------------------------------
    mapa_.push_back(new Parede(0, 5, 30, 60, parede,h));
    mapa_.push_back(new Parede(30.5, 5, 0, parede, 61,h));
    mapa_.push_back(new Parede(-30.5, 5, 0, parede, 61,h));
    mapa_.push_back(new Parede(0, 5, -30, 60, parede,h));
    // --------------------------------------------------------

    // segunda parede -----------------------------------------
    mapa_.push_back(new Parede(0, 5, 26.5, 54, parede,h));
    mapa_.push_back(new Parede(0, 5, -26.5, 54, parede,h));
    mapa_.push_back(new Parede(26.7, 5, 0, parede, 46,h));
    mapa_.push_back(new Parede(-26.7, 5, 0, parede, 46,h));
    // --------------------------------------------------------

    // paredes verticais -------------------------------
    for (int i = 0; i < 6; i++)
    {
        if (i == 0)
            a = 1;
        else if (i == 1)
            a = -1;
        else if (i == 2)
        {
            b = 3.5;
            a = 1;
        }
        else if (i == 3)
        {
            a = -1;
            b = -3.5;
        }
        else if (i == 4)
        {
            b = 2 * 3.5;
            a = 1;
        }
        else
        {
            a = -1;
            b = -2 * 3.5;
        }

        for (int j = -2; j < 3; j++)
        {
            mapa_.push_back(new Parede(j * 10, 5, (a * 22 - b), 7.5, parede,h));
        }
    }
    // --------------------------------------------------------
    a = 1, b = 0;
    //paredes da horizontal -------------------------------
    for (int i = 0; i < 4; i++)
    {
        if(i == 0)
        b = 0;
        else if (i == 1)
        {
            b = 10.2;
            a = 1;
        }
        else if (i == 2)
        {
            a = -1;
            b = 0;
        }
        else
        b = -10.2;

        mapa_.push_back(new Parede(a * 23.4 - b, 5, 0, parede, 24,h));
        mapa_.push_back(new Parede(a * 16.6 - b, 5, 0, parede, 24,h));
        mapa_.push_back(new Parede(a * 20 - b, 5, 6.6, parede, 11,h));
        mapa_.push_back(new Parede(a * 20 - b, 5, -6.6, parede, 11,h));
    }
    // ----------------------------------------------------------
    


    // ECO ----------------------------------------------------
    mapa_.push_back(new Parede(3, 5, 0, parede, 4,h));
    mapa_.push_back(new Parede(-3, 5, 0, parede, 4,h));
    mapa_.push_back(new Parede(3, 5, 7, parede, 4,h));
    mapa_.push_back(new Parede(-3, 5, 7, parede, 4,h));
    mapa_.push_back(new Parede(0, 5, 7, parede, 4,h));
    mapa_.push_back(new Parede(3, 5, -7, parede, 4,h));
    mapa_.push_back(new Parede(-3, 5, -7, parede, 4,h));

    mapa_.push_back(new Parede(0, 5, 9, 6, parede,h));
    mapa_.push_back(new Parede(0, 5, -9, 6, parede,h));
    mapa_.push_back(new Parede(0, 5, -5, 6, parede,h));
    mapa_.push_back(new Parede(0, 5, 2, 6, parede,h));
    // --------------------------------------------------------

    std::cout << " insert: " << mapa_.size() << std::endl;

    return true;
}