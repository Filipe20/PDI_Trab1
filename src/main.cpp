// Jogo PacMan 
// main.cpp
// Prof. Giovani Bernardes Vitor
// ECO034 - 2018



#include <iostream>
#include <thread>

#include "jogo.hpp"

Jogo *ptr_;

void desenha() {ptr_->desenha();}
void atualizatamanho(GLsizei w, GLsizei h) {ptr_->atualizatamanho(w, h);}
void KeyboardHandle(unsigned char key, int x, int y){ptr_->KeyboardHandle(key, x, y);}
void MouseHandle(int button, int state, int x, int y){ptr_->MouseHandle(button, state, x, y);}
void SpecialKeyHandle(int key, int x, int y){ptr_->SpecialKeyHandle(key, x, y);}
void atualiza(int value){ptr_->atualiza(value,&atualiza);}

     
// Programa Principal 
int main(int argc, char** argv)
{
     int time=0;

     Jogo app(argc,argv);
     ptr_ = &app;

     glutDisplayFunc(desenha);
     glutReshapeFunc(atualizatamanho);
     glutKeyboardFunc(KeyboardHandle);
     glutMouseFunc(MouseHandle);
     glutSpecialFunc(SpecialKeyHandle); 
     glutTimerFunc(20,atualiza,time);
     glutMainLoop();

     return 0;
}
