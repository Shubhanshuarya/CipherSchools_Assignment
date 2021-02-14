#include<iostream>
using namespace std;

int maxProfit(int price[], int start, int end){

    // If the stocks can't be bought
    if(end <= start){
        return 0;
    }

    // Initial Profit is Zero
    int profit = 0;

    // Day at which the stocks must be bought
    for(int i = start; i < end; i++){

        // Day at which the stocks must be sold
        for(int j = i + 1; j <= end; j++){

            // If buying the stock at ith day and selling it at jth day is profitable
            if(price[j] > price[i]){

                //Update the current profit
                int current_profit = price[j] - price[i] + maxProfit(price, start, i-1)
                 + maxProfit(price, j+1, end);

                 // Update the maximum profit so far
                 profit = max(profit, current_profit);
            }

        }
    }

    return profit;
}

int main(){

    int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price) / sizeof(int);

    cout << maxProfit(price, 0, n - 1);

    return 0;
}