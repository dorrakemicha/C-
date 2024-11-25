#include "Player.h"
#include <iostream>

// Constructeur
Player::Player(const std::string& name) : playerName(name) {}

// Méthodes d'accès aux attributs
std::string Player::getPlayerName() const {
    return playerName;
}

const std::vector<Card*>& Player::getBenchCards() const {
    return benchCards;
}

const std::vector<PokemonCard*>& Player::getActionCards() const {
    return actionCards;

}

// Ajouter une carte au deck en réserve (benchCards)
void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

// Ajouter une carte Pokémon au deck d'action (actionCards)
void Player::addCardToAction(PokemonCard* pokemonCard) {
    actionCards.push_back(pokemonCard);
}

//1
void Player::activatePokemonCard(int benchIndex) {

    if (benchIndex < 0 || benchIndex >= benchCards.size()) {
        std::cout << "Invalid bench index. Cannot activate card." << std::endl; // Vérification de l'index
        return;
    }


    PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[benchIndex]);
    if (!pokemon) {
        std::cout << "The selected card is not a Pokemon Card. Cannot activate." << std::endl;
        return;
    }


    actionCards.push_back(pokemon);
    benchCards.erase(benchCards.begin() + benchIndex); // Déplacement de la carte vers actionCards


    std::cout << playerName << " is activating a Pokemon Card: "
              << pokemon->getCardName() << std::endl;
}


//2
void Player::attachEnergyCard(int benchIndex, int pokemonIndex) {

    if (benchIndex < 0 || benchIndex >= benchCards.size()) {
        std::cout << "Invalid bench index. Cannot attach energy." << std::endl; // Vérification de l'index de la carte d'énergie
        return;
    }


    EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards[benchIndex]);
    if (!energyCard) {
        std::cout << "The selected card is not an Energy Card. Cannot attach." << std::endl;
        return;
    }


    if (pokemonIndex < 0 || pokemonIndex >= actionCards.size()) {
        std::cout << "Invalid pokemon index. Cannot attach energy." << std::endl;
        return;
    }

    // Attacher l'énergie au Pokémon
    PokemonCard* pokemon = actionCards[pokemonIndex];
    pokemon->addEnergy(energyCard);  // Ajout de l'énergie au Pokémon
    benchCards.erase(benchCards.begin() + benchIndex);  // Retirer l'énergie du banc

    // Message de confirmation
    std::cout << playerName << " is attaching Energy Card of type "
              << energyCard->getEnergyType() << " to the Pokemon "
              << pokemon->getCardName() << std::endl;
}

//3

void Player::displayBench() const {
    std::cout << "Bench cards for Player " << playerName << ":\n";

    // Si le banc est vide
    if (benchCards.empty()) {
        std::cout << "The bench is empty.\n";
        return;
    }

    // Parcours des cartes du banc
    for (size_t i = 0; i < benchCards.size(); ++i) {
        std::cout << "Card #" << i << ": ";

        // Vérifier le type de la carte avec un dynamic_cast
        EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards[i]);
        TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(benchCards[i]);

        if (energyCard) {
            std::cout << "Energy Card - Type: " << energyCard->getEnergyType() << "\n";
        } else if (trainerCard) {
            std::cout << "Trainer Card - Name: " << trainerCard->getCardName()
                      << ", Effect: " << trainerCard->getTrainerEffect() << "\n";
        } else {
            std::cout << "Unknown Card\n";
        }
    }
}

//4

void Player::displayAction() const {
    std::cout << "Action cards for Player " << playerName << ":\n";

    // Si aucune carte n'est active
    if (actionCards.empty()) {
        std::cout << "No active Pokemon cards.\n";
        return;
    }

    // Parcours des cartes Pokémon actives
    for (size_t i = 0; i < actionCards.size(); ++i) {
        PokemonCard* pokemon = actionCards[i];
        std::cout << "Pokemon Card #" << i << ": "
                  << "Name: " << pokemon->getCardName()
                  << ", Type: " << pokemon->getPokemonType()
                  << ", HP: " << pokemon->getCurrentHP() << "/"
                  << pokemon->getMaxHP() << "\n";

        // Afficher les attaques du Pokémon
        const auto& attacks = pokemon->getAttacks();
        for (size_t j = 0; j < attacks.size(); ++j) {
            std::cout << "  Attack #" << j << ": "
                      << "Cost: " << std::get<0>(attacks[j])
                      << ", Current Energy: " << std::get<1>(attacks[j])
                      << ", Description: " << std::get<2>(attacks[j])
                      << ", Damage: " << std::get<3>(attacks[j]) << "\n";
        }
    }
}




// Afficher les informations du joueur (facultatif)
void Player::displayInfo() const {
    std::cout << "Player Name: " << playerName << std::endl;
    std::cout << "Number of cards in Bench: " << benchCards.size() << std::endl;
    std::cout << "Number of action Pokémon cards: " << actionCards.size() << std::endl;
}
