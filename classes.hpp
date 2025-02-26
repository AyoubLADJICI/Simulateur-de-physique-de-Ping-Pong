#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>
#include <string>

using namespace std;

// Structure pour représenter une position dans l'espace
struct coo {
    float x, y, z;
    string toString() const;
};

// Structure pour la vitesse (3D)
struct vitesse {
    float vx, vy, vz;
    string toString() const;
};

// Structure pour l'accélération (3D)
struct acc {
    float ax, ay, az;
    string toString() const;
};

// Classe pour le jeu de ping-pong
class jeu_ping_pong {
public:
    int j_a = 0;
    int j_b = 0;
    int score_a = 0;
    int score_b = 0;
    int serveur = 0;
};

// Classe représentant la table de ping-pong
class table {
public:
    static constexpr float LARGEUR = 183.0f;
    static constexpr float LONGUEUR = 274.0f;
    coo centre_table;

    table();
    void sayHello() const;
};

// Classe pour la météo
class meteo {
public:
    float norme_vent;
    float sens_vent;

    explicit meteo(float vent = 0.0f, float sens = 0.0f);
};

// Classe pour le filet
class filet {
public:
    static constexpr float HAUTEUR = 15.25f;
    static constexpr float LARGEUR = 183.0f;
    coo centre_filet;

    filet();
};

// Classe pour la raquette
class raquette {
public:
    static constexpr float LARGEUR = 15.0f;
    static constexpr float HAUTEUR = 25.0f;
    coo centre_raquette;
    vitesse vitesse_raquette;

    raquette();
    string toString() const;
};

// Classe pour la balle
class balle {
public:
    static constexpr float RAYON = 2.0f;
    static constexpr float GRAVITY = 9.81f;

private:
    coo centre_balle;
    vitesse vitesse_balle;
    acc acceleration;

public:
    explicit balle(float x = 0.0f, float y = 0.0f, float z = 10.0f);

    coo getPosition() const;
    vitesse getVitesse() const;
    acc getAcceleration() const;
    void updatePosition(float dt);
    string toString() const;
};

#endif // CLASSES_HPP
