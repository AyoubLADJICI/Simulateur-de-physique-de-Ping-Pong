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
    int joueur_a;
    int joueur_b;
    int score_a;
    int score_b;
    int serveur;
};

// Classe représentant la table de ping-pong
class table {
    public:
        static constexpr float LARGEUR = 183.0f;   // cm
        static constexpr float LONGUEUR = 274.0f; // cm
        coo centre_table;
        table();
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
    const float HAUTEUR = 15.25;
    const int LARGEUR = 183;
    coo centre_filet;

    filet();
};

// Classe pour la raquette
class raquette {
public:
    const int LARGEUR = 15;
    const int HAUTEUR = 25;
    coo centre_raquette;
    vitesse vitesse_raquette;

    raquette();
    string toString() const;
};

// Classe pour la balle
class balle {
public:
    static constexpr int RAYON = 2;
    const float GRAVITY = 9.81;

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
