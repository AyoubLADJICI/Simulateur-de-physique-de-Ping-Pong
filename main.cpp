#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/glu.h>  // Ajoute les fonctions GLU pour la caméra et la perspective
#include "classes.hpp"
#include <chrono>
#include <cmath>


using namespace std;

// ====================== CONSTANTES =====================
const float GRAVITY = 9.81f;
constexpr std::chrono::milliseconds pas_t(1); // pas de 1ms
float dt = std::chrono::duration_cast<std::chrono::milliseconds>(pas_t).count() / 500.0f;


// ====================== INITIALISATION OPENGL =====================
void initOpenGL() {
    glEnable(GL_DEPTH_TEST); // Active le test de profondeur (3D)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 800.0 / 600.0, 0.1, 5000.0); // Perspective 3D
    glMatrixMode(GL_MODELVIEW);
}

// ====================== DESSIN DE LA TABLE =====================
void drawTable() {
    glColor3f(0.2f, 0.6f, 0.3f); // Vert foncé (table)
    glBegin(GL_QUADS);
    glVertex3f(-table::LARGEUR / 2, -table::LONGUEUR / 2, 1.0f); // Légère élévation
    glVertex3f(table::LARGEUR / 2, -table::LONGUEUR / 2, 1.0f);
    glVertex3f(table::LARGEUR / 2, table::LONGUEUR / 2, 1.0f);
    glVertex3f(-table::LARGEUR / 2, table::LONGUEUR / 2, 1.0f);
    glEnd();
}

// ====================== DESSIN DE LA BALLE =====================
void drawBall(coo position) {
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);

    glColor3f(1.0f, 0.0f, 0.0f);  // Rouge

    GLUquadric* quad;
    quad = gluNewQuadric();
    gluSphere(quad, balle::RAYON * 3, 20, 20);  // Augmentation de la taille

    gluDeleteQuadric(quad);
    glPopMatrix();
}


// ============================= MAIN ===============================
int main() {
    // Initialisation GLFW
    if (!glfwInit()) return -1;
    GLFWwindow* window = glfwCreateWindow(800, 600, "Simulation Ping-Pong 3D", NULL, NULL);
    if (!window) { glfwTerminate(); return -1; }
    glfwMakeContextCurrent(window);
    initOpenGL();

    // Initialisation de la balle
    balle b(0, 0, 200); // Position initiale haute
    float dt = std::chrono::duration_cast<std::chrono::milliseconds>(pas_t).count() / 20.0;// Conversion en secondes

    // Boucle de rendu OpenGL
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        // Position de la caméra
        gluLookAt(0, -500, 100,  // Position de la caméra (face à la table)
          0, 0, 50,      // Point que la caméra regarde (centre de la table)
          0, 0, 1);      // Orientation (haut)

        // Mettre à jour la position de la balle
        b.updatePosition(dt);

        // Dessiner la table et la balle
        drawTable();
        drawBall(b.getPosition());

        // Rafraîchir l'affichage
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
// ============================= FIN ===============================