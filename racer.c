#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race {
    int numberOfLaps;
    int currentLap;
    char* firstPlaceDriverName;
    char* firstPlaceRaceCarColor;
};

struct RaceCar {
    char* driverName;
    char* raceCarColor;
    int totalLapTime; 
};
// Print functions section
char* printIntro() {
    return "Welcome to the race";
}

char* printCountDown() {
    return "Ready\n5\n4\n3\n2\n1\nRace!";
}

void printFirstPlaceAfterLap(struct Race* race) {
    printf("Ater lap number %d\nFirst Place is: %s in the %s car!", race->currentLap, race->firstPlaceDriverName, race->firstPlaceRaceCarColor);
}

void printCongratulations( struct Race* race ) {
    printf("Congratulations to %s in the %s car for an amazing performance.\n\n\n", race->firstPlaceDriverName, race->firstPlaceRaceCarColor);
}

// Logic functions section
//variables are being initialized to random number between 1 and 3 inclusive
//adding 1 to each bc otherwise rand() may return 0
int calculateTimeToCompleteLap() {
    int speed = rand() % 3 + 1;
    int acceleration = rand() % 3 + 1;
    int nerves = rand() % 3 + 1;
    int sum = speed + acceleration + nerves;

    return sum;
}

void updateRaceCar( struct RaceCar* raceCar ) {
    raceCar->totalLapTime = calculateTimeToCompleteLap();
}

void updateFirstPlace( struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2 ) {
    if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
        race->firstPlaceDriverName = raceCar1->driverName;
        race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
    } else {
        race->firstPlaceDriverName = raceCar2->driverName;
        race->firstPlaceRaceCarColor = raceCar2->raceCarColor;
    }
}

void startRace ( struct RaceCar* raceCar1, struct RaceCar* raceCar2 ) {
    struct Race race = {
        .numberOfLaps = 5,
        .currentLap = 1,
        .firstPlaceDriverName = "",
        .firstPlaceRaceCarColor = ""
    };

    for (int i = 0; i < race.numberOfLaps; i++) {
        updateRaceCar(raceCar1);
        updateRaceCar(raceCar2);
        updateFirstPlace(&race, raceCar1, raceCar2);
    }

    printCongratulations(&race);

}

int main() {
    //seed for rand
	srand(time(0));

    printf("\n%s\n\n", printIntro());
    printf("%s\n\n", printCountDown());

    //entry point for the race simulation
    struct RaceCar raceCar1 = {
        .driverName = "Ant",
        .raceCarColor = "Green"
    };

    struct RaceCar raceCar2 = {
        .driverName = "Kat",
        .raceCarColor = "Red"
    };

    startRace(&raceCar1, &raceCar2);



    //tests***********
    // struct RaceCar raceCar1;
    // updateRaceCar(&raceCar1);
    // printf("race car time to complete lap for raceCar1 = %d\n\n", raceCar1.totalLapTime);

    
    
    
  
};