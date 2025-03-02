#include <bits/stdc++.h>
using namespace std;
void load();
void log_in();

class Account
{
private:
    long long Account_balance = 0;
    int security_code;

public:
    string Account_address;
    string Account_password;
    Account *next_block;

    void set_security(int code, Account *temp)
    {
        temp->security_code = code;
        cout << "Your Account Created Sucessfully.\n";
        cout << "Your Security Code is " << code << " . Save this for next time log in";
    }
    bool security_ck(int code, Account *temp)
    {
        return temp->security_code == code ? true : false;
    }
};

class Account_info : public Account
{

private:
    Account *head = NULL;
    Account *tail = NULL;

public:
    Account *temp = head;
    void create_Account(string user_id, string pass)
    {
        Account *na = new Account();
        na->next_block = NULL;
        na->Account_address = user_id;
        na->Account_password = pass;

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(11111111, 99999999);
        int code = dis(gen);
        na->set_security(code, na);

        if (head == NULL)
        {
            head = tail = na;
        }
        else
        {
            tail->next_block = na;
            tail = na;
        }
    }

    bool ck_user_exist(string address)
    {
        temp = head;

        while (temp != NULL)
        {
            if (temp->Account_address == address)
            {
                return true;
            }
            temp = temp->next_block;
        }
        return false;
    }
    bool log_in_ck(int id, string pass)
    {
        temp = head;
        while (temp != NULL)
        {
            if (temp->Account_password == pass)
            {
                if (temp->security_ck(id, temp))
                {
                    return true;
                }
            }
            temp = temp->next_block;
        }
        return false;
    }
};
Account_info ac;

void log_in()
{
    cout << "Enter Security Code\n";
    int id;
    cin >> id;
    cout << "Enter password\n";
    string pass;
    cin >> pass;

    if (ac.log_in_ck(id, pass))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    };
}
void create_account_page()
{
    cout << "Enter User id\n";
    string user_id;
    cin >> user_id;

    if (ac.ck_user_exist(user_id) == true)
    {
        cout << "User Id already exist.Change plz\n";
        create_account_page();
    }
    cout << "Enter PAssword\n";
    string pass;
    cin >> pass;
    cout << "Confirm Password\n";
    string confirm_pass;
    cin >> confirm_pass;
    if (pass != confirm_pass)
    {
        cout << "Password Dont Match\n";
        create_account_page();
    }

    ac.create_Account(user_id, pass);

    load();
}

void load()
{
    cout << "1..view all Transactions\n2..Search\n3..Log in\n4..Create Account\n";
    int x;
    cin >> x;
    if (x == 1)
        ;
    else if (x == 2)
    {
    }
    else if (x == 3)
        log_in();
    else if (x == 4)
        create_account_page();
    else
    {

        cout << "Wrong\n";
        load();
    }
}

int main()
{

    cout << "Welcome to Testnet\n";
    load();

    return 0;
}