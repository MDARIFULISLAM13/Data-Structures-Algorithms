#include <bits/stdc++.h>
using namespace std;
void load();
void log_in();
void clear()
{
    system("cls");
};

class All_Transactions
{
public:
    string from;
    string to;
    int Transaction_value;
    string hash;
    All_Transactions *next_block;
};
class All_Transactions_controler
{
private:
    All_Transactions *head = NULL;
    All_Transactions *tail = NULL;

public:
    void save_All_transactions()
    {
        ofstream file("transactions.txt", ios::app);
        if (file.is_open())
        {
            file << head->from << " " << head->to << " " << head->Transaction_value << " " << head->hash << endl;
            file.close();
        }
    }
    void load_All_transactions()
    {
        ifstream file("transactions.txt");
        if (file.is_open())
        {
            string from, to, hash;
            int value;
            while (file >> from >> to >> value >> hash)
            {
                All_Transactions *at = new All_Transactions();
                at->from = from;
                at->to = to;
                at->Transaction_value = value;
                at->hash = hash;
                at->next_block = NULL;

                if (head == NULL)
                {
                    head = tail = at;
                }
                else
                {
                    tail->next_block = at;
                    tail = at;
                }
            }
            file.close();
        }
    }
    string set_data(string from, string to, int value)
    {

        All_Transactions *at = new All_Transactions();
        at->from = from;
        at->to = to;
        at->Transaction_value = value;
        stringstream ss;
        ss << at;
        string hash = ss.str();
        at->hash = hash;
        at->next_block = NULL;
        if (head == NULL)
        {
            head = tail = at;
        }
        else
        {
            tail->next_block = at;
            tail = at;
        }
        save_All_transactions();
        return hash;
    }
    void print_data()
    {
        clear();
        load_All_transactions();
        All_Transactions *temp = head;
        All_Transactions *pre = NULL;
        int cnt = 1;
        if (temp == NULL)
        {
            cout << "No transactions Done\n\n";
            return;
        }
        while (temp != NULL)
        {
            cout << "Block No : " << cnt << endl;
            ++cnt;
            cout << "From : " << temp->from << endl;
            cout << "To : " << temp->to << endl;
            cout << "Transaction_value : " << temp->Transaction_value << endl;
            cout << "Hash : " << temp->hash << endl;
            cout << "Previous Block : " << pre << endl;
            cout << "Next Block : " << temp->next_block << endl;
            pre = temp;

            temp = temp->next_block;
            cout << endl;
        }
    }
    void search_by_hash()
    {
        load_All_transactions();
        clear();
        cout << "Enter Your Hash Id\n";
        string val;
        cin >> val;
        cout << endl;
        All_Transactions *temp = head;
        All_Transactions *pre = NULL;
        int cnt = 1;
        while (temp != NULL)
        {
            if (temp->hash == val)
            {
                cout << "Block No : " << cnt << endl;
                cout << "From : " << temp->from << endl;
                cout << "To : " << temp->to << endl;
                cout << "Transaction_value : " << temp->Transaction_value << endl;
                cout << "Hash : " << temp->hash << endl;
                cout << "Previous Block : " << pre << endl;
                cout << "Next Block : " << temp->next_block << "\n\n";
                load();
            }

            ++cnt;
            pre = temp;
            temp = temp->next_block;
        }

        {
            cout << "No transactions Found\n\n";
            return;
        }
    }
};
All_Transactions_controler atc;

class Account
{
private:
    long long Account_balance = 100;
    int security_code;

protected:
    int show_balance(Account *temp)
    {
        return temp->Account_balance;
    };
    void whitdraw_balance(Account *temp, int money)
    {
        temp->Account_balance -= money;
    }
    void add_balance(Account *temp, int money)
    {
        temp->Account_balance += money;
    }

public:
    string Account_address;
    string Account_password;
    string deposit_address;
    Account *next_block;
    vector<vector<string>> data;

    void set_security(int code, Account *temp)
    {
        clear();
        temp->security_code = code;
        cout << "Your Account Created Sucessfully.\n";
        cout << "Your Security Code is " << code << " . Save this for next time log in\n\n";
    }
    bool security_ck(int code, Account *temp)
    {
        return temp->security_code == code ? true : false;
    }
    int get_code(Account *temp)
    {
        return temp->security_code;
    }
    void set_code(Account *temp, int code)
    {
        temp->security_code = code;
    }
    int get_balance(Account *temp)
    {
        return temp->Account_balance;
    }
    void set_balance(Account *temp, int val)
    {
        temp->Account_balance = val;
    }
};
void log_in_load(Account *temp);

