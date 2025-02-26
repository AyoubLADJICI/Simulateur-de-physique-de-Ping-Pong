#include "classes.hpp"

// Implémentation des structures
string coo::toString() const {
    return "(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")";
}

string vitesse::toString() const {
    return "(" + to_string(vx) + ", " + to_string(vy) + ", " + to_string(vz) + ")";
}

string acc::toString() const {
    return "(" + to_string(ax) + ", " + to_string(ay) + ", " + to_string(az) + ")";
}

// Implémentation de la table
table::table() : centre_table{0, 0, 0} {}


// Implémentation de la météo
meteo::meteo(float vent, float sens) : norme_vent(vent), sens_vent(sens) {}

// Implémentation du filet
filet::filet() : centre_filet{0, 0, HAUTEUR / 2.0f} {}

// Implémentation de la raquette
raquette::raquette() : centre_raquette{0, 0, 0}, vitesse_raquette{0, 0, 0} {}

string raquette::toString() const {
    return "Raquette - Centre: " + centre_raquette.toString() +
           ", Vitesse: " + vitesse_raquette.toString();
}

// Implémentation de la balle
balle::balle(float x, float y, float z)
    : centre_balle{x, y, z}, vitesse_balle{0, 0, 0}, acceleration{0, 0, -GRAVITY} {}

coo balle::getPosition() const {
    return centre_balle;
}

vitesse balle::getVitesse() const {
    return vitesse_balle;
}

acc balle::getAcceleration() const {
    return acceleration;
}

void balle::updatePosition(float dt) {
    vitesse_balle.vx += acceleration.ax * dt;
    vitesse_balle.vy += acceleration.ay * dt;
    vitesse_balle.vz += acceleration.az * dt;

    centre_balle.x += vitesse_balle.vx * dt;
    centre_balle.y += vitesse_balle.vy * dt;
    centre_balle.z += vitesse_balle.vz * dt;

    // Gestion du rebond sur le sol
    if (centre_balle.z < 0.0f) {
        centre_balle.z = 0.0f;
        vitesse_balle.vz = -vitesse_balle.vz * 0.8f; // Perte d’énergie 20%
    }
}

string balle::toString() const {
    return "Balle - Position: " + centre_balle.toString() +
           ", Vitesse: " + vitesse_balle.toString() +
           ", Accélération: " + acceleration.toString();
}
