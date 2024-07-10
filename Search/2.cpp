
    // int n;
    // cout << " Enter the number : ";
    // cin >> n;

    // int ans = 1;
    // for ( int i=1; i<=n; i++){
    //     if(i*i <= n){
    //         ans = i;
    //     }
    //     else {
    //         break;
    //     }
    // }
    //     cout << " Square root is : " << ans << endl;

    // int arr[10] = {1,2,3,3,7,8,9,9,9,11};
    // int x = 11;
    // for (int i = 0; i < 10; i++) {
    //     if (arr[i] >= x) {
    //         cout << "Greater element found at index: " << i << endl;
    //         return 0;
    //     }
    // }

    // cout << "No element found greater than or equal to " << x << endl;
    // return 0;

    // int arr[8] = {2,4,6,8,8,8,11,13};
    // int x = 8;
    // int first = -1;
    // int last = -1;

    // for ( int i=0; i<8; i++){
    //     if(arr[i] == x){
    //         if(first==-1)
    //         first = i;
    //         last = i;
    //     }
    // }
    // cout << " First occurence of  8 : " << first << endl;
    // cout << " First occurence of  8 : " << last << endl;

    // int arr[10] = {1,2,3,3,7,8,9,9,9,11};
    // int ans = -1;
    // int x = 9;
    // for ( int i=0; i<10; i++){
    //     if(arr[i] >= x){
    //         if(ans == -1)
    //         ans = i;
    //     }
    // }
    // cout << ans << endl;

    // int arr[8] = {11,5,6,7,1,51,2};
    // int min = 0;
    // for ( int i=1; i<7; i++){
    //     if(arr[min] > arr[i]){
    //         min = i;
    //     }
    // }
    // cout << " Index of minimum number : " << min << endl;

//     int arr[11] = {1,1,2,2,3,3,4,5,5,6,6};
//     int ans = -1;
//     for (int i = 0; i < 11; i++) {
//         // Check if current element is the same as the next element
//         if (i < 10 && arr[i] == arr[i + 1]) {
//             i++; // Skip the next element since it's part of a pair
//             continue;
//         }

//         // Check if current element is the same as the previous element
//         if (i > 0 && arr[i] == arr[i - 1]) {
//             continue;
//         }

//         // If current element is not part of a pair, it's unique
//         ans = arr[i];
//         break; // Exit the loop since we found the unique element
//     }
//     cout << " Unique element is : " << ans << endl;
// return 0;

// #include <iostream>
// using namespace std;

//     int arr[11] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
//     int ans = -1;

//     for (int i = 1; i < 11; i += 2) {
//         if (arr[i] != arr[i - 1]) {
//             ans = arr[i - 1];
//             break;
//         }
//     }

//     // If ans is still -1, it means the single element is at the end
//     if (ans == -1) {
//         ans = arr[10];
//     }

//     cout << "Element which appears 1 time: " << ans << endl;
//     return 0;

    // int arr[10] = {1,2,3,4,5,6,7,8,5,1};
    // int ans = INT16_MIN;
    // for ( int i=0; i<10; i++){
    //     if(arr[i] > ans){
    //         ans = max(ans,arr[i]);
    //     }
    // }
    // cout << " Maximum value is : " << ans << endl;

    // int arr[8] = {7,7,7,7,14,0,12,7};
    // int maxi = INT8_MIN;
    // for ( int i=0; i<8; i++){
    //     maxi = max(maxi,arr[i]);
    // }
    // for ( int i=0; i<8; i++){
    //     if(maxi-1 == arr[i]){
    //         maxi = arr[i];
    //     }
    //     if(maxi-2 == arr[i]){
    //         maxi = arr[i];
    //     }
    // }
    // cout << " Minimum second element is : " << maxi << endl;
    
    // int arr[5] = {1,3,3,2,2};
    // int ans = -1;
    // for ( int i=0; i<5; i++){
    //     if(arr[i+1] != arr[i]){
    //         continue;
    //     }
    //     else {
    //         ans = arr[i+1];
    //     }
    // }
    // cout << " Repeat element is : " << ans << endl;

    // int arr[7] = {1,1,2,3,3,4,4};
    // int ans = 0;
    // for ( int i=0; i<7; i++){
    //     ans = arr[i] ^ ans;
    // }
    // cout << " Single element is : " << ans << endl;

    // int arr[6] = {1,2,3,4,5,6};
    // int low = 0 , high = 6-1;
    // while(low<=high){
    //     swap(arr[low++],arr[high--]);
    // }
    // for ( auto i: arr){
    //     cout << i << " ";
    // }cout << endl;


    // int arr[7] = {2,4,10,10,10,11,20};
    // int count = 0;
    // int target = 10;
    // for ( int i=0; i<7; i++){
    //     if(arr[i] == target) count ++;
    // }
    // cout << " Number of occurence : " << count << endl;

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int maxProfit(vector<int>& prices) {
//     if (prices.empty()) return 0;

//     int minPrice = INT8_MAX;
//     int maxProfit = 0;

//     for (int price : prices) {
//         minPrice = min(minPrice, price); // Update minPrice
//         int profit = price - minPrice; // Calculate potential profit
//         maxProfit = max(maxProfit, profit); // Update maxProfit
//     }

//     return maxProfit;
// }

// int main() {
//     vector<int> prices = {7, 1, 5, 3, 6, 4};
//     cout << "Maximum Profit: " << maxProfit(prices) << endl;
//     return 0;
// }



