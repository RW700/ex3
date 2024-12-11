/******************
Assignment: ex3
*******************/

#include <stdio.h>

#define NUM_OF_BRANDS 5
#define BRANDS_NAMES 15
#define NUM_OF_TYPES 4
#define TYPES_NAMES 10
#define DAYS_IN_YEAR 365
#define addOne  1
#define addAll  2  
#define stats  3
#define print  4
#define insights  5
#define deltas  6
#define done  7

char brands[NUM_OF_BRANDS][BRANDS_NAMES] = {"Toyoga", "HyunNight", "Mazduh", "FolksVegan", "Key-Yuh"};
char types[NUM_OF_TYPES][TYPES_NAMES] = {"SUV", "Sedan", "Coupe", "GT"};


void printMenu(){
    printf("Welcome to the Cars Data Cube! What would you like to do?\n"
           "1.Enter Daily Data For A Brand\n"
           "2.Populate A Day Of Sales For All Brands\n"
           "3.Provide Daily Stats\n"
           "4.Print All Data\n"
           "5.Provide Overall (simple) Insights\n"
           "6.Provide Average Delta Metrics\n"
           "7.exit\n");
}

// void populateBrand(int (*ptrToCube), int day) {
//     int brandInd, typeZeroVal, typeOneVal, typeTwoVal, typeThreeVal;
//     scanf("\n%d %d %d %d %d", &brandInd, &typeZeroVal, &typeOneVal, &typeTwoVal, &typeThreeVal);
//     while (brandInd >= NUM_OF_BRANDS || brandInd < 0 || typeZeroVal < 0 || typeOneVal < 0 || typeTwoVal < 0 || typeThreeVal < 0) {
//         if (brandInd >= NUM_OF_BRANDS || brandInd < 0) {
//             printf("This brand is not valid\n");
//         } else {
//             printf("Invalid Entry. Please try again:\n");
//
//         }
//         scanf("%*[^\n]");
//         scanf("\n%d %d %d %d %d", &brandInd, &typeZeroVal, &typeOneVal, &typeTwoVal, &typeThreeVal);
//     }
//     int dayPointerCalc = day * NUM_OF_BRANDS * NUM_OF_TYPES;
//     int brandPointerCalc = brandInd * NUM_OF_TYPES;
//     *(ptrToCube + dayPointerCalc + brandPointerCalc + 0 ) = typeZeroVal;
//     *(ptrToCube + dayPointerCalc + brandPointerCalc + 1 ) = typeOneVal;
//     *(ptrToCube + dayPointerCalc + brandPointerCalc + 2 ) = typeTwoVal;
//     *(ptrToCube + dayPointerCalc + brandPointerCalc + 3 ) = typeThreeVal;
// }


