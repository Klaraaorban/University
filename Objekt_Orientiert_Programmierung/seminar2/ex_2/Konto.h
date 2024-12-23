#ifndef SEMINAR2_KONTO_H
#define SEMINAR2_KONTO_H


class Konto {
private:
    float soldo;
public:
    Konto(float soldo);
    void auszahlen(float betrag);
    void einzahlen(float betrag);
    float kontostand();
    void print_transaction();
};


#endif //SEMINAR2_KONTO_H
