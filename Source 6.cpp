#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



bool checkSack(char contents, double weight)

{





    bool valid_sack = true;



    if (contents != 'C' && contents != 'G' && contents != 'S') {
        valid_sack = false;

        cout << "Invalid contents ";
    }

    if (contents == 'C' && (weight < 24.9 || weight > 25.1))
    {
        valid_sack = false;
        cout << "Invalid weight for cement ";
    }

    else if ((contents == 'G' || contents == 'S') && (weight < 49.9 || weight > 50.1))

    {
        valid_sack = false;

        cout << "Invalid weight for gravel or sand ";

    }


    if (!valid_sack)
    {


        cout << "Rejected sack: " << endl;

    }
    return valid_sack;
}

int main() {

    int cement_sacks, gravel_sacks, sand_sack;
    double total_weight = 0.0;
    int rejected_sack = 0;


    cout << "Enter the number of sacks of cement required: ";
    cin >> cement_sacks;
    cout << "Enter the number of sacks of gravel required: ";
    cin >> gravel_sacks;
    cout << "Enter the number of sacks of sand required: ";
    cin >> sand_sack;


    for (int i = 0; i < cement_sacks; ++i)
    {
        char contents;
        double weight;


        cout << "Enter the contents and weight of cement sack " << i + 1 << ": ";
        cin >> contents >> weight;

        if (checkSack(contents, weight))
        {
            total_weight += weight;
        }
        else
        {
            rejected_sack++;
        }
    }

    for (int i = 0; i < gravel_sacks; ++i)
    {
        char contents;
        double weight;


        cout << "Enter the contents and weight of gravel sack " << i + 1 << ": ";
        cin >> contents >> weight;

        if (checkSack(contents, weight))
        {
            total_weight += weight;
        }
        else
        {
            rejected_sack++;
        }


    }

    for (int i = 0; i < sand_sack; ++i)
    {
        char contents;
        double weight;


        cout << "Enter the contents and weight of sand sack " << i + 1 << ": ";
        cin >> contents >> weight;


        if (checkSack(contents, weight))
        {
            total_weight += weight;
        }
        else
        {
            rejected_sack++;
        }



    }

   

    double regular_price = cement_sacks * 3.0 + gravel_sacks * 2.0 + sand_sack * 2.0;

    int special_pack = min({ cement_sacks, gravel_sacks / 2, sand_sack / 2 });
    double new_price = regular_price - special_pack * 10.0;



    cout << "Regular price for the order: $" << regular_price << endl;

    if (special_pack > 0)
    {
        cout << "Number of special packs in the order: " << special_pack << endl;
        cout << "New price for the order: $" << new_price << endl;
        cout << "Amount saved: $" << regular_price - new_price << endl;
    }

    return 0;
}
