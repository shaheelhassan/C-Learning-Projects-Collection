#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <random>
#include <limits>
#include <map>

using namespace std;

// Structures
struct Question {
    string text;
    string options[4];
    char correctOption;
    string answerText;
};

struct PlayerProfile {
    string id;
    string name;
    int age;
    int score;
    string level;
};

// ANSI Color Codes
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";
const string MAGENTA = "\033[35m";
const string BLUE = "\033[34m";

// Function Prototypes
void clearScreen();
void showHeader();
string determineLevel(int score, int maxScore);
string generateID();
bool isIDUnique(const string& id);
bool loadProfileByID(const string& code, PlayerProfile& outProfile);
bool saveOrUpdateProfile(const PlayerProfile& p);
void loginRegister();
void viewProfile();
void showLeaderboard();
void showRules();
void playQuiz();
bool askToUseLifeline(Question& q, bool& lifelineUsed);

// Global current logged-in player
PlayerProfile currentPlayer;
bool isLoggedIn = false;

// Utility Functions
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void showHeader() {
    cout << MAGENTA << "============================================" << endl;
    cout << "          ULTIMATE QUIZ MASTER PRO          " << endl;
    cout << "============================================" << RESET << endl;
}

string determineLevel(int score, int maxScore) {
    if (maxScore == 0) return "Novice";
    double percentage = (double)score / maxScore * 100.0;
    if (percentage >= 90) return "Grandmaster";
    if (percentage >= 75) return "Expert";
    if (percentage >= 50) return "Intermediate";
    if (percentage >= 25) return "Apprentice";
    return "Novice";
}

// Ensure generated ID is unique in the profiles file
bool isIDUnique(const string& id) {
    ifstream file("quiz_profiles.txt");
    if (!file.is_open()) return true; // no file yet -> unique
    string line;
    while (getline(file, line)) {
        size_t pos = line.find('|');
        if (pos != string::npos) {
            string existingId = line.substr(0, pos);
            if (existingId == id) {
                return false;
            }
        }
    }
    return true;
}

string generateID() {
    stringstream ss;
    string id;
    do {
        ss.str("");
        ss.clear();
        ss << "U" << (rand() % 9000 + 1000);
        id = ss.str();
    } while (!isIDUnique(id));
    return id;
}

// Load a profile by unique access code. Returns true if found and fills outProfile.
bool loadProfileByID(const string& code, PlayerProfile& outProfile) {
    ifstream file("quiz_profiles.txt");
    if (!file.is_open()) return false;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string segment;
        vector<string> parts;
        while (getline(ss, segment, '|')) {
            parts.push_back(segment);
        }
        if (parts.size() >= 5 && parts[0] == code) {
            outProfile.id = parts[0];
            outProfile.name = parts[1];
            outProfile.age = atoi(parts[2].c_str());
            outProfile.score = atoi(parts[3].c_str());
            outProfile.level = parts[4];
            return true;
        }
    }
    return false;
}

// Save or update profile: if ID exists, update that line; otherwise append as new profile.
bool saveOrUpdateProfile(const PlayerProfile& p) {
    vector<string> lines;
    ifstream infile("quiz_profiles.txt");
    bool updated = false;
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            size_t pos = line.find('|');
            if (pos != string::npos) {
                string existingId = line.substr(0, pos);
                if (existingId == p.id) {
                    // replace line
                    stringstream ss;
                    ss << p.id << "|" << p.name << "|" << p.age << "|" << p.score << "|" << p.level;
                    lines.push_back(ss.str());
                    updated = true;
                    continue;
                }
            }
            lines.push_back(line);
        }
        infile.close();
    }

    if (!updated) {
        stringstream ss;
        ss << p.id << "|" << p.name << "|" << p.age << "|" << p.score << "|" << p.level;
        lines.push_back(ss.str());
    }

    ofstream outfile("quiz_profiles.txt", ios::trunc);
    if (!outfile.is_open()) return false;
    for (size_t i = 0; i < lines.size(); ++i) {
        outfile << lines[i] << endl;
    }
    outfile.close();
    return true;
}

