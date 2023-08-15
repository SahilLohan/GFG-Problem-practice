// Link : https://practice.geeksforgeeks.org/problems/generate-all-binary-strings/1


// Code :
class Solution{
public:
    void print(int n,string s,bool prevDigitIsOne)
    {
        if(s.length()==n)
        {
            cout << s << " ";
            return;
        }
        
        print(n , s+"0" , false);
        if(!prevDigitIsOne)
        {
            print(n , s+"1" , true);
        }
        
    }
    void generateBinaryStrings(int num){
        //Write your code
        print(num , "" , false);
    }
};
