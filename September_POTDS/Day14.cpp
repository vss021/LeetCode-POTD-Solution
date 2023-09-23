
/*
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

 

Example 1:


Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
Example 2:


Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
 
*/





/*
This is the variation of dfs.
The way to tweak the dfs is to not to put a base condition and let the dfs fill and tsack and empty itslef
What i mean by this is 

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Lets say we built a graph of this and its adjacenecy list look like this:-
JFK - MUC
MUC - LHR
LHR - SFO
SFO - SJC

So when we perform a dfs on JFK

|        |
|        |
|        |   <-----Recursion Stack
|        |
|__JFK___|

We explore JFKs neighbors 

|        |
|        |
|        |
|  MUC   |
|__JFK___|

We explore Muc neighbors

|        |
|        |
|  LHR   |
|  MUC   |
|__JFK___|

|        |
|  SFO   |
|  LHR   |
|  MUC   |
|__JFK___|

|  SJC   |
|  SFO   |
|  LHR   |
|  MUC   |
|__JFK___|

Since SJC has no neighbors we pus it back to the answer

|        |
|  SFO   |      ans=SJC
|  LHR   |
|  MUC   |
|__JFK___|

|        |
|        |      ans=SJC,SFO
|  LHR   |
|  MUC   |
|__JFK___|

|        |
|        |      ans=SJC,SFO,LHR
|        |
|  MUC   |
|__JFK___|


|        |
|        |      ans=SJC,SFO,LHR,MUC 
|        |
|        |
|__JFK___|

|        |
|        |      ans=SJC,SFO,LHR,MUC,JFK 
|        |
|        |
|________|

We reverse the array and return it.
*/
    

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> map;
    vector<string> ans;

    void dfs(string s) {
        auto &x = map[s];
        while (!x.empty()) {
            string to = x.top();
            x.pop();
            dfs(to);
        }
        ans.push_back(s);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &x : tickets)
            map[x[0]].push(x[1]);
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    Solution solution;

    vector<string> itinerary = solution.findItinerary(tickets);

    // Print the result itinerary
    for (const string& airport : itinerary) {
        cout << airport << " ";
    }
    cout << endl;

    return 0;
}
