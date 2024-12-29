// my own approach: sliding window
string answerString(string word, int numFriends) {
        int n=word.size();
        if(numFriends==1){
            return word;
        }
        int windowSize=n-numFriends+1; //max Windowsize of the word that can we get after spliting into (numFriends) words
        string str=word.substr(0,windowSize);
        string largestString=str;
        //sliding window technique 
        int s=0;
        int e=windowSize;
        while(e<n){
            str.erase(str.begin());//remove first letter from front
            str+=word[e];//add new letter from back
            e++;
            if(str>largestString)largestString=str;
        }
        //now there is possibility that remaining str contains any such lexographically largest string (eg. Z is greater than ABCD although it's length is smaller) 
        while(str.size()>0){
            str.erase(str.begin());
            if(str>largestString)largestString=str;
        }
        return largestString;
        
    }


//GREEDY APPROACH : copied
    string answerString(string word, int numFriends)
    {
        // Step 1: Handle base case where all friends can split the string
        int N = word.size();
        if (numFriends == 1)
        {
            return word;
        }

        // Step 2: Find the lexicographically largest character in the string
        char c = *max_element(word.begin(), word.end());
        string max_string = "";

        // Step 3: Iterate through the positions of the largest character
        for (int pos = 0; pos < N; pos++)
        {
            if (word[pos] == c)
            {
                // Step 4: Compute the maximum allowable substring length from this position
                int l_allowed = min((int)(N - pos), N - numFriends + 1);

                // Skip if no valid substring can be formed
                if (l_allowed <= 0)
                {
                    continue;
                } 

                // Step 5: Extract the substring and compare with the current maximum
                string s = word.substr(pos, l_allowed);
                if (s > max_string)
                {
                    max_string = s; // Update the maximum string
                }
            }
        }

        // Step 6: Return the result
        return max_string;
    }
