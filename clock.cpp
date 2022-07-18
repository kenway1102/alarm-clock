#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

class seconds
{
    protected:
    int sec;

    public:
    void get(int);
    int secUpdate();
};

class minutes : protected seconds
{
    protected:
    int min;

    public:
    void get(int);
    int minUpdate();
};

class dates
{
public:
    int date;
    int month;
    int year;
    int dateUpdate();
};

class hours : protected minutes, public dates
{
    protected:
    int hr;

    public:
    void get(int);
    void hrUpdate(int, int, int);
    bool alarm(int, int, int);
};

class times : public hours
{
    public:
    void getTime(int, int, int, int ,int ,int);
    void display();
};

    void seconds :: get(int x)
    {
        sec = x;
    }

    int seconds :: secUpdate()
    {
        int carry = 0;
        sec++;

        Sleep(1000);
        if(sec == 60)
        {
            sec = 0;
            carry = 1;
            return carry;
        }
        return carry;
    }

    void minutes :: get(int x)
    {
        min = x;
    }

    int minutes :: minUpdate()
    {
        int carry = 0;
        min += secUpdate();
        if(min == 60)
        {
            min = 0;
            carry = 1;
            return carry;
        }
        return carry;
    }

    void hours ::get (int x)
    {
        hr = x;
    }

    void hours :: hrUpdate(int x, int y, int z)
    {
        hr += minUpdate();
        if(hr == 24)
        {
            hr = min = sec = 0;
            dateUpdate();
        }
        if (alarm(x, y, z))
        {
            Beep(523, 500);
        }
    }

    void times :: getTime(int h, int m, int sc, int dt, int mon, int yr)
    {
        hours ::get(h);
        minutes ::get(m);
        seconds :: get(sc);
        date = dt;
        month = mon;
        year = yr;
    }

    void times :: display()
    {
        int x;
        int y; 
        int z;

        cout<<"set alarm : hr min sec\n"<<setw(12)<<" : ";
        cin>>x>>y>>z;
        while(1)
        {
            system("cls");
            
            cout << date << " / " << month << " / " << year << endl;
            cout << hr << " : " <<min << " : "<< sec << endl;

            hrUpdate(x, y, z);
        }
    }

    bool hours :: alarm(int h, int m, int s)
    {
        if(hr == h && min == m && sec == s)
        {
            return 1;
        }
        return 0;
    }

    int dates :: dateUpdate() 
    {
        date++;
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 )
        {
            if(date == 32)
            {
                date = 1;
                month++;
                if (month == 13)
                {
                    month = 1;
                    year++;
                }
            }
        }

        if(month == 2)
        {
            if(date == 29)
            {
                date = 1;
                month++;
            }
        }

        if (month == 4 || month == 6 || month == 9 || month == 11 )
        {
            if (date == 31)
            {
                date = 1;
                month++;
            }
        }
    }

int main()
{
    times t;
    t.getTime(9,46,00,22,02,2022);
    t.display();
    return 0;
}