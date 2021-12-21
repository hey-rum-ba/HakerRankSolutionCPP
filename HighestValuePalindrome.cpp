#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'highestValuePalindrome' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER n
 *  3. INTEGER k
 */

string highestValuePalindrome(string s, int n, int k) {
    int i = 0, j = n - 1, count = 0;
    string visited = s;
    while(i < j){
        if(s[i] < s[j]){
            s[i] = s[j];
            visited[i] = 'x';
            count++;
        }
        else if(s[i] > s[j]){
            s[j] = s[i];
            visited[j] = 'x';
            count++;
        }
        i++;
        j--;
    }
    int z = k - count;
    if(z < 0){
        return "-1";
    }
    else if(z == 0){
        return s;
    }
    
    i = 0; j = n - 1;
    while(z > 0 && i < j){
        if(s[i] != '9'){
            if(visited[i] == 'x' || visited[j] == 'x'){
                    s[i] = '9';
                    s[j] = '9';
                    z -= 1;
            }
            else if(z > 1){
                    s[i] = '9';
                    s[j] = '9';
                    z -= 2;
            }
        }
        i++;
        j--;
    }
    if(z > 0 && n % 2 != 0){
        s[n/2] = '9';
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