// Interactive login / register flow.
// - Enter existing code to login
// - Or create new profile (assigns a unique code) and logs in
void loginRegister() {
    clearScreen();
    showHeader();

    cout << CYAN << "\n\t--- LOGIN / REGISTER ---" << RESET << endl;
    cout << "Enter your Unique Access Code to login or type 'n' to create a new profile: ";
    string input;
    cin >> input;

    if (input == "n" || input == "N") {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        PlayerProfile p;
        cout << "Enter Your Name : ";
        getline(cin, p.name);
        cout << "Enter Your Age  : ";
        while (!(cin >> p.age)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Invalid age. Enter numeric value: " << RESET;
        }
        p.score = 0;
        p.level = "Novice";
        p.id = generateID();
        if (saveOrUpdateProfile(p)) {
            cout << GREEN << "\n[!] Profile created successfully!" << RESET << endl;
            cout << "Your Unique Access Code is: " << MAGENTA << p.id << RESET << endl;
            currentPlayer = p;
            isLoggedIn = true;
        }
        else {
            cout << RED << "\n[!] Error saving profile." << RESET << endl;
        }
        cout << "\nPress Enter to continue...";
        cin.ignore(); cin.get();
        return;
    }
    else {
        PlayerProfile p;
        if (loadProfileByID(input, p)) {
            cout << GREEN << "\n[!] Login successful. Welcome back, " << p.name << "!" << RESET << endl;
            currentPlayer = p;
            isLoggedIn = true;
        }
        else {
            cout << RED << "\nProfile not found for code: " << input << RESET << endl;
            cout << "Would you like to create a new profile? (y/n): ";
            char c;
            cin >> c;
            if (tolower(c) == 'y') {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                PlayerProfile np;
                cout << "Enter Your Name : ";
                getline(cin, np.name);
                cout << "Enter Your Age  : ";
                while (!(cin >> np.age)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << RED << "Invalid age. Enter numeric value: " << RESET;
                }
                np.score = 0;
                np.level = "Novice";
                np.id = generateID();
                if (saveOrUpdateProfile(np)) {
                    cout << GREEN << "\n[!] Profile created successfully!" << RESET << endl;
                    cout << "Your Unique Access Code is: " << MAGENTA << np.id << RESET << endl;
                    currentPlayer = np;
                    isLoggedIn = true;
                }
                else {
                    cout << RED << "\n[!] Error saving profile." << RESET << endl;
                }
                cout << "\nPress Enter to continue...";
                cin.ignore(); cin.get();
                return;
            }
            else {
                cout << "\nPress Enter to return...";
                cin.ignore(); cin.get();
                return;
            }
        }
    }
    cout << "\nPress Enter to continue...";
    cin.ignore(); cin.get();
}

void viewProfile() {
    clearScreen();
    showHeader();
    string code;
    cout << "\nEnter your Unique Access Code: ";
    cin >> code;

    PlayerProfile p;
    if (loadProfileByID(code, p)) {
        cout << CYAN << "\n\t--- PLAYER PROFILE ---" << RESET << endl;
        cout << "Name  : " << p.name << endl;
        cout << "Age   : " << p.age << endl;
        cout << "Score : " << p.score << endl;
        cout << "Level : " << YELLOW << p.level << RESET << endl;
    }
    else {
        cout << RED << "Profile not found!" << RESET << endl;
    }
    cout << "\nPress Enter to return...";
    cin.ignore(); cin.get();
}

bool comparePlayers(const PlayerProfile& a, const PlayerProfile& b) {
    return a.score > b.score;
}

void showLeaderboard() {
    clearScreen();
    showHeader();
    ifstream file("quiz_profiles.txt");
    if (!file.is_open()) {
        cout << RED << "No profiles found." << RESET << endl;
        cout << "\nPress Enter to return...";
        cin.ignore(); cin.get();
        return;
    }

    vector<PlayerProfile> players;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string segment;
        vector<string> parts;

        while (getline(ss, segment, '|')) {
            parts.push_back(segment);
        }

        if (parts.size() >= 5) {
            PlayerProfile p;
            p.id = parts[0];
            p.name = parts[1];
            p.age = atoi(parts[2].c_str());
            p.score = atoi(parts[3].c_str());
            p.level = parts[4];
            players.push_back(p);
        }
    }
    file.close();

    sort(players.begin(), players.end(), comparePlayers);

    cout << CYAN << "\n\t--- TOP 10 LEADERBOARD ---" << RESET << endl;
    cout << "Rank\tName\t\tScore\tLevel" << endl;
    cout << "----\t----\t\t-----\t-----" << endl;
    int limit = (players.size() < 10) ? players.size() : 10;
    for (int i = 0; i < limit; ++i) {
        cout << (i + 1) << "\t" << players[i].name << "\t\t" << players[i].score << "\t" << players[i].level << endl;
    }
    cout << "\nPress Enter to return...";
    cin.ignore(); cin.get();
}

void showRules() {
    clearScreen();
    showHeader();
    cout << YELLOW << "\n\t--- GAME RULES ---" << RESET << endl;
    cout << "1. Each question has 4 options (a, b, c, d)." << endl;
    cout << "2. Correct answer gives +10 points." << endl;
    cout << "3. Wrong answer gives 0 points." << endl;
    cout << "4. You have ONE '50/50' lifeline per game." << endl;
    cout << "5. You can quit anytime by typing 'q'." << endl;
    cout << "6. Achieve higher scores to reach 'Grandmaster' status." << endl;
    cout << "\nPress Enter to return...";
    cin.ignore(); cin.get();
}

