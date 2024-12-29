
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
