#include <GL/glut.h>
#include <stdio.h>
#include <cmath>

//quadrado vermelho
float translateY = 0.0f;
//quadrador roxo
float translateX = -5.0f;
float speed = 0.03f;
//circulo
float angle = 0.0f;


void barco() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Define o fundo bege
    glClearColor(0.96f, 0.89f, 0.76f, 1.0f);

    // Base vermelha (barco)
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-4.0f, -4.0f);  // Esquerda inferior
    glVertex2f(4.0f, -4.0f);   // Direita inferior
    glVertex2f(6.0f, -2.0f);   // Direita superior
    glVertex2f(-6.0f, -2.0f);  // Esquerda superior
    glEnd();

    // Vela cinza
    glColor3f(0.75f, 0.75f, 0.75f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 6.0f);    // Topo da vela
    glVertex2f(-4.0f, -1.0f);   // Base esquerda da vela
    glVertex2f(4.0f, -1.0f);   // Base direita da vela
    glEnd();

    // Mastro marrom
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2f, -2.0f);  // Base esquerda do mastro
    glVertex2f(0.2f, -2.0f);   // Base direita do mastro
    glVertex2f(0.2f, 6.0f);    // Topo direito do mastro
    glVertex2f(-0.2f, 6.0f);   // Topo esquerdo do mastro
    glEnd();

    // Bandeira azul
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.2f, 6.0f);    // Topo esquerdo da bandeira
    glVertex2f(2.0f, 6.0f);    // Topo direito da bandeira
    glVertex2f(2.0f, 5.5f);    // Base direita da bandeira
    glVertex2f(0.2f, 5.5f);    // Base esquerda da bandeira
    glEnd();

    glFlush();
}
void olhoGrego() {
    glClear(GL_COLOR_BUFFER_BIT);

    //fundo branco
    glClearColor(1, 1, 1, 1);
    // Define as cores para os círculos concêntricos
    float cores[][3] = {
        {0.0f, 0.0f, 0.0f},  // Preto (círculo externo)
        {0.0f, 0.0f, 0.5f},  // Azul escuro
        {1.0f, 1.0f, 1.0f}   // Branco (círculo interno)
    };

    // Raios dos círculos
    float raios[] = { 8.0f, 5.0f, 2.0f };

    // Desenha os círculos concêntricos
    for (int i = 0; i < 3; i++) {
        glColor3f(cores[i][0], cores[i][1], cores[i][2]);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f);  // Centro do círculo
        for (int j = 0; j <= 360; j++) {
            float angulo = j * 3.14159f / 180.0f;
            glVertex2f(cos(angulo) * raios[i], sin(angulo) * raios[i]);
        }
        glEnd();
    }

    glFlush();
}

