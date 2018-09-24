#include <bits/stdc++.h>

using namespace std;

int roman_to_number( string s )
{
    int output = 0;
    for( int i = 0 ; i < s.length() ; i++)
    {
        switch( s[i] )
        {
            case 'I':
                output++;
            break;
            case 'V':
                output += 5;
                if( s[i-1] == 'I' )
                    output -= 2;
            break;
            case 'X':
                output += 10;
                if( s[i-1] == 'I' )
                    output -= 2;
            break;
            case 'L':
                output += 50;
                if( s[i-1] == 'X' )
                    output -= 20;
            break;
            case 'C':
                output += 100;
                if( s[i-1] == 'X' )
                    output -= 20;
            break;
            case 'D':
                output += 500;
                if( s[i-1] == 'C' )
                    output -= 200;
            break;
            case 'M':
                output += 1000;
                if( s[i-1] == 'C' )
                    output -= 200;
            break;
        }
    }
    return output;
}


string number_to_roman( int i )
{
    string output = "";

    if( i == 0 )
        return (output = "ZERO");
    
    int temp;
    
    while( i > 0 )
    {
        if( i >= 1000 )
        {
            i -= 1000;
            output += "M";
        }
        else if( i >= 900 )
        {
            i -= 900;
            output += "CM";
        }
        else if( i >= 500 )
        {
            i -= 500;
            output += "D";
        }
        else if( i >= 400 )
        {
            i -= 400;
            output += "CD";
        } 
        else if( i >= 100 )
        {
            i -= 100;
            output += "C";
        }
        else if( i >= 90 )
        {
            i -= 90;
            output += "XC";
        } 
        else if( i >= 50 )
        {
            i -= 50;
            output += "L";
        }
        else if( i >= 40 )
        {
            i -= 40;
            output += "XL";
        }
        else if( i >= 10 )
        {
            i -= 10;
            output += "X";
        }
        else if( i >= 9 )
        {
            i -= 9;
            output += "IX";
        }
        else if( i >= 5 )
        {
            i -= 5;
            output += "V";
        }
        else if( i >= 4 )
        {
            i -= 4;
            output += "IV";
        }
        else
        {
            i -= 1;
            output += "I";
        }
    }
    return output;
}


int main(int argc, char const *argv[])
{
    int input;

    #ifdef DBG
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif

    for (int i = 0; i < 1000; ++i)
    {
         cout << number_to_roman(i) << endl;
    }

   
    return 0;
}