#include <iostream>

#include <string>

#include <sstream>

#include <math.h>

using namespace std;

bool give (char answer);

bool checkstring (string);

float convert (string , float);

int main()
{

    float pricegiven, total, youhave, numberofcar, numbergiven, price;
    int done = 0, remain;
    string stringprice, string_number_of_car, stringpricegiven, stringnumbergiven;
    bool sure;
    do
    {
        cout<<"Price: ";
        cin>>stringprice;
        sure = checkstring(stringprice);
        price = convert(stringprice , price);
    }while(price <= 0 || sure == 1);

    do
    {
        cout<<"Number of passengers: ";
        cin>>string_number_of_car;
        sure = checkstring(string_number_of_car);
        numberofcar = convert(string_number_of_car,numberofcar);
    }while(numberofcar <= 0 || fmod(numberofcar , (int)numberofcar) != 0 || sure == 1 );
    remain = numberofcar;
    float A[(int)numberofcar];
    total = numberofcar * price;
    while(done < numberofcar)
    {
        do
        {
            cout<<"Given: ";
            cin>>stringpricegiven;
            sure = checkstring(stringpricegiven);
            pricegiven = convert(stringpricegiven, pricegiven);
        }while(pricegiven <= 0 || sure == 1);
        do
        {
            cout<<"Number: ";
            cin>>stringnumbergiven;
            sure = checkstring(stringnumbergiven);
            numbergiven = convert(stringnumbergiven, numbergiven);
        }while(numbergiven <= 0 || fmod(numbergiven , (int)numbergiven) != 0 || sure == 1);
        for (int i = done; i < (done + numbergiven); i += numbergiven)
        {
            A[i] = pricegiven - (numbergiven * price);
            if(A[i] < 0)
                cerr<<"You need "<< -A[i]<<" more from him"<<endl;
            else
                cout<<"who payed "<<pricegiven<<" for "<<numbergiven<<" need "<<A[i]<<endl;
        }
        done += numbergiven;
        youhave = done * price;
        remain = numberofcar - done;
        if(remain < 0)
        {
            cerr<<-remain<<" person Payed Twice "<<endl;
            bool giveanswer;
            do
            {
                cout<<"Did you return it ? \n y : Yes \n n : No"<<endl;
                char answer;
                cout<<"Answer: ";
                cin>>answer;
                giveanswer = give(answer);

            }while(giveanswer != true);
            youhave -= -remain * price;
            remain = 0;
        }

        cout<<remain<<" Persons left"<<endl;

    }
    cout<<"******************************\nNow you have "<<youhave<<" And the all you need is "<<total<<endl;
    cout<<"Give the money for the driver and have a nice day "<<endl;
}
bool checkstring (string x)
{
    for(int i = 0; i < x.length(); i++)
        if(isalpha(x[i]))
            return 1;
    return 0;

}
float convert (string string_x, float float_y)
{
    stringstream convert(string_x);
    convert>>float_y;
    return float_y;
}
bool give(char answer)
{
    bool giveanswer;
    if(answer == 'y' || answer == 'Y')
        giveanswer = true;
    else if(answer == 'n' || answer == 'N')
        giveanswer = false;
    return giveanswer;
}