void quadradoVermelho () {
    glClear(GL_COLOR_BUFFER_BIT);  // Limpa o buffer de cor

    //fundo branco
    glClearColor(1, 1, 1, 1);
    glLoadIdentity();  // Carrega a matriz identidade

    // Aplica a translação no eixo Y
    glTranslatef(0.0f, translateY, 0.0f);

    // Desenha o quadrado vermelho
    glColor3f(1.0, 0.0, 0.0);  // Cor vermelha
    glBegin(GL_QUADS);  // Começa a desenhar um quadrado
    glVertex2f(-0.5f, -0.5f);  // Ponto inferior esquerdo
    glVertex2f(0.5f, -0.5f);  // Ponto inferior direito
    glVertex2f(0.5f, 0.5f);  // Ponto superior direito
    glVertex2f(-0.5f, 0.5f);  // Ponto superior esquerdo
    glEnd();

    glutSwapBuffers();  // Troca os buffers para exibir a imagem
}
void handleKeys(unsigned char key, int x, int y) {
    if (key == 32) {  // Verifica se a tecla pressionada é a barra de espaço (código 32)
        translateY += 0.1f;  // Translação para cima
        glutPostRedisplay();  // Solicita que a tela seja redesenhada
    }
}
void quadradoRoxo() {
    glClear(GL_COLOR_BUFFER_BIT);  // Limpa o buffer de cor

    //fundo branco
    glClearColor(1, 1, 1, 1);
    glLoadIdentity();  // Carrega a matriz identidade

    // Aplica a translação no eixo X
    glTranslatef(translateX, 0.0f, 0.0f);

    // Desenha o quadrado roxo
    glColor3f(0.5, 0.0, 0.5);  // Cor roxa
    glBegin(GL_QUADS);  // Começa a desenhar um quadrado
    glVertex2f(-0.5f, -0.5f);  // Ponto inferior esquerdo
    glVertex2f(0.5f, -0.5f);  // Ponto inferior direito
    glVertex2f(0.5f, 0.5f);  // Ponto superior direito
    glVertex2f(-0.5f, 0.5f);  // Ponto superior esquerdo
    glEnd();

    glutSwapBuffers();  // Troca os buffers para exibir a imagem
}
void update(int value) {
    translateX += speed;  // Atualiza a posição do quadrado no eixo X

    // Verifica se o quadrado chegou ao limite da janela e inverte a direção
    if (translateX > 9.0f || translateX < -9.0f) {
        speed = -speed;  // Inverte a direção do movimento
    }

    glutPostRedisplay();  // Solicita a atualização da tela

    // Chama a função de animação novamente após 16ms (~60fps)
    glutTimerFunc(16, update, 0);
}
void circuloGay() {
    glClear(GL_COLOR_BUFFER_BIT);  // Limpa o buffer de cor

    //fundo branco
    glClearColor(1, 1, 1, 1);
    glLoadIdentity();  // Carrega a matriz identidade

    glTranslatef(0.0f, 0.0f, 0.0f);  // Mantém o círculo no centro da tela

    // Aplica a rotação no sentido horário
    glRotatef(angle, 0.0f, 0.0f, 1.0f);  // Rotaciona no eixo Z (sentido horário)

    int numSegments = 100;  // Número de segmentos do círculo
    float radius = 0.8f;  // Raio do círculo

    // Desenha o círculo multicolorido
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);  // Centro do círculo

    // Dividir o círculo em segmentos coloridos
    for (int i = 0; i <= numSegments; i++) {
        // Calcula o ângulo do ponto
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);

        // Define a cor com base no ângulo
        glColor3f((cosf(theta) + 1.0f) / 2.0f, (sinf(theta) + 1.0f) / 2.0f, 0.5f);  // Cor baseada no ângulo

        glVertex2f(x, y);  // Vértice do círculo
    }
    glEnd();

    glutSwapBuffers();  // Troca os buffers para exibir a imagem
}
void updateCircle(int value) {
    angle -= 5.f;  // A rotação no sentido horário (sentido negativo no eixo Z)
    if (angle <= -360.0f) {
        angle = 0.0f;  // Reseta o ângulo para evitar overflow
    }

    glutPostRedisplay();  // Solicita a atualização da tela

    glutTimerFunc(16, update, 0);  // Atualiza a animação a cada 16ms (~60fps)
}

void init() {
    // Configuração do sistema de coordenadas 2D
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    printf("selecione a atividade a executar \n\n");
    printf("(1) barco\n");
    printf("(2) olho grego\n");
    printf("(3) quadrado vermelho\n");
    printf("(4) quadrado roxo\n");
    printf("(5) circulo multicolorido\n");
    int chose;
    while (1) {
        if (scanf_s("%d", &chose) == 1 && chose >= 1 && chose <= 5) {
            break;
        }
        else {
            printf("Opção inválida! Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        }
    }

    switch (chose) {
    case 1:
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutCreateWindow("barco");
        init();  // Inicializa o sistema de coordenadas
        glutDisplayFunc(barco);
        glutMainLoop();
        break;
    case 2:
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutCreateWindow("olho grego");
        init();  // Inicializa o sistema de coordenadas
        glutDisplayFunc(olhoGrego);
        glutMainLoop();
        break;
    case 3:
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  // Modo de exibição com dupla troca de buffers e RGB
        glutInitWindowSize(500, 500);  // Tamanho da janela
        glutCreateWindow("Quadrado Vermelho");  // Criação da janela
        init();  // Inicializa as configurações do OpenGL
        glutDisplayFunc(quadradoVermelho);  // Função de desenho
        glutKeyboardFunc(handleKeys);  // Função para capturar teclas

        glutMainLoop();  // Inicia o loop principal do GLUT
        break;
    case 4:
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  // Modo de exibição com dupla troca de buffers e RGB
        glutInitWindowSize(500, 500);  // Tamanho da janela
        glutCreateWindow("Quadrado Roxo");  // Criação da janela
        init();  // Inicializa as configurações do OpenGL
        glutDisplayFunc(quadradoRoxo);  // Função de desenho
        glutTimerFunc(25, update, 0);  // Inicia o loop de animação com intervalo de 25ms (~40fps)
        glutMainLoop();  // Inicia o loop principal do GLUT
        break;
    case 5:
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  // Modo de exibição com dupla troca de buffers e RGB
        glutInitWindowSize(500, 500);  // Tamanho da janela
        glutCreateWindow("Circulo gay");  // Criação da janela
        init();  // Inicializa as configurações do OpenGL
        glutDisplayFunc(circuloGay);  // Função de desenho
        glutTimerFunc(25, updateCircle, 0);  // Inicia o loop de animação

        glutMainLoop();  // Inicia o loop principal do GLUT
        break;
    }
    return 0;
}
