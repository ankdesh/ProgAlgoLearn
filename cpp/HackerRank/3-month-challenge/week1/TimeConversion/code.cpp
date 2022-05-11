#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    auto time_12 = s.substr(0,s.length()-2);
    auto peher = s.substr(s.length()-2,s.length()-1);
    if (peher == "AM"){
        if (s.substr(0,2) == "12"){
            time_12[0] ='0';
            time_12[1] ='0';
        }
    }
    else{
        int hr = std::stoi(s.substr(0,2));
        if (hr != 12){
            std::string hr_str = std::to_string(hr+12);
            time_12[0] = hr_str[0];
            time_12[1] = hr_str[1];
        }
    }
    return time_12;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
