const int SUIT = 4;
const int FACE = 13;
const int CARDS = SUIT * FACE;
const int HAND = 5;

class DeckOfCards
{
public:
    DeckOfCards();
    void shuffle();
    void deal(int [][HAND + 1]);
    void printHand(int [][HAND + 1]);
    void printCard(const int, const int);
    void printCombination(int);
    void printHighCard(int);
    void checkCombination(int [][HAND + 1]);
    bool royalFlush(int [][HAND + 1]);
    bool straightFlush(int [][HAND + 1]);
    bool fourOfKind(int [][HAND + 1]);
    bool fullHouse(int [][HAND + 1]);
    bool flush(int [][HAND + 1]);
    bool straight(int [][HAND + 1]);
    bool threeOfKind(int [][HAND + 1]);
    bool twoPairs(int [][HAND + 1]);
    bool aPair(int [][HAND + 1]);
    int highCard(int [][HAND + 1]);
    int getEquals(int *);
    void determineWinner();

    int pokerHand1_[2][HAND + 1];
    int pokerHand2_[2][HAND + 1];
private:
    int deck_[SUIT][FACE];
    int card_;
};

