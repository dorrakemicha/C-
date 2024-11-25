#include "TrainerCard.h"
#include <iostream>

// Constructeur
TrainerCard::TrainerCard(const std::string& trainerName, const std::string& effect)
    : Card(trainerName), trainerEffect(effect) {}

// Méthode pour appliquer l'effet
void TrainerCard::applyEffect(std::vector<PokemonCard*>& actionPokemon) const {
    if (trainerEffect == "heal all your action pokemon") {
        for (PokemonCard* pokemon : actionPokemon) {
            if (pokemon != nullptr) {
                pokemon->setHP(pokemon->getMaxHP()); // Remet les HP au maximum
            }
        }
        std::cout << "All action Pokémon have been healed to their maximum HP!" << std::endl;
    } else {
        std::cout << "Unknown trainer effect." << std::endl;
    }
}

// Méthode pour afficher les informations
void TrainerCard::displayInfo() const {
    std::cout << "Trainer Card - Name: " << getCardName() << std::endl;
    std::cout << "Effect: " << trainerEffect << std::endl;
}
