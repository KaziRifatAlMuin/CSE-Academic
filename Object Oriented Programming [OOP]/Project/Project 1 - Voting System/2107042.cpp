/*
    Name : Kazi Rifat Al Muin
    Roll : 2107042
*/

#include <iostream>
using namespace std;

class Election;
class Voter;
class VotingSystem;
class Candidate{
    string name;
    string role;
    int age;
    int ID;
    int votes;
public:
    friend class Election;
    friend class VotingSystem;
    friend void search_Candidate(VotingSystem admin, int id);
    Candidate()
    {
        votes = 0;
    }
    Candidate(string Name, string Role, int Age)
    {
        name = Name;
        role = Role;
        age = Age;
    }
    void display()
    {
        cout << "Name : " <<  name << endl;
        cout << "Role : " <<  role << endl;
        cout << "Age : " <<  age << endl;
        cout << "ID : " << ID << endl;
        cout << "Votes : " <<  votes << endl;
    }
    int GetVoteCount()
    {
        return votes;
    }
};

class Voter{
    string name;
    int NID;
    string password;
    int age;
public:
    friend class Election;
    friend class VotingSystem;
    Voter()
    {

    }
    Voter(string Name, int nid, string pass, int Age)
    {
        name = Name;
        NID = nid;
        password = pass;
        age = Age;
    }
    void display()
    {
        cout << "Name : " <<  name << endl;
        cout << "NID : " <<  NID << endl;
        cout << "Age : " <<  age << endl;
    }
};

class Election{
    Candidate C[50];
    Voter V[10000];
    string Role[10];
    int candidate_no;
    int voter_no;
    int role_no;
    int rolelist[50];
    int votecount[50];
    int Winner[10];
public:
    friend class Candidate;
    friend class Voter;
    friend class VotingSystem;
    friend void search_Candidate(VotingSystem admin, int id);
    Election()
    {
        candidate_no = 1;
        voter_no = 1;
        role_no = 1;
    }
    void AddNewCandidate(string Name, int r, int Age)
    {
        C[candidate_no].name = Name;
        C[candidate_no].role = Role[r];
        C[candidate_no].age = Age;
        C[candidate_no].ID = candidate_no;
        C[candidate_no].votes = 0;
        rolelist[candidate_no] = r;
        candidate_no++;
    }
    void AddNewVoter(string N, int nid, string pass, int Age)
    {
        V[voter_no].name = N;
        V[voter_no].NID = nid;
        V[voter_no].password = pass;
        V[voter_no].age = Age;
        voter_no++;
    }
    void AddNewRole(string R)
    {
        Role[role_no] = R;
        role_no++;
    }
    void CandidateList(int r)
    {
        for(int i = 1; i < candidate_no; i++){
            if(rolelist[i] == r){
                cout << "ID - " << C[i].ID << " : " << C[i].name << endl;
            }
        }
    }
    void RoleList()
    {
        cout << "Available Roles : " << endl;
        for(int i = 1; i < role_no; i++){
            cout << i << ". " << Role[i] << endl;
        }
        cout << "Enter a role number : ";
    }
};

class VotingSystem{
public:
    friend class Candidate;
    friend class Voter;
    friend class Election;
    friend void search_Candidate(VotingSystem admin, int id);
    Election E;
    string Password;
    void set_password(string s)
    {
        Password = s;
    }
    void AllCandidateList()
    {
        for(int i = 1; i < E.role_no; i++){
            cout << "Role " << i << " : " << E.Role[i] << endl;
            cout << "Nominated Candidates : " << endl;
            E.CandidateList(i);
        }
    }
    void CastVote()
    {
        int nid = 1;
        string pass;
        cout << "Enter NID : ";
        cin >> nid;
        cout << "Enter Password : ";
        cin >> pass;
        for(int j = 1; j < E.voter_no; j++){
            if(E.V[j].NID == nid && E.V[j].password == pass){
                for(int i = 1; i < E.role_no; i++){
                    cout << "Role " << i << " : " << E.Role[i] << endl;
                    cout << "Nominated Candidates : " << endl;
                    E.CandidateList(i);
                    cout << "Enter candidate ID to vote : ";
                    int id;
                    cin >> id;
                    E.C[id].votes++;
                    cout << "Voted Successfully!"<< endl;
                }
            }
        }
        cout << "--------------------------------------\n";
    }