class Account_info : public Account
{

private:
    Account *head = NULL;
    Account *tail = NULL;

public:
    Account *temp = head;

    void save_All_Account(Account *temp, bool overwrite = false)
    {
        ofstream file("AccountInfo.txt", ios::app);
        if (file.is_open())
        {
            file << temp->Account_address << " " << temp->Account_password << " "
                 << temp->deposit_address << " " << temp->get_code(temp) << " "
                 << temp->get_balance(temp);

            file << endl;
            file.close();
        }
    }

    void update_amount_withdraw(const string &account_address, int additional_balance)
    {
        ifstream file("AccountInfo.txt");
        stringstream updated_content;
        string line;
        bool updated = false;
        while (getline(file, line))
        {
            stringstream ss(line);
            string Account_Add, Account_Pass, Deposit_add;
            int balance, code;

            ss >> Account_Add >> Account_Pass >> Deposit_add >> code >> balance;

            if (account_address == Deposit_add)
            {
                balance += additional_balance;
                updated = true;
            }

            updated_content << Account_Add << " " << Account_Pass << " " << Deposit_add << " " << code << " " << balance << endl;
        }

        file.close();

        if (updated)
        {
            ofstream outfile("AccountInfo.txt", ios::trunc);
            outfile << updated_content.str();
            outfile.close();
        }
    }
    void update_amount_deposit(const string &account_address, int additional_balance)
    {
        ifstream file("AccountInfo.txt");
        stringstream updated_content;
        string line;
        bool updated = false;
        while (getline(file, line))
        {
            stringstream ss(line);
            string Account_Add, Account_Pass, Deposit_add;
            int balance, code;

            ss >> Account_Add >> Account_Pass >> Deposit_add >> code >> balance;

            if (account_address == Deposit_add)
            {
                balance -= additional_balance;
                updated = true;
            }

            updated_content << Account_Add << " " << Account_Pass << " " << Deposit_add << " " << code << " " << balance << endl;
        }

        file.close();

        if (updated)
        {
            ofstream outfile("AccountInfo.txt", ios::trunc);
            outfile << updated_content.str();
            outfile.close();
        }
    }

