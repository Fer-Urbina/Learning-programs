#include <iostream>

class Instrument
{
    public:
        virtual void MakeSound()
        {
            std::cout << "Instrument playing...\n";
        }
};

class Accordion:public Instrument
{
    public:
        void MakeSound()
        {
            std::cout << "Accordion playing...\n";
        }
};

class Piano :public Instrument
{
    public:
        void MakeSound()
        {
            std::cout << "Piano playing...\n";
        }
};

int main ()
{
    Instrument *i1 = new Accordion();
    //i1->MakeSound();
    Instrument *i2 = new Piano();
    //i2->MakeSound();

    Instrument *instruments[] = {i1, i2};
    for (int i = 0; i < 2; i++)
    {
        instruments[i]->MakeSound();
    }

    return 0;
}