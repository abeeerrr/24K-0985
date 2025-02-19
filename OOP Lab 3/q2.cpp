#include <iostream>
#include <string>

using namespace std;

class FitnessTracker {
private:
    string Name;
    int dailyStepGoal;
    int stepsTaken;
    double caloriesBurned;

public:
    FitnessTracker(string name, int stepGoal) {
        Name = name;
        dailyStepGoal = stepGoal;
        stepsTaken = 0;
        caloriesBurned = 0.0;
    }

    void logSteps(int steps) {
        stepsTaken += steps;
        calculateCalories();
    }

    void calculateCalories() {
        caloriesBurned = stepsTaken * 0.04;
    }
    
    bool isGoalMet() {
        return stepsTaken >= dailyStepGoal;
    }

    void displayProgress() {
        cout << "User: " << Name << endl;
        cout << "Daily Step Goal: " << dailyStepGoal << endl;
        cout << "Steps Taken: " << stepsTaken << endl;
        cout << "Calories Burned: " << caloriesBurned << " kcal" << endl;
        cout << "Goal Status: " << (isGoalMet() ? "Achieved! ??" : "Not Yet!") << endl;
    }
};

int main() {
   
    FitnessTracker abeer("Abeer", 10000);

    abeer.logSteps(5000);
    abeer.displayProgress();

    abeer.logSteps(6000);
    abeer.displayProgress();

    return 0;
}
