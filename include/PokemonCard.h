#ifndef POKEMONCARD_H
#define POKEMONCARD_H
#include "Card.h"
#include <string>
#include <vector>
#include <tuple>

class PokemonCard : public Card
{
private:
    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    std::vector<std::tuple<int,int,std::string,int>> attacks;
public:
    PokemonCard(const std::string& name, const std::string& type, const std::string& family,
                int evolution, int maxHP, int currentHP,
                const std::vector<std::tuple<int, int, std::string, int>>& attackList);

    //
    void displayInfo() const override;




    // Accesseurs pour les attributs (si besoin)
    int getHP() const;
    void setHP(int newHP);
    int getMaxHP() const;
};

#endif // POKEMON_CARD_H


