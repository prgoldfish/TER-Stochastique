#include <string>

class EspeceMoleculaire
{
private:
    std::string nom;
    int taille;
    float vitesse;
    int pop;
public:
    EspeceMoleculaire(std::string nom, int taille, float vitesse, int pop);
    ~EspeceMoleculaire();
};