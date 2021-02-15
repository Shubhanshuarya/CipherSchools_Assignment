// Efficient Method

// 1. Check if the length of the string is less than the length of the given pattern
// and if it is yes, then "no such window can exist"
// 2. Create two arrays with size of number of chars (256), and initialized with Zero
// 3. Store the occurences of Characters of Patterns
// 4. Initialize variables start = 0, start_index = -1, min_len = INI_MAX
// 5. Start traversing the String and Count of Characters
// count the occurences of the characters of String
// If the string's char matches with patterns's char then increment count
// if (count==len2) => now, we try to minimize the window
// If we get minimum window size, we will update with previous one
// 6. If start_index == -1 => No Such Window Exist
// 7. At Last, Return Substring from start_index and Length min_len

#include<iostream>
using namespace std;

const int no_of_chars = 256;

// Finding the smallest window containing all character of 'pat'
string findSubString(string str, string pat){

    // Calculating length() of string
    int len1 = str.length();
    int len2 = pat.length();

    // Check if String's Length is less than pattern's length, if yes, then so such window can exist
    if(len1 < len2){
        cout << "No Such Window Exists";
        return "";
    }

    int hash_pat[no_of_chars] = {0};
    int hash_str[no_of_chars] = {0};

    // Store Occurences of Character of Pattern
    for(int i = 0; i < len2; i++){
        hash_pat[pat[i]]++;
    }

    int start = 0, start_index = -1, min_len = INT32_MAX;

    // Start Traversing the String and Count the characters
    int count = 0;
    for(int j = 0; j < len1; j++){
        
        // Count Occurences of String's Charcetrs
        hash_str[str[j]]++;

        // If String's Char matches with pattern's Char
        if(hash_str[str[j]] <= hash_pat[str[j]]){
            count++;
        }

        // if all the charcters are matched
        if(count == len2){

            //Try to minimize the window
            while(hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0){
                if(hash_str[str[start]] > hash_pat[str[start]]){
                    hash_str[str[start]]--;
                }
                start++;
            }

            // Update window size
            int len_window = j - start + 1;
            if(min_len > len_window){
                min_len = len_window;
                start_index = start;
            }
        }

    }

    // If no window found
    if(start_index == -1){
        cout << "No Such Window found";
        return "";
    }

    // Return Substring Starting from start_index and length min_len
    return str.substr(start_index, min_len);

}

int main(){
    string str = "this is a test string";
    string pat = "tist";

    cout << "Smallest Window is :" << findSubString(str, pat);
    return 0;
}