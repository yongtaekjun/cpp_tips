 #include <iostream>
    #include <vector>
    #include <cmath>
    using namespace std;

    void do_mult_div_mod(vector<double> &values, vector<char> &signs)
    {
        for(int i{0};i < signs.size(); ++i)
        {
            if(signs.size() != 0 && signs.at(i) == '*')
            {
                values.at(i) = values.at(i)*values.at(i+1);
                values.erase(values.begin()+i+1);
                signs.erase(signs.begin()+i);
                --i; // removed an element, so --i, then ++i so i remains at the same value
            }

            if(signs.size() != 0 && signs.at(i) == '/')
            {
                if(values.at(i+1) == 0)
                {
                    cout << "Infinite" << '\n';
                    exit(1);
                }
                values.at(i) = values.at(i)/values.at(i+1);
                values.erase(values.begin()+i+1);
                signs.erase(signs.begin()+i);
                --i;
            }

            if(signs.size() != 0 && signs.at(i) == '%')
            {
               values.at(i) = fmod(values.at(i), values.at(i+1));
               values.erase(values.begin()+i+1);
               signs.erase(signs.begin()+i);
               --i;
            }
        }
     }

double do_add_sub(vector<double> &values, vector<char> &signs)
{
    double result{values.at(0)};
    for(int i{0}; i < signs.size(); ++i)
    {
        if(signs.at(i) == '+')
            result += values.at(i+1);
        if(signs.at(i) == '-')
            result -= values.at(i+1);
    }

    return result;
}

double do_parenthesis()
{
    // get local vectors of values and signs and make a mini-expression
    int nr;
    vector<double> values;

    char op{'0'};
    vector<char> oper;

    while(op != ')')
    {
        if( cin >> nr && cin >> op)
        {
            values.push_back(nr);
            if(op == ')')
                break;

            if(op == '=' || cin.peek() == '=') // if we gan an '=' here, the expression is invalid, as we didn't get an ')' yet
            {
                cout << "Invalid Expression" << '\n';
                exit(2);
            }

            oper.push_back(op);

            char buff;
            if(cin.peek() == '(') // recursion for multiple parenthesis
            {
                cin >> buff;
                values.push_back(do_parenthesis());
                if(cin >> op)
                {
                    if(op == ')')
                        break;
                    if(op == '=')
                    {
                        cout << "Invalid Expression" << '\n';
                        exit(3);
                    }
                    else
                        oper.push_back(op);
                }
                else
                {
                    cout << "Invalid Expression" << '\n';
                    exit(4);
                }
            }
        }
        else
        {
            cout << "Invalid Expression" << '\n';
            exit(5);
        }
    }


    do_mult_div_mod(values, oper);
    double fin{do_add_sub(values, oper)};

    return fin;
}

void get_expression(vector<double> &values, vector<char> &signs)
{
    double num;
    char cha;
    for(;;)  // loop until we get an '='
    {
        if(cin >> num && cin >> cha) // check if the expression we get is valid
        {
            values.push_back(num);
            if(cha == '=')  //stop
                break;
            signs.push_back(cha);

            if(cin.peek() == '(')  // check if the next token is a parenthesis
            {
                char buffer;
                cin >> buffer;
                values.push_back(do_parenthesis()); // if yes, return the result from calculating the parenthesis
                if(cin >> cha) // after a parenthesis, we must get a sign, otherwise we throw an error
                {
                    if(cha == '=')
                        break;
                    else
                        signs.push_back(cha);
                }
                else
                {
                     cout << "Invalid Expression" << '\n';
                     exit(6);
                }
            }

        }
        else
        {
            cout << "Invalid Expression" << '\n';
            exit(7);
        }
    }
}

int main() {

    vector<double> values;
    vector<char> signs;

    get_expression(values,signs);
    do_mult_div_mod(values, signs);

    double result{do_add_sub(values, signs)};

    cout << result;

    return 0;
}