    void load_All_Account()
    {
        ifstream file("AccountInfo.txt");
        if (file.is_open())
        {
            string Account_Add, Account_Pass, Deposit_add;
            int balance, code, data_size;

            while (file >> Account_Add >> Account_Pass >> Deposit_add >> code >> balance)
            {
                Account *na = new Account();
                na->Account_address = Account_Add;
                na->Account_password = Account_Pass;
                na->deposit_address = Deposit_add;
                na->set_balance(na, balance);
                na->set_code(na, code);
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
            file.close();
        }
    }

    Account_info()
    {
        load_All_Account();
    }

    void create_Account(string user_id, string pass)
    {
        Account *na = new Account();
        na->next_block = NULL;
        na->Account_address = user_id;
        na->Account_password = pass;

        auto now = chrono::system_clock::now();
        auto timestamp = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()).count();
        mt19937 gen(timestamp);
        uniform_int_distribution<int> dis(1111, 9999);
        int code = dis(gen);

        na->set_security(code, na);
        stringstream ss;
        ss << "0x4cz" << na;
        na->deposit_address = ss.str();

        if (head == NULL)
        {
            head = tail = na;
        }
        else
        {
            tail->next_block = na;
            tail = na;
        }
        save_All_Account(na);
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
    Account *log_in_ck(string id, int code, string pass)
    {
        temp = head;
        while (temp != NULL)
        {
            if (temp->Account_password == pass && temp->Account_address == id)
            {
                if (temp->security_ck(code, temp))
                {

                    return temp;
                }
            }
            temp = temp->next_block;
        }
        return NULL;
    }
    void Add_Balance(string Address, int val, string address_deposit, string HASH)
    {
        temp = head;
        while (temp != NULL)
        {
            if (temp->deposit_address == Address)
            {
                add_balance(temp, val);

                vector<string> vec;
                vec.push_back("Type : Deposit");
                string data_address = "Address : " + address_deposit;
                vec.push_back(data_address);
                vec.push_back("Amount : " + to_string(val));
                vec.push_back("Hash : " + HASH);
                temp->data.push_back(vec);
                update_amount_withdraw(Address, val);

                break;
            }
            temp = temp->next_block;
        }
    }
    void withdraw_Balance(string Address, int balance)
    {
        update_amount_deposit(Address, balance);
    }
};

Account_info ac;

class account_activity : public Account
{
public:
    void Show_balance(Account *temp)
    {
        clear();
        int balance = show_balance(temp);
        cout << "Your Account Balance is : " << balance << endl;
        log_in_load(temp);
    }
    void withdraw(Account *temp)
    {
        clear();
        cout << "Enter Withdraw Address\n";
        string Address;
        cin >> Address;
        int balance = show_balance(temp);
        cout << "Your Avaiable Balance is : " << balance << endl;
        cout << "Enter Withdraw Amount\n";
        int val;
        cin >> val;
        if (val > balance)
        {
            cout << "Not enough Balance to send\n";
            log_in_load(temp);
        }
        whitdraw_balance(temp, val);

        vector<string> vec;
        vec.push_back("Type : Withdraw");
        string data_address = "Address : " + Address;
        vec.push_back(data_address);
        vec.push_back("Amount : " + to_string(val));
        string address_deposit = temp->deposit_address;
        ac.withdraw_Balance(address_deposit, val);
        string HASH = atc.set_data(address_deposit, Address, val);
        vec.push_back("Hash : " + HASH);
        temp->data.push_back(vec);
        ac.Add_Balance(Address, val, address_deposit, HASH);
        log_in_load(temp);
    }
    void My_All_Transactions(Account *temp)
    {
        clear();
        if (temp->data.size() == 0)
        {

            cout << "No Transactions Complete\n";
            log_in_load(temp);
            return;
        }

        cout << "Transactions Details\n";
        for (int i = 0; i < temp->data.size(); i++)
        {
            cout << i + 1 << ": \n";
            for (auto j : temp->data[i])
            {
                cout << j << endl;
            }
        }
        log_in_load(temp);
    }
};

void log_in()
{
    clear();
    cout << "Enter User id\n";
    string id;
    cin >> id;
    cout << "Enter Security Code\n";
    int code;
    cin >> code;
    cout << "Enter password\n";
    string pass;
    cin >> pass;

    Account *temp = ac.log_in_ck(id, code, pass);
    if (temp != NULL)
    {

        clear();
        cout << "Log in Successfully\n\n";

        log_in_load(temp);
    }
    else
    {
        clear();
        cout << "Wrong User id / Security Code / Password\n\n";
        load();
    };
}
void create_account_page()
{
    clear();
    cout << "Enter User id\n";
    string user_id;
    cin >> user_id;

    if (ac.ck_user_exist(user_id) == true)
    {
        cout << "User Id already exist.Change plz\n";
        create_account_page();
    }
    cout << "Enter Password\n";
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

    cout << "\n1..view all Transactions\n2..Search By Hash\n3..Log in\n4..Create Account\n5..Exit\n\n";
    int x;
    cin >> x;
    if (x == 1)
    {
        atc.print_data();
        load();
    }

    else if (x == 2)
    {
        atc.search_by_hash();
        load();
    }
    else if (x == 3)
    {
        log_in();
    }
    else if (x == 4)
    {
        create_account_page();
    }
    else if (x == 5)
    {
        exit(0);
    }
    else
    {

        cout << "Wrong\n";
        load();
    }
}
void log_in_load(Account *temp)
{

    account_activity acc;
    cout << "\n1..Account Balance\n2..Deposit Address\n3..Withdraw\n4..My All Transactions\n5..Log Out\n\n";
    int x;
    cin >> x;
    if (x == 1)
    {
        acc.Show_balance(temp);
    }
    else if (x == 2)
    {
        clear();
        cout << "Deposit Address : " << temp->deposit_address << "\n\n";
        log_in_load(temp);
    }
    else if (x == 3)
    {
        acc.withdraw(temp);
    }
    else if (x == 4)
    {
        acc.My_All_Transactions(temp);
    }
    else if (x == 5)
    {
        clear();
        load();
    }
}
int main()
{

    cout << "Welcome to Testnet\n";
    load();

    return 0;
}
