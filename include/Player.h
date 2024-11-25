#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
#include "PokemonCard.h"  // Inclure pour utiliser PokemonCard dans actionCards

class Player {
private:
    std::string playerName;                   // Nom du joueur
    std::vector<Card*> benchCards;            // Cartes en réserve (deck)
    std::vector<PokemonCard*> actionCards;    // Cartes Pokémon (deck d'action)

public:
    // Constructeur
    Player(const std::string& name);

    // Méthodes d'accès aux attributs
    std::string getPlayerName() const;
    const std::vector<Card*>& getBenchCards() const;
    const std::vector<PokemonCard*>& getActionCards() const;

    // Ajouter une carte à chaque deck
    void addCardToBench(Card* card);
    void addCardToAction(PokemonCard* pokemonCard);

    void activatePokemonCard(int index);
    void attachEnergyCard(int actionIndex, int energyIndex);

    // Afficher les informations du joueur (facultatif)
    void displayInfo() const;
};

#endif // PLAYER_H
