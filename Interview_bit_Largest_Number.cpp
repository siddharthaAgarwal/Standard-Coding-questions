
bool myCmp(string X, string Y)
{
   return (X+Y)>(Y+X);
}

string Solution::largestNumber(const vector<int> &A) {

    vector<string> s;
    
    for(int i=0;i<A.size();i++)
        s.push_back(to_string(A[i]));

     sort(s.begin(),s.end(),myCmp);
    
    if(s[0]=="0")
    return "0";
    string temp;
    
    for(auto i:s)
    temp+=i;
    

    return temp;
    
}
