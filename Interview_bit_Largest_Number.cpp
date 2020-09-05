
bool myCmp(string X, string Y)
{
   string XY = X.append(Y); 
  
    // then append X at the end of Y 
    string YX = Y.append(X); 
  
    // Now see which of the two formed numbers is greater 
    return XY.compare(YX) > 0 ? 1: 0;  
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