int main() {
    int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES];
    // int *ptrToCubeArr = cube;
    // printf("POINTERS: %p %p\n", &cube[0][1][0], (ptrToCubeGEN + 1 * NUM_OF_TYPES));
    // printf("%p\n", cubePtr);
    // Instantiate every value in cube to -1
    for (int i = 0; i < DAYS_IN_YEAR; i++) {
        for (int j = 0; j < NUM_OF_BRANDS; j++) {
            for (int k = 0; k < NUM_OF_TYPES; k++) {
                cube[i][j][k] = -1;
            }
        }
    }
    // variable to keep track of current day
    int day = 0;
    int choice;
    printMenu();
    scanf("%d", &choice);
    while(choice != done) {
        switch(choice) {
            case addOne:
                printf("Chosen add one\n");
                int brandInd, typeZeroVal, typeOneVal, typeTwoVal, typeThreeVal;
                scanf("\n%d %d %d %d %d", &brandInd, &typeZeroVal, &typeOneVal, &typeTwoVal, &typeThreeVal);
                while (brandInd >= NUM_OF_BRANDS || brandInd < 0 || typeZeroVal < 0 || typeOneVal < 0 || typeTwoVal < 0 || typeThreeVal < 0) {
                    if (brandInd >= NUM_OF_BRANDS || brandInd < 0) {
                        printf("This brand is not valid\n");
                    } else {
                        printf("Invalid Entry. Please try again:\n");

                    }
                    scanf("%*[^\n]");
                    scanf("\n%d %d %d %d %d", &brandInd, &typeZeroVal, &typeOneVal, &typeTwoVal, &typeThreeVal);
                }
                cube[day][brandInd][0] = typeZeroVal;
                cube[day][brandInd][1] = typeOneVal;
                cube[day][brandInd][2] = typeTwoVal;
                cube[day][brandInd][3] = typeThreeVal;
                // populateBrand(ptrToCubeArr, day);
                // int brandInd = 0;
                // printf("%d %d %d %d %d\n", brandInd, cube[day][brandInd][0], cube[day][brandInd][1], cube[day][brandInd][2], cube[day][brandInd][3]);
                break;
            case addAll:
                int loopHolder = 1;
                while (loopHolder == 1) {
                    int noDataCounter = 0;
                    for (int i = 0; i < NUM_OF_BRANDS; i++) {
                        for (int j = 0; j < NUM_OF_TYPES; j++) {
                            if (cube[day][i][j] == -1){
                                if (noDataCounter == 0) {
                                    printf("No data for brands ");

                                }
                                printf("%s ", brands[i]);
                                noDataCounter++;
                                break;
                            }
                        }
                    }
                    if (noDataCounter == 0) {
                        loopHolder = 0;
                        break;
                    }

                    printf("\nPlease complete the data\n");
                    // printf("No data for brands %d\n", noDataCounter);
                    int brandInd, typeZeroVal, typeOneVal, typeTwoVal, typeThreeVal;
                    scanf("\n%d %d %d %d %d", &brandInd, &typeZeroVal, &typeOneVal, &typeTwoVal, &typeThreeVal);
                    while (brandInd >= NUM_OF_BRANDS || brandInd < 0 || typeZeroVal < 0 || typeOneVal < 0 || typeTwoVal < 0 || typeThreeVal < 0 || cube[day][brandInd][0] != -1) {
                        // if (brandInd >= NUM_OF_BRANDS || brandInd < 0) {
                        printf("This brand is not valid\n");
                        // } else {
                            // printf("Invalid Entry. Please try again:\n");

                        // }
                        scanf("%*[^\n]");
                        scanf("\n%d %d %d %d %d", &brandInd, &typeZeroVal, &typeOneVal, &typeTwoVal, &typeThreeVal);
                    }
                    cube[day][brandInd][0] = typeZeroVal;
                    cube[day][brandInd][1] = typeOneVal;
                    cube[day][brandInd][2] = typeTwoVal;
                    cube[day][brandInd][3] = typeThreeVal;

                    // printf("%d %d %d %d\n", cube[day][0][0], cube[day][0][1], cube[day][0][2], cube[day][0][3]);
                    // printf("%d %d %d %d\n", cube[day][1][0], cube[day][1][1], cube[day][1][2], cube[day][1][3]);
                    // printf("%d %d %d %d\n", cube[day][2][0], cube[day][2][1], cube[day][2][2], cube[day][2][3]);
                    // printf("%d %d %d %d\n", cube[day][3][0], cube[day][3][1], cube[day][3][2], cube[day][3][3]);
                    // printf("%d %d %d %d\n", cube[day][4][0], cube[day][4][1], cube[day][4][2], cube[day][4][3]);
                }
                day++;
                break;
            case stats:
                printf("What day would you like to analyze?\n");
                int statDayChoice;
                //  contradiction in assignment page, assuming they give day number NOT index
                scanf("%d", &statDayChoice);
                // statDayChoice--;
                while (statDayChoice <= 0 || statDayChoice >= DAYS_IN_YEAR || statDayChoice > day) {
                    printf("Please enter a valid day.\n");
                    printf("What day would you like to analyze?\n");
                    scanf("%*[^\n]");
                    scanf("%d", &statDayChoice);
                }
                --statDayChoice;
                int salesTotal = 0, bestSoldBrand = 0, bestSoldBrandAmount = 0, bestSoldType = 0, bestSoldTypeAmount = 0;
                int brandSalesNums[NUM_OF_BRANDS], typeSalesNums[NUM_OF_TYPES];

                for (int i = 0; i < NUM_OF_BRANDS; i++) {
                    brandSalesNums[i] = 0;
                }
                for (int i = 0; i < NUM_OF_TYPES; i++) {
                    typeSalesNums[i] = 0;
                }

                for (int i = 0; i < NUM_OF_BRANDS; i++) {
                    for (int j = 0; j < NUM_OF_TYPES; j++) {
                        salesTotal += cube[statDayChoice][i][j];
                        brandSalesNums[i] += cube[statDayChoice][i][j];
                        typeSalesNums[j] += cube[statDayChoice][i][j];
                        // to account for: add all values to sales total
                        //                 add all sales of same type
                        //                 addall sales of brand
                    }
                }
                for (int i = 0; i < NUM_OF_BRANDS; i++) {
                    if (brandSalesNums[i] > bestSoldBrandAmount) {
                        bestSoldBrand = i;
                        bestSoldBrandAmount = brandSalesNums[i];
                    }
                }
                for (int i = 0; i < NUM_OF_TYPES; i++) {
                    if (typeSalesNums[i] > bestSoldTypeAmount) {
                        bestSoldType = i;
                        bestSoldTypeAmount = typeSalesNums[i];
                    }
                }
                statDayChoice++;
                printf("In day number %d:\n", statDayChoice);
                printf("The sales total was %d\n", salesTotal);
                printf("The best sold brand with %d sales was %s\n", bestSoldBrandAmount, brands[bestSoldBrand]);
                printf("The best sold type with %d sales was %s\n\n", bestSoldTypeAmount, types[bestSoldType]);

                break;
        case print:
                printf("*****************************************\n\n");

                for (int i = 0; i < NUM_OF_BRANDS; i++) {
                    printf("Sales for %s:\n", brands[i]);
                    for (int j = 0; j < day; j++) {
                        printf("Day %d- ", j + 1);
                        for (int k = 0; k < NUM_OF_TYPES; k++) {
                            printf("%s: %d ", types[k], cube[j][i][k]);
                        }
                        printf("\n");
                    }
                }

                printf("\n\n*****************************************\n");
                break;
            case insights:
                // cycle through every day so far and:
                // add brand values to higher scope variable/array
                // add type values to higher scope variable/array
                // add all values for day in intermediate scope, check if greater than higher scope current max and work
                int bestSellingBrand = 0, bestSellingBrandAmount = 0;
                int bestSellingType = 0, bestSellingTypeAmount = 0;
                int bestSellingDay = 0, bestSellingDayAmount = 0;
                int brandAmounts[NUM_OF_BRANDS], typeAmounts[NUM_OF_TYPES];
                for (int i = 0; i < NUM_OF_BRANDS; i++) {
                    brandAmounts[i] = 0;
                }
                for (int i = 0; i < NUM_OF_TYPES; i++) {
                    typeAmounts[i] = 0;
                }
                for (int i = 0; i < day; i++) {
                    int daySaleAmount = 0;
                    for (int j = 0; j < NUM_OF_BRANDS; j++) {
                        for (int k = 0; k < NUM_OF_TYPES; k++) {
                            daySaleAmount += cube[i][j][k];
                            brandAmounts[j] += cube[i][j][k];
                            typeAmounts[k] += cube[i][j][k];
                        }
                    }
                    if (daySaleAmount > bestSellingDayAmount) {
                        bestSellingDay = i;
                        bestSellingDayAmount = daySaleAmount;
                    }
                }

                for (int i = 0; i < NUM_OF_BRANDS; i++) {
                    if (brandAmounts[i] > bestSellingBrandAmount) {
                        bestSellingBrand = i;
                        bestSellingBrandAmount = brandAmounts[i];
                    }
                }
                for (int i = 0; i < NUM_OF_TYPES; i++) {
                    if (typeAmounts[i] > bestSellingTypeAmount) {
                        bestSellingType = i;
                        bestSellingTypeAmount = typeAmounts[i];
                    }
                }

                printf("The best-selling brand overall is %s: %d$\n", brands[bestSellingBrand], bestSellingBrandAmount);
                printf("The best-selling type of car is %s: %d$\n", types[bestSellingType], bestSellingTypeAmount);
                printf("The most profitable day was day number %d: %d$\n", bestSellingDay + 1, bestSellingDayAmount);

                break;
            case deltas:

                // make array for brands
                // cycle through all days starting from 2nd day (index 1)
                // get difference of brand of index minus 1 and index, sum to brand val of array
                // foreach brand, divide by days, print out info
                int averageDeltaMetrics[NUM_OF_BRANDS];
                for (int i = 0; i < NUM_OF_BRANDS; i++) {
                    averageDeltaMetrics[i] = 0;
                }
                for (int i = 1; i < day; i++) {
                    for (int j = 0; j < NUM_OF_BRANDS; j++) {
                        int daySum = 0, yesterdaySum = 0;
                        for (int k = 0; k < NUM_OF_TYPES; k++) {
                            daySum += cube[i][j][k];
                            yesterdaySum += cube[i - 1][j][k];
                        }
                        averageDeltaMetrics[j] += (daySum - yesterdaySum);
                    }
                }
                for (int i = 0; i < NUM_OF_BRANDS; i++) {
                    float averageDeltaMetric = (float)averageDeltaMetrics[i] / ((float)(day - 1));
                    printf("Brand: %s, Average Delta: %.6f\n", brands[i], averageDeltaMetric);
                }

                break;
            /*
             ......
             */
            default:
                printf("Invalid input\n");
        }
        printMenu();
        scanf("%d", &choice);
    }
    printf("Goodbye!\n");
    return 0;
}


