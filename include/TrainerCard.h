#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H

#include "Card.h"
#include <string>
#include <vector>
#include "PokemonCard.h"

class TrainerCard : public Card {
private:
    std::string trainerEffect;

public:
    // Constructeur
    TrainerCard(const std::string& trainerName, const std::string& effect);

    // Méthode pour appliquer l'effet
    void applyEffect(std::vector<PokemonCard*>& actionPokemon) const;

    // Méthode pour afficher les informations
    void displayInfo() const override;
};

#endif // TRAINER_CARD_H
