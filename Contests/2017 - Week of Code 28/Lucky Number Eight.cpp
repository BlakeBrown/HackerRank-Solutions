#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

map<string,long long>::iterator it;
unordered_map<string,long long> multipleMap;
unordered_map<long long,long long> contributionMap;

// Long answer I came up with during the contest, basically
// use DP to count the # of contributions
long long threeDigitContribution(long long num, int pos) {
    return (num*contributionMap[pos]%1000000007);
}

long long threeDigitContributionEven(int i) {
    long long contribution = 0;
    contribution += threeDigitContribution(multipleMap["00"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["08"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["16"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["24"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["32"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["40"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["48"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["56"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["64"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["72"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["80"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["88"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["96"], i);
    contribution %= 1000000007;
    return contribution;
}

long long threeDigitContributionOdd(int i) {
    long long contribution = 0;
    contribution += threeDigitContribution(multipleMap["04"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["12"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["20"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["28"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["36"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["44"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["52"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["60"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["68"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["76"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["84"], i);
    contribution %= 1000000007;
    contribution += threeDigitContribution(multipleMap["92"], i);
    contribution %= 1000000007;
    return contribution;
}

int main(){
    int n;
    cin >> n;
    string number;
    cin >> number;
    long long answer = 0;

    // Any of the following keys can be part of a multiple of 8
    multipleMap["0"] = 0;
    multipleMap["1"] = 0;
    multipleMap["2"] = 0;
    multipleMap["3"] = 0;
    multipleMap["4"] = 0;
    multipleMap["5"] = 0;
    multipleMap["6"] = 0;
    multipleMap["7"] = 0;
    multipleMap["8"] = 0;
    multipleMap["9"] = 0;
    multipleMap["00"] = 0;
    multipleMap["04"] = 0;
    multipleMap["08"] = 0;
    multipleMap["12"] = 0;
    multipleMap["16"] = 0;
    multipleMap["20"] = 0;
    multipleMap["24"] = 0;
    multipleMap["28"] = 0;
    multipleMap["32"] = 0;
    multipleMap["36"] = 0;
    multipleMap["40"] = 0;
    multipleMap["44"] = 0;
    multipleMap["48"] = 0;
    multipleMap["52"] = 0;
    multipleMap["56"] = 0;
    multipleMap["60"] = 0;
    multipleMap["64"] = 0;
    multipleMap["68"] = 0;
    multipleMap["72"] = 0;
    multipleMap["76"] = 0;
    multipleMap["80"] = 0;
    multipleMap["84"] = 0;
    multipleMap["88"] = 0;
    multipleMap["92"] = 0;
    multipleMap["96"] = 0;
    // Calculate contribution of 3-digit pairs at different indices
    long long contribution = 1;
    for(int i = 0; i <= 220000; i++) {
        contributionMap[i] = contribution;
        contribution *= 2;
        contribution %= 1000000007;
    }

    // Count 2-digit and 3-digit multiples using DP
    for(int i = number.size()-1; i >= 0; i--) {
        if(number[i] == '0') {
            // First see what we can combine it with
            // 1-digit contributions
            answer++; // Since 0 is a multiple of 8
            // 2-digit contributions
            answer += multipleMap["0"]; // Since 00 is a multiple of 8
            answer %= 1000000007;
            answer += multipleMap["8"]; // Since 08 is a multiple of 8
            answer %= 1000000007;
            // 3-digit contributions
            answer += threeDigitContributionEven(i);
            // Then update the maps
            multipleMap["00"] += multipleMap["0"];
            multipleMap["00"] %= 1000000007;
            multipleMap["04"] += multipleMap["4"];
            multipleMap["04"] %= 1000000007;
            multipleMap["08"] += multipleMap["8"];
            multipleMap["08"] %= 1000000007;
            multipleMap["0"]++;
        } else if(number[i] == '1') {
            // First see what we can combine it with
            answer += multipleMap["6"];
            answer %= 1000000007;
            answer += threeDigitContributionOdd(i);
            answer %= 1000000007;
            // Then update the maps
            multipleMap["12"] += multipleMap["2"];
            multipleMap["12"] %= 1000000007;
            multipleMap["16"] += multipleMap["6"];
            multipleMap["16"] %= 1000000007;
            multipleMap["1"]++;
        } else if(number[i] == '2') {
            // First see what we can combine it with
            answer += multipleMap["4"];
            answer %= 1000000007;
            answer += threeDigitContributionEven(i);
            answer %= 1000000007;
            // Then update the maps
            multipleMap["20"] += multipleMap["0"];
            multipleMap["20"] %= 1000000007;
            multipleMap["24"] += multipleMap["4"];
            multipleMap["24"] %= 1000000007;
            multipleMap["28"] += multipleMap["8"];
            multipleMap["28"] %= 1000000007;
            multipleMap["2"]++;
        } else if(number[i] == '3') {
            // First see what we can combine it with
            answer += multipleMap["2"];
            answer %= 1000000007;
            answer += threeDigitContributionOdd(i);
            answer %= 1000000007;
            // Then update the maps
            multipleMap["32"] += multipleMap["2"];
            multipleMap["32"] %= 1000000007;
            multipleMap["36"] += multipleMap["6"];
            multipleMap["36"] %= 1000000007;
            multipleMap["3"]++;
        } else if(number[i] == '4') {
            // First see what we can combine it with
            answer += multipleMap["0"];
            answer %= 1000000007;
            answer += multipleMap["8"];
            answer %= 1000000007;
            answer += threeDigitContributionEven(i);
            answer %= 1000000007;
            // Then update the maps
            multipleMap["40"] += multipleMap["0"];
            multipleMap["40"] %= 1000000007;
            multipleMap["44"] += multipleMap["4"];
            multipleMap["44"] %= 1000000007;
            multipleMap["48"] += multipleMap["8"];
            multipleMap["48"] %= 1000000007;
            multipleMap["4"]++;
        } else if(number[i] == '5') {
            // First see what we can combine it with
            answer += multipleMap["6"];
            answer %= 1000000007;
            answer += threeDigitContributionOdd(i);
            answer %= 1000000007;
            // Then update the maps
            multipleMap["52"] += multipleMap["2"];
            multipleMap["52"] %= 1000000007;
            multipleMap["56"] += multipleMap["6"];
            multipleMap["56"] %= 1000000007;
            multipleMap["5"]++;
        } else if(number[i] == '6') {
            // First see what we can combine it with
            answer += multipleMap["4"];
            answer %= 1000000007;
            answer += threeDigitContributionEven(i);
            answer %= 1000000007;
            // Then update the maps
            multipleMap["60"] += multipleMap["0"];
            multipleMap["60"] %= 1000000007;
            multipleMap["64"] += multipleMap["4"];
            multipleMap["64"] %= 1000000007;
            multipleMap["68"] += multipleMap["8"];
            multipleMap["68"] %= 1000000007;
            multipleMap["6"]++;
        } else if(number[i] == '7') {
            // First see what we can combine it with
            answer += multipleMap["2"];
            answer %= 1000000007;
            answer += threeDigitContributionOdd(i);
            answer %= 1000000007;
            // Then update the maps
            multipleMap["72"] += multipleMap["2"];
            multipleMap["72"] %= 1000000007;
            multipleMap["76"] += multipleMap["6"];
            multipleMap["76"] %= 1000000007;
            multipleMap["7"]++;
        } else if(number[i] == '8') {
            // First see what we can combine it with
            answer++;
            answer += multipleMap["0"];
            answer %= 1000000007;
            answer += multipleMap["8"];
            answer %= 1000000007;
            answer += threeDigitContributionEven(i);
            answer %= 1000000007;
            // Then update the maps
            multipleMap["80"] += multipleMap["0"];
            multipleMap["80"] %= 1000000007;
            multipleMap["84"] += multipleMap["4"];
            multipleMap["84"] %= 1000000007;
            multipleMap["88"] += multipleMap["8"];
            multipleMap["88"] %= 1000000007;
            multipleMap["8"]++;
        } else if(number[i] == '9') {
            // First see what we can combine it with
            answer += multipleMap["6"];
            answer %= 1000000007;
            answer += threeDigitContributionOdd(i);
            answer %= 1000000007;
            // Then update the maps
            multipleMap["92"] += multipleMap["2"];
            multipleMap["92"] %= 1000000007;
            multipleMap["96"] += multipleMap["6"];
            multipleMap["96"] %= 1000000007;
            multipleMap["9"]++;
        }
    }
    cout<<answer<<"\n";
    return 0;
}


// Much cleaner trie solution (creds to tsite)
// using namespace std;

// #define m 1000000007
// #define pe(a,b){a+=b;a%=m;}

// typedef unsigned int t;

// constexpr t minv_t[]={0,4,3,4,2,4,1,4,0,4};

// int main(){
//     int n;
//     cin >> n;
//     string number;
//     cin >> number;
//     t reg[5]={};
//     t regp[2]={};
//     t dcount=0;
//     t si=1;
//     for(int i=0;i<n;i++) {
//         number[i]-='0';
//         if(number[i]%8==0)dcount++;
//         pe(dcount,reg[minv_t[number[i]]]);
//         pe(reg[number[i]%4],regp[0]+1);
//         pe(reg[(number[i]+2)%4],regp[1]);
//         pe(regp[number[i]%2],si);
//         pe(si,si);
//     }
//     cout << dcount;
//     return 0;
// }
