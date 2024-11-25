#ifndef CARD_H
#define CARD_H
#include <string>


class Card
{
protected:
    std::string cardName;
public:
    Card(const std::string& name);
    virtual ~Card();
    virtual void displayInfo() const=0;

    std::string getCardName() const;
};




#endif // CARD_H
