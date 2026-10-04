// Using Array
#include<iostream>
using namespace std;
class Train{
    private:

    int trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;

    static int trainCount;

    public:
    //Default Constructor
    Train(){
        trainNumber = 0;
        trainName = "";
        source = "";
        destination = "";
        trainTime = "";
        trainCount ++;
    }
    //Parameterized Constructor
    Train(int num, string name, string src, string dest, string time){
        trainNumber = num;
        trainName = name;
        source = src;
        destination = dest;
        trainTime = time;
        trainCount++;
    }
    //Deconstuctor
    ~Train(){
        trainCount--;
    }
    //Setter
    void setTrainNumber(int num){ trainNumber = num; }
    void setTrainName(string name){ trainName = name; }
    void setSource(string src){ source = src; }
    void setDestination(string dest){ destination = dest; }
    void settrainTime(string time){ trainTime = time; }
    //Getter
    int getTrainNumber(){ return trainNumber; }

    // Input Function
    void inputTrainDetails() {
        cout << "\nEnter Train Number: ";
        cin >> trainNumber;
        cin.ignore(); // clear buffer

        cout << "Enter Train Name: ";
        getline(cin, trainName);

        cout << "Enter Source: ";
        getline(cin, source);

        cout << "Enter Destination: ";
        getline(cin, destination);

        cout << "Enter Train Time: ";
        getline(cin, trainTime);
    }

    // Display Function
    void displayTrainDetails() {
        cout << "\nTrain Number: " << trainNumber;
        cout << "\nTrain Name: " << trainName;
        cout << "\nSource: " << source;
        cout << "\nDestination: " << destination;
        cout << "\nTime: " << trainTime << endl;
    }

    // Static Function
    static int getTrainCount() {
        return trainCount;
    }


};
//Intializes static member
int Train::trainCount = 0;
class RailwaySystem{
    private:
    Train trains[100];
    int totalTrains;
    public:
    //Default Constructor
    RailwaySystem() {
        totalTrains = 0;
    }
    //Input Function
    void addTrain() {
        if (totalTrains < 100) {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
        } else {
            cout << "Train limit reached!\n";
        }
    }

    void displayAllTrains() {
        if (totalTrains == 0) {
            cout << "No trains available!\n";
            return;
        }

        for (int i = 0; i < totalTrains; i++) {
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number) {
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                trains[i].displayTrainDetails();
                return;
            }
        }
        cout << "Train not found!\n";
    }
};

int main() {
    RailwaySystem rs;
    int choice, number;

    do {
        cout << "\n\n===== Railway System Menu =====";
        cout << "\n1. Add Train";
        cout << "\n2. Display All Trains";
        cout << "\n3. Search Train";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                rs.addTrain();
                break;

            case 2:
                rs.displayAllTrains();
                break;

            case 3:
                cout << "Enter Train Number to search: ";
                cin >> number;
                rs.searchTrainByNumber(number);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
