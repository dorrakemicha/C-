#include "PokemonCard.h"
#include <iostream>

// Constructeur
PokemonCard::PokemonCard(const std::string& name, const std::string& type, const std::string& family,
                         int evolution, int maxHP, int currentHP,
                         const std::vector<std::tuple<int, int, std::string, int>>& attackList)
    : Card(name), pokemonType(type), familyName(family), evolutionLevel(evolution),
      maxHP(maxHP), hp(currentHP), attacks(attackList) {}

// Méthode pour afficher les informations de la carte
void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card - Name: " << cardName
              << ", Type: " << pokemonType
              << ", Evolution Level: " << evolutionLevel
              << ", Family: " << familyName
              << ", HP: " << hp << "/" << maxHP
              << "\nAttacks:\n";

    for (size_t i = 0; i < attacks.size(); ++i) {
        const auto& attack = attacks[i];
        std::cout << "  Attack #" << i << ":\n"
                  << "    Cost: " << std::get<0>(attack) << "\n"
                  << "    Current Energy Storage: " << std::get<1>(attack) << "\n"
                  << "    Description: " << std::get<2>(attack) << "\n"
                  << "    Damage: " << std::get<3>(attack) << "\n";
    }
}

//2



// Accesseurs pour HP
int PokemonCard::getHP() const {
    return hp;
}
int PokemonCard::getMaxHP() const {
    return maxHP;
}


void PokemonCard::setHP(int newHP) {
    hp = (newHP > maxHP) ? maxHP : (newHP < 0 ? 0 : newHP); // Limiter entre 0 et maxHP
}