    void ShowResult()
    {
        for(int i = 1; i < E.role_no; i++){
            int maxi = 0;
            cout << "Role " << i << " : " << E.Role[i] << endl;
            cout << "Voting Result : " << endl;
            for(int j = 1; j < E.candidate_no; j++){
                if(E.C[j].role == E.Role[i]){
                    cout << E.C[j].name << " : " << E.C[j].votes << " votes\n";
                    if(E.C[j].votes >= maxi){
                        E.Winner[i] = E.C[j].ID;
                        maxi = E.C[j].votes;
                    }
                }
            }
            cout << endl;
        }
        cout << "------------- Final Result -----------\n\n";
        for(int i = 1; i < E.role_no; i++){
            cout << "Winner for " << E.Role[i] << " is " << E.C[E.Winner[i]].name << endl;
        }
    }
};

void search_Candidate(VotingSystem admin, int id)
{
    for(int i = 0; i < admin.E.candidate_no; i++){
        if(admin.E.C[i].ID == id){
            cout << "Candidate Details : " << endl;
            cout << "--------------------------------------\n";
            admin.E.C[i].display();
            return;
        }
    }
    cout << "ID Not Found" << endl;
    cout << "--------------------------------------\n";
}

int main()
{
    cout << "------------ Voting System -----------" << endl;
    VotingSystem admin;
    admin.set_password("1234");
    bool election = true;
    while(election){
        int opt;
        cout << "1. Log in as an admin" << endl;
        cout << "2. Log in as a voter" << endl;
        cout << "3. Register as a new voter" << endl;
        cout << "4. End the Election" << endl;
        cout << "Choose an option : ";
        cin >> opt;
        cout << "--------------------------------------\n";
        if(opt == 1){
            bool Admin = true;
            cout << "Enter Admin Password : ";
            string pass;
            cin >> pass;
            if(pass != admin.Password){
                cout << "Wrong Password";
                continue;
            }
            cout << "Logged in Successfully!\n";
            cout << "--------------------------------------\n";
            while(Admin){
                cout << "1. Add New Role" << endl;
                cout << "2. Add New Candidate" << endl;
                cout << "3. Log Out" << endl;
                cout << "Choose an option : ";
                int opt2;
                cin >> opt2;
                cout << "--------------------------------------\n";
                if(opt2 == 1){
                    string R;
                    getchar();
                    cout << "Enter the Role Name : ";
                    getline(cin, R);
                    admin.E.AddNewRole(R);
                    cout << "Role " << R << " added successfully.\n";
                }
                else if(opt2 == 2){
                    string Name;
                    int r, Age;
                    getchar();
                    cout << "Enter Name : ";
                    getline(cin, Name);
                    admin.E.RoleList();
                    cin >> r;
                    cout << "Enter Age : ";
                    cin >> Age;
                    admin.E.AddNewCandidate(Name, r, Age);
                    cout << "New Candidate added successfully.\n";
                }
                else if(opt2 == 3){
                    Admin = false;
                }
                else{
                    cout << "You have inserted wrong number.\n\n";
                }
                cout << "--------------------------------------\n";
            }
        }
        else if(opt == 2){
            int opt3;
            cout << "1. See Candidate List" << endl;
            cout << "2. Search a Candidate" << endl;
            cout << "3. Cast a Vote" << endl;
            cout << "Choose an option : ";
            cin >> opt3;
            if(opt3 == 1){
                admin.AllCandidateList();
            }
            else if(opt3 == 2){
                int a;
                cout << "Enter Candidate ID : ";
                cin >> a;
                search_Candidate(admin, a);
            }
            else if(opt3 == 3){
                admin.CastVote();
            }
        }
        else if(opt == 3){
            string N, pass;
            int nid, Age;
            getchar();
            cout << "Enter Name : ";
            getline(cin, N);
            cout << "Enter NID : ";
            cin >> nid;
            cout << "Enter Password : ";
            cin >> pass;
            cout << "Enter Age : ";
            cin >> Age;
            admin.E.AddNewVoter(N, nid, pass, Age);
            cout << "New Voter added successfully.\n";
        }
        else if(opt == 4){
            bool Admin = true;
            cout << "Enter Admin Password : ";
            string pass;
            cin >> pass;
            if(pass != admin.Password){
                cout << "Wrong Password";
                continue;
            }
            cout << "Election Ended\n";
            cout << "----------- Vote counting ------------\n";
            election = false;
            admin.ShowResult();
        }
        else{
            cout << "You have inserted wrong number.\n\n";
        }
        cout << "--------------------------------------\n";
    }

    return 0;
}