// Helper to remove 2 wrong options
void useFiftyFifty(const Question& q, vector<int>& visibleIndices) {
    visibleIndices.clear();
    int correctIndex = q.correctOption - 'a';
    visibleIndices.push_back(correctIndex);

    vector<int> wrongIndices;
    for (int i = 0; i < 4; ++i) {
        if (i != correctIndex) wrongIndices.push_back(i);
    }

    // Pick one random wrong answer to keep
    random_device rd;
    mt19937 g(rd());
    shuffle(wrongIndices.begin(), wrongIndices.end(), g);
    visibleIndices.push_back(wrongIndices[0]);
    sort(visibleIndices.begin(), visibleIndices.end());
}

void playQuiz() {
    clearScreen();
    showHeader();
    int score = 0;
    string name;
    int age;

    // If not logged in, offer to login/register before playing
    if (!isLoggedIn) {
        cout << "You are not logged in. Do you want to login/register before playing? (y/n): ";
        char c;
        cin >> c;
        if (tolower(c) == 'y') {
            loginRegister();
        }
    }

    if (isLoggedIn) {
        // use logged-in profile info
        name = currentPlayer.name;
        age = currentPlayer.age;
        cout << GREEN << "\nPlaying as: " << name << " (Code: " << currentPlayer.id << ")" << RESET << endl;
    }
    else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        cout << "Enter Your Name : ";    getline(cin, name);
        cout << "Enter Your Age  : ";
        while (!(cin >> age)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Invalid age. Enter numeric value: " << RESET;
        }
    }

    // Categories
    int categoryChoice;
    cout << "\nSelect Category:" << endl;
    cout << "1. C++ Programming" << endl;
    cout << "2. General Knowledge" << endl;
    cout << "3. Science" << endl;
    cout << "Choice: ";
    cin >> categoryChoice;

    vector<Question> questions;

    if (categoryChoice == 1) {
        Question qData[] = {
            {"Identify the correct extension of a C++ source file?", {"py", "cpp", "c", "c++"}, 'b', "cpp"},
            {"C++ uses which approach?", {"Right-Left", "Top-Down", "Left-Right", "Bottom-Up"}, 'd', "Bottom-Up"},
            {"Which of the following is address of operator?", {"*", "&", "&&", "#"}, 'b', "&"},
            {"Identify the correct example for a pre-increment operator?", {"+n", "--n", "++n", "n++"}, 'c', "++n"},
            {"Which of the following loops is best when we know the number of iterations?", {"For Loop", "While Loop", "Do While Loop", "For Each Loop"}, 'a', "For Loop"},
            {"What is the size of 'int' in a standard 32-bit compiler?", {"2 bytes", "4 bytes", "8 bytes", "1 byte"}, 'b', "4 bytes"},
            {"Which keyword is used to create a class in C++?", {"struct", "class", "object", "new"}, 'b', "class"},
            {"Which of the following is not a valid access specifier?", {"public", "private", "protected", "internal"}, 'd', "internal"},
            {"What does STL stand for?", {"Standard Template Library", "Simple Text Language", "Static Type Library", "Source Type Linker"}, 'a', "Standard Template Library"},
            {"Which operator is used to access members of a class through a pointer?", {".", "->", ":", "::"}, 'b', "->"}
        };
        questions.assign(qData, qData + sizeof(qData) / sizeof(qData[0]));
    }
    else if (categoryChoice == 2) {
        questions = {
            {"Which is the largest ocean in the world?", {"Atlantic", "Indian", "Arctic", "Pacific"}, 'd', "Pacific"},
            {"Who wrote 'Hamlet'?", {"Charles Dickens", "William Shakespeare", "Mark Twain", "Leo Tolstoy"}, 'b', "William Shakespeare"},
            {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 'c', "Paris"},
            {"How many continents are there?", {"5", "6", "7", "8"}, 'c', "7"},
            {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Venus"}, 'b', "Mars"}
        };
    }
    else {
        questions = {
            {"What is the chemical symbol for Gold?", {"Au", "Ag", "Fe", "Hg"}, 'a', "Au"},
            {"What gas do plants absorb from the atmosphere?", {"Oxygen", "Carbon Dioxide", "Nitrogen", "Hydrogen"}, 'b', "Carbon Dioxide"},
            {"What constitutes the center of an atom?", {"Electrons", "Protons and Neutrons", "Protons only", "Neutrons only"}, 'b', "Protons and Neutrons"},
            {"The speed of light is approximately?", {"300,000 km/s", "150,000 km/s", "100,000 km/s", "1080 km/h"}, 'a', "300,000 km/s"},
            {"What is the powerhouse of the cell?", {"Nucleus", "Ribosome", "Mitochondria", "Golgi Body"}, 'c', "Mitochondria"}
        };
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(questions.begin(), questions.end(), g);

    int totalQuestions = questions.size();
    int pointsPerQuestion = 10;
    bool lifelineAvailable = true;

    cout << MAGENTA << "\n\n\t\t\tWelcome to the Advanced Quiz Game!\n\n" << RESET;
    cout << "Type 'q' to quit, 'l' for 50/50 lifeline.\n\n";

    for (int i = 0; i < totalQuestions; ++i) {
        cout << YELLOW << "\nQuestion " << (i + 1) << ": " << questions[i].text << RESET << endl;

        bool showingAll = true;
        vector<int> visibleIndices = { 0, 1, 2, 3 };

        // Inner loop to handle lifeline usage before answering
        while (true) {
            for (int idx : visibleIndices) {
                char opt = 'a' + idx;
                cout << opt << ") " << questions[i].options[idx] << endl;
            }

            char answer;
            cout << "Your Answer (or 'q' to quit, 'l' for lifeline): ";
            cin >> answer;

            if (tolower(answer) == 'q') {
                cout << YELLOW << "\nQuitting to Main Menu...\n" << RESET;
                return;
            }
            if (tolower(answer) == 'l') {
                if (lifelineAvailable && showingAll) {
                    useFiftyFifty(questions[i], visibleIndices);
                    lifelineAvailable = false;
                    showingAll = false;
                    cout << GREEN << "[!] 50/50 Lifeline used! Two wrong answers removed." << RESET << endl;
                    continue; // Re-print options
                }
                else if (!lifelineAvailable) {
                    cout << RED << "[!] Lifeline already used." << RESET << endl;
                    continue;
                }
                else {
                    cout << RED << "[!] Lifeline already active." << RESET << endl;
                    continue;
                }
            }

            answer = tolower(answer);

            // Validation
            bool valid = false;
            for (int idx : visibleIndices) {
                if (answer == ('a' + idx)) valid = true;
            }

            if (!valid) {
                cout << RED << "Invalid option. Please try again." << RESET << endl;
                continue;
            }

            if (answer == questions[i].correctOption) {
                cout << GREEN << "Correct!\n" << RESET;
                score += pointsPerQuestion;
            }
            else {
                cout << RED << "Wrong! The correct answer is " << questions[i].answerText << ".\n" << RESET;
            }
            break; // Move to next question
        }
    }

    string level = determineLevel(score, totalQuestions * pointsPerQuestion);

    // Display the final score
    cout << "\n" << CYAN << "***********************************************************************" << endl;
    cout << name << ", Your Final Score is : " << score << " out of " << (totalQuestions * pointsPerQuestion) << endl;
    cout << "Your Level: " << YELLOW << level << RESET << endl;
    cout << CYAN << "***********************************************************************" << RESET << endl;

    if (isLoggedIn) {
        // update logged in profile and persist
        currentPlayer.score = score;
        currentPlayer.level = level;
        if (saveOrUpdateProfile(currentPlayer)) {
            cout << GREEN << "\n[!] Your profile has been updated." << RESET << endl;
            cout << "Your Unique Access Code: " << MAGENTA << currentPlayer.id << RESET << endl;
        } else {
            cout << RED << "\n[!] Failed to update profile." << RESET << endl;
        }
    }
    else {
        cout << "\nDo you want to save this result as a new profile? (y/n): ";
        char c; cin >> c;
        if (tolower(c) == 'y') {
            PlayerProfile p;
            p.name = name;
            p.age = age;
            p.score = score;
            p.level = level;
            p.id = generateID();
            if (saveOrUpdateProfile(p)) {
                cout << GREEN << "\n[!] Profile saved successfully!" << RESET << endl;
                cout << "Your Unique Access Code is: " << MAGENTA << p.id << RESET << endl;
                cout << "Use this code to view your stats later." << endl;
            }
            else {
                cout << RED << "\n[!] Error saving profile." << RESET << endl;
            }
        }
    }

    cout << "\nPress Enter to return to menu...";
    cin.ignore(); cin.get();
}

int main() {
    srand(time(0));
    while (true) {
        clearScreen();
        showHeader();
        cout << "\n1. Login / Register" << endl;
        cout << "2. Play Quiz" << endl;
        cout << "3. View Profile" << endl;
        cout << "4. Leaderboard" << endl;
        cout << "5. Game Rules" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: loginRegister(); break;
        case 2: playQuiz(); break;
        case 3: viewProfile(); break;
        case 4: showLeaderboard(); break;
        case 5: showRules(); break;
        case 6:
            cout << "Thanks for playing!" << endl;
            return 0;
        default:
            cout << RED << "Invalid Choice!" << RESET << endl;
        }
    }
    return 0;
}
