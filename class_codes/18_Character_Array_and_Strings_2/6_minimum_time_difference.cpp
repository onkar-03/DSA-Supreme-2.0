#include <bits/stdc++.h>
using namespace std;
int findMinDifference(vector<string> Time)
{
    // creating a dynamic array to store the integer values of the Time string of length of the vector<string>Time
    int len = Time.size();
    // cout << "size of time vector : " << len << endl;

    //Dynamic Array initialisation : 
    int *arr = new int[len];

    for (int i = 0; i < len; i++)
    {
        // fetching string elements of vector one by one
        string CurrentTime = Time.at(i);

        // taking the hours part only using substr
        string Hours = CurrentTime.substr(0, 2);

        // converting string hours value to integer value into minutes
        int HoursValue = stoi(Hours) * 60;

        // taking the minutes part only using substr
        string Minutes = CurrentTime.substr(3, 2);

        // converting the string of minutes to integer value
        int MinutesValue = stoi(Minutes);

        int TotalTime = HoursValue + MinutesValue;
        arr[i] = TotalTime;
    }

    // cout << "Before Sorting : " << endl;

    // for (int i = 0; i < len; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    sort(arr, arr + len);

    // cout << "After Sorting : " << endl;

    // for (int i = 0; i < len; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    int minValue = INT_MAX;
    // cout << "current minValue : " << minValue << endl;
    // cout << endl;
    for (int i = 1; i < len; i++)
    {
        // arr[LargerIndex] - arr[SmallerIndex] inorder to avoid the negetive value

        minValue = min(minValue, arr[i] - arr[i - 1]);

        // checking outptut !!
        // cout << "values subtracted to get minValue : " << endl
        //      << arr[i] << " and " << arr[i - 1] << endl;
        // cout << "there differnce : " << arr[i] - arr[i - 1] << endl;
        // cout << "minimum value : " << minValue << endl;
    }
    // cout << "minimum value at last : " << minValue << endl;
    
    // CORNER CASE /  EDGE CASE : 
    // cout << arr[len - 1] << " " << arr[0] << endl;
    // cout << 24 * 60 << " and " << arr[len - 1] + arr[0] << endl;
    // cout << "minimum of : " << 24 * 60 - arr[len - 1] + arr[0] << " and " << minValue<<endl;
    minValue = min(minValue, 24 * 60 - arr[len - 1] + arr[0]);
    return minValue;
}
int main()
{
    vector<string> Time = {"23:59", "00:00", "10:54"};
    // string 1 (0th Index) : 2 2 : 1 0
    //                        0 1 2 3 4
    // string 2 (1st Index) : 0 0 : 0 0
    //                        0 1 2 3 4
    // string 3 (2nd Index) : 1 0 : 5 4
    //                        0 1 2 3 4
    int answer = findMinDifference(Time);
    cout << endl;
    cout << answer << " Minutes !! ";
    return 0;
}