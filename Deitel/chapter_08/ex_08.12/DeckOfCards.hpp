const int SUIT = 4;
const int FACE = 13;
const int CARDS = SUIT * FACE;
const int HAND = 5;

class DeckOfCards
{
public:
    DeckOfCards();
    void shuffle();
    void deal();
    void printHand();
    void printCard(const int, const int);
    void checkCombination();
    bool royalFlush();
    bool straightFlush();
    bool fourOfKind();
    bool fullHouse();
    bool flush();
    bool straight();
    bool threeOfKind();
    bool twoPairs();
    bool aPair();
    int highCard();
    int getEquals(int *);
private:
    int deck_[SUIT][FACE];
    int pokerHand_[2][HAND];
};

