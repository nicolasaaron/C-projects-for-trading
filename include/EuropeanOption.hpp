#include <string>
using namespace std;

class EuropeanOption
{
    private:

        void init();
        void copy(const EuropeanOption& o2);
        double CallPrice() const;
        double PutPrice() const;
        double CallDelta() const;
        double PutDelta() const;

    public:

        // for convinence only
        double r, sig, K, T, S, b;
        // b: cost of carry
        // r: Interest rate
        // S: current underlying price

        string optType;

    public:
        // constructors
        EuropeanOption();
        EuropeanOption(const EuropeanOption & option2);
        EuropeanOption(const string & optionType);

        // destructor
        virtual ~EuropeanOption();

        //Assignment operator
        EuropeanOption& operator = (const EuropeanOption& option2);

        //Functions for calculation
        double Price() const;
        double Delta() const;

        // Modifier functions
        void toggle();   // change option type: Call --> Put or Put --> Call

};